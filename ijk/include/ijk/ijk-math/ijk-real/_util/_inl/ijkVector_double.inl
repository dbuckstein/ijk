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

	ijkVector_double.inl
	Inline definitions for 64-bit float (double) vector functions.
*/

#ifdef _IJK_VECTOR_DOUBLE_H_
#ifndef _IJK_VECTOR_DOUBLE_INL_
#define _IJK_VECTOR_DOUBLE_INL_


//-----------------------------------------------------------------------------

ijk_inl f64 ijkVecAbs1ds(f64 const s)
{
	return ijk_abs_dbl(s);
}

ijk_inl f64 ijkVecSgn1ds(f64 const s)
{
	return ijk_sgn_dbl(s);
}

ijk_inl f64 ijkVecDot1ds(f64 const s_lh, f64 const s_rh)
{
	return (s_lh * s_rh);
}

ijk_inl f64 ijkVecLengthSq1ds(f64 const s)
{
	return (s * s);
}

ijk_inl f64 ijkVecLength1ds(f64 const s)
{
	return ijk_abs_dbl(s);
}

ijk_inl f64 ijkVecLengthSqInv1ds(f64 const s)
{
	f64 const lengthSq = (s * s);
	return ijk_recip_safe_dbl(lengthSq);
}

ijk_inl f64 ijkVecLengthInv1ds(f64 const s)
{
	f64 const length = ijk_abs_dbl(s);
	return ijk_recip_safe_dbl(length);
}

ijk_inl f64 ijkVecNormalize1ds(f64 const s)
{
	return ijk_sgn_dbl(s);
}

ijk_inl f64 ijkVecNormalizeGetLength1ds(f64 const s, f64* const length_out)
{
	f64 const length = *length_out = ijk_abs_dbl(s);
	return ijk_sgn_dbl(s);
}

ijk_inl f64 ijkVecNormalizeGetLengthInv1ds(f64 const s, f64* const lengthInv_out)
{
	f64 const length = ijk_abs_dbl(s);
	*lengthInv_out = ijk_recip_safe_dbl(length);
	return ijk_sgn_dbl(s);
}


//-----------------------------------------------------------------------------

ijk_inl doublev ijkVecPdv(doublev v_out)
{
	return v_out;
}


//-----------------------------------------------------------------------------

ijk_inl doublev ijkVecInit2dv(double2 v_out)
{
	v_out[0] = v_out[1] = 0;
	return v_out;
}

ijk_inl doublev ijkVecInitElems2dv(double2 v_out, f64 const x, f64 const y)
{
	v_out[0] = x;
	v_out[1] = y;
	return v_out;
}

ijk_inl doublev ijkVecCopy2dv(double2 v_out, double2 const v_in)
{
	v_out[0] = +v_in[0];
	v_out[1] = +v_in[1];
	return v_out;
}

ijk_inl doublev ijkVecNegate2dv(double2 v_out, double2 const v_in)
{
	v_out[0] = -v_in[0];
	v_out[1] = -v_in[1];
	return v_out;
}

ijk_inl boolv ijkVecNot2dv(bool2 bv_out, double2 const v_in)
{
	bv_out[0] = !v_in[0];
	bv_out[1] = !v_in[1];
	return bv_out;
}

ijk_inl doublev ijkVecAdd2dv(double2 v_out, double2 const v_lh, double2 const v_rh)
{
	v_out[0] = v_lh[0] + v_rh[0];
	v_out[1] = v_lh[1] + v_rh[1];
	return v_out;
}

ijk_inl doublev ijkVecSub2dv(double2 v_out, double2 const v_lh, double2 const v_rh)
{
	v_out[0] = v_lh[0] - v_rh[0];
	v_out[1] = v_lh[1] - v_rh[1];
	return v_out;
}

ijk_inl doublev ijkVecMul2dv(double2 v_out, double2 const v_lh, double2 const v_rh)
{
	v_out[0] = v_lh[0] * v_rh[0];
	v_out[1] = v_lh[1] * v_rh[1];
	return v_out;
}

ijk_inl doublev ijkVecDiv2dv(double2 v_out, double2 const v_lh, double2 const v_rh)
{
	v_out[0] = v_lh[0] / v_rh[0];
	v_out[1] = v_lh[1] / v_rh[1];
	return v_out;
}

ijk_inl doublev ijkVecDivSafe2dv(double2 v_out, double2 const v_lh, double2 const v_rh)
{
	v_out[0] = ijk_divide_safe_dbl(v_lh[0], v_rh[0]);
	v_out[1] = ijk_divide_safe_dbl(v_lh[1], v_rh[1]);
	return v_out;
}

ijk_inl doublev ijkVecMod2dv(double2 v_out, double2 const v_lh, double2 const v_rh)
{
	v_out[0] = ijk_modulo_dbl(v_lh[0], v_rh[0]);
	v_out[1] = ijk_modulo_dbl(v_lh[1], v_rh[1]);
	return v_out;
}

ijk_inl doublev ijkVecModSafe2dv(double2 v_out, double2 const v_lh, double2 const v_rh)
{
	v_out[0] = ijk_modulo_safe_dbl(v_lh[0], v_rh[0]);
	v_out[1] = ijk_modulo_safe_dbl(v_lh[1], v_rh[1]);
	return v_out;
}

