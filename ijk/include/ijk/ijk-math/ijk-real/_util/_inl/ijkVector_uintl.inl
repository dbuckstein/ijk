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

	ijkVector_uint.inl
	Inline definitions for unsigned 64-bit integer vector functions.
*/

#ifdef _IJK_VECTOR_UINTL_H_
#ifndef _IJK_VECTOR_UINTL_INL_
#define _IJK_VECTOR_UINTL_INL_


//-----------------------------------------------------------------------------

ijk_inl ui64 ijkVecAbs1uls(ui64 const s)
{
	return (s);
}

ijk_inl ui64 ijkVecSgn1uls(ui64 const s)
{
	return ijk_one;
}

ijk_inl ui64 ijkVecDot1uls(ui64 const s_lh, ui64 const s_rh)
{
	return (s_lh * s_rh);
}

ijk_inl ui64 ijkVecLengthSq1uls(ui64 const s)
{
	return (s * s);
}

ijk_inl ui64 ijkVecLength1uls(ui64 const s)
{
	return (s);
}

ijk_inl f64 ijkVecLengthSqInv1uls(ui64 const s)
{
	ui64 const lengthSq = (s * s);
	return ijk_recip_safe_dbl(lengthSq);
}

ijk_inl f64 ijkVecLengthInv1uls(ui64 const s)
{
	ui64 const length = (s);
	return ijk_recip_safe_dbl(length);
}

ijk_inl ui64 ijkVecNormalize1uls(ui64 const s)
{
	return ijk_sgn_int(s);
}

ijk_inl ui64 ijkVecNormalizeGetLength1uls(ui64 const s, ui64* const length_out)
{
	ui64 const length = *length_out = (s);
	return ijk_one;
}

ijk_inl ui64 ijkVecNormalizeGetLengthInv1uls(ui64 const s, f64* const lengthInv_out)
{
	ui64 const length = (s);
	*lengthInv_out = ijk_recip_safe_dbl(length);
	return ijk_one;
}


//-----------------------------------------------------------------------------

ijk_inl uintlv ijkVecPulv(uintlv v_out)
{
	return v_out;
}


//-----------------------------------------------------------------------------

ijk_inl uintlv ijkVecInit2ulv(uintl2 v_out)
{
	v_out[0] = v_out[1] = 0;
	return v_out;
}

ijk_inl uintlv ijkVecInitElems2ulv(uintl2 v_out, ui64 const x, ui64 const y)
{
	v_out[0] = x;
	v_out[1] = y;
	return v_out;
}

ijk_inl uintlv ijkVecCopy2ulv(uintl2 v_out, uintl2 const v_in)
{
	v_out[0] = +v_in[0];
	v_out[1] = +v_in[1];
	return v_out;
}

ijk_inl intlv ijkVecNegate2ulv(intl2 v_out, uintl2 const v_in)
{
	v_out[0] = -(i64)v_in[0];
	v_out[1] = -(i64)v_in[1];
	return v_out;
}

ijk_inl uintlv ijkVecBitNot2ulv(uintl2 v_out, uintl2 const v_in)
{
	v_out[0] = ~v_in[0];
	v_out[1] = ~v_in[1];
	return v_out;
}

ijk_inl boolv ijkVecNot2ulv(bool2 bv_out, uintl2 const v_in)
{
	bv_out[0] = !v_in[0];
	bv_out[1] = !v_in[1];
	return bv_out;
}

ijk_inl uintlv ijkVecAdd2ulv(uintl2 v_out, uintl2 const v_lh, uintl2 const v_rh)
{
	v_out[0] = v_lh[0] + v_rh[0];
	v_out[1] = v_lh[1] + v_rh[1];
	return v_out;
}

ijk_inl uintlv ijkVecSub2ulv(uintl2 v_out, uintl2 const v_lh, uintl2 const v_rh)
{
	v_out[0] = v_lh[0] - v_rh[0];
	v_out[1] = v_lh[1] - v_rh[1];
	return v_out;
}

ijk_inl uintlv ijkVecMul2ulv(uintl2 v_out, uintl2 const v_lh, uintl2 const v_rh)
{
	v_out[0] = v_lh[0] * v_rh[0];
	v_out[1] = v_lh[1] * v_rh[1];
	return v_out;
}

ijk_inl uintlv ijkVecDiv2ulv(uintl2 v_out, uintl2 const v_lh, uintl2 const v_rh)
{
	v_out[0] = v_lh[0] / v_rh[0];
	v_out[1] = v_lh[1] / v_rh[1];
	return v_out;
}

ijk_inl uintlv ijkVecDivSafe2ulv(uintl2 v_out, uintl2 const v_lh, uintl2 const v_rh)
{
	v_out[0] = ijk_divide_safe_int(v_lh[0], v_rh[0]);
	v_out[1] = ijk_divide_safe_int(v_lh[1], v_rh[1]);
	return v_out;
}

ijk_inl uintlv ijkVecMod2ulv(uintl2 v_out, uintl2 const v_lh, uintl2 const v_rh)
{
	v_out[0] = v_lh[0] % v_rh[0];
	v_out[1] = v_lh[1] % v_rh[1];
	return v_out;
}

ijk_inl uintlv ijkVecModSafe2ulv(uintl2 v_out, uintl2 const v_lh, uintl2 const v_rh)
{
	v_out[0] = ijk_modulo_safe_int(v_lh[0], v_rh[0]);
	v_out[1] = ijk_modulo_safe_int(v_lh[1], v_rh[1]);
	return v_out;
}

ijk_inl uintlv ijkVecBitAnd2ulv(uintl2 v_out, uintl2 const v_lh, uintl2 const v_rh)
{
	v_out[0] = (v_lh[0] & v_rh[0]);
	v_out[1] = (v_lh[1] & v_rh[1]);
	return v_out;
}

ijk_inl uintlv ijkVecBitNand2ulv(uintl2 v_out, uintl2 const v_lh, uintl2 const v_rh)
{
	v_out[0] = ~(v_lh[0] & v_rh[0]);
	v_out[1] = ~(v_lh[1] & v_rh[1]);
	return v_out;
}

ijk_inl uintlv ijkVecBitOr2ulv(uintl2 v_out, uintl2 const v_lh, uintl2 const v_rh)
{
	v_out[0] = (v_lh[0] | v_rh[0]);
	v_out[1] = (v_lh[1] | v_rh[1]);
	return v_out;
}

ijk_inl uintlv ijkVecBitNor2ulv(uintl2 v_out, uintl2 const v_lh, uintl2 const v_rh)
{
	v_out[0] = ~(v_lh[0] | v_rh[0]);
	v_out[1] = ~(v_lh[1] | v_rh[1]);
	return v_out;
}

ijk_inl uintlv ijkVecBitXor2ulv(uintl2 v_out, uintl2 const v_lh, uintl2 const v_rh)
{
	v_out[0] = (v_lh[0] ^ v_rh[0]);
	v_out[1] = (v_lh[1] ^ v_rh[1]);
	return v_out;
}

ijk_inl uintlv ijkVecBitXnor2ulv(uintl2 v_out, uintl2 const v_lh, uintl2 const v_rh)
{
	v_out[0] = ~(v_lh[0] ^ v_rh[0]);
	v_out[1] = ~(v_lh[1] ^ v_rh[1]);
	return v_out;
}

ijk_inl uintlv ijkVecBitShiftLeft2ulv(uintl2 v_out, uintl2 const v_lh, uintl2 const v_rh)
{
	v_out[0] = (v_lh[0] << v_rh[0]);
	v_out[1] = (v_lh[1] << v_rh[1]);
	return v_out;
}

ijk_inl uintlv ijkVecBitShiftRight2ulv(uintl2 v_out, uintl2 const v_lh, uintl2 const v_rh)
{
	v_out[0] = (v_lh[0] >> v_rh[0]);
	v_out[1] = (v_lh[1] >> v_rh[1]);
	return v_out;
}

