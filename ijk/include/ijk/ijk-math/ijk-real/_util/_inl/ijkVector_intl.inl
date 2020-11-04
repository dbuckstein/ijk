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

	ijkVector_intl.inl
	Inline definitions for signed 64-bit integer vector functions.
*/

#ifdef _IJK_VECTOR_INTL_H_
#ifndef _IJK_VECTOR_INTL_INL_
#define _IJK_VECTOR_INTL_INL_


//-----------------------------------------------------------------------------

ijk_inl i64 ijkVecAbs1ils(i64 const s)
{
	return ijk_abs_int(s);
}

ijk_inl i64 ijkVecSgn1ils(i64 const s)
{
	return ijk_sgn_int(s);
}

ijk_inl i64 ijkVecDot1ils(i64 const s_lh, i64 const s_rh)
{
	return (s_lh * s_rh);
}

ijk_inl i64 ijkVecLengthSq1ils(i64 const s)
{
	return (s * s);
}

ijk_inl i64 ijkVecLength1ils(i64 const s)
{
	return ijk_abs_int(s);
}

ijk_inl f64 ijkVecLengthSqInv1ils(i64 const s)
{
	i64 const lengthSq = (s * s);
	return ijk_recip_safe_dbl(lengthSq);
}

ijk_inl f64 ijkVecLengthInv1ils(i64 const s)
{
	i64 const length = ijk_abs_int(s);
	return ijk_recip_safe_dbl(length);
}

ijk_inl i64 ijkVecNormalize1ils(i64 const s)
{
	return ijk_sgn_int(s);
}

ijk_inl i64 ijkVecNormalizeGetLength1ils(i64 const s, i64* const length_out)
{
	i64 const length = *length_out = ijk_abs_int(s);
	return ijk_sgn_int(s);
}

ijk_inl i64 ijkVecNormalizeGetLengthInv1ils(i64 const s, f64* const lengthInv_out)
{
	i64 const length = ijk_abs_int(s);
	*lengthInv_out = ijk_recip_safe_dbl(length);
	return ijk_sgn_int(s);
}


//-----------------------------------------------------------------------------

ijk_inl intlv ijkVecPiv(intlv v_out)
{
	return v_out;
}


//-----------------------------------------------------------------------------

ijk_inl intlv ijkVecInit2ilv(intl2 v_out)
{
	v_out[0] = v_out[1] = 0;
	return v_out;
}

ijk_inl intlv ijkVecInitElems2ilv(intl2 v_out, i64 const x, i64 const y)
{
	v_out[0] = x;
	v_out[1] = y;
	return v_out;
}

ijk_inl intlv ijkVecCopy2ilv(intl2 v_out, intl2 const v_in)
{
	v_out[0] = +v_in[0];
	v_out[1] = +v_in[1];
	return v_out;
}

ijk_inl intlv ijkVecNegate2ilv(intl2 v_out, intl2 const v_in)
{
	v_out[0] = -v_in[0];
	v_out[1] = -v_in[1];
	return v_out;
}

ijk_inl intlv ijkVecBitNot2ilv(intl2 v_out, intl2 const v_in)
{
	v_out[0] = ~v_in[0];
	v_out[1] = ~v_in[1];
	return v_out;
}

ijk_inl boolv ijkVecNot2ilv(bool2 bv_out, intl2 const v_in)
{
	bv_out[0] = !v_in[0];
	bv_out[1] = !v_in[1];
	return bv_out;
}

ijk_inl intlv ijkVecAdd2ilv(intl2 v_out, intl2 const v_lh, intl2 const v_rh)
{
	v_out[0] = v_lh[0] + v_rh[0];
	v_out[1] = v_lh[1] + v_rh[1];
	return v_out;
}

ijk_inl intlv ijkVecSub2ilv(intl2 v_out, intl2 const v_lh, intl2 const v_rh)
{
	v_out[0] = v_lh[0] - v_rh[0];
	v_out[1] = v_lh[1] - v_rh[1];
	return v_out;
}

ijk_inl intlv ijkVecMul2ilv(intl2 v_out, intl2 const v_lh, intl2 const v_rh)
{
	v_out[0] = v_lh[0] * v_rh[0];
	v_out[1] = v_lh[1] * v_rh[1];
	return v_out;
}

ijk_inl intlv ijkVecDiv2ilv(intl2 v_out, intl2 const v_lh, intl2 const v_rh)
{
	v_out[0] = v_lh[0] / v_rh[0];
	v_out[1] = v_lh[1] / v_rh[1];
	return v_out;
}

ijk_inl intlv ijkVecDivSafe2ilv(intl2 v_out, intl2 const v_lh, intl2 const v_rh)
{
	v_out[0] = ijk_divide_safe_int(v_lh[0], v_rh[0]);
	v_out[1] = ijk_divide_safe_int(v_lh[1], v_rh[1]);
	return v_out;
}

ijk_inl intlv ijkVecMod2ilv(intl2 v_out, intl2 const v_lh, intl2 const v_rh)
{
	v_out[0] = v_lh[0] % v_rh[0];
	v_out[1] = v_lh[1] % v_rh[1];
	return v_out;
}

ijk_inl intlv ijkVecModSafe2ilv(intl2 v_out, intl2 const v_lh, intl2 const v_rh)
{
	v_out[0] = ijk_modulo_safe_int(v_lh[0], v_rh[0]);
	v_out[1] = ijk_modulo_safe_int(v_lh[1], v_rh[1]);
	return v_out;
}

ijk_inl intlv ijkVecBitAnd2ilv(intl2 v_out, intl2 const v_lh, intl2 const v_rh)
{
	v_out[0] = (v_lh[0] & v_rh[0]);
	v_out[1] = (v_lh[1] & v_rh[1]);
	return v_out;
}

ijk_inl intlv ijkVecBitNand2ilv(intl2 v_out, intl2 const v_lh, intl2 const v_rh)
{
	v_out[0] = ~(v_lh[0] & v_rh[0]);
	v_out[1] = ~(v_lh[1] & v_rh[1]);
	return v_out;
}

ijk_inl intlv ijkVecBitOr2ilv(intl2 v_out, intl2 const v_lh, intl2 const v_rh)
{
	v_out[0] = (v_lh[0] | v_rh[0]);
	v_out[1] = (v_lh[1] | v_rh[1]);
	return v_out;
}

ijk_inl intlv ijkVecBitNor2ilv(intl2 v_out, intl2 const v_lh, intl2 const v_rh)
{
	v_out[0] = ~(v_lh[0] | v_rh[0]);
	v_out[1] = ~(v_lh[1] | v_rh[1]);
	return v_out;
}

ijk_inl intlv ijkVecBitXor2ilv(intl2 v_out, intl2 const v_lh, intl2 const v_rh)
{
	v_out[0] = (v_lh[0] ^ v_rh[0]);
	v_out[1] = (v_lh[1] ^ v_rh[1]);
	return v_out;
}

ijk_inl intlv ijkVecBitXnor2ilv(intl2 v_out, intl2 const v_lh, intl2 const v_rh)
{
	v_out[0] = ~(v_lh[0] ^ v_rh[0]);
	v_out[1] = ~(v_lh[1] ^ v_rh[1]);
	return v_out;
}

ijk_inl intlv ijkVecBitShiftLeft2ilv(intl2 v_out, intl2 const v_lh, intl2 const v_rh)
{
	v_out[0] = (v_lh[0] << v_rh[0]);
	v_out[1] = (v_lh[1] << v_rh[1]);
	return v_out;
}

ijk_inl intlv ijkVecBitShiftRight2ilv(intl2 v_out, intl2 const v_lh, intl2 const v_rh)
{
	v_out[0] = (v_lh[0] >> v_rh[0]);
	v_out[1] = (v_lh[1] >> v_rh[1]);
	return v_out;
}

