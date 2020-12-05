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
	double3 const c = {
		(v_lh[1] * v_rh[2] - v_lh[2] * v_rh[1]),
		(v_lh[2] * v_rh[0] - v_lh[0] * v_rh[2]),
		(v_lh[0] * v_rh[1] - v_lh[1] * v_rh[0]),
	};
	return ijkVecCopy3dv(v_out, c);
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
	return (lengthSq > dbl_zero ? ijkSqrtInv_dbl(lengthSq) : dbl_zero);
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
	f64 const s = ijk_recip_dbl(dbl_one - u);
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

ijk_inl doublev ijkVecNlerp2dv(double2 v_out, double2 const v0, double2 const v1, f64 const u)
{
	ijkVecLerp2dv(v_out, v0, v1, u);
	return ijkVecNormalize2dv(v_out, v_out);
}

ijk_inl doublev ijkVecSlerp2dv(double2 v_out, double2 const v0, double2 const v1, f64 const u)
{
	// slerp[v0,v1](u) = (sin([1 - u]A)v0 + sin(uA)v1) / sin(A)
	//	A = acos(dot(v0,v1))

	//f64 const lenInv0 = ijkVecLengthInv2dv(v0), lenInv1 = ijkVecLengthInv2dv(v1);
	// check if vectors are far enough apart to have an effect
	f64 const dot = ijkVecDot2dv(v0, v1);
	if ((dot * dot) < dbl_one)
	{
		double2 tmp;
		f64 const angle = ijkTrigAcos_deg_dbl(dot),
			sinInv = ijkTrigCsc_deg_dbl(angle),
			s0 = sinInv * ijkTrigSin_deg_dbl(angle * (dbl_one - u)),
			s1 = sinInv * ijkTrigSin_deg_dbl(angle * u);
		return ijkVecAdd2dv(v_out, ijkVecMul2dvs(v_out, v0, s0), ijkVecMul2dvs(tmp, v1, s1));
	}
	// vectors are parallel; just do lerp
	return ijkVecLerp2dv(v_out, v0, v1, u);
}

ijk_inl doublev ijkVecReflectScale2dv(double2 v_out, double2 const v_in, double2 const v_nrm)
{
	// v' = v|n|^2 - 2dot(v, n)n
	f64 const d = dbl_two * ijkVecDot2dv(v_in, v_nrm), lenSq = ijkVecLengthSq2dv(v_nrm);
	v_out[0] = v_in[0] * lenSq - d * v_nrm[0];
	v_out[1] = v_in[1] * lenSq - d * v_nrm[1];
	return v_out;
}

ijk_inl doublev ijkVecUnitReflect2dv(double2 v_out, double2 const v_in, double2 const v_nrm)
{
	// v' = v - 2dot(v, n)n
	f64 const d = dbl_two * ijkVecDot2dv(v_in, v_nrm);
	v_out[0] = v_in[0] - d * v_nrm[0];
	v_out[1] = v_in[1] - d * v_nrm[1];
	return v_out;
}

ijk_inl doublev ijkVecReflect2dv(double2 v_out, double2 const v_in, double2 const v_nrm)
{
	// v' /= |n|^2
	//		= v - 2dot(v, n)n / |n|^2
	f64 const d = dbl_two * ijkVecDot2dv(v_in, v_nrm), lenSqInv = d * ijkVecLengthSqInv2dv(v_nrm);
	v_out[0] = v_in[0] - lenSqInv * v_nrm[0];
	v_out[1] = v_in[1] - lenSqInv * v_nrm[1];
	return v_out;
}

ijk_inl f64 ijkVecDistance2dv(double2 const v_lh, double2 const v_rh)
{
	double2 const diff = {
		(v_lh[0] - v_rh[0]),
		(v_lh[1] - v_rh[1]),
	};
	return ijkVecLength2dv(diff);
}

ijk_inl doublev ijkVecResize2dv(double2 v_out, double2 const v_in, f64 const length)
{
	f64 const s = length * ijkVecLengthInv2dv(v_in);
	return ijkVecMul2dvs(v_out, v_in, s);
}

ijk_inl doublev ijkVecResizeSafe2dv(double2 v_out, double2 const v_in, f64 const length)
{
	f64 const s = length * ijkVecLengthInvSafe2dv(v_in);
	return ijkVecMul2dvs(v_out, v_in, s);
}

ijk_inl f64 ijkVecCrossResize2dv(double2 const v_lh, double2 const v_rh, f64 const length)
{
	return (length * ijkVecCrossNormalize2dv(v_lh, v_rh));
}

ijk_inl f64 ijkVecCrossResizeSafe2dv(double2 const v_lh, double2 const v_rh, f64 const length)
{
	return (length * ijkVecCrossNormalizeSafe2dv(v_lh, v_rh));
}

ijk_inl doublev ijkVecNearest2dv(double2 v_out, double2 const v0, double2 const v1, f64 const u)
{
	return ijkVecCopy2dv(v_out, (u < dbl_half ? v0 : v1));
}

ijk_inl doublev ijkVecBinearest2dv(double2 v_out, double2 const v00, double2 const v01, double2 const v10, double2 const v11, f64 const u0, f64 const u1, f64 const u)
{
	return ijkVecCopy2dv(v_out, (u < dbl_half ? u0 < dbl_half ? v00 : v01 : u1 < dbl_half ? v10 : v11));
}

ijk_inl doublev ijkVecRemap2dv(double2 v_out, double2 const v0_dst, double2 const v1_dst, double2 const v0_src, double2 const v1_src, double2 const v_src)
{
	v_out[0] = ijkInterpRemap_dbl(v0_dst[0], v1_dst[0], v0_src[0], v1_src[0], v_src[0]);
	v_out[1] = ijkInterpRemap_dbl(v0_dst[1], v1_dst[1], v0_src[1], v1_src[1], v_src[1]);
	return v_out;
}

ijk_inl doublev ijkVecBezier0O2dv(double2 v_out, double2 const v0, f64 const u)
{
	return ijkVecCopy2dv(v_out, v0);
}

ijk_inl doublev ijkVecBezier1O2dv(double2 v_out, double2 const v0, double2 const v1, f64 const u)
{
	return ijkVecLerp2dv(v_out, v0, v1, u);
}

ijk_inl doublev ijkVecBezier2O2dv(double2 v_out, double2 const v0, double2 const v1, double2 const v2, f64 const u)
{
	double2 u0, u1;
	ijkVecBezier1O2dv(u0, v0, v1, u);
	ijkVecBezier1O2dv(u1, v1, v2, u);
	return ijkVecLerp2dv(v_out, u0, u1, u);
}

ijk_inl doublev ijkVecBezier3O2dv(double2 v_out, double2 const v0, double2 const v1, double2 const v2, double2 const v3, f64 const u)
{
	double2 u0, u1;
	ijkVecBezier2O2dv(u0, v0, v1, v2, u);
	ijkVecBezier2O2dv(u1, v1, v2, v3, u);
	return ijkVecLerp2dv(v_out, u0, u1, u);
}

ijk_inl doublev ijkVecBezierNO2dv(double2 v_out, double2 const v[], size const order, f64 const u)
{
	double2 u0, u1;
	if (order > 0)
		return ijkVecLerp2dv(v_out, ijkVecBezierNO2dv(u0, v + 0, order - 1, u), ijkVecBezierNO2dv(u1, v + 1, order - 1, u), u);
	return ijkVecCopy2dv(v_out, *v);
}

ijk_inl doublev ijkVecCubicHermite2dv(double2 v_out, double2 const v0, double2 const dv0, double2 const v1, double2 const dv1, f64 const u)
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
	f64 const u2 = u * u, u3 = u * u2;
	double4 const k = {
		(dbl_one - dbl_three * u2 + dbl_two * u3),
		(u - dbl_two * u2 + u3),
		(dbl_three * u2 - dbl_two * u3),
		(u3 - u2),
	};
	v_out[0] = (k[0] * v0[0] + k[1] * dv0[0] + k[2] * v1[0] + k[3] * dv1[0]);
	v_out[1] = (k[0] * v0[1] + k[1] * dv0[1] + k[2] * v1[1] + k[3] * dv1[1]);
	return v_out;
}

ijk_inl doublev ijkVecCubicHermiteHandles2dv(double2 v_out, double2 const v0, double2 const cv0, double2 const v1, double2 const cv1, f64 const u)
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
	f64 const u2 = u * u, u3 = u * u2;
	double4 const k = {
		(dbl_one - u - u2 + u3),
		(u - dbl_two * u2 + u3),
		(dbl_four * u2 - dbl_three * u3),
		(u3 - u2),
	};
	v_out[0] = (k[0] * v0[0] + k[1] * cv0[0] + k[2] * v1[0] + k[3] * cv1[0]);
	v_out[1] = (k[0] * v0[1] + k[1] * cv0[1] + k[2] * v1[1] + k[3] * cv1[1]);
	return v_out;
}

ijk_inl doublev ijkVecCubicCatmullRom2dv(double2 v_out, double2 const vp, double2 const v0, double2 const v1, double2 const v2, f64 const u)
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
	f64 const uh = dbl_half * u, u2h = u * uh, u3h = u * u2h;
	double4 const k = {
		(dbl_two * u2h - uh - u3h),
		(dbl_one - dbl_five * u2h + dbl_three * u3h),
		(uh + dbl_four * u2h - dbl_three * u3h),
		(u3h - u2h),
	};
	v_out[0] = (k[0] * vp[0] + k[1] * v0[0] + k[2] * v1[0] + k[3] * v2[0]);
	v_out[1] = (k[0] * vp[1] + k[1] * v0[1] + k[2] * v1[1] + k[3] * v2[1]);
	return v_out;
}

ijk_inl doublev ijkVecBicubicCatmullRom2dv(double2 v_out, double2 const vpp, double2 const vp0, double2 const vp1, double2 const vp2, double2 const v0p, double2 const v00, double2 const v01, double2 const v02, double2 const v1p, double2 const v10, double2 const v11, double2 const v12, double2 const v2p, double2 const v20, double2 const v21, double2 const v22, f64 const up, f64 const u0, f64 const u1, f64 const u2, f64 const u)
{
	double2 vp, v0, v1, v2;
	ijkVecCubicCatmullRom2dv(vp, vpp, vp0, vp1, vp2, up);
	ijkVecCubicCatmullRom2dv(v0, v0p, v00, v01, v02, u0);
	ijkVecCubicCatmullRom2dv(v1, v1p, v10, v11, v12, u1);
	ijkVecCubicCatmullRom2dv(v2, v2p, v20, v21, v22, u2);
	return ijkVecCubicCatmullRom2dv(v_out, vp, v0, v1, v2, u);
}