ijk_inl boolv ijkVecEqual2ulv(bool2 bv_out, uintl2 const v_lh, uintl2 const v_rh)
{
	bv_out[0] = (v_lh[0] == v_rh[0]);
	bv_out[1] = (v_lh[1] == v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal2ulv(bool2 bv_out, uintl2 const v_lh, uintl2 const v_rh)
{
	bv_out[0] = (v_lh[0] != v_rh[0]);
	bv_out[1] = (v_lh[1] != v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual2ulv(bool2 bv_out, uintl2 const v_lh, uintl2 const v_rh)
{
	bv_out[0] = (v_lh[0] <= v_rh[0]);
	bv_out[1] = (v_lh[1] <= v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual2ulv(bool2 bv_out, uintl2 const v_lh, uintl2 const v_rh)
{
	bv_out[0] = (v_lh[0] >= v_rh[0]);
	bv_out[1] = (v_lh[1] >= v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecLess2ulv(bool2 bv_out, uintl2 const v_lh, uintl2 const v_rh)
{
	bv_out[0] = (v_lh[0] < v_rh[0]);
	bv_out[1] = (v_lh[1] < v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater2ulv(bool2 bv_out, uintl2 const v_lh, uintl2 const v_rh)
{
	bv_out[0] = (v_lh[0] > v_rh[0]);
	bv_out[1] = (v_lh[1] > v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd2ulv(bool2 bv_out, uintl2 const v_lh, uintl2 const v_rh)
{
	bv_out[0] = (v_lh[0] && v_rh[0]);
	bv_out[1] = (v_lh[1] && v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecNand2ulv(bool2 bv_out, uintl2 const v_lh, uintl2 const v_rh)
{
	bv_out[0] = !(v_lh[0] && v_rh[0]);
	bv_out[1] = !(v_lh[1] && v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecOr2ulv(bool2 bv_out, uintl2 const v_lh, uintl2 const v_rh)
{
	bv_out[0] = (v_lh[0] || v_rh[0]);
	bv_out[1] = (v_lh[1] || v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecNor2ulv(bool2 bv_out, uintl2 const v_lh, uintl2 const v_rh)
{
	bv_out[0] = !(v_lh[0] || v_rh[0]);
	bv_out[1] = !(v_lh[1] || v_rh[1]);
	return bv_out;
}

ijk_inl uintlv ijkVecCopy2ulvs(uintl2 v_out, ui64 const s_in)
{
	v_out[0] = v_out[1] = +s_in;
	return v_out;
}

ijk_inl intlv ijkVecNegate2ulvs(intl2 v_out, ui64 const s_in)
{
	v_out[0] = v_out[1] = -(i64)s_in;
	return v_out;
}

ijk_inl uintlv ijkVecBitNot2ulvs(uintl2 v_out, ui64 const s_in)
{
	v_out[0] = v_out[1] = ~s_in;
	return v_out;
}

ijk_inl boolv ijkVecNot2ulvs(bool2 bv_out, ui64 const s_in)
{
	bv_out[0] = bv_out[1] = !s_in;
	return bv_out;
}

ijk_inl uintlv ijkVecAdd2ulvs(uintl2 v_out, uintl2 const v_lh, ui64 const s_rh)
{
	v_out[0] = v_lh[0] + s_rh;
	v_out[1] = v_lh[1] + s_rh;
	return v_out;
}

ijk_inl uintlv ijkVecSub2ulvs(uintl2 v_out, uintl2 const v_lh, ui64 const s_rh)
{
	v_out[0] = v_lh[0] - s_rh;
	v_out[1] = v_lh[1] - s_rh;
	return v_out;
}

ijk_inl uintlv ijkVecMul2ulvs(uintl2 v_out, uintl2 const v_lh, ui64 const s_rh)
{
	v_out[0] = v_lh[0] * s_rh;
	v_out[1] = v_lh[1] * s_rh;
	return v_out;
}

ijk_inl uintlv ijkVecDiv2ulvs(uintl2 v_out, uintl2 const v_lh, ui64 const s_rh)
{
	v_out[0] = v_lh[0] / s_rh;
	v_out[1] = v_lh[1] / s_rh;
	return v_out;
}

ijk_inl uintlv ijkVecDivSafe2ulvs(uintl2 v_out, uintl2 const v_lh, ui64 const s_rh)
{
	if (s_rh)
	{
		v_out[0] = v_lh[0] / s_rh;
		v_out[1] = v_lh[1] / s_rh;
	}
	else
		v_out[0] = v_out[1] = 0;
	return v_out;
}

ijk_inl uintlv ijkVecMod2ulvs(uintl2 v_out, uintl2 const v_lh, ui64 const s_rh)
{
	v_out[0] = v_lh[0] % s_rh;
	v_out[1] = v_lh[1] % s_rh;
	return v_out;
}

ijk_inl uintlv ijkVecModSafe2ulvs(uintl2 v_out, uintl2 const v_lh, ui64 const s_rh)
{
	if (s_rh)
	{
		v_out[0] = v_lh[0] % s_rh;
		v_out[1] = v_lh[1] % s_rh;
		return v_out;
	}
	return ijkVecCopy2ulv(v_out, v_lh);
}

ijk_inl uintlv ijkVecBitAnd2ulvs(uintl2 v_out, uintl2 const v_lh, ui64 const s_rh)
{
	v_out[0] = (v_lh[0] & s_rh);
	v_out[1] = (v_lh[1] & s_rh);
	return v_out;
}

ijk_inl uintlv ijkVecBitNand2ulvs(uintl2 v_out, uintl2 const v_lh, ui64 const s_rh)
{
	v_out[0] = ~(v_lh[0] & s_rh);
	v_out[1] = ~(v_lh[1] & s_rh);
	return v_out;
}

ijk_inl uintlv ijkVecBitOr2ulvs(uintl2 v_out, uintl2 const v_lh, ui64 const s_rh)
{
	v_out[0] = (v_lh[0] | s_rh);
	v_out[1] = (v_lh[1] | s_rh);
	return v_out;
}

ijk_inl uintlv ijkVecBitNor2ulvs(uintl2 v_out, uintl2 const v_lh, ui64 const s_rh)
{
	v_out[0] = ~(v_lh[0] | s_rh);
	v_out[1] = ~(v_lh[1] | s_rh);
	return v_out;
}

ijk_inl uintlv ijkVecBitXor2ulvs(uintl2 v_out, uintl2 const v_lh, ui64 const s_rh)
{
	v_out[0] = (v_lh[0] ^ s_rh);
	v_out[1] = (v_lh[1] ^ s_rh);
	return v_out;
}

ijk_inl uintlv ijkVecBitXnor2ulvs(uintl2 v_out, uintl2 const v_lh, ui64 const s_rh)
{
	v_out[0] = ~(v_lh[0] ^ s_rh);
	v_out[1] = ~(v_lh[1] ^ s_rh);
	return v_out;
}

ijk_inl uintlv ijkVecBitShiftLeft2ulvs(uintl2 v_out, uintl2 const v_lh, ui64 const s_rh)
{
	v_out[0] = (v_lh[0] << s_rh);
	v_out[1] = (v_lh[1] << s_rh);
	return v_out;
}

ijk_inl uintlv ijkVecBitShiftRight2ulvs(uintl2 v_out, uintl2 const v_lh, ui64 const s_rh)
{
	v_out[0] = (v_lh[0] >> s_rh);
	v_out[1] = (v_lh[1] >> s_rh);
	return v_out;
}

ijk_inl boolv ijkVecEqual2ulvs(bool2 bv_out, uintl2 const v_lh, ui64 const s_rh)
{
	bv_out[0] = (v_lh[0] == s_rh);
	bv_out[1] = (v_lh[1] == s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecInequal2ulvs(bool2 bv_out, uintl2 const v_lh, ui64 const s_rh)
{
	bv_out[0] = (v_lh[0] != s_rh);
	bv_out[1] = (v_lh[1] != s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual2ulvs(bool2 bv_out, uintl2 const v_lh, ui64 const s_rh)
{
	bv_out[0] = (v_lh[0] <= s_rh);
	bv_out[1] = (v_lh[1] <= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual2ulvs(bool2 bv_out, uintl2 const v_lh, ui64 const s_rh)
{
	bv_out[0] = (v_lh[0] >= s_rh);
	bv_out[1] = (v_lh[1] >= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLess2ulvs(bool2 bv_out, uintl2 const v_lh, ui64 const s_rh)
{
	bv_out[0] = (v_lh[0] < s_rh);
	bv_out[1] = (v_lh[1] < s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreater2ulvs(bool2 bv_out, uintl2 const v_lh, ui64 const s_rh)
{
	bv_out[0] = (v_lh[0] > s_rh);
	bv_out[1] = (v_lh[1] > s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecAnd2ulvs(bool2 bv_out, uintl2 const v_lh, ui64 const s_rh)
{
	bv_out[0] = (v_lh[0] && s_rh);
	bv_out[1] = (v_lh[1] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNand2ulvs(bool2 bv_out, uintl2 const v_lh, ui64 const s_rh)
{
	bv_out[0] = !(v_lh[0] && s_rh);
	bv_out[1] = !(v_lh[1] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecOr2ulvs(bool2 bv_out, uintl2 const v_lh, ui64 const s_rh)
{
	bv_out[0] = (v_lh[0] || s_rh);
	bv_out[1] = (v_lh[1] || s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNor2ulvs(bool2 bv_out, uintl2 const v_lh, ui64 const s_rh)
{
	bv_out[0] = !(v_lh[0] || s_rh);
	bv_out[1] = !(v_lh[1] || s_rh);
	return bv_out;
}

ijk_inl uintlv ijkVecAdd2ulsv(uintl2 v_out, ui64 const s_lh, uintl2 const v_rh)
{
	v_out[0] = s_lh + v_rh[0];
	v_out[1] = s_lh + v_rh[1];
	return v_out;
}

ijk_inl uintlv ijkVecSub2ulsv(uintl2 v_out, ui64 const s_lh, uintl2 const v_rh)
{
	v_out[0] = s_lh - v_rh[0];
	v_out[1] = s_lh - v_rh[1];
	return v_out;
}

ijk_inl uintlv ijkVecMul2ulsv(uintl2 v_out, ui64 const s_lh, uintl2 const v_rh)
{
	v_out[0] = s_lh * v_rh[0];
	v_out[1] = s_lh * v_rh[1];
	return v_out;
}

ijk_inl uintlv ijkVecDiv2ulsv(uintl2 v_out, ui64 const s_lh, uintl2 const v_rh)
{
	v_out[0] = s_lh / v_rh[0];
	v_out[1] = s_lh / v_rh[1];
	return v_out;
}

ijk_inl uintlv ijkVecDivSafe2ulsv(uintl2 v_out, ui64 const s_lh, uintl2 const v_rh)
{
	v_out[0] = ijk_divide_safe_int(s_lh, v_rh[0]);
	v_out[1] = ijk_divide_safe_int(s_lh, v_rh[1]);
	return v_out;
}

ijk_inl uintlv ijkVecMod2ulsv(uintl2 v_out, ui64 const s_lh, uintl2 const v_rh)
{
	v_out[0] = s_lh % v_rh[0];
	v_out[1] = s_lh % v_rh[1];
	return v_out;
}

ijk_inl uintlv ijkVecModSafe2ulsv(uintl2 v_out, ui64 const s_lh, uintl2 const v_rh)
{
	v_out[0] = ijk_modulo_safe_int(s_lh, v_rh[0]);
	v_out[1] = ijk_modulo_safe_int(s_lh, v_rh[1]);
	return v_out;
}

ijk_inl uintlv ijkVecBitAnd2ulsv(uintl2 v_out, ui64 const s_lh, uintl2 const v_rh)
{
	v_out[0] = (s_lh & v_rh[0]);
	v_out[1] = (s_lh & v_rh[1]);
	return v_out;
}

ijk_inl uintlv ijkVecBitNand2ulsv(uintl2 v_out, ui64 const s_lh, uintl2 const v_rh)
{
	v_out[0] = ~(s_lh & v_rh[0]);
	v_out[1] = ~(s_lh & v_rh[1]);
	return v_out;
}

ijk_inl uintlv ijkVecBitOr2ulsv(uintl2 v_out, ui64 const s_lh, uintl2 const v_rh)
{
	v_out[0] = (s_lh | v_rh[0]);
	v_out[1] = (s_lh | v_rh[1]);
	return v_out;
}

ijk_inl uintlv ijkVecBitNor2ulsv(uintl2 v_out, ui64 const s_lh, uintl2 const v_rh)
{
	v_out[0] = ~(s_lh | v_rh[0]);
	v_out[1] = ~(s_lh | v_rh[1]);
	return v_out;
}

ijk_inl uintlv ijkVecBitXor2ulsv(uintl2 v_out, ui64 const s_lh, uintl2 const v_rh)
{
	v_out[0] = (s_lh ^ v_rh[0]);
	v_out[1] = (s_lh ^ v_rh[1]);
	return v_out;
}

ijk_inl uintlv ijkVecBitXnor2ulsv(uintl2 v_out, ui64 const s_lh, uintl2 const v_rh)
{
	v_out[0] = ~(s_lh ^ v_rh[0]);
	v_out[1] = ~(s_lh ^ v_rh[1]);
	return v_out;
}

ijk_inl uintlv ijkVecBitShiftLeft2ulsv(uintl2 v_out, ui64 const s_lh, uintl2 const v_rh)
{
	v_out[0] = (s_lh << v_rh[0]);
	v_out[1] = (s_lh << v_rh[1]);
	return v_out;
}

ijk_inl uintlv ijkVecBitShiftRight2ulsv(uintl2 v_out, ui64 const s_lh, uintl2 const v_rh)
{
	v_out[0] = (s_lh >> v_rh[0]);
	v_out[1] = (s_lh >> v_rh[1]);
	return v_out;
}

ijk_inl boolv ijkVecEqual2ulsv(bool2 bv_out, ui64 const s_lh, uintl2 const v_rh)
{
	bv_out[0] = (s_lh == v_rh[0]);
	bv_out[1] = (s_lh == v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal2ulsv(bool2 bv_out, ui64 const s_lh, uintl2 const v_rh)
{
	bv_out[0] = (s_lh != v_rh[0]);
	bv_out[1] = (s_lh != v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual2ulsv(bool2 bv_out, ui64 const s_lh, uintl2 const v_rh)
{
	bv_out[0] = (s_lh <= v_rh[0]);
	bv_out[1] = (s_lh <= v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual2ulsv(bool2 bv_out, ui64 const s_lh, uintl2 const v_rh)
{
	bv_out[0] = (s_lh >= v_rh[0]);
	bv_out[1] = (s_lh >= v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecLess2ulsv(bool2 bv_out, ui64 const s_lh, uintl2 const v_rh)
{
	bv_out[0] = (s_lh < v_rh[0]);
	bv_out[1] = (s_lh < v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater2ulsv(bool2 bv_out, ui64 const s_lh, uintl2 const v_rh)
{
	bv_out[0] = (s_lh > v_rh[0]);
	bv_out[1] = (s_lh > v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd2ulsv(bool2 bv_out, ui64 const s_lh, uintl2 const v_rh)
{
	bv_out[0] = (s_lh && v_rh[0]);
	bv_out[1] = (s_lh && v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecNand2ulsv(bool2 bv_out, ui64 const s_lh, uintl2 const v_rh)
{
	bv_out[0] = !(s_lh && v_rh[0]);
	bv_out[1] = !(s_lh && v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecOr2ulsv(bool2 bv_out, ui64 const s_lh, uintl2 const v_rh)
{
	bv_out[0] = (s_lh || v_rh[0]);
	bv_out[1] = (s_lh || v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecNor2ulsv(bool2 bv_out, ui64 const s_lh, uintl2 const v_rh)
{
	bv_out[0] = !(s_lh || v_rh[0]);
	bv_out[1] = !(s_lh || v_rh[1]);
	return bv_out;
}

ijk_inl ui64 ijkVecDot2ulv(uintl2 const v_lh, uintl2 const v_rh)
{
	return (v_lh[0] * v_rh[0] + v_lh[1] * v_rh[1]);
}

ijk_inl ui64 ijkVecCross2ulv(uintl2 const v_lh, uintl2 const v_rh)
{
	return (v_lh[0] * v_rh[1] - v_lh[1] * v_rh[0]);
}


//-----------------------------------------------------------------------------

ijk_inl uintlv ijkVecInit3ulv(uintl3 v_out)
{
	v_out[0] = v_out[1] = v_out[2] = 0;
	return v_out;
}

ijk_inl uintlv ijkVecInitElems3ulv(uintl3 v_out, ui64 const x, ui64 const y, ui64 const z)
{
	v_out[0] = x;
	v_out[1] = y;
	v_out[2] = z;
	return v_out;
}

ijk_inl uintlv ijkVecCopy3ulv(uintl3 v_out, uintl3 const v_in)
{
	v_out[0] = +v_in[0];
	v_out[1] = +v_in[1];
	v_out[2] = +v_in[2];
	return v_out;
}

ijk_inl intlv ijkVecNegate3ulv(intl3 v_out, uintl3 const v_in)
{
	v_out[0] = -(i64)v_in[0];
	v_out[1] = -(i64)v_in[1];
	v_out[2] = -(i64)v_in[2];
	return v_out;
}

ijk_inl uintlv ijkVecBitNot3ulv(uintl3 v_out, uintl3 const v_in)
{
	v_out[0] = ~v_in[0];
	v_out[1] = ~v_in[1];
	v_out[2] = ~v_in[2];
	return v_out;
}

ijk_inl boolv ijkVecNot3ulv(bool3 bv_out, uintl3 const v_in)
{
	bv_out[0] = !v_in[0];
	bv_out[1] = !v_in[1];
	bv_out[2] = !v_in[2];
	return bv_out;
}

ijk_inl uintlv ijkVecAdd3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh)
{
	v_out[0] = v_lh[0] + v_rh[0];
	v_out[1] = v_lh[1] + v_rh[1];
	v_out[2] = v_lh[2] + v_rh[2];
	return v_out;
}

ijk_inl uintlv ijkVecSub3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh)
{
	v_out[0] = v_lh[0] - v_rh[0];
	v_out[1] = v_lh[1] - v_rh[1];
	v_out[2] = v_lh[2] - v_rh[2];
	return v_out;
}

ijk_inl uintlv ijkVecMul3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh)
{
	v_out[0] = v_lh[0] * v_rh[0];
	v_out[1] = v_lh[1] * v_rh[1];
	v_out[2] = v_lh[2] * v_rh[2];
	return v_out;
}

ijk_inl uintlv ijkVecDiv3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh)
{
	v_out[0] = v_lh[0] / v_rh[0];
	v_out[1] = v_lh[1] / v_rh[1];
	v_out[2] = v_lh[2] / v_rh[2];
	return v_out;
}

ijk_inl uintlv ijkVecDivSafe3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh)
{
	v_out[0] = ijk_divide_safe_int(v_lh[0], v_rh[0]);
	v_out[1] = ijk_divide_safe_int(v_lh[1], v_rh[1]);
	v_out[2] = ijk_divide_safe_int(v_lh[2], v_rh[2]);
	return v_out;
}

ijk_inl uintlv ijkVecMod3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh)
{
	v_out[0] = v_lh[0] % v_rh[0];
	v_out[1] = v_lh[1] % v_rh[1];
	v_out[2] = v_lh[2] % v_rh[2];
	return v_out;
}

ijk_inl uintlv ijkVecModSafe3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh)
{
	v_out[0] = ijk_modulo_safe_int(v_lh[0], v_rh[0]);
	v_out[1] = ijk_modulo_safe_int(v_lh[1], v_rh[1]);
	v_out[2] = ijk_modulo_safe_int(v_lh[2], v_rh[2]);
	return v_out;
}

ijk_inl uintlv ijkVecBitAnd3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh)
{
	v_out[0] = (v_lh[0] & v_rh[0]);
	v_out[1] = (v_lh[1] & v_rh[1]);
	v_out[2] = (v_lh[2] & v_rh[2]);
	return v_out;
}

ijk_inl uintlv ijkVecBitNand3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh)
{
	v_out[0] = ~(v_lh[0] & v_rh[0]);
	v_out[1] = ~(v_lh[1] & v_rh[1]);
	v_out[2] = ~(v_lh[2] & v_rh[2]);
	return v_out;
}

ijk_inl uintlv ijkVecBitOr3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh)
{
	v_out[0] = (v_lh[0] | v_rh[0]);
	v_out[1] = (v_lh[1] | v_rh[1]);
	v_out[2] = (v_lh[2] | v_rh[2]);
	return v_out;
}

ijk_inl uintlv ijkVecBitNor3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh)
{
	v_out[0] = ~(v_lh[0] | v_rh[0]);
	v_out[1] = ~(v_lh[1] | v_rh[1]);
	v_out[2] = ~(v_lh[2] | v_rh[2]);
	return v_out;
}

ijk_inl uintlv ijkVecBitXor3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh)
{
	v_out[0] = (v_lh[0] ^ v_rh[0]);
	v_out[1] = (v_lh[1] ^ v_rh[1]);
	v_out[2] = (v_lh[2] ^ v_rh[2]);
	return v_out;
}

ijk_inl uintlv ijkVecBitXnor3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh)
{
	v_out[0] = ~(v_lh[0] ^ v_rh[0]);
	v_out[1] = ~(v_lh[1] ^ v_rh[1]);
	v_out[2] = ~(v_lh[2] ^ v_rh[2]);
	return v_out;
}

ijk_inl uintlv ijkVecBitShiftLeft3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh)
{
	v_out[0] = (v_lh[0] << v_rh[0]);
	v_out[1] = (v_lh[1] << v_rh[1]);
	v_out[2] = (v_lh[2] << v_rh[2]);
	return v_out;
}

ijk_inl uintlv ijkVecBitShiftRight3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh)
{
	v_out[0] = (v_lh[0] >> v_rh[0]);
	v_out[1] = (v_lh[1] >> v_rh[1]);
	v_out[2] = (v_lh[2] >> v_rh[2]);
	return v_out;
}

ijk_inl boolv ijkVecEqual3ulv(bool3 bv_out, uintl3 const v_lh, uintl3 const v_rh)
{
	bv_out[0] = (v_lh[0] == v_rh[0]);
	bv_out[1] = (v_lh[1] == v_rh[1]);
	bv_out[2] = (v_lh[2] == v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal3ulv(bool3 bv_out, uintl3 const v_lh, uintl3 const v_rh)
{
	bv_out[0] = (v_lh[0] != v_rh[0]);
	bv_out[1] = (v_lh[1] != v_rh[1]);
	bv_out[2] = (v_lh[2] != v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual3ulv(bool3 bv_out, uintl3 const v_lh, uintl3 const v_rh)
{
	bv_out[0] = (v_lh[0] <= v_rh[0]);
	bv_out[1] = (v_lh[1] <= v_rh[1]);
	bv_out[2] = (v_lh[2] <= v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual3ulv(bool3 bv_out, uintl3 const v_lh, uintl3 const v_rh)
{
	bv_out[0] = (v_lh[0] >= v_rh[0]);
	bv_out[1] = (v_lh[1] >= v_rh[1]);
	bv_out[2] = (v_lh[2] >= v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecLess3ulv(bool3 bv_out, uintl3 const v_lh, uintl3 const v_rh)
{
	bv_out[0] = (v_lh[0] < v_rh[0]);
	bv_out[1] = (v_lh[1] < v_rh[1]);
	bv_out[2] = (v_lh[2] < v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater3ulv(bool3 bv_out, uintl3 const v_lh, uintl3 const v_rh)
{
	bv_out[0] = (v_lh[0] > v_rh[0]);
	bv_out[1] = (v_lh[1] > v_rh[1]);
	bv_out[2] = (v_lh[2] > v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd3ulv(bool3 bv_out, uintl3 const v_lh, uintl3 const v_rh)
{
	bv_out[0] = (v_lh[0] && v_rh[0]);
	bv_out[1] = (v_lh[1] && v_rh[1]);
	bv_out[2] = (v_lh[2] && v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecNand3ulv(bool3 bv_out, uintl3 const v_lh, uintl3 const v_rh)
{
	bv_out[0] = !(v_lh[0] && v_rh[0]);
	bv_out[1] = !(v_lh[1] && v_rh[1]);
	bv_out[2] = !(v_lh[2] && v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecOr3ulv(bool3 bv_out, uintl3 const v_lh, uintl3 const v_rh)
{
	bv_out[0] = (v_lh[0] || v_rh[0]);
	bv_out[1] = (v_lh[1] || v_rh[1]);
	bv_out[2] = (v_lh[2] || v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecNor3ulv(bool3 bv_out, uintl3 const v_lh, uintl3 const v_rh)
{
	bv_out[0] = !(v_lh[0] || v_rh[0]);
	bv_out[1] = !(v_lh[1] || v_rh[1]);
	bv_out[2] = !(v_lh[2] || v_rh[2]);
	return bv_out;
}

ijk_inl uintlv ijkVecCopy3ulvz(uintl3 v_out, uintl2 const v_xy, ui64 const z)
{
	v_out[0] = v_xy[0];
	v_out[1] = v_xy[1];
	v_out[2] = z;
	return v_out;
}

ijk_inl uintlv ijkVecCopy3ulvs(uintl3 v_out, ui64 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = +s_in;
	return v_out;
}

ijk_inl intlv ijkVecNegate3ulvs(intl3 v_out, ui64 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = -(i64)s_in;
	return v_out;
}

ijk_inl uintlv ijkVecBitNot3ulvs(uintl3 v_out, ui64 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = ~s_in;
	return v_out;
}

ijk_inl boolv ijkVecNot3ulvs(bool3 bv_out, ui64 const s_in)
{
	bv_out[0] = bv_out[1] = bv_out[2] = !s_in;
	return bv_out;
}

ijk_inl uintlv ijkVecAdd3ulvs(uintl3 v_out, uintl3 const v_lh, ui64 const s_rh)
{
	v_out[0] = v_lh[0] + s_rh;
	v_out[1] = v_lh[1] + s_rh;
	v_out[2] = v_lh[2] + s_rh;
	return v_out;
}

ijk_inl uintlv ijkVecSub3ulvs(uintl3 v_out, uintl3 const v_lh, ui64 const s_rh)
{
	v_out[0] = v_lh[0] - s_rh;
	v_out[1] = v_lh[1] - s_rh;
	v_out[2] = v_lh[2] - s_rh;
	return v_out;
}

ijk_inl uintlv ijkVecMul3ulvs(uintl3 v_out, uintl3 const v_lh, ui64 const s_rh)
{
	v_out[0] = v_lh[0] * s_rh;
	v_out[1] = v_lh[1] * s_rh;
	v_out[2] = v_lh[2] * s_rh;
	return v_out;
}

ijk_inl uintlv ijkVecDiv3ulvs(uintl3 v_out, uintl3 const v_lh, ui64 const s_rh)
{
	v_out[0] = v_lh[0] / s_rh;
	v_out[1] = v_lh[1] / s_rh;
	v_out[2] = v_lh[2] / s_rh;
	return v_out;
}

ijk_inl uintlv ijkVecDivSafe3ulvs(uintl3 v_out, uintl3 const v_lh, ui64 const s_rh)
{
	if (s_rh)
	{
		v_out[0] = v_lh[0] / s_rh;
		v_out[1] = v_lh[1] / s_rh;
		v_out[2] = v_lh[2] / s_rh;
	}
	else
		v_out[0] = v_out[1] = v_out[2] = 0;
	return v_out;
}

ijk_inl uintlv ijkVecMod3ulvs(uintl3 v_out, uintl3 const v_lh, ui64 const s_rh)
{
	v_out[0] = v_lh[0] % s_rh;
	v_out[1] = v_lh[1] % s_rh;
	v_out[2] = v_lh[2] % s_rh;
	return v_out;
}

ijk_inl uintlv ijkVecModSafe3ulvs(uintl3 v_out, uintl3 const v_lh, ui64 const s_rh)
{
	if (s_rh)
	{
		v_out[0] = v_lh[0] % s_rh;
		v_out[1] = v_lh[1] % s_rh;
		v_out[2] = v_lh[2] % s_rh;
		return v_out;
	}
	return ijkVecCopy3ulv(v_out, v_lh);
}

ijk_inl uintlv ijkVecBitAnd3ulvs(uintl3 v_out, uintl3 const v_lh, ui64 const s_rh)
{
	v_out[0] = (v_lh[0] & s_rh);
	v_out[1] = (v_lh[1] & s_rh);
	v_out[2] = (v_lh[2] & s_rh);
	return v_out;
}

ijk_inl uintlv ijkVecBitNand3ulvs(uintl3 v_out, uintl3 const v_lh, ui64 const s_rh)
{
	v_out[0] = ~(v_lh[0] & s_rh);
	v_out[1] = ~(v_lh[1] & s_rh);
	v_out[2] = ~(v_lh[2] & s_rh);
	return v_out;
}

ijk_inl uintlv ijkVecBitOr3ulvs(uintl3 v_out, uintl3 const v_lh, ui64 const s_rh)
{
	v_out[0] = (v_lh[0] | s_rh);
	v_out[1] = (v_lh[1] | s_rh);
	v_out[2] = (v_lh[2] | s_rh);
	return v_out;
}

ijk_inl uintlv ijkVecBitNor3ulvs(uintl3 v_out, uintl3 const v_lh, ui64 const s_rh)
{
	v_out[0] = ~(v_lh[0] | s_rh);
	v_out[1] = ~(v_lh[1] | s_rh);
	v_out[2] = ~(v_lh[2] | s_rh);
	return v_out;
}

ijk_inl uintlv ijkVecBitXor3ulvs(uintl3 v_out, uintl3 const v_lh, ui64 const s_rh)
{
	v_out[0] = (v_lh[0] ^ s_rh);
	v_out[1] = (v_lh[1] ^ s_rh);
	v_out[2] = (v_lh[2] ^ s_rh);
	return v_out;
}

ijk_inl uintlv ijkVecBitXnor3ulvs(uintl3 v_out, uintl3 const v_lh, ui64 const s_rh)
{
	v_out[0] = ~(v_lh[0] ^ s_rh);
	v_out[1] = ~(v_lh[1] ^ s_rh);
	v_out[2] = ~(v_lh[2] ^ s_rh);
	return v_out;
}

ijk_inl uintlv ijkVecBitShiftLeft3ulvs(uintl3 v_out, uintl3 const v_lh, ui64 const s_rh)
{
	v_out[0] = (v_lh[0] << s_rh);
	v_out[1] = (v_lh[1] << s_rh);
	v_out[2] = (v_lh[2] << s_rh);
	return v_out;
}

ijk_inl uintlv ijkVecBitShiftRight3ulvs(uintl3 v_out, uintl3 const v_lh, ui64 const s_rh)
{
	v_out[0] = (v_lh[0] >> s_rh);
	v_out[1] = (v_lh[1] >> s_rh);
	v_out[2] = (v_lh[2] >> s_rh);
	return v_out;
}

ijk_inl boolv ijkVecEqual3ulvs(bool3 bv_out, uintl3 const v_lh, ui64 const s_rh)
{
	bv_out[0] = (v_lh[0] == s_rh);
	bv_out[1] = (v_lh[1] == s_rh);
	bv_out[2] = (v_lh[2] == s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecInequal3ulvs(bool3 bv_out, uintl3 const v_lh, ui64 const s_rh)
{
	bv_out[0] = (v_lh[0] != s_rh);
	bv_out[1] = (v_lh[1] != s_rh);
	bv_out[2] = (v_lh[2] != s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual3ulvs(bool3 bv_out, uintl3 const v_lh, ui64 const s_rh)
{
	bv_out[0] = (v_lh[0] <= s_rh);
	bv_out[1] = (v_lh[1] <= s_rh);
	bv_out[2] = (v_lh[2] <= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual3ulvs(bool3 bv_out, uintl3 const v_lh, ui64 const s_rh)
{
	bv_out[0] = (v_lh[0] >= s_rh);
	bv_out[1] = (v_lh[1] >= s_rh);
	bv_out[2] = (v_lh[2] >= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLess3ulvs(bool3 bv_out, uintl3 const v_lh, ui64 const s_rh)
{
	bv_out[0] = (v_lh[0] < s_rh);
	bv_out[1] = (v_lh[1] < s_rh);
	bv_out[2] = (v_lh[2] < s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreater3ulvs(bool3 bv_out, uintl3 const v_lh, ui64 const s_rh)
{
	bv_out[0] = (v_lh[0] > s_rh);
	bv_out[1] = (v_lh[1] > s_rh);
	bv_out[2] = (v_lh[2] > s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecAnd3ulvs(bool3 bv_out, uintl3 const v_lh, ui64 const s_rh)
{
	bv_out[0] = (v_lh[0] && s_rh);
	bv_out[1] = (v_lh[1] && s_rh);
	bv_out[2] = (v_lh[2] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNand3ulvs(bool3 bv_out, uintl3 const v_lh, ui64 const s_rh)
{
	bv_out[0] = !(v_lh[0] && s_rh);
	bv_out[1] = !(v_lh[1] && s_rh);
	bv_out[2] = !(v_lh[2] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecOr3ulvs(bool3 bv_out, uintl3 const v_lh, ui64 const s_rh)
{
	bv_out[0] = (v_lh[0] || s_rh);
	bv_out[1] = (v_lh[1] || s_rh);
	bv_out[2] = (v_lh[2] || s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNor3ulvs(bool3 bv_out, uintl3 const v_lh, ui64 const s_rh)
{
	bv_out[0] = !(v_lh[0] || s_rh);
	bv_out[1] = !(v_lh[1] || s_rh);
	bv_out[2] = !(v_lh[2] || s_rh);
	return bv_out;
}

ijk_inl uintlv ijkVecCopy3ulxv(uintl3 v_out, ui64 const x, uintl2 const v_yz)
{
	v_out[0] = x;
	v_out[1] = v_yz[0];
	v_out[2] = v_yz[1];
	return v_out;
}

ijk_inl uintlv ijkVecAdd3ulsv(uintl3 v_out, ui64 const s_lh, uintl3 const v_rh)
{
	v_out[0] = s_lh + v_rh[0];
	v_out[1] = s_lh + v_rh[1];
	v_out[2] = s_lh + v_rh[2];
	return v_out;
}

ijk_inl uintlv ijkVecSub3ulsv(uintl3 v_out, ui64 const s_lh, uintl3 const v_rh)
{
	v_out[0] = s_lh - v_rh[0];
	v_out[1] = s_lh - v_rh[1];
	v_out[2] = s_lh - v_rh[2];
	return v_out;
}

ijk_inl uintlv ijkVecMul3ulsv(uintl3 v_out, ui64 const s_lh, uintl3 const v_rh)
{
	v_out[0] = s_lh * v_rh[0];
	v_out[1] = s_lh * v_rh[1];
	v_out[2] = s_lh * v_rh[2];
	return v_out;
}

ijk_inl uintlv ijkVecDiv3ulsv(uintl3 v_out, ui64 const s_lh, uintl3 const v_rh)
{
	v_out[0] = s_lh / v_rh[0];
	v_out[1] = s_lh / v_rh[1];
	v_out[2] = s_lh / v_rh[2];
	return v_out;
}

ijk_inl uintlv ijkVecDivSafe3ulsv(uintl3 v_out, ui64 const s_lh, uintl3 const v_rh)
{
	v_out[0] = ijk_divide_safe_int(s_lh, v_rh[0]);
	v_out[1] = ijk_divide_safe_int(s_lh, v_rh[1]);
	v_out[2] = ijk_divide_safe_int(s_lh, v_rh[2]);
	return v_out;
}

ijk_inl uintlv ijkVecMod3ulsv(uintl3 v_out, ui64 const s_lh, uintl3 const v_rh)
{
	v_out[0] = s_lh % v_rh[0];
	v_out[1] = s_lh % v_rh[1];
	v_out[2] = s_lh % v_rh[2];
	return v_out;
}

ijk_inl uintlv ijkVecModSafe3ulsv(uintl3 v_out, ui64 const s_lh, uintl3 const v_rh)
{
	v_out[0] = ijk_modulo_safe_int(s_lh, v_rh[0]);
	v_out[1] = ijk_modulo_safe_int(s_lh, v_rh[1]);
	v_out[2] = ijk_modulo_safe_int(s_lh, v_rh[2]);
	return v_out;
}

ijk_inl uintlv ijkVecBitAnd3ulsv(uintl3 v_out, ui64 const s_lh, uintl3 const v_rh)
{
	v_out[0] = (s_lh & v_rh[0]);
	v_out[1] = (s_lh & v_rh[1]);
	v_out[2] = (s_lh & v_rh[2]);
	return v_out;
}

ijk_inl uintlv ijkVecBitNand3ulsv(uintl3 v_out, ui64 const s_lh, uintl3 const v_rh)
{
	v_out[0] = ~(s_lh & v_rh[0]);
	v_out[1] = ~(s_lh & v_rh[1]);
	v_out[2] = ~(s_lh & v_rh[2]);
	return v_out;
}

ijk_inl uintlv ijkVecBitOr3ulsv(uintl3 v_out, ui64 const s_lh, uintl3 const v_rh)
{
	v_out[0] = (s_lh | v_rh[0]);
	v_out[1] = (s_lh | v_rh[1]);
	v_out[2] = (s_lh | v_rh[2]);
	return v_out;
}

ijk_inl uintlv ijkVecBitNor3ulsv(uintl3 v_out, ui64 const s_lh, uintl3 const v_rh)
{
	v_out[0] = ~(s_lh | v_rh[0]);
	v_out[1] = ~(s_lh | v_rh[1]);
	v_out[2] = ~(s_lh | v_rh[2]);
	return v_out;
}

ijk_inl uintlv ijkVecBitXor3ulsv(uintl3 v_out, ui64 const s_lh, uintl3 const v_rh)
{
	v_out[0] = (s_lh ^ v_rh[0]);
	v_out[1] = (s_lh ^ v_rh[1]);
	v_out[2] = (s_lh ^ v_rh[2]);
	return v_out;
}

ijk_inl uintlv ijkVecBitXnor3ulsv(uintl3 v_out, ui64 const s_lh, uintl3 const v_rh)
{
	v_out[0] = ~(s_lh ^ v_rh[0]);
	v_out[1] = ~(s_lh ^ v_rh[1]);
	v_out[2] = ~(s_lh ^ v_rh[2]);
	return v_out;
}

ijk_inl uintlv ijkVecBitShiftLeft3ulsv(uintl3 v_out, ui64 const s_lh, uintl3 const v_rh)
{
	v_out[0] = (s_lh << v_rh[0]);
	v_out[1] = (s_lh << v_rh[1]);
	v_out[2] = (s_lh << v_rh[2]);
	return v_out;
}

ijk_inl uintlv ijkVecBitShiftRight3ulsv(uintl3 v_out, ui64 const s_lh, uintl3 const v_rh)
{
	v_out[0] = (s_lh >> v_rh[0]);
	v_out[1] = (s_lh >> v_rh[1]);
	v_out[2] = (s_lh >> v_rh[2]);
	return v_out;
}

ijk_inl boolv ijkVecEqual3ulsv(bool3 bv_out, ui64 const s_lh, uintl3 const v_rh)
{
	bv_out[0] = (s_lh == v_rh[0]);
	bv_out[1] = (s_lh == v_rh[1]);
	bv_out[2] = (s_lh == v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal3ulsv(bool3 bv_out, ui64 const s_lh, uintl3 const v_rh)
{
	bv_out[0] = (s_lh != v_rh[0]);
	bv_out[1] = (s_lh != v_rh[1]);
	bv_out[2] = (s_lh != v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual3ulsv(bool3 bv_out, ui64 const s_lh, uintl3 const v_rh)
{
	bv_out[0] = (s_lh <= v_rh[0]);
	bv_out[1] = (s_lh <= v_rh[1]);
	bv_out[2] = (s_lh <= v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual3ulsv(bool3 bv_out, ui64 const s_lh, uintl3 const v_rh)
{
	bv_out[0] = (s_lh >= v_rh[0]);
	bv_out[1] = (s_lh >= v_rh[1]);
	bv_out[2] = (s_lh >= v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecLess3ulsv(bool3 bv_out, ui64 const s_lh, uintl3 const v_rh)
{
	bv_out[0] = (s_lh < v_rh[0]);
	bv_out[1] = (s_lh < v_rh[1]);
	bv_out[2] = (s_lh < v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater3ulsv(bool3 bv_out, ui64 const s_lh, uintl3 const v_rh)
{
	bv_out[0] = (s_lh > v_rh[0]);
	bv_out[1] = (s_lh > v_rh[1]);
	bv_out[2] = (s_lh > v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd3ulsv(bool3 bv_out, ui64 const s_lh, uintl3 const v_rh)
{
	bv_out[0] = (s_lh && v_rh[0]);
	bv_out[1] = (s_lh && v_rh[1]);
	bv_out[2] = (s_lh && v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecNand3ulsv(bool3 bv_out, ui64 const s_lh, uintl3 const v_rh)
{
	bv_out[0] = !(s_lh && v_rh[0]);
	bv_out[1] = !(s_lh && v_rh[1]);
	bv_out[2] = !(s_lh && v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecOr3ulsv(bool3 bv_out, ui64 const s_lh, uintl3 const v_rh)
{
	bv_out[0] = (s_lh || v_rh[0]);
	bv_out[1] = (s_lh || v_rh[1]);
	bv_out[2] = (s_lh || v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecNor3ulsv(bool3 bv_out, ui64 const s_lh, uintl3 const v_rh)
{
	bv_out[0] = !(s_lh || v_rh[0]);
	bv_out[1] = !(s_lh || v_rh[1]);
	bv_out[2] = !(s_lh || v_rh[2]);
	return bv_out;
}

ijk_inl ui64 ijkVecDot3ulv(uintl3 const v_lh, uintl3 const v_rh)
{
	return (v_lh[0] * v_rh[0] + v_lh[1] * v_rh[1] + v_lh[2] * v_rh[2]);
}

ijk_inl uintlv ijkVecCross3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh)
{
	v_out[0] = (v_lh[1] * v_rh[2] - v_lh[2] * v_rh[1]);
	v_out[1] = (v_lh[2] * v_rh[0] - v_lh[0] * v_rh[2]);
	v_out[2] = (v_lh[0] * v_rh[1] - v_lh[1] * v_rh[0]);
	return v_out;
}


//-----------------------------------------------------------------------------

ijk_inl uintlv ijkVecInit4ulv(uintl4 v_out)
{
	v_out[0] = v_out[1] = v_out[2] = v_out[3] = 0;
	return v_out;
}

ijk_inl uintlv ijkVecInitElems4ulv(uintl4 v_out, ui64 const x, ui64 const y, ui64 const z, ui64 const w)
{
	v_out[0] = x;
	v_out[1] = y;
	v_out[2] = z;
	v_out[3] = w;
	return v_out;
}

ijk_inl uintlv ijkVecCopy4ulxvw(uintl4 v_out, ui64 const x, uintl2 const v_yz, ui64 const w)
{
	v_out[0] = x;
	v_out[1] = v_yz[0];
	v_out[2] = v_yz[1];
	v_out[3] = w;
	return v_out;
}

ijk_inl uintlv ijkVecCopy4ulv2(uintl4 v_out, uintl2 const v_xy, uintl2 const v_zw)
{
	v_out[0] = v_xy[0];
	v_out[1] = v_xy[1];
	v_out[2] = v_zw[0];
	v_out[3] = v_zw[1];
	return v_out;
}

ijk_inl uintlv ijkVecCopy4ulv(uintl4 v_out, uintl4 const v_in)
{
	v_out[0] = +v_in[0];
	v_out[1] = +v_in[1];
	v_out[2] = +v_in[2];
	v_out[3] = +v_in[3];
	return v_out;
}

ijk_inl intlv ijkVecNegate4ulv(intl4 v_out, uintl4 const v_in)
{
	v_out[0] = -(i64)v_in[0];
	v_out[1] = -(i64)v_in[1];
	v_out[2] = -(i64)v_in[2];
	v_out[3] = -(i64)v_in[3];
	return v_out;
}

ijk_inl uintlv ijkVecBitNot4ulv(uintl4 v_out, uintl4 const v_in)
{
	v_out[0] = ~v_in[0];
	v_out[1] = ~v_in[1];
	v_out[2] = ~v_in[2];
	v_out[3] = ~v_in[3];
	return v_out;
}

ijk_inl boolv ijkVecNot4ulv(bool4 bv_out, uintl4 const v_in)
{
	bv_out[0] = !v_in[0];
	bv_out[1] = !v_in[1];
	bv_out[2] = !v_in[2];
	bv_out[3] = !v_in[3];
	return bv_out;
}

ijk_inl uintlv ijkVecAdd4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh)
{
	v_out[0] = v_lh[0] + v_rh[0];
	v_out[1] = v_lh[1] + v_rh[1];
	v_out[2] = v_lh[2] + v_rh[2];
	v_out[3] = v_lh[3] + v_rh[3];
	return v_out;
}

ijk_inl uintlv ijkVecSub4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh)
{
	v_out[0] = v_lh[0] - v_rh[0];
	v_out[1] = v_lh[1] - v_rh[1];
	v_out[2] = v_lh[2] - v_rh[2];
	v_out[3] = v_lh[3] - v_rh[3];
	return v_out;
}

ijk_inl uintlv ijkVecMul4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh)
{
	v_out[0] = v_lh[0] * v_rh[0];
	v_out[1] = v_lh[1] * v_rh[1];
	v_out[2] = v_lh[2] * v_rh[2];
	v_out[3] = v_lh[3] * v_rh[3];
	return v_out;
}

ijk_inl uintlv ijkVecDiv4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh)
{
	v_out[0] = v_lh[0] / v_rh[0];
	v_out[1] = v_lh[1] / v_rh[1];
	v_out[2] = v_lh[2] / v_rh[2];
	v_out[3] = v_lh[3] / v_rh[3];
	return v_out;
}

ijk_inl uintlv ijkVecDivSafe4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh)
{
	v_out[0] = ijk_divide_safe_int(v_lh[0], v_rh[0]);
	v_out[1] = ijk_divide_safe_int(v_lh[1], v_rh[1]);
	v_out[2] = ijk_divide_safe_int(v_lh[2], v_rh[2]);
	v_out[3] = ijk_divide_safe_int(v_lh[3], v_rh[3]);
	return v_out;
}

ijk_inl uintlv ijkVecMod4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh)
{
	v_out[0] = v_lh[0] % v_rh[0];
	v_out[1] = v_lh[1] % v_rh[1];
	v_out[2] = v_lh[2] % v_rh[2];
	v_out[3] = v_lh[3] % v_rh[3];
	return v_out;
}

ijk_inl uintlv ijkVecModSafe4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh)
{
	v_out[0] = ijk_modulo_safe_int(v_lh[0], v_rh[0]);
	v_out[1] = ijk_modulo_safe_int(v_lh[1], v_rh[1]);
	v_out[2] = ijk_modulo_safe_int(v_lh[2], v_rh[2]);
	v_out[3] = ijk_modulo_safe_int(v_lh[3], v_rh[3]);
	return v_out;
}

ijk_inl uintlv ijkVecBitAnd4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh)
{
	v_out[0] = (v_lh[0] & v_rh[0]);
	v_out[1] = (v_lh[1] & v_rh[1]);
	v_out[2] = (v_lh[2] & v_rh[2]);
	v_out[3] = (v_lh[3] & v_rh[3]);
	return v_out;
}

ijk_inl uintlv ijkVecBitNand4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh)
{
	v_out[0] = ~(v_lh[0] & v_rh[0]);
	v_out[1] = ~(v_lh[1] & v_rh[1]);
	v_out[2] = ~(v_lh[2] & v_rh[2]);
	v_out[3] = ~(v_lh[3] & v_rh[3]);
	return v_out;
}

ijk_inl uintlv ijkVecBitOr4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh)
{
	v_out[0] = (v_lh[0] | v_rh[0]);
	v_out[1] = (v_lh[1] | v_rh[1]);
	v_out[2] = (v_lh[2] | v_rh[2]);
	v_out[3] = (v_lh[3] | v_rh[3]);
	return v_out;
}

ijk_inl uintlv ijkVecBitNor4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh)
{
	v_out[0] = ~(v_lh[0] | v_rh[0]);
	v_out[1] = ~(v_lh[1] | v_rh[1]);
	v_out[2] = ~(v_lh[2] | v_rh[2]);
	v_out[3] = ~(v_lh[3] | v_rh[3]);
	return v_out;
}

ijk_inl uintlv ijkVecBitXor4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh)
{
	v_out[0] = (v_lh[0] ^ v_rh[0]);
	v_out[1] = (v_lh[1] ^ v_rh[1]);
	v_out[2] = (v_lh[2] ^ v_rh[2]);
	v_out[3] = (v_lh[3] ^ v_rh[3]);
	return v_out;
}

ijk_inl uintlv ijkVecBitXnor4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh)
{
	v_out[0] = ~(v_lh[0] ^ v_rh[0]);
	v_out[1] = ~(v_lh[1] ^ v_rh[1]);
	v_out[2] = ~(v_lh[2] ^ v_rh[2]);
	v_out[3] = ~(v_lh[3] ^ v_rh[3]);
	return v_out;
}

ijk_inl uintlv ijkVecBitShiftLeft4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh)
{
	v_out[0] = (v_lh[0] << v_rh[0]);
	v_out[1] = (v_lh[1] << v_rh[1]);
	v_out[2] = (v_lh[2] << v_rh[2]);
	v_out[3] = (v_lh[3] << v_rh[3]);
	return v_out;
}

ijk_inl uintlv ijkVecBitShiftRight4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh)
{
	v_out[0] = (v_lh[0] >> v_rh[0]);
	v_out[1] = (v_lh[1] >> v_rh[1]);
	v_out[2] = (v_lh[2] >> v_rh[2]);
	v_out[3] = (v_lh[3] >> v_rh[3]);
	return v_out;
}

ijk_inl boolv ijkVecEqual4ulv(bool4 bv_out, uintl4 const v_lh, uintl4 const v_rh)
{
	bv_out[0] = (v_lh[0] == v_rh[0]);
	bv_out[1] = (v_lh[1] == v_rh[1]);
	bv_out[2] = (v_lh[2] == v_rh[2]);
	bv_out[3] = (v_lh[3] == v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal4ulv(bool4 bv_out, uintl4 const v_lh, uintl4 const v_rh)
{
	bv_out[0] = (v_lh[0] != v_rh[0]);
	bv_out[1] = (v_lh[1] != v_rh[1]);
	bv_out[2] = (v_lh[2] != v_rh[2]);
	bv_out[3] = (v_lh[3] != v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual4ulv(bool4 bv_out, uintl4 const v_lh, uintl4 const v_rh)
{
	bv_out[0] = (v_lh[0] <= v_rh[0]);
	bv_out[1] = (v_lh[1] <= v_rh[1]);
	bv_out[2] = (v_lh[2] <= v_rh[2]);
	bv_out[3] = (v_lh[3] <= v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual4ulv(bool4 bv_out, uintl4 const v_lh, uintl4 const v_rh)
{
	bv_out[0] = (v_lh[0] >= v_rh[0]);
	bv_out[1] = (v_lh[1] >= v_rh[1]);
	bv_out[2] = (v_lh[2] >= v_rh[2]);
	bv_out[3] = (v_lh[3] >= v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecLess4ulv(bool4 bv_out, uintl4 const v_lh, uintl4 const v_rh)
{
	bv_out[0] = (v_lh[0] < v_rh[0]);
	bv_out[1] = (v_lh[1] < v_rh[1]);
	bv_out[2] = (v_lh[2] < v_rh[2]);
	bv_out[3] = (v_lh[3] < v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater4ulv(bool4 bv_out, uintl4 const v_lh, uintl4 const v_rh)
{
	bv_out[0] = (v_lh[0] > v_rh[0]);
	bv_out[1] = (v_lh[1] > v_rh[1]);
	bv_out[2] = (v_lh[2] > v_rh[2]);
	bv_out[3] = (v_lh[3] > v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd4ulv(bool4 bv_out, uintl4 const v_lh, uintl4 const v_rh)
{
	bv_out[0] = (v_lh[0] && v_rh[0]);
	bv_out[1] = (v_lh[1] && v_rh[1]);
	bv_out[2] = (v_lh[2] && v_rh[2]);
	bv_out[3] = (v_lh[3] && v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecNand4ulv(bool4 bv_out, uintl4 const v_lh, uintl4 const v_rh)
{
	bv_out[0] = !(v_lh[0] && v_rh[0]);
	bv_out[1] = !(v_lh[1] && v_rh[1]);
	bv_out[2] = !(v_lh[2] && v_rh[2]);
	bv_out[3] = !(v_lh[3] && v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecOr4ulv(bool4 bv_out, uintl4 const v_lh, uintl4 const v_rh)
{
	bv_out[0] = (v_lh[0] || v_rh[0]);
	bv_out[1] = (v_lh[1] || v_rh[1]);
	bv_out[2] = (v_lh[2] || v_rh[2]);
	bv_out[3] = (v_lh[3] || v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecNor4ulv(bool4 bv_out, uintl4 const v_lh, uintl4 const v_rh)
{
	bv_out[0] = !(v_lh[0] || v_rh[0]);
	bv_out[1] = !(v_lh[1] || v_rh[1]);
	bv_out[2] = !(v_lh[2] || v_rh[2]);
	bv_out[3] = !(v_lh[3] || v_rh[3]);
	return bv_out;
}

ijk_inl uintlv ijkVecCopy4ulvzw(uintl4 v_out, uintl2 const v_xy, ui64 const z, ui64 const w)
{
	v_out[0] = v_xy[0];
	v_out[1] = v_xy[1];
	v_out[2] = z;
	v_out[3] = w;
	return v_out;
}

ijk_inl uintlv ijkVecCopy4ulvw(uintl4 v_out, uintl3 const v_xyz, ui64 const w)
{
	v_out[0] = v_xyz[0];
	v_out[1] = v_xyz[1];
	v_out[2] = v_xyz[2];
	v_out[3] = w;
	return v_out;
}

ijk_inl uintlv ijkVecCopy4ulvs(uintl4 v_out, ui64 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = v_out[3] = +s_in;
	return v_out;
}

ijk_inl intlv ijkVecNegate4ulvs(intl4 v_out, ui64 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = v_out[3] = -(i64)s_in;
	return v_out;
}

ijk_inl uintlv ijkVecBitNot4ulvs(uintl4 v_out, ui64 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = v_out[3] = ~s_in;
	return v_out;
}

ijk_inl boolv ijkVecNot4ulvs(bool4 bv_out, ui64 const s_in)
{
	bv_out[0] = bv_out[1] = bv_out[2] = bv_out[3] = !s_in;
	return bv_out;
}

ijk_inl uintlv ijkVecAdd4ulvs(uintl4 v_out, uintl4 const v_lh, ui64 const s_rh)
{
	v_out[0] = v_lh[0] + s_rh;
	v_out[1] = v_lh[1] + s_rh;
	v_out[2] = v_lh[2] + s_rh;
	v_out[3] = v_lh[3] + s_rh;
	return v_out;
}

ijk_inl uintlv ijkVecSub4ulvs(uintl4 v_out, uintl4 const v_lh, ui64 const s_rh)
{
	v_out[0] = v_lh[0] - s_rh;
	v_out[1] = v_lh[1] - s_rh;
	v_out[2] = v_lh[2] - s_rh;
	v_out[3] = v_lh[3] - s_rh;
	return v_out;
}

ijk_inl uintlv ijkVecMul4ulvs(uintl4 v_out, uintl4 const v_lh, ui64 const s_rh)
{
	v_out[0] = v_lh[0] * s_rh;
	v_out[1] = v_lh[1] * s_rh;
	v_out[2] = v_lh[2] * s_rh;
	v_out[3] = v_lh[3] * s_rh;
	return v_out;
}

ijk_inl uintlv ijkVecDiv4ulvs(uintl4 v_out, uintl4 const v_lh, ui64 const s_rh)
{
	v_out[0] = v_lh[0] / s_rh;
	v_out[1] = v_lh[1] / s_rh;
	v_out[2] = v_lh[2] / s_rh;
	v_out[3] = v_lh[3] / s_rh;
	return v_out;
}

ijk_inl uintlv ijkVecDivSafe4ulvs(uintl4 v_out, uintl4 const v_lh, ui64 const s_rh)
{
	if (s_rh)
	{
		v_out[0] = v_lh[0] / s_rh;
		v_out[1] = v_lh[1] / s_rh;
		v_out[2] = v_lh[2] / s_rh;
		v_out[3] = v_lh[3] / s_rh;
	}
	else
		v_out[0] = v_out[1] = v_out[2] = v_out[3] = 0;
	return v_out;
}

ijk_inl uintlv ijkVecMod4ulvs(uintl4 v_out, uintl4 const v_lh, ui64 const s_rh)
{
	v_out[0] = v_lh[0] % s_rh;
	v_out[1] = v_lh[1] % s_rh;
	v_out[2] = v_lh[2] % s_rh;
	v_out[3] = v_lh[3] % s_rh;
	return v_out;
}

ijk_inl uintlv ijkVecModSafe4ulvs(uintl4 v_out, uintl4 const v_lh, ui64 const s_rh)
{
	if (s_rh)
	{
		v_out[0] = v_lh[0] % s_rh;
		v_out[1] = v_lh[1] % s_rh;
		v_out[2] = v_lh[2] % s_rh;
		v_out[3] = v_lh[3] % s_rh;
		return v_out;
	}
	return ijkVecCopy4ulv(v_out, v_lh);
}

ijk_inl uintlv ijkVecBitAnd4ulvs(uintl4 v_out, uintl4 const v_lh, ui64 const s_rh)
{
	v_out[0] = (v_lh[0] & s_rh);
	v_out[1] = (v_lh[1] & s_rh);
	v_out[2] = (v_lh[2] & s_rh);
	v_out[3] = (v_lh[3] & s_rh);
	return v_out;
}

ijk_inl uintlv ijkVecBitNand4ulvs(uintl4 v_out, uintl4 const v_lh, ui64 const s_rh)
{
	v_out[0] = ~(v_lh[0] & s_rh);
	v_out[1] = ~(v_lh[1] & s_rh);
	v_out[2] = ~(v_lh[2] & s_rh);
	v_out[3] = ~(v_lh[3] & s_rh);
	return v_out;
}

ijk_inl uintlv ijkVecBitOr4ulvs(uintl4 v_out, uintl4 const v_lh, ui64 const s_rh)
{
	v_out[0] = (v_lh[0] | s_rh);
	v_out[1] = (v_lh[1] | s_rh);
	v_out[2] = (v_lh[2] | s_rh);
	v_out[3] = (v_lh[3] | s_rh);
	return v_out;
}

ijk_inl uintlv ijkVecBitNor4ulvs(uintl4 v_out, uintl4 const v_lh, ui64 const s_rh)
{
	v_out[0] = ~(v_lh[0] | s_rh);
	v_out[1] = ~(v_lh[1] | s_rh);
	v_out[2] = ~(v_lh[2] | s_rh);
	v_out[3] = ~(v_lh[3] | s_rh);
	return v_out;
}

ijk_inl uintlv ijkVecBitXor4ulvs(uintl4 v_out, uintl4 const v_lh, ui64 const s_rh)
{
	v_out[0] = (v_lh[0] ^ s_rh);
	v_out[1] = (v_lh[1] ^ s_rh);
	v_out[2] = (v_lh[2] ^ s_rh);
	v_out[3] = (v_lh[3] ^ s_rh);
	return v_out;
}

ijk_inl uintlv ijkVecBitXnor4ulvs(uintl4 v_out, uintl4 const v_lh, ui64 const s_rh)
{
	v_out[0] = ~(v_lh[0] ^ s_rh);
	v_out[1] = ~(v_lh[1] ^ s_rh);
	v_out[2] = ~(v_lh[2] ^ s_rh);
	v_out[3] = ~(v_lh[3] ^ s_rh);
	return v_out;
}

ijk_inl uintlv ijkVecBitShiftLeft4ulvs(uintl4 v_out, uintl4 const v_lh, ui64 const s_rh)
{
	v_out[0] = (v_lh[0] << s_rh);
	v_out[1] = (v_lh[1] << s_rh);
	v_out[2] = (v_lh[2] << s_rh);
	v_out[3] = (v_lh[3] << s_rh);
	return v_out;
}

ijk_inl uintlv ijkVecBitShiftRight4ulvs(uintl4 v_out, uintl4 const v_lh, ui64 const s_rh)
{
	v_out[0] = (v_lh[0] >> s_rh);
	v_out[1] = (v_lh[1] >> s_rh);
	v_out[2] = (v_lh[2] >> s_rh);
	v_out[3] = (v_lh[3] >> s_rh);
	return v_out;
}

ijk_inl boolv ijkVecEqual4ulvs(bool4 bv_out, uintl4 const v_lh, ui64 const s_rh)
{
	bv_out[0] = (v_lh[0] == s_rh);
	bv_out[1] = (v_lh[1] == s_rh);
	bv_out[2] = (v_lh[2] == s_rh);
	bv_out[3] = (v_lh[3] == s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecInequal4ulvs(bool4 bv_out, uintl4 const v_lh, ui64 const s_rh)
{
	bv_out[0] = (v_lh[0] != s_rh);
	bv_out[1] = (v_lh[1] != s_rh);
	bv_out[2] = (v_lh[2] != s_rh);
	bv_out[3] = (v_lh[3] != s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual4ulvs(bool4 bv_out, uintl4 const v_lh, ui64 const s_rh)
{
	bv_out[0] = (v_lh[0] <= s_rh);
	bv_out[1] = (v_lh[1] <= s_rh);
	bv_out[2] = (v_lh[2] <= s_rh);
	bv_out[3] = (v_lh[3] <= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual4ulvs(bool4 bv_out, uintl4 const v_lh, ui64 const s_rh)
{
	bv_out[0] = (v_lh[0] >= s_rh);
	bv_out[1] = (v_lh[1] >= s_rh);
	bv_out[2] = (v_lh[2] >= s_rh);
	bv_out[3] = (v_lh[3] >= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLess4ulvs(bool4 bv_out, uintl4 const v_lh, ui64 const s_rh)
{
	bv_out[0] = (v_lh[0] < s_rh);
	bv_out[1] = (v_lh[1] < s_rh);
	bv_out[2] = (v_lh[2] < s_rh);
	bv_out[3] = (v_lh[3] < s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreater4ulvs(bool4 bv_out, uintl4 const v_lh, ui64 const s_rh)
{
	bv_out[0] = (v_lh[0] > s_rh);
	bv_out[1] = (v_lh[1] > s_rh);
	bv_out[2] = (v_lh[2] > s_rh);
	bv_out[3] = (v_lh[3] > s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecAnd4ulvs(bool4 bv_out, uintl4 const v_lh, ui64 const s_rh)
{
	bv_out[0] = (v_lh[0] && s_rh);
	bv_out[1] = (v_lh[1] && s_rh);
	bv_out[2] = (v_lh[2] && s_rh);
	bv_out[3] = (v_lh[3] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNand4ulvs(bool4 bv_out, uintl4 const v_lh, ui64 const s_rh)
{
	bv_out[0] = !(v_lh[0] && s_rh);
	bv_out[1] = !(v_lh[1] && s_rh);
	bv_out[2] = !(v_lh[2] && s_rh);
	bv_out[3] = !(v_lh[3] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecOr4ulvs(bool4 bv_out, uintl4 const v_lh, ui64 const s_rh)
{
	bv_out[0] = (v_lh[0] || s_rh);
	bv_out[1] = (v_lh[1] || s_rh);
	bv_out[2] = (v_lh[2] || s_rh);
	bv_out[3] = (v_lh[3] || s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNor4ulvs(bool4 bv_out, uintl4 const v_lh, ui64 const s_rh)
{
	bv_out[0] = !(v_lh[0] || s_rh);
	bv_out[1] = !(v_lh[1] || s_rh);
	bv_out[2] = !(v_lh[2] || s_rh);
	bv_out[3] = !(v_lh[3] || s_rh);
	return bv_out;
}

ijk_inl uintlv ijkVecCopy4ulxyv(uintl4 v_out, ui64 const x, ui64 const y, uintl2 const v_zw)
{
	v_out[0] = x;
	v_out[1] = y;
	v_out[2] = v_zw[0];
	v_out[3] = v_zw[1];
	return v_out;
}

ijk_inl uintlv ijkVecCopy4ulxv(uintl4 v_out, ui64 const x, uintl3 const v_yzw)
{
	v_out[0] = x;
	v_out[1] = v_yzw[0];
	v_out[2] = v_yzw[1];
	v_out[3] = v_yzw[2];
	return v_out;
}

ijk_inl uintlv ijkVecAdd4ulsv(uintl4 v_out, ui64 const s_lh, uintl4 const v_rh)
{
	v_out[0] = s_lh + v_rh[0];
	v_out[1] = s_lh + v_rh[1];
	v_out[2] = s_lh + v_rh[2];
	v_out[3] = s_lh + v_rh[3];
	return v_out;
}

ijk_inl uintlv ijkVecSub4ulsv(uintl4 v_out, ui64 const s_lh, uintl4 const v_rh)
{
	v_out[0] = s_lh - v_rh[0];
	v_out[1] = s_lh - v_rh[1];
	v_out[2] = s_lh - v_rh[2];
	v_out[3] = s_lh - v_rh[3];
	return v_out;
}

ijk_inl uintlv ijkVecMul4ulsv(uintl4 v_out, ui64 const s_lh, uintl4 const v_rh)
{
	v_out[0] = s_lh * v_rh[0];
	v_out[1] = s_lh * v_rh[1];
	v_out[2] = s_lh * v_rh[2];
	v_out[3] = s_lh * v_rh[3];
	return v_out;
}

ijk_inl uintlv ijkVecDiv4ulsv(uintl4 v_out, ui64 const s_lh, uintl4 const v_rh)
{
	v_out[0] = s_lh / v_rh[0];
	v_out[1] = s_lh / v_rh[1];
	v_out[2] = s_lh / v_rh[2];
	v_out[3] = s_lh / v_rh[3];
	return v_out;
}

ijk_inl uintlv ijkVecDivSafe4ulsv(uintl4 v_out, ui64 const s_lh, uintl4 const v_rh)
{
	v_out[0] = ijk_divide_safe_int(s_lh, v_rh[0]);
	v_out[1] = ijk_divide_safe_int(s_lh, v_rh[1]);
	v_out[2] = ijk_divide_safe_int(s_lh, v_rh[2]);
	v_out[3] = ijk_divide_safe_int(s_lh, v_rh[3]);
	return v_out;
}

ijk_inl uintlv ijkVecMod4ulsv(uintl4 v_out, ui64 const s_lh, uintl4 const v_rh)
{
	v_out[0] = s_lh % v_rh[0];
	v_out[1] = s_lh % v_rh[1];
	v_out[2] = s_lh % v_rh[2];
	v_out[3] = s_lh % v_rh[3];
	return v_out;
}

ijk_inl uintlv ijkVecModSafe4ulsv(uintl4 v_out, ui64 const s_lh, uintl4 const v_rh)
{
	v_out[0] = ijk_modulo_safe_int(s_lh, v_rh[0]);
	v_out[1] = ijk_modulo_safe_int(s_lh, v_rh[1]);
	v_out[2] = ijk_modulo_safe_int(s_lh, v_rh[2]);
	v_out[3] = ijk_modulo_safe_int(s_lh, v_rh[3]);
	return v_out;
}

ijk_inl uintlv ijkVecBitAnd4ulsv(uintl4 v_out, ui64 const s_lh, uintl4 const v_rh)
{
	v_out[0] = (s_lh & v_rh[0]);
	v_out[1] = (s_lh & v_rh[1]);
	v_out[2] = (s_lh & v_rh[2]);
	v_out[3] = (s_lh & v_rh[3]);
	return v_out;
}

ijk_inl uintlv ijkVecBitNand4ulsv(uintl4 v_out, ui64 const s_lh, uintl4 const v_rh)
{
	v_out[0] = ~(s_lh & v_rh[0]);
	v_out[1] = ~(s_lh & v_rh[1]);
	v_out[2] = ~(s_lh & v_rh[2]);
	v_out[3] = ~(s_lh & v_rh[3]);
	return v_out;
}

ijk_inl uintlv ijkVecBitOr4ulsv(uintl4 v_out, ui64 const s_lh, uintl4 const v_rh)
{
	v_out[0] = (s_lh | v_rh[0]);
	v_out[1] = (s_lh | v_rh[1]);
	v_out[2] = (s_lh | v_rh[2]);
	v_out[3] = (s_lh | v_rh[3]);
	return v_out;
}

ijk_inl uintlv ijkVecBitNor4ulsv(uintl4 v_out, ui64 const s_lh, uintl4 const v_rh)
{
	v_out[0] = ~(s_lh | v_rh[0]);
	v_out[1] = ~(s_lh | v_rh[1]);
	v_out[2] = ~(s_lh | v_rh[2]);
	v_out[3] = ~(s_lh | v_rh[3]);
	return v_out;
}

ijk_inl uintlv ijkVecBitXor4ulsv(uintl4 v_out, ui64 const s_lh, uintl4 const v_rh)
{
	v_out[0] = (s_lh ^ v_rh[0]);
	v_out[1] = (s_lh ^ v_rh[1]);
	v_out[2] = (s_lh ^ v_rh[2]);
	v_out[3] = (s_lh ^ v_rh[3]);
	return v_out;
}

ijk_inl uintlv ijkVecBitXnor4ulsv(uintl4 v_out, ui64 const s_lh, uintl4 const v_rh)
{
	v_out[0] = ~(s_lh ^ v_rh[0]);
	v_out[1] = ~(s_lh ^ v_rh[1]);
	v_out[2] = ~(s_lh ^ v_rh[2]);
	v_out[3] = ~(s_lh ^ v_rh[3]);
	return v_out;
}

ijk_inl uintlv ijkVecBitShiftLeft4ulsv(uintl4 v_out, ui64 const s_lh, uintl4 const v_rh)
{
	v_out[0] = (s_lh << v_rh[0]);
	v_out[1] = (s_lh << v_rh[1]);
	v_out[2] = (s_lh << v_rh[2]);
	v_out[3] = (s_lh << v_rh[3]);
	return v_out;
}

ijk_inl uintlv ijkVecBitShiftRight4ulsv(uintl4 v_out, ui64 const s_lh, uintl4 const v_rh)
{
	v_out[0] = (s_lh >> v_rh[0]);
	v_out[1] = (s_lh >> v_rh[1]);
	v_out[2] = (s_lh >> v_rh[2]);
	v_out[3] = (s_lh >> v_rh[3]);
	return v_out;
}

ijk_inl boolv ijkVecEqual4ulsv(bool4 bv_out, ui64 const s_lh, uintl4 const v_rh)
{
	bv_out[0] = (s_lh == v_rh[0]);
	bv_out[1] = (s_lh == v_rh[1]);
	bv_out[2] = (s_lh == v_rh[2]);
	bv_out[3] = (s_lh == v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal4ulsv(bool4 bv_out, ui64 const s_lh, uintl4 const v_rh)
{
	bv_out[0] = (s_lh != v_rh[0]);
	bv_out[1] = (s_lh != v_rh[1]);
	bv_out[2] = (s_lh != v_rh[2]);
	bv_out[3] = (s_lh != v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual4ulsv(bool4 bv_out, ui64 const s_lh, uintl4 const v_rh)
{
	bv_out[0] = (s_lh <= v_rh[0]);
	bv_out[1] = (s_lh <= v_rh[1]);
	bv_out[2] = (s_lh <= v_rh[2]);
	bv_out[3] = (s_lh <= v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual4ulsv(bool4 bv_out, ui64 const s_lh, uintl4 const v_rh)
{
	bv_out[0] = (s_lh >= v_rh[0]);
	bv_out[1] = (s_lh >= v_rh[1]);
	bv_out[2] = (s_lh >= v_rh[2]);
	bv_out[3] = (s_lh >= v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecLess4ulsv(bool4 bv_out, ui64 const s_lh, uintl4 const v_rh)
{
	bv_out[0] = (s_lh < v_rh[0]);
	bv_out[1] = (s_lh < v_rh[1]);
	bv_out[2] = (s_lh < v_rh[2]);
	bv_out[3] = (s_lh < v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater4ulsv(bool4 bv_out, ui64 const s_lh, uintl4 const v_rh)
{
	bv_out[0] = (s_lh > v_rh[0]);
	bv_out[1] = (s_lh > v_rh[1]);
	bv_out[2] = (s_lh > v_rh[2]);
	bv_out[3] = (s_lh > v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd4ulsv(bool4 bv_out, ui64 const s_lh, uintl4 const v_rh)
{
	bv_out[0] = (s_lh && v_rh[0]);
	bv_out[1] = (s_lh && v_rh[1]);
	bv_out[2] = (s_lh && v_rh[2]);
	bv_out[3] = (s_lh && v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecNand4ulsv(bool4 bv_out, ui64 const s_lh, uintl4 const v_rh)
{
	bv_out[0] = !(s_lh && v_rh[0]);
	bv_out[1] = !(s_lh && v_rh[1]);
	bv_out[2] = !(s_lh && v_rh[2]);
	bv_out[3] = !(s_lh && v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecOr4ulsv(bool4 bv_out, ui64 const s_lh, uintl4 const v_rh)
{
	bv_out[0] = (s_lh || v_rh[0]);
	bv_out[1] = (s_lh || v_rh[1]);
	bv_out[2] = (s_lh || v_rh[2]);
	bv_out[3] = (s_lh || v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecNor4ulsv(bool4 bv_out, ui64 const s_lh, uintl4 const v_rh)
{
	bv_out[0] = !(s_lh || v_rh[0]);
	bv_out[1] = !(s_lh || v_rh[1]);
	bv_out[2] = !(s_lh || v_rh[2]);
	bv_out[3] = !(s_lh || v_rh[3]);
	return bv_out;
}

ijk_inl ui64 ijkVecDot4ulv(uintl4 const v_lh, uintl4 const v_rh)
{
	return (v_lh[0] * v_rh[0] + v_lh[1] * v_rh[1] + v_lh[2] * v_rh[2] + v_lh[3] * v_rh[3]);
}

ijk_inl uintlv ijkVecCross4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh)
{
	v_out[3] = 0;
	return ijkVecCross3ulv(v_out, v_lh, v_rh);
}


//-----------------------------------------------------------------------------

ijk_inl uintl ijkVecAbs1ul(uintl const s)
{
	return ijkVecAbs1uls(s);
}

ijk_inl uintl ijkVecSgn1ul(uintl const s)
{
	return ijkVecSgn1uls(s);
}

ijk_inl uintl ijkVecDot1ul(uintl const s_lh, uintl const s_rh)
{
	return ijkVecDot1uls(s_lh, s_rh);
}

ijk_inl uintl ijkVecLengthSq1ul(uintl const s)
{
	return ijkVecLengthSq1uls(s);
}

ijk_inl uintl ijkVecLength1ul(uintl const s)
{
	return ijkVecLength1uls(s);
}

ijk_inl double ijkVecLengthSqInv1ul(uintl const s)
{
	return ijkVecLengthSqInv1uls(s);
}

ijk_inl double ijkVecLengthInv1ul(uintl const s)
{
	return ijkVecLengthInv1uls(s);
}

ijk_inl uintl ijkVecNormalize1ul(uintl const s)
{
	return ijkVecNormalize1uls(s);
}

ijk_inl uintl ijkVecNormalizeGetLength1ul(uintl const s, uintl* const length_out)
{
	return ijkVecNormalizeGetLength1uls(s, (ui64*)length_out);
}

ijk_inl uintl ijkVecNormalizeGetLengthInv1ul(uintl const s, double* const lengthInv_out)
{
	return ijkVecNormalizeGetLengthInv1uls(s, (f64*)lengthInv_out);
}


//-----------------------------------------------------------------------------

ijk_inl ulvec2 ijkVecInit2ul()
{
	ulvec2 const v_out = { 0, 0 };
	return v_out;
}

ijk_inl ulvec2 ijkVecInitElems2ul(uintl const x, uintl const y)
{
	ulvec2 const v_out = { x, y };
	return v_out;
}

ijk_inl ulvec2 ijkVecCopy2ul(ulvec2 const v_in)
{
	ulvec2 const v_out = { +v_in.x, +v_in.y };
	return v_out;
}

ijk_inl ilvec2 ijkVecNegate2ul(ulvec2 const v_in)
{
	ilvec2 const v_out = { -(i64)v_in.x, -(i64)v_in.y };
	return v_out;
}

ijk_inl ulvec2 ijkVecBitNot2ul(ulvec2 const v_in)
{
	ulvec2 const v_out = { ~v_in.x, ~v_in.y };
	return v_out;
}

ijk_inl bvec2 ijkVecNot2ul(ulvec2 const v_in)
{
	bvec2 const bv_out = { !v_in.x, !v_in.y };
	return bv_out;
}

ijk_inl ulvec2 ijkVecAdd2ul(ulvec2 const v_lh, ulvec2 const v_rh)
{
	ulvec2 const v_out = {
		v_lh.x + v_rh.x,
		v_lh.y + v_rh.y,
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecSub2ul(ulvec2 const v_lh, ulvec2 const v_rh)
{
	ulvec2 const v_out = {
		v_lh.x - v_rh.x,
		v_lh.y - v_rh.y,
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecMul2ul(ulvec2 const v_lh, ulvec2 const v_rh)
{
	ulvec2 const v_out = {
		v_lh.x * v_rh.x,
		v_lh.y * v_rh.y,
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecDiv2ul(ulvec2 const v_lh, ulvec2 const v_rh)
{
	ulvec2 const v_out = {
		v_lh.x / v_rh.x,
		v_lh.y / v_rh.y,
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecDivSafe2ul(ulvec2 const v_lh, ulvec2 const v_rh)
{
	ulvec2 const v_out = {
		ijk_divide_safe_int(v_lh.x, v_rh.x),
		ijk_divide_safe_int(v_lh.y, v_rh.y),
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecMod2ul(ulvec2 const v_lh, ulvec2 const v_rh)
{
	ulvec2 const v_out = {
		v_lh.x % v_rh.x,
		v_lh.y % v_rh.y,
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecModSafe2ul(ulvec2 const v_lh, ulvec2 const v_rh)
{
	ulvec2 const v_out = {
		ijk_modulo_safe_int(v_lh.x, v_rh.x),
		ijk_modulo_safe_int(v_lh.y, v_rh.y),
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecBitAnd2ul(ulvec2 const v_lh, ulvec2 const v_rh)
{
	ulvec2 const v_out = {
		(v_lh.x & v_rh.x),
		(v_lh.y & v_rh.y),
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecBitNand2ul(ulvec2 const v_lh, ulvec2 const v_rh)
{
	ulvec2 const v_out = {
		~(v_lh.x & v_rh.x),
		~(v_lh.y & v_rh.y),
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecBitOr2ul(ulvec2 const v_lh, ulvec2 const v_rh)
{
	ulvec2 const v_out = {
		(v_lh.x | v_rh.x),
		(v_lh.y | v_rh.y),
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecBitNor2ul(ulvec2 const v_lh, ulvec2 const v_rh)
{
	ulvec2 const v_out = {
		~(v_lh.x | v_rh.x),
		~(v_lh.y | v_rh.y),
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecBitXor2ul(ulvec2 const v_lh, ulvec2 const v_rh)
{
	ulvec2 const v_out = {
		(v_lh.x ^ v_rh.x),
		(v_lh.y ^ v_rh.y),
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecBitXnor2ul(ulvec2 const v_lh, ulvec2 const v_rh)
{
	ulvec2 const v_out = {
		~(v_lh.x ^ v_rh.x),
		~(v_lh.y ^ v_rh.y),
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecBitShiftLeft2ul(ulvec2 const v_lh, ulvec2 const v_rh)
{
	ulvec2 const v_out = {
		(v_lh.x << v_rh.x),
		(v_lh.y << v_rh.y),
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecBitShiftRight2ul(ulvec2 const v_lh, ulvec2 const v_rh)
{
	ulvec2 const v_out = {
		(v_lh.x >> v_rh.x),
		(v_lh.y >> v_rh.y),
	};
	return v_out;
}

ijk_inl bvec2 ijkVecEqual2ul(ulvec2 const v_lh, ulvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x == v_rh.x),
		(v_lh.y == v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecInequal2ul(ulvec2 const v_lh, ulvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x != v_rh.x),
		(v_lh.y != v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLessEqual2ul(ulvec2 const v_lh, ulvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x <= v_rh.x),
		(v_lh.y <= v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreaterEqual2ul(ulvec2 const v_lh, ulvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x >= v_rh.x),
		(v_lh.y >= v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLess2ul(ulvec2 const v_lh, ulvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x < v_rh.x),
		(v_lh.y < v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreater2ul(ulvec2 const v_lh, ulvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x > v_rh.x),
		(v_lh.y > v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecAnd2ul(ulvec2 const v_lh, ulvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x && v_rh.x),
		(v_lh.y && v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNand2ul(ulvec2 const v_lh, ulvec2 const v_rh)
{
	bvec2 const bv_out = {
		!(v_lh.x && v_rh.x),
		!(v_lh.y && v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecOr2ul(ulvec2 const v_lh, ulvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x || v_rh.x),
		(v_lh.y || v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNor2ul(ulvec2 const v_lh, ulvec2 const v_rh)
{
	bvec2 const bv_out = {
		!(v_lh.x || v_rh.x),
		!(v_lh.y || v_rh.y),
	};
	return bv_out;
}

ijk_inl ulvec2 ijkVecCopy2uls(uintl const s_in)
{
	ulvec2 const v_out = { s_in, s_in };
	return v_out;
}

ijk_inl ilvec2 ijkVecNegate2uls(uintl const s_in)
{
	intl const s = -(i64)s_in;
	ilvec2 const v_out = { s, s };
	return v_out;
}

ijk_inl ulvec2 ijkVecBitNot2uls(uintl const s_in)
{
	uintl const s = ~s_in;
	ulvec2 const v_out = { s, s };
	return v_out;
}

ijk_inl bvec2 ijkVecNot2uls(uintl const s_in)
{
	bool const s = !s_in;
	bvec2 const bv_out = { s, s };
	return bv_out;
}

ijk_inl ulvec2 ijkVecAdd2uls(ulvec2 const v_lh, uintl const s_rh)
{
	ulvec2 const v_out = {
		v_lh.x + s_rh,
		v_lh.y + s_rh,
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecSub2uls(ulvec2 const v_lh, uintl const s_rh)
{
	ulvec2 const v_out = {
		v_lh.x - s_rh,
		v_lh.y - s_rh,
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecMul2uls(ulvec2 const v_lh, uintl const s_rh)
{
	ulvec2 const v_out = {
		v_lh.x * s_rh,
		v_lh.y * s_rh,
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecDiv2uls(ulvec2 const v_lh, uintl const s_rh)
{
	ulvec2 const v_out = {
		v_lh.x / s_rh,
		v_lh.y / s_rh,
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecDivSafe2uls(ulvec2 const v_lh, uintl const s_rh)
{
	if (s_rh)
	{
		ulvec2 const v_out = {
			v_lh.x / s_rh,
			v_lh.y / s_rh,
		};
		return v_out;
	}
	else
	{
		ulvec2 const v_out = { 0, 0 };
		return v_out;
	}
}

ijk_inl ulvec2 ijkVecMod2uls(ulvec2 const v_lh, uintl const s_rh)
{
	ulvec2 const v_out = {
		v_lh.x % s_rh,
		v_lh.y % s_rh,
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecModSafe2uls(ulvec2 const v_lh, uintl const s_rh)
{
	if (s_rh)
	{
		ulvec2 const v_out = {
			v_lh.x % s_rh,
			v_lh.y % s_rh,
		};
		return v_out;
	}
	return v_lh;
}

ijk_inl ulvec2 ijkVecBitAnd2uls(ulvec2 const v_lh, uintl const s_rh)
{
	ulvec2 const v_out = {
		(v_lh.x & s_rh),
		(v_lh.y & s_rh),
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecBitNand2uls(ulvec2 const v_lh, uintl const s_rh)
{
	ulvec2 const v_out = {
		~(v_lh.x & s_rh),
		~(v_lh.y & s_rh),
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecBitOr2uls(ulvec2 const v_lh, uintl const s_rh)
{
	ulvec2 const v_out = {
		(v_lh.x | s_rh),
		(v_lh.y | s_rh),
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecBitNor2uls(ulvec2 const v_lh, uintl const s_rh)
{
	ulvec2 const v_out = {
		~(v_lh.x | s_rh),
		~(v_lh.y | s_rh),
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecBitXor2uls(ulvec2 const v_lh, uintl const s_rh)
{
	ulvec2 const v_out = {
		(v_lh.x ^ s_rh),
		(v_lh.y ^ s_rh),
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecBitXnor2uls(ulvec2 const v_lh, uintl const s_rh)
{
	ulvec2 const v_out = {
		~(v_lh.x ^ s_rh),
		~(v_lh.y ^ s_rh),
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecBitShiftLeft2uls(ulvec2 const v_lh, uintl const s_rh)
{
	ulvec2 const v_out = {
		(v_lh.x << s_rh),
		(v_lh.y << s_rh),
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecBitShiftRight2uls(ulvec2 const v_lh, uintl const s_rh)
{
	ulvec2 const v_out = {
		(v_lh.x >> s_rh),
		(v_lh.y >> s_rh),
	};
	return v_out;
}

ijk_inl bvec2 ijkVecEqual2uls(ulvec2 const v_lh, uintl const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x == s_rh),
		(v_lh.y == s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecInequal2uls(ulvec2 const v_lh, uintl const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x != s_rh),
		(v_lh.y != s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLessEqual2uls(ulvec2 const v_lh, uintl const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x <= s_rh),
		(v_lh.y <= s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreaterEqual2uls(ulvec2 const v_lh, uintl const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x >= s_rh),
		(v_lh.y >= s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLess2uls(ulvec2 const v_lh, uintl const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x < s_rh),
		(v_lh.y < s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreater2uls(ulvec2 const v_lh, uintl const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x > s_rh),
		(v_lh.y > s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecAnd2uls(ulvec2 const v_lh, uintl const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x && s_rh),
		(v_lh.y && s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNand2uls(ulvec2 const v_lh, uintl const s_rh)
{
	bvec2 const bv_out = {
		!(v_lh.x && s_rh),
		!(v_lh.y && s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecOr2uls(ulvec2 const v_lh, uintl const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x || s_rh),
		(v_lh.y || s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNor2uls(ulvec2 const v_lh, uintl const s_rh)
{
	bvec2 const bv_out = {
		!(v_lh.x || s_rh),
		!(v_lh.y || s_rh),
	};
	return bv_out;
}

ijk_inl ulvec2 ijkVecAdd2sul(uintl const s_lh, ulvec2 const v_rh)
{
	ulvec2 const v_out = {
		s_lh + v_rh.x,
		s_lh + v_rh.y,
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecSub2sul(uintl const s_lh, ulvec2 const v_rh)
{
	ulvec2 const v_out = {
		s_lh - v_rh.x,
		s_lh - v_rh.y,
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecMul2sul(uintl const s_lh, ulvec2 const v_rh)
{
	ulvec2 const v_out = {
		s_lh * v_rh.x,
		s_lh * v_rh.y,
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecDiv2sul(uintl const s_lh, ulvec2 const v_rh)
{
	ulvec2 const v_out = {
		s_lh / v_rh.x,
		s_lh / v_rh.y,
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecDivSafe2sul(uintl const s_lh, ulvec2 const v_rh)
{
	ulvec2 const v_out = {
		ijk_divide_safe_int(s_lh, v_rh.x),
		ijk_divide_safe_int(s_lh, v_rh.y),
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecMod2sul(uintl const s_lh, ulvec2 const v_rh)
{
	ulvec2 const v_out = {
		s_lh % v_rh.x,
		s_lh % v_rh.y,
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecModSafe2sul(uintl const s_lh, ulvec2 const v_rh)
{
	ulvec2 const v_out = {
		ijk_modulo_safe_int((ui64)s_lh, v_rh.x),
		ijk_modulo_safe_int((ui64)s_lh, v_rh.y),
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecBitAnd2sul(uintl const s_lh, ulvec2 const v_rh)
{
	ulvec2 const v_out = {
		(s_lh & v_rh.x),
		(s_lh & v_rh.y),
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecBitNand2sul(uintl const s_lh, ulvec2 const v_rh)
{
	ulvec2 const v_out = {
		~(s_lh & v_rh.x),
		~(s_lh & v_rh.y),
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecBitOr2sul(uintl const s_lh, ulvec2 const v_rh)
{
	ulvec2 const v_out = {
		(s_lh | v_rh.x),
		(s_lh | v_rh.y),
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecBitNor2sul(uintl const s_lh, ulvec2 const v_rh)
{
	ulvec2 const v_out = {
		~(s_lh | v_rh.x),
		~(s_lh | v_rh.y),
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecBitXor2sul(uintl const s_lh, ulvec2 const v_rh)
{
	ulvec2 const v_out = {
		(s_lh ^ v_rh.x),
		(s_lh ^ v_rh.y),
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecBitXnor2sul(uintl const s_lh, ulvec2 const v_rh)
{
	ulvec2 const v_out = {
		~(s_lh ^ v_rh.x),
		~(s_lh ^ v_rh.y),
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecBitShiftLeft2sul(uintl const s_lh, ulvec2 const v_rh)
{
	ulvec2 const v_out = {
		(s_lh << v_rh.x),
		(s_lh << v_rh.y),
	};
	return v_out;
}

ijk_inl ulvec2 ijkVecBitShiftRight2sul(uintl const s_lh, ulvec2 const v_rh)
{
	ulvec2 const v_out = {
		(s_lh >> v_rh.x),
		(s_lh >> v_rh.y),
	};
	return v_out;
}

ijk_inl bvec2 ijkVecEqual2sul(uintl const s_lh, ulvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh == v_rh.x),
		(s_lh == v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecInequal2sul(uintl const s_lh, ulvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh != v_rh.x),
		(s_lh != v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLessEqual2sul(uintl const s_lh, ulvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh <= v_rh.x),
		(s_lh <= v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreaterEqual2sul(uintl const s_lh, ulvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh >= v_rh.x),
		(s_lh >= v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLess2sul(uintl const s_lh, ulvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh < v_rh.x),
		(s_lh < v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreater2sul(uintl const s_lh, ulvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh > v_rh.x),
		(s_lh > v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecAnd2sul(uintl const s_lh, ulvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh && v_rh.x),
		(s_lh && v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNand2sul(uintl const s_lh, ulvec2 const v_rh)
{
	bvec2 const bv_out = {
		!(s_lh && v_rh.x),
		!(s_lh && v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecOr2sul(uintl const s_lh, ulvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh || v_rh.x),
		(s_lh || v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNor2sul(uintl const s_lh, ulvec2 const v_rh)
{
	bvec2 const bv_out = {
		!(s_lh || v_rh.x),
		!(s_lh || v_rh.y),
	};
	return bv_out;
}

ijk_inl uintl ijkVecDot2ul(ulvec2 const v_lh, ulvec2 const v_rh)
{
	return ijkVecDot2ulv(v_lh.xy, v_rh.xy);
}

ijk_inl uintl ijkVecCross2ul(ulvec2 const v_lh, ulvec2 const v_rh)
{
	return ijkVecCross2ulv(v_lh.xy, v_rh.xy);
}


//-----------------------------------------------------------------------------

ijk_inl ulvec3 ijkVecInit3ul()
{
	ulvec3 const v_out = { 0, 0, 0 };
	return v_out;
}

ijk_inl ulvec3 ijkVecInitElems3ul(uintl const x, uintl const y, uintl const z)
{
	ulvec3 const v_out = { x, y, z };
	return v_out;
}

ijk_inl ulvec3 ijkVecCopy3ul(ulvec3 const v_in)
{
	ulvec3 const v_out = { +v_in.x, +v_in.y, +v_in.z };
	return v_out;
}

ijk_inl ilvec3 ijkVecNegate3ul(ulvec3 const v_in)
{
	ilvec3 const v_out = { -(i64)v_in.x, -(i64)v_in.y, -(i64)v_in.z };
	return v_out;
}

ijk_inl ulvec3 ijkVecBitNot3ul(ulvec3 const v_in)
{
	ulvec3 const v_out = { ~v_in.x, ~v_in.y, ~v_in.z };
	return v_out;
}

ijk_inl bvec3 ijkVecNot3ul(ulvec3 const v_in)
{
	bvec3 const bv_out = { !v_in.x, !v_in.y, !v_in.z };
	return bv_out;
}

ijk_inl ulvec3 ijkVecAdd3ul(ulvec3 const v_lh, ulvec3 const v_rh)
{
	ulvec3 const v_out = {
		v_lh.x + v_rh.x,
		v_lh.y + v_rh.y,
		v_lh.z + v_rh.z,
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecSub3ul(ulvec3 const v_lh, ulvec3 const v_rh)
{
	ulvec3 const v_out = {
		v_lh.x - v_rh.x,
		v_lh.y - v_rh.y,
		v_lh.z - v_rh.z,
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecMul3ul(ulvec3 const v_lh, ulvec3 const v_rh)
{
	ulvec3 const v_out = {
		v_lh.x * v_rh.x,
		v_lh.y * v_rh.y,
		v_lh.z * v_rh.z,
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecDiv3ul(ulvec3 const v_lh, ulvec3 const v_rh)
{
	ulvec3 const v_out = {
		v_lh.x / v_rh.x,
		v_lh.y / v_rh.y,
		v_lh.z / v_rh.z,
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecDivSafe3ul(ulvec3 const v_lh, ulvec3 const v_rh)
{
	ulvec3 const v_out = {
		ijk_divide_safe_int(v_lh.x, v_rh.x),
		ijk_divide_safe_int(v_lh.y, v_rh.y),
		ijk_divide_safe_int(v_lh.z, v_rh.z),
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecMod3ul(ulvec3 const v_lh, ulvec3 const v_rh)
{
	ulvec3 const v_out = {
		v_lh.x % v_rh.x,
		v_lh.y % v_rh.y,
		v_lh.z % v_rh.z,
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecModSafe3ul(ulvec3 const v_lh, ulvec3 const v_rh)
{
	ulvec3 const v_out = {
		ijk_modulo_safe_int(v_lh.x, v_rh.x),
		ijk_modulo_safe_int(v_lh.y, v_rh.y),
		ijk_modulo_safe_int(v_lh.z, v_rh.z),
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecBitAnd3ul(ulvec3 const v_lh, ulvec3 const v_rh)
{
	ulvec3 const v_out = {
		(v_lh.x & v_rh.x),
		(v_lh.y & v_rh.y),
		(v_lh.z & v_rh.z),
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecBitNand3ul(ulvec3 const v_lh, ulvec3 const v_rh)
{
	ulvec3 const v_out = {
		~(v_lh.x & v_rh.x),
		~(v_lh.y & v_rh.y),
		~(v_lh.z & v_rh.z),
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecBitOr3ul(ulvec3 const v_lh, ulvec3 const v_rh)
{
	ulvec3 const v_out = {
		(v_lh.x | v_rh.x),
		(v_lh.y | v_rh.y),
		(v_lh.z | v_rh.z),
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecBitNor3ul(ulvec3 const v_lh, ulvec3 const v_rh)
{
	ulvec3 const v_out = {
		~(v_lh.x | v_rh.x),
		~(v_lh.y | v_rh.y),
		~(v_lh.z | v_rh.z),
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecBitXor3ul(ulvec3 const v_lh, ulvec3 const v_rh)
{
	ulvec3 const v_out = {
		(v_lh.x ^ v_rh.x),
		(v_lh.y ^ v_rh.y),
		(v_lh.z ^ v_rh.z),
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecBitXnor3ul(ulvec3 const v_lh, ulvec3 const v_rh)
{
	ulvec3 const v_out = {
		~(v_lh.x ^ v_rh.x),
		~(v_lh.y ^ v_rh.y),
		~(v_lh.z ^ v_rh.z),
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecBitShiftLeft3ul(ulvec3 const v_lh, ulvec3 const v_rh)
{
	ulvec3 const v_out = {
		(v_lh.x << v_rh.x),
		(v_lh.y << v_rh.y),
		(v_lh.z << v_rh.z),
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecBitShiftRight3ul(ulvec3 const v_lh, ulvec3 const v_rh)
{
	ulvec3 const v_out = {
		(v_lh.x >> v_rh.x),
		(v_lh.y >> v_rh.y),
		(v_lh.z >> v_rh.z),
	};
	return v_out;
}

ijk_inl bvec3 ijkVecEqual3ul(ulvec3 const v_lh, ulvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x == v_rh.x),
		(v_lh.y == v_rh.y),
		(v_lh.z == v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecInequal3ul(ulvec3 const v_lh, ulvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x != v_rh.x),
		(v_lh.y != v_rh.y),
		(v_lh.z != v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLessEqual3ul(ulvec3 const v_lh, ulvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x <= v_rh.x),
		(v_lh.y <= v_rh.y),
		(v_lh.z <= v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreaterEqual3ul(ulvec3 const v_lh, ulvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x >= v_rh.x),
		(v_lh.y >= v_rh.y),
		(v_lh.z >= v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLess3ul(ulvec3 const v_lh, ulvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x < v_rh.x),
		(v_lh.y < v_rh.y),
		(v_lh.z < v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreater3ul(ulvec3 const v_lh, ulvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x > v_rh.x),
		(v_lh.y > v_rh.y),
		(v_lh.z > v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecAnd3ul(ulvec3 const v_lh, ulvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x && v_rh.x),
		(v_lh.y && v_rh.y),
		(v_lh.z && v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNand3ul(ulvec3 const v_lh, ulvec3 const v_rh)
{
	bvec3 const bv_out = {
		!(v_lh.x && v_rh.x),
		!(v_lh.y && v_rh.y),
		!(v_lh.z && v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecOr3ul(ulvec3 const v_lh, ulvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x || v_rh.x),
		(v_lh.y || v_rh.y),
		(v_lh.z || v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNor3ul(ulvec3 const v_lh, ulvec3 const v_rh)
{
	bvec3 const bv_out = {
		!(v_lh.x || v_rh.x),
		!(v_lh.y || v_rh.y),
		!(v_lh.z || v_rh.z),
	};
	return bv_out;
}

ijk_inl ulvec3 ijkVecCopy3ulz(ulvec2 const v_xy, uintl const z)
{
	ulvec3 const v_out = { v_xy.x, v_xy.y, z };
	return v_out;
}

ijk_inl ulvec3 ijkVecCopy3uls(uintl const s_in)
{
	ulvec3 const v_out = { s_in, s_in, s_in };
	return v_out;
}

ijk_inl ilvec3 ijkVecNegate3uls(uintl const s_in)
{
	intl const s = -(i64)s_in;
	ilvec3 const v_out = { s, s, s };
	return v_out;
}

ijk_inl ulvec3 ijkVecBitNot3uls(uintl const s_in)
{
	uintl const s = ~s_in;
	ulvec3 const v_out = { s, s, s };
	return v_out;
}

ijk_inl bvec3 ijkVecNot3uls(uintl const s_in)
{
	bool const s = !s_in;
	bvec3 const bv_out = { s, s, s };
	return bv_out;
}

ijk_inl ulvec3 ijkVecAdd3uls(ulvec3 const v_lh, uintl const s_rh)
{
	ulvec3 const v_out = {
		v_lh.x + s_rh,
		v_lh.y + s_rh,
		v_lh.z + s_rh,
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecSub3uls(ulvec3 const v_lh, uintl const s_rh)
{
	ulvec3 const v_out = {
		v_lh.x - s_rh,
		v_lh.y - s_rh,
		v_lh.z - s_rh,
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecMul3uls(ulvec3 const v_lh, uintl const s_rh)
{
	ulvec3 const v_out = {
		v_lh.x * s_rh,
		v_lh.y * s_rh,
		v_lh.z * s_rh,
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecDiv3uls(ulvec3 const v_lh, uintl const s_rh)
{
	ulvec3 const v_out = {
		v_lh.x / s_rh,
		v_lh.y / s_rh,
		v_lh.z / s_rh,
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecDivSafe3uls(ulvec3 const v_lh, uintl const s_rh)
{
	if (s_rh)
	{
		ulvec3 const v_out = {
			v_lh.x / s_rh,
			v_lh.y / s_rh,
			v_lh.z / s_rh,
		};
		return v_out;
	}
	else
	{
		ulvec3 const v_out = { 0, 0, 0 };
		return v_out;
	}
}

ijk_inl ulvec3 ijkVecMod3uls(ulvec3 const v_lh, uintl const s_rh)
{
	ulvec3 const v_out = {
		v_lh.x % s_rh,
		v_lh.y % s_rh,
		v_lh.z % s_rh,
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecModSafe3uls(ulvec3 const v_lh, uintl const s_rh)
{
	if (s_rh)
	{
		ulvec3 const v_out = {
			v_lh.x % s_rh,
			v_lh.y % s_rh,
			v_lh.z % s_rh,
		};
		return v_out;
	}
	return v_lh;
}

ijk_inl ulvec3 ijkVecBitAnd3uls(ulvec3 const v_lh, uintl const s_rh)
{
	ulvec3 const v_out = {
		(v_lh.x & s_rh),
		(v_lh.y & s_rh),
		(v_lh.z & s_rh),
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecBitNand3uls(ulvec3 const v_lh, uintl const s_rh)
{
	ulvec3 const v_out = {
		~(v_lh.x & s_rh),
		~(v_lh.y & s_rh),
		~(v_lh.z & s_rh),
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecBitOr3uls(ulvec3 const v_lh, uintl const s_rh)
{
	ulvec3 const v_out = {
		(v_lh.x | s_rh),
		(v_lh.y | s_rh),
		(v_lh.z | s_rh),
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecBitNor3uls(ulvec3 const v_lh, uintl const s_rh)
{
	ulvec3 const v_out = {
		~(v_lh.x | s_rh),
		~(v_lh.y | s_rh),
		~(v_lh.z | s_rh),
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecBitXor3uls(ulvec3 const v_lh, uintl const s_rh)
{
	ulvec3 const v_out = {
		(v_lh.x ^ s_rh),
		(v_lh.y ^ s_rh),
		(v_lh.z ^ s_rh),
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecBitXnor3uls(ulvec3 const v_lh, uintl const s_rh)
{
	ulvec3 const v_out = {
		~(v_lh.x ^ s_rh),
		~(v_lh.y ^ s_rh),
		~(v_lh.z ^ s_rh),
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecBitShiftLeft3uls(ulvec3 const v_lh, uintl const s_rh)
{
	ulvec3 const v_out = {
		(v_lh.x << s_rh),
		(v_lh.y << s_rh),
		(v_lh.z << s_rh),
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecBitShiftRight3uls(ulvec3 const v_lh, uintl const s_rh)
{
	ulvec3 const v_out = {
		(v_lh.x >> s_rh),
		(v_lh.y >> s_rh),
		(v_lh.z >> s_rh),
	};
	return v_out;
}

ijk_inl bvec3 ijkVecEqual3uls(ulvec3 const v_lh, uintl const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x == s_rh),
		(v_lh.y == s_rh),
		(v_lh.z == s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecInequal3uls(ulvec3 const v_lh, uintl const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x != s_rh),
		(v_lh.y != s_rh),
		(v_lh.z != s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLessEqual3uls(ulvec3 const v_lh, uintl const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x <= s_rh),
		(v_lh.y <= s_rh),
		(v_lh.z <= s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreaterEqual3uls(ulvec3 const v_lh, uintl const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x >= s_rh),
		(v_lh.y >= s_rh),
		(v_lh.z >= s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLess3uls(ulvec3 const v_lh, uintl const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x < s_rh),
		(v_lh.y < s_rh),
		(v_lh.z < s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreater3uls(ulvec3 const v_lh, uintl const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x > s_rh),
		(v_lh.y > s_rh),
		(v_lh.z > s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecAnd3uls(ulvec3 const v_lh, uintl const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x && s_rh),
		(v_lh.y && s_rh),
		(v_lh.z && s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNand3uls(ulvec3 const v_lh, uintl const s_rh)
{
	bvec3 const bv_out = {
		!(v_lh.x && s_rh),
		!(v_lh.y && s_rh),
		!(v_lh.z && s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecOr3uls(ulvec3 const v_lh, uintl const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x || s_rh),
		(v_lh.y || s_rh),
		(v_lh.z || s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNor3uls(ulvec3 const v_lh, uintl const s_rh)
{
	bvec3 const bv_out = {
		!(v_lh.x || s_rh),
		!(v_lh.y || s_rh),
		!(v_lh.z || s_rh),
	};
	return bv_out;
}

ijk_inl ulvec3 ijkVecCopy3xul(uintl const x, ulvec2 const v_yz)
{
	ulvec3 const v_out = { x, v_yz.x, v_yz.y };
	return v_out;
}

ijk_inl ulvec3 ijkVecAdd3sul(uintl const s_lh, ulvec3 const v_rh)
{
	ulvec3 const v_out = {
		s_lh + v_rh.x,
		s_lh + v_rh.y,
		s_lh + v_rh.z,
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecSub3sul(uintl const s_lh, ulvec3 const v_rh)
{
	ulvec3 const v_out = {
		s_lh - v_rh.x,
		s_lh - v_rh.y,
		s_lh - v_rh.z,
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecMul3sul(uintl const s_lh, ulvec3 const v_rh)
{
	ulvec3 const v_out = {
		s_lh * v_rh.x,
		s_lh * v_rh.y,
		s_lh * v_rh.z,
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecDiv3sul(uintl const s_lh, ulvec3 const v_rh)
{
	ulvec3 const v_out = {
		s_lh / v_rh.x,
		s_lh / v_rh.y,
		s_lh / v_rh.z,
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecDivSafe3sul(uintl const s_lh, ulvec3 const v_rh)
{
	ulvec3 const v_out = {
		ijk_divide_safe_int(s_lh, v_rh.x),
		ijk_divide_safe_int(s_lh, v_rh.y),
		ijk_divide_safe_int(s_lh, v_rh.z),
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecMod3sul(uintl const s_lh, ulvec3 const v_rh)
{
	ulvec3 const v_out = {
		s_lh % v_rh.x,
		s_lh % v_rh.y,
		s_lh % v_rh.z,
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecModSafe3sul(uintl const s_lh, ulvec3 const v_rh)
{
	ulvec3 const v_out = {
		ijk_modulo_safe_int((ui64)s_lh, v_rh.x),
		ijk_modulo_safe_int((ui64)s_lh, v_rh.y),
		ijk_modulo_safe_int((ui64)s_lh, v_rh.z),
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecBitAnd3sul(uintl const s_lh, ulvec3 const v_rh)
{
	ulvec3 const v_out = {
		(s_lh & v_rh.x),
		(s_lh & v_rh.y),
		(s_lh & v_rh.z),
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecBitNand3sul(uintl const s_lh, ulvec3 const v_rh)
{
	ulvec3 const v_out = {
		~(s_lh & v_rh.x),
		~(s_lh & v_rh.y),
		~(s_lh & v_rh.z),
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecBitOr3sul(uintl const s_lh, ulvec3 const v_rh)
{
	ulvec3 const v_out = {
		(s_lh | v_rh.x),
		(s_lh | v_rh.y),
		(s_lh | v_rh.z),
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecBitNor3sul(uintl const s_lh, ulvec3 const v_rh)
{
	ulvec3 const v_out = {
		~(s_lh | v_rh.x),
		~(s_lh | v_rh.y),
		~(s_lh | v_rh.z),
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecBitXor3sul(uintl const s_lh, ulvec3 const v_rh)
{
	ulvec3 const v_out = {
		(s_lh ^ v_rh.x),
		(s_lh ^ v_rh.y),
		(s_lh ^ v_rh.z),
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecBitXnor3sul(uintl const s_lh, ulvec3 const v_rh)
{
	ulvec3 const v_out = {
		~(s_lh ^ v_rh.x),
		~(s_lh ^ v_rh.y),
		~(s_lh ^ v_rh.z),
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecBitShiftLeft3sul(uintl const s_lh, ulvec3 const v_rh)
{
	ulvec3 const v_out = {
		(s_lh << v_rh.x),
		(s_lh << v_rh.y),
		(s_lh << v_rh.z),
	};
	return v_out;
}

ijk_inl ulvec3 ijkVecBitShiftRight3sul(uintl const s_lh, ulvec3 const v_rh)
{
	ulvec3 const v_out = {
		(s_lh >> v_rh.x),
		(s_lh >> v_rh.y),
		(s_lh >> v_rh.z),
	};
	return v_out;
}

ijk_inl bvec3 ijkVecEqual3sul(uintl const s_lh, ulvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh == v_rh.x),
		(s_lh == v_rh.y),
		(s_lh == v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecInequal3sul(uintl const s_lh, ulvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh != v_rh.x),
		(s_lh != v_rh.y),
		(s_lh != v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLessEqual3sul(uintl const s_lh, ulvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh <= v_rh.x),
		(s_lh <= v_rh.y),
		(s_lh <= v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreaterEqual3sul(uintl const s_lh, ulvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh >= v_rh.x),
		(s_lh >= v_rh.y),
		(s_lh >= v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLess3sul(uintl const s_lh, ulvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh < v_rh.x),
		(s_lh < v_rh.y),
		(s_lh < v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreater3sul(uintl const s_lh, ulvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh > v_rh.x),
		(s_lh > v_rh.y),
		(s_lh > v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecAnd3sul(uintl const s_lh, ulvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh && v_rh.x),
		(s_lh && v_rh.y),
		(s_lh && v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNand3sul(uintl const s_lh, ulvec3 const v_rh)
{
	bvec3 const bv_out = {
		!(s_lh && v_rh.x),
		!(s_lh && v_rh.y),
		!(s_lh && v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecOr3sul(uintl const s_lh, ulvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh || v_rh.x),
		(s_lh || v_rh.y),
		(s_lh || v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNor3sul(uintl const s_lh, ulvec3 const v_rh)
{
	bvec3 const bv_out = {
		!(s_lh || v_rh.x),
		!(s_lh || v_rh.y),
		!(s_lh || v_rh.z),
	};
	return bv_out;
}

ijk_inl uintl ijkVecDot3ul(ulvec3 const v_lh, ulvec3 const v_rh)
{
	return ijkVecDot3ulv(v_lh.xyz, v_rh.xyz);
}

ijk_inl ulvec3 ijkVecCross3ul(ulvec3 const v_lh, ulvec3 const v_rh)
{
	ulvec3 v_out;
	ijkVecCross3ulv(v_out.xyz, v_lh.xyz, v_rh.xyz);
	return v_out;
}


//-----------------------------------------------------------------------------

ijk_inl ulvec4 ijkVecInit4ul()
{
	ulvec4 const v_out = { 0, 0, 0, 0 };
	return v_out;
}

ijk_inl ulvec4 ijkVecInitElems4ul(uintl const x, uintl const y, uintl const z, uintl const w)
{
	ulvec4 const v_out = { x, y, z, w };
	return v_out;
}

ijk_inl ulvec4 ijkVecCopy4xulw(uintl const x, ulvec2 const v_yz, uintl const w)
{
	ulvec4 const v_out = { x, v_yz.x, v_yz.y, w };
	return v_out;
}

ijk_inl ulvec4 ijkVecCopy4ul2(ulvec2 const v_xy, ulvec2 const v_zw)
{
	ulvec4 const v_out = { v_xy.x, v_xy.y, v_zw.x, v_zw.y };
	return v_out;
}

ijk_inl ulvec4 ijkVecCopy4ul(ulvec4 const v_in)
{
	ulvec4 const v_out = { +v_in.x, +v_in.y, +v_in.z, +v_in.w };
	return v_out;
}

ijk_inl ilvec4 ijkVecNegate4ul(ulvec4 const v_in)
{
	ilvec4 const v_out = { -(i64)v_in.x, -(i64)v_in.y, -(i64)v_in.z, -(i64)v_in.w };
	return v_out;
}

ijk_inl ulvec4 ijkVecBitNot4ul(ulvec4 const v_in)
{
	ulvec4 const v_out = { ~v_in.x, ~v_in.y, ~v_in.z, ~v_in.w };
	return v_out;
}

ijk_inl bvec4 ijkVecNot4ul(ulvec4 const v_in)
{
	bvec4 const bv_out = { !v_in.x, !v_in.y, !v_in.z, !v_in.w };
	return bv_out;
}

ijk_inl ulvec4 ijkVecAdd4ul(ulvec4 const v_lh, ulvec4 const v_rh)
{
	ulvec4 const v_out = {
		v_lh.x + v_rh.x,
		v_lh.y + v_rh.y,
		v_lh.z + v_rh.z,
		v_lh.w + v_rh.w,
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecSub4ul(ulvec4 const v_lh, ulvec4 const v_rh)
{
	ulvec4 const v_out = {
		v_lh.x - v_rh.x,
		v_lh.y - v_rh.y,
		v_lh.z - v_rh.z,
		v_lh.w - v_rh.w,
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecMul4ul(ulvec4 const v_lh, ulvec4 const v_rh)
{
	ulvec4 const v_out = {
		v_lh.x * v_rh.x,
		v_lh.y * v_rh.y,
		v_lh.z * v_rh.z,
		v_lh.w * v_rh.w,
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecDiv4ul(ulvec4 const v_lh, ulvec4 const v_rh)
{
	ulvec4 const v_out = {
		v_lh.x / v_rh.x,
		v_lh.y / v_rh.y,
		v_lh.z / v_rh.z,
		v_lh.w / v_rh.w,
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecDivSafe4ul(ulvec4 const v_lh, ulvec4 const v_rh)
{
	ulvec4 const v_out = {
		ijk_divide_safe_int(v_lh.x, v_rh.x),
		ijk_divide_safe_int(v_lh.y, v_rh.y),
		ijk_divide_safe_int(v_lh.z, v_rh.z),
		ijk_divide_safe_int(v_lh.w, v_rh.w),
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecMod4ul(ulvec4 const v_lh, ulvec4 const v_rh)
{
	ulvec4 const v_out = {
		v_lh.x % v_rh.x,
		v_lh.y % v_rh.y,
		v_lh.z % v_rh.z,
		v_lh.w % v_rh.w,
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecModSafe4ul(ulvec4 const v_lh, ulvec4 const v_rh)
{
	ulvec4 const v_out = {
		ijk_modulo_safe_int(v_lh.x, v_rh.x),
		ijk_modulo_safe_int(v_lh.y, v_rh.y),
		ijk_modulo_safe_int(v_lh.z, v_rh.z),
		ijk_modulo_safe_int(v_lh.w, v_rh.w),
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecBitAnd4ul(ulvec4 const v_lh, ulvec4 const v_rh)
{
	ulvec4 const v_out = {
		(v_lh.x & v_rh.x),
		(v_lh.y & v_rh.y),
		(v_lh.z & v_rh.z),
		(v_lh.w & v_rh.w),
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecBitNand4ul(ulvec4 const v_lh, ulvec4 const v_rh)
{
	ulvec4 const v_out = {
		~(v_lh.x & v_rh.x),
		~(v_lh.y & v_rh.y),
		~(v_lh.z & v_rh.z),
		~(v_lh.w & v_rh.w),
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecBitOr4ul(ulvec4 const v_lh, ulvec4 const v_rh)
{
	ulvec4 const v_out = {
		(v_lh.x | v_rh.x),
		(v_lh.y | v_rh.y),
		(v_lh.z | v_rh.z),
		(v_lh.w | v_rh.w),
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecBitNor4ul(ulvec4 const v_lh, ulvec4 const v_rh)
{
	ulvec4 const v_out = {
		~(v_lh.x | v_rh.x),
		~(v_lh.y | v_rh.y),
		~(v_lh.z | v_rh.z),
		~(v_lh.w | v_rh.w),
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecBitXor4ul(ulvec4 const v_lh, ulvec4 const v_rh)
{
	ulvec4 const v_out = {
		(v_lh.x ^ v_rh.x),
		(v_lh.y ^ v_rh.y),
		(v_lh.z ^ v_rh.z),
		(v_lh.w ^ v_rh.w),
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecBitXnor4ul(ulvec4 const v_lh, ulvec4 const v_rh)
{
	ulvec4 const v_out = {
		~(v_lh.x ^ v_rh.x),
		~(v_lh.y ^ v_rh.y),
		~(v_lh.z ^ v_rh.z),
		~(v_lh.w ^ v_rh.w),
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecBitShiftLeft4ul(ulvec4 const v_lh, ulvec4 const v_rh)
{
	ulvec4 const v_out = {
		(v_lh.x << v_rh.x),
		(v_lh.y << v_rh.y),
		(v_lh.z << v_rh.z),
		(v_lh.w << v_rh.w),
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecBitShiftRight4ul(ulvec4 const v_lh, ulvec4 const v_rh)
{
	ulvec4 const v_out = {
		(v_lh.x >> v_rh.x),
		(v_lh.y >> v_rh.y),
		(v_lh.z >> v_rh.z),
		(v_lh.w >> v_rh.w),
	};
	return v_out;
}

ijk_inl bvec4 ijkVecEqual4ul(ulvec4 const v_lh, ulvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x == v_rh.x),
		(v_lh.y == v_rh.y),
		(v_lh.z == v_rh.z),
		(v_lh.w == v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecInequal4ul(ulvec4 const v_lh, ulvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x != v_rh.x),
		(v_lh.y != v_rh.y),
		(v_lh.z != v_rh.z),
		(v_lh.w != v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLessEqual4ul(ulvec4 const v_lh, ulvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x <= v_rh.x),
		(v_lh.y <= v_rh.y),
		(v_lh.z <= v_rh.z),
		(v_lh.w <= v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreaterEqual4ul(ulvec4 const v_lh, ulvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x >= v_rh.x),
		(v_lh.y >= v_rh.y),
		(v_lh.z >= v_rh.z),
		(v_lh.w >= v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLess4ul(ulvec4 const v_lh, ulvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x < v_rh.x),
		(v_lh.y < v_rh.y),
		(v_lh.z < v_rh.z),
		(v_lh.w < v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreater4ul(ulvec4 const v_lh, ulvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x > v_rh.x),
		(v_lh.y > v_rh.y),
		(v_lh.z > v_rh.z),
		(v_lh.w > v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecAnd4ul(ulvec4 const v_lh, ulvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x && v_rh.x),
		(v_lh.y && v_rh.y),
		(v_lh.z && v_rh.z),
		(v_lh.w && v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNand4ul(ulvec4 const v_lh, ulvec4 const v_rh)
{
	bvec4 const bv_out = {
		!(v_lh.x && v_rh.x),
		!(v_lh.y && v_rh.y),
		!(v_lh.z && v_rh.z),
		!(v_lh.w && v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecOr4ul(ulvec4 const v_lh, ulvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x || v_rh.x),
		(v_lh.y || v_rh.y),
		(v_lh.z || v_rh.z),
		(v_lh.w || v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNor4ul(ulvec4 const v_lh, ulvec4 const v_rh)
{
	bvec4 const bv_out = {
		!(v_lh.x || v_rh.x),
		!(v_lh.y || v_rh.y),
		!(v_lh.z || v_rh.z),
		!(v_lh.w || v_rh.w),
	};
	return bv_out;
}

ijk_inl ulvec4 ijkVecCopy4ulzw(ulvec2 const v_xy, uintl const z, uintl const w)
{
	ulvec4 const v_out = { v_xy.x, v_xy.y, z, w };
	return v_out;
}

ijk_inl ulvec4 ijkVecCopy4ulw(ulvec3 const v_xyz, uintl const w)
{
	ulvec4 const v_out = { v_xyz.x, v_xyz.y, v_xyz.z, w };
	return v_out;
}

ijk_inl ulvec4 ijkVecCopy4uls(uintl const s_in)
{
	ulvec4 const v_out = { s_in, s_in, s_in, s_in };
	return v_out;
}

ijk_inl ilvec4 ijkVecNegate4uls(uintl const s_in)
{
	intl const s = -(i64)s_in;
	ilvec4 const v_out = { s, s, s, s };
	return v_out;
}

ijk_inl ulvec4 ijkVecBitNot4uls(uintl const s_in)
{
	uintl const s = ~s_in;
	ulvec4 const v_out = { s, s, s, s };
	return v_out;
}

ijk_inl bvec4 ijkVecNot4uls(uintl const s_in)
{
	bool const s = !s_in;
	bvec4 const bv_out = { s, s, s, s };
	return bv_out;
}

ijk_inl ulvec4 ijkVecAdd4uls(ulvec4 const v_lh, uintl const s_rh)
{
	ulvec4 const v_out = {
		v_lh.x + s_rh,
		v_lh.y + s_rh,
		v_lh.z + s_rh,
		v_lh.w + s_rh,
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecSub4uls(ulvec4 const v_lh, uintl const s_rh)
{
	ulvec4 const v_out = {
		v_lh.x - s_rh,
		v_lh.y - s_rh,
		v_lh.z - s_rh,
		v_lh.w - s_rh,
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecMul4uls(ulvec4 const v_lh, uintl const s_rh)
{
	ulvec4 const v_out = {
		v_lh.x * s_rh,
		v_lh.y * s_rh,
		v_lh.z * s_rh,
		v_lh.w * s_rh,
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecDiv4uls(ulvec4 const v_lh, uintl const s_rh)
{
	ulvec4 const v_out = {
		v_lh.x / s_rh,
		v_lh.y / s_rh,
		v_lh.z / s_rh,
		v_lh.w / s_rh,
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecDivSafe4uls(ulvec4 const v_lh, uintl const s_rh)
{
	if (s_rh)
	{
		ulvec4 const v_out = {
			v_lh.x / s_rh,
			v_lh.y / s_rh,
			v_lh.z / s_rh,
			v_lh.w / s_rh,
		};
		return v_out;
	}
	else
	{
		ulvec4 const v_out = { 0, 0, 0, 0 };
		return v_out;
	}
}

ijk_inl ulvec4 ijkVecMod4uls(ulvec4 const v_lh, uintl const s_rh)
{
	ulvec4 const v_out = {
		v_lh.x % s_rh,
		v_lh.y % s_rh,
		v_lh.z % s_rh,
		v_lh.w % s_rh,
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecModSafe4uls(ulvec4 const v_lh, uintl const s_rh)
{
	if (s_rh)
	{
		ulvec4 const v_out = {
			v_lh.x % s_rh,
			v_lh.y % s_rh,
			v_lh.z % s_rh,
			v_lh.w % s_rh,
		};
		return v_out;
	}
	return v_lh;
}

ijk_inl ulvec4 ijkVecBitAnd4uls(ulvec4 const v_lh, uintl const s_rh)
{
	ulvec4 const v_out = {
		(v_lh.x & s_rh),
		(v_lh.y & s_rh),
		(v_lh.z & s_rh),
		(v_lh.w & s_rh),
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecBitNand4uls(ulvec4 const v_lh, uintl const s_rh)
{
	ulvec4 const v_out = {
		~(v_lh.x & s_rh),
		~(v_lh.y & s_rh),
		~(v_lh.z & s_rh),
		~(v_lh.w & s_rh),
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecBitOr4uls(ulvec4 const v_lh, uintl const s_rh)
{
	ulvec4 const v_out = {
		(v_lh.x | s_rh),
		(v_lh.y | s_rh),
		(v_lh.z | s_rh),
		(v_lh.w | s_rh),
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecBitNor4uls(ulvec4 const v_lh, uintl const s_rh)
{
	ulvec4 const v_out = {
		~(v_lh.x | s_rh),
		~(v_lh.y | s_rh),
		~(v_lh.z | s_rh),
		~(v_lh.w | s_rh),
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecBitXor4uls(ulvec4 const v_lh, uintl const s_rh)
{
	ulvec4 const v_out = {
		(v_lh.x ^ s_rh),
		(v_lh.y ^ s_rh),
		(v_lh.z ^ s_rh),
		(v_lh.w ^ s_rh),
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecBitXnor4uls(ulvec4 const v_lh, uintl const s_rh)
{
	ulvec4 const v_out = {
		~(v_lh.x ^ s_rh),
		~(v_lh.y ^ s_rh),
		~(v_lh.z ^ s_rh),
		~(v_lh.w ^ s_rh),
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecBitShiftLeft4uls(ulvec4 const v_lh, uintl const s_rh)
{
	ulvec4 const v_out = {
		(v_lh.x << s_rh),
		(v_lh.y << s_rh),
		(v_lh.z << s_rh),
		(v_lh.w << s_rh),
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecBitShiftRight4uls(ulvec4 const v_lh, uintl const s_rh)
{
	ulvec4 const v_out = {
		(v_lh.x >> s_rh),
		(v_lh.y >> s_rh),
		(v_lh.z >> s_rh),
		(v_lh.w >> s_rh),
	};
	return v_out;
}

ijk_inl bvec4 ijkVecEqual4uls(ulvec4 const v_lh, uintl const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x == s_rh),
		(v_lh.y == s_rh),
		(v_lh.z == s_rh),
		(v_lh.w == s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecInequal4uls(ulvec4 const v_lh, uintl const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x != s_rh),
		(v_lh.y != s_rh),
		(v_lh.z != s_rh),
		(v_lh.w != s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLessEqual4uls(ulvec4 const v_lh, uintl const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x <= s_rh),
		(v_lh.y <= s_rh),
		(v_lh.z <= s_rh),
		(v_lh.w <= s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreaterEqual4uls(ulvec4 const v_lh, uintl const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x >= s_rh),
		(v_lh.y >= s_rh),
		(v_lh.z >= s_rh),
		(v_lh.w >= s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLess4uls(ulvec4 const v_lh, uintl const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x < s_rh),
		(v_lh.y < s_rh),
		(v_lh.z < s_rh),
		(v_lh.w < s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreater4uls(ulvec4 const v_lh, uintl const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x > s_rh),
		(v_lh.y > s_rh),
		(v_lh.z > s_rh),
		(v_lh.w > s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecAnd4uls(ulvec4 const v_lh, uintl const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x && s_rh),
		(v_lh.y && s_rh),
		(v_lh.z && s_rh),
		(v_lh.w && s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNand4uls(ulvec4 const v_lh, uintl const s_rh)
{
	bvec4 const bv_out = {
		!(v_lh.x && s_rh),
		!(v_lh.y && s_rh),
		!(v_lh.z && s_rh),
		!(v_lh.w && s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecOr4uls(ulvec4 const v_lh, uintl const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x || s_rh),
		(v_lh.y || s_rh),
		(v_lh.z || s_rh),
		(v_lh.w || s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNor4uls(ulvec4 const v_lh, uintl const s_rh)
{
	bvec4 const bv_out = {
		!(v_lh.x || s_rh),
		!(v_lh.y || s_rh),
		!(v_lh.z || s_rh),
		!(v_lh.w || s_rh),
	};
	return bv_out;
}

ijk_inl ulvec4 ijkVecCopy4xyul(uintl const x, uintl const y, ulvec2 const v_zw)
{
	ulvec4 const v_out = { x, y, v_zw.x, v_zw.y };
	return v_out;
}

ijk_inl ulvec4 ijkVecCopy4xul(uintl const x, ulvec3 const v_yzw)
{
	ulvec4 const v_out = { x, v_yzw.x, v_yzw.y, v_yzw.z };
	return v_out;
}

ijk_inl ulvec4 ijkVecAdd4sul(uintl const s_lh, ulvec4 const v_rh)
{
	ulvec4 const v_out = {
		s_lh + v_rh.x,
		s_lh + v_rh.y,
		s_lh + v_rh.z,
		s_lh + v_rh.w,
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecSub4sul(uintl const s_lh, ulvec4 const v_rh)
{
	ulvec4 const v_out = {
		s_lh - v_rh.x,
		s_lh - v_rh.y,
		s_lh - v_rh.z,
		s_lh - v_rh.w,
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecMul4sul(uintl const s_lh, ulvec4 const v_rh)
{
	ulvec4 const v_out = {
		s_lh * v_rh.x,
		s_lh * v_rh.y,
		s_lh * v_rh.z,
		s_lh * v_rh.w,
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecDiv4sul(uintl const s_lh, ulvec4 const v_rh)
{
	ulvec4 const v_out = {
		s_lh / v_rh.x,
		s_lh / v_rh.y,
		s_lh / v_rh.z,
		s_lh / v_rh.w,
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecDivSafe4sul(uintl const s_lh, ulvec4 const v_rh)
{
	ulvec4 const v_out = {
		ijk_divide_safe_int(s_lh, v_rh.x),
		ijk_divide_safe_int(s_lh, v_rh.y),
		ijk_divide_safe_int(s_lh, v_rh.z),
		ijk_divide_safe_int(s_lh, v_rh.w),
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecMod4sul(uintl const s_lh, ulvec4 const v_rh)
{
	ulvec4 const v_out = {
		s_lh % v_rh.x,
		s_lh % v_rh.y,
		s_lh % v_rh.z,
		s_lh % v_rh.w,
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecModSafe4sul(uintl const s_lh, ulvec4 const v_rh)
{
	ulvec4 const v_out = {
		ijk_modulo_safe_int((ui64)s_lh, v_rh.x),
		ijk_modulo_safe_int((ui64)s_lh, v_rh.y),
		ijk_modulo_safe_int((ui64)s_lh, v_rh.z),
		ijk_modulo_safe_int((ui64)s_lh, v_rh.w),
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecBitAnd4sul(uintl const s_lh, ulvec4 const v_rh)
{
	ulvec4 const v_out = {
		(s_lh & v_rh.x),
		(s_lh & v_rh.y),
		(s_lh & v_rh.z),
		(s_lh & v_rh.w),
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecBitNand4sul(uintl const s_lh, ulvec4 const v_rh)
{
	ulvec4 const v_out = {
		~(s_lh & v_rh.x),
		~(s_lh & v_rh.y),
		~(s_lh & v_rh.z),
		~(s_lh & v_rh.w),
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecBitOr4sul(uintl const s_lh, ulvec4 const v_rh)
{
	ulvec4 const v_out = {
		(s_lh | v_rh.x),
		(s_lh | v_rh.y),
		(s_lh | v_rh.z),
		(s_lh | v_rh.w),
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecBitNor4sul(uintl const s_lh, ulvec4 const v_rh)
{
	ulvec4 const v_out = {
		~(s_lh | v_rh.x),
		~(s_lh | v_rh.y),
		~(s_lh | v_rh.z),
		~(s_lh | v_rh.w),
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecBitXor4sul(uintl const s_lh, ulvec4 const v_rh)
{
	ulvec4 const v_out = {
		(s_lh ^ v_rh.x),
		(s_lh ^ v_rh.y),
		(s_lh ^ v_rh.z),
		(s_lh ^ v_rh.w),
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecBitXnor4sul(uintl const s_lh, ulvec4 const v_rh)
{
	ulvec4 const v_out = {
		~(s_lh ^ v_rh.x),
		~(s_lh ^ v_rh.y),
		~(s_lh ^ v_rh.z),
		~(s_lh ^ v_rh.w),
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecBitShiftLeft4sul(uintl const s_lh, ulvec4 const v_rh)
{
	ulvec4 const v_out = {
		(s_lh << v_rh.x),
		(s_lh << v_rh.y),
		(s_lh << v_rh.z),
		(s_lh << v_rh.w),
	};
	return v_out;
}

ijk_inl ulvec4 ijkVecBitShiftRight4sul(uintl const s_lh, ulvec4 const v_rh)
{
	ulvec4 const v_out = {
		(s_lh >> v_rh.x),
		(s_lh >> v_rh.y),
		(s_lh >> v_rh.z),
		(s_lh >> v_rh.w),
	};
	return v_out;
}

ijk_inl bvec4 ijkVecEqual4sul(uintl const s_lh, ulvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh == v_rh.x),
		(s_lh == v_rh.y),
		(s_lh == v_rh.z),
		(s_lh == v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecInequal4sul(uintl const s_lh, ulvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh != v_rh.x),
		(s_lh != v_rh.y),
		(s_lh != v_rh.z),
		(s_lh != v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLessEqual4sul(uintl const s_lh, ulvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh <= v_rh.x),
		(s_lh <= v_rh.y),
		(s_lh <= v_rh.z),
		(s_lh <= v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreaterEqual4sul(uintl const s_lh, ulvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh >= v_rh.x),
		(s_lh >= v_rh.y),
		(s_lh >= v_rh.z),
		(s_lh >= v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLess4sul(uintl const s_lh, ulvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh < v_rh.x),
		(s_lh < v_rh.y),
		(s_lh < v_rh.z),
		(s_lh < v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreater4sul(uintl const s_lh, ulvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh > v_rh.x),
		(s_lh > v_rh.y),
		(s_lh > v_rh.z),
		(s_lh > v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecAnd4sul(uintl const s_lh, ulvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh && v_rh.x),
		(s_lh && v_rh.y),
		(s_lh && v_rh.z),
		(s_lh && v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNand4sul(uintl const s_lh, ulvec4 const v_rh)
{
	bvec4 const bv_out = {
		!(s_lh && v_rh.x),
		!(s_lh && v_rh.y),
		!(s_lh && v_rh.z),
		!(s_lh && v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecOr4sul(uintl const s_lh, ulvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh || v_rh.x),
		(s_lh || v_rh.y),
		(s_lh || v_rh.z),
		(s_lh || v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNor4sul(uintl const s_lh, ulvec4 const v_rh)
{
	bvec4 const bv_out = {
		!(s_lh || v_rh.x),
		!(s_lh || v_rh.y),
		!(s_lh || v_rh.z),
		!(s_lh || v_rh.w),
	};
	return bv_out;
}

ijk_inl uintl ijkVecDot4ul(ulvec4 const v_lh, ulvec4 const v_rh)
{
	return ijkVecDot4ulv(v_lh.xyzw, v_rh.xyzw);
}

ijk_inl ulvec4 ijkVecCross4ul(ulvec4 const v_lh, ulvec4 const v_rh)
{
	ulvec4 v_out;
	ijkVecCross4ulv(v_out.xyzw, v_lh.xyzw, v_rh.xyzw);
	return v_out;
}


//-----------------------------------------------------------------------------


#endif	// !_IJK_VECTOR_UINTL_INL_
#endif	// _IJK_VECTOR_UINTL_H_