ijk_inl boolv ijkVecEqual2ilv(bool2 bv_out, intl2 const v_lh, intl2 const v_rh)
{
	bv_out[0] = (v_lh[0] == v_rh[0]);
	bv_out[1] = (v_lh[1] == v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal2ilv(bool2 bv_out, intl2 const v_lh, intl2 const v_rh)
{
	bv_out[0] = (v_lh[0] != v_rh[0]);
	bv_out[1] = (v_lh[1] != v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual2ilv(bool2 bv_out, intl2 const v_lh, intl2 const v_rh)
{
	bv_out[0] = (v_lh[0] <= v_rh[0]);
	bv_out[1] = (v_lh[1] <= v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual2ilv(bool2 bv_out, intl2 const v_lh, intl2 const v_rh)
{
	bv_out[0] = (v_lh[0] >= v_rh[0]);
	bv_out[1] = (v_lh[1] >= v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecLess2ilv(bool2 bv_out, intl2 const v_lh, intl2 const v_rh)
{
	bv_out[0] = (v_lh[0] < v_rh[0]);
	bv_out[1] = (v_lh[1] < v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater2ilv(bool2 bv_out, intl2 const v_lh, intl2 const v_rh)
{
	bv_out[0] = (v_lh[0] > v_rh[0]);
	bv_out[1] = (v_lh[1] > v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd2ilv(bool2 bv_out, intl2 const v_lh, intl2 const v_rh)
{
	bv_out[0] = (v_lh[0] && v_rh[0]);
	bv_out[1] = (v_lh[1] && v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecNand2ilv(bool2 bv_out, intl2 const v_lh, intl2 const v_rh)
{
	bv_out[0] = !(v_lh[0] && v_rh[0]);
	bv_out[1] = !(v_lh[1] && v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecOr2ilv(bool2 bv_out, intl2 const v_lh, intl2 const v_rh)
{
	bv_out[0] = (v_lh[0] || v_rh[0]);
	bv_out[1] = (v_lh[1] || v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecNor2ilv(bool2 bv_out, intl2 const v_lh, intl2 const v_rh)
{
	bv_out[0] = !(v_lh[0] || v_rh[0]);
	bv_out[1] = !(v_lh[1] || v_rh[1]);
	return bv_out;
}

ijk_inl intlv ijkVecCopy2ilvs(intl2 v_out, i64 const s_in)
{
	v_out[0] = v_out[1] = +s_in;
	return v_out;
}

ijk_inl intlv ijkVecNegate2ilvs(intl2 v_out, i64 const s_in)
{
	v_out[0] = v_out[1] = -s_in;
	return v_out;
}

ijk_inl intlv ijkVecBitNot2ilvs(intl2 v_out, i64 const s_in)
{
	v_out[0] = v_out[1] = ~s_in;
	return v_out;
}

ijk_inl boolv ijkVecNot2ilvs(bool2 bv_out, i64 const s_in)
{
	bv_out[0] = bv_out[1] = !s_in;
	return bv_out;
}

ijk_inl intlv ijkVecAdd2ilvs(intl2 v_out, intl2 const v_lh, i64 const s_rh)
{
	v_out[0] = v_lh[0] + s_rh;
	v_out[1] = v_lh[1] + s_rh;
	return v_out;
}

ijk_inl intlv ijkVecSub2ilvs(intl2 v_out, intl2 const v_lh, i64 const s_rh)
{
	v_out[0] = v_lh[0] - s_rh;
	v_out[1] = v_lh[1] - s_rh;
	return v_out;
}

ijk_inl intlv ijkVecMul2ilvs(intl2 v_out, intl2 const v_lh, i64 const s_rh)
{
	v_out[0] = v_lh[0] * s_rh;
	v_out[1] = v_lh[1] * s_rh;
	return v_out;
}

ijk_inl intlv ijkVecDiv2ilvs(intl2 v_out, intl2 const v_lh, i64 const s_rh)
{
	v_out[0] = v_lh[0] / s_rh;
	v_out[1] = v_lh[1] / s_rh;
	return v_out;
}

ijk_inl intlv ijkVecDivSafe2ilvs(intl2 v_out, intl2 const v_lh, i64 const s_rh)
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

ijk_inl intlv ijkVecMod2ilvs(intl2 v_out, intl2 const v_lh, i64 const s_rh)
{
	v_out[0] = v_lh[0] % s_rh;
	v_out[1] = v_lh[1] % s_rh;
	return v_out;
}

ijk_inl intlv ijkVecModSafe2ilvs(intl2 v_out, intl2 const v_lh, i64 const s_rh)
{
	if (s_rh)
	{
		v_out[0] = v_lh[0] % s_rh;
		v_out[1] = v_lh[1] % s_rh;
		return v_out;
	}
	return ijkVecCopy2ilv(v_out, v_lh);
}

ijk_inl intlv ijkVecBitAnd2ilvs(intl2 v_out, intl2 const v_lh, i64 const s_rh)
{
	v_out[0] = (v_lh[0] & s_rh);
	v_out[1] = (v_lh[1] & s_rh);
	return v_out;
}

ijk_inl intlv ijkVecBitNand2ilvs(intl2 v_out, intl2 const v_lh, i64 const s_rh)
{
	v_out[0] = ~(v_lh[0] & s_rh);
	v_out[1] = ~(v_lh[1] & s_rh);
	return v_out;
}

ijk_inl intlv ijkVecBitOr2ilvs(intl2 v_out, intl2 const v_lh, i64 const s_rh)
{
	v_out[0] = (v_lh[0] | s_rh);
	v_out[1] = (v_lh[1] | s_rh);
	return v_out;
}

ijk_inl intlv ijkVecBitNor2ilvs(intl2 v_out, intl2 const v_lh, i64 const s_rh)
{
	v_out[0] = ~(v_lh[0] | s_rh);
	v_out[1] = ~(v_lh[1] | s_rh);
	return v_out;
}

ijk_inl intlv ijkVecBitXor2ilvs(intl2 v_out, intl2 const v_lh, i64 const s_rh)
{
	v_out[0] = (v_lh[0] ^ s_rh);
	v_out[1] = (v_lh[1] ^ s_rh);
	return v_out;
}

ijk_inl intlv ijkVecBitXnor2ilvs(intl2 v_out, intl2 const v_lh, i64 const s_rh)
{
	v_out[0] = ~(v_lh[0] ^ s_rh);
	v_out[1] = ~(v_lh[1] ^ s_rh);
	return v_out;
}

ijk_inl intlv ijkVecBitShiftLeft2ilvs(intl2 v_out, intl2 const v_lh, i64 const s_rh)
{
	v_out[0] = (v_lh[0] << s_rh);
	v_out[1] = (v_lh[1] << s_rh);
	return v_out;
}

ijk_inl intlv ijkVecBitShiftRight2ilvs(intl2 v_out, intl2 const v_lh, i64 const s_rh)
{
	v_out[0] = (v_lh[0] >> s_rh);
	v_out[1] = (v_lh[1] >> s_rh);
	return v_out;
}

ijk_inl boolv ijkVecEqual2ilvs(bool2 bv_out, intl2 const v_lh, i64 const s_rh)
{
	bv_out[0] = (v_lh[0] == s_rh);
	bv_out[1] = (v_lh[1] == s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecInequal2ilvs(bool2 bv_out, intl2 const v_lh, i64 const s_rh)
{
	bv_out[0] = (v_lh[0] != s_rh);
	bv_out[1] = (v_lh[1] != s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual2ilvs(bool2 bv_out, intl2 const v_lh, i64 const s_rh)
{
	bv_out[0] = (v_lh[0] <= s_rh);
	bv_out[1] = (v_lh[1] <= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual2ilvs(bool2 bv_out, intl2 const v_lh, i64 const s_rh)
{
	bv_out[0] = (v_lh[0] >= s_rh);
	bv_out[1] = (v_lh[1] >= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLess2ilvs(bool2 bv_out, intl2 const v_lh, i64 const s_rh)
{
	bv_out[0] = (v_lh[0] < s_rh);
	bv_out[1] = (v_lh[1] < s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreater2ilvs(bool2 bv_out, intl2 const v_lh, i64 const s_rh)
{
	bv_out[0] = (v_lh[0] > s_rh);
	bv_out[1] = (v_lh[1] > s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecAnd2ilvs(bool2 bv_out, intl2 const v_lh, i64 const s_rh)
{
	bv_out[0] = (v_lh[0] && s_rh);
	bv_out[1] = (v_lh[1] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNand2ilvs(bool2 bv_out, intl2 const v_lh, i64 const s_rh)
{
	bv_out[0] = !(v_lh[0] && s_rh);
	bv_out[1] = !(v_lh[1] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecOr2ilvs(bool2 bv_out, intl2 const v_lh, i64 const s_rh)
{
	bv_out[0] = (v_lh[0] || s_rh);
	bv_out[1] = (v_lh[1] || s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNor2ilvs(bool2 bv_out, intl2 const v_lh, i64 const s_rh)
{
	bv_out[0] = !(v_lh[0] || s_rh);
	bv_out[1] = !(v_lh[1] || s_rh);
	return bv_out;
}

ijk_inl intlv ijkVecAdd2ilsv(intl2 v_out, i64 const s_lh, intl2 const v_rh)
{
	v_out[0] = s_lh + v_rh[0];
	v_out[1] = s_lh + v_rh[1];
	return v_out;
}

ijk_inl intlv ijkVecSub2ilsv(intl2 v_out, i64 const s_lh, intl2 const v_rh)
{
	v_out[0] = s_lh - v_rh[0];
	v_out[1] = s_lh - v_rh[1];
	return v_out;
}

ijk_inl intlv ijkVecMul2ilsv(intl2 v_out, i64 const s_lh, intl2 const v_rh)
{
	v_out[0] = s_lh * v_rh[0];
	v_out[1] = s_lh * v_rh[1];
	return v_out;
}

ijk_inl intlv ijkVecDiv2ilsv(intl2 v_out, i64 const s_lh, intl2 const v_rh)
{
	v_out[0] = s_lh / v_rh[0];
	v_out[1] = s_lh / v_rh[1];
	return v_out;
}

ijk_inl intlv ijkVecDivSafe2ilsv(intl2 v_out, i64 const s_lh, intl2 const v_rh)
{
	v_out[0] = ijk_divide_safe_int(s_lh, v_rh[0]);
	v_out[1] = ijk_divide_safe_int(s_lh, v_rh[1]);
	return v_out;
}

ijk_inl intlv ijkVecMod2ilsv(intl2 v_out, i64 const s_lh, intl2 const v_rh)
{
	v_out[0] = s_lh % v_rh[0];
	v_out[1] = s_lh % v_rh[1];
	return v_out;
}

ijk_inl intlv ijkVecModSafe2ilsv(intl2 v_out, i64 const s_lh, intl2 const v_rh)
{
	v_out[0] = ijk_modulo_safe_int(s_lh, v_rh[0]);
	v_out[1] = ijk_modulo_safe_int(s_lh, v_rh[1]);
	return v_out;
}

ijk_inl intlv ijkVecBitAnd2ilsv(intl2 v_out, i64 const s_lh, intl2 const v_rh)
{
	v_out[0] = (s_lh & v_rh[0]);
	v_out[1] = (s_lh & v_rh[1]);
	return v_out;
}

ijk_inl intlv ijkVecBitNand2ilsv(intl2 v_out, i64 const s_lh, intl2 const v_rh)
{
	v_out[0] = ~(s_lh & v_rh[0]);
	v_out[1] = ~(s_lh & v_rh[1]);
	return v_out;
}

ijk_inl intlv ijkVecBitOr2ilsv(intl2 v_out, i64 const s_lh, intl2 const v_rh)
{
	v_out[0] = (s_lh | v_rh[0]);
	v_out[1] = (s_lh | v_rh[1]);
	return v_out;
}

ijk_inl intlv ijkVecBitNor2ilsv(intl2 v_out, i64 const s_lh, intl2 const v_rh)
{
	v_out[0] = ~(s_lh | v_rh[0]);
	v_out[1] = ~(s_lh | v_rh[1]);
	return v_out;
}

ijk_inl intlv ijkVecBitXor2ilsv(intl2 v_out, i64 const s_lh, intl2 const v_rh)
{
	v_out[0] = (s_lh ^ v_rh[0]);
	v_out[1] = (s_lh ^ v_rh[1]);
	return v_out;
}

ijk_inl intlv ijkVecBitXnor2ilsv(intl2 v_out, i64 const s_lh, intl2 const v_rh)
{
	v_out[0] = ~(s_lh ^ v_rh[0]);
	v_out[1] = ~(s_lh ^ v_rh[1]);
	return v_out;
}

ijk_inl intlv ijkVecBitShiftLeft2ilsv(intl2 v_out, i64 const s_lh, intl2 const v_rh)
{
	v_out[0] = (s_lh << v_rh[0]);
	v_out[1] = (s_lh << v_rh[1]);
	return v_out;
}

ijk_inl intlv ijkVecBitShiftRight2ilsv(intl2 v_out, i64 const s_lh, intl2 const v_rh)
{
	v_out[0] = (s_lh >> v_rh[0]);
	v_out[1] = (s_lh >> v_rh[1]);
	return v_out;
}

ijk_inl boolv ijkVecEqual2ilsv(bool2 bv_out, i64 const s_lh, intl2 const v_rh)
{
	bv_out[0] = (s_lh == v_rh[0]);
	bv_out[1] = (s_lh == v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal2ilsv(bool2 bv_out, i64 const s_lh, intl2 const v_rh)
{
	bv_out[0] = (s_lh != v_rh[0]);
	bv_out[1] = (s_lh != v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual2ilsv(bool2 bv_out, i64 const s_lh, intl2 const v_rh)
{
	bv_out[0] = (s_lh <= v_rh[0]);
	bv_out[1] = (s_lh <= v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual2ilsv(bool2 bv_out, i64 const s_lh, intl2 const v_rh)
{
	bv_out[0] = (s_lh >= v_rh[0]);
	bv_out[1] = (s_lh >= v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecLess2ilsv(bool2 bv_out, i64 const s_lh, intl2 const v_rh)
{
	bv_out[0] = (s_lh < v_rh[0]);
	bv_out[1] = (s_lh < v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater2ilsv(bool2 bv_out, i64 const s_lh, intl2 const v_rh)
{
	bv_out[0] = (s_lh > v_rh[0]);
	bv_out[1] = (s_lh > v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd2ilsv(bool2 bv_out, i64 const s_lh, intl2 const v_rh)
{
	bv_out[0] = (s_lh && v_rh[0]);
	bv_out[1] = (s_lh && v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecNand2ilsv(bool2 bv_out, i64 const s_lh, intl2 const v_rh)
{
	bv_out[0] = !(s_lh && v_rh[0]);
	bv_out[1] = !(s_lh && v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecOr2ilsv(bool2 bv_out, i64 const s_lh, intl2 const v_rh)
{
	bv_out[0] = (s_lh || v_rh[0]);
	bv_out[1] = (s_lh || v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecNor2ilsv(bool2 bv_out, i64 const s_lh, intl2 const v_rh)
{
	bv_out[0] = !(s_lh || v_rh[0]);
	bv_out[1] = !(s_lh || v_rh[1]);
	return bv_out;
}

ijk_inl i64 ijkVecDot2ilv(intl2 const v_lh, intl2 const v_rh)
{
	return (v_lh[0] * v_rh[0] + v_lh[1] * v_rh[1]);
}

ijk_inl i64 ijkVecCross2ilv(intl2 const v_lh, intl2 const v_rh)
{
	return (v_lh[0] * v_rh[1] - v_lh[1] * v_rh[0]);
}


//-----------------------------------------------------------------------------

ijk_inl intlv ijkVecInit3ilv(intl3 v_out)
{
	v_out[0] = v_out[1] = v_out[2] = 0;
	return v_out;
}

ijk_inl intlv ijkVecInitElems3ilv(intl3 v_out, i64 const x, i64 const y, i64 const z)
{
	v_out[0] = x;
	v_out[1] = y;
	v_out[2] = z;
	return v_out;
}

ijk_inl intlv ijkVecCopy3ilv(intl3 v_out, intl3 const v_in)
{
	v_out[0] = +v_in[0];
	v_out[1] = +v_in[1];
	v_out[2] = +v_in[2];
	return v_out;
}

ijk_inl intlv ijkVecNegate3ilv(intl3 v_out, intl3 const v_in)
{
	v_out[0] = -v_in[0];
	v_out[1] = -v_in[1];
	v_out[2] = -v_in[2];
	return v_out;
}

ijk_inl intlv ijkVecBitNot3ilv(intl3 v_out, intl3 const v_in)
{
	v_out[0] = ~v_in[0];
	v_out[1] = ~v_in[1];
	v_out[2] = ~v_in[2];
	return v_out;
}

ijk_inl boolv ijkVecNot3ilv(bool3 bv_out, intl3 const v_in)
{
	bv_out[0] = !v_in[0];
	bv_out[1] = !v_in[1];
	bv_out[2] = !v_in[2];
	return bv_out;
}

ijk_inl intlv ijkVecAdd3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh)
{
	v_out[0] = v_lh[0] + v_rh[0];
	v_out[1] = v_lh[1] + v_rh[1];
	v_out[2] = v_lh[2] + v_rh[2];
	return v_out;
}

ijk_inl intlv ijkVecSub3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh)
{
	v_out[0] = v_lh[0] - v_rh[0];
	v_out[1] = v_lh[1] - v_rh[1];
	v_out[2] = v_lh[2] - v_rh[2];
	return v_out;
}

ijk_inl intlv ijkVecMul3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh)
{
	v_out[0] = v_lh[0] * v_rh[0];
	v_out[1] = v_lh[1] * v_rh[1];
	v_out[2] = v_lh[2] * v_rh[2];
	return v_out;
}

ijk_inl intlv ijkVecDiv3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh)
{
	v_out[0] = v_lh[0] / v_rh[0];
	v_out[1] = v_lh[1] / v_rh[1];
	v_out[2] = v_lh[2] / v_rh[2];
	return v_out;
}

ijk_inl intlv ijkVecDivSafe3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh)
{
	v_out[0] = ijk_divide_safe_int(v_lh[0], v_rh[0]);
	v_out[1] = ijk_divide_safe_int(v_lh[1], v_rh[1]);
	v_out[2] = ijk_divide_safe_int(v_lh[2], v_rh[2]);
	return v_out;
}

ijk_inl intlv ijkVecMod3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh)
{
	v_out[0] = v_lh[0] % v_rh[0];
	v_out[1] = v_lh[1] % v_rh[1];
	v_out[2] = v_lh[2] % v_rh[2];
	return v_out;
}

ijk_inl intlv ijkVecModSafe3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh)
{
	v_out[0] = ijk_modulo_safe_int(v_lh[0], v_rh[0]);
	v_out[1] = ijk_modulo_safe_int(v_lh[1], v_rh[1]);
	v_out[2] = ijk_modulo_safe_int(v_lh[2], v_rh[2]);
	return v_out;
}

ijk_inl intlv ijkVecBitAnd3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh)
{
	v_out[0] = (v_lh[0] & v_rh[0]);
	v_out[1] = (v_lh[1] & v_rh[1]);
	v_out[2] = (v_lh[2] & v_rh[2]);
	return v_out;
}

ijk_inl intlv ijkVecBitNand3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh)
{
	v_out[0] = ~(v_lh[0] & v_rh[0]);
	v_out[1] = ~(v_lh[1] & v_rh[1]);
	v_out[2] = ~(v_lh[2] & v_rh[2]);
	return v_out;
}

ijk_inl intlv ijkVecBitOr3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh)
{
	v_out[0] = (v_lh[0] | v_rh[0]);
	v_out[1] = (v_lh[1] | v_rh[1]);
	v_out[2] = (v_lh[2] | v_rh[2]);
	return v_out;
}

ijk_inl intlv ijkVecBitNor3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh)
{
	v_out[0] = ~(v_lh[0] | v_rh[0]);
	v_out[1] = ~(v_lh[1] | v_rh[1]);
	v_out[2] = ~(v_lh[2] | v_rh[2]);
	return v_out;
}

ijk_inl intlv ijkVecBitXor3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh)
{
	v_out[0] = (v_lh[0] ^ v_rh[0]);
	v_out[1] = (v_lh[1] ^ v_rh[1]);
	v_out[2] = (v_lh[2] ^ v_rh[2]);
	return v_out;
}

ijk_inl intlv ijkVecBitXnor3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh)
{
	v_out[0] = ~(v_lh[0] ^ v_rh[0]);
	v_out[1] = ~(v_lh[1] ^ v_rh[1]);
	v_out[2] = ~(v_lh[2] ^ v_rh[2]);
	return v_out;
}

ijk_inl intlv ijkVecBitShiftLeft3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh)
{
	v_out[0] = (v_lh[0] << v_rh[0]);
	v_out[1] = (v_lh[1] << v_rh[1]);
	v_out[2] = (v_lh[2] << v_rh[2]);
	return v_out;
}

ijk_inl intlv ijkVecBitShiftRight3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh)
{
	v_out[0] = (v_lh[0] >> v_rh[0]);
	v_out[1] = (v_lh[1] >> v_rh[1]);
	v_out[2] = (v_lh[2] >> v_rh[2]);
	return v_out;
}

ijk_inl boolv ijkVecEqual3ilv(bool3 bv_out, intl3 const v_lh, intl3 const v_rh)
{
	bv_out[0] = (v_lh[0] == v_rh[0]);
	bv_out[1] = (v_lh[1] == v_rh[1]);
	bv_out[2] = (v_lh[2] == v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal3ilv(bool3 bv_out, intl3 const v_lh, intl3 const v_rh)
{
	bv_out[0] = (v_lh[0] != v_rh[0]);
	bv_out[1] = (v_lh[1] != v_rh[1]);
	bv_out[2] = (v_lh[2] != v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual3ilv(bool3 bv_out, intl3 const v_lh, intl3 const v_rh)
{
	bv_out[0] = (v_lh[0] <= v_rh[0]);
	bv_out[1] = (v_lh[1] <= v_rh[1]);
	bv_out[2] = (v_lh[2] <= v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual3ilv(bool3 bv_out, intl3 const v_lh, intl3 const v_rh)
{
	bv_out[0] = (v_lh[0] >= v_rh[0]);
	bv_out[1] = (v_lh[1] >= v_rh[1]);
	bv_out[2] = (v_lh[2] >= v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecLess3ilv(bool3 bv_out, intl3 const v_lh, intl3 const v_rh)
{
	bv_out[0] = (v_lh[0] < v_rh[0]);
	bv_out[1] = (v_lh[1] < v_rh[1]);
	bv_out[2] = (v_lh[2] < v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater3ilv(bool3 bv_out, intl3 const v_lh, intl3 const v_rh)
{
	bv_out[0] = (v_lh[0] > v_rh[0]);
	bv_out[1] = (v_lh[1] > v_rh[1]);
	bv_out[2] = (v_lh[2] > v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd3ilv(bool3 bv_out, intl3 const v_lh, intl3 const v_rh)
{
	bv_out[0] = (v_lh[0] && v_rh[0]);
	bv_out[1] = (v_lh[1] && v_rh[1]);
	bv_out[2] = (v_lh[2] && v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecNand3ilv(bool3 bv_out, intl3 const v_lh, intl3 const v_rh)
{
	bv_out[0] = !(v_lh[0] && v_rh[0]);
	bv_out[1] = !(v_lh[1] && v_rh[1]);
	bv_out[2] = !(v_lh[2] && v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecOr3ilv(bool3 bv_out, intl3 const v_lh, intl3 const v_rh)
{
	bv_out[0] = (v_lh[0] || v_rh[0]);
	bv_out[1] = (v_lh[1] || v_rh[1]);
	bv_out[2] = (v_lh[2] || v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecNor3ilv(bool3 bv_out, intl3 const v_lh, intl3 const v_rh)
{
	bv_out[0] = !(v_lh[0] || v_rh[0]);
	bv_out[1] = !(v_lh[1] || v_rh[1]);
	bv_out[2] = !(v_lh[2] || v_rh[2]);
	return bv_out;
}

ijk_inl intlv ijkVecCopy3ilvz(intl3 v_out, intl2 const v_xy, i64 const z)
{
	v_out[0] = v_xy[0];
	v_out[1] = v_xy[1];
	v_out[2] = z;
	return v_out;
}

ijk_inl intlv ijkVecCopy3ilvs(intl3 v_out, i64 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = +s_in;
	return v_out;
}

ijk_inl intlv ijkVecNegate3ilvs(intl3 v_out, i64 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = -s_in;
	return v_out;
}

ijk_inl intlv ijkVecBitNot3ilvs(intl3 v_out, i64 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = ~s_in;
	return v_out;
}

ijk_inl boolv ijkVecNot3ilvs(bool3 bv_out, i64 const s_in)
{
	bv_out[0] = bv_out[1] = bv_out[2] = !s_in;
	return bv_out;
}

ijk_inl intlv ijkVecAdd3ilvs(intl3 v_out, intl3 const v_lh, i64 const s_rh)
{
	v_out[0] = v_lh[0] + s_rh;
	v_out[1] = v_lh[1] + s_rh;
	v_out[2] = v_lh[2] + s_rh;
	return v_out;
}

ijk_inl intlv ijkVecSub3ilvs(intl3 v_out, intl3 const v_lh, i64 const s_rh)
{
	v_out[0] = v_lh[0] - s_rh;
	v_out[1] = v_lh[1] - s_rh;
	v_out[2] = v_lh[2] - s_rh;
	return v_out;
}

ijk_inl intlv ijkVecMul3ilvs(intl3 v_out, intl3 const v_lh, i64 const s_rh)
{
	v_out[0] = v_lh[0] * s_rh;
	v_out[1] = v_lh[1] * s_rh;
	v_out[2] = v_lh[2] * s_rh;
	return v_out;
}

ijk_inl intlv ijkVecDiv3ilvs(intl3 v_out, intl3 const v_lh, i64 const s_rh)
{
	v_out[0] = v_lh[0] / s_rh;
	v_out[1] = v_lh[1] / s_rh;
	v_out[2] = v_lh[2] / s_rh;
	return v_out;
}

ijk_inl intlv ijkVecDivSafe3ilvs(intl3 v_out, intl3 const v_lh, i64 const s_rh)
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

ijk_inl intlv ijkVecMod3ilvs(intl3 v_out, intl3 const v_lh, i64 const s_rh)
{
	v_out[0] = v_lh[0] % s_rh;
	v_out[1] = v_lh[1] % s_rh;
	v_out[2] = v_lh[2] % s_rh;
	return v_out;
}

ijk_inl intlv ijkVecModSafe3ilvs(intl3 v_out, intl3 const v_lh, i64 const s_rh)
{
	if (s_rh)
	{
		v_out[0] = v_lh[0] % s_rh;
		v_out[1] = v_lh[1] % s_rh;
		v_out[2] = v_lh[2] % s_rh;
		return v_out;
	}
	return ijkVecCopy3ilv(v_out, v_lh);
}

ijk_inl intlv ijkVecBitAnd3ilvs(intl3 v_out, intl3 const v_lh, i64 const s_rh)
{
	v_out[0] = (v_lh[0] & s_rh);
	v_out[1] = (v_lh[1] & s_rh);
	v_out[2] = (v_lh[2] & s_rh);
	return v_out;
}

ijk_inl intlv ijkVecBitNand3ilvs(intl3 v_out, intl3 const v_lh, i64 const s_rh)
{
	v_out[0] = ~(v_lh[0] & s_rh);
	v_out[1] = ~(v_lh[1] & s_rh);
	v_out[2] = ~(v_lh[2] & s_rh);
	return v_out;
}

ijk_inl intlv ijkVecBitOr3ilvs(intl3 v_out, intl3 const v_lh, i64 const s_rh)
{
	v_out[0] = (v_lh[0] | s_rh);
	v_out[1] = (v_lh[1] | s_rh);
	v_out[2] = (v_lh[2] | s_rh);
	return v_out;
}

ijk_inl intlv ijkVecBitNor3ilvs(intl3 v_out, intl3 const v_lh, i64 const s_rh)
{
	v_out[0] = ~(v_lh[0] | s_rh);
	v_out[1] = ~(v_lh[1] | s_rh);
	v_out[2] = ~(v_lh[2] | s_rh);
	return v_out;
}

ijk_inl intlv ijkVecBitXor3ilvs(intl3 v_out, intl3 const v_lh, i64 const s_rh)
{
	v_out[0] = (v_lh[0] ^ s_rh);
	v_out[1] = (v_lh[1] ^ s_rh);
	v_out[2] = (v_lh[2] ^ s_rh);
	return v_out;
}

ijk_inl intlv ijkVecBitXnor3ilvs(intl3 v_out, intl3 const v_lh, i64 const s_rh)
{
	v_out[0] = ~(v_lh[0] ^ s_rh);
	v_out[1] = ~(v_lh[1] ^ s_rh);
	v_out[2] = ~(v_lh[2] ^ s_rh);
	return v_out;
}

ijk_inl intlv ijkVecBitShiftLeft3ilvs(intl3 v_out, intl3 const v_lh, i64 const s_rh)
{
	v_out[0] = (v_lh[0] << s_rh);
	v_out[1] = (v_lh[1] << s_rh);
	v_out[2] = (v_lh[2] << s_rh);
	return v_out;
}

ijk_inl intlv ijkVecBitShiftRight3ilvs(intl3 v_out, intl3 const v_lh, i64 const s_rh)
{
	v_out[0] = (v_lh[0] >> s_rh);
	v_out[1] = (v_lh[1] >> s_rh);
	v_out[2] = (v_lh[2] >> s_rh);
	return v_out;
}

ijk_inl boolv ijkVecEqual3ilvs(bool3 bv_out, intl3 const v_lh, i64 const s_rh)
{
	bv_out[0] = (v_lh[0] == s_rh);
	bv_out[1] = (v_lh[1] == s_rh);
	bv_out[2] = (v_lh[2] == s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecInequal3ilvs(bool3 bv_out, intl3 const v_lh, i64 const s_rh)
{
	bv_out[0] = (v_lh[0] != s_rh);
	bv_out[1] = (v_lh[1] != s_rh);
	bv_out[2] = (v_lh[2] != s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual3ilvs(bool3 bv_out, intl3 const v_lh, i64 const s_rh)
{
	bv_out[0] = (v_lh[0] <= s_rh);
	bv_out[1] = (v_lh[1] <= s_rh);
	bv_out[2] = (v_lh[2] <= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual3ilvs(bool3 bv_out, intl3 const v_lh, i64 const s_rh)
{
	bv_out[0] = (v_lh[0] >= s_rh);
	bv_out[1] = (v_lh[1] >= s_rh);
	bv_out[2] = (v_lh[2] >= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLess3ilvs(bool3 bv_out, intl3 const v_lh, i64 const s_rh)
{
	bv_out[0] = (v_lh[0] < s_rh);
	bv_out[1] = (v_lh[1] < s_rh);
	bv_out[2] = (v_lh[2] < s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreater3ilvs(bool3 bv_out, intl3 const v_lh, i64 const s_rh)
{
	bv_out[0] = (v_lh[0] > s_rh);
	bv_out[1] = (v_lh[1] > s_rh);
	bv_out[2] = (v_lh[2] > s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecAnd3ilvs(bool3 bv_out, intl3 const v_lh, i64 const s_rh)
{
	bv_out[0] = (v_lh[0] && s_rh);
	bv_out[1] = (v_lh[1] && s_rh);
	bv_out[2] = (v_lh[2] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNand3ilvs(bool3 bv_out, intl3 const v_lh, i64 const s_rh)
{
	bv_out[0] = !(v_lh[0] && s_rh);
	bv_out[1] = !(v_lh[1] && s_rh);
	bv_out[2] = !(v_lh[2] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecOr3ilvs(bool3 bv_out, intl3 const v_lh, i64 const s_rh)
{
	bv_out[0] = (v_lh[0] || s_rh);
	bv_out[1] = (v_lh[1] || s_rh);
	bv_out[2] = (v_lh[2] || s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNor3ilvs(bool3 bv_out, intl3 const v_lh, i64 const s_rh)
{
	bv_out[0] = !(v_lh[0] || s_rh);
	bv_out[1] = !(v_lh[1] || s_rh);
	bv_out[2] = !(v_lh[2] || s_rh);
	return bv_out;
}

ijk_inl intlv ijkVecCopy3ilxv(intl3 v_out, i64 const x, intl2 const v_yz)
{
	v_out[0] = x;
	v_out[1] = v_yz[0];
	v_out[2] = v_yz[1];
	return v_out;
}

ijk_inl intlv ijkVecAdd3ilsv(intl3 v_out, i64 const s_lh, intl3 const v_rh)
{
	v_out[0] = s_lh + v_rh[0];
	v_out[1] = s_lh + v_rh[1];
	v_out[2] = s_lh + v_rh[2];
	return v_out;
}

ijk_inl intlv ijkVecSub3ilsv(intl3 v_out, i64 const s_lh, intl3 const v_rh)
{
	v_out[0] = s_lh - v_rh[0];
	v_out[1] = s_lh - v_rh[1];
	v_out[2] = s_lh - v_rh[2];
	return v_out;
}

ijk_inl intlv ijkVecMul3ilsv(intl3 v_out, i64 const s_lh, intl3 const v_rh)
{
	v_out[0] = s_lh * v_rh[0];
	v_out[1] = s_lh * v_rh[1];
	v_out[2] = s_lh * v_rh[2];
	return v_out;
}

ijk_inl intlv ijkVecDiv3ilsv(intl3 v_out, i64 const s_lh, intl3 const v_rh)
{
	v_out[0] = s_lh / v_rh[0];
	v_out[1] = s_lh / v_rh[1];
	v_out[2] = s_lh / v_rh[2];
	return v_out;
}

ijk_inl intlv ijkVecDivSafe3ilsv(intl3 v_out, i64 const s_lh, intl3 const v_rh)
{
	v_out[0] = ijk_divide_safe_int(s_lh, v_rh[0]);
	v_out[1] = ijk_divide_safe_int(s_lh, v_rh[1]);
	v_out[2] = ijk_divide_safe_int(s_lh, v_rh[2]);
	return v_out;
}

ijk_inl intlv ijkVecMod3ilsv(intl3 v_out, i64 const s_lh, intl3 const v_rh)
{
	v_out[0] = s_lh % v_rh[0];
	v_out[1] = s_lh % v_rh[1];
	v_out[2] = s_lh % v_rh[2];
	return v_out;
}

ijk_inl intlv ijkVecModSafe3ilsv(intl3 v_out, i64 const s_lh, intl3 const v_rh)
{
	v_out[0] = ijk_modulo_safe_int(s_lh, v_rh[0]);
	v_out[1] = ijk_modulo_safe_int(s_lh, v_rh[1]);
	v_out[2] = ijk_modulo_safe_int(s_lh, v_rh[2]);
	return v_out;
}

ijk_inl intlv ijkVecBitAnd3ilsv(intl3 v_out, i64 const s_lh, intl3 const v_rh)
{
	v_out[0] = (s_lh & v_rh[0]);
	v_out[1] = (s_lh & v_rh[1]);
	v_out[2] = (s_lh & v_rh[2]);
	return v_out;
}

ijk_inl intlv ijkVecBitNand3ilsv(intl3 v_out, i64 const s_lh, intl3 const v_rh)
{
	v_out[0] = ~(s_lh & v_rh[0]);
	v_out[1] = ~(s_lh & v_rh[1]);
	v_out[2] = ~(s_lh & v_rh[2]);
	return v_out;
}

ijk_inl intlv ijkVecBitOr3ilsv(intl3 v_out, i64 const s_lh, intl3 const v_rh)
{
	v_out[0] = (s_lh | v_rh[0]);
	v_out[1] = (s_lh | v_rh[1]);
	v_out[2] = (s_lh | v_rh[2]);
	return v_out;
}

ijk_inl intlv ijkVecBitNor3ilsv(intl3 v_out, i64 const s_lh, intl3 const v_rh)
{
	v_out[0] = ~(s_lh | v_rh[0]);
	v_out[1] = ~(s_lh | v_rh[1]);
	v_out[2] = ~(s_lh | v_rh[2]);
	return v_out;
}

ijk_inl intlv ijkVecBitXor3ilsv(intl3 v_out, i64 const s_lh, intl3 const v_rh)
{
	v_out[0] = (s_lh ^ v_rh[0]);
	v_out[1] = (s_lh ^ v_rh[1]);
	v_out[2] = (s_lh ^ v_rh[2]);
	return v_out;
}

ijk_inl intlv ijkVecBitXnor3ilsv(intl3 v_out, i64 const s_lh, intl3 const v_rh)
{
	v_out[0] = ~(s_lh ^ v_rh[0]);
	v_out[1] = ~(s_lh ^ v_rh[1]);
	v_out[2] = ~(s_lh ^ v_rh[2]);
	return v_out;
}

ijk_inl intlv ijkVecBitShiftLeft3ilsv(intl3 v_out, i64 const s_lh, intl3 const v_rh)
{
	v_out[0] = (s_lh << v_rh[0]);
	v_out[1] = (s_lh << v_rh[1]);
	v_out[2] = (s_lh << v_rh[2]);
	return v_out;
}

ijk_inl intlv ijkVecBitShiftRight3ilsv(intl3 v_out, i64 const s_lh, intl3 const v_rh)
{
	v_out[0] = (s_lh >> v_rh[0]);
	v_out[1] = (s_lh >> v_rh[1]);
	v_out[2] = (s_lh >> v_rh[2]);
	return v_out;
}

ijk_inl boolv ijkVecEqual3ilsv(bool3 bv_out, i64 const s_lh, intl3 const v_rh)
{
	bv_out[0] = (s_lh == v_rh[0]);
	bv_out[1] = (s_lh == v_rh[1]);
	bv_out[2] = (s_lh == v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal3ilsv(bool3 bv_out, i64 const s_lh, intl3 const v_rh)
{
	bv_out[0] = (s_lh != v_rh[0]);
	bv_out[1] = (s_lh != v_rh[1]);
	bv_out[2] = (s_lh != v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual3ilsv(bool3 bv_out, i64 const s_lh, intl3 const v_rh)
{
	bv_out[0] = (s_lh <= v_rh[0]);
	bv_out[1] = (s_lh <= v_rh[1]);
	bv_out[2] = (s_lh <= v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual3ilsv(bool3 bv_out, i64 const s_lh, intl3 const v_rh)
{
	bv_out[0] = (s_lh >= v_rh[0]);
	bv_out[1] = (s_lh >= v_rh[1]);
	bv_out[2] = (s_lh >= v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecLess3ilsv(bool3 bv_out, i64 const s_lh, intl3 const v_rh)
{
	bv_out[0] = (s_lh < v_rh[0]);
	bv_out[1] = (s_lh < v_rh[1]);
	bv_out[2] = (s_lh < v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater3ilsv(bool3 bv_out, i64 const s_lh, intl3 const v_rh)
{
	bv_out[0] = (s_lh > v_rh[0]);
	bv_out[1] = (s_lh > v_rh[1]);
	bv_out[2] = (s_lh > v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd3ilsv(bool3 bv_out, i64 const s_lh, intl3 const v_rh)
{
	bv_out[0] = (s_lh && v_rh[0]);
	bv_out[1] = (s_lh && v_rh[1]);
	bv_out[2] = (s_lh && v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecNand3ilsv(bool3 bv_out, i64 const s_lh, intl3 const v_rh)
{
	bv_out[0] = !(s_lh && v_rh[0]);
	bv_out[1] = !(s_lh && v_rh[1]);
	bv_out[2] = !(s_lh && v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecOr3ilsv(bool3 bv_out, i64 const s_lh, intl3 const v_rh)
{
	bv_out[0] = (s_lh || v_rh[0]);
	bv_out[1] = (s_lh || v_rh[1]);
	bv_out[2] = (s_lh || v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecNor3ilsv(bool3 bv_out, i64 const s_lh, intl3 const v_rh)
{
	bv_out[0] = !(s_lh || v_rh[0]);
	bv_out[1] = !(s_lh || v_rh[1]);
	bv_out[2] = !(s_lh || v_rh[2]);
	return bv_out;
}

ijk_inl i64 ijkVecDot3ilv(intl3 const v_lh, intl3 const v_rh)
{
	return (v_lh[0] * v_rh[0] + v_lh[1] * v_rh[1] + v_lh[2] * v_rh[2]);
}

ijk_inl intlv ijkVecCross3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh)
{
	v_out[0] = (v_lh[1] * v_rh[2] - v_lh[2] * v_rh[1]);
	v_out[1] = (v_lh[2] * v_rh[0] - v_lh[0] * v_rh[2]);
	v_out[2] = (v_lh[0] * v_rh[1] - v_lh[1] * v_rh[0]);
	return v_out;
}


//-----------------------------------------------------------------------------

ijk_inl intlv ijkVecInit4ilv(intl4 v_out)
{
	v_out[0] = v_out[1] = v_out[2] = v_out[3] = 0;
	return v_out;
}

ijk_inl intlv ijkVecInitElems4ilv(intl4 v_out, i64 const x, i64 const y, i64 const z, i64 const w)
{
	v_out[0] = x;
	v_out[1] = y;
	v_out[2] = z;
	v_out[3] = w;
	return v_out;
}

ijk_inl intlv ijkVecCopy4ilxvw(intl4 v_out, i64 const x, intl2 const v_yz, i64 const w)
{
	v_out[0] = x;
	v_out[1] = v_yz[0];
	v_out[2] = v_yz[1];
	v_out[3] = w;
	return v_out;
}

ijk_inl intlv ijkVecCopy4ilv2(intl4 v_out, intl2 const v_xy, intl2 const v_zw)
{
	v_out[0] = v_xy[0];
	v_out[1] = v_xy[1];
	v_out[2] = v_zw[0];
	v_out[3] = v_zw[1];
	return v_out;
}

ijk_inl intlv ijkVecCopy4ilv(intl4 v_out, intl4 const v_in)
{
	v_out[0] = +v_in[0];
	v_out[1] = +v_in[1];
	v_out[2] = +v_in[2];
	v_out[3] = +v_in[3];
	return v_out;
}

ijk_inl intlv ijkVecNegate4ilv(intl4 v_out, intl4 const v_in)
{
	v_out[0] = -v_in[0];
	v_out[1] = -v_in[1];
	v_out[2] = -v_in[2];
	v_out[3] = -v_in[3];
	return v_out;
}

ijk_inl intlv ijkVecBitNot4ilv(intl4 v_out, intl4 const v_in)
{
	v_out[0] = ~v_in[0];
	v_out[1] = ~v_in[1];
	v_out[2] = ~v_in[2];
	v_out[3] = ~v_in[3];
	return v_out;
}

ijk_inl boolv ijkVecNot4ilv(bool4 bv_out, intl4 const v_in)
{
	bv_out[0] = !v_in[0];
	bv_out[1] = !v_in[1];
	bv_out[2] = !v_in[2];
	bv_out[3] = !v_in[3];
	return bv_out;
}

ijk_inl intlv ijkVecAdd4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh)
{
	v_out[0] = v_lh[0] + v_rh[0];
	v_out[1] = v_lh[1] + v_rh[1];
	v_out[2] = v_lh[2] + v_rh[2];
	v_out[3] = v_lh[3] + v_rh[3];
	return v_out;
}

ijk_inl intlv ijkVecSub4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh)
{
	v_out[0] = v_lh[0] - v_rh[0];
	v_out[1] = v_lh[1] - v_rh[1];
	v_out[2] = v_lh[2] - v_rh[2];
	v_out[3] = v_lh[3] - v_rh[3];
	return v_out;
}

ijk_inl intlv ijkVecMul4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh)
{
	v_out[0] = v_lh[0] * v_rh[0];
	v_out[1] = v_lh[1] * v_rh[1];
	v_out[2] = v_lh[2] * v_rh[2];
	v_out[3] = v_lh[3] * v_rh[3];
	return v_out;
}

ijk_inl intlv ijkVecDiv4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh)
{
	v_out[0] = v_lh[0] / v_rh[0];
	v_out[1] = v_lh[1] / v_rh[1];
	v_out[2] = v_lh[2] / v_rh[2];
	v_out[3] = v_lh[3] / v_rh[3];
	return v_out;
}

ijk_inl intlv ijkVecDivSafe4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh)
{
	v_out[0] = ijk_divide_safe_int(v_lh[0], v_rh[0]);
	v_out[1] = ijk_divide_safe_int(v_lh[1], v_rh[1]);
	v_out[2] = ijk_divide_safe_int(v_lh[2], v_rh[2]);
	v_out[3] = ijk_divide_safe_int(v_lh[3], v_rh[3]);
	return v_out;
}

ijk_inl intlv ijkVecMod4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh)
{
	v_out[0] = v_lh[0] % v_rh[0];
	v_out[1] = v_lh[1] % v_rh[1];
	v_out[2] = v_lh[2] % v_rh[2];
	v_out[3] = v_lh[3] % v_rh[3];
	return v_out;
}

ijk_inl intlv ijkVecModSafe4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh)
{
	v_out[0] = ijk_modulo_safe_int(v_lh[0], v_rh[0]);
	v_out[1] = ijk_modulo_safe_int(v_lh[1], v_rh[1]);
	v_out[2] = ijk_modulo_safe_int(v_lh[2], v_rh[2]);
	v_out[3] = ijk_modulo_safe_int(v_lh[3], v_rh[3]);
	return v_out;
}

ijk_inl intlv ijkVecBitAnd4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh)
{
	v_out[0] = (v_lh[0] & v_rh[0]);
	v_out[1] = (v_lh[1] & v_rh[1]);
	v_out[2] = (v_lh[2] & v_rh[2]);
	v_out[3] = (v_lh[3] & v_rh[3]);
	return v_out;
}

ijk_inl intlv ijkVecBitNand4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh)
{
	v_out[0] = ~(v_lh[0] & v_rh[0]);
	v_out[1] = ~(v_lh[1] & v_rh[1]);
	v_out[2] = ~(v_lh[2] & v_rh[2]);
	v_out[3] = ~(v_lh[3] & v_rh[3]);
	return v_out;
}

ijk_inl intlv ijkVecBitOr4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh)
{
	v_out[0] = (v_lh[0] | v_rh[0]);
	v_out[1] = (v_lh[1] | v_rh[1]);
	v_out[2] = (v_lh[2] | v_rh[2]);
	v_out[3] = (v_lh[3] | v_rh[3]);
	return v_out;
}

ijk_inl intlv ijkVecBitNor4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh)
{
	v_out[0] = ~(v_lh[0] | v_rh[0]);
	v_out[1] = ~(v_lh[1] | v_rh[1]);
	v_out[2] = ~(v_lh[2] | v_rh[2]);
	v_out[3] = ~(v_lh[3] | v_rh[3]);
	return v_out;
}

ijk_inl intlv ijkVecBitXor4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh)
{
	v_out[0] = (v_lh[0] ^ v_rh[0]);
	v_out[1] = (v_lh[1] ^ v_rh[1]);
	v_out[2] = (v_lh[2] ^ v_rh[2]);
	v_out[3] = (v_lh[3] ^ v_rh[3]);
	return v_out;
}

ijk_inl intlv ijkVecBitXnor4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh)
{
	v_out[0] = ~(v_lh[0] ^ v_rh[0]);
	v_out[1] = ~(v_lh[1] ^ v_rh[1]);
	v_out[2] = ~(v_lh[2] ^ v_rh[2]);
	v_out[3] = ~(v_lh[3] ^ v_rh[3]);
	return v_out;
}

ijk_inl intlv ijkVecBitShiftLeft4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh)
{
	v_out[0] = (v_lh[0] << v_rh[0]);
	v_out[1] = (v_lh[1] << v_rh[1]);
	v_out[2] = (v_lh[2] << v_rh[2]);
	v_out[3] = (v_lh[3] << v_rh[3]);
	return v_out;
}

ijk_inl intlv ijkVecBitShiftRight4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh)
{
	v_out[0] = (v_lh[0] >> v_rh[0]);
	v_out[1] = (v_lh[1] >> v_rh[1]);
	v_out[2] = (v_lh[2] >> v_rh[2]);
	v_out[3] = (v_lh[3] >> v_rh[3]);
	return v_out;
}

ijk_inl boolv ijkVecEqual4ilv(bool4 bv_out, intl4 const v_lh, intl4 const v_rh)
{
	bv_out[0] = (v_lh[0] == v_rh[0]);
	bv_out[1] = (v_lh[1] == v_rh[1]);
	bv_out[2] = (v_lh[2] == v_rh[2]);
	bv_out[3] = (v_lh[3] == v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal4ilv(bool4 bv_out, intl4 const v_lh, intl4 const v_rh)
{
	bv_out[0] = (v_lh[0] != v_rh[0]);
	bv_out[1] = (v_lh[1] != v_rh[1]);
	bv_out[2] = (v_lh[2] != v_rh[2]);
	bv_out[3] = (v_lh[3] != v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual4ilv(bool4 bv_out, intl4 const v_lh, intl4 const v_rh)
{
	bv_out[0] = (v_lh[0] <= v_rh[0]);
	bv_out[1] = (v_lh[1] <= v_rh[1]);
	bv_out[2] = (v_lh[2] <= v_rh[2]);
	bv_out[3] = (v_lh[3] <= v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual4ilv(bool4 bv_out, intl4 const v_lh, intl4 const v_rh)
{
	bv_out[0] = (v_lh[0] >= v_rh[0]);
	bv_out[1] = (v_lh[1] >= v_rh[1]);
	bv_out[2] = (v_lh[2] >= v_rh[2]);
	bv_out[3] = (v_lh[3] >= v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecLess4ilv(bool4 bv_out, intl4 const v_lh, intl4 const v_rh)
{
	bv_out[0] = (v_lh[0] < v_rh[0]);
	bv_out[1] = (v_lh[1] < v_rh[1]);
	bv_out[2] = (v_lh[2] < v_rh[2]);
	bv_out[3] = (v_lh[3] < v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater4ilv(bool4 bv_out, intl4 const v_lh, intl4 const v_rh)
{
	bv_out[0] = (v_lh[0] > v_rh[0]);
	bv_out[1] = (v_lh[1] > v_rh[1]);
	bv_out[2] = (v_lh[2] > v_rh[2]);
	bv_out[3] = (v_lh[3] > v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd4ilv(bool4 bv_out, intl4 const v_lh, intl4 const v_rh)
{
	bv_out[0] = (v_lh[0] && v_rh[0]);
	bv_out[1] = (v_lh[1] && v_rh[1]);
	bv_out[2] = (v_lh[2] && v_rh[2]);
	bv_out[3] = (v_lh[3] && v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecNand4ilv(bool4 bv_out, intl4 const v_lh, intl4 const v_rh)
{
	bv_out[0] = !(v_lh[0] && v_rh[0]);
	bv_out[1] = !(v_lh[1] && v_rh[1]);
	bv_out[2] = !(v_lh[2] && v_rh[2]);
	bv_out[3] = !(v_lh[3] && v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecOr4ilv(bool4 bv_out, intl4 const v_lh, intl4 const v_rh)
{
	bv_out[0] = (v_lh[0] || v_rh[0]);
	bv_out[1] = (v_lh[1] || v_rh[1]);
	bv_out[2] = (v_lh[2] || v_rh[2]);
	bv_out[3] = (v_lh[3] || v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecNor4ilv(bool4 bv_out, intl4 const v_lh, intl4 const v_rh)
{
	bv_out[0] = !(v_lh[0] || v_rh[0]);
	bv_out[1] = !(v_lh[1] || v_rh[1]);
	bv_out[2] = !(v_lh[2] || v_rh[2]);
	bv_out[3] = !(v_lh[3] || v_rh[3]);
	return bv_out;
}

ijk_inl intlv ijkVecCopy4ilvzw(intl4 v_out, intl2 const v_xy, i64 const z, i64 const w)
{
	v_out[0] = v_xy[0];
	v_out[1] = v_xy[1];
	v_out[2] = z;
	v_out[3] = w;
	return v_out;
}

ijk_inl intlv ijkVecCopy4ilvw(intl4 v_out, intl3 const v_xyz, i64 const w)
{
	v_out[0] = v_xyz[0];
	v_out[1] = v_xyz[1];
	v_out[2] = v_xyz[2];
	v_out[3] = w;
	return v_out;
}

ijk_inl intlv ijkVecCopy4ilvs(intl4 v_out, i64 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = v_out[3] = +s_in;
	return v_out;
}

ijk_inl intlv ijkVecNegate4ilvs(intl4 v_out, i64 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = v_out[3] = -s_in;
	return v_out;
}

ijk_inl intlv ijkVecBitNot4ilvs(intl4 v_out, i64 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = v_out[3] = ~s_in;
	return v_out;
}

ijk_inl boolv ijkVecNot4ilvs(bool4 bv_out, i64 const s_in)
{
	bv_out[0] = bv_out[1] = bv_out[2] = bv_out[3] = !s_in;
	return bv_out;
}

ijk_inl intlv ijkVecAdd4ilvs(intl4 v_out, intl4 const v_lh, i64 const s_rh)
{
	v_out[0] = v_lh[0] + s_rh;
	v_out[1] = v_lh[1] + s_rh;
	v_out[2] = v_lh[2] + s_rh;
	v_out[3] = v_lh[3] + s_rh;
	return v_out;
}

ijk_inl intlv ijkVecSub4ilvs(intl4 v_out, intl4 const v_lh, i64 const s_rh)
{
	v_out[0] = v_lh[0] - s_rh;
	v_out[1] = v_lh[1] - s_rh;
	v_out[2] = v_lh[2] - s_rh;
	v_out[3] = v_lh[3] - s_rh;
	return v_out;
}

ijk_inl intlv ijkVecMul4ilvs(intl4 v_out, intl4 const v_lh, i64 const s_rh)
{
	v_out[0] = v_lh[0] * s_rh;
	v_out[1] = v_lh[1] * s_rh;
	v_out[2] = v_lh[2] * s_rh;
	v_out[3] = v_lh[3] * s_rh;
	return v_out;
}

ijk_inl intlv ijkVecDiv4ilvs(intl4 v_out, intl4 const v_lh, i64 const s_rh)
{
	v_out[0] = v_lh[0] / s_rh;
	v_out[1] = v_lh[1] / s_rh;
	v_out[2] = v_lh[2] / s_rh;
	v_out[3] = v_lh[3] / s_rh;
	return v_out;
}

ijk_inl intlv ijkVecDivSafe4ilvs(intl4 v_out, intl4 const v_lh, i64 const s_rh)
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

ijk_inl intlv ijkVecMod4ilvs(intl4 v_out, intl4 const v_lh, i64 const s_rh)
{
	v_out[0] = v_lh[0] % s_rh;
	v_out[1] = v_lh[1] % s_rh;
	v_out[2] = v_lh[2] % s_rh;
	v_out[3] = v_lh[3] % s_rh;
	return v_out;
}

ijk_inl intlv ijkVecModSafe4ilvs(intl4 v_out, intl4 const v_lh, i64 const s_rh)
{
	if (s_rh)
	{
		v_out[0] = v_lh[0] % s_rh;
		v_out[1] = v_lh[1] % s_rh;
		v_out[2] = v_lh[2] % s_rh;
		v_out[3] = v_lh[3] % s_rh;
		return v_out;
	}
	return ijkVecCopy4ilv(v_out, v_lh);
}

ijk_inl intlv ijkVecBitAnd4ilvs(intl4 v_out, intl4 const v_lh, i64 const s_rh)
{
	v_out[0] = (v_lh[0] & s_rh);
	v_out[1] = (v_lh[1] & s_rh);
	v_out[2] = (v_lh[2] & s_rh);
	v_out[3] = (v_lh[3] & s_rh);
	return v_out;
}

ijk_inl intlv ijkVecBitNand4ilvs(intl4 v_out, intl4 const v_lh, i64 const s_rh)
{
	v_out[0] = ~(v_lh[0] & s_rh);
	v_out[1] = ~(v_lh[1] & s_rh);
	v_out[2] = ~(v_lh[2] & s_rh);
	v_out[3] = ~(v_lh[3] & s_rh);
	return v_out;
}

ijk_inl intlv ijkVecBitOr4ilvs(intl4 v_out, intl4 const v_lh, i64 const s_rh)
{
	v_out[0] = (v_lh[0] | s_rh);
	v_out[1] = (v_lh[1] | s_rh);
	v_out[2] = (v_lh[2] | s_rh);
	v_out[3] = (v_lh[3] | s_rh);
	return v_out;
}

ijk_inl intlv ijkVecBitNor4ilvs(intl4 v_out, intl4 const v_lh, i64 const s_rh)
{
	v_out[0] = ~(v_lh[0] | s_rh);
	v_out[1] = ~(v_lh[1] | s_rh);
	v_out[2] = ~(v_lh[2] | s_rh);
	v_out[3] = ~(v_lh[3] | s_rh);
	return v_out;
}

ijk_inl intlv ijkVecBitXor4ilvs(intl4 v_out, intl4 const v_lh, i64 const s_rh)
{
	v_out[0] = (v_lh[0] ^ s_rh);
	v_out[1] = (v_lh[1] ^ s_rh);
	v_out[2] = (v_lh[2] ^ s_rh);
	v_out[3] = (v_lh[3] ^ s_rh);
	return v_out;
}

ijk_inl intlv ijkVecBitXnor4ilvs(intl4 v_out, intl4 const v_lh, i64 const s_rh)
{
	v_out[0] = ~(v_lh[0] ^ s_rh);
	v_out[1] = ~(v_lh[1] ^ s_rh);
	v_out[2] = ~(v_lh[2] ^ s_rh);
	v_out[3] = ~(v_lh[3] ^ s_rh);
	return v_out;
}

ijk_inl intlv ijkVecBitShiftLeft4ilvs(intl4 v_out, intl4 const v_lh, i64 const s_rh)
{
	v_out[0] = (v_lh[0] << s_rh);
	v_out[1] = (v_lh[1] << s_rh);
	v_out[2] = (v_lh[2] << s_rh);
	v_out[3] = (v_lh[3] << s_rh);
	return v_out;
}

ijk_inl intlv ijkVecBitShiftRight4ilvs(intl4 v_out, intl4 const v_lh, i64 const s_rh)
{
	v_out[0] = (v_lh[0] >> s_rh);
	v_out[1] = (v_lh[1] >> s_rh);
	v_out[2] = (v_lh[2] >> s_rh);
	v_out[3] = (v_lh[3] >> s_rh);
	return v_out;
}

ijk_inl boolv ijkVecEqual4ilvs(bool4 bv_out, intl4 const v_lh, i64 const s_rh)
{
	bv_out[0] = (v_lh[0] == s_rh);
	bv_out[1] = (v_lh[1] == s_rh);
	bv_out[2] = (v_lh[2] == s_rh);
	bv_out[3] = (v_lh[3] == s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecInequal4ilvs(bool4 bv_out, intl4 const v_lh, i64 const s_rh)
{
	bv_out[0] = (v_lh[0] != s_rh);
	bv_out[1] = (v_lh[1] != s_rh);
	bv_out[2] = (v_lh[2] != s_rh);
	bv_out[3] = (v_lh[3] != s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual4ilvs(bool4 bv_out, intl4 const v_lh, i64 const s_rh)
{
	bv_out[0] = (v_lh[0] <= s_rh);
	bv_out[1] = (v_lh[1] <= s_rh);
	bv_out[2] = (v_lh[2] <= s_rh);
	bv_out[3] = (v_lh[3] <= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual4ilvs(bool4 bv_out, intl4 const v_lh, i64 const s_rh)
{
	bv_out[0] = (v_lh[0] >= s_rh);
	bv_out[1] = (v_lh[1] >= s_rh);
	bv_out[2] = (v_lh[2] >= s_rh);
	bv_out[3] = (v_lh[3] >= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLess4ilvs(bool4 bv_out, intl4 const v_lh, i64 const s_rh)
{
	bv_out[0] = (v_lh[0] < s_rh);
	bv_out[1] = (v_lh[1] < s_rh);
	bv_out[2] = (v_lh[2] < s_rh);
	bv_out[3] = (v_lh[3] < s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreater4ilvs(bool4 bv_out, intl4 const v_lh, i64 const s_rh)
{
	bv_out[0] = (v_lh[0] > s_rh);
	bv_out[1] = (v_lh[1] > s_rh);
	bv_out[2] = (v_lh[2] > s_rh);
	bv_out[3] = (v_lh[3] > s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecAnd4ilvs(bool4 bv_out, intl4 const v_lh, i64 const s_rh)
{
	bv_out[0] = (v_lh[0] && s_rh);
	bv_out[1] = (v_lh[1] && s_rh);
	bv_out[2] = (v_lh[2] && s_rh);
	bv_out[3] = (v_lh[3] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNand4ilvs(bool4 bv_out, intl4 const v_lh, i64 const s_rh)
{
	bv_out[0] = !(v_lh[0] && s_rh);
	bv_out[1] = !(v_lh[1] && s_rh);
	bv_out[2] = !(v_lh[2] && s_rh);
	bv_out[3] = !(v_lh[3] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecOr4ilvs(bool4 bv_out, intl4 const v_lh, i64 const s_rh)
{
	bv_out[0] = (v_lh[0] || s_rh);
	bv_out[1] = (v_lh[1] || s_rh);
	bv_out[2] = (v_lh[2] || s_rh);
	bv_out[3] = (v_lh[3] || s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNor4ilvs(bool4 bv_out, intl4 const v_lh, i64 const s_rh)
{
	bv_out[0] = !(v_lh[0] || s_rh);
	bv_out[1] = !(v_lh[1] || s_rh);
	bv_out[2] = !(v_lh[2] || s_rh);
	bv_out[3] = !(v_lh[3] || s_rh);
	return bv_out;
}

ijk_inl intlv ijkVecCopy4ilxyv(intl4 v_out, i64 const x, i64 const y, intl2 const v_zw)
{
	v_out[0] = x;
	v_out[1] = y;
	v_out[2] = v_zw[0];
	v_out[3] = v_zw[1];
	return v_out;
}

ijk_inl intlv ijkVecCopy4ilxv(intl4 v_out, i64 const x, intl3 const v_yzw)
{
	v_out[0] = x;
	v_out[1] = v_yzw[0];
	v_out[2] = v_yzw[1];
	v_out[3] = v_yzw[2];
	return v_out;
}

ijk_inl intlv ijkVecAdd4ilsv(intl4 v_out, i64 const s_lh, intl4 const v_rh)
{
	v_out[0] = s_lh + v_rh[0];
	v_out[1] = s_lh + v_rh[1];
	v_out[2] = s_lh + v_rh[2];
	v_out[3] = s_lh + v_rh[3];
	return v_out;
}

ijk_inl intlv ijkVecSub4ilsv(intl4 v_out, i64 const s_lh, intl4 const v_rh)
{
	v_out[0] = s_lh - v_rh[0];
	v_out[1] = s_lh - v_rh[1];
	v_out[2] = s_lh - v_rh[2];
	v_out[3] = s_lh - v_rh[3];
	return v_out;
}

ijk_inl intlv ijkVecMul4ilsv(intl4 v_out, i64 const s_lh, intl4 const v_rh)
{
	v_out[0] = s_lh * v_rh[0];
	v_out[1] = s_lh * v_rh[1];
	v_out[2] = s_lh * v_rh[2];
	v_out[3] = s_lh * v_rh[3];
	return v_out;
}

ijk_inl intlv ijkVecDiv4ilsv(intl4 v_out, i64 const s_lh, intl4 const v_rh)
{
	v_out[0] = s_lh / v_rh[0];
	v_out[1] = s_lh / v_rh[1];
	v_out[2] = s_lh / v_rh[2];
	v_out[3] = s_lh / v_rh[3];
	return v_out;
}

ijk_inl intlv ijkVecDivSafe4ilsv(intl4 v_out, i64 const s_lh, intl4 const v_rh)
{
	v_out[0] = ijk_divide_safe_int(s_lh, v_rh[0]);
	v_out[1] = ijk_divide_safe_int(s_lh, v_rh[1]);
	v_out[2] = ijk_divide_safe_int(s_lh, v_rh[2]);
	v_out[3] = ijk_divide_safe_int(s_lh, v_rh[3]);
	return v_out;
}

ijk_inl intlv ijkVecMod4ilsv(intl4 v_out, i64 const s_lh, intl4 const v_rh)
{
	v_out[0] = s_lh % v_rh[0];
	v_out[1] = s_lh % v_rh[1];
	v_out[2] = s_lh % v_rh[2];
	v_out[3] = s_lh % v_rh[3];
	return v_out;
}

ijk_inl intlv ijkVecModSafe4ilsv(intl4 v_out, i64 const s_lh, intl4 const v_rh)
{
	v_out[0] = ijk_modulo_safe_int(s_lh, v_rh[0]);
	v_out[1] = ijk_modulo_safe_int(s_lh, v_rh[1]);
	v_out[2] = ijk_modulo_safe_int(s_lh, v_rh[2]);
	v_out[3] = ijk_modulo_safe_int(s_lh, v_rh[3]);
	return v_out;
}

ijk_inl intlv ijkVecBitAnd4ilsv(intl4 v_out, i64 const s_lh, intl4 const v_rh)
{
	v_out[0] = (s_lh & v_rh[0]);
	v_out[1] = (s_lh & v_rh[1]);
	v_out[2] = (s_lh & v_rh[2]);
	v_out[3] = (s_lh & v_rh[3]);
	return v_out;
}

ijk_inl intlv ijkVecBitNand4ilsv(intl4 v_out, i64 const s_lh, intl4 const v_rh)
{
	v_out[0] = ~(s_lh & v_rh[0]);
	v_out[1] = ~(s_lh & v_rh[1]);
	v_out[2] = ~(s_lh & v_rh[2]);
	v_out[3] = ~(s_lh & v_rh[3]);
	return v_out;
}

ijk_inl intlv ijkVecBitOr4ilsv(intl4 v_out, i64 const s_lh, intl4 const v_rh)
{
	v_out[0] = (s_lh | v_rh[0]);
	v_out[1] = (s_lh | v_rh[1]);
	v_out[2] = (s_lh | v_rh[2]);
	v_out[3] = (s_lh | v_rh[3]);
	return v_out;
}

ijk_inl intlv ijkVecBitNor4ilsv(intl4 v_out, i64 const s_lh, intl4 const v_rh)
{
	v_out[0] = ~(s_lh | v_rh[0]);
	v_out[1] = ~(s_lh | v_rh[1]);
	v_out[2] = ~(s_lh | v_rh[2]);
	v_out[3] = ~(s_lh | v_rh[3]);
	return v_out;
}

ijk_inl intlv ijkVecBitXor4ilsv(intl4 v_out, i64 const s_lh, intl4 const v_rh)
{
	v_out[0] = (s_lh ^ v_rh[0]);
	v_out[1] = (s_lh ^ v_rh[1]);
	v_out[2] = (s_lh ^ v_rh[2]);
	v_out[3] = (s_lh ^ v_rh[3]);
	return v_out;
}

ijk_inl intlv ijkVecBitXnor4ilsv(intl4 v_out, i64 const s_lh, intl4 const v_rh)
{
	v_out[0] = ~(s_lh ^ v_rh[0]);
	v_out[1] = ~(s_lh ^ v_rh[1]);
	v_out[2] = ~(s_lh ^ v_rh[2]);
	v_out[3] = ~(s_lh ^ v_rh[3]);
	return v_out;
}

ijk_inl intlv ijkVecBitShiftLeft4ilsv(intl4 v_out, i64 const s_lh, intl4 const v_rh)
{
	v_out[0] = (s_lh << v_rh[0]);
	v_out[1] = (s_lh << v_rh[1]);
	v_out[2] = (s_lh << v_rh[2]);
	v_out[3] = (s_lh << v_rh[3]);
	return v_out;
}

ijk_inl intlv ijkVecBitShiftRight4ilsv(intl4 v_out, i64 const s_lh, intl4 const v_rh)
{
	v_out[0] = (s_lh >> v_rh[0]);
	v_out[1] = (s_lh >> v_rh[1]);
	v_out[2] = (s_lh >> v_rh[2]);
	v_out[3] = (s_lh >> v_rh[3]);
	return v_out;
}

ijk_inl boolv ijkVecEqual4ilsv(bool4 bv_out, i64 const s_lh, intl4 const v_rh)
{
	bv_out[0] = (s_lh == v_rh[0]);
	bv_out[1] = (s_lh == v_rh[1]);
	bv_out[2] = (s_lh == v_rh[2]);
	bv_out[3] = (s_lh == v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal4ilsv(bool4 bv_out, i64 const s_lh, intl4 const v_rh)
{
	bv_out[0] = (s_lh != v_rh[0]);
	bv_out[1] = (s_lh != v_rh[1]);
	bv_out[2] = (s_lh != v_rh[2]);
	bv_out[3] = (s_lh != v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual4ilsv(bool4 bv_out, i64 const s_lh, intl4 const v_rh)
{
	bv_out[0] = (s_lh <= v_rh[0]);
	bv_out[1] = (s_lh <= v_rh[1]);
	bv_out[2] = (s_lh <= v_rh[2]);
	bv_out[3] = (s_lh <= v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual4ilsv(bool4 bv_out, i64 const s_lh, intl4 const v_rh)
{
	bv_out[0] = (s_lh >= v_rh[0]);
	bv_out[1] = (s_lh >= v_rh[1]);
	bv_out[2] = (s_lh >= v_rh[2]);
	bv_out[3] = (s_lh >= v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecLess4ilsv(bool4 bv_out, i64 const s_lh, intl4 const v_rh)
{
	bv_out[0] = (s_lh < v_rh[0]);
	bv_out[1] = (s_lh < v_rh[1]);
	bv_out[2] = (s_lh < v_rh[2]);
	bv_out[3] = (s_lh < v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater4ilsv(bool4 bv_out, i64 const s_lh, intl4 const v_rh)
{
	bv_out[0] = (s_lh > v_rh[0]);
	bv_out[1] = (s_lh > v_rh[1]);
	bv_out[2] = (s_lh > v_rh[2]);
	bv_out[3] = (s_lh > v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd4ilsv(bool4 bv_out, i64 const s_lh, intl4 const v_rh)
{
	bv_out[0] = (s_lh && v_rh[0]);
	bv_out[1] = (s_lh && v_rh[1]);
	bv_out[2] = (s_lh && v_rh[2]);
	bv_out[3] = (s_lh && v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecNand4ilsv(bool4 bv_out, i64 const s_lh, intl4 const v_rh)
{
	bv_out[0] = !(s_lh && v_rh[0]);
	bv_out[1] = !(s_lh && v_rh[1]);
	bv_out[2] = !(s_lh && v_rh[2]);
	bv_out[3] = !(s_lh && v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecOr4ilsv(bool4 bv_out, i64 const s_lh, intl4 const v_rh)
{
	bv_out[0] = (s_lh || v_rh[0]);
	bv_out[1] = (s_lh || v_rh[1]);
	bv_out[2] = (s_lh || v_rh[2]);
	bv_out[3] = (s_lh || v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecNor4ilsv(bool4 bv_out, i64 const s_lh, intl4 const v_rh)
{
	bv_out[0] = !(s_lh || v_rh[0]);
	bv_out[1] = !(s_lh || v_rh[1]);
	bv_out[2] = !(s_lh || v_rh[2]);
	bv_out[3] = !(s_lh || v_rh[3]);
	return bv_out;
}

ijk_inl i64 ijkVecDot4ilv(intl4 const v_lh, intl4 const v_rh)
{
	return (v_lh[0] * v_rh[0] + v_lh[1] * v_rh[1] + v_lh[2] * v_rh[2] + v_lh[3] * v_rh[3]);
}

ijk_inl intlv ijkVecCross4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh)
{
	v_out[3] = 0;
	return ijkVecCross3ilv(v_out, v_lh, v_rh);
}


//-----------------------------------------------------------------------------

ijk_inl int ijkVecAbs1il(int const s)
{
	return ijkVecAbs1ils(s);
}

ijk_inl int ijkVecSgn1il(int const s)
{
	return ijkVecSgn1ils(s);
}

ijk_inl int ijkVecDot1il(int const s_lh, int const s_rh)
{
	return ijkVecDot1ils(s_lh, s_rh);
}

ijk_inl int ijkVecLengthSq1il(int const s)
{
	return ijkVecLengthSq1ils(s);
}

ijk_inl int ijkVecLength1il(int const s)
{
	return ijkVecLength1ils(s);
}

ijk_inl float ijkVecLengthSqInv1il(int const s)
{
	return ijkVecLengthSqInv1ils(s);
}

ijk_inl float ijkVecLengthInv1il(int const s)
{
	return ijkVecLengthInv1ils(s);
}

ijk_inl int ijkVecNormalize1il(int const s)
{
	return ijkVecNormalize1ils(s);
}

ijk_inl int ijkVecNormalizeGetLength1il(int const s, int* const length_out)
{
	return ijkVecNormalizeGetLength1ils(s, (i64*)length_out);
}

ijk_inl int ijkVecNormalizeGetLengthInv1il(int const s, float* const lengthInv_out)
{
	return ijkVecNormalizeGetLengthInv1ils(s, (f64*)lengthInv_out);
}


//-----------------------------------------------------------------------------

ijk_inl ilvec2 ijkVecInit2il()
{
	ilvec2 const v_out = { 0, 0 };
	return v_out;
}

ijk_inl ilvec2 ijkVecInitElems2il(int const x, int const y)
{
	ilvec2 const v_out = { x, y };
	return v_out;
}

ijk_inl ilvec2 ijkVecCopy2il(ilvec2 const v_in)
{
	ilvec2 const v_out = { +v_in.x, +v_in.y };
	return v_out;
}

ijk_inl ilvec2 ijkVecNegate2il(ilvec2 const v_in)
{
	ilvec2 const v_out = { -v_in.x, -v_in.y };
	return v_out;
}

ijk_inl ilvec2 ijkVecBitNot2il(ilvec2 const v_in)
{
	ilvec2 const v_out = { ~v_in.x, ~v_in.y };
	return v_out;
}

ijk_inl bvec2 ijkVecNot2il(ilvec2 const v_in)
{
	bvec2 const bv_out = { !v_in.x, !v_in.y };
	return bv_out;
}

ijk_inl ilvec2 ijkVecAdd2il(ilvec2 const v_lh, ilvec2 const v_rh)
{
	ilvec2 const v_out = {
		v_lh.x + v_rh.x,
		v_lh.y + v_rh.y,
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecSub2il(ilvec2 const v_lh, ilvec2 const v_rh)
{
	ilvec2 const v_out = {
		v_lh.x - v_rh.x,
		v_lh.y - v_rh.y,
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecMul2il(ilvec2 const v_lh, ilvec2 const v_rh)
{
	ilvec2 const v_out = {
		v_lh.x * v_rh.x,
		v_lh.y * v_rh.y,
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecDiv2il(ilvec2 const v_lh, ilvec2 const v_rh)
{
	ilvec2 const v_out = {
		v_lh.x / v_rh.x,
		v_lh.y / v_rh.y,
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecDivSafe2il(ilvec2 const v_lh, ilvec2 const v_rh)
{
	ilvec2 const v_out = {
		ijk_divide_safe_int(v_lh.x, v_rh.x),
		ijk_divide_safe_int(v_lh.y, v_rh.y),
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecMod2il(ilvec2 const v_lh, ilvec2 const v_rh)
{
	ilvec2 const v_out = {
		v_lh.x % v_rh.x,
		v_lh.y % v_rh.y,
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecModSafe2il(ilvec2 const v_lh, ilvec2 const v_rh)
{
	ilvec2 const v_out = {
		ijk_modulo_safe_int(v_lh.x, v_rh.x),
		ijk_modulo_safe_int(v_lh.y, v_rh.y),
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecBitAnd2il(ilvec2 const v_lh, ilvec2 const v_rh)
{
	ilvec2 const v_out = {
		(v_lh.x & v_rh.x),
		(v_lh.y & v_rh.y),
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecBitNand2il(ilvec2 const v_lh, ilvec2 const v_rh)
{
	ilvec2 const v_out = {
		~(v_lh.x & v_rh.x),
		~(v_lh.y & v_rh.y),
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecBitOr2il(ilvec2 const v_lh, ilvec2 const v_rh)
{
	ilvec2 const v_out = {
		(v_lh.x | v_rh.x),
		(v_lh.y | v_rh.y),
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecBitNor2il(ilvec2 const v_lh, ilvec2 const v_rh)
{
	ilvec2 const v_out = {
		~(v_lh.x | v_rh.x),
		~(v_lh.y | v_rh.y),
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecBitXor2il(ilvec2 const v_lh, ilvec2 const v_rh)
{
	ilvec2 const v_out = {
		(v_lh.x ^ v_rh.x),
		(v_lh.y ^ v_rh.y),
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecBitXnor2il(ilvec2 const v_lh, ilvec2 const v_rh)
{
	ilvec2 const v_out = {
		~(v_lh.x ^ v_rh.x),
		~(v_lh.y ^ v_rh.y),
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecBitShiftLeft2il(ilvec2 const v_lh, ilvec2 const v_rh)
{
	ilvec2 const v_out = {
		(v_lh.x << v_rh.x),
		(v_lh.y << v_rh.y),
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecBitShiftRight2il(ilvec2 const v_lh, ilvec2 const v_rh)
{
	ilvec2 const v_out = {
		(v_lh.x >> v_rh.x),
		(v_lh.y >> v_rh.y),
	};
	return v_out;
}

ijk_inl bvec2 ijkVecEqual2il(ilvec2 const v_lh, ilvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x == v_rh.x),
		(v_lh.y == v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecInequal2il(ilvec2 const v_lh, ilvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x != v_rh.x),
		(v_lh.y != v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLessEqual2il(ilvec2 const v_lh, ilvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x <= v_rh.x),
		(v_lh.y <= v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreaterEqual2il(ilvec2 const v_lh, ilvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x >= v_rh.x),
		(v_lh.y >= v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLess2il(ilvec2 const v_lh, ilvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x < v_rh.x),
		(v_lh.y < v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreater2il(ilvec2 const v_lh, ilvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x > v_rh.x),
		(v_lh.y > v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecAnd2il(ilvec2 const v_lh, ilvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x && v_rh.x),
		(v_lh.y && v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNand2il(ilvec2 const v_lh, ilvec2 const v_rh)
{
	bvec2 const bv_out = {
		!(v_lh.x && v_rh.x),
		!(v_lh.y && v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecOr2il(ilvec2 const v_lh, ilvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x || v_rh.x),
		(v_lh.y || v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNor2il(ilvec2 const v_lh, ilvec2 const v_rh)
{
	bvec2 const bv_out = {
		!(v_lh.x || v_rh.x),
		!(v_lh.y || v_rh.y),
	};
	return bv_out;
}

ijk_inl ilvec2 ijkVecCopy2ils(int const s_in)
{
	ilvec2 const v_out = { s_in, s_in };
	return v_out;
}

ijk_inl ilvec2 ijkVecNegate2ils(int const s_in)
{
	int const s = -s_in;
	ilvec2 const v_out = { s, s };
	return v_out;
}

ijk_inl ilvec2 ijkVecBitNot2ils(int const s_in)
{
	int const s = ~s_in;
	ilvec2 const v_out = { s, s };
	return v_out;
}

ijk_inl bvec2 ijkVecNot2ils(int const s_in)
{
	bool const s = !s_in;
	bvec2 const bv_out = { s, s };
	return bv_out;
}

ijk_inl ilvec2 ijkVecAdd2ils(ilvec2 const v_lh, int const s_rh)
{
	ilvec2 const v_out = {
		v_lh.x + s_rh,
		v_lh.y + s_rh,
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecSub2ils(ilvec2 const v_lh, int const s_rh)
{
	ilvec2 const v_out = {
		v_lh.x - s_rh,
		v_lh.y - s_rh,
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecMul2ils(ilvec2 const v_lh, int const s_rh)
{
	ilvec2 const v_out = {
		v_lh.x * s_rh,
		v_lh.y * s_rh,
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecDiv2ils(ilvec2 const v_lh, int const s_rh)
{
	ilvec2 const v_out = {
		v_lh.x / s_rh,
		v_lh.y / s_rh,
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecDivSafe2ils(ilvec2 const v_lh, int const s_rh)
{
	if (s_rh)
	{
		ilvec2 const v_out = {
			v_lh.x / s_rh,
			v_lh.y / s_rh,
		};
		return v_out;
	}
	else
	{
		ilvec2 const v_out = { 0, 0 };
		return v_out;
	}
}

ijk_inl ilvec2 ijkVecMod2ils(ilvec2 const v_lh, int const s_rh)
{
	ilvec2 const v_out = {
		v_lh.x % s_rh,
		v_lh.y % s_rh,
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecModSafe2ils(ilvec2 const v_lh, int const s_rh)
{
	if (s_rh)
	{
		ilvec2 const v_out = {
			v_lh.x % s_rh,
			v_lh.y % s_rh,
		};
		return v_out;
	}
	return v_lh;
}

ijk_inl ilvec2 ijkVecBitAnd2ils(ilvec2 const v_lh, int const s_rh)
{
	ilvec2 const v_out = {
		(v_lh.x & s_rh),
		(v_lh.y & s_rh),
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecBitNand2ils(ilvec2 const v_lh, int const s_rh)
{
	ilvec2 const v_out = {
		~(v_lh.x & s_rh),
		~(v_lh.y & s_rh),
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecBitOr2ils(ilvec2 const v_lh, int const s_rh)
{
	ilvec2 const v_out = {
		(v_lh.x | s_rh),
		(v_lh.y | s_rh),
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecBitNor2ils(ilvec2 const v_lh, int const s_rh)
{
	ilvec2 const v_out = {
		~(v_lh.x | s_rh),
		~(v_lh.y | s_rh),
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecBitXor2ils(ilvec2 const v_lh, int const s_rh)
{
	ilvec2 const v_out = {
		(v_lh.x ^ s_rh),
		(v_lh.y ^ s_rh),
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecBitXnor2ils(ilvec2 const v_lh, int const s_rh)
{
	ilvec2 const v_out = {
		~(v_lh.x ^ s_rh),
		~(v_lh.y ^ s_rh),
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecBitShiftLeft2ils(ilvec2 const v_lh, int const s_rh)
{
	ilvec2 const v_out = {
		(v_lh.x << s_rh),
		(v_lh.y << s_rh),
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecBitShiftRight2ils(ilvec2 const v_lh, int const s_rh)
{
	ilvec2 const v_out = {
		(v_lh.x >> s_rh),
		(v_lh.y >> s_rh),
	};
	return v_out;
}

ijk_inl bvec2 ijkVecEqual2ils(ilvec2 const v_lh, int const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x == s_rh),
		(v_lh.y == s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecInequal2ils(ilvec2 const v_lh, int const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x != s_rh),
		(v_lh.y != s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLessEqual2ils(ilvec2 const v_lh, int const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x <= s_rh),
		(v_lh.y <= s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreaterEqual2ils(ilvec2 const v_lh, int const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x >= s_rh),
		(v_lh.y >= s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLess2ils(ilvec2 const v_lh, int const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x < s_rh),
		(v_lh.y < s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreater2ils(ilvec2 const v_lh, int const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x > s_rh),
		(v_lh.y > s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecAnd2ils(ilvec2 const v_lh, int const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x && s_rh),
		(v_lh.y && s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNand2ils(ilvec2 const v_lh, int const s_rh)
{
	bvec2 const bv_out = {
		!(v_lh.x && s_rh),
		!(v_lh.y && s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecOr2ils(ilvec2 const v_lh, int const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x || s_rh),
		(v_lh.y || s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNor2ils(ilvec2 const v_lh, int const s_rh)
{
	bvec2 const bv_out = {
		!(v_lh.x || s_rh),
		!(v_lh.y || s_rh),
	};
	return bv_out;
}

ijk_inl ilvec2 ijkVecAdd2sil(int const s_lh, ilvec2 const v_rh)
{
	ilvec2 const v_out = {
		s_lh + v_rh.x,
		s_lh + v_rh.y,
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecSub2sil(int const s_lh, ilvec2 const v_rh)
{
	ilvec2 const v_out = {
		s_lh - v_rh.x,
		s_lh - v_rh.y,
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecMul2sil(int const s_lh, ilvec2 const v_rh)
{
	ilvec2 const v_out = {
		s_lh * v_rh.x,
		s_lh * v_rh.y,
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecDiv2sil(int const s_lh, ilvec2 const v_rh)
{
	ilvec2 const v_out = {
		s_lh / v_rh.x,
		s_lh / v_rh.y,
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecDivSafe2sil(int const s_lh, ilvec2 const v_rh)
{
	ilvec2 const v_out = {
		ijk_divide_safe_int(s_lh, v_rh.x),
		ijk_divide_safe_int(s_lh, v_rh.y),
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecMod2sil(int const s_lh, ilvec2 const v_rh)
{
	ilvec2 const v_out = {
		s_lh % v_rh.x,
		s_lh % v_rh.y,
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecModSafe2sil(int const s_lh, ilvec2 const v_rh)
{
	ilvec2 const v_out = {
		ijk_modulo_safe_int((i64)s_lh, v_rh.x),
		ijk_modulo_safe_int((i64)s_lh, v_rh.y),
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecBitAnd2sil(int const s_lh, ilvec2 const v_rh)
{
	ilvec2 const v_out = {
		(s_lh & v_rh.x),
		(s_lh & v_rh.y),
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecBitNand2sil(int const s_lh, ilvec2 const v_rh)
{
	ilvec2 const v_out = {
		~(s_lh & v_rh.x),
		~(s_lh & v_rh.y),
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecBitOr2sil(int const s_lh, ilvec2 const v_rh)
{
	ilvec2 const v_out = {
		(s_lh | v_rh.x),
		(s_lh | v_rh.y),
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecBitNor2sil(int const s_lh, ilvec2 const v_rh)
{
	ilvec2 const v_out = {
		~(s_lh | v_rh.x),
		~(s_lh | v_rh.y),
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecBitXor2sil(int const s_lh, ilvec2 const v_rh)
{
	ilvec2 const v_out = {
		(s_lh ^ v_rh.x),
		(s_lh ^ v_rh.y),
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecBitXnor2sil(int const s_lh, ilvec2 const v_rh)
{
	ilvec2 const v_out = {
		~(s_lh ^ v_rh.x),
		~(s_lh ^ v_rh.y),
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecBitShiftLeft2sil(int const s_lh, ilvec2 const v_rh)
{
	ilvec2 const v_out = {
		(s_lh << v_rh.x),
		(s_lh << v_rh.y),
	};
	return v_out;
}

ijk_inl ilvec2 ijkVecBitShiftRight2sil(int const s_lh, ilvec2 const v_rh)
{
	ilvec2 const v_out = {
		(s_lh >> v_rh.x),
		(s_lh >> v_rh.y),
	};
	return v_out;
}

ijk_inl bvec2 ijkVecEqual2sil(int const s_lh, ilvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh == v_rh.x),
		(s_lh == v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecInequal2sil(int const s_lh, ilvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh != v_rh.x),
		(s_lh != v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLessEqual2sil(int const s_lh, ilvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh <= v_rh.x),
		(s_lh <= v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreaterEqual2sil(int const s_lh, ilvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh >= v_rh.x),
		(s_lh >= v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLess2sil(int const s_lh, ilvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh < v_rh.x),
		(s_lh < v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreater2sil(int const s_lh, ilvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh > v_rh.x),
		(s_lh > v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecAnd2sil(int const s_lh, ilvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh && v_rh.x),
		(s_lh && v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNand2sil(int const s_lh, ilvec2 const v_rh)
{
	bvec2 const bv_out = {
		!(s_lh && v_rh.x),
		!(s_lh && v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecOr2sil(int const s_lh, ilvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh || v_rh.x),
		(s_lh || v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNor2sil(int const s_lh, ilvec2 const v_rh)
{
	bvec2 const bv_out = {
		!(s_lh || v_rh.x),
		!(s_lh || v_rh.y),
	};
	return bv_out;
}

ijk_inl int ijkVecDot2il(ilvec2 const v_lh, ilvec2 const v_rh)
{
	return ijkVecDot2ilv(v_lh.xy, v_rh.xy);
}

ijk_inl int ijkVecCross2il(ilvec2 const v_lh, ilvec2 const v_rh)
{
	return ijkVecCross2ilv(v_lh.xy, v_rh.xy);
}


//-----------------------------------------------------------------------------

ijk_inl ilvec3 ijkVecInit3il()
{
	ilvec3 const v_out = { 0, 0, 0 };
	return v_out;
}

ijk_inl ilvec3 ijkVecInitElems3il(int const x, int const y, int const z)
{
	ilvec3 const v_out = { x, y, z };
	return v_out;
}

ijk_inl ilvec3 ijkVecCopy3il(ilvec3 const v_in)
{
	ilvec3 const v_out = { +v_in.x, +v_in.y, +v_in.z };
	return v_out;
}

ijk_inl ilvec3 ijkVecNegate3il(ilvec3 const v_in)
{
	ilvec3 const v_out = { -v_in.x, -v_in.y, -v_in.z };
	return v_out;
}

ijk_inl ilvec3 ijkVecBitNot3il(ilvec3 const v_in)
{
	ilvec3 const v_out = { ~v_in.x, ~v_in.y, ~v_in.z };
	return v_out;
}

ijk_inl bvec3 ijkVecNot3il(ilvec3 const v_in)
{
	bvec3 const bv_out = { !v_in.x, !v_in.y, !v_in.z };
	return bv_out;
}

ijk_inl ilvec3 ijkVecAdd3il(ilvec3 const v_lh, ilvec3 const v_rh)
{
	ilvec3 const v_out = {
		v_lh.x + v_rh.x,
		v_lh.y + v_rh.y,
		v_lh.z + v_rh.z,
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecSub3il(ilvec3 const v_lh, ilvec3 const v_rh)
{
	ilvec3 const v_out = {
		v_lh.x - v_rh.x,
		v_lh.y - v_rh.y,
		v_lh.z - v_rh.z,
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecMul3il(ilvec3 const v_lh, ilvec3 const v_rh)
{
	ilvec3 const v_out = {
		v_lh.x * v_rh.x,
		v_lh.y * v_rh.y,
		v_lh.z * v_rh.z,
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecDiv3il(ilvec3 const v_lh, ilvec3 const v_rh)
{
	ilvec3 const v_out = {
		v_lh.x / v_rh.x,
		v_lh.y / v_rh.y,
		v_lh.z / v_rh.z,
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecDivSafe3il(ilvec3 const v_lh, ilvec3 const v_rh)
{
	ilvec3 const v_out = {
		ijk_divide_safe_int(v_lh.x, v_rh.x),
		ijk_divide_safe_int(v_lh.y, v_rh.y),
		ijk_divide_safe_int(v_lh.z, v_rh.z),
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecMod3il(ilvec3 const v_lh, ilvec3 const v_rh)
{
	ilvec3 const v_out = {
		v_lh.x % v_rh.x,
		v_lh.y % v_rh.y,
		v_lh.z % v_rh.z,
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecModSafe3il(ilvec3 const v_lh, ilvec3 const v_rh)
{
	ilvec3 const v_out = {
		ijk_modulo_safe_int(v_lh.x, v_rh.x),
		ijk_modulo_safe_int(v_lh.y, v_rh.y),
		ijk_modulo_safe_int(v_lh.z, v_rh.z),
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecBitAnd3il(ilvec3 const v_lh, ilvec3 const v_rh)
{
	ilvec3 const v_out = {
		(v_lh.x & v_rh.x),
		(v_lh.y & v_rh.y),
		(v_lh.z & v_rh.z),
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecBitNand3il(ilvec3 const v_lh, ilvec3 const v_rh)
{
	ilvec3 const v_out = {
		~(v_lh.x & v_rh.x),
		~(v_lh.y & v_rh.y),
		~(v_lh.z & v_rh.z),
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecBitOr3il(ilvec3 const v_lh, ilvec3 const v_rh)
{
	ilvec3 const v_out = {
		(v_lh.x | v_rh.x),
		(v_lh.y | v_rh.y),
		(v_lh.z | v_rh.z),
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecBitNor3il(ilvec3 const v_lh, ilvec3 const v_rh)
{
	ilvec3 const v_out = {
		~(v_lh.x | v_rh.x),
		~(v_lh.y | v_rh.y),
		~(v_lh.z | v_rh.z),
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecBitXor3il(ilvec3 const v_lh, ilvec3 const v_rh)
{
	ilvec3 const v_out = {
		(v_lh.x ^ v_rh.x),
		(v_lh.y ^ v_rh.y),
		(v_lh.z ^ v_rh.z),
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecBitXnor3il(ilvec3 const v_lh, ilvec3 const v_rh)
{
	ilvec3 const v_out = {
		~(v_lh.x ^ v_rh.x),
		~(v_lh.y ^ v_rh.y),
		~(v_lh.z ^ v_rh.z),
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecBitShiftLeft3il(ilvec3 const v_lh, ilvec3 const v_rh)
{
	ilvec3 const v_out = {
		(v_lh.x << v_rh.x),
		(v_lh.y << v_rh.y),
		(v_lh.z << v_rh.z),
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecBitShiftRight3il(ilvec3 const v_lh, ilvec3 const v_rh)
{
	ilvec3 const v_out = {
		(v_lh.x >> v_rh.x),
		(v_lh.y >> v_rh.y),
		(v_lh.z >> v_rh.z),
	};
	return v_out;
}

ijk_inl bvec3 ijkVecEqual3il(ilvec3 const v_lh, ilvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x == v_rh.x),
		(v_lh.y == v_rh.y),
		(v_lh.z == v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecInequal3il(ilvec3 const v_lh, ilvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x != v_rh.x),
		(v_lh.y != v_rh.y),
		(v_lh.z != v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLessEqual3il(ilvec3 const v_lh, ilvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x <= v_rh.x),
		(v_lh.y <= v_rh.y),
		(v_lh.z <= v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreaterEqual3il(ilvec3 const v_lh, ilvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x >= v_rh.x),
		(v_lh.y >= v_rh.y),
		(v_lh.z >= v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLess3il(ilvec3 const v_lh, ilvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x < v_rh.x),
		(v_lh.y < v_rh.y),
		(v_lh.z < v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreater3il(ilvec3 const v_lh, ilvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x > v_rh.x),
		(v_lh.y > v_rh.y),
		(v_lh.z > v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecAnd3il(ilvec3 const v_lh, ilvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x && v_rh.x),
		(v_lh.y && v_rh.y),
		(v_lh.z && v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNand3il(ilvec3 const v_lh, ilvec3 const v_rh)
{
	bvec3 const bv_out = {
		!(v_lh.x && v_rh.x),
		!(v_lh.y && v_rh.y),
		!(v_lh.z && v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecOr3il(ilvec3 const v_lh, ilvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x || v_rh.x),
		(v_lh.y || v_rh.y),
		(v_lh.z || v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNor3il(ilvec3 const v_lh, ilvec3 const v_rh)
{
	bvec3 const bv_out = {
		!(v_lh.x || v_rh.x),
		!(v_lh.y || v_rh.y),
		!(v_lh.z || v_rh.z),
	};
	return bv_out;
}

ijk_inl ilvec3 ijkVecCopy3ilz(ilvec2 const v_xy, int const z)
{
	ilvec3 const v_out = { v_xy.x, v_xy.y, z };
	return v_out;
}

ijk_inl ilvec3 ijkVecCopy3ils(int const s_in)
{
	ilvec3 const v_out = { s_in, s_in, s_in };
	return v_out;
}

ijk_inl ilvec3 ijkVecNegate3ils(int const s_in)
{
	int const s = -s_in;
	ilvec3 const v_out = { s, s, s };
	return v_out;
}

ijk_inl ilvec3 ijkVecBitNot3ils(int const s_in)
{
	int const s = ~s_in;
	ilvec3 const v_out = { s, s, s };
	return v_out;
}

ijk_inl bvec3 ijkVecNot3ils(int const s_in)
{
	bool const s = !s_in;
	bvec3 const bv_out = { s, s, s };
	return bv_out;
}

ijk_inl ilvec3 ijkVecAdd3ils(ilvec3 const v_lh, int const s_rh)
{
	ilvec3 const v_out = {
		v_lh.x + s_rh,
		v_lh.y + s_rh,
		v_lh.z + s_rh,
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecSub3ils(ilvec3 const v_lh, int const s_rh)
{
	ilvec3 const v_out = {
		v_lh.x - s_rh,
		v_lh.y - s_rh,
		v_lh.z - s_rh,
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecMul3ils(ilvec3 const v_lh, int const s_rh)
{
	ilvec3 const v_out = {
		v_lh.x * s_rh,
		v_lh.y * s_rh,
		v_lh.z * s_rh,
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecDiv3ils(ilvec3 const v_lh, int const s_rh)
{
	ilvec3 const v_out = {
		v_lh.x / s_rh,
		v_lh.y / s_rh,
		v_lh.z / s_rh,
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecDivSafe3ils(ilvec3 const v_lh, int const s_rh)
{
	if (s_rh)
	{
		ilvec3 const v_out = {
			v_lh.x / s_rh,
			v_lh.y / s_rh,
			v_lh.z / s_rh,
		};
		return v_out;
	}
	else
	{
		ilvec3 const v_out = { 0, 0, 0 };
		return v_out;
	}
}

ijk_inl ilvec3 ijkVecMod3ils(ilvec3 const v_lh, int const s_rh)
{
	ilvec3 const v_out = {
		v_lh.x % s_rh,
		v_lh.y % s_rh,
		v_lh.z % s_rh,
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecModSafe3ils(ilvec3 const v_lh, int const s_rh)
{
	if (s_rh)
	{
		ilvec3 const v_out = {
			v_lh.x % s_rh,
			v_lh.y % s_rh,
			v_lh.z % s_rh,
		};
		return v_out;
	}
	return v_lh;
}

ijk_inl ilvec3 ijkVecBitAnd3ils(ilvec3 const v_lh, int const s_rh)
{
	ilvec3 const v_out = {
		(v_lh.x & s_rh),
		(v_lh.y & s_rh),
		(v_lh.z & s_rh),
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecBitNand3ils(ilvec3 const v_lh, int const s_rh)
{
	ilvec3 const v_out = {
		~(v_lh.x & s_rh),
		~(v_lh.y & s_rh),
		~(v_lh.z & s_rh),
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecBitOr3ils(ilvec3 const v_lh, int const s_rh)
{
	ilvec3 const v_out = {
		(v_lh.x | s_rh),
		(v_lh.y | s_rh),
		(v_lh.z | s_rh),
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecBitNor3ils(ilvec3 const v_lh, int const s_rh)
{
	ilvec3 const v_out = {
		~(v_lh.x | s_rh),
		~(v_lh.y | s_rh),
		~(v_lh.z | s_rh),
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecBitXor3ils(ilvec3 const v_lh, int const s_rh)
{
	ilvec3 const v_out = {
		(v_lh.x ^ s_rh),
		(v_lh.y ^ s_rh),
		(v_lh.z ^ s_rh),
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecBitXnor3ils(ilvec3 const v_lh, int const s_rh)
{
	ilvec3 const v_out = {
		~(v_lh.x ^ s_rh),
		~(v_lh.y ^ s_rh),
		~(v_lh.z ^ s_rh),
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecBitShiftLeft3ils(ilvec3 const v_lh, int const s_rh)
{
	ilvec3 const v_out = {
		(v_lh.x << s_rh),
		(v_lh.y << s_rh),
		(v_lh.z << s_rh),
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecBitShiftRight3ils(ilvec3 const v_lh, int const s_rh)
{
	ilvec3 const v_out = {
		(v_lh.x >> s_rh),
		(v_lh.y >> s_rh),
		(v_lh.z >> s_rh),
	};
	return v_out;
}

ijk_inl bvec3 ijkVecEqual3ils(ilvec3 const v_lh, int const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x == s_rh),
		(v_lh.y == s_rh),
		(v_lh.z == s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecInequal3ils(ilvec3 const v_lh, int const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x != s_rh),
		(v_lh.y != s_rh),
		(v_lh.z != s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLessEqual3ils(ilvec3 const v_lh, int const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x <= s_rh),
		(v_lh.y <= s_rh),
		(v_lh.z <= s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreaterEqual3ils(ilvec3 const v_lh, int const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x >= s_rh),
		(v_lh.y >= s_rh),
		(v_lh.z >= s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLess3ils(ilvec3 const v_lh, int const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x < s_rh),
		(v_lh.y < s_rh),
		(v_lh.z < s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreater3ils(ilvec3 const v_lh, int const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x > s_rh),
		(v_lh.y > s_rh),
		(v_lh.z > s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecAnd3ils(ilvec3 const v_lh, int const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x && s_rh),
		(v_lh.y && s_rh),
		(v_lh.z && s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNand3ils(ilvec3 const v_lh, int const s_rh)
{
	bvec3 const bv_out = {
		!(v_lh.x && s_rh),
		!(v_lh.y && s_rh),
		!(v_lh.z && s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecOr3ils(ilvec3 const v_lh, int const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x || s_rh),
		(v_lh.y || s_rh),
		(v_lh.z || s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNor3ils(ilvec3 const v_lh, int const s_rh)
{
	bvec3 const bv_out = {
		!(v_lh.x || s_rh),
		!(v_lh.y || s_rh),
		!(v_lh.z || s_rh),
	};
	return bv_out;
}

ijk_inl ilvec3 ijkVecCopy3xi(int const x, ilvec2 const v_yz)
{
	ilvec3 const v_out = { x, v_yz.x, v_yz.y };
	return v_out;
}

ijk_inl ilvec3 ijkVecAdd3sil(int const s_lh, ilvec3 const v_rh)
{
	ilvec3 const v_out = {
		s_lh + v_rh.x,
		s_lh + v_rh.y,
		s_lh + v_rh.z,
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecSub3sil(int const s_lh, ilvec3 const v_rh)
{
	ilvec3 const v_out = {
		s_lh - v_rh.x,
		s_lh - v_rh.y,
		s_lh - v_rh.z,
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecMul3sil(int const s_lh, ilvec3 const v_rh)
{
	ilvec3 const v_out = {
		s_lh * v_rh.x,
		s_lh * v_rh.y,
		s_lh * v_rh.z,
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecDiv3sil(int const s_lh, ilvec3 const v_rh)
{
	ilvec3 const v_out = {
		s_lh / v_rh.x,
		s_lh / v_rh.y,
		s_lh / v_rh.z,
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecDivSafe3sil(int const s_lh, ilvec3 const v_rh)
{
	ilvec3 const v_out = {
		ijk_divide_safe_int(s_lh, v_rh.x),
		ijk_divide_safe_int(s_lh, v_rh.y),
		ijk_divide_safe_int(s_lh, v_rh.z),
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecMod3sil(int const s_lh, ilvec3 const v_rh)
{
	ilvec3 const v_out = {
		s_lh % v_rh.x,
		s_lh % v_rh.y,
		s_lh % v_rh.z,
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecModSafe3sil(int const s_lh, ilvec3 const v_rh)
{
	ilvec3 const v_out = {
		ijk_modulo_safe_int((i64)s_lh, v_rh.x),
		ijk_modulo_safe_int((i64)s_lh, v_rh.y),
		ijk_modulo_safe_int((i64)s_lh, v_rh.z),
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecBitAnd3sil(int const s_lh, ilvec3 const v_rh)
{
	ilvec3 const v_out = {
		(s_lh & v_rh.x),
		(s_lh & v_rh.y),
		(s_lh & v_rh.z),
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecBitNand3sil(int const s_lh, ilvec3 const v_rh)
{
	ilvec3 const v_out = {
		~(s_lh & v_rh.x),
		~(s_lh & v_rh.y),
		~(s_lh & v_rh.z),
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecBitOr3sil(int const s_lh, ilvec3 const v_rh)
{
	ilvec3 const v_out = {
		(s_lh | v_rh.x),
		(s_lh | v_rh.y),
		(s_lh | v_rh.z),
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecBitNor3sil(int const s_lh, ilvec3 const v_rh)
{
	ilvec3 const v_out = {
		~(s_lh | v_rh.x),
		~(s_lh | v_rh.y),
		~(s_lh | v_rh.z),
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecBitXor3sil(int const s_lh, ilvec3 const v_rh)
{
	ilvec3 const v_out = {
		(s_lh ^ v_rh.x),
		(s_lh ^ v_rh.y),
		(s_lh ^ v_rh.z),
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecBitXnor3sil(int const s_lh, ilvec3 const v_rh)
{
	ilvec3 const v_out = {
		~(s_lh ^ v_rh.x),
		~(s_lh ^ v_rh.y),
		~(s_lh ^ v_rh.z),
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecBitShiftLeft3sil(int const s_lh, ilvec3 const v_rh)
{
	ilvec3 const v_out = {
		(s_lh << v_rh.x),
		(s_lh << v_rh.y),
		(s_lh << v_rh.z),
	};
	return v_out;
}

ijk_inl ilvec3 ijkVecBitShiftRight3sil(int const s_lh, ilvec3 const v_rh)
{
	ilvec3 const v_out = {
		(s_lh >> v_rh.x),
		(s_lh >> v_rh.y),
		(s_lh >> v_rh.z),
	};
	return v_out;
}

ijk_inl bvec3 ijkVecEqual3sil(int const s_lh, ilvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh == v_rh.x),
		(s_lh == v_rh.y),
		(s_lh == v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecInequal3sil(int const s_lh, ilvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh != v_rh.x),
		(s_lh != v_rh.y),
		(s_lh != v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLessEqual3sil(int const s_lh, ilvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh <= v_rh.x),
		(s_lh <= v_rh.y),
		(s_lh <= v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreaterEqual3sil(int const s_lh, ilvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh >= v_rh.x),
		(s_lh >= v_rh.y),
		(s_lh >= v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLess3sil(int const s_lh, ilvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh < v_rh.x),
		(s_lh < v_rh.y),
		(s_lh < v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreater3sil(int const s_lh, ilvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh > v_rh.x),
		(s_lh > v_rh.y),
		(s_lh > v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecAnd3sil(int const s_lh, ilvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh && v_rh.x),
		(s_lh && v_rh.y),
		(s_lh && v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNand3sil(int const s_lh, ilvec3 const v_rh)
{
	bvec3 const bv_out = {
		!(s_lh && v_rh.x),
		!(s_lh && v_rh.y),
		!(s_lh && v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecOr3sil(int const s_lh, ilvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh || v_rh.x),
		(s_lh || v_rh.y),
		(s_lh || v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNor3sil(int const s_lh, ilvec3 const v_rh)
{
	bvec3 const bv_out = {
		!(s_lh || v_rh.x),
		!(s_lh || v_rh.y),
		!(s_lh || v_rh.z),
	};
	return bv_out;
}

ijk_inl int ijkVecDot3il(ilvec3 const v_lh, ilvec3 const v_rh)
{
	return ijkVecDot3ilv(v_lh.xyz, v_rh.xyz);
}

ijk_inl ilvec3 ijkVecCross3il(ilvec3 const v_lh, ilvec3 const v_rh)
{
	ilvec3 v_out;
	ijkVecCross3ilv(v_out.xyz, v_lh.xyz, v_rh.xyz);
	return v_out;
}


//-----------------------------------------------------------------------------

ijk_inl ilvec4 ijkVecInit4il()
{
	ilvec4 const v_out = { 0, 0, 0, 0 };
	return v_out;
}

ijk_inl ilvec4 ijkVecInitElems4il(int const x, int const y, int const z, int const w)
{
	ilvec4 const v_out = { x, y, z, w };
	return v_out;
}

ijk_inl ilvec4 ijkVecCopy4xiw(int const x, ilvec2 const v_yz, int const w)
{
	ilvec4 const v_out = { x, v_yz.x, v_yz.y, w };
	return v_out;
}

ijk_inl ilvec4 ijkVecCopy4il2(ilvec2 const v_xy, ilvec2 const v_zw)
{
	ilvec4 const v_out = { v_xy.x, v_xy.y, v_zw.x, v_zw.y };
	return v_out;
}

ijk_inl ilvec4 ijkVecCopy4il(ilvec4 const v_in)
{
	ilvec4 const v_out = { +v_in.x, +v_in.y, +v_in.z, +v_in.w };
	return v_out;
}

ijk_inl ilvec4 ijkVecNegate4il(ilvec4 const v_in)
{
	ilvec4 const v_out = { -v_in.x, -v_in.y, -v_in.z, -v_in.w };
	return v_out;
}

ijk_inl ilvec4 ijkVecBitNot4il(ilvec4 const v_in)
{
	ilvec4 const v_out = { ~v_in.x, ~v_in.y, ~v_in.z, ~v_in.w };
	return v_out;
}

ijk_inl bvec4 ijkVecNot4il(ilvec4 const v_in)
{
	bvec4 const bv_out = { !v_in.x, !v_in.y, !v_in.z, !v_in.w };
	return bv_out;
}

ijk_inl ilvec4 ijkVecAdd4il(ilvec4 const v_lh, ilvec4 const v_rh)
{
	ilvec4 const v_out = {
		v_lh.x + v_rh.x,
		v_lh.y + v_rh.y,
		v_lh.z + v_rh.z,
		v_lh.w + v_rh.w,
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecSub4il(ilvec4 const v_lh, ilvec4 const v_rh)
{
	ilvec4 const v_out = {
		v_lh.x - v_rh.x,
		v_lh.y - v_rh.y,
		v_lh.z - v_rh.z,
		v_lh.w - v_rh.w,
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecMul4il(ilvec4 const v_lh, ilvec4 const v_rh)
{
	ilvec4 const v_out = {
		v_lh.x * v_rh.x,
		v_lh.y * v_rh.y,
		v_lh.z * v_rh.z,
		v_lh.w * v_rh.w,
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecDiv4il(ilvec4 const v_lh, ilvec4 const v_rh)
{
	ilvec4 const v_out = {
		v_lh.x / v_rh.x,
		v_lh.y / v_rh.y,
		v_lh.z / v_rh.z,
		v_lh.w / v_rh.w,
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecDivSafe4il(ilvec4 const v_lh, ilvec4 const v_rh)
{
	ilvec4 const v_out = {
		ijk_divide_safe_int(v_lh.x, v_rh.x),
		ijk_divide_safe_int(v_lh.y, v_rh.y),
		ijk_divide_safe_int(v_lh.z, v_rh.z),
		ijk_divide_safe_int(v_lh.w, v_rh.w),
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecMod4il(ilvec4 const v_lh, ilvec4 const v_rh)
{
	ilvec4 const v_out = {
		v_lh.x % v_rh.x,
		v_lh.y % v_rh.y,
		v_lh.z % v_rh.z,
		v_lh.w % v_rh.w,
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecModSafe4il(ilvec4 const v_lh, ilvec4 const v_rh)
{
	ilvec4 const v_out = {
		ijk_modulo_safe_int(v_lh.x, v_rh.x),
		ijk_modulo_safe_int(v_lh.y, v_rh.y),
		ijk_modulo_safe_int(v_lh.z, v_rh.z),
		ijk_modulo_safe_int(v_lh.w, v_rh.w),
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecBitAnd4il(ilvec4 const v_lh, ilvec4 const v_rh)
{
	ilvec4 const v_out = {
		(v_lh.x & v_rh.x),
		(v_lh.y & v_rh.y),
		(v_lh.z & v_rh.z),
		(v_lh.w & v_rh.w),
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecBitNand4il(ilvec4 const v_lh, ilvec4 const v_rh)
{
	ilvec4 const v_out = {
		~(v_lh.x & v_rh.x),
		~(v_lh.y & v_rh.y),
		~(v_lh.z & v_rh.z),
		~(v_lh.w & v_rh.w),
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecBitOr4il(ilvec4 const v_lh, ilvec4 const v_rh)
{
	ilvec4 const v_out = {
		(v_lh.x | v_rh.x),
		(v_lh.y | v_rh.y),
		(v_lh.z | v_rh.z),
		(v_lh.w | v_rh.w),
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecBitNor4il(ilvec4 const v_lh, ilvec4 const v_rh)
{
	ilvec4 const v_out = {
		~(v_lh.x | v_rh.x),
		~(v_lh.y | v_rh.y),
		~(v_lh.z | v_rh.z),
		~(v_lh.w | v_rh.w),
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecBitXor4il(ilvec4 const v_lh, ilvec4 const v_rh)
{
	ilvec4 const v_out = {
		(v_lh.x ^ v_rh.x),
		(v_lh.y ^ v_rh.y),
		(v_lh.z ^ v_rh.z),
		(v_lh.w ^ v_rh.w),
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecBitXnor4il(ilvec4 const v_lh, ilvec4 const v_rh)
{
	ilvec4 const v_out = {
		~(v_lh.x ^ v_rh.x),
		~(v_lh.y ^ v_rh.y),
		~(v_lh.z ^ v_rh.z),
		~(v_lh.w ^ v_rh.w),
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecBitShiftLeft4il(ilvec4 const v_lh, ilvec4 const v_rh)
{
	ilvec4 const v_out = {
		(v_lh.x << v_rh.x),
		(v_lh.y << v_rh.y),
		(v_lh.z << v_rh.z),
		(v_lh.w << v_rh.w),
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecBitShiftRight4il(ilvec4 const v_lh, ilvec4 const v_rh)
{
	ilvec4 const v_out = {
		(v_lh.x >> v_rh.x),
		(v_lh.y >> v_rh.y),
		(v_lh.z >> v_rh.z),
		(v_lh.w >> v_rh.w),
	};
	return v_out;
}

ijk_inl bvec4 ijkVecEqual4il(ilvec4 const v_lh, ilvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x == v_rh.x),
		(v_lh.y == v_rh.y),
		(v_lh.z == v_rh.z),
		(v_lh.w == v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecInequal4il(ilvec4 const v_lh, ilvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x != v_rh.x),
		(v_lh.y != v_rh.y),
		(v_lh.z != v_rh.z),
		(v_lh.w != v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLessEqual4il(ilvec4 const v_lh, ilvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x <= v_rh.x),
		(v_lh.y <= v_rh.y),
		(v_lh.z <= v_rh.z),
		(v_lh.w <= v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreaterEqual4il(ilvec4 const v_lh, ilvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x >= v_rh.x),
		(v_lh.y >= v_rh.y),
		(v_lh.z >= v_rh.z),
		(v_lh.w >= v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLess4il(ilvec4 const v_lh, ilvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x < v_rh.x),
		(v_lh.y < v_rh.y),
		(v_lh.z < v_rh.z),
		(v_lh.w < v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreater4il(ilvec4 const v_lh, ilvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x > v_rh.x),
		(v_lh.y > v_rh.y),
		(v_lh.z > v_rh.z),
		(v_lh.w > v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecAnd4il(ilvec4 const v_lh, ilvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x && v_rh.x),
		(v_lh.y && v_rh.y),
		(v_lh.z && v_rh.z),
		(v_lh.w && v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNand4il(ilvec4 const v_lh, ilvec4 const v_rh)
{
	bvec4 const bv_out = {
		!(v_lh.x && v_rh.x),
		!(v_lh.y && v_rh.y),
		!(v_lh.z && v_rh.z),
		!(v_lh.w && v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecOr4il(ilvec4 const v_lh, ilvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x || v_rh.x),
		(v_lh.y || v_rh.y),
		(v_lh.z || v_rh.z),
		(v_lh.w || v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNor4il(ilvec4 const v_lh, ilvec4 const v_rh)
{
	bvec4 const bv_out = {
		!(v_lh.x || v_rh.x),
		!(v_lh.y || v_rh.y),
		!(v_lh.z || v_rh.z),
		!(v_lh.w || v_rh.w),
	};
	return bv_out;
}

ijk_inl ilvec4 ijkVecCopy4ilzw(ilvec2 const v_xy, int const z, int const w)
{
	ilvec4 const v_out = { v_xy.x, v_xy.y, z, w };
	return v_out;
}

ijk_inl ilvec4 ijkVecCopy4ilw(ilvec3 const v_xyz, int const w)
{
	ilvec4 const v_out = { v_xyz.x, v_xyz.y, v_xyz.z, w };
	return v_out;
}

ijk_inl ilvec4 ijkVecCopy4ils(int const s_in)
{
	ilvec4 const v_out = { s_in, s_in, s_in, s_in };
	return v_out;
}

ijk_inl ilvec4 ijkVecNegate4ils(int const s_in)
{
	int const s = -s_in;
	ilvec4 const v_out = { s, s, s, s };
	return v_out;
}

ijk_inl ilvec4 ijkVecBitNot4ils(int const s_in)
{
	int const s = ~s_in;
	ilvec4 const v_out = { s, s, s, s };
	return v_out;
}

ijk_inl bvec4 ijkVecNot4ils(int const s_in)
{
	bool const s = !s_in;
	bvec4 const bv_out = { s, s, s, s };
	return bv_out;
}

ijk_inl ilvec4 ijkVecAdd4ils(ilvec4 const v_lh, int const s_rh)
{
	ilvec4 const v_out = {
		v_lh.x + s_rh,
		v_lh.y + s_rh,
		v_lh.z + s_rh,
		v_lh.w + s_rh,
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecSub4ils(ilvec4 const v_lh, int const s_rh)
{
	ilvec4 const v_out = {
		v_lh.x - s_rh,
		v_lh.y - s_rh,
		v_lh.z - s_rh,
		v_lh.w - s_rh,
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecMul4ils(ilvec4 const v_lh, int const s_rh)
{
	ilvec4 const v_out = {
		v_lh.x * s_rh,
		v_lh.y * s_rh,
		v_lh.z * s_rh,
		v_lh.w * s_rh,
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecDiv4ils(ilvec4 const v_lh, int const s_rh)
{
	ilvec4 const v_out = {
		v_lh.x / s_rh,
		v_lh.y / s_rh,
		v_lh.z / s_rh,
		v_lh.w / s_rh,
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecDivSafe4ils(ilvec4 const v_lh, int const s_rh)
{
	if (s_rh)
	{
		ilvec4 const v_out = {
			v_lh.x / s_rh,
			v_lh.y / s_rh,
			v_lh.z / s_rh,
			v_lh.w / s_rh,
		};
		return v_out;
	}
	else
	{
		ilvec4 const v_out = { 0, 0, 0, 0 };
		return v_out;
	}
}

ijk_inl ilvec4 ijkVecMod4ils(ilvec4 const v_lh, int const s_rh)
{
	ilvec4 const v_out = {
		v_lh.x % s_rh,
		v_lh.y % s_rh,
		v_lh.z % s_rh,
		v_lh.w % s_rh,
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecModSafe4ils(ilvec4 const v_lh, int const s_rh)
{
	if (s_rh)
	{
		ilvec4 const v_out = {
			v_lh.x % s_rh,
			v_lh.y % s_rh,
			v_lh.z % s_rh,
			v_lh.w % s_rh,
		};
		return v_out;
	}
	return v_lh;
}

ijk_inl ilvec4 ijkVecBitAnd4ils(ilvec4 const v_lh, int const s_rh)
{
	ilvec4 const v_out = {
		(v_lh.x & s_rh),
		(v_lh.y & s_rh),
		(v_lh.z & s_rh),
		(v_lh.w & s_rh),
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecBitNand4ils(ilvec4 const v_lh, int const s_rh)
{
	ilvec4 const v_out = {
		~(v_lh.x & s_rh),
		~(v_lh.y & s_rh),
		~(v_lh.z & s_rh),
		~(v_lh.w & s_rh),
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecBitOr4ils(ilvec4 const v_lh, int const s_rh)
{
	ilvec4 const v_out = {
		(v_lh.x | s_rh),
		(v_lh.y | s_rh),
		(v_lh.z | s_rh),
		(v_lh.w | s_rh),
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecBitNor4ils(ilvec4 const v_lh, int const s_rh)
{
	ilvec4 const v_out = {
		~(v_lh.x | s_rh),
		~(v_lh.y | s_rh),
		~(v_lh.z | s_rh),
		~(v_lh.w | s_rh),
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecBitXor4ils(ilvec4 const v_lh, int const s_rh)
{
	ilvec4 const v_out = {
		(v_lh.x ^ s_rh),
		(v_lh.y ^ s_rh),
		(v_lh.z ^ s_rh),
		(v_lh.w ^ s_rh),
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecBitXnor4ils(ilvec4 const v_lh, int const s_rh)
{
	ilvec4 const v_out = {
		~(v_lh.x ^ s_rh),
		~(v_lh.y ^ s_rh),
		~(v_lh.z ^ s_rh),
		~(v_lh.w ^ s_rh),
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecBitShiftLeft4ils(ilvec4 const v_lh, int const s_rh)
{
	ilvec4 const v_out = {
		(v_lh.x << s_rh),
		(v_lh.y << s_rh),
		(v_lh.z << s_rh),
		(v_lh.w << s_rh),
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecBitShiftRight4ils(ilvec4 const v_lh, int const s_rh)
{
	ilvec4 const v_out = {
		(v_lh.x >> s_rh),
		(v_lh.y >> s_rh),
		(v_lh.z >> s_rh),
		(v_lh.w >> s_rh),
	};
	return v_out;
}

ijk_inl bvec4 ijkVecEqual4ils(ilvec4 const v_lh, int const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x == s_rh),
		(v_lh.y == s_rh),
		(v_lh.z == s_rh),
		(v_lh.w == s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecInequal4ils(ilvec4 const v_lh, int const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x != s_rh),
		(v_lh.y != s_rh),
		(v_lh.z != s_rh),
		(v_lh.w != s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLessEqual4ils(ilvec4 const v_lh, int const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x <= s_rh),
		(v_lh.y <= s_rh),
		(v_lh.z <= s_rh),
		(v_lh.w <= s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreaterEqual4ils(ilvec4 const v_lh, int const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x >= s_rh),
		(v_lh.y >= s_rh),
		(v_lh.z >= s_rh),
		(v_lh.w >= s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLess4ils(ilvec4 const v_lh, int const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x < s_rh),
		(v_lh.y < s_rh),
		(v_lh.z < s_rh),
		(v_lh.w < s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreater4ils(ilvec4 const v_lh, int const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x > s_rh),
		(v_lh.y > s_rh),
		(v_lh.z > s_rh),
		(v_lh.w > s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecAnd4ils(ilvec4 const v_lh, int const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x && s_rh),
		(v_lh.y && s_rh),
		(v_lh.z && s_rh),
		(v_lh.w && s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNand4ils(ilvec4 const v_lh, int const s_rh)
{
	bvec4 const bv_out = {
		!(v_lh.x && s_rh),
		!(v_lh.y && s_rh),
		!(v_lh.z && s_rh),
		!(v_lh.w && s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecOr4ils(ilvec4 const v_lh, int const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x || s_rh),
		(v_lh.y || s_rh),
		(v_lh.z || s_rh),
		(v_lh.w || s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNor4ils(ilvec4 const v_lh, int const s_rh)
{
	bvec4 const bv_out = {
		!(v_lh.x || s_rh),
		!(v_lh.y || s_rh),
		!(v_lh.z || s_rh),
		!(v_lh.w || s_rh),
	};
	return bv_out;
}

ijk_inl ilvec4 ijkVecCopy4xyi(int const x, int const y, ilvec2 const v_zw)
{
	ilvec4 const v_out = { x, y, v_zw.x, v_zw.y };
	return v_out;
}

ijk_inl ilvec4 ijkVecCopy4xi(int const x, ilvec3 const v_yzw)
{
	ilvec4 const v_out = { x, v_yzw.x, v_yzw.y, v_yzw.z };
	return v_out;
}

ijk_inl ilvec4 ijkVecAdd4sil(int const s_lh, ilvec4 const v_rh)
{
	ilvec4 const v_out = {
		s_lh + v_rh.x,
		s_lh + v_rh.y,
		s_lh + v_rh.z,
		s_lh + v_rh.w,
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecSub4sil(int const s_lh, ilvec4 const v_rh)
{
	ilvec4 const v_out = {
		s_lh - v_rh.x,
		s_lh - v_rh.y,
		s_lh - v_rh.z,
		s_lh - v_rh.w,
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecMul4sil(int const s_lh, ilvec4 const v_rh)
{
	ilvec4 const v_out = {
		s_lh * v_rh.x,
		s_lh * v_rh.y,
		s_lh * v_rh.z,
		s_lh * v_rh.w,
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecDiv4sil(int const s_lh, ilvec4 const v_rh)
{
	ilvec4 const v_out = {
		s_lh / v_rh.x,
		s_lh / v_rh.y,
		s_lh / v_rh.z,
		s_lh / v_rh.w,
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecDivSafe4sil(int const s_lh, ilvec4 const v_rh)
{
	ilvec4 const v_out = {
		ijk_divide_safe_int(s_lh, v_rh.x),
		ijk_divide_safe_int(s_lh, v_rh.y),
		ijk_divide_safe_int(s_lh, v_rh.z),
		ijk_divide_safe_int(s_lh, v_rh.w),
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecMod4sil(int const s_lh, ilvec4 const v_rh)
{
	ilvec4 const v_out = {
		s_lh % v_rh.x,
		s_lh % v_rh.y,
		s_lh % v_rh.z,
		s_lh % v_rh.w,
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecModSafe4sil(int const s_lh, ilvec4 const v_rh)
{
	ilvec4 const v_out = {
		ijk_modulo_safe_int((i64)s_lh, v_rh.x),
		ijk_modulo_safe_int((i64)s_lh, v_rh.y),
		ijk_modulo_safe_int((i64)s_lh, v_rh.z),
		ijk_modulo_safe_int((i64)s_lh, v_rh.w),
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecBitAnd4sil(int const s_lh, ilvec4 const v_rh)
{
	ilvec4 const v_out = {
		(s_lh & v_rh.x),
		(s_lh & v_rh.y),
		(s_lh & v_rh.z),
		(s_lh & v_rh.w),
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecBitNand4sil(int const s_lh, ilvec4 const v_rh)
{
	ilvec4 const v_out = {
		~(s_lh & v_rh.x),
		~(s_lh & v_rh.y),
		~(s_lh & v_rh.z),
		~(s_lh & v_rh.w),
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecBitOr4sil(int const s_lh, ilvec4 const v_rh)
{
	ilvec4 const v_out = {
		(s_lh | v_rh.x),
		(s_lh | v_rh.y),
		(s_lh | v_rh.z),
		(s_lh | v_rh.w),
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecBitNor4sil(int const s_lh, ilvec4 const v_rh)
{
	ilvec4 const v_out = {
		~(s_lh | v_rh.x),
		~(s_lh | v_rh.y),
		~(s_lh | v_rh.z),
		~(s_lh | v_rh.w),
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecBitXor4sil(int const s_lh, ilvec4 const v_rh)
{
	ilvec4 const v_out = {
		(s_lh ^ v_rh.x),
		(s_lh ^ v_rh.y),
		(s_lh ^ v_rh.z),
		(s_lh ^ v_rh.w),
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecBitXnor4sil(int const s_lh, ilvec4 const v_rh)
{
	ilvec4 const v_out = {
		~(s_lh ^ v_rh.x),
		~(s_lh ^ v_rh.y),
		~(s_lh ^ v_rh.z),
		~(s_lh ^ v_rh.w),
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecBitShiftLeft4sil(int const s_lh, ilvec4 const v_rh)
{
	ilvec4 const v_out = {
		(s_lh << v_rh.x),
		(s_lh << v_rh.y),
		(s_lh << v_rh.z),
		(s_lh << v_rh.w),
	};
	return v_out;
}

ijk_inl ilvec4 ijkVecBitShiftRight4sil(int const s_lh, ilvec4 const v_rh)
{
	ilvec4 const v_out = {
		(s_lh >> v_rh.x),
		(s_lh >> v_rh.y),
		(s_lh >> v_rh.z),
		(s_lh >> v_rh.w),
	};
	return v_out;
}

ijk_inl bvec4 ijkVecEqual4sil(int const s_lh, ilvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh == v_rh.x),
		(s_lh == v_rh.y),
		(s_lh == v_rh.z),
		(s_lh == v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecInequal4sil(int const s_lh, ilvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh != v_rh.x),
		(s_lh != v_rh.y),
		(s_lh != v_rh.z),
		(s_lh != v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLessEqual4sil(int const s_lh, ilvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh <= v_rh.x),
		(s_lh <= v_rh.y),
		(s_lh <= v_rh.z),
		(s_lh <= v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreaterEqual4sil(int const s_lh, ilvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh >= v_rh.x),
		(s_lh >= v_rh.y),
		(s_lh >= v_rh.z),
		(s_lh >= v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLess4sil(int const s_lh, ilvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh < v_rh.x),
		(s_lh < v_rh.y),
		(s_lh < v_rh.z),
		(s_lh < v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreater4sil(int const s_lh, ilvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh > v_rh.x),
		(s_lh > v_rh.y),
		(s_lh > v_rh.z),
		(s_lh > v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecAnd4sil(int const s_lh, ilvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh && v_rh.x),
		(s_lh && v_rh.y),
		(s_lh && v_rh.z),
		(s_lh && v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNand4sil(int const s_lh, ilvec4 const v_rh)
{
	bvec4 const bv_out = {
		!(s_lh && v_rh.x),
		!(s_lh && v_rh.y),
		!(s_lh && v_rh.z),
		!(s_lh && v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecOr4sil(int const s_lh, ilvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh || v_rh.x),
		(s_lh || v_rh.y),
		(s_lh || v_rh.z),
		(s_lh || v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNor4sil(int const s_lh, ilvec4 const v_rh)
{
	bvec4 const bv_out = {
		!(s_lh || v_rh.x),
		!(s_lh || v_rh.y),
		!(s_lh || v_rh.z),
		!(s_lh || v_rh.w),
	};
	return bv_out;
}

ijk_inl int ijkVecDot4il(ilvec4 const v_lh, ilvec4 const v_rh)
{
	return ijkVecDot4ilv(v_lh.xyzw, v_rh.xyzw);
}

ijk_inl ilvec4 ijkVecCross4il(ilvec4 const v_lh, ilvec4 const v_rh)
{
	ilvec4 v_out;
	ijkVecCross4ilv(v_out.xyzw, v_lh.xyzw, v_rh.xyzw);
	return v_out;
}


//-----------------------------------------------------------------------------


#endif	// !_IJK_VECTOR_INTL_INL_
#endif	// _IJK_VECTOR_INTL_H_