ijk_inl f64 ijkVecReparamCubicHermite2dv(f64 uTable_out[], f64 lTable_out[], double2 vTable_out[], size const numDivisions, ibool const lNormalize, double2 const v0, double2 const dv0, double2 const v1, double2 const dv1)
{
	f64 u = dbl_zero, du, arcLength = dbl_zero, arcLengthInv;
	f64* lTable = lTable_out;
	uindex i;
	doublekv v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		vc = ijkVecCopy2dv(*vTable_out, v0);

		for (i = 1, du = ijk_recip_dbl((f64)numDivisions); i <= numDivisions; ++i)
		{
			u = (f64)i * du;
			v = ijkVecCubicHermite2dv(*(++vTable_out), v0, dv0, v1, dv1, u);
			arcLength += ijkVecDistance2dv(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_dbl(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl f64 ijkVecReparamCubicHermiteHandles2dv(f64 uTable_out[], f64 lTable_out[], double2 vTable_out[], size const numDivisions, ibool const lNormalize, double2 const v0, double2 const cv0, double2 const v1, double2 const cv1)
{
	f64 u = dbl_zero, du, arcLength = dbl_zero, arcLengthInv;
	f64* lTable = lTable_out;
	uindex i;
	doublekv v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		vc = ijkVecCopy2dv(*vTable_out, v0);

		for (i = 1, du = ijk_recip_dbl((f64)numDivisions); i <= numDivisions; ++i)
		{
			u = (f64)i * du;
			v = ijkVecCubicHermiteHandles2dv(*(++vTable_out), v0, cv0, v1, cv1, u);
			arcLength += ijkVecDistance2dv(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_dbl(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl f64 ijkVecReparamCubicCatmullRom2dv(f64 uTable_out[], f64 lTable_out[], double2 vTable_out[], size const numDivisions, ibool const lNormalize, double2 const vp, double2 const v0, double2 const v1, double2 const v2)
{
	f64 u = dbl_zero, du, arcLength = dbl_zero, arcLengthInv;
	f64* lTable = lTable_out;
	uindex i;
	doublekv v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		vc = ijkVecCopy2dv(*vTable_out, v0);

		for (i = 1, du = ijk_recip_dbl((f64)numDivisions); i <= numDivisions; ++i)
		{
			u = (f64)i * du;
			v = ijkVecCubicCatmullRom2dv(*(++vTable_out), vp, v0, v1, v2, u);
			arcLength += ijkVecDistance2dv(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_dbl(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl f64 ijkVecReparamBicubicCatmullRom2dv(f64 uTable_out[], f64 lTable_out[], double2 vTable_out[], size const numDivisions, ibool const lNormalize, double2 const vpp, double2 const vp0, double2 const vp1, double2 const vp2, double2 const v0p, double2 const v00, double2 const v01, double2 const v02, double2 const v1p, double2 const v10, double2 const v11, double2 const v12, double2 const v2p, double2 const v20, double2 const v21, double2 const v22, f64 const up, f64 const u0, f64 const u1, f64 const u2)
{
	f64 u = dbl_zero, du, arcLength = dbl_zero, arcLengthInv;
	f64* lTable = lTable_out;
	uindex i;
	doublekv v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		double2 vp, v0, v1, v2;
		ijkVecCubicCatmullRom2dv(vp, vpp, vp0, vp1, vp2, up);
		ijkVecCubicCatmullRom2dv(v0, v0p, v00, v01, v02, u0);
		ijkVecCubicCatmullRom2dv(v1, v1p, v10, v11, v12, u1);
		ijkVecCubicCatmullRom2dv(v2, v2p, v20, v21, v22, u2);

		*uTable_out = u;
		*lTable_out = arcLength;
		vc = ijkVecCopy2dv(*vTable_out, v0);

		for (i = 1, du = ijk_recip_dbl((f64)numDivisions); i <= numDivisions; ++i)
		{
			u = (f64)i * du;
			v = ijkVecCubicCatmullRom2dv(*(++vTable_out), vp, v0, v1, v2, u);
			arcLength += ijkVecDistance2dv(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_dbl(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl doublev ijkVecSampleTableInc2dv(double2 v_out, f64 const uTable[], double2 const vTable[], index i, index di, f64 const u)
{
	doublekv v0, v1;
	f64 uReparam;
	f64 u0, u1 = *(uTable + (i += (di ? di : (di = 1))));

	while (u1 < u)
		u1 = *(uTable + (i += di));
	v1 = *(vTable + i);
	v0 = *(vTable + (i -= di));
	u0 = *(uTable + i);
	uReparam = ijkInterpLinearInv_dbl(u0, u1, u);
	return ijkVecLerp2dv(v_out, v0, v1, uReparam);
}

ijk_inl doublev ijkVecSampleTableDec2dv(double2 v_out, f64 const uTable[], double2 const vTable[], index i, index di, f64 const u)
{
	doublekv v0, v1;
	f64 uReparam;
	f64 u0, u1 = *(uTable + (i += (di ? di : (di = 1))));

	while (u1 > u)
		u1 = *(uTable + (i += di));
	v1 = *(vTable + i);
	v0 = *(vTable + (i -= di));
	u0 = *(uTable + i);
	uReparam = ijkInterpLinearInv_dbl(u0, u1, u);
	return ijkVecLerp2dv(v_out, v0, v1, uReparam);
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
	return (lengthSq > dbl_zero ? ijkSqrtInv_dbl(lengthSq) : dbl_zero);
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
	f64 const s = ijk_recip_dbl(dbl_one - u);
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

ijk_inl doublev ijkVecNlerp3dv(double3 v_out, double3 const v0, double3 const v1, f64 const u)
{
	ijkVecLerp3dv(v_out, v0, v1, u);
	return ijkVecNormalize3dv(v_out, v_out);
}

ijk_inl doublev ijkVecSlerp3dv(double3 v_out, double3 const v0, double3 const v1, f64 const u)
{
	f64 const dot = ijkVecDot3dv(v0, v1);
	if ((dot * dot) < dbl_one)
	{
		double3 tmp;
		f64 const angle = ijkTrigAcos_deg_dbl(dot),
			sinInv = ijkTrigCsc_deg_dbl(angle),
			s0 = sinInv * ijkTrigSin_deg_dbl(angle * (dbl_one - u)),
			s1 = sinInv * ijkTrigSin_deg_dbl(angle * u);
		return ijkVecAdd3dv(v_out, ijkVecMul3dvs(v_out, v0, s0), ijkVecMul3dvs(tmp, v1, s1));
	}
	return ijkVecLerp3dv(v_out, v0, v1, u);
}

ijk_inl doublev ijkVecReflectScale3dv(double3 v_out, double3 const v_in, double3 const v_nrm)
{
	f64 const d = dbl_two * ijkVecDot3dv(v_in, v_nrm), lenSq = ijkVecLengthSq3dv(v_nrm);
	v_out[0] = v_in[0] * lenSq - d * v_nrm[0];
	v_out[1] = v_in[1] * lenSq - d * v_nrm[1];
	v_out[2] = v_in[2] * lenSq - d * v_nrm[2];
	return v_out;
}

ijk_inl doublev ijkVecUnitReflect3dv(double3 v_out, double3 const v_in, double3 const v_nrm)
{
	f64 const d = dbl_two * ijkVecDot3dv(v_in, v_nrm);
	v_out[0] = v_in[0] - d * v_nrm[0];
	v_out[1] = v_in[1] - d * v_nrm[1];
	v_out[2] = v_in[2] - d * v_nrm[2];
	return v_out;
}

ijk_inl doublev ijkVecReflect3dv(double3 v_out, double3 const v_in, double3 const v_nrm)
{
	f64 const d = dbl_two * ijkVecDot3dv(v_in, v_nrm), lenSqInv = d * ijkVecLengthSqInv3dv(v_nrm);
	v_out[0] = v_in[0] - lenSqInv * v_nrm[0];
	v_out[1] = v_in[1] - lenSqInv * v_nrm[1];
	v_out[2] = v_in[2] - lenSqInv * v_nrm[2];
	return v_out;
}

ijk_inl f64 ijkVecDistance3dv(double3 const v_lh, double3 const v_rh)
{
	double3 const diff = {
		(v_lh[0] - v_rh[0]),
		(v_lh[1] - v_rh[1]),
		(v_lh[2] - v_rh[2]),
	};
	return ijkVecLength3dv(diff);
}

ijk_inl doublev ijkVecResize3dv(double3 v_out, double3 const v_in, f64 const length)
{
	f64 const s = length * ijkVecLengthInv3dv(v_in);
	return ijkVecMul3dvs(v_out, v_in, s);
}

ijk_inl doublev ijkVecResizeSafe3dv(double3 v_out, double3 const v_in, f64 const length)
{
	f64 const s = length * ijkVecLengthInvSafe3dv(v_in);
	return ijkVecMul3dvs(v_out, v_in, s);
}

ijk_inl doublev ijkVecCrossResize3dv(double3 v_out, double3 const v_lh, double3 const v_rh, f64 const length)
{
	f64 const s = length * ijkVecLengthInv3dv(ijkVecCross3dv(v_out, v_lh, v_rh));
	return ijkVecMul3dvs(v_out, v_out, s);
}

ijk_inl doublev ijkVecCrossResizeSafe3dv(double3 v_out, double3 const v_lh, double3 const v_rh, f64 const length)
{
	f64 const s = length * ijkVecLengthInvSafe3dv(ijkVecCross3dv(v_out, v_lh, v_rh));
	return ijkVecMul3dvs(v_out, v_out, s);
}

ijk_inl doublev ijkVecNearest3dv(double3 v_out, double3 const v0, double3 const v1, f64 const u)
{
	return ijkVecCopy3dv(v_out, (u < dbl_half ? v0 : v1));
}

ijk_inl doublev ijkVecBinearest3dv(double3 v_out, double3 const v00, double3 const v01, double3 const v10, double3 const v11, f64 const u0, f64 const u1, f64 const u)
{
	return ijkVecCopy3dv(v_out, (u < dbl_half ? u0 < dbl_half ? v00 : v01 : u1 < dbl_half ? v10 : v11));
}

ijk_inl doublev ijkVecRemap3dv(double3 v_out, double3 const v0_dst, double3 const v1_dst, double3 const v0_src, double3 const v1_src, double3 const v_src)
{
	v_out[0] = ijkInterpRemap_dbl(v0_dst[0], v1_dst[0], v0_src[0], v1_src[0], v_src[0]);
	v_out[1] = ijkInterpRemap_dbl(v0_dst[1], v1_dst[1], v0_src[1], v1_src[1], v_src[1]);
	v_out[2] = ijkInterpRemap_dbl(v0_dst[2], v1_dst[2], v0_src[2], v1_src[2], v_src[2]);
	return v_out;
}

ijk_inl doublev ijkVecBezier0O3dv(double3 v_out, double3 const v0, f64 const u)
{
	return ijkVecCopy3dv(v_out, v0);
}

ijk_inl doublev ijkVecBezier1O3dv(double3 v_out, double3 const v0, double3 const v1, f64 const u)
{
	return ijkVecLerp3dv(v_out, v0, v1, u);
}

ijk_inl doublev ijkVecBezier2O3dv(double3 v_out, double3 const v0, double3 const v1, double3 const v2, f64 const u)
{
	double3 u0, u1;
	ijkVecBezier1O3dv(u0, v0, v1, u);
	ijkVecBezier1O3dv(u1, v1, v2, u);
	return ijkVecLerp3dv(v_out, u0, u1, u);
}

ijk_inl doublev ijkVecBezier3O3dv(double3 v_out, double3 const v0, double3 const v1, double3 const v2, double3 const v3, f64 const u)
{
	double3 u0, u1;
	ijkVecBezier2O3dv(u0, v0, v1, v2, u);
	ijkVecBezier2O3dv(u1, v1, v2, v3, u);
	return ijkVecLerp3dv(v_out, u0, u1, u);
}

ijk_inl doublev ijkVecBezierNO3dv(double3 v_out, double3 const v[], size const order, f64 const u)
{
	double3 u0, u1;
	if (order > 0)
		return ijkVecLerp3dv(v_out, ijkVecBezierNO3dv(u0, v + 0, order - 1, u), ijkVecBezierNO3dv(u1, v + 1, order - 1, u), u);
	return ijkVecCopy3dv(v_out, *v);
}

ijk_inl doublev ijkVecCubicHermite3dv(double3 v_out, double3 const v0, double3 const dv0, double3 const v1, double3 const dv1, f64 const u)
{
	f64 const u2 = u * u, u3 = u * u2;
	double4 const k = {
		(dbl_one - dbl_three * u2 + dbl_two * u3),
		(u - dbl_two * u2 + u3),
		(dbl_three * u2 - dbl_two * u3),
		(u3 - u2),
	};
	v_out[0] = (k[0] * v0[0] + k[1] * dv0[0] + k[2] * v1[0] + k[3] * dv1[0]);
	v_out[1] = (k[0] * v0[1] + k[1] * dv0[1] + k[2] * v1[1] + k[3] * dv1[1]);
	v_out[2] = (k[0] * v0[2] + k[1] * dv0[2] + k[2] * v1[2] + k[3] * dv1[2]);
	return v_out;
}

ijk_inl doublev ijkVecCubicHermiteHandles3dv(double3 v_out, double3 const v0, double3 const cv0, double3 const v1, double3 const cv1, f64 const u)
{
	f64 const u2 = u * u, u3 = u * u2;
	double4 const k = {
		(dbl_one - u - u2 + u3),
		(u - dbl_two * u2 + u3),
		(dbl_four * u2 - dbl_three * u3),
		(u3 - u2),
	};
	v_out[0] = (k[0] * v0[0] + k[1] * cv0[0] + k[2] * v1[0] + k[3] * cv1[0]);
	v_out[1] = (k[0] * v0[1] + k[1] * cv0[1] + k[2] * v1[1] + k[3] * cv1[1]);
	v_out[2] = (k[0] * v0[2] + k[1] * cv0[2] + k[2] * v1[2] + k[3] * cv1[2]);
	return v_out;
}

ijk_inl doublev ijkVecCubicCatmullRom3dv(double3 v_out, double3 const vp, double3 const v0, double3 const v1, double3 const v2, f64 const u)
{
	f64 const uh = dbl_half * u, u2h = u * uh, u3h = u * u2h;
	double4 const k = {
		(dbl_two * u2h - uh - u3h),
		(dbl_one - dbl_five * u2h + dbl_three * u3h),
		(uh + dbl_four * u2h - dbl_three * u3h),
		(u3h - u2h),
	};
	v_out[0] = (k[0] * vp[0] + k[1] * v0[0] + k[2] * v1[0] + k[3] * v2[0]);
	v_out[1] = (k[0] * vp[1] + k[1] * v0[1] + k[2] * v1[1] + k[3] * v2[1]);
	v_out[2] = (k[0] * vp[2] + k[1] * v0[2] + k[2] * v1[2] + k[3] * v2[2]);
	return v_out;
}

ijk_inl doublev ijkVecBicubicCatmullRom3dv(double3 v_out, double3 const vpp, double3 const vp0, double3 const vp1, double3 const vp2, double3 const v0p, double3 const v00, double3 const v01, double3 const v02, double3 const v1p, double3 const v10, double3 const v11, double3 const v12, double3 const v2p, double3 const v20, double3 const v21, double3 const v22, f64 const up, f64 const u0, f64 const u1, f64 const u2, f64 const u)
{
	double3 vp, v0, v1, v2;
	ijkVecCubicCatmullRom3dv(vp, vpp, vp0, vp1, vp2, up);
	ijkVecCubicCatmullRom3dv(v0, v0p, v00, v01, v02, u0);
	ijkVecCubicCatmullRom3dv(v1, v1p, v10, v11, v12, u1);
	ijkVecCubicCatmullRom3dv(v2, v2p, v20, v21, v22, u2);
	return ijkVecCubicCatmullRom3dv(v_out, vp, v0, v1, v2, u);
}

ijk_inl f64 ijkVecReparamCubicHermite3dv(f64 uTable_out[], f64 lTable_out[], double3 vTable_out[], size const numDivisions, ibool const lNormalize, double3 const v0, double3 const dv0, double3 const v1, double3 const dv1)
{
	f64 u = dbl_zero, du, arcLength = dbl_zero, arcLengthInv;
	f64* lTable = lTable_out;
	uindex i;
	doublekv v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		vc = ijkVecCopy3dv(*vTable_out, v0);

		for (i = 1, du = ijk_recip_dbl((f64)numDivisions); i <= numDivisions; ++i)
		{
			u = (f64)i * du;
			v = ijkVecCubicHermite3dv(*(++vTable_out), v0, dv0, v1, dv1, u);
			arcLength += ijkVecDistance3dv(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_dbl(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl f64 ijkVecReparamCubicHermiteHandles3dv(f64 uTable_out[], f64 lTable_out[], double3 vTable_out[], size const numDivisions, ibool const lNormalize, double3 const v0, double3 const cv0, double3 const v1, double3 const cv1)
{
	f64 u = dbl_zero, du, arcLength = dbl_zero, arcLengthInv;
	f64* lTable = lTable_out;
	uindex i;
	doublekv v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		vc = ijkVecCopy3dv(*vTable_out, v0);

		for (i = 1, du = ijk_recip_dbl((f64)numDivisions); i <= numDivisions; ++i)
		{
			u = (f64)i * du;
			v = ijkVecCubicHermiteHandles3dv(*(++vTable_out), v0, cv0, v1, cv1, u);
			arcLength += ijkVecDistance3dv(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_dbl(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl f64 ijkVecReparamCubicCatmullRom3dv(f64 uTable_out[], f64 lTable_out[], double3 vTable_out[], size const numDivisions, ibool const lNormalize, double3 const vp, double3 const v0, double3 const v1, double3 const v2)
{
	f64 u = dbl_zero, du, arcLength = dbl_zero, arcLengthInv;
	f64* lTable = lTable_out;
	uindex i;
	doublekv v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		vc = ijkVecCopy3dv(*vTable_out, v0);

		for (i = 1, du = ijk_recip_dbl((f64)numDivisions); i <= numDivisions; ++i)
		{
			u = (f64)i * du;
			v = ijkVecCubicCatmullRom3dv(*(++vTable_out), vp, v0, v1, v2, u);
			arcLength += ijkVecDistance3dv(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_dbl(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl f64 ijkVecReparamBicubicCatmullRom3dv(f64 uTable_out[], f64 lTable_out[], double3 vTable_out[], size const numDivisions, ibool const lNormalize, double3 const vpp, double3 const vp0, double3 const vp1, double3 const vp2, double3 const v0p, double3 const v00, double3 const v01, double3 const v02, double3 const v1p, double3 const v10, double3 const v11, double3 const v12, double3 const v2p, double3 const v20, double3 const v21, double3 const v22, f64 const up, f64 const u0, f64 const u1, f64 const u2)
{
	f64 u = dbl_zero, du, arcLength = dbl_zero, arcLengthInv;
	f64* lTable = lTable_out;
	uindex i;
	doublekv v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		double3 vp, v0, v1, v2;
		ijkVecCubicCatmullRom3dv(vp, vpp, vp0, vp1, vp2, up);
		ijkVecCubicCatmullRom3dv(v0, v0p, v00, v01, v02, u0);
		ijkVecCubicCatmullRom3dv(v1, v1p, v10, v11, v12, u1);
		ijkVecCubicCatmullRom3dv(v2, v2p, v20, v21, v22, u2);

		*uTable_out = u;
		*lTable_out = arcLength;
		vc = ijkVecCopy3dv(*vTable_out, v0);

		for (i = 1, du = ijk_recip_dbl((f64)numDivisions); i <= numDivisions; ++i)
		{
			u = (f64)i * du;
			v = ijkVecCubicCatmullRom3dv(*(++vTable_out), vp, v0, v1, v2, u);
			arcLength += ijkVecDistance3dv(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_dbl(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl doublev ijkVecSampleTableInc3dv(double3 v_out, f64 const uTable[], double3 const vTable[], index i, index di, f64 const u)
{
	doublekv v0, v1;
	f64 uReparam;
	f64 u0, u1 = *(uTable + (i += (di ? di : (di = 1))));

	while (u1 < u)
		u1 = *(uTable + (i += di));
	v1 = *(vTable + i);
	v0 = *(vTable + (i -= di));
	u0 = *(uTable + i);
	uReparam = ijkInterpLinearInv_dbl(u0, u1, u);
	return ijkVecLerp3dv(v_out, v0, v1, uReparam);
}

ijk_inl doublev ijkVecSampleTableDec3dv(double3 v_out, f64 const uTable[], double3 const vTable[], index i, index di, f64 const u)
{
	doublekv v0, v1;
	f64 uReparam;
	f64 u0, u1 = *(uTable + (i += (di ? di : (di = 1))));

	while (u1 > u)
		u1 = *(uTable + (i += di));
	v1 = *(vTable + i);
	v0 = *(vTable + (i -= di));
	u0 = *(uTable + i);
	uReparam = ijkInterpLinearInv_dbl(u0, u1, u);
	return ijkVecLerp3dv(v_out, v0, v1, uReparam);
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
	return (lengthSq > dbl_zero ? ijkSqrtInv_dbl(lengthSq) : dbl_zero);
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
	f64 const s = ijk_recip_dbl(dbl_one - u);
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

ijk_inl doublev ijkVecNlerp4dv(double4 v_out, double4 const v0, double4 const v1, f64 const u)
{
	ijkVecLerp4dv(v_out, v0, v1, u);
	return ijkVecNormalize4dv(v_out, v_out);
}

ijk_inl doublev ijkVecSlerp4dv(double4 v_out, double4 const v0, double4 const v1, f64 const u)
{
	f64 const dot = ijkVecDot4dv(v0, v1);
	if ((dot * dot) < dbl_one)
	{
		double4 tmp;
		f64 const angle = ijkTrigAcos_deg_dbl(dot),
			sinInv = ijkTrigCsc_deg_dbl(angle),
			s0 = sinInv * ijkTrigSin_deg_dbl(angle * (dbl_one - u)),
			s1 = sinInv * ijkTrigSin_deg_dbl(angle * u);
		return ijkVecAdd4dv(v_out, ijkVecMul4dvs(v_out, v0, s0), ijkVecMul4dvs(tmp, v1, s1));
	}
	return ijkVecLerp4dv(v_out, v0, v1, u);
}

ijk_inl doublev ijkVecReflectScale4dv(double4 v_out, double4 const v_in, double4 const v_nrm)
{
	f64 const d = dbl_two * ijkVecDot4dv(v_in, v_nrm), lenSq = ijkVecLengthSq4dv(v_nrm);
	v_out[0] = v_in[0] * lenSq - d * v_nrm[0];
	v_out[1] = v_in[1] * lenSq - d * v_nrm[1];
	v_out[2] = v_in[2] * lenSq - d * v_nrm[2];
	v_out[3] = v_in[3] * lenSq - d * v_nrm[3];
	return v_out;
}

ijk_inl doublev ijkVecUnitReflect4dv(double4 v_out, double4 const v_in, double4 const v_nrm)
{
	f64 const d = dbl_two * ijkVecDot4dv(v_in, v_nrm);
	v_out[0] = v_in[0] - d * v_nrm[0];
	v_out[1] = v_in[1] - d * v_nrm[1];
	v_out[2] = v_in[2] - d * v_nrm[2];
	v_out[3] = v_in[3] - d * v_nrm[3];
	return v_out;
}

ijk_inl doublev ijkVecReflect4dv(double4 v_out, double4 const v_in, double4 const v_nrm)
{
	f64 const d = dbl_two * ijkVecDot4dv(v_in, v_nrm), lenSqInv = d * ijkVecLengthSqInv4dv(v_nrm);
	v_out[0] = v_in[0] - lenSqInv * v_nrm[0];
	v_out[1] = v_in[1] - lenSqInv * v_nrm[1];
	v_out[2] = v_in[2] - lenSqInv * v_nrm[2];
	v_out[3] = v_in[3] - lenSqInv * v_nrm[3];
	return v_out;
}

ijk_inl f64 ijkVecDistance4dv(double4 const v_lh, double4 const v_rh)
{
	double4 const diff = {
		(v_lh[0] - v_rh[0]),
		(v_lh[1] - v_rh[1]),
		(v_lh[2] - v_rh[2]),
		(v_lh[3] - v_rh[3]),
	};
	return ijkVecLength4dv(diff);
}

ijk_inl doublev ijkVecResize4dv(double4 v_out, double4 const v_in, f64 const length)
{
	f64 const s = length * ijkVecLengthInv4dv(v_in);
	return ijkVecMul4dvs(v_out, v_in, s);
}

ijk_inl doublev ijkVecResizeSafe4dv(double4 v_out, double4 const v_in, f64 const length)
{
	f64 const s = length * ijkVecLengthInvSafe4dv(v_in);
	return ijkVecMul4dvs(v_out, v_in, s);
}

ijk_inl doublev ijkVecCrossResize4dv(double4 v_out, double4 const v_lh, double4 const v_rh, f64 const length)
{
	f64 const s = length * ijkVecLengthInv3dv(ijkVecCross4dv(v_out, v_lh, v_rh));
	return ijkVecMul3dvs(v_out, v_out, s);
}

ijk_inl doublev ijkVecCrossResizeSafe4dv(double4 v_out, double4 const v_lh, double4 const v_rh, f64 const length)
{
	f64 const s = length * ijkVecLengthInvSafe3dv(ijkVecCross4dv(v_out, v_lh, v_rh));
	return ijkVecMul3dvs(v_out, v_out, s);
}

ijk_inl doublev ijkVecNearest4dv(double4 v_out, double4 const v0, double4 const v1, f64 const u)
{
	return ijkVecCopy4dv(v_out, (u < dbl_half ? v0 : v1));
}

ijk_inl doublev ijkVecBinearest4dv(double4 v_out, double4 const v00, double4 const v01, double4 const v10, double4 const v11, f64 const u0, f64 const u1, f64 const u)
{
	return ijkVecCopy4dv(v_out, (u < dbl_half ? u0 < dbl_half ? v00 : v01 : u1 < dbl_half ? v10 : v11));
}

ijk_inl doublev ijkVecRemap4dv(double4 v_out, double4 const v0_dst, double4 const v1_dst, double4 const v0_src, double4 const v1_src, double4 const v_src)
{
	v_out[0] = ijkInterpRemap_dbl(v0_dst[0], v1_dst[0], v0_src[0], v1_src[0], v_src[0]);
	v_out[1] = ijkInterpRemap_dbl(v0_dst[1], v1_dst[1], v0_src[1], v1_src[1], v_src[1]);
	v_out[2] = ijkInterpRemap_dbl(v0_dst[2], v1_dst[2], v0_src[2], v1_src[2], v_src[2]);
	v_out[3] = ijkInterpRemap_dbl(v0_dst[3], v1_dst[3], v0_src[3], v1_src[3], v_src[3]);
	return v_out;
}

ijk_inl doublev ijkVecBezier0O4dv(double4 v_out, double4 const v0, f64 const u)
{
	return ijkVecCopy4dv(v_out, v0);
}

ijk_inl doublev ijkVecBezier1O4dv(double4 v_out, double4 const v0, double4 const v1, f64 const u)
{
	return ijkVecLerp4dv(v_out, v0, v1, u);
}

ijk_inl doublev ijkVecBezier2O4dv(double4 v_out, double4 const v0, double4 const v1, double4 const v2, f64 const u)
{
	double4 u0, u1;
	ijkVecBezier1O4dv(u0, v0, v1, u);
	ijkVecBezier1O4dv(u1, v1, v2, u);
	return ijkVecLerp4dv(v_out, u0, u1, u);
}

ijk_inl doublev ijkVecBezier3O4dv(double4 v_out, double4 const v0, double4 const v1, double4 const v2, double4 const v3, f64 const u)
{
	double4 u0, u1;
	ijkVecBezier2O4dv(u0, v0, v1, v2, u);
	ijkVecBezier2O4dv(u1, v1, v2, v3, u);
	return ijkVecLerp4dv(v_out, u0, u1, u);
}

ijk_inl doublev ijkVecBezierNO4dv(double4 v_out, double4 const v[], size const order, f64 const u)
{
	double4 u0, u1;
	if (order > 0)
		return ijkVecLerp4dv(v_out, ijkVecBezierNO4dv(u0, v + 0, order - 1, u), ijkVecBezierNO4dv(u1, v + 1, order - 1, u), u);
	return ijkVecCopy4dv(v_out, *v);
}

ijk_inl doublev ijkVecCubicHermite4dv(double4 v_out, double4 const v0, double4 const dv0, double4 const v1, double4 const dv1, f64 const u)
{
	f64 const u2 = u * u, u3 = u * u2;
	double4 const k = {
		(dbl_one - dbl_three * u2 + dbl_two * u3),
		(u - dbl_two * u2 + u3),
		(dbl_three * u2 - dbl_two * u3),
		(u3 - u2),
	};
	v_out[0] = (k[0] * v0[0] + k[1] * dv0[0] + k[2] * v1[0] + k[3] * dv1[0]);
	v_out[1] = (k[0] * v0[1] + k[1] * dv0[1] + k[2] * v1[1] + k[3] * dv1[1]);
	v_out[2] = (k[0] * v0[2] + k[1] * dv0[2] + k[2] * v1[2] + k[3] * dv1[2]);
	v_out[3] = (k[0] * v0[3] + k[1] * dv0[3] + k[2] * v1[3] + k[3] * dv1[3]);
	return v_out;
}

ijk_inl doublev ijkVecCubicHermiteHandles4dv(double4 v_out, double4 const v0, double4 const cv0, double4 const v1, double4 const cv1, f64 const u)
{
	f64 const u2 = u * u, u3 = u * u2;
	double4 const k = {
		(dbl_one - u - u2 + u3),
		(u - dbl_two * u2 + u3),
		(dbl_four * u2 - dbl_three * u3),
		(u3 - u2),
	};
	v_out[0] = (k[0] * v0[0] + k[1] * cv0[0] + k[2] * v1[0] + k[3] * cv1[0]);
	v_out[1] = (k[0] * v0[1] + k[1] * cv0[1] + k[2] * v1[1] + k[3] * cv1[1]);
	v_out[2] = (k[0] * v0[2] + k[1] * cv0[2] + k[2] * v1[2] + k[3] * cv1[2]);
	v_out[3] = (k[0] * v0[3] + k[1] * cv0[3] + k[2] * v1[3] + k[3] * cv1[3]);
	return v_out;
}

ijk_inl doublev ijkVecCubicCatmullRom4dv(double4 v_out, double4 const vp, double4 const v0, double4 const v1, double4 const v2, f64 const u)
{
	f64 const uh = dbl_half * u, u2h = u * uh, u3h = u * u2h;
	double4 const k = {
		(dbl_two * u2h - uh - u3h),
		(dbl_one - dbl_five * u2h + dbl_three * u3h),
		(uh + dbl_four * u2h - dbl_three * u3h),
		(u3h - u2h),
	};
	v_out[0] = (k[0] * vp[0] + k[1] * v0[0] + k[2] * v1[0] + k[3] * v2[0]);
	v_out[1] = (k[0] * vp[1] + k[1] * v0[1] + k[2] * v1[1] + k[3] * v2[1]);
	v_out[2] = (k[0] * vp[2] + k[1] * v0[2] + k[2] * v1[2] + k[3] * v2[2]);
	v_out[3] = (k[0] * vp[3] + k[1] * v0[3] + k[2] * v1[3] + k[3] * v2[3]);
	return v_out;
}

ijk_inl doublev ijkVecBicubicCatmullRom4dv(double4 v_out, double4 const vpp, double4 const vp0, double4 const vp1, double4 const vp2, double4 const v0p, double4 const v00, double4 const v01, double4 const v02, double4 const v1p, double4 const v10, double4 const v11, double4 const v12, double4 const v2p, double4 const v20, double4 const v21, double4 const v22, f64 const up, f64 const u0, f64 const u1, f64 const u2, f64 const u)
{
	double4 vp, v0, v1, v2;
	ijkVecCubicCatmullRom4dv(vp, vpp, vp0, vp1, vp2, up);
	ijkVecCubicCatmullRom4dv(v0, v0p, v00, v01, v02, u0);
	ijkVecCubicCatmullRom4dv(v1, v1p, v10, v11, v12, u1);
	ijkVecCubicCatmullRom4dv(v2, v2p, v20, v21, v22, u2);
	return ijkVecCubicCatmullRom4dv(v_out, vp, v0, v1, v2, u);
}

ijk_inl f64 ijkVecReparamCubicHermite4dv(f64 uTable_out[], f64 lTable_out[], double4 vTable_out[], size const numDivisions, ibool const lNormalize, double4 const v0, double4 const dv0, double4 const v1, double4 const dv1)
{
	f64 u = dbl_zero, du, arcLength = dbl_zero, arcLengthInv;
	f64* lTable = lTable_out;
	uindex i;
	doublekv v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		vc = ijkVecCopy4dv(*vTable_out, v0);

		for (i = 1, du = ijk_recip_dbl((f64)numDivisions); i <= numDivisions; ++i)
		{
			u = (f64)i * du;
			v = ijkVecCubicHermite4dv(*(++vTable_out), v0, dv0, v1, dv1, u);
			arcLength += ijkVecDistance4dv(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_dbl(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl f64 ijkVecReparamCubicHermiteHandles4dv(f64 uTable_out[], f64 lTable_out[], double4 vTable_out[], size const numDivisions, ibool const lNormalize, double4 const v0, double4 const cv0, double4 const v1, double4 const cv1)
{
	f64 u = dbl_zero, du, arcLength = dbl_zero, arcLengthInv;
	f64* lTable = lTable_out;
	uindex i;
	doublekv v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		vc = ijkVecCopy4dv(*vTable_out, v0);

		for (i = 1, du = ijk_recip_dbl((f64)numDivisions); i <= numDivisions; ++i)
		{
			u = (f64)i * du;
			v = ijkVecCubicHermiteHandles4dv(*(++vTable_out), v0, cv0, v1, cv1, u);
			arcLength += ijkVecDistance4dv(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_dbl(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl f64 ijkVecReparamCubicCatmullRom4dv(f64 uTable_out[], f64 lTable_out[], double4 vTable_out[], size const numDivisions, ibool const lNormalize, double4 const vp, double4 const v0, double4 const v1, double4 const v2)
{
	f64 u = dbl_zero, du, arcLength = dbl_zero, arcLengthInv;
	f64* lTable = lTable_out;
	uindex i;
	doublekv v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		vc = ijkVecCopy4dv(*vTable_out, v0);

		for (i = 1, du = ijk_recip_dbl((f64)numDivisions); i <= numDivisions; ++i)
		{
			u = (f64)i * du;
			v = ijkVecCubicCatmullRom4dv(*(++vTable_out), vp, v0, v1, v2, u);
			arcLength += ijkVecDistance4dv(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_dbl(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl f64 ijkVecReparamBicubicCatmullRom4dv(f64 uTable_out[], f64 lTable_out[], double4 vTable_out[], size const numDivisions, ibool const lNormalize, double4 const vpp, double4 const vp0, double4 const vp1, double4 const vp2, double4 const v0p, double4 const v00, double4 const v01, double4 const v02, double4 const v1p, double4 const v10, double4 const v11, double4 const v12, double4 const v2p, double4 const v20, double4 const v21, double4 const v22, f64 const up, f64 const u0, f64 const u1, f64 const u2)
{
	f64 u = dbl_zero, du, arcLength = dbl_zero, arcLengthInv;
	f64* lTable = lTable_out;
	uindex i;
	doublekv v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		double4 vp, v0, v1, v2;
		ijkVecCubicCatmullRom4dv(vp, vpp, vp0, vp1, vp2, up);
		ijkVecCubicCatmullRom4dv(v0, v0p, v00, v01, v02, u0);
		ijkVecCubicCatmullRom4dv(v1, v1p, v10, v11, v12, u1);
		ijkVecCubicCatmullRom4dv(v2, v2p, v20, v21, v22, u2);

		*uTable_out = u;
		*lTable_out = arcLength;
		vc = ijkVecCopy4dv(*vTable_out, v0);

		for (i = 1, du = ijk_recip_dbl((f64)numDivisions); i <= numDivisions; ++i)
		{
			u = (f64)i * du;
			v = ijkVecCubicCatmullRom4dv(*(++vTable_out), vp, v0, v1, v2, u);
			arcLength += ijkVecDistance4dv(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_dbl(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl doublev ijkVecSampleTableInc4dv(double4 v_out, f64 const uTable[], double4 const vTable[], index i, index di, f64 const u)
{
	doublekv v0, v1;
	f64 uReparam;
	f64 u0, u1 = *(uTable + (i += (di ? di : (di = 1))));

	while (u1 < u)
		u1 = *(uTable + (i += di));
	v1 = *(vTable + i);
	v0 = *(vTable + (i -= di));
	u0 = *(uTable + i);
	uReparam = ijkInterpLinearInv_dbl(u0, u1, u);
	return ijkVecLerp4dv(v_out, v0, v1, uReparam);
}

ijk_inl doublev ijkVecSampleTableDec4dv(double4 v_out, f64 const uTable[], double4 const vTable[], index i, index di, f64 const u)
{
	doublekv v0, v1;
	f64 uReparam;
	f64 u0, u1 = *(uTable + (i += (di ? di : (di = 1))));

	while (u1 > u)
		u1 = *(uTable + (i += di));
	v1 = *(vTable + i);
	v0 = *(vTable + (i -= di));
	u0 = *(uTable + i);
	uReparam = ijkInterpLinearInv_dbl(u0, u1, u);
	return ijkVecLerp4dv(v_out, v0, v1, uReparam);
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
	return (lengthSq > dbl_zero ? ijkSqrtInv_dbl(lengthSq) : dbl_zero);
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
	double const s = ijk_recip_dbl(dbl_one - u);
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

ijk_inl dvec2 ijkVecNlerp2d(dvec2 const v0, dvec2 const v1, double const u)
{
	return ijkVecNormalize2d(ijkVecLerp2d(v0, v1, u));
}

ijk_inl dvec2 ijkVecSlerp2d(dvec2 const v0, dvec2 const v1, double const u)
{
	double const dot = ijkVecDot2d(v0, v1);
	if ((dot * dot) < dbl_one)
	{
		double const angle = ijkTrigAcos_deg_dbl(dot),
			sinInv = ijkTrigCsc_deg_dbl(angle),
			s0 = sinInv * ijkTrigSin_deg_dbl(angle * (dbl_one - u)),
			s1 = sinInv * ijkTrigSin_deg_dbl(angle * u);
		return ijkVecAdd2d(ijkVecMul2ds(v0, s0), ijkVecMul2ds(v1, s1));
	}
	return ijkVecLerp2d(v0, v1, u);
}

ijk_inl dvec2 ijkVecReflectScale2d(dvec2 const v_in, dvec2 const v_nrm)
{
	double const d = dbl_two * ijkVecDot2d(v_in, v_nrm), lenSq = ijkVecLengthSq2d(v_nrm);
	dvec2 const v_out = {
		(v_in.x * lenSq - d * v_nrm.x),
		(v_in.y * lenSq - d * v_nrm.y),
	};
	return v_out;
}

ijk_inl dvec2 ijkVecUnitReflect2d(dvec2 const v_in, dvec2 const v_nrm)
{
	double const d = dbl_two * ijkVecDot2d(v_in, v_nrm);
	dvec2 const v_out = {
		(v_in.x - d * v_nrm.x),
		(v_in.y - d * v_nrm.y),
	};
	return v_out;
}

ijk_inl dvec2 ijkVecReflect2d(dvec2 const v_in, dvec2 const v_nrm)
{
	double const d = dbl_two * ijkVecDot2d(v_in, v_nrm), lenSqInv = d * ijkVecLengthSqInv2d(v_nrm);
	dvec2 const v_out = {
		(v_in.x - lenSqInv * v_nrm.x),
		(v_in.y - lenSqInv * v_nrm.y),
	};
	return v_out;
}

ijk_inl double ijkVecDistance2d(dvec2 const v_lh, dvec2 const v_rh)
{
	dvec2 const diff = {
		(v_lh.x - v_rh.x),
		(v_lh.y - v_rh.y),
	};
	return ijkVecLength2d(diff);
}

ijk_inl dvec2 ijkVecResize2d(dvec2 const v_in, double const length)
{
	double const s = length * ijkVecLengthInv2d(v_in);
	return ijkVecMul2ds(v_in, s);
}

ijk_inl dvec2 ijkVecResizeSafe2d(dvec2 const v_in, double const length)
{
	double const s = length * ijkVecLengthInvSafe2d(v_in);
	return ijkVecMul2ds(v_in, s);
}

ijk_inl double ijkVecCrossResize2d(dvec2 const v_lh, dvec2 const v_rh, double const length)
{
	return (length * ijkVecCrossNormalize2d(v_lh, v_rh));
}

ijk_inl double ijkVecCrossResizeSafe2d(dvec2 const v_lh, dvec2 const v_rh, double const length)
{
	return (length * ijkVecCrossNormalizeSafe2d(v_lh, v_rh));
}

ijk_inl dvec2 ijkVecNearest2d(dvec2 const v0, dvec2 const v1, double const u)
{
	return (u < dbl_half ? v0 : v1);
}

ijk_inl dvec2 ijkVecBinearest2d(dvec2 const v00, dvec2 const v01, dvec2 const v10, dvec2 const v11, double const u0, double const u1, double const u)
{
	return (u < dbl_half ? u0 < dbl_half ? v00 : v01 : u1 < dbl_half ? v10 : v11);
}

ijk_inl dvec2 ijkVecRemap2d(dvec2 const v0_dst, dvec2 const v1_dst, dvec2 const v0_src, dvec2 const v1_src, dvec2 const v_src)
{
	dvec2 const v_out = {
		ijkInterpRemap_dbl(v0_dst.x, v1_dst.x, v0_src.x, v1_src.x, v_src.x),
		ijkInterpRemap_dbl(v0_dst.y, v1_dst.y, v0_src.y, v1_src.y, v_src.y),
	};
	return v_out;
}

ijk_inl dvec2 ijkVecBezier0O2d(dvec2 const v0, double const u)
{
	return v0;
}

ijk_inl dvec2 ijkVecBezier1O2d(dvec2 const v0, dvec2 const v1, double const u)
{
	return ijkVecLerp2d(v0, v1, u);
}

ijk_inl dvec2 ijkVecBezier2O2d(dvec2 const v0, dvec2 const v1, dvec2 const v2, double const u)
{
	dvec2 const u0 = ijkVecBezier1O2d(v0, v1, u), u1 = ijkVecBezier1O2d(v1, v2, u);
	return ijkVecLerp2d(u0, u1, u);
}

ijk_inl dvec2 ijkVecBezier3O2d(dvec2 const v0, dvec2 const v1, dvec2 const v2, dvec2 const v3, double const u)
{
	dvec2 const u0 = ijkVecBezier2O2d(v0, v1, v2, u), u1 = ijkVecBezier2O2d(v1, v2, v3, u);
	return ijkVecLerp2d(u0, u1, u);
}

ijk_inl dvec2 ijkVecBezierNO2d(dvec2 const v[], size const order, double const u)
{
	if (order > 0)
	{
		dvec2 const u0 = ijkVecBezierNO2d(v + 0, order - 1, u), u1 = ijkVecBezierNO2d(v + 1, order - 1, u);
		return ijkVecLerp2d(u0, u1, u);
	}
	return *v;
}

ijk_inl dvec2 ijkVecCubicHermite2d(dvec2 const v0, dvec2 const dv0, dvec2 const v1, dvec2 const dv1, double const u)
{
	double const u2 = u * u, u3 = u * u2;
	dvec4 const k = {
		(dbl_one - dbl_three * u2 + dbl_two * u3),
		(u - dbl_two * u2 + u3),
		(dbl_three * u2 - dbl_two * u3),
		(u3 - u2),
	};
	dvec2 const v_out = {
		(k.x * v0.x + k.y * dv0.x + k.z * v1.x + k.w * dv1.x),
		(k.x * v0.y + k.y * dv0.y + k.z * v1.y + k.w * dv1.y),
	};
	return v_out;
}

ijk_inl dvec2 ijkVecCubicHermiteHandles2d(dvec2 const v0, dvec2 const cv0, dvec2 const v1, dvec2 const cv1, double const u)
{
	double const u2 = u * u, u3 = u * u2;
	dvec4 const k = {
		(dbl_one - u - u2 + u3),
		(u - dbl_two * u2 + u3),
		(dbl_four * u2 - dbl_three * u3),
		(u3 - u2),
	};
	dvec2 const v_out = {
		(k.x * v0.x + k.y * cv0.x + k.z * v1.x + k.w * cv1.x),
		(k.x * v0.y + k.y * cv0.y + k.z * v1.y + k.w * cv1.y),
	};
	return v_out;
}

ijk_inl dvec2 ijkVecCubicCatmullRom2d(dvec2 const vp, dvec2 const v0, dvec2 const v1, dvec2 const v2, double const u)
{
	double const uh = dbl_half * u, u2h = u * uh, u3h = u * u2h;
	dvec4 const k = {
		(dbl_two * u2h - uh - u3h),
		(dbl_one - dbl_five * u2h + dbl_three * u3h),
		(uh + dbl_four * u2h - dbl_three * u3h),
		(u3h - u2h),
	};
	dvec2 const v_out = {
		(k.x * vp.x + k.y * v0.x + k.z * v1.x + k.w * v2.x),
		(k.x * vp.y + k.y * v0.y + k.z * v1.y + k.w * v2.y),
	};
	return v_out;
}

ijk_inl dvec2 ijkVecBicubicCatmullRom2d(dvec2 const vpp, dvec2 const vp0, dvec2 const vp1, dvec2 const vp2, dvec2 const v0p, dvec2 const v00, dvec2 const v01, dvec2 const v02, dvec2 const v1p, dvec2 const v10, dvec2 const v11, dvec2 const v12, dvec2 const v2p, dvec2 const v20, dvec2 const v21, dvec2 const v22, double const up, double const u0, double const u1, double const u2, double const u)
{
	dvec2 const vp = ijkVecCubicCatmullRom2d(vpp, vp0, vp1, vp2, up), v0 = ijkVecCubicCatmullRom2d(v0p, v00, v01, v02, u0),
		v1 = ijkVecCubicCatmullRom2d(v1p, v10, v11, v12, u1), v2 = ijkVecCubicCatmullRom2d(v2p, v20, v21, v22, u2);
	return ijkVecCubicCatmullRom2d(vp, v0, v1, v2, u);
}

ijk_inl double ijkVecReparamCubicHermite2d(double uTable_out[], double lTable_out[], dvec2 vTable_out[], size const numDivisions, ibool const lNormalize, dvec2 const v0, dvec2 const dv0, dvec2 const v1, dvec2 const dv1)
{
	double u = dbl_zero, du, arcLength = dbl_zero, arcLengthInv;
	double* lTable = lTable_out;
	uindex i;
	dvec2 v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		*vTable_out = vc = v0;

		for (i = 1, du = ijk_recip_dbl((f64)numDivisions); i <= numDivisions; ++i)
		{
			u = (f64)i * du;
			v = ijkVecCubicHermite2d(v0, dv0, v1, dv1, u);
			arcLength += ijkVecDistance2d(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			*(++vTable_out) = vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_dbl(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl double ijkVecReparamCubicHermiteHandles2d(double uTable_out[], double lTable_out[], dvec2 vTable_out[], size const numDivisions, ibool const lNormalize, dvec2 const v0, dvec2 const cv0, dvec2 const v1, dvec2 const cv1)
{
	double u = dbl_zero, du, arcLength = dbl_zero, arcLengthInv;
	double* lTable = lTable_out;
	uindex i;
	dvec2 v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		*vTable_out = vc = v0;

		for (i = 1, du = ijk_recip_dbl((f64)numDivisions); i <= numDivisions; ++i)
		{
			u = (f64)i * du;
			v = ijkVecCubicHermiteHandles2d(v0, cv0, v1, cv1, u);
			arcLength += ijkVecDistance2d(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			*(++vTable_out) = vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_dbl(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl double ijkVecReparamCubicCatmullRom2d(double uTable_out[], double lTable_out[], dvec2 vTable_out[], size const numDivisions, ibool const lNormalize, dvec2 const vp, dvec2 const v0, dvec2 const v1, dvec2 const v2)
{
	double u = dbl_zero, du, arcLength = dbl_zero, arcLengthInv;
	double* lTable = lTable_out;
	uindex i;
	dvec2 v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		*vTable_out = vc = v0;

		for (i = 1, du = ijk_recip_dbl((f64)numDivisions); i <= numDivisions; ++i)
		{
			u = (f64)i * du;
			v = ijkVecCubicCatmullRom2d(vp, v0, v1, v2, u);
			arcLength += ijkVecDistance2d(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			*(++vTable_out) = vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_dbl(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl double ijkVecReparamBicubicCatmullRom2d(double uTable_out[], double lTable_out[], dvec2 vTable_out[], size const numDivisions, ibool const lNormalize, dvec2 const vpp, dvec2 const vp0, dvec2 const vp1, dvec2 const vp2, dvec2 const v0p, dvec2 const v00, dvec2 const v01, dvec2 const v02, dvec2 const v1p, dvec2 const v10, dvec2 const v11, dvec2 const v12, dvec2 const v2p, dvec2 const v20, dvec2 const v21, dvec2 const v22, double const up, double const u0, double const u1, double const u2)
{
	double u = dbl_zero, du, arcLength = dbl_zero, arcLengthInv;
	double* lTable = lTable_out;
	uindex i;
	dvec2 v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		dvec2 const vp = ijkVecCubicCatmullRom2d(vpp, vp0, vp1, vp2, up), v0 = ijkVecCubicCatmullRom2d(v0p, v00, v01, v02, u0),
			v1 = ijkVecCubicCatmullRom2d(v1p, v10, v11, v12, u1), v2 = ijkVecCubicCatmullRom2d(v2p, v20, v21, v22, u2);

		*uTable_out = u;
		*lTable_out = arcLength;
		*vTable_out = vc = v0;

		for (i = 1, du = ijk_recip_dbl((f64)numDivisions); i <= numDivisions; ++i)
		{
			u = (f64)i * du;
			v = ijkVecCubicCatmullRom2d(vp, v0, v1, v2, u);
			arcLength += ijkVecDistance2d(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			*(++vTable_out) = vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_dbl(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl dvec2 ijkVecSampleTableInc2d(double const uTable[], dvec2 const vTable[], index i, index di, double const u)
{
	dvec2 v0, v1;
	double uReparam;
	double u0, u1 = *(uTable + (i += (di ? di : (di = 1))));

	while (u1 < u)
		u1 = *(uTable + (i += di));
	v1 = *(vTable + i);
	v0 = *(vTable + (i -= di));
	u0 = *(uTable + i);
	uReparam = ijkInterpLinearInv_dbl(u0, u1, u);
	return ijkVecLerp2d(v0, v1, uReparam);
}

ijk_inl dvec2 ijkVecSampleTableDec2d(double const uTable[], dvec2 const vTable[], index i, index di, double const u)
{
	dvec2 v0, v1;
	double uReparam;
	double u0, u1 = *(uTable + (i += (di ? di : (di = 1))));

	while (u1 > u)
		u1 = *(uTable + (i += di));
	v1 = *(vTable + i);
	v0 = *(vTable + (i -= di));
	u0 = *(uTable + i);
	uReparam = ijkInterpLinearInv_dbl(u0, u1, u);
	return ijkVecLerp2d(v0, v1, uReparam);
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
	return (lengthSq > dbl_zero ? ijkSqrtInv_dbl(lengthSq) : dbl_zero);
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
	double const s = ijk_recip_dbl(dbl_one - u);
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

ijk_inl dvec3 ijkVecNlerp3d(dvec3 const v0, dvec3 const v1, double const u)
{
	return ijkVecNormalize3d(ijkVecLerp3d(v0, v1, u));
}

ijk_inl dvec3 ijkVecSlerp3d(dvec3 const v0, dvec3 const v1, double const u)
{
	double const dot = ijkVecDot3d(v0, v1);
	if ((dot * dot) < dbl_one)
	{
		double const angle = ijkTrigAcos_deg_dbl(dot),
			sinInv = ijkTrigCsc_deg_dbl(angle),
			s0 = sinInv * ijkTrigSin_deg_dbl(angle * (dbl_one - u)),
			s1 = sinInv * ijkTrigSin_deg_dbl(angle * u);
		return ijkVecAdd3d(ijkVecMul3ds(v0, s0), ijkVecMul3ds(v1, s1));
	}
	return ijkVecLerp3d(v0, v1, u);
}

ijk_inl dvec3 ijkVecReflectScale3d(dvec3 const v_in, dvec3 const v_nrm)
{
	double const d = dbl_two * ijkVecDot3d(v_in, v_nrm), lenSq = ijkVecLengthSq3d(v_nrm);
	dvec3 const v_out = {
		(v_in.x * lenSq - d * v_nrm.x),
		(v_in.y * lenSq - d * v_nrm.y),
		(v_in.z * lenSq - d * v_nrm.z),
	};
	return v_out;
}

ijk_inl dvec3 ijkVecUnitReflect3d(dvec3 const v_in, dvec3 const v_nrm)
{
	double const d = dbl_two * ijkVecDot3d(v_in, v_nrm);
	dvec3 const v_out = {
		(v_in.x - d * v_nrm.x),
		(v_in.y - d * v_nrm.y),
		(v_in.z - d * v_nrm.z),
	};
	return v_out;
}

ijk_inl dvec3 ijkVecReflect3d(dvec3 const v_in, dvec3 const v_nrm)
{
	double const d = dbl_two * ijkVecDot3d(v_in, v_nrm), lenSqInv = d * ijkVecLengthSqInv3d(v_nrm);
	dvec3 const v_out = {
		(v_in.x - lenSqInv * v_nrm.x),
		(v_in.y - lenSqInv * v_nrm.y),
		(v_in.z - lenSqInv * v_nrm.z),
	};
	return v_out;
}

ijk_inl double ijkVecDistance3d(dvec3 const v_lh, dvec3 const v_rh)
{
	dvec3 const diff = {
		(v_lh.x - v_rh.x),
		(v_lh.y - v_rh.y),
		(v_lh.z - v_rh.z),
	};
	return ijkVecLength3d(diff);
}

ijk_inl dvec3 ijkVecResize3d(dvec3 const v_in, double const length)
{
	double const s = length * ijkVecLengthInv3d(v_in);
	return ijkVecMul3ds(v_in, s);
}

ijk_inl dvec3 ijkVecResizeSafe3d(dvec3 const v_in, double const length)
{
	double const s = length * ijkVecLengthInvSafe3d(v_in);
	return ijkVecMul3ds(v_in, s);
}

ijk_inl dvec3 ijkVecCrossResize3d(dvec3 const v_lh, dvec3 const v_rh, double const length)
{
	dvec3 const c = ijkVecCrossNormalize3d(v_lh, v_rh);
	double const s = length * ijkVecLengthInv3d(c);
	return ijkVecMul3ds(c, s);
}

ijk_inl dvec3 ijkVecCrossResizeSafe3d(dvec3 const v_lh, dvec3 const v_rh, double const length)
{
	dvec3 const c = ijkVecCrossNormalize3d(v_lh, v_rh);
	double const s = length * ijkVecLengthInvSafe3d(c);
	return ijkVecMul3ds(c, s);
}

ijk_inl dvec3 ijkVecNearest3d(dvec3 const v0, dvec3 const v1, double const u)
{
	return (u < dbl_half ? v0 : v1);
}

ijk_inl dvec3 ijkVecBinearest3d(dvec3 const v00, dvec3 const v01, dvec3 const v10, dvec3 const v11, double const u0, double const u1, double const u)
{
	return (u < dbl_half ? u0 < dbl_half ? v00 : v01 : u1 < dbl_half ? v10 : v11);
}

ijk_inl dvec3 ijkVecRemap3d(dvec3 const v0_dst, dvec3 const v1_dst, dvec3 const v0_src, dvec3 const v1_src, dvec3 const v_src)
{
	dvec3 const v_out = {
		ijkInterpRemap_dbl(v0_dst.x, v1_dst.x, v0_src.x, v1_src.x, v_src.x),
		ijkInterpRemap_dbl(v0_dst.y, v1_dst.y, v0_src.y, v1_src.y, v_src.y),
		ijkInterpRemap_dbl(v0_dst.z, v1_dst.z, v0_src.z, v1_src.z, v_src.z),
	};
	return v_out;
}

ijk_inl dvec3 ijkVecBezier0O3d(dvec3 const v0, double const u)
{
	return v0;
}

ijk_inl dvec3 ijkVecBezier1O3d(dvec3 const v0, dvec3 const v1, double const u)
{
	return ijkVecLerp3d(v0, v1, u);
}

ijk_inl dvec3 ijkVecBezier2O3d(dvec3 const v0, dvec3 const v1, dvec3 const v2, double const u)
{
	dvec3 const u0 = ijkVecBezier1O3d(v0, v1, u), u1 = ijkVecBezier1O3d(v1, v2, u);
	return ijkVecLerp3d(u0, u1, u);
}

ijk_inl dvec3 ijkVecBezier3O3d(dvec3 const v0, dvec3 const v1, dvec3 const v2, dvec3 const v3, double const u)
{
	dvec3 const u0 = ijkVecBezier2O3d(v0, v1, v2, u), u1 = ijkVecBezier2O3d(v1, v2, v3, u);
	return ijkVecLerp3d(u0, u1, u);
}

ijk_inl dvec3 ijkVecBezierNO3d(dvec3 const v[], size const order, double const u)
{
	if (order > 0)
	{
		dvec3 const u0 = ijkVecBezierNO3d(v + 0, order - 1, u), u1 = ijkVecBezierNO3d(v + 1, order - 1, u);
		return ijkVecLerp3d(u0, u1, u);
	}
	return *v;
}

ijk_inl dvec3 ijkVecCubicHermite3d(dvec3 const v0, dvec3 const dv0, dvec3 const v1, dvec3 const dv1, double const u)
{
	double const u2 = u * u, u3 = u * u2;
	dvec4 const k = {
		(dbl_one - dbl_three * u2 + dbl_two * u3),
		(u - dbl_two * u2 + u3),
		(dbl_three * u2 - dbl_two * u3),
		(u3 - u2),
	};
	dvec3 const v_out = {
		(k.x * v0.x + k.y * dv0.x + k.z * v1.x + k.w * dv1.x),
		(k.x * v0.y + k.y * dv0.y + k.z * v1.y + k.w * dv1.y),
		(k.x * v0.z + k.y * dv0.z + k.z * v1.z + k.w * dv1.z),
	};
	return v_out;
}

ijk_inl dvec3 ijkVecCubicHermiteHandles3d(dvec3 const v0, dvec3 const cv0, dvec3 const v1, dvec3 const cv1, double const u)
{
	double const u2 = u * u, u3 = u * u2;
	dvec4 const k = {
		(dbl_one - u - u2 + u3),
		(u - dbl_two * u2 + u3),
		(dbl_four * u2 - dbl_three * u3),
		(u3 - u2),
	};
	dvec3 const v_out = {
		(k.x * v0.x + k.y * cv0.x + k.z * v1.x + k.w * cv1.x),
		(k.x * v0.y + k.y * cv0.y + k.z * v1.y + k.w * cv1.y),
		(k.x * v0.z + k.y * cv0.z + k.z * v1.z + k.w * cv1.z),
	};
	return v_out;
}

ijk_inl dvec3 ijkVecCubicCatmullRom3d(dvec3 const vp, dvec3 const v0, dvec3 const v1, dvec3 const v2, double const u)
{
	double const uh = dbl_half * u, u2h = u * uh, u3h = u * u2h;
	dvec4 const k = {
		(dbl_two * u2h - uh - u3h),
		(dbl_one - dbl_five * u2h + dbl_three * u3h),
		(uh + dbl_four * u2h - dbl_three * u3h),
		(u3h - u2h),
	};
	dvec3 const v_out = {
		(k.x * vp.x + k.y * v0.x + k.z * v1.x + k.w * v2.x),
		(k.x * vp.y + k.y * v0.y + k.z * v1.y + k.w * v2.y),
		(k.x * vp.z + k.y * v0.z + k.z * v1.z + k.w * v2.z),
	};
	return v_out;
}

ijk_inl dvec3 ijkVecBicubicCatmullRom3d(dvec3 const vpp, dvec3 const vp0, dvec3 const vp1, dvec3 const vp2, dvec3 const v0p, dvec3 const v00, dvec3 const v01, dvec3 const v02, dvec3 const v1p, dvec3 const v10, dvec3 const v11, dvec3 const v12, dvec3 const v2p, dvec3 const v20, dvec3 const v21, dvec3 const v22, double const up, double const u0, double const u1, double const u2, double const u)
{
	dvec3 const vp = ijkVecCubicCatmullRom3d(vpp, vp0, vp1, vp2, up), v0 = ijkVecCubicCatmullRom3d(v0p, v00, v01, v02, u0),
		v1 = ijkVecCubicCatmullRom3d(v1p, v10, v11, v12, u1), v2 = ijkVecCubicCatmullRom3d(v2p, v20, v21, v22, u2);
	return ijkVecCubicCatmullRom3d(vp, v0, v1, v2, u);
}

ijk_inl double ijkVecReparamCubicHermite3d(double uTable_out[], double lTable_out[], dvec3 vTable_out[], size const numDivisions, ibool const lNormalize, dvec3 const v0, dvec3 const dv0, dvec3 const v1, dvec3 const dv1)
{
	double u = dbl_zero, du, arcLength = dbl_zero, arcLengthInv;
	double* lTable = lTable_out;
	uindex i;
	dvec3 v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		*vTable_out = vc = v0;

		for (i = 1, du = ijk_recip_dbl((f64)numDivisions); i <= numDivisions; ++i)
		{
			u = (f64)i * du;
			v = ijkVecCubicHermite3d(v0, dv0, v1, dv1, u);
			arcLength += ijkVecDistance3d(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			*(++vTable_out) = vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_dbl(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl double ijkVecReparamCubicHermiteHandles3d(double uTable_out[], double lTable_out[], dvec3 vTable_out[], size const numDivisions, ibool const lNormalize, dvec3 const v0, dvec3 const cv0, dvec3 const v1, dvec3 const cv1)
{
	double u = dbl_zero, du, arcLength = dbl_zero, arcLengthInv;
	double* lTable = lTable_out;
	uindex i;
	dvec3 v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		*vTable_out = vc = v0;

		for (i = 1, du = ijk_recip_dbl((f64)numDivisions); i <= numDivisions; ++i)
		{
			u = (f64)i * du;
			v = ijkVecCubicHermiteHandles3d(v0, cv0, v1, cv1, u);
			arcLength += ijkVecDistance3d(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			*(++vTable_out) = vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_dbl(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl double ijkVecReparamCubicCatmullRom3d(double uTable_out[], double lTable_out[], dvec3 vTable_out[], size const numDivisions, ibool const lNormalize, dvec3 const vp, dvec3 const v0, dvec3 const v1, dvec3 const v2)
{
	double u = dbl_zero, du, arcLength = dbl_zero, arcLengthInv;
	double* lTable = lTable_out;
	uindex i;
	dvec3 v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		*vTable_out = vc = v0;

		for (i = 1, du = ijk_recip_dbl((f64)numDivisions); i <= numDivisions; ++i)
		{
			u = (f64)i * du;
			v = ijkVecCubicCatmullRom3d(vp, v0, v1, v2, u);
			arcLength += ijkVecDistance3d(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			*(++vTable_out) = vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_dbl(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl double ijkVecReparamBicubicCatmullRom3d(double uTable_out[], double lTable_out[], dvec3 vTable_out[], size const numDivisions, ibool const lNormalize, dvec3 const vpp, dvec3 const vp0, dvec3 const vp1, dvec3 const vp2, dvec3 const v0p, dvec3 const v00, dvec3 const v01, dvec3 const v02, dvec3 const v1p, dvec3 const v10, dvec3 const v11, dvec3 const v12, dvec3 const v2p, dvec3 const v20, dvec3 const v21, dvec3 const v22, double const up, double const u0, double const u1, double const u2)
{
	double u = dbl_zero, du, arcLength = dbl_zero, arcLengthInv;
	double* lTable = lTable_out;
	uindex i;
	dvec3 v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		dvec3 const vp = ijkVecCubicCatmullRom3d(vpp, vp0, vp1, vp2, up), v0 = ijkVecCubicCatmullRom3d(v0p, v00, v01, v02, u0),
			v1 = ijkVecCubicCatmullRom3d(v1p, v10, v11, v12, u1), v2 = ijkVecCubicCatmullRom3d(v2p, v20, v21, v22, u2);

		*uTable_out = u;
		*lTable_out = arcLength;
		*vTable_out = vc = v0;

		for (i = 1, du = ijk_recip_dbl((f64)numDivisions); i <= numDivisions; ++i)
		{
			u = (f64)i * du;
			v = ijkVecCubicCatmullRom3d(vp, v0, v1, v2, u);
			arcLength += ijkVecDistance3d(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			*(++vTable_out) = vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_dbl(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl dvec3 ijkVecSampleTableInc3d(double const uTable[], dvec3 const vTable[], index i, index di, double const u)
{
	dvec3 v0, v1;
	double uReparam;
	double u0, u1 = *(uTable + (i += (di ? di : (di = 1))));

	while (u1 < u)
		u1 = *(uTable + (i += di));
	v1 = *(vTable + i);
	v0 = *(vTable + (i -= di));
	u0 = *(uTable + i);
	uReparam = ijkInterpLinearInv_dbl(u0, u1, u);
	return ijkVecLerp3d(v0, v1, uReparam);
}

ijk_inl dvec3 ijkVecSampleTableDec3d(double const uTable[], dvec3 const vTable[], index i, index di, double const u)
{
	dvec3 v0, v1;
	double uReparam;
	double u0, u1 = *(uTable + (i += (di ? di : (di = 1))));

	while (u1 > u)
		u1 = *(uTable + (i += di));
	v1 = *(vTable + i);
	v0 = *(vTable + (i -= di));
	u0 = *(uTable + i);
	uReparam = ijkInterpLinearInv_dbl(u0, u1, u);
	return ijkVecLerp3d(v0, v1, uReparam);
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
	return (lengthSq > dbl_zero ? ijkSqrtInv_dbl(lengthSq) : dbl_zero);
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
	double const s = ijk_recip_dbl(dbl_one - u);
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

ijk_inl dvec4 ijkVecNlerp4d(dvec4 const v0, dvec4 const v1, double const u)
{
	return ijkVecNormalize4d(ijkVecLerp4d(v0, v1, u));
}

ijk_inl dvec4 ijkVecSlerp4d(dvec4 const v0, dvec4 const v1, double const u)
{
	double const dot = ijkVecDot4d(v0, v1);
	if ((dot * dot) < dbl_one)
	{
		double const angle = ijkTrigAcos_deg_dbl(dot),
			sinInv = ijkTrigCsc_deg_dbl(angle),
			s0 = sinInv * ijkTrigSin_deg_dbl(angle * (dbl_one - u)),
			s1 = sinInv * ijkTrigSin_deg_dbl(angle * u);
		return ijkVecAdd4d(ijkVecMul4ds(v0, s0), ijkVecMul4ds(v1, s1));
	}
	return ijkVecLerp4d(v0, v1, u);
}

ijk_inl dvec4 ijkVecReflectScale4d(dvec4 const v_in, dvec4 const v_nrm)
{
	double const d = dbl_two * ijkVecDot4d(v_in, v_nrm), lenSq = ijkVecLengthSq4d(v_nrm);
	dvec4 const v_out = {
		(v_in.x * lenSq - d * v_nrm.x),
		(v_in.y * lenSq - d * v_nrm.y),
		(v_in.z * lenSq - d * v_nrm.z),
		(v_in.w * lenSq - d * v_nrm.w),
	};
	return v_out;
}

ijk_inl dvec4 ijkVecUnitReflect4d(dvec4 const v_in, dvec4 const v_nrm)
{
	double const d = dbl_two * ijkVecDot4d(v_in, v_nrm);
	dvec4 const v_out = {
		(v_in.x - d * v_nrm.x),
		(v_in.y - d * v_nrm.y),
		(v_in.z - d * v_nrm.z),
		(v_in.w - d * v_nrm.w),
	};
	return v_out;
}

ijk_inl dvec4 ijkVecReflect4d(dvec4 const v_in, dvec4 const v_nrm)
{
	double const d = dbl_two * ijkVecDot4d(v_in, v_nrm), lenSqInv = d * ijkVecLengthSqInv4d(v_nrm);
	dvec4 const v_out = {
		(v_in.x - lenSqInv * v_nrm.x),
		(v_in.y - lenSqInv * v_nrm.y),
		(v_in.z - lenSqInv * v_nrm.z),
		(v_in.w - lenSqInv * v_nrm.w),
	};
	return v_out;
}

ijk_inl double ijkVecDistance4d(dvec4 const v_lh, dvec4 const v_rh)
{
	dvec4 const diff = {
		(v_lh.x - v_rh.x),
		(v_lh.y - v_rh.y),
		(v_lh.z - v_rh.z),
		(v_lh.w - v_rh.w),
	};
	return ijkVecLength4d(diff);
}

ijk_inl dvec4 ijkVecResize4d(dvec4 const v_in, double const length)
{
	double const s = length * ijkVecLengthInv4d(v_in);
	return ijkVecMul4ds(v_in, s);
}

ijk_inl dvec4 ijkVecResizeSafe4d(dvec4 const v_in, double const length)
{
	double const s = length * ijkVecLengthInvSafe4d(v_in);
	return ijkVecMul4ds(v_in, s);
}

ijk_inl dvec4 ijkVecCrossResize4d(dvec4 const v_lh, dvec4 const v_rh, double const length)
{
	dvec4 const c = ijkVecCrossNormalize4d(v_lh, v_rh);
	double const s = length * ijkVecLengthInv3d(c.xyz);
	return ijkVecMul4ds(c, s);
}

ijk_inl dvec4 ijkVecCrossResizeSafe4d(dvec4 const v_lh, dvec4 const v_rh, double const length)
{
	dvec4 const c = ijkVecCrossNormalize4d(v_lh, v_rh);
	double const s = length * ijkVecLengthInvSafe3d(c.xyz);
	return ijkVecMul4ds(c, s);
}

ijk_inl dvec4 ijkVecNearest4d(dvec4 const v0, dvec4 const v1, double const u)
{
	return (u < dbl_half ? v0 : v1);
}

ijk_inl dvec4 ijkVecBinearest4d(dvec4 const v00, dvec4 const v01, dvec4 const v10, dvec4 const v11, double const u0, double const u1, double const u)
{
	return (u < dbl_half ? u0 < dbl_half ? v00 : v01 : u1 < dbl_half ? v10 : v11);
}

ijk_inl dvec4 ijkVecRemap4d(dvec4 const v0_dst, dvec4 const v1_dst, dvec4 const v0_src, dvec4 const v1_src, dvec4 const v_src)
{
	dvec4 const v_out = {
		ijkInterpRemap_dbl(v0_dst.x, v1_dst.x, v0_src.x, v1_src.x, v_src.x),
		ijkInterpRemap_dbl(v0_dst.y, v1_dst.y, v0_src.y, v1_src.y, v_src.y),
		ijkInterpRemap_dbl(v0_dst.z, v1_dst.z, v0_src.z, v1_src.z, v_src.z),
		ijkInterpRemap_dbl(v0_dst.w, v1_dst.w, v0_src.w, v1_src.w, v_src.w),
	};
	return v_out;
}

ijk_inl dvec4 ijkVecBezier0O4d(dvec4 const v0, double const u)
{
	return v0;
}

ijk_inl dvec4 ijkVecBezier1O4d(dvec4 const v0, dvec4 const v1, double const u)
{
	return ijkVecLerp4d(v0, v1, u);
}

ijk_inl dvec4 ijkVecBezier2O4d(dvec4 const v0, dvec4 const v1, dvec4 const v2, double const u)
{
	dvec4 const u0 = ijkVecBezier1O4d(v0, v1, u), u1 = ijkVecBezier1O4d(v1, v2, u);
	return ijkVecLerp4d(u0, u1, u);
}

ijk_inl dvec4 ijkVecBezier3O4d(dvec4 const v0, dvec4 const v1, dvec4 const v2, dvec4 const v3, double const u)
{
	dvec4 const u0 = ijkVecBezier2O4d(v0, v1, v2, u), u1 = ijkVecBezier2O4d(v1, v2, v3, u);
	return ijkVecLerp4d(u0, u1, u);
}

ijk_inl dvec4 ijkVecBezierNO4d(dvec4 const v[], size const order, double const u)
{
	if (order > 0)
	{
		dvec4 const u0 = ijkVecBezierNO4d(v + 0, order - 1, u), u1 = ijkVecBezierNO4d(v + 1, order - 1, u);
		return ijkVecLerp4d(u0, u1, u);
	}
	return *v;
}

ijk_inl dvec4 ijkVecCubicHermite4d(dvec4 const v0, dvec4 const dv0, dvec4 const v1, dvec4 const dv1, double const u)
{
	double const u2 = u * u, u3 = u * u2;
	dvec4 const k = {
		(dbl_one - dbl_three * u2 + dbl_two * u3),
		(u - dbl_two * u2 + u3),
		(dbl_three * u2 - dbl_two * u3),
		(u3 - u2),
	};
	dvec4 const v_out = {
		(k.x * v0.x + k.y * dv0.x + k.z * v1.x + k.w * dv1.x),
		(k.x * v0.y + k.y * dv0.y + k.z * v1.y + k.w * dv1.y),
		(k.x * v0.z + k.y * dv0.z + k.z * v1.z + k.w * dv1.z),
		(k.x * v0.w + k.y * dv0.w + k.z * v1.w + k.w * dv1.w),
	};
	return v_out;
}

ijk_inl dvec4 ijkVecCubicHermiteHandles4d(dvec4 const v0, dvec4 const cv0, dvec4 const v1, dvec4 const cv1, double const u)
{
	double const u2 = u * u, u3 = u * u2;
	dvec4 const k = {
		(dbl_one - u - u2 + u3),
		(u - dbl_two * u2 + u3),
		(dbl_four * u2 - dbl_three * u3),
		(u3 - u2),
	};
	dvec4 const v_out = {
		(k.x * v0.x + k.y * cv0.x + k.z * v1.x + k.w * cv1.x),
		(k.x * v0.y + k.y * cv0.y + k.z * v1.y + k.w * cv1.y),
		(k.x * v0.z + k.y * cv0.z + k.z * v1.z + k.w * cv1.z),
		(k.x * v0.w + k.y * cv0.w + k.z * v1.w + k.w * cv1.w),
	};
	return v_out;
}

ijk_inl dvec4 ijkVecCubicCatmullRom4d(dvec4 const vp, dvec4 const v0, dvec4 const v1, dvec4 const v2, double const u)
{
	double const uh = dbl_half * u, u2h = u * uh, u3h = u * u2h;
	dvec4 const k = {
		(dbl_two * u2h - uh - u3h),
		(dbl_one - dbl_five * u2h + dbl_three * u3h),
		(uh + dbl_four * u2h - dbl_three * u3h),
		(u3h - u2h),
	};
	dvec4 const v_out = {
		(k.x * vp.x + k.y * v0.x + k.z * v1.x + k.w * v2.x),
		(k.x * vp.y + k.y * v0.y + k.z * v1.y + k.w * v2.y),
		(k.x * vp.z + k.y * v0.z + k.z * v1.z + k.w * v2.z),
		(k.x * vp.w + k.y * v0.w + k.z * v1.w + k.w * v2.w),
	};
	return v_out;
}

ijk_inl dvec4 ijkVecBicubicCatmullRom4d(dvec4 const vpp, dvec4 const vp0, dvec4 const vp1, dvec4 const vp2, dvec4 const v0p, dvec4 const v00, dvec4 const v01, dvec4 const v02, dvec4 const v1p, dvec4 const v10, dvec4 const v11, dvec4 const v12, dvec4 const v2p, dvec4 const v20, dvec4 const v21, dvec4 const v22, double const up, double const u0, double const u1, double const u2, double const u)
{
	dvec4 const vp = ijkVecCubicCatmullRom4d(vpp, vp0, vp1, vp2, up), v0 = ijkVecCubicCatmullRom4d(v0p, v00, v01, v02, u0),
		v1 = ijkVecCubicCatmullRom4d(v1p, v10, v11, v12, u1), v2 = ijkVecCubicCatmullRom4d(v2p, v20, v21, v22, u2);
	return ijkVecCubicCatmullRom4d(vp, v0, v1, v2, u);
}

ijk_inl double ijkVecReparamCubicHermite4d(double uTable_out[], double lTable_out[], dvec4 vTable_out[], size const numDivisions, ibool const lNormalize, dvec4 const v0, dvec4 const dv0, dvec4 const v1, dvec4 const dv1)
{
	double u = dbl_zero, du, arcLength = dbl_zero, arcLengthInv;
	double* lTable = lTable_out;
	uindex i;
	dvec4 v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		*vTable_out = vc = v0;

		for (i = 1, du = ijk_recip_dbl((f64)numDivisions); i <= numDivisions; ++i)
		{
			u = (f64)i * du;
			v = ijkVecCubicHermite4d(v0, dv0, v1, dv1, u);
			arcLength += ijkVecDistance4d(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			*(++vTable_out) = vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_dbl(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl double ijkVecReparamCubicHermiteHandles4d(double uTable_out[], double lTable_out[], dvec4 vTable_out[], size const numDivisions, ibool const lNormalize, dvec4 const v0, dvec4 const cv0, dvec4 const v1, dvec4 const cv1)
{
	double u = dbl_zero, du, arcLength = dbl_zero, arcLengthInv;
	double* lTable = lTable_out;
	uindex i;
	dvec4 v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		*vTable_out = vc = v0;

		for (i = 1, du = ijk_recip_dbl((f64)numDivisions); i <= numDivisions; ++i)
		{
			u = (f64)i * du;
			v = ijkVecCubicHermiteHandles4d(v0, cv0, v1, cv1, u);
			arcLength += ijkVecDistance4d(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			*(++vTable_out) = vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_dbl(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl double ijkVecReparamCubicCatmullRom4d(double uTable_out[], double lTable_out[], dvec4 vTable_out[], size const numDivisions, ibool const lNormalize, dvec4 const vp, dvec4 const v0, dvec4 const v1, dvec4 const v2)
{
	double u = dbl_zero, du, arcLength = dbl_zero, arcLengthInv;
	double* lTable = lTable_out;
	uindex i;
	dvec4 v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		*vTable_out = vc = v0;

		for (i = 1, du = ijk_recip_dbl((f64)numDivisions); i <= numDivisions; ++i)
		{
			u = (f64)i * du;
			v = ijkVecCubicCatmullRom4d(vp, v0, v1, v2, u);
			arcLength += ijkVecDistance4d(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			*(++vTable_out) = vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_dbl(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl double ijkVecReparamBicubicCatmullRom4d(double uTable_out[], double lTable_out[], dvec4 vTable_out[], size const numDivisions, ibool const lNormalize, dvec4 const vpp, dvec4 const vp0, dvec4 const vp1, dvec4 const vp2, dvec4 const v0p, dvec4 const v00, dvec4 const v01, dvec4 const v02, dvec4 const v1p, dvec4 const v10, dvec4 const v11, dvec4 const v12, dvec4 const v2p, dvec4 const v20, dvec4 const v21, dvec4 const v22, double const up, double const u0, double const u1, double const u2)
{
	double u = dbl_zero, du, arcLength = dbl_zero, arcLengthInv;
	double* lTable = lTable_out;
	uindex i;
	dvec4 v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		dvec4 const vp = ijkVecCubicCatmullRom4d(vpp, vp0, vp1, vp2, up), v0 = ijkVecCubicCatmullRom4d(v0p, v00, v01, v02, u0),
			v1 = ijkVecCubicCatmullRom4d(v1p, v10, v11, v12, u1), v2 = ijkVecCubicCatmullRom4d(v2p, v20, v21, v22, u2);

		*uTable_out = u;
		*lTable_out = arcLength;
		*vTable_out = vc = v0;

		for (i = 1, du = ijk_recip_dbl((f64)numDivisions); i <= numDivisions; ++i)
		{
			u = (f64)i * du;
			v = ijkVecCubicCatmullRom4d(vp, v0, v1, v2, u);
			arcLength += ijkVecDistance4d(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			*(++vTable_out) = vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_dbl(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl dvec4 ijkVecSampleTableInc4d(double const uTable[], dvec4 const vTable[], index i, index di, double const u)
{
	dvec4 v0, v1;
	double uReparam;
	double u0, u1 = *(uTable + (i += (di ? di : (di = 1))));

	while (u1 < u)
		u1 = *(uTable + (i += di));
	v1 = *(vTable + i);
	v0 = *(vTable + (i -= di));
	u0 = *(uTable + i);
	uReparam = ijkInterpLinearInv_dbl(u0, u1, u);
	return ijkVecLerp4d(v0, v1, uReparam);
}

ijk_inl dvec4 ijkVecSampleTableDec4d(double const uTable[], dvec4 const vTable[], index i, index di, double const u)
{
	dvec4 v0, v1;
	double uReparam;
	double u0, u1 = *(uTable + (i += (di ? di : (di = 1))));

	while (u1 > u)
		u1 = *(uTable + (i += di));
	v1 = *(vTable + i);
	v0 = *(vTable + (i -= di));
	u0 = *(uTable + i);
	uReparam = ijkInterpLinearInv_dbl(u0, u1, u);
	return ijkVecLerp4d(v0, v1, uReparam);
}


//-----------------------------------------------------------------------------

ijk_inl i8 ijkVecPack1db(f64 const v_in)
{
	// pack signed double into signed byte: 7 bits + sign
	//	2^7-1 = 127
	return (i8)(v_in * 127.0);
}

ijk_inl f64 ijkVecUnpack1db(i8 const i_in)
{
	return ((f64)i_in / 127.0);
}

ijk_inl i16 ijkVecPack1ds(f64 const v_in)
{
	// sign + 15 bits
	return (i16)(v_in * 32767.0);
}

ijk_inl f64 ijkVecUnpack1ds(i16 const i_in)
{
	return ((f64)i_in / 32767.0);
}

ijk_inl i16 ijkVecPack2dvs(double2 const v_in)
{
	// scale inputs, mask and shift
	return (i16)(
		((i16)(v_in[0] * 127.0) & 0xff) |
		((i16)(v_in[1] * 127.0) & 0xff) << 8);
}

ijk_inl doublev ijkVecUnpack2dvs(double2 v_out, i16 const i_in)
{
	// shift, mask and scale
	v_out[0] = ((f64)(i_in		& 0xff) / 127.0);
	v_out[1] = ((f64)(i_in >> 8 & 0xff) / 127.0);
	return v_out;
}

ijk_inl i32 ijkVecPack2dvl(double2 const v_in)
{
	return (i32)(
		((i32)(v_in[0] * 32767.0) & 0xffff) |
		((i32)(v_in[1] * 32767.0) & 0xffff) << 16);
}

ijk_inl doublev ijkVecUnpack2dvl(double2 v_out, i32 const i_in)
{
	v_out[0] = ((f64)(i_in		 & 0xffff) / 32767.0);
	v_out[1] = ((f64)(i_in >> 16 & 0xffff) / 32767.0);
	return v_out;
}

ijk_inl i32 ijkVecPack3dvl(double3 const v_in)
{
	return (i32)(
		((i32)(v_in[0] * 511.0) & 0x03ff) |
		((i32)(v_in[1] * 511.0) & 0x03ff) << 10 |
		((i32)(v_in[2] * 511.0) & 0x03ff) << 20);
}

ijk_inl doublev ijkVecUnpack3dvl(double3 v_out, i32 const i_in)
{
	v_out[0] = ((f64)(i_in		 & 0x03ff) / 511.0);
	v_out[1] = ((f64)(i_in >> 10 & 0x03ff) / 511.0);
	v_out[2] = ((f64)(i_in >> 20 & 0x03ff) / 511.0);
	return v_out;
}

ijk_inl i32 ijkVecPack4dvl(double4 const v_in)
{
	return (i32)(
		((i32)(v_in[0] * 127.0) & 0xff) |
		((i32)(v_in[1] * 127.0) & 0xff) <<  8 |
		((i32)(v_in[2] * 127.0) & 0xff) << 16 |
		((i32)(v_in[3] * 127.0) & 0xff) << 24);
}

ijk_inl doublev ijkVecUnpack4dvl(double4 v_out, i32 const i_in)
{
	v_out[0] = ((f64)(i_in		 & 0xff) / 127.0);
	v_out[1] = ((f64)(i_in >>  8 & 0xff) / 127.0);
	v_out[2] = ((f64)(i_in >> 16 & 0xff) / 127.0);
	v_out[3] = ((f64)(i_in >> 24 & 0xff) / 127.0);
	return v_out;
}

ijk_inl i64 ijkVecPack4dvll(double4 const v_in)
{
	return (i64)(
		((i64)(v_in[0] * 32767.0) & 0xffff) |
		((i64)(v_in[1] * 32767.0) & 0xffff) << 16 |
		((i64)(v_in[2] * 32767.0) & 0xffff) << 32 |
		((i64)(v_in[3] * 32767.0) & 0xffff) << 48);
}

ijk_inl doublev ijkVecUnpack4dvll(double4 v_out, i64 const i_in)
{
	v_out[0] = ((f64)(i_in		 & 0xffff) / 32767.0);
	v_out[1] = ((f64)(i_in >> 16 & 0xffff) / 32767.0);
	v_out[2] = ((f64)(i_in >> 32 & 0xffff) / 32767.0);
	v_out[3] = ((f64)(i_in >> 48 & 0xffff) / 32767.0);
	return v_out;
}

ijk_inl i32 ijkVecPackUnitXYZ4dvl(double4 const v_in)
{
	// store first three elements and sign of fourth
	return (i32)(
		((i32)(v_in[0] * 511.0) & 0x03ff) |
		((i32)(v_in[1] * 511.0) & 0x03ff) << 10 |
		((i32)(v_in[2] * 511.0) & 0x03ff) << 20 |
		(*(i32*)(v_in + 3) & 0x80000000));
}

ijk_inl doublev ijkVecUnpackUnitXYZ4dvl(double4 v_out, i32 const i_in)
{
	// extract first three elements, calculate fourth using magnitude and sign
	v_out[0] = ((f64)(i_in		 & 0x03ff) / 511.0);
	v_out[1] = ((f64)(i_in >> 10 & 0x03ff) / 511.0);
	v_out[2] = ((f64)(i_in >> 20 & 0x03ff) / 511.0);
	v_out[3] = ((f64)(i_in >> 31) * ijkSqrt_dbl(dbl_one - ijkVecLengthSq3dv(v_out)));
	return v_out;
}

ijk_inl i32 ijkVecPackUnit3of4dvl(double4 const v_in, ui32 const excl)
{
	// entire vector scales by sign of excluded element
	// store all others and index of excluded
	ui32 const x = (excl % 4);
	f64 const f = (*(i32*)(v_in + x) & 0x80000000) ? -511.0 : +511.0;
	return (i32)(
		((i32)(v_in[(x + 1) % 4] * f) & 0x03ff) |
		((i32)(v_in[(x + 2) % 4] * f) & 0x03ff) << 10 |
		((i32)(v_in[(x + 3) % 4] * f) & 0x03ff) << 20 |
		x << 30);
}

ijk_inl doublev ijkVecUnpackUnit3of4dvl(double4 v_out, i32 const i_in, ui32* const excl_out)
{
	// get index of excluded, extract others, calculate using magnitude
	ui32 const x = *excl_out = (i_in >> 30);
	f64 v1, v2, v3;
	v_out[(x + 1) % 4] = v1 = ((f64)(i_in		& 0x03ff) / 511.0);
	v_out[(x + 2) % 4] = v2 = ((f64)(i_in >> 10 & 0x03ff) / 511.0);
	v_out[(x + 3) % 4] = v3 = ((f64)(i_in >> 20 & 0x03ff) / 511.0);
	v_out[x] = ijkSqrt_dbl(dbl_one - v1 * v1 - v2 * v2 - v3 * v3);
	return v_out;
}

ijk_inl i32 ijkVecPackQuant4dvl(double4 const v_in)
{
	// calculate index of component with greatest magnitude
	double4 const sq = { (v_in[0] * v_in[0]), (v_in[1] * v_in[1]), (v_in[2] * v_in[2]), (v_in[3] * v_in[3]) };
	ui32 const xy = (sq[1] >= sq[0]) + 0, zw = (sq[3] >= sq[2]) + 2, x = (sq[xy] >= sq[zw] ? xy : zw);
	f64 const f = (*(i32*)(v_in + x) & 0x80000000) ? -722.6631303726515 : +722.6631303726515; // ~= 511 * sqrt(2)
	return (i32)(
		((i32)(v_in[(x + 1) % 4] * f) & 0x03ff) |
		((i32)(v_in[(x + 2) % 4] * f) & 0x03ff) << 10 |
		((i32)(v_in[(x + 3) % 4] * f) & 0x03ff) << 20 |
		x << 30);
}

ijk_inl doublev ijkVecUnpackQuant4dvl(double4 v_out, i32 const i_in)
{
	// get index of excluded, extract others, calculate using magnitude
	ui32 const x = (i_in >> 30);
	f64 v1, v2, v3;
	v_out[(x + 1) % 4] = v1 = ((f64)(i_in		& 0x03ff) / 722.6631303726515);
	v_out[(x + 2) % 4] = v2 = ((f64)(i_in >> 10 & 0x03ff) / 722.6631303726515);
	v_out[(x + 3) % 4] = v3 = ((f64)(i_in >> 20 & 0x03ff) / 722.6631303726515);
	v_out[x] = ijkSqrt_dbl(dbl_one - v1 * v1 - v2 * v2 - v3 * v3);
	return v_out;
}

ijk_inl i64 ijkVecPackUnitXYZ4dvll(double4 const v_in)
{
	// store first three elements and sign of fourth
	return (i64)(
		((i64)(v_in[0] * 1048575.0) & 0x001fffff) << 00 |
		((i64)(v_in[1] * 1048575.0) & 0x001fffff) << 21 |
		((i64)(v_in[2] * 1048575.0) & 0x001fffff) << 42 |
		((i64)(*(i32*)(v_in + 3) & 0x80000000)) << 31);
}

ijk_inl doublev ijkVecUnpackUnitXYZ4dvll(double4 v_out, i64 const i_in)
{
	v_out[0] = ((f64)(i_in		 & 0x001fffff) / 1048575.0);
	v_out[1] = ((f64)(i_in >> 21 & 0x001fffff) / 1048575.0);
	v_out[2] = ((f64)(i_in >> 42 & 0x001fffff) / 1048575.0);
	v_out[3] = ((f64)(i_in >> 63) * ijkSqrt_dbl(dbl_one - ijkVecLengthSq3dv(v_out)));
	return v_out;
}

ijk_inl i64 ijkVecPackUnit3of4dvll(double4 const v_in, ui64 const excl)
{
	// this time store index and sign
	ui64 const x = (excl % 4);
	return (i64)(
		((i64)(v_in[(x + 1) % 4] * 524287.0) & 0x000fffff) |
		((i64)(v_in[(x + 2) % 4] * 524287.0) & 0x000fffff) << 10 |
		((i64)(v_in[(x + 3) % 4] * 524287.0) & 0x000fffff) << 20 |
		((i64)(*(i32*)(v_in + x) & 0x80000000)) << 31 |
		x << 61);
}

ijk_inl doublev ijkVecUnpackUnit3of4dvll(double4 v_out, i64 const i_in, ui64* const excl_out)
{
	// get missing index without sign
	ui64 const x = (i_in >> 61 & 3);
	f64 v1, v2, v3;
	v_out[(x + 1) % 4] = v1 = ((f64)(i_in		& 0x000fffff) / 524287.0);
	v_out[(x + 2) % 4] = v2 = ((f64)(i_in >> 20 & 0x000fffff) / 524287.0);
	v_out[(x + 3) % 4] = v3 = ((f64)(i_in >> 40 & 0x000fffff) / 524287.0);
	v_out[x] = ((f64)(i_in >> 63) * ijkSqrt_dbl(dbl_one - v1 * v1 - v2 * v2 - v3 * v3));
	return v_out;
}

ijk_inl i64 ijkVecPackQuant4dvll(double4 const v_in)
{
	double4 const sq = { (v_in[0] * v_in[0]), (v_in[1] * v_in[1]), (v_in[2] * v_in[2]), (v_in[3] * v_in[3]) };
	ui64 const xy = (sq[1] >= sq[0]) + 0, zw = (sq[3] >= sq[2]) + 2, x = (sq[xy] >= sq[zw] ? xy : zw);
	return (i64)(
		((i64)(v_in[(x + 1) % 4] * 23169.06079235841) & 0x7fff) << 16 | // ~= 16383 * sqrt(2); << 16
		((i64)(v_in[(x + 2) % 4] * 23169.06079235841) & 0x7fff) << 31 |	// << 15 << 16
		((i64)(v_in[(x + 3) % 4] * 23169.06079235841) & 0x7fff) << 46 |	// << 30 << 16
		((i64)(*(i32*)(v_in + x) & 0x80000000)) << 31 |
		x << 61);
}

ijk_inl doublev ijkVecUnpackQuant4dvll(double4 v_out, i64 const i_in)
{
	ui64 const x = (i_in >> 61 & 3);
	f64 v1, v2, v3;
	v_out[(x + 1) % 4] = v1 = ((f64)(i_in >> 16 & 0x7fff) / 23169.06079235841);
	v_out[(x + 2) % 4] = v2 = ((f64)(i_in >> 31 & 0x7fff) / 23169.06079235841);
	v_out[(x + 3) % 4] = v3 = ((f64)(i_in >> 46 & 0x7fff) / 23169.06079235841);
	v_out[x] = ((f64)(i_in >> 63) * ijkSqrt_dbl(dbl_one - v1 * v1 - v2 * v2 - v3 * v3));
	return v_out;
}


//-----------------------------------------------------------------------------

ijk_inl i16 ijkVecPack2ds(dvec2 const v_in)
{
	return (i16)(
		((i16)(v_in.x * 127.0) & 0xff) |
		((i16)(v_in.y * 127.0) & 0xff) << 8);
}

ijk_inl dvec2 ijkVecUnpack2ds(i16 const i_in)
{
	dvec2 const v_out = {
		((f64)(i_in		 & 0xff) / 127.0),
		((f64)(i_in >> 8 & 0xff) / 127.0),
	};
	return v_out;
}

ijk_inl i32 ijkVecPack2dl(dvec2 const v_in)
{
	return (i32)(
		((i32)(v_in.x * 32767.0) & 0xffff) |
		((i32)(v_in.y * 32767.0) & 0xffff) << 16);
}

ijk_inl dvec2 ijkVecUnpack2dl(i32 const i_in)
{
	dvec2 const v_out = {
		((f64)(i_in		  & 0xffff) / 32767.0),
		((f64)(i_in >> 16 & 0xffff) / 32767.0),
	};
	return v_out;
}

ijk_inl i32 ijkVecPack3dl(dvec3 const v_in)
{
	return (i32)(
		((i32)(v_in.x * 511.0) & 0x03ff) |
		((i32)(v_in.y * 511.0) & 0x03ff) << 10 |
		((i32)(v_in.z * 511.0) & 0x03ff) << 20);
}

ijk_inl dvec3 ijkVecUnpack3dl(i32 const i_in)
{
	dvec3 const v_out = {
		((f64)(i_in		  & 0x03ff) / 511.0),
		((f64)(i_in >> 10 & 0x03ff) / 511.0),
		((f64)(i_in >> 20 & 0x03ff) / 511.0),
	};
	return v_out;
}

ijk_inl i32 ijkVecPack4dl(dvec4 const v_in)
{
	return (i32)(
		((i32)(v_in.x * 127.0) & 0xff) |
		((i32)(v_in.y * 127.0) & 0xff) <<  8 |
		((i32)(v_in.z * 127.0) & 0xff) << 16 |
		((i32)(v_in.w * 127.0) & 0xff) << 24);
}

ijk_inl dvec4 ijkVecUnpack4dl(i32 const i_in)
{
	dvec4 const v_out = {
		((f64)(i_in		  & 0xff) / 127.0),
		((f64)(i_in >>  8 & 0xff) / 127.0),
		((f64)(i_in >> 16 & 0xff) / 127.0),
		((f64)(i_in >> 24 & 0xff) / 127.0),
	};
	return v_out;
}

ijk_inl i64 ijkVecPack4dll(dvec4 const v_in)
{
	return (i64)(
		((i64)(v_in.x * 32767.0) & 0xffff) |
		((i64)(v_in.y * 32767.0) & 0xffff) << 16 |
		((i64)(v_in.z * 32767.0) & 0xffff) << 32 |
		((i64)(v_in.w * 32767.0) & 0xffff) << 48);
}

ijk_inl dvec4 ijkVecUnpack4dll(i64 const i_in)
{
	dvec4 const v_out = {
		((f64)(i_in		  & 0xffff) / 32767.0),
		((f64)(i_in >> 16 & 0xffff) / 32767.0),
		((f64)(i_in >> 32 & 0xffff) / 32767.0),
		((f64)(i_in >> 48 & 0xffff) / 32767.0),
	};
	return v_out;
}

ijk_inl i32 ijkVecPackUnitXYZ4dl(dvec4 const v_in)
{
	return (i32)(
		((i32)(v_in.x * 511.0) & 0x03ff) |
		((i32)(v_in.y * 511.0) & 0x03ff) << 10 |
		((i32)(v_in.z * 511.0) & 0x03ff) << 20 |
		(*(i32*)(v_in.v + 3) & 0x80000000));
}

ijk_inl dvec4 ijkVecUnpackUnitXYZ4dl(i32 const i_in)
{
	f64 x, y, z;
	dvec4 const v_out = {
		(x = (f64)(i_in		  & 0x03ff) / 511.0),
		(y = (f64)(i_in >> 10 & 0x03ff) / 511.0),
		(z = (f64)(i_in >> 20 & 0x03ff) / 511.0),
		((f64)(i_in >> 31) * ijkSqrt_dbl(dbl_one - x * x - y * y - z * z)),
	};
	return v_out;
}

ijk_inl i32 ijkVecPackUnit3of4dl(dvec4 const v_in, ui32 const excl)
{
	ui32 const x = (excl % 4);
	f64 const f = (*(i32*)(v_in.v + x) & 0x80000000) ? -511.0 : +511.0;
	return (i32)(
		((i32)(v_in.v[(x + 1) % 4] * f) & 0x03ff) |
		((i32)(v_in.v[(x + 2) % 4] * f) & 0x03ff) << 10 |
		((i32)(v_in.v[(x + 3) % 4] * f) & 0x03ff) << 20 |
		x << 30);
}

ijk_inl dvec4 ijkVecUnpackUnit3of4dl(i32 const i_in, ui32* const excl_out)
{
	ui32 const x = *excl_out = (i_in >> 30);
	f64 v1, v2, v3;
	dvec4 v_out;
	v_out.v[(x + 1) % 4] = v1 = ((f64)(i_in		  & 0x03ff) / 511.0);
	v_out.v[(x + 2) % 4] = v2 = ((f64)(i_in >> 10 & 0x03ff) / 511.0);
	v_out.v[(x + 3) % 4] = v3 = ((f64)(i_in >> 20 & 0x03ff) / 511.0);
	v_out.v[x] = ijkSqrt_dbl(dbl_one - v1 * v1 - v2 * v2 - v3 * v3);
	return v_out;
}

ijk_inl i32 ijkVecPackQuant4dl(dvec4 const v_in)
{
	dvec4 const sq = { (v_in.x * v_in.x), (v_in.y * v_in.y), (v_in.z * v_in.z), (v_in.w * v_in.w) };
	ui32 const xy = (sq.y >= sq.x) + 0, zw = (sq.w >= sq.z) + 2, x = (sq.v[xy] >= sq.v[zw] ? xy : zw);
	f64 const f = (*(i32*)(v_in.v + x) & 0x80000000) ? -722.6631303726515 : +722.6631303726515; // ~= 511 * sqrt(2)
	return (i32)(
		((i32)(v_in.v[(x + 1) % 4] * f) & 0x03ff) |
		((i32)(v_in.v[(x + 2) % 4] * f) & 0x03ff) << 10 |
		((i32)(v_in.v[(x + 3) % 4] * f) & 0x03ff) << 20 |
		x << 30);
}

ijk_inl dvec4 ijkVecUnpackQuant4dl(i32 const i_in)
{
	ui32 const x = (i_in >> 30);
	f64 v1, v2, v3;
	dvec4 v_out;
	v_out.v[(x + 1) % 4] = v1 = ((f64)(i_in		  & 0x03ff) / 722.6631303726515);
	v_out.v[(x + 2) % 4] = v2 = ((f64)(i_in >> 10 & 0x03ff) / 722.6631303726515);
	v_out.v[(x + 3) % 4] = v3 = ((f64)(i_in >> 20 & 0x03ff) / 722.6631303726515);
	v_out.v[x] = ijkSqrt_dbl(dbl_one - v1 * v1 - v2 * v2 - v3 * v3);
	return v_out;
}

ijk_inl i64 ijkVecPackUnitXYZ4dll(dvec4 const v_in)
{
	return (i64)(
		((i64)(v_in.x * 1048575.0) & 0x001fffff) << 00 |
		((i64)(v_in.y * 1048575.0) & 0x001fffff) << 21 |
		((i64)(v_in.z * 1048575.0) & 0x001fffff) << 42 |
		((i64)(*(i32*)(v_in.v + 3) & 0x80000000)) << 31);
}

ijk_inl dvec4 ijkVecUnpackUnitXYZ4dll(i64 const i_in)
{
	f64 x, y, z;
	dvec4 const v_out = {
		(x = (f64)(i_in		  & 0x001fffff) / 1048575.0),
		(y = (f64)(i_in >> 21 & 0x001fffff) / 1048575.0),
		(z = (f64)(i_in >> 42 & 0x001fffff) / 1048575.0),
		((f64)(i_in >> 63) * ijkSqrt_dbl(dbl_one - x * x - y * y - z * z)),
	};
	return v_out;
}

ijk_inl i64 ijkVecPackUnit3of4dll(dvec4 const v_in, ui64 const excl)
{
	ui64 const x = (excl % 4);
	return (i64)(
		((i64)(v_in.v[(x + 1) % 4] * 524287.0) & 0x000fffff) |
		((i64)(v_in.v[(x + 2) % 4] * 524287.0) & 0x000fffff) << 10 |
		((i64)(v_in.v[(x + 3) % 4] * 524287.0) & 0x000fffff) << 20 |
		((i64)(*(i32*)(v_in.v + x) & 0x80000000)) << 31 |
		x << 61);
}

ijk_inl dvec4 ijkVecUnpackUnit3of4dll(i64 const i_in, ui64* const excl_out)
{
	ui64 const x = (i_in >> 61 & 3);
	f64 v1, v2, v3;
	dvec4 v_out;
	v_out.v[(x + 1) % 4] = v1 = ((f64)(i_in		  & 0x000fffff) / 524287.0);
	v_out.v[(x + 2) % 4] = v2 = ((f64)(i_in >> 20 & 0x000fffff) / 524287.0);
	v_out.v[(x + 3) % 4] = v3 = ((f64)(i_in >> 40 & 0x000fffff) / 524287.0);
	v_out.v[x] = ((f64)(i_in >> 63) * ijkSqrt_dbl(dbl_one - v1 * v1 - v2 * v2 - v3 * v3));
	return v_out;
}

ijk_inl i64 ijkVecPackQuant4dll(dvec4 const v_in)
{
	dvec4 const sq = { (v_in.x * v_in.x), (v_in.y * v_in.y), (v_in.z * v_in.z), (v_in.w * v_in.w) };
	ui64 const xy = (sq.y >= sq.x) + 0, zw = (sq.w >= sq.z) + 2, x = (sq.v[xy] >= sq.v[zw] ? xy : zw);
	return (i64)(
		((i64)(v_in.v[(x + 1) % 4] * 23169.06079235841) & 0x7fff) << 16 | // ~= 16383 * sqrt(2); << 16
		((i64)(v_in.v[(x + 2) % 4] * 23169.06079235841) & 0x7fff) << 31 |	// << 15 << 16
		((i64)(v_in.v[(x + 3) % 4] * 23169.06079235841) & 0x7fff) << 46 |	// << 30 << 16
		((i64)(*(i32*)(v_in.v + x) & 0x80000000)) << 31 |
		x << 61);
}

ijk_inl dvec4 ijkVecUnpackQuant4dll(i64 const i_in)
{
	ui64 const x = (i_in >> 61 & 3);
	f64 v1, v2, v3;
	dvec4 v_out;
	v_out.v[(x + 1) % 4] = v1 = ((f64)(i_in >> 16 & 0x7fff) / 23169.06079235841);
	v_out.v[(x + 2) % 4] = v2 = ((f64)(i_in >> 31 & 0x7fff) / 23169.06079235841);
	v_out.v[(x + 3) % 4] = v3 = ((f64)(i_in >> 46 & 0x7fff) / 23169.06079235841);
	v_out.v[x] = ((f64)(i_in >> 63) * ijkSqrt_dbl(dbl_one - v1 * v1 - v2 * v2 - v3 * v3));
	return v_out;
}


//-----------------------------------------------------------------------------


#endif	// !_IJK_VECTOR_DOUBLE_INL_
#endif	// _IJK_VECTOR_DOUBLE_H_