ijk_inl boolv ijkVecEqual2dv(bool2 bv_out, double2 const v_lh, double2 const v_rh)
{
	bv_out[0] = (v_lh[0] == v_rh[0]);
	bv_out[1] = (v_lh[1] == v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal2dv(bool2 bv_out, double2 const v_lh, double2 const v_rh)
{
	bv_out[0] = (v_lh[0] != v_rh[0]);
	bv_out[1] = (v_lh[1] != v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual2dv(bool2 bv_out, double2 const v_lh, double2 const v_rh)
{
	bv_out[0] = (v_lh[0] <= v_rh[0]);
	bv_out[1] = (v_lh[1] <= v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual2dv(bool2 bv_out, double2 const v_lh, double2 const v_rh)
{
	bv_out[0] = (v_lh[0] >= v_rh[0]);
	bv_out[1] = (v_lh[1] >= v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecLess2dv(bool2 bv_out, double2 const v_lh, double2 const v_rh)
{
	bv_out[0] = (v_lh[0] < v_rh[0]);
	bv_out[1] = (v_lh[1] < v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater2dv(bool2 bv_out, double2 const v_lh, double2 const v_rh)
{
	bv_out[0] = (v_lh[0] > v_rh[0]);
	bv_out[1] = (v_lh[1] > v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd2dv(bool2 bv_out, double2 const v_lh, double2 const v_rh)
{
	bv_out[0] = (v_lh[0] && v_rh[0]);
	bv_out[1] = (v_lh[1] && v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecNand2dv(bool2 bv_out, double2 const v_lh, double2 const v_rh)
{
	bv_out[0] = !(v_lh[0] && v_rh[0]);
	bv_out[1] = !(v_lh[1] && v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecOr2dv(bool2 bv_out, double2 const v_lh, double2 const v_rh)
{
	bv_out[0] = (v_lh[0] || v_rh[0]);
	bv_out[1] = (v_lh[1] || v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecNor2dv(bool2 bv_out, double2 const v_lh, double2 const v_rh)
{
	bv_out[0] = !(v_lh[0] || v_rh[0]);
	bv_out[1] = !(v_lh[1] || v_rh[1]);
	return bv_out;
}

ijk_inl doublev ijkVecCopy2dvs(double2 v_out, f64 const s_in)
{
	v_out[0] = v_out[1] = +s_in;
	return v_out;
}

ijk_inl doublev ijkVecNegate2dvs(double2 v_out, f64 const s_in)
{
	v_out[0] = v_out[1] = -s_in;
	return v_out;
}

ijk_inl boolv ijkVecNot2dvs(bool2 bv_out, f64 const s_in)
{
	bv_out[0] = bv_out[1] = !s_in;
	return bv_out;
}

ijk_inl doublev ijkVecAdd2dvs(double2 v_out, double2 const v_lh, f64 const s_rh)
{
	v_out[0] = v_lh[0] + s_rh;
	v_out[1] = v_lh[1] + s_rh;
	return v_out;
}

ijk_inl doublev ijkVecSub2dvs(double2 v_out, double2 const v_lh, f64 const s_rh)
{
	v_out[0] = v_lh[0] - s_rh;
	v_out[1] = v_lh[1] - s_rh;
	return v_out;
}

ijk_inl doublev ijkVecMul2dvs(double2 v_out, double2 const v_lh, f64 const s_rh)
{
	v_out[0] = v_lh[0] * s_rh;
	v_out[1] = v_lh[1] * s_rh;
	return v_out;
}

ijk_inl doublev ijkVecDiv2dvs(double2 v_out, double2 const v_lh, f64 const s_rh)
{
	f64 const s = ijk_recip_dbl(s_rh);
	v_out[0] = v_lh[0] * s;
	v_out[1] = v_lh[1] * s;
	return v_out;
}

ijk_inl doublev ijkVecDivSafe2dvs(double2 v_out, double2 const v_lh, f64 const s_rh)
{
	f64 const s = ijk_recip_safe_dbl(s_rh);
	v_out[0] = v_lh[0] * s;
	v_out[1] = v_lh[1] * s;
	return v_out;
}

ijk_inl doublev ijkVecMod2dvs(double2 v_out, double2 const v_lh, f64 const s_rh)
{
	v_out[0] = ijk_modulo_dbl(v_lh[0], s_rh);
	v_out[1] = ijk_modulo_dbl(v_lh[1], s_rh);
	return v_out;
}

ijk_inl doublev ijkVecModSafe2dvs(double2 v_out, double2 const v_lh, f64 const s_rh)
{
	if (s_rh)
	{
		v_out[0] = ijk_modulo_dbl(v_lh[0], s_rh);
		v_out[1] = ijk_modulo_dbl(v_lh[1], s_rh);
		return v_out;
	}
	return ijkVecCopy2dv(v_out, v_lh);
}

ijk_inl boolv ijkVecEqual2dvs(bool2 bv_out, double2 const v_lh, f64 const s_rh)
{
	bv_out[0] = (v_lh[0] == s_rh);
	bv_out[1] = (v_lh[1] == s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecInequal2dvs(bool2 bv_out, double2 const v_lh, f64 const s_rh)
{
	bv_out[0] = (v_lh[0] != s_rh);
	bv_out[1] = (v_lh[1] != s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual2dvs(bool2 bv_out, double2 const v_lh, f64 const s_rh)
{
	bv_out[0] = (v_lh[0] <= s_rh);
	bv_out[1] = (v_lh[1] <= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual2dvs(bool2 bv_out, double2 const v_lh, f64 const s_rh)
{
	bv_out[0] = (v_lh[0] >= s_rh);
	bv_out[1] = (v_lh[1] >= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLess2dvs(bool2 bv_out, double2 const v_lh, f64 const s_rh)
{
	bv_out[0] = (v_lh[0] < s_rh);
	bv_out[1] = (v_lh[1] < s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreater2dvs(bool2 bv_out, double2 const v_lh, f64 const s_rh)
{
	bv_out[0] = (v_lh[0] > s_rh);
	bv_out[1] = (v_lh[1] > s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecAnd2dvs(bool2 bv_out, double2 const v_lh, f64 const s_rh)
{
	bv_out[0] = (v_lh[0] && s_rh);
	bv_out[1] = (v_lh[1] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNand2dvs(bool2 bv_out, double2 const v_lh, f64 const s_rh)
{
	bv_out[0] = !(v_lh[0] && s_rh);
	bv_out[1] = !(v_lh[1] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecOr2dvs(bool2 bv_out, double2 const v_lh, f64 const s_rh)
{
	bv_out[0] = (v_lh[0] || s_rh);
	bv_out[1] = (v_lh[1] || s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNor2dvs(bool2 bv_out, double2 const v_lh, f64 const s_rh)
{
	bv_out[0] = !(v_lh[0] || s_rh);
	bv_out[1] = !(v_lh[1] || s_rh);
	return bv_out;
}

ijk_inl doublev ijkVecAdd2dsv(double2 v_out, f64 const s_lh, double2 const v_rh)
{
	v_out[0] = s_lh + v_rh[0];
	v_out[1] = s_lh + v_rh[1];
	return v_out;
}

ijk_inl doublev ijkVecSub2dsv(double2 v_out, f64 const s_lh, double2 const v_rh)
{
	v_out[0] = s_lh - v_rh[0];
	v_out[1] = s_lh - v_rh[1];
	return v_out;
}

ijk_inl doublev ijkVecMul2dsv(double2 v_out, f64 const s_lh, double2 const v_rh)
{
	v_out[0] = s_lh * v_rh[0];
	v_out[1] = s_lh * v_rh[1];
	return v_out;
}

ijk_inl doublev ijkVecDiv2dsv(double2 v_out, f64 const s_lh, double2 const v_rh)
{
	v_out[0] = s_lh / v_rh[0];
	v_out[1] = s_lh / v_rh[1];
	return v_out;
}

ijk_inl doublev ijkVecDivSafe2dsv(double2 v_out, f64 const s_lh, double2 const v_rh)
{
	v_out[0] = ijk_divide_safe_dbl(s_lh, v_rh[0]);
	v_out[1] = ijk_divide_safe_dbl(s_lh, v_rh[1]);
	return v_out;
}

ijk_inl doublev ijkVecMod2dsv(double2 v_out, f64 const s_lh, double2 const v_rh)
{
	v_out[0] = ijk_modulo_dbl(s_lh, v_rh[0]);
	v_out[1] = ijk_modulo_dbl(s_lh, v_rh[1]);
	return v_out;
}

ijk_inl doublev ijkVecModSafe2dsv(double2 v_out, f64 const s_lh, double2 const v_rh)
{
	v_out[0] = ijk_modulo_safe_dbl(s_lh, v_rh[0]);
	v_out[1] = ijk_modulo_safe_dbl(s_lh, v_rh[1]);
	return v_out;
}

ijk_inl boolv ijkVecEqual2dsv(bool2 bv_out, f64 const s_lh, double2 const v_rh)
{
	bv_out[0] = (s_lh == v_rh[0]);
	bv_out[1] = (s_lh == v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal2dsv(bool2 bv_out, f64 const s_lh, double2 const v_rh)
{
	bv_out[0] = (s_lh != v_rh[0]);
	bv_out[1] = (s_lh != v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual2dsv(bool2 bv_out, f64 const s_lh, double2 const v_rh)
{
	bv_out[0] = (s_lh <= v_rh[0]);
	bv_out[1] = (s_lh <= v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual2dsv(bool2 bv_out, f64 const s_lh, double2 const v_rh)
{
	bv_out[0] = (s_lh >= v_rh[0]);
	bv_out[1] = (s_lh >= v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecLess2dsv(bool2 bv_out, f64 const s_lh, double2 const v_rh)
{
	bv_out[0] = (s_lh < v_rh[0]);
	bv_out[1] = (s_lh < v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater2dsv(bool2 bv_out, f64 const s_lh, double2 const v_rh)
{
	bv_out[0] = (s_lh > v_rh[0]);
	bv_out[1] = (s_lh > v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd2dsv(bool2 bv_out, f64 const s_lh, double2 const v_rh)
{
	bv_out[0] = (s_lh && v_rh[0]);
	bv_out[1] = (s_lh && v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecNand2dsv(bool2 bv_out, f64 const s_lh, double2 const v_rh)
{
	bv_out[0] = !(s_lh && v_rh[0]);
	bv_out[1] = !(s_lh && v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecOr2dsv(bool2 bv_out, f64 const s_lh, double2 const v_rh)
{
	bv_out[0] = (s_lh || v_rh[0]);
	bv_out[1] = (s_lh || v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecNor2dsv(bool2 bv_out, f64 const s_lh, double2 const v_rh)
{
	bv_out[0] = !(s_lh || v_rh[0]);
	bv_out[1] = !(s_lh || v_rh[1]);
	return bv_out;
}

ijk_inl f64 ijkVecDot2dv(double2 const v_lh, double2 const v_rh)
{
	return (v_lh[0] * v_rh[0] + v_lh[1] * v_rh[1]);
}

ijk_inl f64 ijkVecCross2dv(double2 const v_lh, double2 const v_rh)
{
	return (v_lh[0] * v_rh[1] - v_lh[1] * v_rh[0]);
}


//-----------------------------------------------------------------------------

ijk_inl doublev ijkVecInit3dv(double3 v_out)
{
	v_out[0] = v_out[1] = v_out[2] = 0;
	return v_out;
}

ijk_inl doublev ijkVecInitElems3dv(double3 v_out, f64 const x, f64 const y, f64 const z)
{
	v_out[0] = x;
	v_out[1] = y;
	v_out[2] = z;
	return v_out;
}

ijk_inl doublev ijkVecCopy3dv(double3 v_out, double3 const v_in)
{
	v_out[0] = +v_in[0];
	v_out[1] = +v_in[1];
	v_out[2] = +v_in[2];
	return v_out;
}

ijk_inl doublev ijkVecNegate3dv(double3 v_out, double3 const v_in)
{
	v_out[0] = -v_in[0];
	v_out[1] = -v_in[1];
	v_out[2] = -v_in[2];
	return v_out;
}

ijk_inl boolv ijkVecNot3dv(bool3 bv_out, double3 const v_in)
{
	bv_out[0] = !v_in[0];
	bv_out[1] = !v_in[1];
	bv_out[2] = !v_in[2];
	return bv_out;
}

ijk_inl doublev ijkVecAdd3dv(double3 v_out, double3 const v_lh, double3 const v_rh)
{
	v_out[0] = v_lh[0] + v_rh[0];
	v_out[1] = v_lh[1] + v_rh[1];
	v_out[2] = v_lh[2] + v_rh[2];
	return v_out;
}

ijk_inl doublev ijkVecSub3dv(double3 v_out, double3 const v_lh, double3 const v_rh)
{
	v_out[0] = v_lh[0] - v_rh[0];
	v_out[1] = v_lh[1] - v_rh[1];
	v_out[2] = v_lh[2] - v_rh[2];
	return v_out;
}

ijk_inl doublev ijkVecMul3dv(double3 v_out, double3 const v_lh, double3 const v_rh)
{
	v_out[0] = v_lh[0] * v_rh[0];
	v_out[1] = v_lh[1] * v_rh[1];
	v_out[2] = v_lh[2] * v_rh[2];
	return v_out;
}

ijk_inl doublev ijkVecDiv3dv(double3 v_out, double3 const v_lh, double3 const v_rh)
{
	v_out[0] = v_lh[0] / v_rh[0];
	v_out[1] = v_lh[1] / v_rh[1];
	v_out[2] = v_lh[2] / v_rh[2];
	return v_out;
}

ijk_inl doublev ijkVecDivSafe3dv(double3 v_out, double3 const v_lh, double3 const v_rh)
{
	v_out[0] = ijk_divide_safe_dbl(v_lh[0], v_rh[0]);
	v_out[1] = ijk_divide_safe_dbl(v_lh[1], v_rh[1]);
	v_out[2] = ijk_divide_safe_dbl(v_lh[2], v_rh[2]);
	return v_out;
}

ijk_inl doublev ijkVecMod3dv(double3 v_out, double3 const v_lh, double3 const v_rh)
{
	v_out[0] = ijk_modulo_dbl(v_lh[0], v_rh[0]);
	v_out[1] = ijk_modulo_dbl(v_lh[1], v_rh[1]);
	v_out[2] = ijk_modulo_dbl(v_lh[2], v_rh[2]);
	return v_out;
}

ijk_inl doublev ijkVecModSafe3dv(double3 v_out, double3 const v_lh, double3 const v_rh)
{
	v_out[0] = ijk_modulo_safe_dbl(v_lh[0], v_rh[0]);
	v_out[1] = ijk_modulo_safe_dbl(v_lh[1], v_rh[1]);
	v_out[2] = ijk_modulo_safe_dbl(v_lh[2], v_rh[2]);
	return v_out;
}

ijk_inl boolv ijkVecEqual3dv(bool3 bv_out, double3 const v_lh, double3 const v_rh)
{
	bv_out[0] = (v_lh[0] == v_rh[0]);
	bv_out[1] = (v_lh[1] == v_rh[1]);
	bv_out[2] = (v_lh[2] == v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal3dv(bool3 bv_out, double3 const v_lh, double3 const v_rh)
{
	bv_out[0] = (v_lh[0] != v_rh[0]);
	bv_out[1] = (v_lh[1] != v_rh[1]);
	bv_out[2] = (v_lh[2] != v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual3dv(bool3 bv_out, double3 const v_lh, double3 const v_rh)
{
	bv_out[0] = (v_lh[0] <= v_rh[0]);
	bv_out[1] = (v_lh[1] <= v_rh[1]);
	bv_out[2] = (v_lh[2] <= v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual3dv(bool3 bv_out, double3 const v_lh, double3 const v_rh)
{
	bv_out[0] = (v_lh[0] >= v_rh[0]);
	bv_out[1] = (v_lh[1] >= v_rh[1]);
	bv_out[2] = (v_lh[2] >= v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecLess3dv(bool3 bv_out, double3 const v_lh, double3 const v_rh)
{
	bv_out[0] = (v_lh[0] < v_rh[0]);
	bv_out[1] = (v_lh[1] < v_rh[1]);
	bv_out[2] = (v_lh[2] < v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater3dv(bool3 bv_out, double3 const v_lh, double3 const v_rh)
{
	bv_out[0] = (v_lh[0] > v_rh[0]);
	bv_out[1] = (v_lh[1] > v_rh[1]);
	bv_out[2] = (v_lh[2] > v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd3dv(bool3 bv_out, double3 const v_lh, double3 const v_rh)
{
	bv_out[0] = (v_lh[0] && v_rh[0]);
	bv_out[1] = (v_lh[1] && v_rh[1]);
	bv_out[2] = (v_lh[2] && v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecNand3dv(bool3 bv_out, double3 const v_lh, double3 const v_rh)
{
	bv_out[0] = !(v_lh[0] && v_rh[0]);
	bv_out[1] = !(v_lh[1] && v_rh[1]);
	bv_out[2] = !(v_lh[2] && v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecOr3dv(bool3 bv_out, double3 const v_lh, double3 const v_rh)
{
	bv_out[0] = (v_lh[0] || v_rh[0]);
	bv_out[1] = (v_lh[1] || v_rh[1]);
	bv_out[2] = (v_lh[2] || v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecNor3dv(bool3 bv_out, double3 const v_lh, double3 const v_rh)
{
	bv_out[0] = !(v_lh[0] || v_rh[0]);
	bv_out[1] = !(v_lh[1] || v_rh[1]);
	bv_out[2] = !(v_lh[2] || v_rh[2]);
	return bv_out;
}

ijk_inl doublev ijkVecCopy3dvz(double3 v_out, double2 const v_xy, f64 const z)
{
	v_out[0] = v_xy[0];
	v_out[1] = v_xy[1];
	v_out[2] = z;
	return v_out;
}

ijk_inl doublev ijkVecCopy3dvs(double3 v_out, f64 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = +s_in;
	return v_out;
}

ijk_inl doublev ijkVecNegate3dvs(double3 v_out, f64 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = -s_in;
	return v_out;
}

ijk_inl boolv ijkVecNot3dvs(bool3 bv_out, f64 const s_in)
{
	bv_out[0] = bv_out[1] = bv_out[2] = !s_in;
	return bv_out;
}

ijk_inl doublev ijkVecAdd3dvs(double3 v_out, double3 const v_lh, f64 const s_rh)
{
	v_out[0] = v_lh[0] + s_rh;
	v_out[1] = v_lh[1] + s_rh;
	v_out[2] = v_lh[2] + s_rh;
	return v_out;
}

ijk_inl doublev ijkVecSub3dvs(double3 v_out, double3 const v_lh, f64 const s_rh)
{
	v_out[0] = v_lh[0] - s_rh;
	v_out[1] = v_lh[1] - s_rh;
	v_out[2] = v_lh[2] - s_rh;
	return v_out;
}

ijk_inl doublev ijkVecMul3dvs(double3 v_out, double3 const v_lh, f64 const s_rh)
{
	v_out[0] = v_lh[0] * s_rh;
	v_out[1] = v_lh[1] * s_rh;
	v_out[2] = v_lh[2] * s_rh;
	return v_out;
}

ijk_inl doublev ijkVecDiv3dvs(double3 v_out, double3 const v_lh, f64 const s_rh)
{
	f64 const s = ijk_recip_dbl(s_rh);
	v_out[0] = v_lh[0] * s;
	v_out[1] = v_lh[1] * s;
	v_out[2] = v_lh[2] * s;
	return v_out;
}

ijk_inl doublev ijkVecDivSafe3dvs(double3 v_out, double3 const v_lh, f64 const s_rh)
{
	f64 const s = ijk_recip_safe_dbl(s_rh);
	v_out[0] = v_lh[0] * s;
	v_out[1] = v_lh[1] * s;
	v_out[2] = v_lh[2] * s;
	return v_out;
}

ijk_inl doublev ijkVecMod3dvs(double3 v_out, double3 const v_lh, f64 const s_rh)
{
	v_out[0] = ijk_modulo_dbl(v_lh[0], s_rh);
	v_out[1] = ijk_modulo_dbl(v_lh[1], s_rh);
	v_out[2] = ijk_modulo_dbl(v_lh[2], s_rh);
	return v_out;
}

ijk_inl doublev ijkVecModSafe3dvs(double3 v_out, double3 const v_lh, f64 const s_rh)
{
	if (s_rh)
	{
		v_out[0] = ijk_modulo_dbl(v_lh[0], s_rh);
		v_out[1] = ijk_modulo_dbl(v_lh[1], s_rh);
		v_out[2] = ijk_modulo_dbl(v_lh[2], s_rh);
		return v_out;
	}
	return ijkVecCopy3dv(v_out, v_lh);
}

ijk_inl boolv ijkVecEqual3dvs(bool3 bv_out, double3 const v_lh, f64 const s_rh)
{
	bv_out[0] = (v_lh[0] == s_rh);
	bv_out[1] = (v_lh[1] == s_rh);
	bv_out[2] = (v_lh[2] == s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecInequal3dvs(bool3 bv_out, double3 const v_lh, f64 const s_rh)
{
	bv_out[0] = (v_lh[0] != s_rh);
	bv_out[1] = (v_lh[1] != s_rh);
	bv_out[2] = (v_lh[2] != s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual3dvs(bool3 bv_out, double3 const v_lh, f64 const s_rh)
{
	bv_out[0] = (v_lh[0] <= s_rh);
	bv_out[1] = (v_lh[1] <= s_rh);
	bv_out[2] = (v_lh[2] <= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual3dvs(bool3 bv_out, double3 const v_lh, f64 const s_rh)
{
	bv_out[0] = (v_lh[0] >= s_rh);
	bv_out[1] = (v_lh[1] >= s_rh);
	bv_out[2] = (v_lh[2] >= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLess3dvs(bool3 bv_out, double3 const v_lh, f64 const s_rh)
{
	bv_out[0] = (v_lh[0] < s_rh);
	bv_out[1] = (v_lh[1] < s_rh);
	bv_out[2] = (v_lh[2] < s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreater3dvs(bool3 bv_out, double3 const v_lh, f64 const s_rh)
{
	bv_out[0] = (v_lh[0] > s_rh);
	bv_out[1] = (v_lh[1] > s_rh);
	bv_out[2] = (v_lh[2] > s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecAnd3dvs(bool3 bv_out, double3 const v_lh, f64 const s_rh)
{
	bv_out[0] = (v_lh[0] && s_rh);
	bv_out[1] = (v_lh[1] && s_rh);
	bv_out[2] = (v_lh[2] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNand3dvs(bool3 bv_out, double3 const v_lh, f64 const s_rh)
{
	bv_out[0] = !(v_lh[0] && s_rh);
	bv_out[1] = !(v_lh[1] && s_rh);
	bv_out[2] = !(v_lh[2] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecOr3dvs(bool3 bv_out, double3 const v_lh, f64 const s_rh)
{
	bv_out[0] = (v_lh[0] || s_rh);
	bv_out[1] = (v_lh[1] || s_rh);
	bv_out[2] = (v_lh[2] || s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNor3dvs(bool3 bv_out, double3 const v_lh, f64 const s_rh)
{
	bv_out[0] = !(v_lh[0] || s_rh);
	bv_out[1] = !(v_lh[1] || s_rh);
	bv_out[2] = !(v_lh[2] || s_rh);
	return bv_out;
}

ijk_inl doublev ijkVecCopy3dxv(double3 v_out, f64 const x, double2 const v_yz)
{
	v_out[0] = x;
	v_out[1] = v_yz[0];
	v_out[2] = v_yz[1];
	return v_out;
}

ijk_inl doublev ijkVecAdd3dsv(double3 v_out, f64 const s_lh, double3 const v_rh)
{
	v_out[0] = s_lh + v_rh[0];
	v_out[1] = s_lh + v_rh[1];
	v_out[2] = s_lh + v_rh[2];
	return v_out;
}

ijk_inl doublev ijkVecSub3dsv(double3 v_out, f64 const s_lh, double3 const v_rh)
{
	v_out[0] = s_lh - v_rh[0];
	v_out[1] = s_lh - v_rh[1];
	v_out[2] = s_lh - v_rh[2];
	return v_out;
}

ijk_inl doublev ijkVecMul3dsv(double3 v_out, f64 const s_lh, double3 const v_rh)
{
	v_out[0] = s_lh * v_rh[0];
	v_out[1] = s_lh * v_rh[1];
	v_out[2] = s_lh * v_rh[2];
	return v_out;
}

ijk_inl doublev ijkVecDiv3dsv(double3 v_out, f64 const s_lh, double3 const v_rh)
{
	v_out[0] = s_lh / v_rh[0];
	v_out[1] = s_lh / v_rh[1];
	v_out[2] = s_lh / v_rh[2];
	return v_out;
}

ijk_inl doublev ijkVecDivSafe3dsv(double3 v_out, f64 const s_lh, double3 const v_rh)
{
	v_out[0] = ijk_divide_safe_dbl(s_lh, v_rh[0]);
	v_out[1] = ijk_divide_safe_dbl(s_lh, v_rh[1]);
	v_out[2] = ijk_divide_safe_dbl(s_lh, v_rh[2]);
	return v_out;
}

ijk_inl doublev ijkVecMod3dsv(double3 v_out, f64 const s_lh, double3 const v_rh)
{
	v_out[0] = ijk_modulo_dbl(s_lh, v_rh[0]);
	v_out[1] = ijk_modulo_dbl(s_lh, v_rh[1]);
	v_out[2] = ijk_modulo_dbl(s_lh, v_rh[2]);
	return v_out;
}

ijk_inl doublev ijkVecModSafe3dsv(double3 v_out, f64 const s_lh, double3 const v_rh)
{
	v_out[0] = ijk_modulo_safe_dbl(s_lh, v_rh[0]);
	v_out[1] = ijk_modulo_safe_dbl(s_lh, v_rh[1]);
	v_out[2] = ijk_modulo_safe_dbl(s_lh, v_rh[2]);
	return v_out;
}

ijk_inl boolv ijkVecEqual3dsv(bool3 bv_out, f64 const s_lh, double3 const v_rh)
{
	bv_out[0] = (s_lh == v_rh[0]);
	bv_out[1] = (s_lh == v_rh[1]);
	bv_out[2] = (s_lh == v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal3dsv(bool3 bv_out, f64 const s_lh, double3 const v_rh)
{
	bv_out[0] = (s_lh != v_rh[0]);
	bv_out[1] = (s_lh != v_rh[1]);
	bv_out[2] = (s_lh != v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual3dsv(bool3 bv_out, f64 const s_lh, double3 const v_rh)
{
	bv_out[0] = (s_lh <= v_rh[0]);
	bv_out[1] = (s_lh <= v_rh[1]);
	bv_out[2] = (s_lh <= v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual3dsv(bool3 bv_out, f64 const s_lh, double3 const v_rh)
{
	bv_out[0] = (s_lh >= v_rh[0]);
	bv_out[1] = (s_lh >= v_rh[1]);
	bv_out[2] = (s_lh >= v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecLess3dsv(bool3 bv_out, f64 const s_lh, double3 const v_rh)
{
	bv_out[0] = (s_lh < v_rh[0]);
	bv_out[1] = (s_lh < v_rh[1]);
	bv_out[2] = (s_lh < v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater3dsv(bool3 bv_out, f64 const s_lh, double3 const v_rh)
{
	bv_out[0] = (s_lh > v_rh[0]);
	bv_out[1] = (s_lh > v_rh[1]);
	bv_out[2] = (s_lh > v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd3dsv(bool3 bv_out, f64 const s_lh, double3 const v_rh)
{
	bv_out[0] = (s_lh && v_rh[0]);
	bv_out[1] = (s_lh && v_rh[1]);
	bv_out[2] = (s_lh && v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecNand3dsv(bool3 bv_out, f64 const s_lh, double3 const v_rh)
{
	bv_out[0] = !(s_lh && v_rh[0]);
	bv_out[1] = !(s_lh && v_rh[1]);
	bv_out[2] = !(s_lh && v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecOr3dsv(bool3 bv_out, f64 const s_lh, double3 const v_rh)
{
	bv_out[0] = (s_lh || v_rh[0]);
	bv_out[1] = (s_lh || v_rh[1]);
	bv_out[2] = (s_lh || v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecNor3dsv(bool3 bv_out, f64 const s_lh, double3 const v_rh)
{
	bv_out[0] = !(s_lh || v_rh[0]);
	bv_out[1] = !(s_lh || v_rh[1]);
	bv_out[2] = !(s_lh || v_rh[2]);
	return bv_out;
}

ijk_inl f64 ijkVecDot3dv(double3 const v_lh, double3 const v_rh)
{
	return (v_lh[0] * v_rh[0] + v_lh[1] * v_rh[1] + v_lh[2] * v_rh[2]);
}

ijk_inl doublev ijkVecCross3dv(double3 v_out, double3 const v_lh, double3 const v_rh)
{
	v_out[0] = (v_lh[1] * v_rh[2] - v_lh[2] * v_rh[1]);
	v_out[1] = (v_lh[2] * v_rh[0] - v_lh[0] * v_rh[2]);
	v_out[2] = (v_lh[0] * v_rh[1] - v_lh[1] * v_rh[0]);
	return v_out;
}


//-----------------------------------------------------------------------------

ijk_inl doublev ijkVecInit4dv(double4 v_out)
{
	v_out[0] = v_out[1] = v_out[2] = v_out[3] = 0;
	return v_out;
}

ijk_inl doublev ijkVecInitElems4dv(double4 v_out, f64 const x, f64 const y, f64 const z, f64 const w)
{
	v_out[0] = x;
	v_out[1] = y;
	v_out[2] = z;
	v_out[3] = w;
	return v_out;
}

ijk_inl doublev ijkVecCopy4dxvw(double4 v_out, f64 const x, double2 const v_yz, f64 const w)
{
	v_out[0] = x;
	v_out[1] = v_yz[0];
	v_out[2] = v_yz[1];
	v_out[3] = w;
	return v_out;
}

ijk_inl doublev ijkVecCopy4dv2(double4 v_out, double2 const v_xy, double2 const v_zw)
{
	v_out[0] = v_xy[0];
	v_out[1] = v_xy[1];
	v_out[2] = v_zw[0];
	v_out[3] = v_zw[1];
	return v_out;
}

ijk_inl doublev ijkVecCopy4dv(double4 v_out, double4 const v_in)
{
	v_out[0] = +v_in[0];
	v_out[1] = +v_in[1];
	v_out[2] = +v_in[2];
	v_out[3] = +v_in[3];
	return v_out;
}

ijk_inl doublev ijkVecNegate4dv(double4 v_out, double4 const v_in)
{
	v_out[0] = -v_in[0];
	v_out[1] = -v_in[1];
	v_out[2] = -v_in[2];
	v_out[3] = -v_in[3];
	return v_out;
}

ijk_inl boolv ijkVecNot4dv(bool4 bv_out, double4 const v_in)
{
	bv_out[0] = !v_in[0];
	bv_out[1] = !v_in[1];
	bv_out[2] = !v_in[2];
	bv_out[3] = !v_in[3];
	return bv_out;
}

ijk_inl doublev ijkVecAdd4dv(double4 v_out, double4 const v_lh, double4 const v_rh)
{
	v_out[0] = v_lh[0] + v_rh[0];
	v_out[1] = v_lh[1] + v_rh[1];
	v_out[2] = v_lh[2] + v_rh[2];
	v_out[3] = v_lh[3] + v_rh[3];
	return v_out;
}

ijk_inl doublev ijkVecSub4dv(double4 v_out, double4 const v_lh, double4 const v_rh)
{
	v_out[0] = v_lh[0] - v_rh[0];
	v_out[1] = v_lh[1] - v_rh[1];
	v_out[2] = v_lh[2] - v_rh[2];
	v_out[3] = v_lh[3] - v_rh[3];
	return v_out;
}

ijk_inl doublev ijkVecMul4dv(double4 v_out, double4 const v_lh, double4 const v_rh)
{
	v_out[0] = v_lh[0] * v_rh[0];
	v_out[1] = v_lh[1] * v_rh[1];
	v_out[2] = v_lh[2] * v_rh[2];
	v_out[3] = v_lh[3] * v_rh[3];
	return v_out;
}

ijk_inl doublev ijkVecDiv4dv(double4 v_out, double4 const v_lh, double4 const v_rh)
{
	v_out[0] = v_lh[0] / v_rh[0];
	v_out[1] = v_lh[1] / v_rh[1];
	v_out[2] = v_lh[2] / v_rh[2];
	v_out[3] = v_lh[3] / v_rh[3];
	return v_out;
}

ijk_inl doublev ijkVecDivSafe4dv(double4 v_out, double4 const v_lh, double4 const v_rh)
{
	v_out[0] = ijk_divide_safe_dbl(v_lh[0], v_rh[0]);
	v_out[1] = ijk_divide_safe_dbl(v_lh[1], v_rh[1]);
	v_out[2] = ijk_divide_safe_dbl(v_lh[2], v_rh[2]);
	v_out[3] = ijk_divide_safe_dbl(v_lh[3], v_rh[3]);
	return v_out;
}

ijk_inl doublev ijkVecMod4dv(double4 v_out, double4 const v_lh, double4 const v_rh)
{
	v_out[0] = ijk_modulo_dbl(v_lh[0], v_rh[0]);
	v_out[1] = ijk_modulo_dbl(v_lh[1], v_rh[1]);
	v_out[2] = ijk_modulo_dbl(v_lh[2], v_rh[2]);
	v_out[3] = ijk_modulo_dbl(v_lh[3], v_rh[3]);
	return v_out;
}

ijk_inl doublev ijkVecModSafe4dv(double4 v_out, double4 const v_lh, double4 const v_rh)
{
	v_out[0] = ijk_modulo_safe_dbl(v_lh[0], v_rh[0]);
	v_out[1] = ijk_modulo_safe_dbl(v_lh[1], v_rh[1]);
	v_out[2] = ijk_modulo_safe_dbl(v_lh[2], v_rh[2]);
	v_out[3] = ijk_modulo_safe_dbl(v_lh[3], v_rh[3]);
	return v_out;
}

ijk_inl boolv ijkVecEqual4dv(bool4 bv_out, double4 const v_lh, double4 const v_rh)
{
	bv_out[0] = (v_lh[0] == v_rh[0]);
	bv_out[1] = (v_lh[1] == v_rh[1]);
	bv_out[2] = (v_lh[2] == v_rh[2]);
	bv_out[3] = (v_lh[3] == v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal4dv(bool4 bv_out, double4 const v_lh, double4 const v_rh)
{
	bv_out[0] = (v_lh[0] != v_rh[0]);
	bv_out[1] = (v_lh[1] != v_rh[1]);
	bv_out[2] = (v_lh[2] != v_rh[2]);
	bv_out[3] = (v_lh[3] != v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual4dv(bool4 bv_out, double4 const v_lh, double4 const v_rh)
{
	bv_out[0] = (v_lh[0] <= v_rh[0]);
	bv_out[1] = (v_lh[1] <= v_rh[1]);
	bv_out[2] = (v_lh[2] <= v_rh[2]);
	bv_out[3] = (v_lh[3] <= v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual4dv(bool4 bv_out, double4 const v_lh, double4 const v_rh)
{
	bv_out[0] = (v_lh[0] >= v_rh[0]);
	bv_out[1] = (v_lh[1] >= v_rh[1]);
	bv_out[2] = (v_lh[2] >= v_rh[2]);
	bv_out[3] = (v_lh[3] >= v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecLess4dv(bool4 bv_out, double4 const v_lh, double4 const v_rh)
{
	bv_out[0] = (v_lh[0] < v_rh[0]);
	bv_out[1] = (v_lh[1] < v_rh[1]);
	bv_out[2] = (v_lh[2] < v_rh[2]);
	bv_out[3] = (v_lh[3] < v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater4dv(bool4 bv_out, double4 const v_lh, double4 const v_rh)
{
	bv_out[0] = (v_lh[0] > v_rh[0]);
	bv_out[1] = (v_lh[1] > v_rh[1]);
	bv_out[2] = (v_lh[2] > v_rh[2]);
	bv_out[3] = (v_lh[3] > v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd4dv(bool4 bv_out, double4 const v_lh, double4 const v_rh)
{
	bv_out[0] = (v_lh[0] && v_rh[0]);
	bv_out[1] = (v_lh[1] && v_rh[1]);
	bv_out[2] = (v_lh[2] && v_rh[2]);
	bv_out[3] = (v_lh[3] && v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecNand4dv(bool4 bv_out, double4 const v_lh, double4 const v_rh)
{
	bv_out[0] = !(v_lh[0] && v_rh[0]);
	bv_out[1] = !(v_lh[1] && v_rh[1]);
	bv_out[2] = !(v_lh[2] && v_rh[2]);
	bv_out[3] = !(v_lh[3] && v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecOr4dv(bool4 bv_out, double4 const v_lh, double4 const v_rh)
{
	bv_out[0] = (v_lh[0] || v_rh[0]);
	bv_out[1] = (v_lh[1] || v_rh[1]);
	bv_out[2] = (v_lh[2] || v_rh[2]);
	bv_out[3] = (v_lh[3] || v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecNor4dv(bool4 bv_out, double4 const v_lh, double4 const v_rh)
{
	bv_out[0] = !(v_lh[0] || v_rh[0]);
	bv_out[1] = !(v_lh[1] || v_rh[1]);
	bv_out[2] = !(v_lh[2] || v_rh[2]);
	bv_out[3] = !(v_lh[3] || v_rh[3]);
	return bv_out;
}

ijk_inl doublev ijkVecCopy4dvzw(double4 v_out, double2 const v_xy, f64 const z, f64 const w)
{
	v_out[0] = v_xy[0];
	v_out[1] = v_xy[1];
	v_out[2] = z;
	v_out[3] = w;
	return v_out;
}

ijk_inl doublev ijkVecCopy4dvw(double4 v_out, double3 const v_xyz, f64 const w)
{
	v_out[0] = v_xyz[0];
	v_out[1] = v_xyz[1];
	v_out[2] = v_xyz[2];
	v_out[3] = w;
	return v_out;
}

ijk_inl doublev ijkVecCopy4dvs(double4 v_out, f64 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = v_out[3] = +s_in;
	return v_out;
}

ijk_inl doublev ijkVecNegate4dvs(double4 v_out, f64 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = v_out[3] = -s_in;
	return v_out;
}

ijk_inl boolv ijkVecNot4dvs(bool4 bv_out, f64 const s_in)
{
	bv_out[0] = bv_out[1] = bv_out[2] = bv_out[3] = !s_in;
	return bv_out;
}

ijk_inl doublev ijkVecAdd4dvs(double4 v_out, double4 const v_lh, f64 const s_rh)
{
	v_out[0] = v_lh[0] + s_rh;
	v_out[1] = v_lh[1] + s_rh;
	v_out[2] = v_lh[2] + s_rh;
	v_out[3] = v_lh[3] + s_rh;
	return v_out;
}

ijk_inl doublev ijkVecSub4dvs(double4 v_out, double4 const v_lh, f64 const s_rh)
{
	v_out[0] = v_lh[0] - s_rh;
	v_out[1] = v_lh[1] - s_rh;
	v_out[2] = v_lh[2] - s_rh;
	v_out[3] = v_lh[3] - s_rh;
	return v_out;
}

ijk_inl doublev ijkVecMul4dvs(double4 v_out, double4 const v_lh, f64 const s_rh)
{
	v_out[0] = v_lh[0] * s_rh;
	v_out[1] = v_lh[1] * s_rh;
	v_out[2] = v_lh[2] * s_rh;
	v_out[3] = v_lh[3] * s_rh;
	return v_out;
}

ijk_inl doublev ijkVecDiv4dvs(double4 v_out, double4 const v_lh, f64 const s_rh)
{
	f64 const s = ijk_recip_dbl(s_rh);
	v_out[0] = v_lh[0] * s;
	v_out[1] = v_lh[1] * s;
	v_out[2] = v_lh[2] * s;
	v_out[3] = v_lh[3] * s;
	return v_out;
}

ijk_inl doublev ijkVecDivSafe4dvs(double4 v_out, double4 const v_lh, f64 const s_rh)
{
	f64 const s = ijk_recip_safe_dbl(s_rh);
	v_out[0] = v_lh[0] * s;
	v_out[1] = v_lh[1] * s;
	v_out[2] = v_lh[2] * s;
	v_out[3] = v_lh[3] * s;
	return v_out;
}

ijk_inl doublev ijkVecMod4dvs(double4 v_out, double4 const v_lh, f64 const s_rh)
{
	v_out[0] = ijk_modulo_dbl(v_lh[0], s_rh);
	v_out[1] = ijk_modulo_dbl(v_lh[1], s_rh);
	v_out[2] = ijk_modulo_dbl(v_lh[2], s_rh);
	v_out[3] = ijk_modulo_dbl(v_lh[3], s_rh);
	return v_out;
}

ijk_inl doublev ijkVecModSafe4dvs(double4 v_out, double4 const v_lh, f64 const s_rh)
{
	if (s_rh)
	{
		v_out[0] = ijk_modulo_dbl(v_lh[0], s_rh);
		v_out[1] = ijk_modulo_dbl(v_lh[1], s_rh);
		v_out[2] = ijk_modulo_dbl(v_lh[2], s_rh);
		v_out[3] = ijk_modulo_dbl(v_lh[3], s_rh);
		return v_out;
	}
	return ijkVecCopy4dv(v_out, v_lh);
}

ijk_inl boolv ijkVecEqual4dvs(bool4 bv_out, double4 const v_lh, f64 const s_rh)
{
	bv_out[0] = (v_lh[0] == s_rh);
	bv_out[1] = (v_lh[1] == s_rh);
	bv_out[2] = (v_lh[2] == s_rh);
	bv_out[3] = (v_lh[3] == s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecInequal4dvs(bool4 bv_out, double4 const v_lh, f64 const s_rh)
{
	bv_out[0] = (v_lh[0] != s_rh);
	bv_out[1] = (v_lh[1] != s_rh);
	bv_out[2] = (v_lh[2] != s_rh);
	bv_out[3] = (v_lh[3] != s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual4dvs(bool4 bv_out, double4 const v_lh, f64 const s_rh)
{
	bv_out[0] = (v_lh[0] <= s_rh);
	bv_out[1] = (v_lh[1] <= s_rh);
	bv_out[2] = (v_lh[2] <= s_rh);
	bv_out[3] = (v_lh[3] <= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual4dvs(bool4 bv_out, double4 const v_lh, f64 const s_rh)
{
	bv_out[0] = (v_lh[0] >= s_rh);
	bv_out[1] = (v_lh[1] >= s_rh);
	bv_out[2] = (v_lh[2] >= s_rh);
	bv_out[3] = (v_lh[3] >= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLess4dvs(bool4 bv_out, double4 const v_lh, f64 const s_rh)
{
	bv_out[0] = (v_lh[0] < s_rh);
	bv_out[1] = (v_lh[1] < s_rh);
	bv_out[2] = (v_lh[2] < s_rh);
	bv_out[3] = (v_lh[3] < s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreater4dvs(bool4 bv_out, double4 const v_lh, f64 const s_rh)
{
	bv_out[0] = (v_lh[0] > s_rh);
	bv_out[1] = (v_lh[1] > s_rh);
	bv_out[2] = (v_lh[2] > s_rh);
	bv_out[3] = (v_lh[3] > s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecAnd4dvs(bool4 bv_out, double4 const v_lh, f64 const s_rh)
{
	bv_out[0] = (v_lh[0] && s_rh);
	bv_out[1] = (v_lh[1] && s_rh);
	bv_out[2] = (v_lh[2] && s_rh);
	bv_out[3] = (v_lh[3] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNand4dvs(bool4 bv_out, double4 const v_lh, f64 const s_rh)
{
	bv_out[0] = !(v_lh[0] && s_rh);
	bv_out[1] = !(v_lh[1] && s_rh);
	bv_out[2] = !(v_lh[2] && s_rh);
	bv_out[3] = !(v_lh[3] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecOr4dvs(bool4 bv_out, double4 const v_lh, f64 const s_rh)
{
	bv_out[0] = (v_lh[0] || s_rh);
	bv_out[1] = (v_lh[1] || s_rh);
	bv_out[2] = (v_lh[2] || s_rh);
	bv_out[3] = (v_lh[3] || s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNor4dvs(bool4 bv_out, double4 const v_lh, f64 const s_rh)
{
	bv_out[0] = !(v_lh[0] || s_rh);
	bv_out[1] = !(v_lh[1] || s_rh);
	bv_out[2] = !(v_lh[2] || s_rh);
	bv_out[3] = !(v_lh[3] || s_rh);
	return bv_out;
}

ijk_inl doublev ijkVecCopy4dxyv(double4 v_out, f64 const x, f64 const y, double2 const v_zw)
{
	v_out[0] = x;
	v_out[1] = y;
	v_out[2] = v_zw[0];
	v_out[3] = v_zw[1];
	return v_out;
}

ijk_inl doublev ijkVecCopy4dxv(double4 v_out, f64 const x, double3 const v_yzw)
{
	v_out[0] = x;
	v_out[1] = v_yzw[0];
	v_out[2] = v_yzw[1];
	v_out[3] = v_yzw[2];
	return v_out;
}

ijk_inl doublev ijkVecAdd4dsv(double4 v_out, f64 const s_lh, double4 const v_rh)
{
	v_out[0] = s_lh + v_rh[0];
	v_out[1] = s_lh + v_rh[1];
	v_out[2] = s_lh + v_rh[2];
	v_out[3] = s_lh + v_rh[3];
	return v_out;
}

ijk_inl doublev ijkVecSub4dsv(double4 v_out, f64 const s_lh, double4 const v_rh)
{
	v_out[0] = s_lh - v_rh[0];
	v_out[1] = s_lh - v_rh[1];
	v_out[2] = s_lh - v_rh[2];
	v_out[3] = s_lh - v_rh[3];
	return v_out;
}

ijk_inl doublev ijkVecMul4dsv(double4 v_out, f64 const s_lh, double4 const v_rh)
{
	v_out[0] = s_lh * v_rh[0];
	v_out[1] = s_lh * v_rh[1];
	v_out[2] = s_lh * v_rh[2];
	v_out[3] = s_lh * v_rh[3];
	return v_out;
}

ijk_inl doublev ijkVecDiv4dsv(double4 v_out, f64 const s_lh, double4 const v_rh)
{
	v_out[0] = s_lh / v_rh[0];
	v_out[1] = s_lh / v_rh[1];
	v_out[2] = s_lh / v_rh[2];
	v_out[3] = s_lh / v_rh[3];
	return v_out;
}

ijk_inl doublev ijkVecDivSafe4dsv(double4 v_out, f64 const s_lh, double4 const v_rh)
{
	v_out[0] = ijk_divide_safe_dbl(s_lh, v_rh[0]);
	v_out[1] = ijk_divide_safe_dbl(s_lh, v_rh[1]);
	v_out[2] = ijk_divide_safe_dbl(s_lh, v_rh[2]);
	v_out[3] = ijk_divide_safe_dbl(s_lh, v_rh[3]);
	return v_out;
}

ijk_inl doublev ijkVecMod4dsv(double4 v_out, f64 const s_lh, double4 const v_rh)
{
	v_out[0] = ijk_modulo_dbl(s_lh, v_rh[0]);
	v_out[1] = ijk_modulo_dbl(s_lh, v_rh[1]);
	v_out[2] = ijk_modulo_dbl(s_lh, v_rh[2]);
	v_out[3] = ijk_modulo_dbl(s_lh, v_rh[3]);
	return v_out;
}

ijk_inl doublev ijkVecModSafe4dsv(double4 v_out, f64 const s_lh, double4 const v_rh)
{
	v_out[0] = ijk_modulo_safe_dbl(s_lh, v_rh[0]);
	v_out[1] = ijk_modulo_safe_dbl(s_lh, v_rh[1]);
	v_out[2] = ijk_modulo_safe_dbl(s_lh, v_rh[2]);
	v_out[3] = ijk_modulo_safe_dbl(s_lh, v_rh[3]);
	return v_out;
}

ijk_inl boolv ijkVecEqual4dsv(bool4 bv_out, f64 const s_lh, double4 const v_rh)
{
	bv_out[0] = (s_lh == v_rh[0]);
	bv_out[1] = (s_lh == v_rh[1]);
	bv_out[2] = (s_lh == v_rh[2]);
	bv_out[3] = (s_lh == v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal4dsv(bool4 bv_out, f64 const s_lh, double4 const v_rh)
{
	bv_out[0] = (s_lh != v_rh[0]);
	bv_out[1] = (s_lh != v_rh[1]);
	bv_out[2] = (s_lh != v_rh[2]);
	bv_out[3] = (s_lh != v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual4dsv(bool4 bv_out, f64 const s_lh, double4 const v_rh)
{
	bv_out[0] = (s_lh <= v_rh[0]);
	bv_out[1] = (s_lh <= v_rh[1]);
	bv_out[2] = (s_lh <= v_rh[2]);
	bv_out[3] = (s_lh <= v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual4dsv(bool4 bv_out, f64 const s_lh, double4 const v_rh)
{
	bv_out[0] = (s_lh >= v_rh[0]);
	bv_out[1] = (s_lh >= v_rh[1]);
	bv_out[2] = (s_lh >= v_rh[2]);
	bv_out[3] = (s_lh >= v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecLess4dsv(bool4 bv_out, f64 const s_lh, double4 const v_rh)
{
	bv_out[0] = (s_lh < v_rh[0]);
	bv_out[1] = (s_lh < v_rh[1]);
	bv_out[2] = (s_lh < v_rh[2]);
	bv_out[3] = (s_lh < v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater4dsv(bool4 bv_out, f64 const s_lh, double4 const v_rh)
{
	bv_out[0] = (s_lh > v_rh[0]);
	bv_out[1] = (s_lh > v_rh[1]);
	bv_out[2] = (s_lh > v_rh[2]);
	bv_out[3] = (s_lh > v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd4dsv(bool4 bv_out, f64 const s_lh, double4 const v_rh)
{
	bv_out[0] = (s_lh && v_rh[0]);
	bv_out[1] = (s_lh && v_rh[1]);
	bv_out[2] = (s_lh && v_rh[2]);
	bv_out[3] = (s_lh && v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecNand4dsv(bool4 bv_out, f64 const s_lh, double4 const v_rh)
{
	bv_out[0] = !(s_lh && v_rh[0]);
	bv_out[1] = !(s_lh && v_rh[1]);
	bv_out[2] = !(s_lh && v_rh[2]);
	bv_out[3] = !(s_lh && v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecOr4dsv(bool4 bv_out, f64 const s_lh, double4 const v_rh)
{
	bv_out[0] = (s_lh || v_rh[0]);
	bv_out[1] = (s_lh || v_rh[1]);
	bv_out[2] = (s_lh || v_rh[2]);
	bv_out[3] = (s_lh || v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecNor4dsv(bool4 bv_out, f64 const s_lh, double4 const v_rh)
{
	bv_out[0] = !(s_lh || v_rh[0]);
	bv_out[1] = !(s_lh || v_rh[1]);
	bv_out[2] = !(s_lh || v_rh[2]);
	bv_out[3] = !(s_lh || v_rh[3]);
	return bv_out;
}

ijk_inl f64 ijkVecDot4dv(double4 const v_lh, double4 const v_rh)
{
	return (v_lh[0] * v_rh[0] + v_lh[1] * v_rh[1] + v_lh[2] * v_rh[2] + v_lh[3] * v_rh[3]);
}

ijk_inl doublev ijkVecCross4dv(double4 v_out, double4 const v_lh, double4 const v_rh)
{
	v_out[3] = 0;
	return ijkVecCross3dv(v_out, v_lh, v_rh);
}


//-----------------------------------------------------------------------------

ijk_inl double ijkVecAbs1d(double const s)
{
	return ijkVecAbs1ds(s);
}

ijk_inl double ijkVecSgn1d(double const s)
{
	return ijkVecSgn1ds(s);
}

ijk_inl double ijkVecDot1d(double const s_lh, double const s_rh)
{
	return ijkVecDot1ds(s_lh, s_rh);
}

ijk_inl double ijkVecLengthSq1d(double const s)
{
	return ijkVecLengthSq1ds(s);
}

ijk_inl double ijkVecLength1d(double const s)
{
	return ijkVecLength1ds(s);
}

ijk_inl double ijkVecLengthSqInv1d(double const s)
{
	return ijkVecLengthSqInv1ds(s);
}

ijk_inl double ijkVecLengthInv1d(double const s)
{
	return ijkVecLengthInv1ds(s);
}

ijk_inl double ijkVecNormalize1d(double const s)
{
	return ijkVecNormalize1ds(s);
}

ijk_inl double ijkVecNormalizeGetLength1d(double const s, double* const length_out)
{
	return ijkVecNormalizeGetLength1ds(s, (f64*)length_out);
}

ijk_inl double ijkVecNormalizeGetLengthInv1d(double const s, double* const lengthInv_out)
{
	return ijkVecNormalizeGetLengthInv1ds(s, (f64*)lengthInv_out);
}


//-----------------------------------------------------------------------------

ijk_inl dvec2 ijkVecInit2d()
{
	dvec2 const v_out = { 0, 0 };
	return v_out;
}

ijk_inl dvec2 ijkVecInitElems2d(double const x, double const y)
{
	dvec2 const v_out = { x, y };
	return v_out;
}

ijk_inl dvec2 ijkVecCopy2d(dvec2 const v_in)
{
	dvec2 const v_out = { +v_in.x, +v_in.y };
	return v_out;
}

ijk_inl dvec2 ijkVecNegate2d(dvec2 const v_in)
{
	dvec2 const v_out = { -v_in.x, -v_in.y };
	return v_out;
}

ijk_inl bvec2 ijkVecNot2d(dvec2 const v_in)
{
	bvec2 const bv_out = { !v_in.x, !v_in.y };
	return bv_out;
}

ijk_inl dvec2 ijkVecAdd2d(dvec2 const v_lh, dvec2 const v_rh)
{
	dvec2 const v_out = {
		v_lh.x + v_rh.x,
		v_lh.y + v_rh.y,
	};
	return v_out;
}

ijk_inl dvec2 ijkVecSub2d(dvec2 const v_lh, dvec2 const v_rh)
{
	dvec2 const v_out = {
		v_lh.x - v_rh.x,
		v_lh.y - v_rh.y,
	};
	return v_out;
}

ijk_inl dvec2 ijkVecMul2d(dvec2 const v_lh, dvec2 const v_rh)
{
	dvec2 const v_out = {
		v_lh.x * v_rh.x,
		v_lh.y * v_rh.y,
	};
	return v_out;
}

ijk_inl dvec2 ijkVecDiv2d(dvec2 const v_lh, dvec2 const v_rh)
{
	dvec2 const v_out = {
		v_lh.x / v_rh.x,
		v_lh.y / v_rh.y,
	};
	return v_out;
}

ijk_inl dvec2 ijkVecDivSafe2d(dvec2 const v_lh, dvec2 const v_rh)
{
	dvec2 const v_out = {
		ijk_divide_safe_dbl(v_lh.x, v_rh.x),
		ijk_divide_safe_dbl(v_lh.y, v_rh.y),
	};
	return v_out;
}

ijk_inl dvec2 ijkVecMod2d(dvec2 const v_lh, dvec2 const v_rh)
{
	dvec2 const v_out = {
		ijk_modulo_dbl(v_lh.x, v_rh.x),
		ijk_modulo_dbl(v_lh.y, v_rh.y),
	};
	return v_out;
}

ijk_inl dvec2 ijkVecModSafe2d(dvec2 const v_lh, dvec2 const v_rh)
{
	dvec2 const v_out = {
		ijk_modulo_safe_dbl(v_lh.x, v_rh.x),
		ijk_modulo_safe_dbl(v_lh.y, v_rh.y),
	};
	return v_out;
}

ijk_inl bvec2 ijkVecEqual2d(dvec2 const v_lh, dvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x == v_rh.x),
		(v_lh.y == v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecInequal2d(dvec2 const v_lh, dvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x != v_rh.x),
		(v_lh.y != v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLessEqual2d(dvec2 const v_lh, dvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x <= v_rh.x),
		(v_lh.y <= v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreaterEqual2d(dvec2 const v_lh, dvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x >= v_rh.x),
		(v_lh.y >= v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLess2d(dvec2 const v_lh, dvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x < v_rh.x),
		(v_lh.y < v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreater2d(dvec2 const v_lh, dvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x > v_rh.x),
		(v_lh.y > v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecAnd2d(dvec2 const v_lh, dvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x && v_rh.x),
		(v_lh.y && v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNand2d(dvec2 const v_lh, dvec2 const v_rh)
{
	bvec2 const bv_out = {
		!(v_lh.x && v_rh.x),
		!(v_lh.y && v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecOr2d(dvec2 const v_lh, dvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x || v_rh.x),
		(v_lh.y || v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNor2d(dvec2 const v_lh, dvec2 const v_rh)
{
	bvec2 const bv_out = {
		!(v_lh.x || v_rh.x),
		!(v_lh.y || v_rh.y),
	};
	return bv_out;
}

ijk_inl dvec2 ijkVecCopy2ds(double const s_in)
{
	dvec2 const v_out = { s_in, s_in };
	return v_out;
}

ijk_inl dvec2 ijkVecNegate2ds(double const s_in)
{
	double const s = -s_in;
	dvec2 const v_out = { s, s };
	return v_out;
}

ijk_inl bvec2 ijkVecNot2ds(double const s_in)
{
	bool const s = !s_in;
	bvec2 const bv_out = { s, s };
	return bv_out;
}

ijk_inl dvec2 ijkVecAdd2ds(dvec2 const v_lh, double const s_rh)
{
	dvec2 const v_out = {
		v_lh.x + s_rh,
		v_lh.y + s_rh,
	};
	return v_out;
}

ijk_inl dvec2 ijkVecSub2ds(dvec2 const v_lh, double const s_rh)
{
	dvec2 const v_out = {
		v_lh.x - s_rh,
		v_lh.y - s_rh,
	};
	return v_out;
}

ijk_inl dvec2 ijkVecMul2ds(dvec2 const v_lh, double const s_rh)
{
	dvec2 const v_out = {
		v_lh.x * s_rh,
		v_lh.y * s_rh,
	};
	return v_out;
}

ijk_inl dvec2 ijkVecDiv2ds(dvec2 const v_lh, double const s_rh)
{
	f64 const s = ijk_recip_dbl(s_rh);
	dvec2 const v_out = {
		v_lh.x * s,
		v_lh.y * s,
	};
	return v_out;
}

ijk_inl dvec2 ijkVecDivSafe2ds(dvec2 const v_lh, double const s_rh)
{
	f64 const s = ijk_recip_safe_dbl(s_rh);
	dvec2 const v_out = {
		v_lh.x * s,
		v_lh.y * s,
	};
	return v_out;
}

ijk_inl dvec2 ijkVecMod2ds(dvec2 const v_lh, double const s_rh)
{
	dvec2 const v_out = {
		ijk_modulo_dbl(v_lh.x, s_rh),
		ijk_modulo_dbl(v_lh.y, s_rh),
	};
	return v_out;
}

ijk_inl dvec2 ijkVecModSafe2ds(dvec2 const v_lh, double const s_rh)
{
	if (s_rh)
	{
		dvec2 const v_out = {
			ijk_modulo_dbl(v_lh.x, s_rh),
			ijk_modulo_dbl(v_lh.y, s_rh),
		};
		return v_out;
	}
	return v_lh;
}

ijk_inl bvec2 ijkVecEqual2ds(dvec2 const v_lh, double const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x == s_rh),
		(v_lh.y == s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecInequal2ds(dvec2 const v_lh, double const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x != s_rh),
		(v_lh.y != s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLessEqual2ds(dvec2 const v_lh, double const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x <= s_rh),
		(v_lh.y <= s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreaterEqual2ds(dvec2 const v_lh, double const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x >= s_rh),
		(v_lh.y >= s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLess2ds(dvec2 const v_lh, double const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x < s_rh),
		(v_lh.y < s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreater2ds(dvec2 const v_lh, double const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x > s_rh),
		(v_lh.y > s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecAnd2ds(dvec2 const v_lh, double const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x && s_rh),
		(v_lh.y && s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNand2ds(dvec2 const v_lh, double const s_rh)
{
	bvec2 const bv_out = {
		!(v_lh.x && s_rh),
		!(v_lh.y && s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecOr2ds(dvec2 const v_lh, double const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x || s_rh),
		(v_lh.y || s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNor2ds(dvec2 const v_lh, double const s_rh)
{
	bvec2 const bv_out = {
		!(v_lh.x || s_rh),
		!(v_lh.y || s_rh),
	};
	return bv_out;
}

ijk_inl dvec2 ijkVecAdd2sd(double const s_lh, dvec2 const v_rh)
{
	dvec2 const v_out = {
		s_lh + v_rh.x,
		s_lh + v_rh.y,
	};
	return v_out;
}

ijk_inl dvec2 ijkVecSub2sd(double const s_lh, dvec2 const v_rh)
{
	dvec2 const v_out = {
		s_lh - v_rh.x,
		s_lh - v_rh.y,
	};
	return v_out;
}

ijk_inl dvec2 ijkVecMul2sd(double const s_lh, dvec2 const v_rh)
{
	dvec2 const v_out = {
		s_lh * v_rh.x,
		s_lh * v_rh.y,
	};
	return v_out;
}

ijk_inl dvec2 ijkVecDiv2sd(double const s_lh, dvec2 const v_rh)
{
	dvec2 const v_out = {
		s_lh / v_rh.x,
		s_lh / v_rh.y,
	};
	return v_out;
}

ijk_inl dvec2 ijkVecDivSafe2sd(double const s_lh, dvec2 const v_rh)
{
	dvec2 const v_out = {
		ijk_divide_safe_dbl(s_lh, v_rh.x),
		ijk_divide_safe_dbl(s_lh, v_rh.y),
	};
	return v_out;
}

ijk_inl dvec2 ijkVecMod2sd(double const s_lh, dvec2 const v_rh)
{
	dvec2 const v_out = {
		ijk_modulo_dbl(s_lh, v_rh.x),
		ijk_modulo_dbl(s_lh, v_rh.y),
	};
	return v_out;
}

ijk_inl dvec2 ijkVecModSafe2sd(double const s_lh, dvec2 const v_rh)
{
	dvec2 const v_out = {
		ijk_modulo_safe_dbl((f64)s_lh, v_rh.x),
		ijk_modulo_safe_dbl((f64)s_lh, v_rh.y),
	};
	return v_out;
}

ijk_inl bvec2 ijkVecEqual2sd(double const s_lh, dvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh == v_rh.x),
		(s_lh == v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecInequal2sd(double const s_lh, dvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh != v_rh.x),
		(s_lh != v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLessEqual2sd(double const s_lh, dvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh <= v_rh.x),
		(s_lh <= v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreaterEqual2sd(double const s_lh, dvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh >= v_rh.x),
		(s_lh >= v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLess2sd(double const s_lh, dvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh < v_rh.x),
		(s_lh < v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreater2sd(double const s_lh, dvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh > v_rh.x),
		(s_lh > v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecAnd2sd(double const s_lh, dvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh && v_rh.x),
		(s_lh && v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNand2sd(double const s_lh, dvec2 const v_rh)
{
	bvec2 const bv_out = {
		!(s_lh && v_rh.x),
		!(s_lh && v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecOr2sd(double const s_lh, dvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh || v_rh.x),
		(s_lh || v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNor2sd(double const s_lh, dvec2 const v_rh)
{
	bvec2 const bv_out = {
		!(s_lh || v_rh.x),
		!(s_lh || v_rh.y),
	};
	return bv_out;
}

ijk_inl double ijkVecDot2d(dvec2 const v_lh, dvec2 const v_rh)
{
	return ijkVecDot2dv(v_lh.xy, v_rh.xy);
}

ijk_inl double ijkVecCross2d(dvec2 const v_lh, dvec2 const v_rh)
{
	return ijkVecCross2dv(v_lh.xy, v_rh.xy);
}


//-----------------------------------------------------------------------------

ijk_inl dvec3 ijkVecInit3d()
{
	dvec3 const v_out = { 0, 0, 0 };
	return v_out;
}

ijk_inl dvec3 ijkVecInitElems3d(double const x, double const y, double const z)
{
	dvec3 const v_out = { x, y, z };
	return v_out;
}

ijk_inl dvec3 ijkVecCopy3d(dvec3 const v_in)
{
	dvec3 const v_out = { +v_in.x, +v_in.y, +v_in.z };
	return v_out;
}

ijk_inl dvec3 ijkVecNegate3d(dvec3 const v_in)
{
	dvec3 const v_out = { -v_in.x, -v_in.y, -v_in.z };
	return v_out;
}

ijk_inl bvec3 ijkVecNot3d(dvec3 const v_in)
{
	bvec3 const bv_out = { !v_in.x, !v_in.y, !v_in.z };
	return bv_out;
}

ijk_inl dvec3 ijkVecAdd3d(dvec3 const v_lh, dvec3 const v_rh)
{
	dvec3 const v_out = {
		v_lh.x + v_rh.x,
		v_lh.y + v_rh.y,
		v_lh.z + v_rh.z,
	};
	return v_out;
}

ijk_inl dvec3 ijkVecSub3d(dvec3 const v_lh, dvec3 const v_rh)
{
	dvec3 const v_out = {
		v_lh.x - v_rh.x,
		v_lh.y - v_rh.y,
		v_lh.z - v_rh.z,
	};
	return v_out;
}

ijk_inl dvec3 ijkVecMul3d(dvec3 const v_lh, dvec3 const v_rh)
{
	dvec3 const v_out = {
		v_lh.x * v_rh.x,
		v_lh.y * v_rh.y,
		v_lh.z * v_rh.z,
	};
	return v_out;
}

ijk_inl dvec3 ijkVecDiv3d(dvec3 const v_lh, dvec3 const v_rh)
{
	dvec3 const v_out = {
		v_lh.x / v_rh.x,
		v_lh.y / v_rh.y,
		v_lh.z / v_rh.z,
	};
	return v_out;
}

ijk_inl dvec3 ijkVecDivSafe3d(dvec3 const v_lh, dvec3 const v_rh)
{
	dvec3 const v_out = {
		ijk_divide_safe_dbl(v_lh.x, v_rh.x),
		ijk_divide_safe_dbl(v_lh.y, v_rh.y),
		ijk_divide_safe_dbl(v_lh.z, v_rh.z),
	};
	return v_out;
}

ijk_inl dvec3 ijkVecMod3d(dvec3 const v_lh, dvec3 const v_rh)
{
	dvec3 const v_out = {
		ijk_modulo_dbl(v_lh.x, v_rh.x),
		ijk_modulo_dbl(v_lh.y, v_rh.y),
		ijk_modulo_dbl(v_lh.z, v_rh.z),
	};
	return v_out;
}

ijk_inl dvec3 ijkVecModSafe3d(dvec3 const v_lh, dvec3 const v_rh)
{
	dvec3 const v_out = {
		ijk_modulo_safe_dbl(v_lh.x, v_rh.x),
		ijk_modulo_safe_dbl(v_lh.y, v_rh.y),
		ijk_modulo_safe_dbl(v_lh.z, v_rh.z),
	};
	return v_out;
}

ijk_inl bvec3 ijkVecEqual3d(dvec3 const v_lh, dvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x == v_rh.x),
		(v_lh.y == v_rh.y),
		(v_lh.z == v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecInequal3d(dvec3 const v_lh, dvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x != v_rh.x),
		(v_lh.y != v_rh.y),
		(v_lh.z != v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLessEqual3d(dvec3 const v_lh, dvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x <= v_rh.x),
		(v_lh.y <= v_rh.y),
		(v_lh.z <= v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreaterEqual3d(dvec3 const v_lh, dvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x >= v_rh.x),
		(v_lh.y >= v_rh.y),
		(v_lh.z >= v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLess3d(dvec3 const v_lh, dvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x < v_rh.x),
		(v_lh.y < v_rh.y),
		(v_lh.z < v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreater3d(dvec3 const v_lh, dvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x > v_rh.x),
		(v_lh.y > v_rh.y),
		(v_lh.z > v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecAnd3d(dvec3 const v_lh, dvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x && v_rh.x),
		(v_lh.y && v_rh.y),
		(v_lh.z && v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNand3d(dvec3 const v_lh, dvec3 const v_rh)
{
	bvec3 const bv_out = {
		!(v_lh.x && v_rh.x),
		!(v_lh.y && v_rh.y),
		!(v_lh.z && v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecOr3d(dvec3 const v_lh, dvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x || v_rh.x),
		(v_lh.y || v_rh.y),
		(v_lh.z || v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNor3d(dvec3 const v_lh, dvec3 const v_rh)
{
	bvec3 const bv_out = {
		!(v_lh.x || v_rh.x),
		!(v_lh.y || v_rh.y),
		!(v_lh.z || v_rh.z),
	};
	return bv_out;
}

ijk_inl dvec3 ijkVecCopy3dz(dvec2 const v_xy, double const z)
{
	dvec3 const v_out = { v_xy.x, v_xy.y, z };
	return v_out;
}

ijk_inl dvec3 ijkVecCopy3ds(double const s_in)
{
	dvec3 const v_out = { s_in, s_in, s_in };
	return v_out;
}

ijk_inl dvec3 ijkVecNegate3ds(double const s_in)
{
	double const s = -s_in;
	dvec3 const v_out = { s, s, s };
	return v_out;
}

ijk_inl bvec3 ijkVecNot3ds(double const s_in)
{
	bool const s = !s_in;
	bvec3 const bv_out = { s, s, s };
	return bv_out;
}

ijk_inl dvec3 ijkVecAdd3ds(dvec3 const v_lh, double const s_rh)
{
	dvec3 const v_out = {
		v_lh.x + s_rh,
		v_lh.y + s_rh,
		v_lh.z + s_rh,
	};
	return v_out;
}

ijk_inl dvec3 ijkVecSub3ds(dvec3 const v_lh, double const s_rh)
{
	dvec3 const v_out = {
		v_lh.x - s_rh,
		v_lh.y - s_rh,
		v_lh.z - s_rh,
	};
	return v_out;
}

ijk_inl dvec3 ijkVecMul3ds(dvec3 const v_lh, double const s_rh)
{
	dvec3 const v_out = {
		v_lh.x * s_rh,
		v_lh.y * s_rh,
		v_lh.z * s_rh,
	};
	return v_out;
}

ijk_inl dvec3 ijkVecDiv3ds(dvec3 const v_lh, double const s_rh)
{
	f64 const s = ijk_recip_dbl(s_rh);
	dvec3 const v_out = {
		v_lh.x * s,
		v_lh.y * s,
		v_lh.z * s,
	};
	return v_out;
}

ijk_inl dvec3 ijkVecDivSafe3ds(dvec3 const v_lh, double const s_rh)
{
	f64 const s = ijk_recip_safe_dbl(s_rh);
	dvec3 const v_out = {
		v_lh.x * s,
		v_lh.y * s,
		v_lh.z * s,
	};
	return v_out;
}

ijk_inl dvec3 ijkVecMod3ds(dvec3 const v_lh, double const s_rh)
{
	dvec3 const v_out = {
		ijk_modulo_dbl(v_lh.x, s_rh),
		ijk_modulo_dbl(v_lh.y, s_rh),
		ijk_modulo_dbl(v_lh.z, s_rh),
	};
	return v_out;
}

ijk_inl dvec3 ijkVecModSafe3ds(dvec3 const v_lh, double const s_rh)
{
	if (s_rh)
	{
		dvec3 const v_out = {
			ijk_modulo_dbl(v_lh.x, s_rh),
			ijk_modulo_dbl(v_lh.y, s_rh),
			ijk_modulo_dbl(v_lh.z, s_rh),
		};
		return v_out;
	}
	return v_lh;
}

ijk_inl bvec3 ijkVecEqual3ds(dvec3 const v_lh, double const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x == s_rh),
		(v_lh.y == s_rh),
		(v_lh.z == s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecInequal3ds(dvec3 const v_lh, double const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x != s_rh),
		(v_lh.y != s_rh),
		(v_lh.z != s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLessEqual3ds(dvec3 const v_lh, double const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x <= s_rh),
		(v_lh.y <= s_rh),
		(v_lh.z <= s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreaterEqual3ds(dvec3 const v_lh, double const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x >= s_rh),
		(v_lh.y >= s_rh),
		(v_lh.z >= s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLess3ds(dvec3 const v_lh, double const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x < s_rh),
		(v_lh.y < s_rh),
		(v_lh.z < s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreater3ds(dvec3 const v_lh, double const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x > s_rh),
		(v_lh.y > s_rh),
		(v_lh.z > s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecAnd3ds(dvec3 const v_lh, double const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x && s_rh),
		(v_lh.y && s_rh),
		(v_lh.z && s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNand3ds(dvec3 const v_lh, double const s_rh)
{
	bvec3 const bv_out = {
		!(v_lh.x && s_rh),
		!(v_lh.y && s_rh),
		!(v_lh.z && s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecOr3ds(dvec3 const v_lh, double const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x || s_rh),
		(v_lh.y || s_rh),
		(v_lh.z || s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNor3ds(dvec3 const v_lh, double const s_rh)
{
	bvec3 const bv_out = {
		!(v_lh.x || s_rh),
		!(v_lh.y || s_rh),
		!(v_lh.z || s_rh),
	};
	return bv_out;
}

ijk_inl dvec3 ijkVecCopy3xd(double const x, dvec2 const v_yz)
{
	dvec3 const v_out = { x, v_yz.x, v_yz.y };
	return v_out;
}

ijk_inl dvec3 ijkVecAdd3sd(double const s_lh, dvec3 const v_rh)
{
	dvec3 const v_out = {
		s_lh + v_rh.x,
		s_lh + v_rh.y,
		s_lh + v_rh.z,
	};
	return v_out;
}

ijk_inl dvec3 ijkVecSub3sd(double const s_lh, dvec3 const v_rh)
{
	dvec3 const v_out = {
		s_lh - v_rh.x,
		s_lh - v_rh.y,
		s_lh - v_rh.z,
	};
	return v_out;
}

ijk_inl dvec3 ijkVecMul3sd(double const s_lh, dvec3 const v_rh)
{
	dvec3 const v_out = {
		s_lh * v_rh.x,
		s_lh * v_rh.y,
		s_lh * v_rh.z,
	};
	return v_out;
}

ijk_inl dvec3 ijkVecDiv3sd(double const s_lh, dvec3 const v_rh)
{
	dvec3 const v_out = {
		s_lh / v_rh.x,
		s_lh / v_rh.y,
		s_lh / v_rh.z,
	};
	return v_out;
}

ijk_inl dvec3 ijkVecDivSafe3sd(double const s_lh, dvec3 const v_rh)
{
	dvec3 const v_out = {
		ijk_divide_safe_dbl(s_lh, v_rh.x),
		ijk_divide_safe_dbl(s_lh, v_rh.y),
		ijk_divide_safe_dbl(s_lh, v_rh.z),
	};
	return v_out;
}

ijk_inl dvec3 ijkVecMod3sd(double const s_lh, dvec3 const v_rh)
{
	dvec3 const v_out = {
		ijk_modulo_dbl(s_lh, v_rh.x),
		ijk_modulo_dbl(s_lh, v_rh.y),
		ijk_modulo_dbl(s_lh, v_rh.z),
	};
	return v_out;
}

ijk_inl dvec3 ijkVecModSafe3sd(double const s_lh, dvec3 const v_rh)
{
	dvec3 const v_out = {
		ijk_modulo_safe_dbl((f64)s_lh, v_rh.x),
		ijk_modulo_safe_dbl((f64)s_lh, v_rh.y),
		ijk_modulo_safe_dbl((f64)s_lh, v_rh.z),
	};
	return v_out;
}

ijk_inl bvec3 ijkVecEqual3sd(double const s_lh, dvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh == v_rh.x),
		(s_lh == v_rh.y),
		(s_lh == v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecInequal3sd(double const s_lh, dvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh != v_rh.x),
		(s_lh != v_rh.y),
		(s_lh != v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLessEqual3sd(double const s_lh, dvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh <= v_rh.x),
		(s_lh <= v_rh.y),
		(s_lh <= v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreaterEqual3sd(double const s_lh, dvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh >= v_rh.x),
		(s_lh >= v_rh.y),
		(s_lh >= v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLess3sd(double const s_lh, dvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh < v_rh.x),
		(s_lh < v_rh.y),
		(s_lh < v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreater3sd(double const s_lh, dvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh > v_rh.x),
		(s_lh > v_rh.y),
		(s_lh > v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecAnd3sd(double const s_lh, dvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh && v_rh.x),
		(s_lh && v_rh.y),
		(s_lh && v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNand3sd(double const s_lh, dvec3 const v_rh)
{
	bvec3 const bv_out = {
		!(s_lh && v_rh.x),
		!(s_lh && v_rh.y),
		!(s_lh && v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecOr3sd(double const s_lh, dvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh || v_rh.x),
		(s_lh || v_rh.y),
		(s_lh || v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNor3sd(double const s_lh, dvec3 const v_rh)
{
	bvec3 const bv_out = {
		!(s_lh || v_rh.x),
		!(s_lh || v_rh.y),
		!(s_lh || v_rh.z),
	};
	return bv_out;
}

ijk_inl double ijkVecDot3d(dvec3 const v_lh, dvec3 const v_rh)
{
	return ijkVecDot3dv(v_lh.xyz, v_rh.xyz);
}

ijk_inl dvec3 ijkVecCross3d(dvec3 const v_lh, dvec3 const v_rh)
{
	dvec3 v_out;
	ijkVecCross3dv(v_out.xyz, v_lh.xyz, v_rh.xyz);
	return v_out;
}


//-----------------------------------------------------------------------------

ijk_inl dvec4 ijkVecInit4d()
{
	dvec4 const v_out = { 0, 0, 0, 0 };
	return v_out;
}

ijk_inl dvec4 ijkVecInitElems4d(double const x, double const y, double const z, double const w)
{
	dvec4 const v_out = { x, y, z, w };
	return v_out;
}

ijk_inl dvec4 ijkVecCopy4xdw(double const x, dvec2 const v_yz, double const w)
{
	dvec4 const v_out = { x, v_yz.x, v_yz.y, w };
	return v_out;
}

ijk_inl dvec4 ijkVecCopy4d2(dvec2 const v_xy, dvec2 const v_zw)
{
	dvec4 const v_out = { v_xy.x, v_xy.y, v_zw.x, v_zw.y };
	return v_out;
}

ijk_inl dvec4 ijkVecCopy4d(dvec4 const v_in)
{
	dvec4 const v_out = { +v_in.x, +v_in.y, +v_in.z, +v_in.w };
	return v_out;
}

ijk_inl dvec4 ijkVecNegate4d(dvec4 const v_in)
{
	dvec4 const v_out = { -v_in.x, -v_in.y, -v_in.z, -v_in.w };
	return v_out;
}

ijk_inl bvec4 ijkVecNot4d(dvec4 const v_in)
{
	bvec4 const bv_out = { !v_in.x, !v_in.y, !v_in.z, !v_in.w };
	return bv_out;
}

ijk_inl dvec4 ijkVecAdd4d(dvec4 const v_lh, dvec4 const v_rh)
{
	dvec4 const v_out = {
		v_lh.x + v_rh.x,
		v_lh.y + v_rh.y,
		v_lh.z + v_rh.z,
		v_lh.w + v_rh.w,
	};
	return v_out;
}

ijk_inl dvec4 ijkVecSub4d(dvec4 const v_lh, dvec4 const v_rh)
{
	dvec4 const v_out = {
		v_lh.x - v_rh.x,
		v_lh.y - v_rh.y,
		v_lh.z - v_rh.z,
		v_lh.w - v_rh.w,
	};
	return v_out;
}

ijk_inl dvec4 ijkVecMul4d(dvec4 const v_lh, dvec4 const v_rh)
{
	dvec4 const v_out = {
		v_lh.x * v_rh.x,
		v_lh.y * v_rh.y,
		v_lh.z * v_rh.z,
		v_lh.w * v_rh.w,
	};
	return v_out;
}

ijk_inl dvec4 ijkVecDiv4d(dvec4 const v_lh, dvec4 const v_rh)
{
	dvec4 const v_out = {
		v_lh.x / v_rh.x,
		v_lh.y / v_rh.y,
		v_lh.z / v_rh.z,
		v_lh.w / v_rh.w,
	};
	return v_out;
}

ijk_inl dvec4 ijkVecDivSafe4d(dvec4 const v_lh, dvec4 const v_rh)
{
	dvec4 const v_out = {
		ijk_divide_safe_dbl(v_lh.x, v_rh.x),
		ijk_divide_safe_dbl(v_lh.y, v_rh.y),
		ijk_divide_safe_dbl(v_lh.z, v_rh.z),
		ijk_divide_safe_dbl(v_lh.w, v_rh.w),
	};
	return v_out;
}

ijk_inl dvec4 ijkVecMod4d(dvec4 const v_lh, dvec4 const v_rh)
{
	dvec4 const v_out = {
		ijk_modulo_dbl(v_lh.x, v_rh.x),
		ijk_modulo_dbl(v_lh.y, v_rh.y),
		ijk_modulo_dbl(v_lh.z, v_rh.z),
		ijk_modulo_dbl(v_lh.w, v_rh.w),
	};
	return v_out;
}

ijk_inl dvec4 ijkVecModSafe4d(dvec4 const v_lh, dvec4 const v_rh)
{
	dvec4 const v_out = {
		ijk_modulo_safe_dbl(v_lh.x, v_rh.x),
		ijk_modulo_safe_dbl(v_lh.y, v_rh.y),
		ijk_modulo_safe_dbl(v_lh.z, v_rh.z),
		ijk_modulo_safe_dbl(v_lh.w, v_rh.w),
	};
	return v_out;
}

ijk_inl bvec4 ijkVecEqual4d(dvec4 const v_lh, dvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x == v_rh.x),
		(v_lh.y == v_rh.y),
		(v_lh.z == v_rh.z),
		(v_lh.w == v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecInequal4d(dvec4 const v_lh, dvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x != v_rh.x),
		(v_lh.y != v_rh.y),
		(v_lh.z != v_rh.z),
		(v_lh.w != v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLessEqual4d(dvec4 const v_lh, dvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x <= v_rh.x),
		(v_lh.y <= v_rh.y),
		(v_lh.z <= v_rh.z),
		(v_lh.w <= v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreaterEqual4d(dvec4 const v_lh, dvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x >= v_rh.x),
		(v_lh.y >= v_rh.y),
		(v_lh.z >= v_rh.z),
		(v_lh.w >= v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLess4d(dvec4 const v_lh, dvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x < v_rh.x),
		(v_lh.y < v_rh.y),
		(v_lh.z < v_rh.z),
		(v_lh.w < v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreater4d(dvec4 const v_lh, dvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x > v_rh.x),
		(v_lh.y > v_rh.y),
		(v_lh.z > v_rh.z),
		(v_lh.w > v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecAnd4d(dvec4 const v_lh, dvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x && v_rh.x),
		(v_lh.y && v_rh.y),
		(v_lh.z && v_rh.z),
		(v_lh.w && v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNand4d(dvec4 const v_lh, dvec4 const v_rh)
{
	bvec4 const bv_out = {
		!(v_lh.x && v_rh.x),
		!(v_lh.y && v_rh.y),
		!(v_lh.z && v_rh.z),
		!(v_lh.w && v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecOr4d(dvec4 const v_lh, dvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x || v_rh.x),
		(v_lh.y || v_rh.y),
		(v_lh.z || v_rh.z),
		(v_lh.w || v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNor4d(dvec4 const v_lh, dvec4 const v_rh)
{
	bvec4 const bv_out = {
		!(v_lh.x || v_rh.x),
		!(v_lh.y || v_rh.y),
		!(v_lh.z || v_rh.z),
		!(v_lh.w || v_rh.w),
	};
	return bv_out;
}

ijk_inl dvec4 ijkVecCopy4dzw(dvec2 const v_xy, double const z, double const w)
{
	dvec4 const v_out = { v_xy.x, v_xy.y, z, w };
	return v_out;
}

ijk_inl dvec4 ijkVecCopy4dw(dvec3 const v_xyz, double const w)
{
	dvec4 const v_out = { v_xyz.x, v_xyz.y, v_xyz.z, w };
	return v_out;
}

ijk_inl dvec4 ijkVecCopy4ds(double const s_in)
{
	dvec4 const v_out = { s_in, s_in, s_in, s_in };
	return v_out;
}

ijk_inl dvec4 ijkVecNegate4ds(double const s_in)
{
	double const s = -s_in;
	dvec4 const v_out = { s, s, s, s };
	return v_out;
}

ijk_inl bvec4 ijkVecNot4ds(double const s_in)
{
	bool const s = !s_in;
	bvec4 const bv_out = { s, s, s, s };
	return bv_out;
}

ijk_inl dvec4 ijkVecAdd4ds(dvec4 const v_lh, double const s_rh)
{
	dvec4 const v_out = {
		v_lh.x + s_rh,
		v_lh.y + s_rh,
		v_lh.z + s_rh,
		v_lh.w + s_rh,
	};
	return v_out;
}

ijk_inl dvec4 ijkVecSub4ds(dvec4 const v_lh, double const s_rh)
{
	dvec4 const v_out = {
		v_lh.x - s_rh,
		v_lh.y - s_rh,
		v_lh.z - s_rh,
		v_lh.w - s_rh,
	};
	return v_out;
}

ijk_inl dvec4 ijkVecMul4ds(dvec4 const v_lh, double const s_rh)
{
	dvec4 const v_out = {
		v_lh.x * s_rh,
		v_lh.y * s_rh,
		v_lh.z * s_rh,
		v_lh.w * s_rh,
	};
	return v_out;
}

ijk_inl dvec4 ijkVecDiv4ds(dvec4 const v_lh, double const s_rh)
{
	f64 const s = ijk_recip_dbl(s_rh);
	dvec4 const v_out = {
		v_lh.x * s,
		v_lh.y * s,
		v_lh.z * s,
		v_lh.w * s,
	};
	return v_out;
}

ijk_inl dvec4 ijkVecDivSafe4ds(dvec4 const v_lh, double const s_rh)
{
	f64 const s = ijk_recip_safe_dbl(s_rh);
	dvec4 const v_out = {
		v_lh.x * s,
		v_lh.y * s,
		v_lh.z * s,
		v_lh.w * s,
	};
	return v_out;
}

ijk_inl dvec4 ijkVecMod4ds(dvec4 const v_lh, double const s_rh)
{
	dvec4 const v_out = {
		ijk_modulo_dbl(v_lh.x, s_rh),
		ijk_modulo_dbl(v_lh.y, s_rh),
		ijk_modulo_dbl(v_lh.z, s_rh),
		ijk_modulo_dbl(v_lh.w, s_rh),
	};
	return v_out;
}

ijk_inl dvec4 ijkVecModSafe4ds(dvec4 const v_lh, double const s_rh)
{
	if (s_rh)
	{
		dvec4 const v_out = {
			ijk_modulo_dbl(v_lh.x, s_rh),
			ijk_modulo_dbl(v_lh.y, s_rh),
			ijk_modulo_dbl(v_lh.z, s_rh),
			ijk_modulo_dbl(v_lh.w, s_rh),
		};
		return v_out;
	}
	return v_lh;
}

ijk_inl bvec4 ijkVecEqual4ds(dvec4 const v_lh, double const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x == s_rh),
		(v_lh.y == s_rh),
		(v_lh.z == s_rh),
		(v_lh.w == s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecInequal4ds(dvec4 const v_lh, double const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x != s_rh),
		(v_lh.y != s_rh),
		(v_lh.z != s_rh),
		(v_lh.w != s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLessEqual4ds(dvec4 const v_lh, double const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x <= s_rh),
		(v_lh.y <= s_rh),
		(v_lh.z <= s_rh),
		(v_lh.w <= s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreaterEqual4ds(dvec4 const v_lh, double const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x >= s_rh),
		(v_lh.y >= s_rh),
		(v_lh.z >= s_rh),
		(v_lh.w >= s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLess4ds(dvec4 const v_lh, double const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x < s_rh),
		(v_lh.y < s_rh),
		(v_lh.z < s_rh),
		(v_lh.w < s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreater4ds(dvec4 const v_lh, double const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x > s_rh),
		(v_lh.y > s_rh),
		(v_lh.z > s_rh),
		(v_lh.w > s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecAnd4ds(dvec4 const v_lh, double const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x && s_rh),
		(v_lh.y && s_rh),
		(v_lh.z && s_rh),
		(v_lh.w && s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNand4ds(dvec4 const v_lh, double const s_rh)
{
	bvec4 const bv_out = {
		!(v_lh.x && s_rh),
		!(v_lh.y && s_rh),
		!(v_lh.z && s_rh),
		!(v_lh.w && s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecOr4ds(dvec4 const v_lh, double const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x || s_rh),
		(v_lh.y || s_rh),
		(v_lh.z || s_rh),
		(v_lh.w || s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNor4ds(dvec4 const v_lh, double const s_rh)
{
	bvec4 const bv_out = {
		!(v_lh.x || s_rh),
		!(v_lh.y || s_rh),
		!(v_lh.z || s_rh),
		!(v_lh.w || s_rh),
	};
	return bv_out;
}

ijk_inl dvec4 ijkVecCopy4xyd(double const x, double const y, dvec2 const v_zw)
{
	dvec4 const v_out = { x, y, v_zw.x, v_zw.y };
	return v_out;
}

ijk_inl dvec4 ijkVecCopy4xd(double const x, dvec3 const v_yzw)
{
	dvec4 const v_out = { x, v_yzw.x, v_yzw.y, v_yzw.z };
	return v_out;
}

ijk_inl dvec4 ijkVecAdd4sd(double const s_lh, dvec4 const v_rh)
{
	dvec4 const v_out = {
		s_lh + v_rh.x,
		s_lh + v_rh.y,
		s_lh + v_rh.z,
		s_lh + v_rh.w,
	};
	return v_out;
}

ijk_inl dvec4 ijkVecSub4sd(double const s_lh, dvec4 const v_rh)
{
	dvec4 const v_out = {
		s_lh - v_rh.x,
		s_lh - v_rh.y,
		s_lh - v_rh.z,
		s_lh - v_rh.w,
	};
	return v_out;
}

ijk_inl dvec4 ijkVecMul4sd(double const s_lh, dvec4 const v_rh)
{
	dvec4 const v_out = {
		s_lh * v_rh.x,
		s_lh * v_rh.y,
		s_lh * v_rh.z,
		s_lh * v_rh.w,
	};
	return v_out;
}

ijk_inl dvec4 ijkVecDiv4sd(double const s_lh, dvec4 const v_rh)
{
	dvec4 const v_out = {
		s_lh / v_rh.x,
		s_lh / v_rh.y,
		s_lh / v_rh.z,
		s_lh / v_rh.w,
	};
	return v_out;
}

ijk_inl dvec4 ijkVecDivSafe4sd(double const s_lh, dvec4 const v_rh)
{
	dvec4 const v_out = {
		ijk_divide_safe_dbl(s_lh, v_rh.x),
		ijk_divide_safe_dbl(s_lh, v_rh.y),
		ijk_divide_safe_dbl(s_lh, v_rh.z),
		ijk_divide_safe_dbl(s_lh, v_rh.w),
	};
	return v_out;
}

ijk_inl dvec4 ijkVecMod4sd(double const s_lh, dvec4 const v_rh)
{
	dvec4 const v_out = {
		ijk_modulo_dbl(s_lh, v_rh.x),
		ijk_modulo_dbl(s_lh, v_rh.y),
		ijk_modulo_dbl(s_lh, v_rh.z),
		ijk_modulo_dbl(s_lh, v_rh.w),
	};
	return v_out;
}

ijk_inl dvec4 ijkVecModSafe4sd(double const s_lh, dvec4 const v_rh)
{
	dvec4 const v_out = {
		ijk_modulo_safe_dbl((f64)s_lh, v_rh.x),
		ijk_modulo_safe_dbl((f64)s_lh, v_rh.y),
		ijk_modulo_safe_dbl((f64)s_lh, v_rh.z),
		ijk_modulo_safe_dbl((f64)s_lh, v_rh.w),
	};
	return v_out;
}

ijk_inl bvec4 ijkVecEqual4sd(double const s_lh, dvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh == v_rh.x),
		(s_lh == v_rh.y),
		(s_lh == v_rh.z),
		(s_lh == v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecInequal4sd(double const s_lh, dvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh != v_rh.x),
		(s_lh != v_rh.y),
		(s_lh != v_rh.z),
		(s_lh != v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLessEqual4sd(double const s_lh, dvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh <= v_rh.x),
		(s_lh <= v_rh.y),
		(s_lh <= v_rh.z),
		(s_lh <= v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreaterEqual4sd(double const s_lh, dvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh >= v_rh.x),
		(s_lh >= v_rh.y),
		(s_lh >= v_rh.z),
		(s_lh >= v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLess4sd(double const s_lh, dvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh < v_rh.x),
		(s_lh < v_rh.y),
		(s_lh < v_rh.z),
		(s_lh < v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreater4sd(double const s_lh, dvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh > v_rh.x),
		(s_lh > v_rh.y),
		(s_lh > v_rh.z),
		(s_lh > v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecAnd4sd(double const s_lh, dvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh && v_rh.x),
		(s_lh && v_rh.y),
		(s_lh && v_rh.z),
		(s_lh && v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNand4sd(double const s_lh, dvec4 const v_rh)
{
	bvec4 const bv_out = {
		!(s_lh && v_rh.x),
		!(s_lh && v_rh.y),
		!(s_lh && v_rh.z),
		!(s_lh && v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecOr4sd(double const s_lh, dvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh || v_rh.x),
		(s_lh || v_rh.y),
		(s_lh || v_rh.z),
		(s_lh || v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNor4sd(double const s_lh, dvec4 const v_rh)
{
	bvec4 const bv_out = {
		!(s_lh || v_rh.x),
		!(s_lh || v_rh.y),
		!(s_lh || v_rh.z),
		!(s_lh || v_rh.w),
	};
	return bv_out;
}

ijk_inl double ijkVecDot4d(dvec4 const v_lh, dvec4 const v_rh)
{
	return ijkVecDot4dv(v_lh.xyzw, v_rh.xyzw);
}

ijk_inl dvec4 ijkVecCross4d(dvec4 const v_lh, dvec4 const v_rh)
{
	dvec4 v_out;
	ijkVecCross4dv(v_out.xyzw, v_lh.xyzw, v_rh.xyzw);
	return v_out;
}


//-----------------------------------------------------------------------------

ijk_inl f64 ijkVecLengthSq2dv(double2 const v_in)
{
	return ijkVecDot2dv(v_in, v_in);
}

ijk_inl f64 ijkVecLength2dv(double2 const v_in)
{
	return ijkSqrt_dbl(ijkVecLengthSq2dv(v_in));
}

ijk_inl f64 ijkVecLengthSqInv2dv(double2 const v_in)
{
	return ijk_recip_dbl(ijkVecLengthSq2dv(v_in));
}

ijk_inl f64 ijkVecLengthSqInvSafe2dv(double2 const v_in)
{
	f64 const lengthSq = ijkVecLengthSq2dv(v_in);
	return ijk_recip_safe_dbl(lengthSq);
}

ijk_inl f64 ijkVecLengthInv2dv(double2 const v_in)
{
	return ijkSqrtInv_dbl(ijkVecLengthSq2dv(v_in));
}

ijk_inl f64 ijkVecLengthInvSafe2dv(double2 const v_in)
{
	f64 const lengthSq = ijkVecLengthSq2dv(v_in);
	return (lengthSq > flt_zero ? ijkSqrtInv_dbl(lengthSq) : flt_zero);
}

ijk_inl doublev ijkVecNormalize2dv(double2 v_out, double2 const v_in)
{
	return ijkVecMul2dvs(v_out, v_in, ijkVecLengthInv2dv(v_in));
}

ijk_inl doublev ijkVecNormalizeSafe2dv(double2 v_out, double2 const v_in)
{
	return ijkVecMul2dvs(v_out, v_in, ijkVecLengthInvSafe2dv(v_in));
}

ijk_inl doublev ijkVecNormalizeGetLength2dv(double2 v_out, double2 const v_in, f64* const length_out)
{
	return ijkVecDiv2dvs(v_out, v_in, (*length_out = ijkVecLength2dv(v_in)));
}

ijk_inl doublev ijkVecNormalizeSafeGetLength2dv(double2 v_out, double2 const v_in, f64* const length_out)
{
	return ijkVecDivSafe2dvs(v_out, v_in, (*length_out = ijkVecLength2dv(v_in)));
}

ijk_inl doublev ijkVecNormalizeGetLengthInv2dv(double2 v_out, double2 const v_in, f64* const lengthInv_out)
{
	return ijkVecMul2dvs(v_out, v_in, (*lengthInv_out = ijkVecLengthInv2dv(v_in)));
}

ijk_inl doublev ijkVecNormalizeSafeGetLengthInv2dv(double2 v_out, double2 const v_in, f64* const lengthInv_out)
{
	return ijkVecMul2dvs(v_out, v_in, (*lengthInv_out = ijkVecLengthInvSafe2dv(v_in)));
}

ijk_inl f64 ijkVecCrossNormalize2dv(double2 const v_lh, double2 const v_rh)
{
	f64 const cross = ijkVecCross2dv(v_lh, v_rh);
	return ijk_sgn_dbl(cross);
}

ijk_inl f64 ijkVecCrossNormalizeSafe2dv(double2 const v_lh, double2 const v_rh)
{
	f64 const cross = ijkVecCross2dv(v_lh, v_rh);
	return ijk_sgn_dbl(cross);
}

ijk_inl f64 ijkVecCrossNormalizeGetLength2dv(double2 const v_lh, double2 const v_rh, f64* const length_out)
{
	f64 const cross = ijkVecCross2dv(v_lh, v_rh);
	*length_out = ijk_abs_dbl(cross);
	return ijk_sgn_dbl(cross);
}

ijk_inl f64 ijkVecCrossNormalizeSafeGetLength2dv(double2 const v_lh, double2 const v_rh, f64* const length_out)
{
	f64 const cross = ijkVecCross2dv(v_lh, v_rh);
	*length_out = ijk_abs_dbl(cross);
	return ijk_sgn_dbl(cross);
}

ijk_inl f64 ijkVecCrossNormalizeGetLengthInv2dv(double2 const v_lh, double2 const v_rh, f64* const lengthInv_out)
{
	f64 const cross = ijkVecCross2dv(v_lh, v_rh);
	f64 const length = ijk_abs_dbl(cross);
	*lengthInv_out = ijk_recip_dbl(length);
	return ijk_sgn_dbl(cross);
}

ijk_inl f64 ijkVecCrossNormalizeSafeGetLengthInv2dv(double2 const v_lh, double2 const v_rh, f64* const lengthInv_out)
{
	f64 const cross = ijkVecCross2dv(v_lh, v_rh);
	f64 const length = ijk_abs_dbl(cross);
	*lengthInv_out = ijk_recip_safe_dbl(length);
	return ijk_sgn_dbl(cross);
}

ijk_inl doublev ijkVecLerp2dv(double2 v_out, double2 const v0, double2 const v1, f64 const u)
{
	v_out[0] = ijkInterpLinear_dbl(v0[0], v1[0], u);
	v_out[1] = ijkInterpLinear_dbl(v0[1], v1[1], u);
	return v_out;
}

ijk_inl doublev ijkVecLerpInv2dv(double2 v_out, double2 const v0, double2 const v1, double2 const v_lerp)
{
	v_out[0] = ijkInterpLinearInv_dbl(v0[0], v1[0], v_lerp[0]);
	v_out[1] = ijkInterpLinearInv_dbl(v0[1], v1[1], v_lerp[1]);
	return v_out;
}

ijk_inl doublev ijkVecLerpRevInit2dv(double2 v0_out, double2 const v_lerp, double2 const v1, f64 const u)
{
	f64 const s = ijk_recip_dbl(flt_one - u);
	v0_out[0] = (v_lerp[0] - v1[0] * u) * s;
	v0_out[1] = (v_lerp[1] - v1[1] * u) * s;
	return v0_out;
}

ijk_inl doublev ijkVecLerpRevTerm2dv(double2 v1_out, double2 const v0, double2 const v_lerp, f64 const u)
{
	return ijkVecLerp2dv(v1_out, v0, v_lerp, ijk_recip_dbl(u));
}

ijk_inl f64 ijkVecProjRatio2dv(double2 const v_base, double2 const v_in)
{
	return (ijkVecDot2dv(v_base, v_in) / ijkVecLengthSq2dv(v_base));
}

ijk_inl doublev ijkVecProj2dv(double2 v_out, double2 const v_base, double2 const v_in)
{
	return ijkVecMul2dvs(v_out, v_base, ijkVecProjRatio2dv(v_base, v_in));
}

ijk_inl doublev ijkVecOrtho2dv(double2 v_out, double2 const v_base, double2 const v_in)
{
	double2 ortho;
	return ijkVecSub2dv(v_out, v_in, ijkVecProj2dv(ortho, v_base, v_in));
}

ijk_inl doublev ijkVecOrthoNorm2dv(double2 v_out, double2 const v_base, double2 const v_in, double2 v_base_norm_out)
{
	double2 ortho;
	ijkVecNormalize2dv(v_base_norm_out, v_base);
	ijkVecSub2dv(v_out, v_in, ijkVecMul2dvs(ortho, v_base_norm_out, ijkVecDot2dv(v_base_norm_out, v_in)));
	return ijkVecNormalize2dv(v_out, v_out);
}

ijk_inl double2* ijkVecOrthoList2dv(double2 vl_out[], double2 const v_base, double2 const vl_in[], size const n)
{
	double2 ortho, orthoSum;
	doublev vp_out;
	doublekv vp_in;
	uindex i, j;
	for (i = 0; i < n; ++i)
	{
		vp_out = vl_out[i];
		vp_in = vl_in[i];
		ijkVecProj2dv(orthoSum, v_base, vp_in);
		for (j = 0; j < i; ++j)
			ijkVecAdd2dv(orthoSum, orthoSum, ijkVecProj2dv(ortho, vl_out[j], vp_in));
		ijkVecSub2dv(vp_out, vp_in, orthoSum);
	}
	return vl_out;
}

ijk_inl double2* ijkVecOrthoNormList2dv(double2 vl_out[], double2 const v_base, double2 const vl_in[], size const n, double2 v_base_norm_out)
{
	double2 ortho, orthoSum;
	doublev vp_out;
	doublekv vp_in;
	uindex i, j;
	ijkVecNormalize2dv(v_base_norm_out, v_base);
	for (i = 0; i < n; ++i)
	{
		vp_out = vl_out[i];
		vp_in = vl_in[i];
		ijkVecMul2dvs(ortho, v_base_norm_out, ijkVecDot2dv(v_base_norm_out, vp_in));
		for (j = 0; j < i; ++j)
			ijkVecAdd2dv(orthoSum, orthoSum, ijkVecMul2dvs(ortho, vl_out[j], ijkVecDot2dv(vl_out[j], vp_in)));
		ijkVecSub2dv(vp_out, vp_in, orthoSum);
		ijkVecNormalize2dv(vp_out, vp_out);
	}
	return vl_out;
}


//-----------------------------------------------------------------------------

ijk_inl f64 ijkVecLengthSq3dv(double3 const v_in)
{
	return ijkVecDot3dv(v_in, v_in);
}

ijk_inl f64 ijkVecLength3dv(double3 const v_in)
{
	return ijkSqrt_dbl(ijkVecLengthSq3dv(v_in));
}

ijk_inl f64 ijkVecLengthSqInv3dv(double3 const v_in)
{
	return ijk_recip_dbl(ijkVecLengthSq3dv(v_in));
}

ijk_inl f64 ijkVecLengthSqInvSafe3dv(double3 const v_in)
{
	f64 const lengthSq = ijkVecLengthSq3dv(v_in);
	return ijk_recip_safe_dbl(lengthSq);
}

ijk_inl f64 ijkVecLengthInv3dv(double3 const v_in)
{
	return ijkSqrtInv_dbl(ijkVecLengthSq3dv(v_in));
}

ijk_inl f64 ijkVecLengthInvSafe3dv(double3 const v_in)
{
	f64 const lengthSq = ijkVecLengthSq3dv(v_in);
	return (lengthSq > flt_zero ? ijkSqrtInv_dbl(lengthSq) : flt_zero);
}

ijk_inl doublev ijkVecNormalize3dv(double3 v_out, double3 const v_in)
{
	return ijkVecMul3dvs(v_out, v_in, ijkVecLengthInv3dv(v_in));
}

ijk_inl doublev ijkVecNormalizeSafe3dv(double3 v_out, double3 const v_in)
{
	return ijkVecMul3dvs(v_out, v_in, ijkVecLengthInvSafe3dv(v_in));
}

ijk_inl doublev ijkVecNormalizeGetLength3dv(double3 v_out, double3 const v_in, f64* const length_out)
{
	return ijkVecDiv3dvs(v_out, v_in, (*length_out = ijkVecLength3dv(v_in)));
}

ijk_inl doublev ijkVecNormalizeSafeGetLength3dv(double3 v_out, double3 const v_in, f64* const length_out)
{
	return ijkVecDivSafe3dvs(v_out, v_in, (*length_out = ijkVecLength3dv(v_in)));
}

ijk_inl doublev ijkVecNormalizeGetLengthInv3dv(double3 v_out, double3 const v_in, f64* const lengthInv_out)
{
	return ijkVecMul3dvs(v_out, v_in, (*lengthInv_out = ijkVecLengthInv3dv(v_in)));
}

ijk_inl doublev ijkVecNormalizeSafeGetLengthInv3dv(double3 v_out, double3 const v_in, f64* const lengthInv_out)
{
	return ijkVecMul3dvs(v_out, v_in, (*lengthInv_out = ijkVecLengthInvSafe3dv(v_in)));
}

ijk_inl doublev ijkVecCrossNormalize3dv(double3 v_out, double3 const v_lh, double3 const v_rh)
{
	ijkVecCross3dv(v_out, v_lh, v_rh);
	return ijkVecNormalize3dv(v_out, v_out);
}

ijk_inl doublev ijkVecCrossNormalizeSafe3dv(double3 v_out, double3 const v_lh, double3 const v_rh)
{
	ijkVecCross3dv(v_out, v_lh, v_rh);
	return ijkVecNormalizeSafe3dv(v_out, v_out);
}

ijk_inl doublev ijkVecCrossNormalizeGetLength3dv(double3 v_out, double3 const v_lh, double3 const v_rh, f64* const length_out)
{
	ijkVecCross3dv(v_out, v_lh, v_rh);
	return ijkVecNormalizeGetLength3dv(v_out, v_out, length_out);
}

ijk_inl doublev ijkVecCrossNormalizeSafeGetLength3dv(double3 v_out, double3 const v_lh, double3 const v_rh, f64* const length_out)
{
	ijkVecCross3dv(v_out, v_lh, v_rh);
	return ijkVecNormalizeSafeGetLength3dv(v_out, v_out, length_out);
}

ijk_inl doublev ijkVecCrossNormalizeGetLengthInv3dv(double3 v_out, double3 const v_lh, double3 const v_rh, f64* const lengthInv_out)
{
	ijkVecCross3dv(v_out, v_lh, v_rh);
	return ijkVecNormalizeGetLengthInv3dv(v_out, v_out, lengthInv_out);
}

ijk_inl doublev ijkVecCrossNormalizeSafeGetLengthInv3dv(double3 v_out, double3 const v_lh, double3 const v_rh, f64* const lengthInv_out)
{
	ijkVecCross3dv(v_out, v_lh, v_rh);
	return ijkVecNormalizeSafeGetLengthInv3dv(v_out, v_out, lengthInv_out);
}

ijk_inl doublev ijkVecLerp3dv(double3 v_out, double3 const v0, double3 const v1, f64 const u)
{
	v_out[0] = ijkInterpLinear_dbl(v0[0], v1[0], u);
	v_out[1] = ijkInterpLinear_dbl(v0[1], v1[1], u);
	v_out[2] = ijkInterpLinear_dbl(v0[2], v1[2], u);
	return v_out;
}

ijk_inl doublev ijkVecLerpInv3dv(double3 v_out, double3 const v0, double3 const v1, double3 const v_lerp)
{
	v_out[0] = ijkInterpLinearInv_dbl(v0[0], v1[0], v_lerp[0]);
	v_out[1] = ijkInterpLinearInv_dbl(v0[1], v1[1], v_lerp[1]);
	v_out[2] = ijkInterpLinearInv_dbl(v0[2], v1[2], v_lerp[2]);
	return v_out;
}

ijk_inl doublev ijkVecLerpRevInit3dv(double3 v0_out, double3 const v_lerp, double3 const v1, f64 const u)
{
	f64 const s = ijk_recip_dbl(flt_one - u);
	v0_out[0] = (v_lerp[0] - v1[0] * u) * s;
	v0_out[1] = (v_lerp[1] - v1[1] * u) * s;
	v0_out[2] = (v_lerp[2] - v1[2] * u) * s;
	return v0_out;
}

ijk_inl doublev ijkVecLerpRevTerm3dv(double3 v1_out, double3 const v0, double3 const v_lerp, f64 const u)
{
	return ijkVecLerp3dv(v1_out, v0, v_lerp, ijk_recip_dbl(u));
}

ijk_inl f64 ijkVecProjRatio3dv(double3 const v_base, double3 const v_in)
{
	return (ijkVecDot3dv(v_base, v_in) / ijkVecLengthSq3dv(v_base));
}

ijk_inl doublev ijkVecProj3dv(double3 v_out, double3 const v_base, double3 const v_in)
{
	return ijkVecMul3dvs(v_out, v_base, ijkVecProjRatio3dv(v_base, v_in));
}

ijk_inl doublev ijkVecOrtho3dv(double3 v_out, double3 const v_base, double3 const v_in)
{
	double3 ortho;
	return ijkVecSub3dv(v_out, v_in, ijkVecProj3dv(ortho, v_base, v_in));
}

ijk_inl doublev ijkVecOrthoNorm3dv(double3 v_out, double3 const v_base, double3 const v_in, double3 v_base_norm_out)
{
	double3 ortho;
	ijkVecNormalize3dv(v_base_norm_out, v_base);
	ijkVecSub3dv(v_out, v_in, ijkVecMul3dvs(ortho, v_base_norm_out, ijkVecDot3dv(v_base_norm_out, v_in)));
	return ijkVecNormalize3dv(v_out, v_out);
}

ijk_inl double3* ijkVecOrthoList3dv(double3 vl_out[], double3 const v_base, double3 const vl_in[], size const n)
{
	double3 ortho, orthoSum;
	doublev vp_out;
	doublekv vp_in;
	uindex i, j;
	for (i = 0; i < n; ++i)
	{
		vp_out = vl_out[i];
		vp_in = vl_in[i];
		ijkVecProj3dv(orthoSum, v_base, vp_in);
		for (j = 0; j < i; ++j)
			ijkVecAdd3dv(orthoSum, orthoSum, ijkVecProj3dv(ortho, vl_out[j], vp_in));
		ijkVecSub3dv(vp_out, vp_in, orthoSum);
	}
	return vl_out;
}

ijk_inl double3* ijkVecOrthoNormList3dv(double3 vl_out[], double3 const v_base, double3 const vl_in[], size const n, double3 v_base_norm_out)
{
	double3 ortho, orthoSum;
	doublev vp_out;
	doublekv vp_in;
	uindex i, j;
	ijkVecNormalize3dv(v_base_norm_out, v_base);
	for (i = 0; i < n; ++i)
	{
		vp_out = vl_out[i];
		vp_in = vl_in[i];
		ijkVecMul3dvs(ortho, v_base_norm_out, ijkVecDot3dv(v_base_norm_out, vp_in));
		for (j = 0; j < i; ++j)
			ijkVecAdd3dv(orthoSum, orthoSum, ijkVecMul3dvs(ortho, vl_out[j], ijkVecDot3dv(vl_out[j], vp_in)));
		ijkVecSub3dv(vp_out, vp_in, orthoSum);
		ijkVecNormalize3dv(vp_out, vp_out);
	}
	return vl_out;
}


//-----------------------------------------------------------------------------

ijk_inl f64 ijkVecLengthSq4dv(double4 const v_in)
{
	return ijkVecDot4dv(v_in, v_in);
}

ijk_inl f64 ijkVecLength4dv(double4 const v_in)
{
	return ijkSqrt_dbl(ijkVecLengthSq4dv(v_in));
}

ijk_inl f64 ijkVecLengthSqInv4dv(double4 const v_in)
{
	return ijk_recip_dbl(ijkVecLengthSq4dv(v_in));
}

ijk_inl f64 ijkVecLengthSqInvSafe4dv(double4 const v_in)
{
	f64 const lengthSq = ijkVecLengthSq4dv(v_in);
	return ijk_recip_safe_dbl(lengthSq);
}

ijk_inl f64 ijkVecLengthInv4dv(double4 const v_in)
{
	return ijkSqrtInv_dbl(ijkVecLengthSq4dv(v_in));
}

ijk_inl f64 ijkVecLengthInvSafe4dv(double4 const v_in)
{
	f64 const lengthSq = ijkVecLengthSq4dv(v_in);
	return (lengthSq > flt_zero ? ijkSqrtInv_dbl(lengthSq) : flt_zero);
}

ijk_inl doublev ijkVecNormalize4dv(double4 v_out, double4 const v_in)
{
	return ijkVecMul4dvs(v_out, v_in, ijkVecLengthInv4dv(v_in));
}

ijk_inl doublev ijkVecNormalizeSafe4dv(double4 v_out, double4 const v_in)
{
	return ijkVecMul4dvs(v_out, v_in, ijkVecLengthInvSafe4dv(v_in));
}

ijk_inl doublev ijkVecNormalizeGetLength4dv(double4 v_out, double4 const v_in, f64* const length_out)
{
	return ijkVecDiv4dvs(v_out, v_in, (*length_out = ijkVecLength4dv(v_in)));
}

ijk_inl doublev ijkVecNormalizeSafeGetLength4dv(double4 v_out, double4 const v_in, f64* const length_out)
{
	return ijkVecDivSafe4dvs(v_out, v_in, (*length_out = ijkVecLength4dv(v_in)));
}

ijk_inl doublev ijkVecNormalizeGetLengthInv4dv(double4 v_out, double4 const v_in, f64* const lengthInv_out)
{
	return ijkVecMul4dvs(v_out, v_in, (*lengthInv_out = ijkVecLengthInv4dv(v_in)));
}

ijk_inl doublev ijkVecNormalizeSafeGetLengthInv4dv(double4 v_out, double4 const v_in, f64* const lengthInv_out)
{
	return ijkVecMul4dvs(v_out, v_in, (*lengthInv_out = ijkVecLengthInvSafe4dv(v_in)));
}

ijk_inl doublev ijkVecCrossNormalize4dv(double4 v_out, double4 const v_lh, double4 const v_rh)
{
	ijkVecCross4dv(v_out, v_lh, v_rh);
	return ijkVecNormalize3dv(v_out, v_out);
}

ijk_inl doublev ijkVecCrossNormalizeSafe4dv(double4 v_out, double4 const v_lh, double4 const v_rh)
{
	ijkVecCross4dv(v_out, v_lh, v_rh);
	return ijkVecNormalizeSafe3dv(v_out, v_out);
}

ijk_inl doublev ijkVecCrossNormalizeGetLength4dv(double4 v_out, double4 const v_lh, double4 const v_rh, f64* const length_out)
{
	ijkVecCross4dv(v_out, v_lh, v_rh);
	return ijkVecNormalizeGetLength3dv(v_out, v_out, length_out);
}

ijk_inl doublev ijkVecCrossNormalizeSafeGetLength4dv(double4 v_out, double4 const v_lh, double4 const v_rh, f64* const length_out)
{
	ijkVecCross4dv(v_out, v_lh, v_rh);
	return ijkVecNormalizeSafeGetLength3dv(v_out, v_out, length_out);
}

ijk_inl doublev ijkVecCrossNormalizeGetLengthInv4dv(double4 v_out, double4 const v_lh, double4 const v_rh, f64* const lengthInv_out)
{
	ijkVecCross4dv(v_out, v_lh, v_rh);
	return ijkVecNormalizeGetLengthInv3dv(v_out, v_out, lengthInv_out);
}

ijk_inl doublev ijkVecCrossNormalizeSafeGetLengthInv4dv(double4 v_out, double4 const v_lh, double4 const v_rh, f64* const lengthInv_out)
{
	ijkVecCross4dv(v_out, v_lh, v_rh);
	return ijkVecNormalizeSafeGetLengthInv3dv(v_out, v_out, lengthInv_out);
}

ijk_inl doublev ijkVecLerp4dv(double4 v_out, double4 const v0, double4 const v1, f64 const u)
{
	v_out[0] = ijkInterpLinear_dbl(v0[0], v1[0], u);
	v_out[1] = ijkInterpLinear_dbl(v0[1], v1[1], u);
	v_out[2] = ijkInterpLinear_dbl(v0[2], v1[2], u);
	v_out[3] = ijkInterpLinear_dbl(v0[3], v1[3], u);
	return v_out;
}

ijk_inl doublev ijkVecLerpInv4dv(double4 v_out, double4 const v0, double4 const v1, double4 const v_lerp)
{
	v_out[0] = ijkInterpLinearInv_dbl(v0[0], v1[0], v_lerp[0]);
	v_out[1] = ijkInterpLinearInv_dbl(v0[1], v1[1], v_lerp[1]);
	v_out[2] = ijkInterpLinearInv_dbl(v0[2], v1[2], v_lerp[2]);
	v_out[3] = ijkInterpLinearInv_dbl(v0[3], v1[3], v_lerp[3]);
	return v_out;
}

ijk_inl doublev ijkVecLerpRevInit4dv(double4 v0_out, double4 const v_lerp, double4 const v1, f64 const u)
{
	f64 const s = ijk_recip_dbl(flt_one - u);
	v0_out[0] = (v_lerp[0] - v1[0] * u) * s;
	v0_out[1] = (v_lerp[1] - v1[1] * u) * s;
	v0_out[2] = (v_lerp[2] - v1[2] * u) * s;
	v0_out[3] = (v_lerp[3] - v1[3] * u) * s;
	return v0_out;
}

ijk_inl doublev ijkVecLerpRevTerm4dv(double4 v1_out, double4 const v0, double4 const v_lerp, f64 const u)
{
	return ijkVecLerp4dv(v1_out, v0, v_lerp, ijk_recip_dbl(u));
}

ijk_inl f64 ijkVecProjRatio4dv(double4 const v_base, double4 const v_in)
{
	return (ijkVecDot4dv(v_base, v_in) / ijkVecLengthSq4dv(v_base));
}

ijk_inl doublev ijkVecProj4dv(double4 v_out, double4 const v_base, double4 const v_in)
{
	return ijkVecMul4dvs(v_out, v_base, ijkVecProjRatio4dv(v_base, v_in));
}

ijk_inl doublev ijkVecOrtho4dv(double4 v_out, double4 const v_base, double4 const v_in)
{
	double4 ortho;
	return ijkVecSub4dv(v_out, v_in, ijkVecProj4dv(ortho, v_base, v_in));
}

ijk_inl doublev ijkVecOrthoNorm4dv(double4 v_out, double4 const v_base, double4 const v_in, double4 v_base_norm_out)
{
	double4 ortho;
	ijkVecNormalize4dv(v_base_norm_out, v_base);
	ijkVecSub4dv(v_out, v_in, ijkVecMul4dvs(ortho, v_base_norm_out, ijkVecDot4dv(v_base_norm_out, v_in)));
	return ijkVecNormalize4dv(v_out, v_out);
}

ijk_inl double4* ijkVecOrthoList4dv(double4 vl_out[], double4 const v_base, double4 const vl_in[], size const n)
{
	double4 ortho, orthoSum;
	doublev vp_out;
	doublekv vp_in;
	uindex i, j;
	for (i = 0; i < n; ++i)
	{
		vp_out = vl_out[i];
		vp_in = vl_in[i];
		ijkVecProj4dv(orthoSum, v_base, vp_in);
		for (j = 0; j < i; ++j)
			ijkVecAdd4dv(orthoSum, orthoSum, ijkVecProj4dv(ortho, vl_out[j], vp_in));
		ijkVecSub4dv(vp_out, vp_in, orthoSum);
	}
	return vl_out;
}

ijk_inl double4* ijkVecOrthoNormList4dv(double4 vl_out[], double4 const v_base, double4 const vl_in[], size const n, double4 v_base_norm_out)
{
	double4 ortho, orthoSum;
	doublev vp_out;
	doublekv vp_in;
	uindex i, j;
	ijkVecNormalize4dv(v_base_norm_out, v_base);
	for (i = 0; i < n; ++i)
	{
		vp_out = vl_out[i];
		vp_in = vl_in[i];
		ijkVecMul4dvs(ortho, v_base_norm_out, ijkVecDot4dv(v_base_norm_out, vp_in));
		for (j = 0; j < i; ++j)
			ijkVecAdd4dv(orthoSum, orthoSum, ijkVecMul4dvs(ortho, vl_out[j], ijkVecDot4dv(vl_out[j], vp_in)));
		ijkVecSub4dv(vp_out, vp_in, orthoSum);
		ijkVecNormalize4dv(vp_out, vp_out);
	}
	return vl_out;
}


//-----------------------------------------------------------------------------

ijk_inl double ijkVecLengthSq2d(dvec2 const v_in)
{
	return ijkVecDot2d(v_in, v_in);
}

ijk_inl double ijkVecLength2d(dvec2 const v_in)
{
	return ijkSqrt_dbl(ijkVecLengthSq2d(v_in));
}

ijk_inl double ijkVecLengthSqInv2d(dvec2 const v_in)
{
	return ijk_recip_dbl(ijkVecLengthSq2d(v_in));
}

ijk_inl double ijkVecLengthSqInvSafe2d(dvec2 const v_in)
{
	double const lengthSq = ijkVecLengthSq2d(v_in);
	return ijk_recip_safe_dbl(lengthSq);
}

ijk_inl double ijkVecLengthInv2d(dvec2 const v_in)
{
	return ijkSqrtInv_dbl(ijkVecLengthSq2d(v_in));
}

ijk_inl double ijkVecLengthInvSafe2d(dvec2 const v_in)
{
	double const lengthSq = ijkVecLengthSq2d(v_in);
	return (lengthSq > flt_zero ? ijkSqrtInv_dbl(lengthSq) : flt_zero);
}

ijk_inl dvec2 ijkVecNormalize2d(dvec2 const v_in)
{
	return ijkVecMul2ds(v_in, ijkVecLengthInv2d(v_in));
}

ijk_inl dvec2 ijkVecNormalizeSafe2d(dvec2 const v_in)
{
	return ijkVecMul2ds(v_in, ijkVecLengthInvSafe2d(v_in));
}

ijk_inl dvec2 ijkVecNormalizeGetLength2d(dvec2 const v_in, double* const length_out)
{
	return ijkVecDiv2ds(v_in, (*length_out = ijkVecLength2d(v_in)));
}

ijk_inl dvec2 ijkVecNormalizeSafeGetLength2d(dvec2 const v_in, double* const length_out)
{
	return ijkVecDivSafe2ds(v_in, (*length_out = ijkVecLength2d(v_in)));
}

ijk_inl dvec2 ijkVecNormalizeGetLengthInv2d(dvec2 const v_in, double* const lengthInv_out)
{
	return ijkVecMul2ds(v_in, (*lengthInv_out = ijkVecLengthInv2d(v_in)));
}

ijk_inl dvec2 ijkVecNormalizeSafeGetLengthInv2d(dvec2 const v_in, double* const lengthInv_out)
{
	return ijkVecMul2ds(v_in, (*lengthInv_out = ijkVecLengthInvSafe2d(v_in)));
}

ijk_inl double ijkVecCrossNormalize2d(dvec2 const v_lh, dvec2 const v_rh)
{
	double const cross = ijkVecCross2d(v_lh, v_rh);
	return ijk_sgn_dbl(cross);
}

ijk_inl double ijkVecCrossNormalizeSafe2d(dvec2 const v_lh, dvec2 const v_rh)
{
	double const cross = ijkVecCross2d(v_lh, v_rh);
	return ijk_sgn_dbl(cross);
}

ijk_inl double ijkVecCrossNormalizeGetLength2d(dvec2 const v_lh, dvec2 const v_rh, double* const length_out)
{
	double const cross = ijkVecCross2d(v_lh, v_rh);
	*length_out = ijk_abs_dbl(cross);
	return ijk_sgn_dbl(cross);
}

ijk_inl double ijkVecCrossNormalizeSafeGetLength2d(dvec2 const v_lh, dvec2 const v_rh, double* const length_out)
{
	double const cross = ijkVecCross2d(v_lh, v_rh);
	*length_out = ijk_abs_dbl(cross);
	return ijk_sgn_dbl(cross);
}

ijk_inl double ijkVecCrossNormalizeGetLengthInv2d(dvec2 const v_lh, dvec2 const v_rh, double* const lengthInv_out)
{
	double const cross = ijkVecCross2d(v_lh, v_rh);
	double const length = ijk_abs_dbl(cross);
	*lengthInv_out = ijk_recip_dbl(length);
	return ijk_sgn_dbl(cross);
}

ijk_inl double ijkVecCrossNormalizeSafeGetLengthInv2d(dvec2 const v_lh, dvec2 const v_rh, double* const lengthInv_out)
{
	double const cross = ijkVecCross2d(v_lh, v_rh);
	double const length = ijk_abs_dbl(cross);
	*lengthInv_out = ijk_recip_safe_dbl(length);
	return ijk_sgn_dbl(cross);
}

ijk_inl dvec2 ijkVecLerp2d(dvec2 const v0, dvec2 const v1, double const u)
{
	dvec2 const v_out = {
		ijkInterpLinear_dbl(v0.x, v1.x, u),
		ijkInterpLinear_dbl(v0.y, v1.y, u),
	};
	return v_out;
}

ijk_inl dvec2 ijkVecLerpInv2d(dvec2 const v0, dvec2 const v1, dvec2 const v_lerp)
{
	dvec2 const v_out = {
		ijkInterpLinearInv_dbl(v0.x, v1.x, v_lerp.x),
		ijkInterpLinearInv_dbl(v0.y, v1.y, v_lerp.y),
	};
	return v_out;
}

ijk_inl dvec2 ijkVecLerpRevInit2d(dvec2 const v_lerp, dvec2 const v1, double const u)
{
	double const s = ijk_recip_dbl(flt_one - u);
	dvec2 const v0_out = {
		(v_lerp.x - v1.x * u) * s,
		(v_lerp.y - v1.y * u) * s,
	};
	return v0_out;
}

ijk_inl dvec2 ijkVecLerpRevTerm2d(dvec2 const v0, dvec2 const v_lerp, double const u)
{
	return ijkVecLerp2d(v0, v_lerp, ijk_recip_dbl(u));
}

ijk_inl double ijkVecProjRatio2d(dvec2 const v_base, dvec2 const v_in)
{
	return (ijkVecDot2d(v_base, v_in) / ijkVecLengthSq2d(v_base));
}

ijk_inl dvec2 ijkVecProj2d(dvec2 const v_base, dvec2 const v_in)
{
	return ijkVecMul2ds(v_base, ijkVecProjRatio2d(v_base, v_in));
}

ijk_inl dvec2 ijkVecOrtho2d(dvec2 const v_base, dvec2 const v_in)
{
	return ijkVecSub2d(v_in, ijkVecProj2d(v_base, v_in));
}

ijk_inl dvec2 ijkVecOrthoNorm2d(dvec2 const v_base, dvec2 const v_in, dvec2* const v_base_norm_out)
{
	dvec2 const v_base_norm = *v_base_norm_out = ijkVecNormalize2d(v_base);
	return ijkVecNormalize2d(ijkVecSub2d(v_in, ijkVecMul2ds(v_base_norm, ijkVecDot2d(v_base_norm, v_in))));
}

ijk_inl dvec2* ijkVecOrthoList2d(dvec2 vl_out[], dvec2 const v_base, dvec2 const vl_in[], size const n)
{
	dvec2 orthoSum;
	dvec2 vp_in;
	uindex i, j;
	for (i = 0; i < n; ++i)
	{
		vp_in = vl_in[i];
		orthoSum = ijkVecProj2d(v_base, vp_in);
		for (j = 0; j < i; ++j)
			orthoSum = ijkVecAdd2d(orthoSum, ijkVecProj2d(vl_out[j], vp_in));
		vl_out[i] = ijkVecSub2d(vp_in, orthoSum);
	}
	return vl_out;
}

ijk_inl dvec2* ijkVecOrthoNormList2d(dvec2 vl_out[], dvec2 const v_base, dvec2 const vl_in[], size const n, dvec2* const v_base_norm_out)
{
	dvec2 orthoSum;
	dvec2 vp_in;
	uindex i, j;
	dvec2 const v_base_norm = *v_base_norm_out = ijkVecNormalize2d(v_base);
	for (i = 0; i < n; ++i)
	{
		vp_in = vl_in[i];
		orthoSum = ijkVecMul2ds(v_base_norm, ijkVecDot2d(v_base_norm, vp_in));
		for (j = 0; j < i; ++j)
			orthoSum = ijkVecAdd2d(orthoSum, ijkVecMul2ds(vl_out[j], ijkVecDot2d(vl_out[j], vp_in)));
		vl_out[i] = ijkVecNormalize2d(ijkVecSub2d(vp_in, orthoSum));
	}
	return vl_out;
}


//-----------------------------------------------------------------------------

ijk_inl double ijkVecLengthSq3d(dvec3 const v_in)
{
	return ijkVecDot3d(v_in, v_in);
}

ijk_inl double ijkVecLength3d(dvec3 const v_in)
{
	return ijkSqrt_dbl(ijkVecLengthSq3d(v_in));
}

ijk_inl double ijkVecLengthSqInv3d(dvec3 const v_in)
{
	return ijk_recip_dbl(ijkVecLengthSq3d(v_in));
}

ijk_inl double ijkVecLengthSqInvSafe3d(dvec3 const v_in)
{
	double const lengthSq = ijkVecLengthSq3d(v_in);
	return ijk_recip_safe_dbl(lengthSq);
}

ijk_inl double ijkVecLengthInv3d(dvec3 const v_in)
{
	return ijkSqrtInv_dbl(ijkVecLengthSq3d(v_in));
}

ijk_inl double ijkVecLengthInvSafe3d(dvec3 const v_in)
{
	double const lengthSq = ijkVecLengthSq3d(v_in);
	return (lengthSq > flt_zero ? ijkSqrtInv_dbl(lengthSq) : flt_zero);
}

ijk_inl dvec3 ijkVecNormalize3d(dvec3 const v_in)
{
	return ijkVecMul3ds(v_in, ijkVecLengthInv3d(v_in));
}

ijk_inl dvec3 ijkVecNormalizeSafe3d(dvec3 const v_in)
{
	return ijkVecMul3ds(v_in, ijkVecLengthInvSafe3d(v_in));
}

ijk_inl dvec3 ijkVecNormalizeGetLength3d(dvec3 const v_in, double* const length_out)
{
	return ijkVecDiv3ds(v_in, (*length_out = ijkVecLength3d(v_in)));
}

ijk_inl dvec3 ijkVecNormalizeSafeGetLength3d(dvec3 const v_in, double* const length_out)
{
	return ijkVecDivSafe3ds(v_in, (*length_out = ijkVecLength3d(v_in)));
}

ijk_inl dvec3 ijkVecNormalizeGetLengthInv3d(dvec3 const v_in, double* const lengthInv_out)
{
	return ijkVecMul3ds(v_in, (*lengthInv_out = ijkVecLengthInv3d(v_in)));
}

ijk_inl dvec3 ijkVecNormalizeSafeGetLengthInv3d(dvec3 const v_in, double* const lengthInv_out)
{
	return ijkVecMul3ds(v_in, (*lengthInv_out = ijkVecLengthInvSafe3d(v_in)));
}

ijk_inl dvec3 ijkVecCrossNormalize3d(dvec3 const v_lh, dvec3 const v_rh)
{
	return ijkVecNormalize3d(ijkVecCross3d(v_lh, v_rh));
}

ijk_inl dvec3 ijkVecCrossNormalizeSafe3d(dvec3 const v_lh, dvec3 const v_rh)
{
	return ijkVecNormalizeSafe3d(ijkVecCross3d(v_lh, v_rh));
}

ijk_inl dvec3 ijkVecCrossNormalizeGetLength3d(dvec3 const v_lh, dvec3 const v_rh, double* const length_out)
{
	return ijkVecNormalizeGetLength3d(ijkVecCross3d(v_lh, v_rh), length_out);
}

ijk_inl dvec3 ijkVecCrossNormalizeSafeGetLength3d(dvec3 const v_lh, dvec3 const v_rh, double* const length_out)
{
	return ijkVecNormalizeSafeGetLength3d(ijkVecCross3d(v_lh, v_rh), length_out);
}

ijk_inl dvec3 ijkVecCrossNormalizeGetLengthInv3d(dvec3 const v_lh, dvec3 const v_rh, double* const lengthInv_out)
{
	return ijkVecNormalizeGetLengthInv3d(ijkVecCross3d(v_lh, v_rh), lengthInv_out);
}

ijk_inl dvec3 ijkVecCrossNormalizeSafeGetLengthInv3d(dvec3 const v_lh, dvec3 const v_rh, double* const lengthInv_out)
{
	return ijkVecNormalizeSafeGetLengthInv3d(ijkVecCross3d(v_lh, v_rh), lengthInv_out);
}

ijk_inl dvec3 ijkVecLerp3d(dvec3 const v0, dvec3 const v1, double const u)
{
	dvec3 const v_out = {
		ijkInterpLinear_dbl(v0.x, v1.x, u),
		ijkInterpLinear_dbl(v0.y, v1.y, u),
		ijkInterpLinear_dbl(v0.z, v1.z, u),
	};
	return v_out;
}

ijk_inl dvec3 ijkVecLerpInv3d(dvec3 const v0, dvec3 const v1, dvec3 const v_lerp)
{
	dvec3 const v_out = {
		ijkInterpLinearInv_dbl(v0.x, v1.x, v_lerp.x),
		ijkInterpLinearInv_dbl(v0.y, v1.y, v_lerp.y),
		ijkInterpLinearInv_dbl(v0.z, v1.z, v_lerp.z),
	};
	return v_out;
}

ijk_inl dvec3 ijkVecLerpRevInit3d(dvec3 const v_lerp, dvec3 const v1, double const u)
{
	double const s = ijk_recip_dbl(flt_one - u);
	dvec3 const v0_out = {
		(v_lerp.x - v1.x * u) * s,
		(v_lerp.y - v1.y * u) * s,
		(v_lerp.z - v1.z * u) * s,
	};
	return v0_out;
}

ijk_inl dvec3 ijkVecLerpRevTerm3d(dvec3 const v0, dvec3 const v_lerp, double const u)
{
	return ijkVecLerp3d(v0, v_lerp, ijk_recip_dbl(u));
}

ijk_inl double ijkVecProjRatio3d(dvec3 const v_base, dvec3 const v_in)
{
	return (ijkVecDot3d(v_base, v_in) / ijkVecLengthSq3d(v_base));
}

ijk_inl dvec3 ijkVecProj3d(dvec3 const v_base, dvec3 const v_in)
{
	return ijkVecMul3ds(v_base, ijkVecProjRatio3d(v_base, v_in));
}

ijk_inl dvec3 ijkVecOrtho3d(dvec3 const v_base, dvec3 const v_in)
{
	return ijkVecSub3d(v_in, ijkVecProj3d(v_base, v_in));
}

ijk_inl dvec3 ijkVecOrthoNorm3d(dvec3 const v_base, dvec3 const v_in, dvec3* const v_base_norm_out)
{
	dvec3 const v_base_norm = *v_base_norm_out = ijkVecNormalize3d(v_base);
	return ijkVecNormalize3d(ijkVecSub3d(v_in, ijkVecMul3ds(v_base_norm, ijkVecDot3d(v_base_norm, v_in))));
}

ijk_inl dvec3* ijkVecOrthoList3d(dvec3 vl_out[], dvec3 const v_base, dvec3 const vl_in[], size const n)
{
	dvec3 orthoSum;
	dvec3 vp_in;
	uindex i, j;
	for (i = 0; i < n; ++i)
	{
		vp_in = vl_in[i];
		orthoSum = ijkVecProj3d(v_base, vp_in);
		for (j = 0; j < i; ++j)
			orthoSum = ijkVecAdd3d(orthoSum, ijkVecProj3d(vl_out[j], vp_in));
		vl_out[i] = ijkVecSub3d(vp_in, orthoSum);
	}
	return vl_out;
}

ijk_inl dvec3* ijkVecOrthoNormList3d(dvec3 vl_out[], dvec3 const v_base, dvec3 const vl_in[], size const n, dvec3* const v_base_norm_out)
{
	dvec3 orthoSum;
	dvec3 vp_in;
	uindex i, j;
	dvec3 const v_base_norm = *v_base_norm_out = ijkVecNormalize3d(v_base);
	for (i = 0; i < n; ++i)
	{
		vp_in = vl_in[i];
		orthoSum = ijkVecMul3ds(v_base_norm, ijkVecDot3d(v_base_norm, vp_in));
		for (j = 0; j < i; ++j)
			orthoSum = ijkVecAdd3d(orthoSum, ijkVecMul3ds(vl_out[j], ijkVecDot3d(vl_out[j], vp_in)));
		vl_out[i] = ijkVecNormalize3d(ijkVecSub3d(vp_in, orthoSum));
	}
	return vl_out;
}


//-----------------------------------------------------------------------------

ijk_inl double ijkVecLengthSq4d(dvec4 const v_in)
{
	return ijkVecDot4d(v_in, v_in);
}

ijk_inl double ijkVecLength4d(dvec4 const v_in)
{
	return ijkSqrt_dbl(ijkVecLengthSq4d(v_in));
}

ijk_inl double ijkVecLengthSqInv4d(dvec4 const v_in)
{
	return ijk_recip_dbl(ijkVecLengthSq4d(v_in));
}

ijk_inl double ijkVecLengthSqInvSafe4d(dvec4 const v_in)
{
	double const lengthSq = ijkVecLengthSq4d(v_in);
	return ijk_recip_safe_dbl(lengthSq);
}

ijk_inl double ijkVecLengthInv4d(dvec4 const v_in)
{
	return ijkSqrtInv_dbl(ijkVecLengthSq4d(v_in));
}

ijk_inl double ijkVecLengthInvSafe4d(dvec4 const v_in)
{
	double const lengthSq = ijkVecLengthSq4d(v_in);
	return (lengthSq > flt_zero ? ijkSqrtInv_dbl(lengthSq) : flt_zero);
}

ijk_inl dvec4 ijkVecNormalize4d(dvec4 const v_in)
{
	return ijkVecMul4ds(v_in, ijkVecLengthInv4d(v_in));
}

ijk_inl dvec4 ijkVecNormalizeSafe4d(dvec4 const v_in)
{
	return ijkVecMul4ds(v_in, ijkVecLengthInvSafe4d(v_in));
}

ijk_inl dvec4 ijkVecNormalizeGetLength4d(dvec4 const v_in, double* const length_out)
{
	return ijkVecDiv4ds(v_in, (*length_out = ijkVecLength4d(v_in)));
}

ijk_inl dvec4 ijkVecNormalizeSafeGetLength4d(dvec4 const v_in, double* const length_out)
{
	return ijkVecDivSafe4ds(v_in, (*length_out = ijkVecLength4d(v_in)));
}

ijk_inl dvec4 ijkVecNormalizeGetLengthInv4d(dvec4 const v_in, double* const lengthInv_out)
{
	return ijkVecMul4ds(v_in, (*lengthInv_out = ijkVecLengthInv4d(v_in)));
}

ijk_inl dvec4 ijkVecNormalizeSafeGetLengthInv4d(dvec4 const v_in, double* const lengthInv_out)
{
	return ijkVecMul4ds(v_in, (*lengthInv_out = ijkVecLengthInvSafe4d(v_in)));
}

ijk_inl dvec4 ijkVecCrossNormalize4d(dvec4 const v_lh, dvec4 const v_rh)
{
	return ijkVecNormalize4d(ijkVecCross4d(v_lh, v_rh));
}

ijk_inl dvec4 ijkVecCrossNormalizeSafe4d(dvec4 const v_lh, dvec4 const v_rh)
{
	return ijkVecNormalizeSafe4d(ijkVecCross4d(v_lh, v_rh));
}

ijk_inl dvec4 ijkVecCrossNormalizeGetLength4d(dvec4 const v_lh, dvec4 const v_rh, double* const length_out)
{
	return ijkVecNormalizeGetLength4d(ijkVecCross4d(v_lh, v_rh), length_out);
}

ijk_inl dvec4 ijkVecCrossNormalizeSafeGetLength4d(dvec4 const v_lh, dvec4 const v_rh, double* const length_out)
{
	return ijkVecNormalizeSafeGetLength4d(ijkVecCross4d(v_lh, v_rh), length_out);
}

ijk_inl dvec4 ijkVecCrossNormalizeGetLengthInv4d(dvec4 const v_lh, dvec4 const v_rh, double* const lengthInv_out)
{
	return ijkVecNormalizeGetLengthInv4d(ijkVecCross4d(v_lh, v_rh), lengthInv_out);
}

ijk_inl dvec4 ijkVecCrossNormalizeSafeGetLengthInv4d(dvec4 const v_lh, dvec4 const v_rh, double* const lengthInv_out)
{
	return ijkVecNormalizeSafeGetLengthInv4d(ijkVecCross4d(v_lh, v_rh), lengthInv_out);
}

ijk_inl dvec4 ijkVecLerp4d(dvec4 const v0, dvec4 const v1, double const u)
{
	dvec4 const v_out = {
		ijkInterpLinear_dbl(v0.x, v1.x, u),
		ijkInterpLinear_dbl(v0.y, v1.y, u),
		ijkInterpLinear_dbl(v0.z, v1.z, u),
		ijkInterpLinear_dbl(v0.w, v1.w, u),
	};
	return v_out;
}

ijk_inl dvec4 ijkVecLerpInv4d(dvec4 const v0, dvec4 const v1, dvec4 const v_lerp)
{
	dvec4 const v_out = {
		ijkInterpLinearInv_dbl(v0.x, v1.x, v_lerp.x),
		ijkInterpLinearInv_dbl(v0.y, v1.y, v_lerp.y),
		ijkInterpLinearInv_dbl(v0.z, v1.z, v_lerp.z),
		ijkInterpLinearInv_dbl(v0.w, v1.w, v_lerp.w),
	};
	return v_out;
}

ijk_inl dvec4 ijkVecLerpRevInit4d(dvec4 const v_lerp, dvec4 const v1, double const u)
{
	double const s = ijk_recip_dbl(flt_one - u);
	dvec4 const v0_out = {
		(v_lerp.x - v1.x * u) * s,
		(v_lerp.y - v1.y * u) * s,
		(v_lerp.z - v1.z * u) * s,
		(v_lerp.w - v1.w * u) * s,
	};
	return v0_out;
}

ijk_inl dvec4 ijkVecLerpRevTerm4d(dvec4 const v0, dvec4 const v_lerp, double const u)
{
	return ijkVecLerp4d(v0, v_lerp, ijk_recip_dbl(u));
}

ijk_inl double ijkVecProjRatio4d(dvec4 const v_base, dvec4 const v_in)
{
	return (ijkVecDot4d(v_base, v_in) / ijkVecLengthSq4d(v_base));
}

ijk_inl dvec4 ijkVecProj4d(dvec4 const v_base, dvec4 const v_in)
{
	return ijkVecMul4ds(v_base, ijkVecProjRatio4d(v_base, v_in));
}

ijk_inl dvec4 ijkVecOrtho4d(dvec4 const v_base, dvec4 const v_in)
{
	return ijkVecSub4d(v_in, ijkVecProj4d(v_base, v_in));
}

ijk_inl dvec4 ijkVecOrthoNorm4d(dvec4 const v_base, dvec4 const v_in, dvec4* const v_base_norm_out)
{
	dvec4 const v_base_norm = *v_base_norm_out = ijkVecNormalize4d(v_base);
	return ijkVecNormalize4d(ijkVecSub4d(v_in, ijkVecMul4ds(v_base_norm, ijkVecDot4d(v_base_norm, v_in))));
}

ijk_inl dvec4* ijkVecOrthoList4d(dvec4 vl_out[], dvec4 const v_base, dvec4 const vl_in[], size const n)
{
	dvec4 orthoSum;
	dvec4 vp_in;
	uindex i, j;
	for (i = 0; i < n; ++i)
	{
		vp_in = vl_in[i];
		orthoSum = ijkVecProj4d(v_base, vp_in);
		for (j = 0; j < i; ++j)
			orthoSum = ijkVecAdd4d(orthoSum, ijkVecProj4d(vl_out[j], vp_in));
		vl_out[i] = ijkVecSub4d(vp_in, orthoSum);
	}
	return vl_out;
}

ijk_inl dvec4* ijkVecOrthoNormList4d(dvec4 vl_out[], dvec4 const v_base, dvec4 const vl_in[], size const n, dvec4* const v_base_norm_out)
{
	dvec4 orthoSum;
	dvec4 vp_in;
	uindex i, j;
	dvec4 const v_base_norm = *v_base_norm_out = ijkVecNormalize4d(v_base);
	for (i = 0; i < n; ++i)
	{
		vp_in = vl_in[i];
		orthoSum = ijkVecMul4ds(v_base_norm, ijkVecDot4d(v_base_norm, vp_in));
		for (j = 0; j < i; ++j)
			orthoSum = ijkVecAdd4d(orthoSum, ijkVecMul4ds(vl_out[j], ijkVecDot4d(vl_out[j], vp_in)));
		vl_out[i] = ijkVecNormalize4d(ijkVecSub4d(vp_in, orthoSum));
	}
	return vl_out;
}


//-----------------------------------------------------------------------------


#endif	// !_IJK_VECTOR_DOUBLE_INL_
#endif	// _IJK_VECTOR_DOUBLE_H_