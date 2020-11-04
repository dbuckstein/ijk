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

	ijkVector_int.inl
	Inline definitions for signed 32-bit integer vector functions.
*/

#ifdef _IJK_VECTOR_INT_H_
#ifndef _IJK_VECTOR_INT_INL_
#define _IJK_VECTOR_INT_INL_


//-----------------------------------------------------------------------------

ijk_inl i32 ijkVecAbs1is(i32 const s)
{
	return ijk_abs_int(s);
}

ijk_inl i32 ijkVecSgn1is(i32 const s)
{
	return ijk_sgn_int(s);
}

ijk_inl i32 ijkVecDot1is(i32 const s_lh, i32 const s_rh)
{
	return (s_lh * s_rh);
}

ijk_inl i32 ijkVecLengthSq1is(i32 const s)
{
	return (s * s);
}

ijk_inl i32 ijkVecLength1is(i32 const s)
{
	return ijk_abs_int(s);
}

ijk_inl f32 ijkVecLengthSqInv1is(i32 const s)
{
	i32 const lengthSq = (s * s);
	return ijk_recip_safe_flt(lengthSq);
}

ijk_inl f32 ijkVecLengthInv1is(i32 const s)
{
	i32 const length = ijk_abs_int(s);
	return ijk_recip_safe_flt(length);
}

ijk_inl i32 ijkVecNormalize1is(i32 const s)
{
	return ijk_sgn_int(s);
}

ijk_inl i32 ijkVecNormalizeGetLength1is(i32 const s, i32* const length_out)
{
	i32 const length = *length_out = ijk_abs_int(s);
	return ijk_sgn_int(s);
}

ijk_inl i32 ijkVecNormalizeGetLengthInv1is(i32 const s, f32* const lengthInv_out)
{
	i32 const length = ijk_abs_int(s);
	*lengthInv_out = ijk_recip_safe_flt(length);
	return ijk_sgn_int(s);
}


//-----------------------------------------------------------------------------

ijk_inl intv ijkVecPiv(intv v_out)
{
	return v_out;
}


//-----------------------------------------------------------------------------

ijk_inl intv ijkVecInit2iv(int2 v_out)
{
	v_out[0] = v_out[1] = 0;
	return v_out;
}

ijk_inl intv ijkVecInitElems2iv(int2 v_out, i32 const x, i32 const y)
{
	v_out[0] = x;
	v_out[1] = y;
	return v_out;
}

ijk_inl intv ijkVecCopy2iv(int2 v_out, int2 const v_in)
{
	v_out[0] = +v_in[0];
	v_out[1] = +v_in[1];
	return v_out;
}

ijk_inl intv ijkVecNegate2iv(int2 v_out, int2 const v_in)
{
	v_out[0] = -v_in[0];
	v_out[1] = -v_in[1];
	return v_out;
}

ijk_inl intv ijkVecBitNot2iv(int2 v_out, int2 const v_in)
{
	v_out[0] = ~v_in[0];
	v_out[1] = ~v_in[1];
	return v_out;
}

ijk_inl boolv ijkVecNot2iv(bool2 bv_out, int2 const v_in)
{
	bv_out[0] = !v_in[0];
	bv_out[1] = !v_in[1];
	return bv_out;
}

ijk_inl intv ijkVecAdd2iv(int2 v_out, int2 const v_lh, int2 const v_rh)
{
	v_out[0] = v_lh[0] + v_rh[0];
	v_out[1] = v_lh[1] + v_rh[1];
	return v_out;
}

ijk_inl intv ijkVecSub2iv(int2 v_out, int2 const v_lh, int2 const v_rh)
{
	v_out[0] = v_lh[0] - v_rh[0];
	v_out[1] = v_lh[1] - v_rh[1];
	return v_out;
}

ijk_inl intv ijkVecMul2iv(int2 v_out, int2 const v_lh, int2 const v_rh)
{
	v_out[0] = v_lh[0] * v_rh[0];
	v_out[1] = v_lh[1] * v_rh[1];
	return v_out;
}

ijk_inl intv ijkVecDiv2iv(int2 v_out, int2 const v_lh, int2 const v_rh)
{
	v_out[0] = v_lh[0] / v_rh[0];
	v_out[1] = v_lh[1] / v_rh[1];
	return v_out;
}

ijk_inl intv ijkVecDivSafe2iv(int2 v_out, int2 const v_lh, int2 const v_rh)
{
	v_out[0] = ijk_divide_safe_int(v_lh[0], v_rh[0]);
	v_out[1] = ijk_divide_safe_int(v_lh[1], v_rh[1]);
	return v_out;
}

ijk_inl intv ijkVecMod2iv(int2 v_out, int2 const v_lh, int2 const v_rh)
{
	v_out[0] = v_lh[0] % v_rh[0];
	v_out[1] = v_lh[1] % v_rh[1];
	return v_out;
}

ijk_inl intv ijkVecModSafe2iv(int2 v_out, int2 const v_lh, int2 const v_rh)
{
	v_out[0] = ijk_modulo_safe_int(v_lh[0], v_rh[0]);
	v_out[1] = ijk_modulo_safe_int(v_lh[1], v_rh[1]);
	return v_out;
}

ijk_inl intv ijkVecBitAnd2iv(int2 v_out, int2 const v_lh, int2 const v_rh)
{
	v_out[0] = (v_lh[0] & v_rh[0]);
	v_out[1] = (v_lh[1] & v_rh[1]);
	return v_out;
}

ijk_inl intv ijkVecBitNand2iv(int2 v_out, int2 const v_lh, int2 const v_rh)
{
	v_out[0] = ~(v_lh[0] & v_rh[0]);
	v_out[1] = ~(v_lh[1] & v_rh[1]);
	return v_out;
}

ijk_inl intv ijkVecBitOr2iv(int2 v_out, int2 const v_lh, int2 const v_rh)
{
	v_out[0] = (v_lh[0] | v_rh[0]);
	v_out[1] = (v_lh[1] | v_rh[1]);
	return v_out;
}

ijk_inl intv ijkVecBitNor2iv(int2 v_out, int2 const v_lh, int2 const v_rh)
{
	v_out[0] = ~(v_lh[0] | v_rh[0]);
	v_out[1] = ~(v_lh[1] | v_rh[1]);
	return v_out;
}

ijk_inl intv ijkVecBitXor2iv(int2 v_out, int2 const v_lh, int2 const v_rh)
{
	v_out[0] = (v_lh[0] ^ v_rh[0]);
	v_out[1] = (v_lh[1] ^ v_rh[1]);
	return v_out;
}

ijk_inl intv ijkVecBitXnor2iv(int2 v_out, int2 const v_lh, int2 const v_rh)
{
	v_out[0] = ~(v_lh[0] ^ v_rh[0]);
	v_out[1] = ~(v_lh[1] ^ v_rh[1]);
	return v_out;
}

ijk_inl intv ijkVecBitShiftLeft2iv(int2 v_out, int2 const v_lh, int2 const v_rh)
{
	v_out[0] = (v_lh[0] << v_rh[0]);
	v_out[1] = (v_lh[1] << v_rh[1]);
	return v_out;
}

ijk_inl intv ijkVecBitShiftRight2iv(int2 v_out, int2 const v_lh, int2 const v_rh)
{
	v_out[0] = (v_lh[0] >> v_rh[0]);
	v_out[1] = (v_lh[1] >> v_rh[1]);
	return v_out;
}

ijk_inl boolv ijkVecEqual2iv(bool2 bv_out, int2 const v_lh, int2 const v_rh)
{
	bv_out[0] = (v_lh[0] == v_rh[0]);
	bv_out[1] = (v_lh[1] == v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal2iv(bool2 bv_out, int2 const v_lh, int2 const v_rh)
{
	bv_out[0] = (v_lh[0] != v_rh[0]);
	bv_out[1] = (v_lh[1] != v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual2iv(bool2 bv_out, int2 const v_lh, int2 const v_rh)
{
	bv_out[0] = (v_lh[0] <= v_rh[0]);
	bv_out[1] = (v_lh[1] <= v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual2iv(bool2 bv_out, int2 const v_lh, int2 const v_rh)
{
	bv_out[0] = (v_lh[0] >= v_rh[0]);
	bv_out[1] = (v_lh[1] >= v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecLess2iv(bool2 bv_out, int2 const v_lh, int2 const v_rh)
{
	bv_out[0] = (v_lh[0] < v_rh[0]);
	bv_out[1] = (v_lh[1] < v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater2iv(bool2 bv_out, int2 const v_lh, int2 const v_rh)
{
	bv_out[0] = (v_lh[0] > v_rh[0]);
	bv_out[1] = (v_lh[1] > v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd2iv(bool2 bv_out, int2 const v_lh, int2 const v_rh)
{
	bv_out[0] = (v_lh[0] && v_rh[0]);
	bv_out[1] = (v_lh[1] && v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecNand2iv(bool2 bv_out, int2 const v_lh, int2 const v_rh)
{
	bv_out[0] = !(v_lh[0] && v_rh[0]);
	bv_out[1] = !(v_lh[1] && v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecOr2iv(bool2 bv_out, int2 const v_lh, int2 const v_rh)
{
	bv_out[0] = (v_lh[0] || v_rh[0]);
	bv_out[1] = (v_lh[1] || v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecNor2iv(bool2 bv_out, int2 const v_lh, int2 const v_rh)
{
	bv_out[0] = !(v_lh[0] || v_rh[0]);
	bv_out[1] = !(v_lh[1] || v_rh[1]);
	return bv_out;
}

ijk_inl intv ijkVecCopy2ivs(int2 v_out, i32 const s_in)
{
	v_out[0] = v_out[1] = +s_in;
	return v_out;
}

ijk_inl intv ijkVecNegate2ivs(int2 v_out, i32 const s_in)
{
	v_out[0] = v_out[1] = -s_in;
	return v_out;
}

ijk_inl intv ijkVecBitNot2ivs(int2 v_out, i32 const s_in)
{
	v_out[0] = v_out[1] = ~s_in;
	return v_out;
}

ijk_inl boolv ijkVecNot2ivs(bool2 bv_out, i32 const s_in)
{
	bv_out[0] = bv_out[1] = !s_in;
	return bv_out;
}

ijk_inl intv ijkVecAdd2ivs(int2 v_out, int2 const v_lh, i32 const s_rh)
{
	v_out[0] = v_lh[0] + s_rh;
	v_out[1] = v_lh[1] + s_rh;
	return v_out;
}

ijk_inl intv ijkVecSub2ivs(int2 v_out, int2 const v_lh, i32 const s_rh)
{
	v_out[0] = v_lh[0] - s_rh;
	v_out[1] = v_lh[1] - s_rh;
	return v_out;
}

ijk_inl intv ijkVecMul2ivs(int2 v_out, int2 const v_lh, i32 const s_rh)
{
	v_out[0] = v_lh[0] * s_rh;
	v_out[1] = v_lh[1] * s_rh;
	return v_out;
}

ijk_inl intv ijkVecDiv2ivs(int2 v_out, int2 const v_lh, i32 const s_rh)
{
	v_out[0] = v_lh[0] / s_rh;
	v_out[1] = v_lh[1] / s_rh;
	return v_out;
}

ijk_inl intv ijkVecDivSafe2ivs(int2 v_out, int2 const v_lh, i32 const s_rh)
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

ijk_inl intv ijkVecMod2ivs(int2 v_out, int2 const v_lh, i32 const s_rh)
{
	v_out[0] = v_lh[0] % s_rh;
	v_out[1] = v_lh[1] % s_rh;
	return v_out;
}

ijk_inl intv ijkVecModSafe2ivs(int2 v_out, int2 const v_lh, i32 const s_rh)
{
	if (s_rh)
	{
		v_out[0] = v_lh[0] % s_rh;
		v_out[1] = v_lh[1] % s_rh;
	}
	else
		v_out[0] = v_out[1] = 0;
	return v_out;
}

ijk_inl intv ijkVecBitAnd2ivs(int2 v_out, int2 const v_lh, i32 const s_rh)
{
	v_out[0] = (v_lh[0] & s_rh);
	v_out[1] = (v_lh[1] & s_rh);
	return v_out;
}

ijk_inl intv ijkVecBitNand2ivs(int2 v_out, int2 const v_lh, i32 const s_rh)
{
	v_out[0] = ~(v_lh[0] & s_rh);
	v_out[1] = ~(v_lh[1] & s_rh);
	return v_out;
}

ijk_inl intv ijkVecBitOr2ivs(int2 v_out, int2 const v_lh, i32 const s_rh)
{
	v_out[0] = (v_lh[0] | s_rh);
	v_out[1] = (v_lh[1] | s_rh);
	return v_out;
}

ijk_inl intv ijkVecBitNor2ivs(int2 v_out, int2 const v_lh, i32 const s_rh)
{
	v_out[0] = ~(v_lh[0] | s_rh);
	v_out[1] = ~(v_lh[1] | s_rh);
	return v_out;
}

ijk_inl intv ijkVecBitXor2ivs(int2 v_out, int2 const v_lh, i32 const s_rh)
{
	v_out[0] = (v_lh[0] ^ s_rh);
	v_out[1] = (v_lh[1] ^ s_rh);
	return v_out;
}

ijk_inl intv ijkVecBitXnor2ivs(int2 v_out, int2 const v_lh, i32 const s_rh)
{
	v_out[0] = ~(v_lh[0] ^ s_rh);
	v_out[1] = ~(v_lh[1] ^ s_rh);
	return v_out;
}

ijk_inl intv ijkVecBitShiftLeft2ivs(int2 v_out, int2 const v_lh, i32 const s_rh)
{
	v_out[0] = (v_lh[0] << s_rh);
	v_out[1] = (v_lh[1] << s_rh);
	return v_out;
}

ijk_inl intv ijkVecBitShiftRight2ivs(int2 v_out, int2 const v_lh, i32 const s_rh)
{
	v_out[0] = (v_lh[0] >> s_rh);
	v_out[1] = (v_lh[1] >> s_rh);
	return v_out;
}

ijk_inl boolv ijkVecEqual2ivs(bool2 bv_out, int2 const v_lh, i32 const s_rh)
{
	bv_out[0] = (v_lh[0] == s_rh);
	bv_out[1] = (v_lh[1] == s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecInequal2ivs(bool2 bv_out, int2 const v_lh, i32 const s_rh)
{
	bv_out[0] = (v_lh[0] != s_rh);
	bv_out[1] = (v_lh[1] != s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual2ivs(bool2 bv_out, int2 const v_lh, i32 const s_rh)
{
	bv_out[0] = (v_lh[0] <= s_rh);
	bv_out[1] = (v_lh[1] <= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual2ivs(bool2 bv_out, int2 const v_lh, i32 const s_rh)
{
	bv_out[0] = (v_lh[0] >= s_rh);
	bv_out[1] = (v_lh[1] >= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLess2ivs(bool2 bv_out, int2 const v_lh, i32 const s_rh)
{
	bv_out[0] = (v_lh[0] < s_rh);
	bv_out[1] = (v_lh[1] < s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreater2ivs(bool2 bv_out, int2 const v_lh, i32 const s_rh)
{
	bv_out[0] = (v_lh[0] > s_rh);
	bv_out[1] = (v_lh[1] > s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecAnd2ivs(bool2 bv_out, int2 const v_lh, i32 const s_rh)
{
	bv_out[0] = (v_lh[0] && s_rh);
	bv_out[1] = (v_lh[1] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNand2ivs(bool2 bv_out, int2 const v_lh, i32 const s_rh)
{
	bv_out[0] = !(v_lh[0] && s_rh);
	bv_out[1] = !(v_lh[1] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecOr2ivs(bool2 bv_out, int2 const v_lh, i32 const s_rh)
{
	bv_out[0] = (v_lh[0] || s_rh);
	bv_out[1] = (v_lh[1] || s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNor2ivs(bool2 bv_out, int2 const v_lh, i32 const s_rh)
{
	bv_out[0] = !(v_lh[0] || s_rh);
	bv_out[1] = !(v_lh[1] || s_rh);
	return bv_out;
}

ijk_inl intv ijkVecAdd2isv(int2 v_out, i32 const s_lh, int2 const v_rh)
{
	v_out[0] = s_lh + v_rh[0];
	v_out[1] = s_lh + v_rh[1];
	return v_out;
}

ijk_inl intv ijkVecSub2isv(int2 v_out, i32 const s_lh, int2 const v_rh)
{
	v_out[0] = s_lh - v_rh[0];
	v_out[1] = s_lh - v_rh[1];
	return v_out;
}

ijk_inl intv ijkVecMul2isv(int2 v_out, i32 const s_lh, int2 const v_rh)
{
	v_out[0] = s_lh * v_rh[0];
	v_out[1] = s_lh * v_rh[1];
	return v_out;
}

ijk_inl intv ijkVecDiv2isv(int2 v_out, i32 const s_lh, int2 const v_rh)
{
	v_out[0] = s_lh / v_rh[0];
	v_out[1] = s_lh / v_rh[1];
	return v_out;
}

ijk_inl intv ijkVecDivSafe2isv(int2 v_out, i32 const s_lh, int2 const v_rh)
{
	v_out[0] = ijk_divide_safe_int(s_lh, v_rh[0]);
	v_out[1] = ijk_divide_safe_int(s_lh, v_rh[1]);
	return v_out;
}

ijk_inl intv ijkVecMod2isv(int2 v_out, i32 const s_lh, int2 const v_rh)
{
	v_out[0] = s_lh % v_rh[0];
	v_out[1] = s_lh % v_rh[1];
	return v_out;
}

ijk_inl intv ijkVecModSafe2isv(int2 v_out, i32 const s_lh, int2 const v_rh)
{
	v_out[0] = ijk_modulo_safe_int(s_lh, v_rh[0]);
	v_out[1] = ijk_modulo_safe_int(s_lh, v_rh[1]);
	return v_out;
}

ijk_inl intv ijkVecBitAnd2isv(int2 v_out, i32 const s_lh, int2 const v_rh)
{
	v_out[0] = (s_lh & v_rh[0]);
	v_out[1] = (s_lh & v_rh[1]);
	return v_out;
}

ijk_inl intv ijkVecBitNand2isv(int2 v_out, i32 const s_lh, int2 const v_rh)
{
	v_out[0] = ~(s_lh & v_rh[0]);
	v_out[1] = ~(s_lh & v_rh[1]);
	return v_out;
}

ijk_inl intv ijkVecBitOr2isv(int2 v_out, i32 const s_lh, int2 const v_rh)
{
	v_out[0] = (s_lh | v_rh[0]);
	v_out[1] = (s_lh | v_rh[1]);
	return v_out;
}

ijk_inl intv ijkVecBitNor2isv(int2 v_out, i32 const s_lh, int2 const v_rh)
{
	v_out[0] = ~(s_lh | v_rh[0]);
	v_out[1] = ~(s_lh | v_rh[1]);
	return v_out;
}

ijk_inl intv ijkVecBitXor2isv(int2 v_out, i32 const s_lh, int2 const v_rh)
{
	v_out[0] = (s_lh ^ v_rh[0]);
	v_out[1] = (s_lh ^ v_rh[1]);
	return v_out;
}

ijk_inl intv ijkVecBitXnor2isv(int2 v_out, i32 const s_lh, int2 const v_rh)
{
	v_out[0] = ~(s_lh ^ v_rh[0]);
	v_out[1] = ~(s_lh ^ v_rh[1]);
	return v_out;
}

ijk_inl intv ijkVecBitShiftLeft2isv(int2 v_out, i32 const s_lh, int2 const v_rh)
{
	v_out[0] = (s_lh << v_rh[0]);
	v_out[1] = (s_lh << v_rh[1]);
	return v_out;
}

ijk_inl intv ijkVecBitShiftRight2isv(int2 v_out, i32 const s_lh, int2 const v_rh)
{
	v_out[0] = (s_lh >> v_rh[0]);
	v_out[1] = (s_lh >> v_rh[1]);
	return v_out;
}

ijk_inl boolv ijkVecEqual2isv(bool2 bv_out, i32 const s_lh, int2 const v_rh)
{
	bv_out[0] = (s_lh == v_rh[0]);
	bv_out[1] = (s_lh == v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal2isv(bool2 bv_out, i32 const s_lh, int2 const v_rh)
{
	bv_out[0] = (s_lh != v_rh[0]);
	bv_out[1] = (s_lh != v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual2isv(bool2 bv_out, i32 const s_lh, int2 const v_rh)
{
	bv_out[0] = (s_lh <= v_rh[0]);
	bv_out[1] = (s_lh <= v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual2isv(bool2 bv_out, i32 const s_lh, int2 const v_rh)
{
	bv_out[0] = (s_lh >= v_rh[0]);
	bv_out[1] = (s_lh >= v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecLess2isv(bool2 bv_out, i32 const s_lh, int2 const v_rh)
{
	bv_out[0] = (s_lh < v_rh[0]);
	bv_out[1] = (s_lh < v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater2isv(bool2 bv_out, i32 const s_lh, int2 const v_rh)
{
	bv_out[0] = (s_lh > v_rh[0]);
	bv_out[1] = (s_lh > v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd2isv(bool2 bv_out, i32 const s_lh, int2 const v_rh)
{
	bv_out[0] = (s_lh && v_rh[0]);
	bv_out[1] = (s_lh && v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecNand2isv(bool2 bv_out, i32 const s_lh, int2 const v_rh)
{
	bv_out[0] = !(s_lh && v_rh[0]);
	bv_out[1] = !(s_lh && v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecOr2isv(bool2 bv_out, i32 const s_lh, int2 const v_rh)
{
	bv_out[0] = (s_lh || v_rh[0]);
	bv_out[1] = (s_lh || v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecNor2isv(bool2 bv_out, i32 const s_lh, int2 const v_rh)
{
	bv_out[0] = !(s_lh || v_rh[0]);
	bv_out[1] = !(s_lh || v_rh[1]);
	return bv_out;
}

ijk_inl i32 ijkVecDot2iv(int2 const v_lh, int2 const v_rh)
{
	return (v_lh[0] * v_rh[0] + v_lh[1] * v_rh[1]);
}

ijk_inl i32 ijkVecCross2iv(int2 const v_lh, int2 const v_rh)
{
	return (v_lh[0] * v_rh[1] - v_lh[1] * v_rh[0]);
}


//-----------------------------------------------------------------------------

ijk_inl intv ijkVecInit3iv(int3 v_out)
{
	v_out[0] = v_out[1] = v_out[2] = 0;
	return v_out;
}

ijk_inl intv ijkVecInitElems3iv(int3 v_out, i32 const x, i32 const y, i32 const z)
{
	v_out[0] = x;
	v_out[1] = y;
	v_out[2] = z;
	return v_out;
}

ijk_inl intv ijkVecCopy3iv(int3 v_out, int3 const v_in)
{
	v_out[0] = +v_in[0];
	v_out[1] = +v_in[1];
	v_out[2] = +v_in[2];
	return v_out;
}

ijk_inl intv ijkVecNegate3iv(int3 v_out, int3 const v_in)
{
	v_out[0] = -v_in[0];
	v_out[1] = -v_in[1];
	v_out[2] = -v_in[2];
	return v_out;
}

ijk_inl intv ijkVecBitNot3iv(int3 v_out, int3 const v_in)
{
	v_out[0] = ~v_in[0];
	v_out[1] = ~v_in[1];
	v_out[2] = ~v_in[2];
	return v_out;
}

ijk_inl boolv ijkVecNot3iv(bool3 bv_out, int3 const v_in)
{
	bv_out[0] = !v_in[0];
	bv_out[1] = !v_in[1];
	bv_out[2] = !v_in[2];
	return bv_out;
}

ijk_inl intv ijkVecAdd3iv(int3 v_out, int3 const v_lh, int3 const v_rh)
{
	v_out[0] = v_lh[0] + v_rh[0];
	v_out[1] = v_lh[1] + v_rh[1];
	v_out[2] = v_lh[2] + v_rh[2];
	return v_out;
}

ijk_inl intv ijkVecSub3iv(int3 v_out, int3 const v_lh, int3 const v_rh)
{
	v_out[0] = v_lh[0] - v_rh[0];
	v_out[1] = v_lh[1] - v_rh[1];
	v_out[2] = v_lh[2] - v_rh[2];
	return v_out;
}

ijk_inl intv ijkVecMul3iv(int3 v_out, int3 const v_lh, int3 const v_rh)
{
	v_out[0] = v_lh[0] * v_rh[0];
	v_out[1] = v_lh[1] * v_rh[1];
	v_out[2] = v_lh[2] * v_rh[2];
	return v_out;
}

ijk_inl intv ijkVecDiv3iv(int3 v_out, int3 const v_lh, int3 const v_rh)
{
	v_out[0] = v_lh[0] / v_rh[0];
	v_out[1] = v_lh[1] / v_rh[1];
	v_out[2] = v_lh[2] / v_rh[2];
	return v_out;
}

ijk_inl intv ijkVecDivSafe3iv(int3 v_out, int3 const v_lh, int3 const v_rh)
{
	v_out[0] = ijk_divide_safe_int(v_lh[0], v_rh[0]);
	v_out[1] = ijk_divide_safe_int(v_lh[1], v_rh[1]);
	v_out[2] = ijk_divide_safe_int(v_lh[2], v_rh[2]);
	return v_out;
}

ijk_inl intv ijkVecMod3iv(int3 v_out, int3 const v_lh, int3 const v_rh)
{
	v_out[0] = v_lh[0] % v_rh[0];
	v_out[1] = v_lh[1] % v_rh[1];
	v_out[2] = v_lh[2] % v_rh[2];
	return v_out;
}

ijk_inl intv ijkVecModSafe3iv(int3 v_out, int3 const v_lh, int3 const v_rh)
{
	v_out[0] = ijk_modulo_safe_int(v_lh[0], v_rh[0]);
	v_out[1] = ijk_modulo_safe_int(v_lh[1], v_rh[1]);
	v_out[2] = ijk_modulo_safe_int(v_lh[2], v_rh[2]);
	return v_out;
}

ijk_inl intv ijkVecBitAnd3iv(int3 v_out, int3 const v_lh, int3 const v_rh)
{
	v_out[0] = (v_lh[0] & v_rh[0]);
	v_out[1] = (v_lh[1] & v_rh[1]);
	v_out[2] = (v_lh[2] & v_rh[2]);
	return v_out;
}

ijk_inl intv ijkVecBitNand3iv(int3 v_out, int3 const v_lh, int3 const v_rh)
{
	v_out[0] = ~(v_lh[0] & v_rh[0]);
	v_out[1] = ~(v_lh[1] & v_rh[1]);
	v_out[2] = ~(v_lh[2] & v_rh[2]);
	return v_out;
}

ijk_inl intv ijkVecBitOr3iv(int3 v_out, int3 const v_lh, int3 const v_rh)
{
	v_out[0] = (v_lh[0] | v_rh[0]);
	v_out[1] = (v_lh[1] | v_rh[1]);
	v_out[2] = (v_lh[2] | v_rh[2]);
	return v_out;
}

ijk_inl intv ijkVecBitNor3iv(int3 v_out, int3 const v_lh, int3 const v_rh)
{
	v_out[0] = ~(v_lh[0] | v_rh[0]);
	v_out[1] = ~(v_lh[1] | v_rh[1]);
	v_out[2] = ~(v_lh[2] | v_rh[2]);
	return v_out;
}

ijk_inl intv ijkVecBitXor3iv(int3 v_out, int3 const v_lh, int3 const v_rh)
{
	v_out[0] = (v_lh[0] ^ v_rh[0]);
	v_out[1] = (v_lh[1] ^ v_rh[1]);
	v_out[2] = (v_lh[2] ^ v_rh[2]);
	return v_out;
}

ijk_inl intv ijkVecBitXnor3iv(int3 v_out, int3 const v_lh, int3 const v_rh)
{
	v_out[0] = ~(v_lh[0] ^ v_rh[0]);
	v_out[1] = ~(v_lh[1] ^ v_rh[1]);
	v_out[2] = ~(v_lh[2] ^ v_rh[2]);
	return v_out;
}

ijk_inl intv ijkVecBitShiftLeft3iv(int3 v_out, int3 const v_lh, int3 const v_rh)
{
	v_out[0] = (v_lh[0] << v_rh[0]);
	v_out[1] = (v_lh[1] << v_rh[1]);
	v_out[2] = (v_lh[2] << v_rh[2]);
	return v_out;
}

ijk_inl intv ijkVecBitShiftRight3iv(int3 v_out, int3 const v_lh, int3 const v_rh)
{
	v_out[0] = (v_lh[0] >> v_rh[0]);
	v_out[1] = (v_lh[1] >> v_rh[1]);
	v_out[2] = (v_lh[2] >> v_rh[2]);
	return v_out;
}

ijk_inl boolv ijkVecEqual3iv(bool3 bv_out, int3 const v_lh, int3 const v_rh)
{
	bv_out[0] = (v_lh[0] == v_rh[0]);
	bv_out[1] = (v_lh[1] == v_rh[1]);
	bv_out[2] = (v_lh[2] == v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal3iv(bool3 bv_out, int3 const v_lh, int3 const v_rh)
{
	bv_out[0] = (v_lh[0] != v_rh[0]);
	bv_out[1] = (v_lh[1] != v_rh[1]);
	bv_out[2] = (v_lh[2] != v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual3iv(bool3 bv_out, int3 const v_lh, int3 const v_rh)
{
	bv_out[0] = (v_lh[0] <= v_rh[0]);
	bv_out[1] = (v_lh[1] <= v_rh[1]);
	bv_out[2] = (v_lh[2] <= v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual3iv(bool3 bv_out, int3 const v_lh, int3 const v_rh)
{
	bv_out[0] = (v_lh[0] >= v_rh[0]);
	bv_out[1] = (v_lh[1] >= v_rh[1]);
	bv_out[2] = (v_lh[2] >= v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecLess3iv(bool3 bv_out, int3 const v_lh, int3 const v_rh)
{
	bv_out[0] = (v_lh[0] < v_rh[0]);
	bv_out[1] = (v_lh[1] < v_rh[1]);
	bv_out[2] = (v_lh[2] < v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater3iv(bool3 bv_out, int3 const v_lh, int3 const v_rh)
{
	bv_out[0] = (v_lh[0] > v_rh[0]);
	bv_out[1] = (v_lh[1] > v_rh[1]);
	bv_out[2] = (v_lh[2] > v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd3iv(bool3 bv_out, int3 const v_lh, int3 const v_rh)
{
	bv_out[0] = (v_lh[0] && v_rh[0]);
	bv_out[1] = (v_lh[1] && v_rh[1]);
	bv_out[2] = (v_lh[2] && v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecNand3iv(bool3 bv_out, int3 const v_lh, int3 const v_rh)
{
	bv_out[0] = !(v_lh[0] && v_rh[0]);
	bv_out[1] = !(v_lh[1] && v_rh[1]);
	bv_out[2] = !(v_lh[2] && v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecOr3iv(bool3 bv_out, int3 const v_lh, int3 const v_rh)
{
	bv_out[0] = (v_lh[0] || v_rh[0]);
	bv_out[1] = (v_lh[1] || v_rh[1]);
	bv_out[2] = (v_lh[2] || v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecNor3iv(bool3 bv_out, int3 const v_lh, int3 const v_rh)
{
	bv_out[0] = !(v_lh[0] || v_rh[0]);
	bv_out[1] = !(v_lh[1] || v_rh[1]);
	bv_out[2] = !(v_lh[2] || v_rh[2]);
	return bv_out;
}

ijk_inl intv ijkVecCopy3ivz(int3 v_out, int2 const v_xy, i32 const z)
{
	v_out[0] = v_xy[0];
	v_out[1] = v_xy[1];
	v_out[2] = z;
	return v_out;
}

ijk_inl intv ijkVecCopy3ivs(int3 v_out, i32 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = +s_in;
	return v_out;
}

ijk_inl intv ijkVecNegate3ivs(int3 v_out, i32 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = -s_in;
	return v_out;
}

ijk_inl intv ijkVecBitNot3ivs(int3 v_out, i32 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = ~s_in;
	return v_out;
}

ijk_inl boolv ijkVecNot3ivs(bool3 bv_out, i32 const s_in)
{
	bv_out[0] = bv_out[1] = bv_out[2] = !s_in;
	return bv_out;
}

ijk_inl intv ijkVecAdd3ivs(int3 v_out, int3 const v_lh, i32 const s_rh)
{
	v_out[0] = v_lh[0] + s_rh;
	v_out[1] = v_lh[1] + s_rh;
	v_out[2] = v_lh[2] + s_rh;
	return v_out;
}

ijk_inl intv ijkVecSub3ivs(int3 v_out, int3 const v_lh, i32 const s_rh)
{
	v_out[0] = v_lh[0] - s_rh;
	v_out[1] = v_lh[1] - s_rh;
	v_out[2] = v_lh[2] - s_rh;
	return v_out;
}

ijk_inl intv ijkVecMul3ivs(int3 v_out, int3 const v_lh, i32 const s_rh)
{
	v_out[0] = v_lh[0] * s_rh;
	v_out[1] = v_lh[1] * s_rh;
	v_out[2] = v_lh[2] * s_rh;
	return v_out;
}

ijk_inl intv ijkVecDiv3ivs(int3 v_out, int3 const v_lh, i32 const s_rh)
{
	v_out[0] = v_lh[0] / s_rh;
	v_out[1] = v_lh[1] / s_rh;
	v_out[2] = v_lh[2] / s_rh;
	return v_out;
}

ijk_inl intv ijkVecDivSafe3ivs(int3 v_out, int3 const v_lh, i32 const s_rh)
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

ijk_inl intv ijkVecMod3ivs(int3 v_out, int3 const v_lh, i32 const s_rh)
{
	v_out[0] = v_lh[0] % s_rh;
	v_out[1] = v_lh[1] % s_rh;
	v_out[2] = v_lh[2] % s_rh;
	return v_out;
}

ijk_inl intv ijkVecModSafe3ivs(int3 v_out, int3 const v_lh, i32 const s_rh)
{
	if (s_rh)
	{
		v_out[0] = v_lh[0] % s_rh;
		v_out[1] = v_lh[1] % s_rh;
		v_out[2] = v_lh[2] % s_rh;
	}
	else
		v_out[0] = v_out[1] = v_out[2] = 0;
	return v_out;
}

ijk_inl intv ijkVecBitAnd3ivs(int3 v_out, int3 const v_lh, i32 const s_rh)
{
	v_out[0] = (v_lh[0] & s_rh);
	v_out[1] = (v_lh[1] & s_rh);
	v_out[2] = (v_lh[2] & s_rh);
	return v_out;
}

ijk_inl intv ijkVecBitNand3ivs(int3 v_out, int3 const v_lh, i32 const s_rh)
{
	v_out[0] = ~(v_lh[0] & s_rh);
	v_out[1] = ~(v_lh[1] & s_rh);
	v_out[2] = ~(v_lh[2] & s_rh);
	return v_out;
}

ijk_inl intv ijkVecBitOr3ivs(int3 v_out, int3 const v_lh, i32 const s_rh)
{
	v_out[0] = (v_lh[0] | s_rh);
	v_out[1] = (v_lh[1] | s_rh);
	v_out[2] = (v_lh[2] | s_rh);
	return v_out;
}

ijk_inl intv ijkVecBitNor3ivs(int3 v_out, int3 const v_lh, i32 const s_rh)
{
	v_out[0] = ~(v_lh[0] | s_rh);
	v_out[1] = ~(v_lh[1] | s_rh);
	v_out[2] = ~(v_lh[2] | s_rh);
	return v_out;
}

ijk_inl intv ijkVecBitXor3ivs(int3 v_out, int3 const v_lh, i32 const s_rh)
{
	v_out[0] = (v_lh[0] ^ s_rh);
	v_out[1] = (v_lh[1] ^ s_rh);
	v_out[2] = (v_lh[2] ^ s_rh);
	return v_out;
}

ijk_inl intv ijkVecBitXnor3ivs(int3 v_out, int3 const v_lh, i32 const s_rh)
{
	v_out[0] = ~(v_lh[0] ^ s_rh);
	v_out[1] = ~(v_lh[1] ^ s_rh);
	v_out[2] = ~(v_lh[2] ^ s_rh);
	return v_out;
}

ijk_inl intv ijkVecBitShiftLeft3ivs(int3 v_out, int3 const v_lh, i32 const s_rh)
{
	v_out[0] = (v_lh[0] << s_rh);
	v_out[1] = (v_lh[1] << s_rh);
	v_out[2] = (v_lh[2] << s_rh);
	return v_out;
}

ijk_inl intv ijkVecBitShiftRight3ivs(int3 v_out, int3 const v_lh, i32 const s_rh)
{
	v_out[0] = (v_lh[0] >> s_rh);
	v_out[1] = (v_lh[1] >> s_rh);
	v_out[2] = (v_lh[2] >> s_rh);
	return v_out;
}

ijk_inl boolv ijkVecEqual3ivs(bool3 bv_out, int3 const v_lh, i32 const s_rh)
{
	bv_out[0] = (v_lh[0] == s_rh);
	bv_out[1] = (v_lh[1] == s_rh);
	bv_out[2] = (v_lh[2] == s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecInequal3ivs(bool3 bv_out, int3 const v_lh, i32 const s_rh)
{
	bv_out[0] = (v_lh[0] != s_rh);
	bv_out[1] = (v_lh[1] != s_rh);
	bv_out[2] = (v_lh[2] != s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual3ivs(bool3 bv_out, int3 const v_lh, i32 const s_rh)
{
	bv_out[0] = (v_lh[0] <= s_rh);
	bv_out[1] = (v_lh[1] <= s_rh);
	bv_out[2] = (v_lh[2] <= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual3ivs(bool3 bv_out, int3 const v_lh, i32 const s_rh)
{
	bv_out[0] = (v_lh[0] >= s_rh);
	bv_out[1] = (v_lh[1] >= s_rh);
	bv_out[2] = (v_lh[2] >= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLess3ivs(bool3 bv_out, int3 const v_lh, i32 const s_rh)
{
	bv_out[0] = (v_lh[0] < s_rh);
	bv_out[1] = (v_lh[1] < s_rh);
	bv_out[2] = (v_lh[2] < s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreater3ivs(bool3 bv_out, int3 const v_lh, i32 const s_rh)
{
	bv_out[0] = (v_lh[0] > s_rh);
	bv_out[1] = (v_lh[1] > s_rh);
	bv_out[2] = (v_lh[2] > s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecAnd3ivs(bool3 bv_out, int3 const v_lh, i32 const s_rh)
{
	bv_out[0] = (v_lh[0] && s_rh);
	bv_out[1] = (v_lh[1] && s_rh);
	bv_out[2] = (v_lh[2] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNand3ivs(bool3 bv_out, int3 const v_lh, i32 const s_rh)
{
	bv_out[0] = !(v_lh[0] && s_rh);
	bv_out[1] = !(v_lh[1] && s_rh);
	bv_out[2] = !(v_lh[2] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecOr3ivs(bool3 bv_out, int3 const v_lh, i32 const s_rh)
{
	bv_out[0] = (v_lh[0] || s_rh);
	bv_out[1] = (v_lh[1] || s_rh);
	bv_out[2] = (v_lh[2] || s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNor3ivs(bool3 bv_out, int3 const v_lh, i32 const s_rh)
{
	bv_out[0] = !(v_lh[0] || s_rh);
	bv_out[1] = !(v_lh[1] || s_rh);
	bv_out[2] = !(v_lh[2] || s_rh);
	return bv_out;
}

ijk_inl intv ijkVecCopy3ixv(int3 v_out, i32 const x, int2 const v_yz)
{
	v_out[0] = x;
	v_out[1] = v_yz[0];
	v_out[2] = v_yz[1];
	return v_out;
}

ijk_inl intv ijkVecAdd3isv(int3 v_out, i32 const s_lh, int3 const v_rh)
{
	v_out[0] = s_lh + v_rh[0];
	v_out[1] = s_lh + v_rh[1];
	v_out[2] = s_lh + v_rh[2];
	return v_out;
}

ijk_inl intv ijkVecSub3isv(int3 v_out, i32 const s_lh, int3 const v_rh)
{
	v_out[0] = s_lh - v_rh[0];
	v_out[1] = s_lh - v_rh[1];
	v_out[2] = s_lh - v_rh[2];
	return v_out;
}

ijk_inl intv ijkVecMul3isv(int3 v_out, i32 const s_lh, int3 const v_rh)
{
	v_out[0] = s_lh * v_rh[0];
	v_out[1] = s_lh * v_rh[1];
	v_out[2] = s_lh * v_rh[2];
	return v_out;
}

ijk_inl intv ijkVecDiv3isv(int3 v_out, i32 const s_lh, int3 const v_rh)
{
	v_out[0] = s_lh / v_rh[0];
	v_out[1] = s_lh / v_rh[1];
	v_out[2] = s_lh / v_rh[2];
	return v_out;
}

ijk_inl intv ijkVecDivSafe3isv(int3 v_out, i32 const s_lh, int3 const v_rh)
{
	v_out[0] = ijk_divide_safe_int(s_lh, v_rh[0]);
	v_out[1] = ijk_divide_safe_int(s_lh, v_rh[1]);
	v_out[2] = ijk_divide_safe_int(s_lh, v_rh[2]);
	return v_out;
}

ijk_inl intv ijkVecMod3isv(int3 v_out, i32 const s_lh, int3 const v_rh)
{
	v_out[0] = s_lh % v_rh[0];
	v_out[1] = s_lh % v_rh[1];
	v_out[2] = s_lh % v_rh[2];
	return v_out;
}

ijk_inl intv ijkVecModSafe3isv(int3 v_out, i32 const s_lh, int3 const v_rh)
{
	v_out[0] = ijk_modulo_safe_int(s_lh, v_rh[0]);
	v_out[1] = ijk_modulo_safe_int(s_lh, v_rh[1]);
	v_out[2] = ijk_modulo_safe_int(s_lh, v_rh[2]);
	return v_out;
}

ijk_inl intv ijkVecBitAnd3isv(int3 v_out, i32 const s_lh, int3 const v_rh)
{
	v_out[0] = (s_lh & v_rh[0]);
	v_out[1] = (s_lh & v_rh[1]);
	v_out[2] = (s_lh & v_rh[2]);
	return v_out;
}

ijk_inl intv ijkVecBitNand3isv(int3 v_out, i32 const s_lh, int3 const v_rh)
{
	v_out[0] = ~(s_lh & v_rh[0]);
	v_out[1] = ~(s_lh & v_rh[1]);
	v_out[2] = ~(s_lh & v_rh[2]);
	return v_out;
}

ijk_inl intv ijkVecBitOr3isv(int3 v_out, i32 const s_lh, int3 const v_rh)
{
	v_out[0] = (s_lh | v_rh[0]);
	v_out[1] = (s_lh | v_rh[1]);
	v_out[2] = (s_lh | v_rh[2]);
	return v_out;
}

ijk_inl intv ijkVecBitNor3isv(int3 v_out, i32 const s_lh, int3 const v_rh)
{
	v_out[0] = ~(s_lh | v_rh[0]);
	v_out[1] = ~(s_lh | v_rh[1]);
	v_out[2] = ~(s_lh | v_rh[2]);
	return v_out;
}

ijk_inl intv ijkVecBitXor3isv(int3 v_out, i32 const s_lh, int3 const v_rh)
{
	v_out[0] = (s_lh ^ v_rh[0]);
	v_out[1] = (s_lh ^ v_rh[1]);
	v_out[2] = (s_lh ^ v_rh[2]);
	return v_out;
}

ijk_inl intv ijkVecBitXnor3isv(int3 v_out, i32 const s_lh, int3 const v_rh)
{
	v_out[0] = ~(s_lh ^ v_rh[0]);
	v_out[1] = ~(s_lh ^ v_rh[1]);
	v_out[2] = ~(s_lh ^ v_rh[2]);
	return v_out;
}

ijk_inl intv ijkVecBitShiftLeft3isv(int3 v_out, i32 const s_lh, int3 const v_rh)
{
	v_out[0] = (s_lh << v_rh[0]);
	v_out[1] = (s_lh << v_rh[1]);
	v_out[2] = (s_lh << v_rh[2]);
	return v_out;
}

ijk_inl intv ijkVecBitShiftRight3isv(int3 v_out, i32 const s_lh, int3 const v_rh)
{
	v_out[0] = (s_lh >> v_rh[0]);
	v_out[1] = (s_lh >> v_rh[1]);
	v_out[2] = (s_lh >> v_rh[2]);
	return v_out;
}

ijk_inl boolv ijkVecEqual3isv(bool3 bv_out, i32 const s_lh, int3 const v_rh)
{
	bv_out[0] = (s_lh == v_rh[0]);
	bv_out[1] = (s_lh == v_rh[1]);
	bv_out[2] = (s_lh == v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal3isv(bool3 bv_out, i32 const s_lh, int3 const v_rh)
{
	bv_out[0] = (s_lh != v_rh[0]);
	bv_out[1] = (s_lh != v_rh[1]);
	bv_out[2] = (s_lh != v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual3isv(bool3 bv_out, i32 const s_lh, int3 const v_rh)
{
	bv_out[0] = (s_lh <= v_rh[0]);
	bv_out[1] = (s_lh <= v_rh[1]);
	bv_out[2] = (s_lh <= v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual3isv(bool3 bv_out, i32 const s_lh, int3 const v_rh)
{
	bv_out[0] = (s_lh >= v_rh[0]);
	bv_out[1] = (s_lh >= v_rh[1]);
	bv_out[2] = (s_lh >= v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecLess3isv(bool3 bv_out, i32 const s_lh, int3 const v_rh)
{
	bv_out[0] = (s_lh < v_rh[0]);
	bv_out[1] = (s_lh < v_rh[1]);
	bv_out[2] = (s_lh < v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater3isv(bool3 bv_out, i32 const s_lh, int3 const v_rh)
{
	bv_out[0] = (s_lh > v_rh[0]);
	bv_out[1] = (s_lh > v_rh[1]);
	bv_out[2] = (s_lh > v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd3isv(bool3 bv_out, i32 const s_lh, int3 const v_rh)
{
	bv_out[0] = (s_lh && v_rh[0]);
	bv_out[1] = (s_lh && v_rh[1]);
	bv_out[2] = (s_lh && v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecNand3isv(bool3 bv_out, i32 const s_lh, int3 const v_rh)
{
	bv_out[0] = !(s_lh && v_rh[0]);
	bv_out[1] = !(s_lh && v_rh[1]);
	bv_out[2] = !(s_lh && v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecOr3isv(bool3 bv_out, i32 const s_lh, int3 const v_rh)
{
	bv_out[0] = (s_lh || v_rh[0]);
	bv_out[1] = (s_lh || v_rh[1]);
	bv_out[2] = (s_lh || v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecNor3isv(bool3 bv_out, i32 const s_lh, int3 const v_rh)
{
	bv_out[0] = !(s_lh || v_rh[0]);
	bv_out[1] = !(s_lh || v_rh[1]);
	bv_out[2] = !(s_lh || v_rh[2]);
	return bv_out;
}

ijk_inl i32 ijkVecDot3iv(int3 const v_lh, int3 const v_rh)
{
	return (v_lh[0] * v_rh[0] + v_lh[1] * v_rh[1] + v_lh[2] * v_rh[2]);
}

ijk_inl intv ijkVecCross3iv(int3 v_out, int3 const v_lh, int3 const v_rh)
{
	v_out[0] = (v_lh[1] * v_rh[2] - v_lh[2] * v_rh[1]);
	v_out[1] = (v_lh[2] * v_rh[0] - v_lh[0] * v_rh[2]);
	v_out[2] = (v_lh[0] * v_rh[1] - v_lh[1] * v_rh[0]);
	return v_out;
}


//-----------------------------------------------------------------------------

ijk_inl intv ijkVecInit4iv(int4 v_out)
{
	v_out[0] = v_out[1] = v_out[2] = v_out[3] = 0;
	return v_out;
}

ijk_inl intv ijkVecInitElems4iv(int4 v_out, i32 const x, i32 const y, i32 const z, i32 const w)
{
	v_out[0] = x;
	v_out[1] = y;
	v_out[2] = z;
	v_out[3] = w;
	return v_out;
}

ijk_inl intv ijkVecCopy4ixvw(int4 v_out, i32 const x, int2 const v_yz, i32 const w)
{
	v_out[0] = x;
	v_out[1] = v_yz[0];
	v_out[2] = v_yz[1];
	v_out[3] = w;
	return v_out;
}

ijk_inl intv ijkVecCopy4iv2(int4 v_out, int2 const v_xy, int2 const v_zw)
{
	v_out[0] = v_xy[0];
	v_out[1] = v_xy[1];
	v_out[2] = v_zw[0];
	v_out[3] = v_zw[1];
	return v_out;
}

ijk_inl intv ijkVecCopy4iv(int4 v_out, int4 const v_in)
{
	v_out[0] = +v_in[0];
	v_out[1] = +v_in[1];
	v_out[2] = +v_in[2];
	v_out[3] = +v_in[3];
	return v_out;
}

ijk_inl intv ijkVecNegate4iv(int4 v_out, int4 const v_in)
{
	v_out[0] = -v_in[0];
	v_out[1] = -v_in[1];
	v_out[2] = -v_in[2];
	v_out[3] = -v_in[3];
	return v_out;
}

ijk_inl intv ijkVecBitNot4iv(int4 v_out, int4 const v_in)
{
	v_out[0] = ~v_in[0];
	v_out[1] = ~v_in[1];
	v_out[2] = ~v_in[2];
	v_out[3] = ~v_in[3];
	return v_out;
}

ijk_inl boolv ijkVecNot4iv(bool4 bv_out, int4 const v_in)
{
	bv_out[0] = !v_in[0];
	bv_out[1] = !v_in[1];
	bv_out[2] = !v_in[2];
	bv_out[3] = !v_in[3];
	return bv_out;
}

ijk_inl intv ijkVecAdd4iv(int4 v_out, int4 const v_lh, int4 const v_rh)
{
	v_out[0] = v_lh[0] + v_rh[0];
	v_out[1] = v_lh[1] + v_rh[1];
	v_out[2] = v_lh[2] + v_rh[2];
	v_out[3] = v_lh[3] + v_rh[3];
	return v_out;
}

ijk_inl intv ijkVecSub4iv(int4 v_out, int4 const v_lh, int4 const v_rh)
{
	v_out[0] = v_lh[0] - v_rh[0];
	v_out[1] = v_lh[1] - v_rh[1];
	v_out[2] = v_lh[2] - v_rh[2];
	v_out[3] = v_lh[3] - v_rh[3];
	return v_out;
}

ijk_inl intv ijkVecMul4iv(int4 v_out, int4 const v_lh, int4 const v_rh)
{
	v_out[0] = v_lh[0] * v_rh[0];
	v_out[1] = v_lh[1] * v_rh[1];
	v_out[2] = v_lh[2] * v_rh[2];
	v_out[3] = v_lh[3] * v_rh[3];
	return v_out;
}

ijk_inl intv ijkVecDiv4iv(int4 v_out, int4 const v_lh, int4 const v_rh)
{
	v_out[0] = v_lh[0] / v_rh[0];
	v_out[1] = v_lh[1] / v_rh[1];
	v_out[2] = v_lh[2] / v_rh[2];
	v_out[3] = v_lh[3] / v_rh[3];
	return v_out;
}

ijk_inl intv ijkVecDivSafe4iv(int4 v_out, int4 const v_lh, int4 const v_rh)
{
	v_out[0] = ijk_divide_safe_int(v_lh[0], v_rh[0]);
	v_out[1] = ijk_divide_safe_int(v_lh[1], v_rh[1]);
	v_out[2] = ijk_divide_safe_int(v_lh[2], v_rh[2]);
	v_out[3] = ijk_divide_safe_int(v_lh[3], v_rh[3]);
	return v_out;
}

ijk_inl intv ijkVecMod4iv(int4 v_out, int4 const v_lh, int4 const v_rh)
{
	v_out[0] = v_lh[0] % v_rh[0];
	v_out[1] = v_lh[1] % v_rh[1];
	v_out[2] = v_lh[2] % v_rh[2];
	v_out[3] = v_lh[3] % v_rh[3];
	return v_out;
}

ijk_inl intv ijkVecModSafe4iv(int4 v_out, int4 const v_lh, int4 const v_rh)
{
	v_out[0] = ijk_modulo_safe_int(v_lh[0], v_rh[0]);
	v_out[1] = ijk_modulo_safe_int(v_lh[1], v_rh[1]);
	v_out[2] = ijk_modulo_safe_int(v_lh[2], v_rh[2]);
	v_out[3] = ijk_modulo_safe_int(v_lh[3], v_rh[3]);
	return v_out;
}

ijk_inl intv ijkVecBitAnd4iv(int4 v_out, int4 const v_lh, int4 const v_rh)
{
	v_out[0] = (v_lh[0] & v_rh[0]);
	v_out[1] = (v_lh[1] & v_rh[1]);
	v_out[2] = (v_lh[2] & v_rh[2]);
	v_out[3] = (v_lh[3] & v_rh[3]);
	return v_out;
}

ijk_inl intv ijkVecBitNand4iv(int4 v_out, int4 const v_lh, int4 const v_rh)
{
	v_out[0] = ~(v_lh[0] & v_rh[0]);
	v_out[1] = ~(v_lh[1] & v_rh[1]);
	v_out[2] = ~(v_lh[2] & v_rh[2]);
	v_out[3] = ~(v_lh[3] & v_rh[3]);
	return v_out;
}

ijk_inl intv ijkVecBitOr4iv(int4 v_out, int4 const v_lh, int4 const v_rh)
{
	v_out[0] = (v_lh[0] | v_rh[0]);
	v_out[1] = (v_lh[1] | v_rh[1]);
	v_out[2] = (v_lh[2] | v_rh[2]);
	v_out[3] = (v_lh[3] | v_rh[3]);
	return v_out;
}

ijk_inl intv ijkVecBitNor4iv(int4 v_out, int4 const v_lh, int4 const v_rh)
{
	v_out[0] = ~(v_lh[0] | v_rh[0]);
	v_out[1] = ~(v_lh[1] | v_rh[1]);
	v_out[2] = ~(v_lh[2] | v_rh[2]);
	v_out[3] = ~(v_lh[3] | v_rh[3]);
	return v_out;
}

ijk_inl intv ijkVecBitXor4iv(int4 v_out, int4 const v_lh, int4 const v_rh)
{
	v_out[0] = (v_lh[0] ^ v_rh[0]);
	v_out[1] = (v_lh[1] ^ v_rh[1]);
	v_out[2] = (v_lh[2] ^ v_rh[2]);
	v_out[3] = (v_lh[3] ^ v_rh[3]);
	return v_out;
}

ijk_inl intv ijkVecBitXnor4iv(int4 v_out, int4 const v_lh, int4 const v_rh)
{
	v_out[0] = ~(v_lh[0] ^ v_rh[0]);
	v_out[1] = ~(v_lh[1] ^ v_rh[1]);
	v_out[2] = ~(v_lh[2] ^ v_rh[2]);
	v_out[3] = ~(v_lh[3] ^ v_rh[3]);
	return v_out;
}

ijk_inl intv ijkVecBitShiftLeft4iv(int4 v_out, int4 const v_lh, int4 const v_rh)
{
	v_out[0] = (v_lh[0] << v_rh[0]);
	v_out[1] = (v_lh[1] << v_rh[1]);
	v_out[2] = (v_lh[2] << v_rh[2]);
	v_out[3] = (v_lh[3] << v_rh[3]);
	return v_out;
}

ijk_inl intv ijkVecBitShiftRight4iv(int4 v_out, int4 const v_lh, int4 const v_rh)
{
	v_out[0] = (v_lh[0] >> v_rh[0]);
	v_out[1] = (v_lh[1] >> v_rh[1]);
	v_out[2] = (v_lh[2] >> v_rh[2]);
	v_out[3] = (v_lh[3] >> v_rh[3]);
	return v_out;
}

ijk_inl boolv ijkVecEqual4iv(bool4 bv_out, int4 const v_lh, int4 const v_rh)
{
	bv_out[0] = (v_lh[0] == v_rh[0]);
	bv_out[1] = (v_lh[1] == v_rh[1]);
	bv_out[2] = (v_lh[2] == v_rh[2]);
	bv_out[3] = (v_lh[3] == v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal4iv(bool4 bv_out, int4 const v_lh, int4 const v_rh)
{
	bv_out[0] = (v_lh[0] != v_rh[0]);
	bv_out[1] = (v_lh[1] != v_rh[1]);
	bv_out[2] = (v_lh[2] != v_rh[2]);
	bv_out[3] = (v_lh[3] != v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual4iv(bool4 bv_out, int4 const v_lh, int4 const v_rh)
{
	bv_out[0] = (v_lh[0] <= v_rh[0]);
	bv_out[1] = (v_lh[1] <= v_rh[1]);
	bv_out[2] = (v_lh[2] <= v_rh[2]);
	bv_out[3] = (v_lh[3] <= v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual4iv(bool4 bv_out, int4 const v_lh, int4 const v_rh)
{
	bv_out[0] = (v_lh[0] >= v_rh[0]);
	bv_out[1] = (v_lh[1] >= v_rh[1]);
	bv_out[2] = (v_lh[2] >= v_rh[2]);
	bv_out[3] = (v_lh[3] >= v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecLess4iv(bool4 bv_out, int4 const v_lh, int4 const v_rh)
{
	bv_out[0] = (v_lh[0] < v_rh[0]);
	bv_out[1] = (v_lh[1] < v_rh[1]);
	bv_out[2] = (v_lh[2] < v_rh[2]);
	bv_out[3] = (v_lh[3] < v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater4iv(bool4 bv_out, int4 const v_lh, int4 const v_rh)
{
	bv_out[0] = (v_lh[0] > v_rh[0]);
	bv_out[1] = (v_lh[1] > v_rh[1]);
	bv_out[2] = (v_lh[2] > v_rh[2]);
	bv_out[3] = (v_lh[3] > v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd4iv(bool4 bv_out, int4 const v_lh, int4 const v_rh)
{
	bv_out[0] = (v_lh[0] && v_rh[0]);
	bv_out[1] = (v_lh[1] && v_rh[1]);
	bv_out[2] = (v_lh[2] && v_rh[2]);
	bv_out[3] = (v_lh[3] && v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecNand4iv(bool4 bv_out, int4 const v_lh, int4 const v_rh)
{
	bv_out[0] = !(v_lh[0] && v_rh[0]);
	bv_out[1] = !(v_lh[1] && v_rh[1]);
	bv_out[2] = !(v_lh[2] && v_rh[2]);
	bv_out[3] = !(v_lh[3] && v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecOr4iv(bool4 bv_out, int4 const v_lh, int4 const v_rh)
{
	bv_out[0] = (v_lh[0] || v_rh[0]);
	bv_out[1] = (v_lh[1] || v_rh[1]);
	bv_out[2] = (v_lh[2] || v_rh[2]);
	bv_out[3] = (v_lh[3] || v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecNor4iv(bool4 bv_out, int4 const v_lh, int4 const v_rh)
{
	bv_out[0] = !(v_lh[0] || v_rh[0]);
	bv_out[1] = !(v_lh[1] || v_rh[1]);
	bv_out[2] = !(v_lh[2] || v_rh[2]);
	bv_out[3] = !(v_lh[3] || v_rh[3]);
	return bv_out;
}

ijk_inl intv ijkVecCopy4ivzw(int4 v_out, int2 const v_xy, i32 const z, i32 const w)
{
	v_out[0] = v_xy[0];
	v_out[1] = v_xy[1];
	v_out[2] = z;
	v_out[3] = w;
	return v_out;
}

ijk_inl intv ijkVecCopy4ivw(int4 v_out, int3 const v_xyz, i32 const w)
{
	v_out[0] = v_xyz[0];
	v_out[1] = v_xyz[1];
	v_out[2] = v_xyz[2];
	v_out[3] = w;
	return v_out;
}

ijk_inl intv ijkVecCopy4ivs(int4 v_out, i32 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = v_out[3] = +s_in;
	return v_out;
}

ijk_inl intv ijkVecNegate4ivs(int4 v_out, i32 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = v_out[3] = -s_in;
	return v_out;
}

ijk_inl intv ijkVecBitNot4ivs(int4 v_out, i32 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = v_out[3] = ~s_in;
	return v_out;
}

ijk_inl boolv ijkVecNot4ivs(bool4 bv_out, i32 const s_in)
{
	bv_out[0] = bv_out[1] = bv_out[2] = bv_out[3] = !s_in;
	return bv_out;
}

ijk_inl intv ijkVecAdd4ivs(int4 v_out, int4 const v_lh, i32 const s_rh)
{
	v_out[0] = v_lh[0] + s_rh;
	v_out[1] = v_lh[1] + s_rh;
	v_out[2] = v_lh[2] + s_rh;
	v_out[3] = v_lh[3] + s_rh;
	return v_out;
}

ijk_inl intv ijkVecSub4ivs(int4 v_out, int4 const v_lh, i32 const s_rh)
{
	v_out[0] = v_lh[0] - s_rh;
	v_out[1] = v_lh[1] - s_rh;
	v_out[2] = v_lh[2] - s_rh;
	v_out[3] = v_lh[3] - s_rh;
	return v_out;
}

ijk_inl intv ijkVecMul4ivs(int4 v_out, int4 const v_lh, i32 const s_rh)
{
	v_out[0] = v_lh[0] * s_rh;
	v_out[1] = v_lh[1] * s_rh;
	v_out[2] = v_lh[2] * s_rh;
	v_out[3] = v_lh[3] * s_rh;
	return v_out;
}

ijk_inl intv ijkVecDiv4ivs(int4 v_out, int4 const v_lh, i32 const s_rh)
{
	v_out[0] = v_lh[0] / s_rh;
	v_out[1] = v_lh[1] / s_rh;
	v_out[2] = v_lh[2] / s_rh;
	v_out[3] = v_lh[3] / s_rh;
	return v_out;
}

ijk_inl intv ijkVecDivSafe4ivs(int4 v_out, int4 const v_lh, i32 const s_rh)
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

ijk_inl intv ijkVecMod4ivs(int4 v_out, int4 const v_lh, i32 const s_rh)
{
	v_out[0] = v_lh[0] % s_rh;
	v_out[1] = v_lh[1] % s_rh;
	v_out[2] = v_lh[2] % s_rh;
	v_out[3] = v_lh[3] % s_rh;
	return v_out;
}

ijk_inl intv ijkVecModSafe4ivs(int4 v_out, int4 const v_lh, i32 const s_rh)
{
	if (s_rh)
	{
		v_out[0] = v_lh[0] % s_rh;
		v_out[1] = v_lh[1] % s_rh;
		v_out[2] = v_lh[2] % s_rh;
		v_out[3] = v_lh[3] % s_rh;
	}
	else
		v_out[0] = v_out[1] = v_out[2] = v_out[3] = 0;
	return v_out;
}

ijk_inl intv ijkVecBitAnd4ivs(int4 v_out, int4 const v_lh, i32 const s_rh)
{
	v_out[0] = (v_lh[0] & s_rh);
	v_out[1] = (v_lh[1] & s_rh);
	v_out[2] = (v_lh[2] & s_rh);
	v_out[3] = (v_lh[3] & s_rh);
	return v_out;
}

ijk_inl intv ijkVecBitNand4ivs(int4 v_out, int4 const v_lh, i32 const s_rh)
{
	v_out[0] = ~(v_lh[0] & s_rh);
	v_out[1] = ~(v_lh[1] & s_rh);
	v_out[2] = ~(v_lh[2] & s_rh);
	v_out[3] = ~(v_lh[3] & s_rh);
	return v_out;
}

ijk_inl intv ijkVecBitOr4ivs(int4 v_out, int4 const v_lh, i32 const s_rh)
{
	v_out[0] = (v_lh[0] | s_rh);
	v_out[1] = (v_lh[1] | s_rh);
	v_out[2] = (v_lh[2] | s_rh);
	v_out[3] = (v_lh[3] | s_rh);
	return v_out;
}

ijk_inl intv ijkVecBitNor4ivs(int4 v_out, int4 const v_lh, i32 const s_rh)
{
	v_out[0] = ~(v_lh[0] | s_rh);
	v_out[1] = ~(v_lh[1] | s_rh);
	v_out[2] = ~(v_lh[2] | s_rh);
	v_out[3] = ~(v_lh[3] | s_rh);
	return v_out;
}

ijk_inl intv ijkVecBitXor4ivs(int4 v_out, int4 const v_lh, i32 const s_rh)
{
	v_out[0] = (v_lh[0] ^ s_rh);
	v_out[1] = (v_lh[1] ^ s_rh);
	v_out[2] = (v_lh[2] ^ s_rh);
	v_out[3] = (v_lh[3] ^ s_rh);
	return v_out;
}

ijk_inl intv ijkVecBitXnor4ivs(int4 v_out, int4 const v_lh, i32 const s_rh)
{
	v_out[0] = ~(v_lh[0] ^ s_rh);
	v_out[1] = ~(v_lh[1] ^ s_rh);
	v_out[2] = ~(v_lh[2] ^ s_rh);
	v_out[3] = ~(v_lh[3] ^ s_rh);
	return v_out;
}

ijk_inl intv ijkVecBitShiftLeft4ivs(int4 v_out, int4 const v_lh, i32 const s_rh)
{
	v_out[0] = (v_lh[0] << s_rh);
	v_out[1] = (v_lh[1] << s_rh);
	v_out[2] = (v_lh[2] << s_rh);
	v_out[3] = (v_lh[3] << s_rh);
	return v_out;
}

ijk_inl intv ijkVecBitShiftRight4ivs(int4 v_out, int4 const v_lh, i32 const s_rh)
{
	v_out[0] = (v_lh[0] >> s_rh);
	v_out[1] = (v_lh[1] >> s_rh);
	v_out[2] = (v_lh[2] >> s_rh);
	v_out[3] = (v_lh[3] >> s_rh);
	return v_out;
}

ijk_inl boolv ijkVecEqual4ivs(bool4 bv_out, int4 const v_lh, i32 const s_rh)
{
	bv_out[0] = (v_lh[0] == s_rh);
	bv_out[1] = (v_lh[1] == s_rh);
	bv_out[2] = (v_lh[2] == s_rh);
	bv_out[3] = (v_lh[3] == s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecInequal4ivs(bool4 bv_out, int4 const v_lh, i32 const s_rh)
{
	bv_out[0] = (v_lh[0] != s_rh);
	bv_out[1] = (v_lh[1] != s_rh);
	bv_out[2] = (v_lh[2] != s_rh);
	bv_out[3] = (v_lh[3] != s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual4ivs(bool4 bv_out, int4 const v_lh, i32 const s_rh)
{
	bv_out[0] = (v_lh[0] <= s_rh);
	bv_out[1] = (v_lh[1] <= s_rh);
	bv_out[2] = (v_lh[2] <= s_rh);
	bv_out[3] = (v_lh[3] <= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual4ivs(bool4 bv_out, int4 const v_lh, i32 const s_rh)
{
	bv_out[0] = (v_lh[0] >= s_rh);
	bv_out[1] = (v_lh[1] >= s_rh);
	bv_out[2] = (v_lh[2] >= s_rh);
	bv_out[3] = (v_lh[3] >= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLess4ivs(bool4 bv_out, int4 const v_lh, i32 const s_rh)
{
	bv_out[0] = (v_lh[0] < s_rh);
	bv_out[1] = (v_lh[1] < s_rh);
	bv_out[2] = (v_lh[2] < s_rh);
	bv_out[3] = (v_lh[3] < s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreater4ivs(bool4 bv_out, int4 const v_lh, i32 const s_rh)
{
	bv_out[0] = (v_lh[0] > s_rh);
	bv_out[1] = (v_lh[1] > s_rh);
	bv_out[2] = (v_lh[2] > s_rh);
	bv_out[3] = (v_lh[3] > s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecAnd4ivs(bool4 bv_out, int4 const v_lh, i32 const s_rh)
{
	bv_out[0] = (v_lh[0] && s_rh);
	bv_out[1] = (v_lh[1] && s_rh);
	bv_out[2] = (v_lh[2] && s_rh);
	bv_out[3] = (v_lh[3] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNand4ivs(bool4 bv_out, int4 const v_lh, i32 const s_rh)
{
	bv_out[0] = !(v_lh[0] && s_rh);
	bv_out[1] = !(v_lh[1] && s_rh);
	bv_out[2] = !(v_lh[2] && s_rh);
	bv_out[3] = !(v_lh[3] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecOr4ivs(bool4 bv_out, int4 const v_lh, i32 const s_rh)
{
	bv_out[0] = (v_lh[0] || s_rh);
	bv_out[1] = (v_lh[1] || s_rh);
	bv_out[2] = (v_lh[2] || s_rh);
	bv_out[3] = (v_lh[3] || s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNor4ivs(bool4 bv_out, int4 const v_lh, i32 const s_rh)
{
	bv_out[0] = !(v_lh[0] || s_rh);
	bv_out[1] = !(v_lh[1] || s_rh);
	bv_out[2] = !(v_lh[2] || s_rh);
	bv_out[3] = !(v_lh[3] || s_rh);
	return bv_out;
}

ijk_inl intv ijkVecCopy4ixyv(int4 v_out, i32 const x, i32 const y, int2 const v_zw)
{
	v_out[0] = x;
	v_out[1] = y;
	v_out[2] = v_zw[0];
	v_out[3] = v_zw[1];
	return v_out;
}

ijk_inl intv ijkVecCopy4ixv(int4 v_out, i32 const x, int3 const v_yzw)
{
	v_out[0] = x;
	v_out[1] = v_yzw[0];
	v_out[2] = v_yzw[1];
	v_out[3] = v_yzw[2];
	return v_out;
}

ijk_inl intv ijkVecAdd4isv(int4 v_out, i32 const s_lh, int4 const v_rh)
{
	v_out[0] = s_lh + v_rh[0];
	v_out[1] = s_lh + v_rh[1];
	v_out[2] = s_lh + v_rh[2];
	v_out[3] = s_lh + v_rh[3];
	return v_out;
}

ijk_inl intv ijkVecSub4isv(int4 v_out, i32 const s_lh, int4 const v_rh)
{
	v_out[0] = s_lh - v_rh[0];
	v_out[1] = s_lh - v_rh[1];
	v_out[2] = s_lh - v_rh[2];
	v_out[3] = s_lh - v_rh[3];
	return v_out;
}

ijk_inl intv ijkVecMul4isv(int4 v_out, i32 const s_lh, int4 const v_rh)
{
	v_out[0] = s_lh * v_rh[0];
	v_out[1] = s_lh * v_rh[1];
	v_out[2] = s_lh * v_rh[2];
	v_out[3] = s_lh * v_rh[3];
	return v_out;
}

ijk_inl intv ijkVecDiv4isv(int4 v_out, i32 const s_lh, int4 const v_rh)
{
	v_out[0] = s_lh / v_rh[0];
	v_out[1] = s_lh / v_rh[1];
	v_out[2] = s_lh / v_rh[2];
	v_out[3] = s_lh / v_rh[3];
	return v_out;
}

ijk_inl intv ijkVecDivSafe4isv(int4 v_out, i32 const s_lh, int4 const v_rh)
{
	v_out[0] = ijk_divide_safe_int(s_lh, v_rh[0]);
	v_out[1] = ijk_divide_safe_int(s_lh, v_rh[1]);
	v_out[2] = ijk_divide_safe_int(s_lh, v_rh[2]);
	v_out[3] = ijk_divide_safe_int(s_lh, v_rh[3]);
	return v_out;
}

ijk_inl intv ijkVecMod4isv(int4 v_out, i32 const s_lh, int4 const v_rh)
{
	v_out[0] = s_lh % v_rh[0];
	v_out[1] = s_lh % v_rh[1];
	v_out[2] = s_lh % v_rh[2];
	v_out[3] = s_lh % v_rh[3];
	return v_out;
}

ijk_inl intv ijkVecModSafe4isv(int4 v_out, i32 const s_lh, int4 const v_rh)
{
	v_out[0] = ijk_modulo_safe_int(s_lh, v_rh[0]);
	v_out[1] = ijk_modulo_safe_int(s_lh, v_rh[1]);
	v_out[2] = ijk_modulo_safe_int(s_lh, v_rh[2]);
	v_out[3] = ijk_modulo_safe_int(s_lh, v_rh[3]);
	return v_out;
}

ijk_inl intv ijkVecBitAnd4isv(int4 v_out, i32 const s_lh, int4 const v_rh)
{
	v_out[0] = (s_lh & v_rh[0]);
	v_out[1] = (s_lh & v_rh[1]);
	v_out[2] = (s_lh & v_rh[2]);
	v_out[3] = (s_lh & v_rh[3]);
	return v_out;
}

ijk_inl intv ijkVecBitNand4isv(int4 v_out, i32 const s_lh, int4 const v_rh)
{
	v_out[0] = ~(s_lh & v_rh[0]);
	v_out[1] = ~(s_lh & v_rh[1]);
	v_out[2] = ~(s_lh & v_rh[2]);
	v_out[3] = ~(s_lh & v_rh[3]);
	return v_out;
}

ijk_inl intv ijkVecBitOr4isv(int4 v_out, i32 const s_lh, int4 const v_rh)
{
	v_out[0] = (s_lh | v_rh[0]);
	v_out[1] = (s_lh | v_rh[1]);
	v_out[2] = (s_lh | v_rh[2]);
	v_out[3] = (s_lh | v_rh[3]);
	return v_out;
}

ijk_inl intv ijkVecBitNor4isv(int4 v_out, i32 const s_lh, int4 const v_rh)
{
	v_out[0] = ~(s_lh | v_rh[0]);
	v_out[1] = ~(s_lh | v_rh[1]);
	v_out[2] = ~(s_lh | v_rh[2]);
	v_out[3] = ~(s_lh | v_rh[3]);
	return v_out;
}

ijk_inl intv ijkVecBitXor4isv(int4 v_out, i32 const s_lh, int4 const v_rh)
{
	v_out[0] = (s_lh ^ v_rh[0]);
	v_out[1] = (s_lh ^ v_rh[1]);
	v_out[2] = (s_lh ^ v_rh[2]);
	v_out[3] = (s_lh ^ v_rh[3]);
	return v_out;
}

ijk_inl intv ijkVecBitXnor4isv(int4 v_out, i32 const s_lh, int4 const v_rh)
{
	v_out[0] = ~(s_lh ^ v_rh[0]);
	v_out[1] = ~(s_lh ^ v_rh[1]);
	v_out[2] = ~(s_lh ^ v_rh[2]);
	v_out[3] = ~(s_lh ^ v_rh[3]);
	return v_out;
}

ijk_inl intv ijkVecBitShiftLeft4isv(int4 v_out, i32 const s_lh, int4 const v_rh)
{
	v_out[0] = (s_lh << v_rh[0]);
	v_out[1] = (s_lh << v_rh[1]);
	v_out[2] = (s_lh << v_rh[2]);
	v_out[3] = (s_lh << v_rh[3]);
	return v_out;
}

ijk_inl intv ijkVecBitShiftRight4isv(int4 v_out, i32 const s_lh, int4 const v_rh)
{
	v_out[0] = (s_lh >> v_rh[0]);
	v_out[1] = (s_lh >> v_rh[1]);
	v_out[2] = (s_lh >> v_rh[2]);
	v_out[3] = (s_lh >> v_rh[3]);
	return v_out;
}

ijk_inl boolv ijkVecEqual4isv(bool4 bv_out, i32 const s_lh, int4 const v_rh)
{
	bv_out[0] = (s_lh == v_rh[0]);
	bv_out[1] = (s_lh == v_rh[1]);
	bv_out[2] = (s_lh == v_rh[2]);
	bv_out[3] = (s_lh == v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal4isv(bool4 bv_out, i32 const s_lh, int4 const v_rh)
{
	bv_out[0] = (s_lh != v_rh[0]);
	bv_out[1] = (s_lh != v_rh[1]);
	bv_out[2] = (s_lh != v_rh[2]);
	bv_out[3] = (s_lh != v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual4isv(bool4 bv_out, i32 const s_lh, int4 const v_rh)
{
	bv_out[0] = (s_lh <= v_rh[0]);
	bv_out[1] = (s_lh <= v_rh[1]);
	bv_out[2] = (s_lh <= v_rh[2]);
	bv_out[3] = (s_lh <= v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual4isv(bool4 bv_out, i32 const s_lh, int4 const v_rh)
{
	bv_out[0] = (s_lh >= v_rh[0]);
	bv_out[1] = (s_lh >= v_rh[1]);
	bv_out[2] = (s_lh >= v_rh[2]);
	bv_out[3] = (s_lh >= v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecLess4isv(bool4 bv_out, i32 const s_lh, int4 const v_rh)
{
	bv_out[0] = (s_lh < v_rh[0]);
	bv_out[1] = (s_lh < v_rh[1]);
	bv_out[2] = (s_lh < v_rh[2]);
	bv_out[3] = (s_lh < v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater4isv(bool4 bv_out, i32 const s_lh, int4 const v_rh)
{
	bv_out[0] = (s_lh > v_rh[0]);
	bv_out[1] = (s_lh > v_rh[1]);
	bv_out[2] = (s_lh > v_rh[2]);
	bv_out[3] = (s_lh > v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd4isv(bool4 bv_out, i32 const s_lh, int4 const v_rh)
{
	bv_out[0] = (s_lh && v_rh[0]);
	bv_out[1] = (s_lh && v_rh[1]);
	bv_out[2] = (s_lh && v_rh[2]);
	bv_out[3] = (s_lh && v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecNand4isv(bool4 bv_out, i32 const s_lh, int4 const v_rh)
{
	bv_out[0] = !(s_lh && v_rh[0]);
	bv_out[1] = !(s_lh && v_rh[1]);
	bv_out[2] = !(s_lh && v_rh[2]);
	bv_out[3] = !(s_lh && v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecOr4isv(bool4 bv_out, i32 const s_lh, int4 const v_rh)
{
	bv_out[0] = (s_lh || v_rh[0]);
	bv_out[1] = (s_lh || v_rh[1]);
	bv_out[2] = (s_lh || v_rh[2]);
	bv_out[3] = (s_lh || v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecNor4isv(bool4 bv_out, i32 const s_lh, int4 const v_rh)
{
	bv_out[0] = !(s_lh || v_rh[0]);
	bv_out[1] = !(s_lh || v_rh[1]);
	bv_out[2] = !(s_lh || v_rh[2]);
	bv_out[3] = !(s_lh || v_rh[3]);
	return bv_out;
}

ijk_inl i32 ijkVecDot4iv(int4 const v_lh, int4 const v_rh)
{
	return (v_lh[0] * v_rh[0] + v_lh[1] * v_rh[1] + v_lh[2] * v_rh[2] + v_lh[3] * v_rh[3]);
}

ijk_inl intv ijkVecCross4iv(int4 v_out, int4 const v_lh, int4 const v_rh)
{
	v_out[3] = 0;
	return ijkVecCross3iv(v_out, v_lh, v_rh);
}


//-----------------------------------------------------------------------------

ijk_inl int ijkVecAbs1i(int const s)
{
	return ijkVecAbs1is(s);
}

ijk_inl int ijkVecSgn1i(int const s)
{
	return ijkVecSgn1is(s);
}

ijk_inl int ijkVecDot1i(int const s_lh, int const s_rh)
{
	return ijkVecDot1is(s_lh, s_rh);
}

ijk_inl int ijkVecLengthSq1i(int const s)
{
	return ijkVecLengthSq1is(s);
}

ijk_inl int ijkVecLength1i(int const s)
{
	return ijkVecLength1is(s);
}

ijk_inl float ijkVecLengthSqInv1i(int const s)
{
	return ijkVecLengthSqInv1is(s);
}

ijk_inl float ijkVecLengthInv1i(int const s)
{
	return ijkVecLengthInv1is(s);
}

ijk_inl int ijkVecNormalize1i(int const s)
{
	return ijkVecNormalize1is(s);
}

ijk_inl int ijkVecNormalizeGetLength1i(int const s, int* const length_out)
{
	return ijkVecNormalizeGetLength1is(s, (i32*)length_out);
}

ijk_inl int ijkVecNormalizeGetLengthInv1i(int const s, float* const lengthInv_out)
{
	return ijkVecNormalizeGetLengthInv1is(s, (f32*)lengthInv_out);
}


//-----------------------------------------------------------------------------

ijk_inl ivec2 ijkVecInit2i()
{
	ivec2 const v_out = { 0, 0 };
	return v_out;
}

ijk_inl ivec2 ijkVecInitElems2i(int const x, int const y)
{
	ivec2 const v_out = { x, y };
	return v_out;
}

ijk_inl ivec2 ijkVecCopy2i(ivec2 const v_in)
{
	ivec2 const v_out = { +v_in.x, +v_in.y };
	return v_out;
}

ijk_inl ivec2 ijkVecNegate2i(ivec2 const v_in)
{
	ivec2 const v_out = { -v_in.x, -v_in.y };
	return v_out;
}

ijk_inl ivec2 ijkVecBitNot2i(ivec2 const v_in)
{
	ivec2 const v_out = { ~v_in.x, ~v_in.y };
	return v_out;
}

ijk_inl bvec2 ijkVecNot2i(ivec2 const v_in)
{
	bvec2 const bv_out = { !v_in.x, !v_in.y };
	return bv_out;
}

ijk_inl ivec2 ijkVecAdd2i(ivec2 const v_lh, ivec2 const v_rh)
{
	ivec2 const v_out = {
		v_lh.x + v_rh.x,
		v_lh.y + v_rh.y,
	};
	return v_out;
}

ijk_inl ivec2 ijkVecSub2i(ivec2 const v_lh, ivec2 const v_rh)
{
	ivec2 const v_out = {
		v_lh.x - v_rh.x,
		v_lh.y - v_rh.y,
	};
	return v_out;
}

ijk_inl ivec2 ijkVecMul2i(ivec2 const v_lh, ivec2 const v_rh)
{
	ivec2 const v_out = {
		v_lh.x * v_rh.x,
		v_lh.y * v_rh.y,
	};
	return v_out;
}

ijk_inl ivec2 ijkVecDiv2i(ivec2 const v_lh, ivec2 const v_rh)
{
	ivec2 const v_out = {
		v_lh.x / v_rh.x,
		v_lh.y / v_rh.y,
	};
	return v_out;
}

ijk_inl ivec2 ijkVecDivSafe2i(ivec2 const v_lh, ivec2 const v_rh)
{
	ivec2 const v_out = {
		ijk_divide_safe_int(v_lh.x, v_rh.x),
		ijk_divide_safe_int(v_lh.y, v_rh.y),
	};
	return v_out;
}

ijk_inl ivec2 ijkVecMod2i(ivec2 const v_lh, ivec2 const v_rh)
{
	ivec2 const v_out = {
		v_lh.x % v_rh.x,
		v_lh.y % v_rh.y,
	};
	return v_out;
}

ijk_inl ivec2 ijkVecModSafe2i(ivec2 const v_lh, ivec2 const v_rh)
{
	ivec2 const v_out = {
		ijk_modulo_safe_int(v_lh.x, v_rh.x),
		ijk_modulo_safe_int(v_lh.y, v_rh.y),
	};
	return v_out;
}

ijk_inl ivec2 ijkVecBitAnd2i(ivec2 const v_lh, ivec2 const v_rh)
{
	ivec2 const v_out = {
		(v_lh.x & v_rh.x),
		(v_lh.y & v_rh.y),
	};
	return v_out;
}

ijk_inl ivec2 ijkVecBitNand2i(ivec2 const v_lh, ivec2 const v_rh)
{
	ivec2 const v_out = {
		~(v_lh.x & v_rh.x),
		~(v_lh.y & v_rh.y),
	};
	return v_out;
}

ijk_inl ivec2 ijkVecBitOr2i(ivec2 const v_lh, ivec2 const v_rh)
{
	ivec2 const v_out = {
		(v_lh.x | v_rh.x),
		(v_lh.y | v_rh.y),
	};
	return v_out;
}

ijk_inl ivec2 ijkVecBitNor2i(ivec2 const v_lh, ivec2 const v_rh)
{
	ivec2 const v_out = {
		~(v_lh.x | v_rh.x),
		~(v_lh.y | v_rh.y),
	};
	return v_out;
}

ijk_inl ivec2 ijkVecBitXor2i(ivec2 const v_lh, ivec2 const v_rh)
{
	ivec2 const v_out = {
		(v_lh.x ^ v_rh.x),
		(v_lh.y ^ v_rh.y),
	};
	return v_out;
}

ijk_inl ivec2 ijkVecBitXnor2i(ivec2 const v_lh, ivec2 const v_rh)
{
	ivec2 const v_out = {
		~(v_lh.x ^ v_rh.x),
		~(v_lh.y ^ v_rh.y),
	};
	return v_out;
}

ijk_inl ivec2 ijkVecBitShiftLeft2i(ivec2 const v_lh, ivec2 const v_rh)
{
	ivec2 const v_out = {
		(v_lh.x << v_rh.x),
		(v_lh.y << v_rh.y),
	};
	return v_out;
}

ijk_inl ivec2 ijkVecBitShiftRight2i(ivec2 const v_lh, ivec2 const v_rh)
{
	ivec2 const v_out = {
		(v_lh.x >> v_rh.x),
		(v_lh.y >> v_rh.y),
	};
	return v_out;
}

ijk_inl bvec2 ijkVecEqual2i(ivec2 const v_lh, ivec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x == v_rh.x),
		(v_lh.y == v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecInequal2i(ivec2 const v_lh, ivec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x != v_rh.x),
		(v_lh.y != v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLessEqual2i(ivec2 const v_lh, ivec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x <= v_rh.x),
		(v_lh.y <= v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreaterEqual2i(ivec2 const v_lh, ivec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x >= v_rh.x),
		(v_lh.y >= v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLess2i(ivec2 const v_lh, ivec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x < v_rh.x),
		(v_lh.y < v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreater2i(ivec2 const v_lh, ivec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x > v_rh.x),
		(v_lh.y > v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecAnd2i(ivec2 const v_lh, ivec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x && v_rh.x),
		(v_lh.y && v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNand2i(ivec2 const v_lh, ivec2 const v_rh)
{
	bvec2 const bv_out = {
		!(v_lh.x && v_rh.x),
		!(v_lh.y && v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecOr2i(ivec2 const v_lh, ivec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x || v_rh.x),
		(v_lh.y || v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNor2i(ivec2 const v_lh, ivec2 const v_rh)
{
	bvec2 const bv_out = {
		!(v_lh.x || v_rh.x),
		!(v_lh.y || v_rh.y),
	};
	return bv_out;
}

ijk_inl ivec2 ijkVecCopy2is(int const s_in)
{
	ivec2 const v_out = { s_in, s_in };
	return v_out;
}

ijk_inl ivec2 ijkVecNegate2is(int const s_in)
{
	int const s = -s_in;
	ivec2 const v_out = { s, s };
	return v_out;
}

ijk_inl ivec2 ijkVecBitNot2is(int const s_in)
{
	int const s = ~s_in;
	ivec2 const v_out = { s, s };
	return v_out;
}

ijk_inl bvec2 ijkVecNot2is(int const s_in)
{
	bool const s = !s_in;
	bvec2 const bv_out = { s, s };
	return bv_out;
}

ijk_inl ivec2 ijkVecAdd2is(ivec2 const v_lh, int const s_rh)
{
	ivec2 const v_out = {
		v_lh.x + s_rh,
		v_lh.y + s_rh,
	};
	return v_out;
}

ijk_inl ivec2 ijkVecSub2is(ivec2 const v_lh, int const s_rh)
{
	ivec2 const v_out = {
		v_lh.x - s_rh,
		v_lh.y - s_rh,
	};
	return v_out;
}

ijk_inl ivec2 ijkVecMul2is(ivec2 const v_lh, int const s_rh)
{
	ivec2 const v_out = {
		v_lh.x * s_rh,
		v_lh.y * s_rh,
	};
	return v_out;
}

ijk_inl ivec2 ijkVecDiv2is(ivec2 const v_lh, int const s_rh)
{
	ivec2 const v_out = {
		v_lh.x / s_rh,
		v_lh.y / s_rh,
	};
	return v_out;
}

ijk_inl ivec2 ijkVecDivSafe2is(ivec2 const v_lh, int const s_rh)
{
	if (s_rh)
	{
		ivec2 const v_out = {
			v_lh.x / s_rh,
			v_lh.y / s_rh,
		};
		return v_out;
	}
	else
	{
		ivec2 const v_out = { 0, 0 };
		return v_out;
	}
}

ijk_inl ivec2 ijkVecMod2is(ivec2 const v_lh, int const s_rh)
{
	ivec2 const v_out = {
		v_lh.x % s_rh,
		v_lh.y % s_rh,
	};
	return v_out;
}

ijk_inl ivec2 ijkVecModSafe2is(ivec2 const v_lh, int const s_rh)
{
	if (s_rh)
	{
		ivec2 const v_out = {
			v_lh.x % s_rh,
			v_lh.y % s_rh,
		};
		return v_out;
	}
	else
	{
		ivec2 const v_out = { 0, 0 };
		return v_out;
	}
}

ijk_inl ivec2 ijkVecBitAnd2is(ivec2 const v_lh, int const s_rh)
{
	ivec2 const v_out = {
		(v_lh.x & s_rh),
		(v_lh.y & s_rh),
	};
	return v_out;
}

ijk_inl ivec2 ijkVecBitNand2is(ivec2 const v_lh, int const s_rh)
{
	ivec2 const v_out = {
		~(v_lh.x & s_rh),
		~(v_lh.y & s_rh),
	};
	return v_out;
}

ijk_inl ivec2 ijkVecBitOr2is(ivec2 const v_lh, int const s_rh)
{
	ivec2 const v_out = {
		(v_lh.x | s_rh),
		(v_lh.y | s_rh),
	};
	return v_out;
}

ijk_inl ivec2 ijkVecBitNor2is(ivec2 const v_lh, int const s_rh)
{
	ivec2 const v_out = {
		~(v_lh.x | s_rh),
		~(v_lh.y | s_rh),
	};
	return v_out;
}

ijk_inl ivec2 ijkVecBitXor2is(ivec2 const v_lh, int const s_rh)
{
	ivec2 const v_out = {
		(v_lh.x ^ s_rh),
		(v_lh.y ^ s_rh),
	};
	return v_out;
}

ijk_inl ivec2 ijkVecBitXnor2is(ivec2 const v_lh, int const s_rh)
{
	ivec2 const v_out = {
		~(v_lh.x ^ s_rh),
		~(v_lh.y ^ s_rh),
	};
	return v_out;
}

ijk_inl ivec2 ijkVecBitShiftLeft2is(ivec2 const v_lh, int const s_rh)
{
	ivec2 const v_out = {
		(v_lh.x << s_rh),
		(v_lh.y << s_rh),
	};
	return v_out;
}

ijk_inl ivec2 ijkVecBitShiftRight2is(ivec2 const v_lh, int const s_rh)
{
	ivec2 const v_out = {
		(v_lh.x >> s_rh),
		(v_lh.y >> s_rh),
	};
	return v_out;
}

ijk_inl bvec2 ijkVecEqual2is(ivec2 const v_lh, int const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x == s_rh),
		(v_lh.y == s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecInequal2is(ivec2 const v_lh, int const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x != s_rh),
		(v_lh.y != s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLessEqual2is(ivec2 const v_lh, int const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x <= s_rh),
		(v_lh.y <= s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreaterEqual2is(ivec2 const v_lh, int const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x >= s_rh),
		(v_lh.y >= s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLess2is(ivec2 const v_lh, int const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x < s_rh),
		(v_lh.y < s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreater2is(ivec2 const v_lh, int const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x > s_rh),
		(v_lh.y > s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecAnd2is(ivec2 const v_lh, int const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x && s_rh),
		(v_lh.y && s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNand2is(ivec2 const v_lh, int const s_rh)
{
	bvec2 const bv_out = {
		!(v_lh.x && s_rh),
		!(v_lh.y && s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecOr2is(ivec2 const v_lh, int const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x || s_rh),
		(v_lh.y || s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNor2is(ivec2 const v_lh, int const s_rh)
{
	bvec2 const bv_out = {
		!(v_lh.x || s_rh),
		!(v_lh.y || s_rh),
	};
	return bv_out;
}

ijk_inl ivec2 ijkVecAdd2si(int const s_lh, ivec2 const v_rh)
{
	ivec2 const v_out = {
		s_lh + v_rh.x,
		s_lh + v_rh.y,
	};
	return v_out;
}

ijk_inl ivec2 ijkVecSub2si(int const s_lh, ivec2 const v_rh)
{
	ivec2 const v_out = {
		s_lh - v_rh.x,
		s_lh - v_rh.y,
	};
	return v_out;
}

ijk_inl ivec2 ijkVecMul2si(int const s_lh, ivec2 const v_rh)
{
	ivec2 const v_out = {
		s_lh * v_rh.x,
		s_lh * v_rh.y,
	};
	return v_out;
}

ijk_inl ivec2 ijkVecDiv2si(int const s_lh, ivec2 const v_rh)
{
	ivec2 const v_out = {
		s_lh / v_rh.x,
		s_lh / v_rh.y,
	};
	return v_out;
}

ijk_inl ivec2 ijkVecDivSafe2si(int const s_lh, ivec2 const v_rh)
{
	ivec2 const v_out = {
		ijk_divide_safe_int(s_lh, v_rh.x),
		ijk_divide_safe_int(s_lh, v_rh.y),
	};
	return v_out;
}

ijk_inl ivec2 ijkVecMod2si(int const s_lh, ivec2 const v_rh)
{
	ivec2 const v_out = {
		s_lh % v_rh.x,
		s_lh % v_rh.y,
	};
	return v_out;
}

ijk_inl ivec2 ijkVecModSafe2si(int const s_lh, ivec2 const v_rh)
{
	ivec2 const v_out = {
		ijk_modulo_safe_int(s_lh, v_rh.x),
		ijk_modulo_safe_int(s_lh, v_rh.y),
	};
	return v_out;
}

ijk_inl ivec2 ijkVecBitAnd2si(int const s_lh, ivec2 const v_rh)
{
	ivec2 const v_out = {
		(s_lh & v_rh.x),
		(s_lh & v_rh.y),
	};
	return v_out;
}

ijk_inl ivec2 ijkVecBitNand2si(int const s_lh, ivec2 const v_rh)
{
	ivec2 const v_out = {
		~(s_lh & v_rh.x),
		~(s_lh & v_rh.y),
	};
	return v_out;
}

ijk_inl ivec2 ijkVecBitOr2si(int const s_lh, ivec2 const v_rh)
{
	ivec2 const v_out = {
		(s_lh | v_rh.x),
		(s_lh | v_rh.y),
	};
	return v_out;
}

ijk_inl ivec2 ijkVecBitNor2si(int const s_lh, ivec2 const v_rh)
{
	ivec2 const v_out = {
		~(s_lh | v_rh.x),
		~(s_lh | v_rh.y),
	};
	return v_out;
}

ijk_inl ivec2 ijkVecBitXor2si(int const s_lh, ivec2 const v_rh)
{
	ivec2 const v_out = {
		(s_lh ^ v_rh.x),
		(s_lh ^ v_rh.y),
	};
	return v_out;
}

ijk_inl ivec2 ijkVecBitXnor2si(int const s_lh, ivec2 const v_rh)
{
	ivec2 const v_out = {
		~(s_lh ^ v_rh.x),
		~(s_lh ^ v_rh.y),
	};
	return v_out;
}

ijk_inl ivec2 ijkVecBitShiftLeft2si(int const s_lh, ivec2 const v_rh)
{
	ivec2 const v_out = {
		(s_lh << v_rh.x),
		(s_lh << v_rh.y),
	};
	return v_out;
}

ijk_inl ivec2 ijkVecBitShiftRight2si(int const s_lh, ivec2 const v_rh)
{
	ivec2 const v_out = {
		(s_lh >> v_rh.x),
		(s_lh >> v_rh.y),
	};
	return v_out;
}

ijk_inl bvec2 ijkVecEqual2si(int const s_lh, ivec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh == v_rh.x),
		(s_lh == v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecInequal2si(int const s_lh, ivec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh != v_rh.x),
		(s_lh != v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLessEqual2si(int const s_lh, ivec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh <= v_rh.x),
		(s_lh <= v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreaterEqual2si(int const s_lh, ivec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh >= v_rh.x),
		(s_lh >= v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLess2si(int const s_lh, ivec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh < v_rh.x),
		(s_lh < v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreater2si(int const s_lh, ivec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh > v_rh.x),
		(s_lh > v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecAnd2si(int const s_lh, ivec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh && v_rh.x),
		(s_lh && v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNand2si(int const s_lh, ivec2 const v_rh)
{
	bvec2 const bv_out = {
		!(s_lh && v_rh.x),
		!(s_lh && v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecOr2si(int const s_lh, ivec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh || v_rh.x),
		(s_lh || v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNor2si(int const s_lh, ivec2 const v_rh)
{
	bvec2 const bv_out = {
		!(s_lh || v_rh.x),
		!(s_lh || v_rh.y),
	};
	return bv_out;
}

ijk_inl int ijkVecDot2i(ivec2 const v_lh, ivec2 const v_rh)
{
	return ijkVecDot2iv(v_lh.xy, v_rh.xy);
}

ijk_inl int ijkVecCross2i(ivec2 const v_lh, ivec2 const v_rh)
{
	return ijkVecCross2iv(v_lh.xy, v_rh.xy);
}


//-----------------------------------------------------------------------------

ijk_inl ivec3 ijkVecInit3i()
{
	ivec3 const v_out = { 0, 0, 0 };
	return v_out;
}

ijk_inl ivec3 ijkVecInitElems3i(int const x, int const y, int const z)
{
	ivec3 const v_out = { x, y, z };
	return v_out;
}

ijk_inl ivec3 ijkVecCopy3i(ivec3 const v_in)
{
	ivec3 const v_out = { +v_in.x, +v_in.y, +v_in.z };
	return v_out;
}

ijk_inl ivec3 ijkVecNegate3i(ivec3 const v_in)
{
	ivec3 const v_out = { -v_in.x, -v_in.y, -v_in.z };
	return v_out;
}

ijk_inl ivec3 ijkVecBitNot3i(ivec3 const v_in)
{
	ivec3 const v_out = { ~v_in.x, ~v_in.y, ~v_in.z };
	return v_out;
}

ijk_inl bvec3 ijkVecNot3i(ivec3 const v_in)
{
	bvec3 const bv_out = { !v_in.x, !v_in.y, !v_in.z };
	return bv_out;
}

ijk_inl ivec3 ijkVecAdd3i(ivec3 const v_lh, ivec3 const v_rh)
{
	ivec3 const v_out = {
		v_lh.x + v_rh.x,
		v_lh.y + v_rh.y,
		v_lh.z + v_rh.z,
	};
	return v_out;
}

ijk_inl ivec3 ijkVecSub3i(ivec3 const v_lh, ivec3 const v_rh)
{
	ivec3 const v_out = {
		v_lh.x - v_rh.x,
		v_lh.y - v_rh.y,
		v_lh.z - v_rh.z,
	};
	return v_out;
}

ijk_inl ivec3 ijkVecMul3i(ivec3 const v_lh, ivec3 const v_rh)
{
	ivec3 const v_out = {
		v_lh.x * v_rh.x,
		v_lh.y * v_rh.y,
		v_lh.z * v_rh.z,
	};
	return v_out;
}

ijk_inl ivec3 ijkVecDiv3i(ivec3 const v_lh, ivec3 const v_rh)
{
	ivec3 const v_out = {
		v_lh.x / v_rh.x,
		v_lh.y / v_rh.y,
		v_lh.z / v_rh.z,
	};
	return v_out;
}

ijk_inl ivec3 ijkVecDivSafe3i(ivec3 const v_lh, ivec3 const v_rh)
{
	ivec3 const v_out = {
		ijk_divide_safe_int(v_lh.x, v_rh.x),
		ijk_divide_safe_int(v_lh.y, v_rh.y),
		ijk_divide_safe_int(v_lh.z, v_rh.z),
	};
	return v_out;
}

ijk_inl ivec3 ijkVecMod3i(ivec3 const v_lh, ivec3 const v_rh)
{
	ivec3 const v_out = {
		v_lh.x % v_rh.x,
		v_lh.y % v_rh.y,
		v_lh.z % v_rh.z,
	};
	return v_out;
}

ijk_inl ivec3 ijkVecModSafe3i(ivec3 const v_lh, ivec3 const v_rh)
{
	ivec3 const v_out = {
		ijk_modulo_safe_int(v_lh.x, v_rh.x),
		ijk_modulo_safe_int(v_lh.y, v_rh.y),
		ijk_modulo_safe_int(v_lh.z, v_rh.z),
	};
	return v_out;
}

ijk_inl ivec3 ijkVecBitAnd3i(ivec3 const v_lh, ivec3 const v_rh)
{
	ivec3 const v_out = {
		(v_lh.x & v_rh.x),
		(v_lh.y & v_rh.y),
		(v_lh.z & v_rh.z),
	};
	return v_out;
}

ijk_inl ivec3 ijkVecBitNand3i(ivec3 const v_lh, ivec3 const v_rh)
{
	ivec3 const v_out = {
		~(v_lh.x & v_rh.x),
		~(v_lh.y & v_rh.y),
		~(v_lh.z & v_rh.z),
	};
	return v_out;
}

ijk_inl ivec3 ijkVecBitOr3i(ivec3 const v_lh, ivec3 const v_rh)
{
	ivec3 const v_out = {
		(v_lh.x | v_rh.x),
		(v_lh.y | v_rh.y),
		(v_lh.z | v_rh.z),
	};
	return v_out;
}

ijk_inl ivec3 ijkVecBitNor3i(ivec3 const v_lh, ivec3 const v_rh)
{
	ivec3 const v_out = {
		~(v_lh.x | v_rh.x),
		~(v_lh.y | v_rh.y),
		~(v_lh.z | v_rh.z),
	};
	return v_out;
}

ijk_inl ivec3 ijkVecBitXor3i(ivec3 const v_lh, ivec3 const v_rh)
{
	ivec3 const v_out = {
		(v_lh.x ^ v_rh.x),
		(v_lh.y ^ v_rh.y),
		(v_lh.z ^ v_rh.z),
	};
	return v_out;
}

ijk_inl ivec3 ijkVecBitXnor3i(ivec3 const v_lh, ivec3 const v_rh)
{
	ivec3 const v_out = {
		~(v_lh.x ^ v_rh.x),
		~(v_lh.y ^ v_rh.y),
		~(v_lh.z ^ v_rh.z),
	};
	return v_out;
}

ijk_inl ivec3 ijkVecBitShiftLeft3i(ivec3 const v_lh, ivec3 const v_rh)
{
	ivec3 const v_out = {
		(v_lh.x << v_rh.x),
		(v_lh.y << v_rh.y),
		(v_lh.z << v_rh.z),
	};
	return v_out;
}

ijk_inl ivec3 ijkVecBitShiftRight3i(ivec3 const v_lh, ivec3 const v_rh)
{
	ivec3 const v_out = {
		(v_lh.x >> v_rh.x),
		(v_lh.y >> v_rh.y),
		(v_lh.z >> v_rh.z),
	};
	return v_out;
}

ijk_inl bvec3 ijkVecEqual3i(ivec3 const v_lh, ivec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x == v_rh.x),
		(v_lh.y == v_rh.y),
		(v_lh.z == v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecInequal3i(ivec3 const v_lh, ivec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x != v_rh.x),
		(v_lh.y != v_rh.y),
		(v_lh.z != v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLessEqual3i(ivec3 const v_lh, ivec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x <= v_rh.x),
		(v_lh.y <= v_rh.y),
		(v_lh.z <= v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreaterEqual3i(ivec3 const v_lh, ivec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x >= v_rh.x),
		(v_lh.y >= v_rh.y),
		(v_lh.z >= v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLess3i(ivec3 const v_lh, ivec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x < v_rh.x),
		(v_lh.y < v_rh.y),
		(v_lh.z < v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreater3i(ivec3 const v_lh, ivec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x > v_rh.x),
		(v_lh.y > v_rh.y),
		(v_lh.z > v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecAnd3i(ivec3 const v_lh, ivec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x && v_rh.x),
		(v_lh.y && v_rh.y),
		(v_lh.z && v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNand3i(ivec3 const v_lh, ivec3 const v_rh)
{
	bvec3 const bv_out = {
		!(v_lh.x && v_rh.x),
		!(v_lh.y && v_rh.y),
		!(v_lh.z && v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecOr3i(ivec3 const v_lh, ivec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x || v_rh.x),
		(v_lh.y || v_rh.y),
		(v_lh.z || v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNor3i(ivec3 const v_lh, ivec3 const v_rh)
{
	bvec3 const bv_out = {
		!(v_lh.x || v_rh.x),
		!(v_lh.y || v_rh.y),
		!(v_lh.z || v_rh.z),
	};
	return bv_out;
}

ijk_inl ivec3 ijkVecCopy3iz(ivec2 const v_xy, int const z)
{
	ivec3 const v_out = { v_xy.x, v_xy.y, z };
	return v_out;
}

ijk_inl ivec3 ijkVecCopy3is(int const s_in)
{
	ivec3 const v_out = { s_in, s_in, s_in };
	return v_out;
}

ijk_inl ivec3 ijkVecNegate3is(int const s_in)
{
	int const s = -s_in;
	ivec3 const v_out = { s, s, s };
	return v_out;
}

ijk_inl ivec3 ijkVecBitNot3is(int const s_in)
{
	int const s = ~s_in;
	ivec3 const v_out = { s, s, s };
	return v_out;
}

ijk_inl bvec3 ijkVecNot3is(int const s_in)
{
	bool const s = !s_in;
	bvec3 const bv_out = { s, s, s };
	return bv_out;
}

ijk_inl ivec3 ijkVecAdd3is(ivec3 const v_lh, int const s_rh)
{
	ivec3 const v_out = {
		v_lh.x + s_rh,
		v_lh.y + s_rh,
		v_lh.z + s_rh,
	};
	return v_out;
}

ijk_inl ivec3 ijkVecSub3is(ivec3 const v_lh, int const s_rh)
{
	ivec3 const v_out = {
		v_lh.x - s_rh,
		v_lh.y - s_rh,
		v_lh.z - s_rh,
	};
	return v_out;
}

ijk_inl ivec3 ijkVecMul3is(ivec3 const v_lh, int const s_rh)
{
	ivec3 const v_out = {
		v_lh.x * s_rh,
		v_lh.y * s_rh,
		v_lh.z * s_rh,
	};
	return v_out;
}

ijk_inl ivec3 ijkVecDiv3is(ivec3 const v_lh, int const s_rh)
{
	ivec3 const v_out = {
		v_lh.x / s_rh,
		v_lh.y / s_rh,
		v_lh.z / s_rh,
	};
	return v_out;
}

ijk_inl ivec3 ijkVecDivSafe3is(ivec3 const v_lh, int const s_rh)
{
	if (s_rh)
	{
		ivec3 const v_out = {
			v_lh.x / s_rh,
			v_lh.y / s_rh,
			v_lh.z / s_rh,
		};
		return v_out;
	}
	else
	{
		ivec3 const v_out = { 0, 0, 0 };
		return v_out;
	}
}

ijk_inl ivec3 ijkVecMod3is(ivec3 const v_lh, int const s_rh)
{
	ivec3 const v_out = {
		v_lh.x % s_rh,
		v_lh.y % s_rh,
		v_lh.z % s_rh,
	};
	return v_out;
}

ijk_inl ivec3 ijkVecModSafe3is(ivec3 const v_lh, int const s_rh)
{
	if (s_rh)
	{
		ivec3 const v_out = {
			v_lh.x % s_rh,
			v_lh.y % s_rh,
			v_lh.z % s_rh,
		};
		return v_out;
	}
	else
	{
		ivec3 const v_out = { 0, 0, 0 };
		return v_out;
	}
}

ijk_inl ivec3 ijkVecBitAnd3is(ivec3 const v_lh, int const s_rh)
{
	ivec3 const v_out = {
		(v_lh.x & s_rh),
		(v_lh.y & s_rh),
		(v_lh.z & s_rh),
	};
	return v_out;
}

ijk_inl ivec3 ijkVecBitNand3is(ivec3 const v_lh, int const s_rh)
{
	ivec3 const v_out = {
		~(v_lh.x & s_rh),
		~(v_lh.y & s_rh),
		~(v_lh.z & s_rh),
	};
	return v_out;
}

ijk_inl ivec3 ijkVecBitOr3is(ivec3 const v_lh, int const s_rh)
{
	ivec3 const v_out = {
		(v_lh.x | s_rh),
		(v_lh.y | s_rh),
		(v_lh.z | s_rh),
	};
	return v_out;
}

ijk_inl ivec3 ijkVecBitNor3is(ivec3 const v_lh, int const s_rh)
{
	ivec3 const v_out = {
		~(v_lh.x | s_rh),
		~(v_lh.y | s_rh),
		~(v_lh.z | s_rh),
	};
	return v_out;
}

ijk_inl ivec3 ijkVecBitXor3is(ivec3 const v_lh, int const s_rh)
{
	ivec3 const v_out = {
		(v_lh.x ^ s_rh),
		(v_lh.y ^ s_rh),
		(v_lh.z ^ s_rh),
	};
	return v_out;
}

ijk_inl ivec3 ijkVecBitXnor3is(ivec3 const v_lh, int const s_rh)
{
	ivec3 const v_out = {
		~(v_lh.x ^ s_rh),
		~(v_lh.y ^ s_rh),
		~(v_lh.z ^ s_rh),
	};
	return v_out;
}

ijk_inl ivec3 ijkVecBitShiftLeft3is(ivec3 const v_lh, int const s_rh)
{
	ivec3 const v_out = {
		(v_lh.x << s_rh),
		(v_lh.y << s_rh),
		(v_lh.z << s_rh),
	};
	return v_out;
}

ijk_inl ivec3 ijkVecBitShiftRight3is(ivec3 const v_lh, int const s_rh)
{
	ivec3 const v_out = {
		(v_lh.x >> s_rh),
		(v_lh.y >> s_rh),
		(v_lh.z >> s_rh),
	};
	return v_out;
}

ijk_inl bvec3 ijkVecEqual3is(ivec3 const v_lh, int const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x == s_rh),
		(v_lh.y == s_rh),
		(v_lh.z == s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecInequal3is(ivec3 const v_lh, int const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x != s_rh),
		(v_lh.y != s_rh),
		(v_lh.z != s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLessEqual3is(ivec3 const v_lh, int const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x <= s_rh),
		(v_lh.y <= s_rh),
		(v_lh.z <= s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreaterEqual3is(ivec3 const v_lh, int const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x >= s_rh),
		(v_lh.y >= s_rh),
		(v_lh.z >= s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLess3is(ivec3 const v_lh, int const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x < s_rh),
		(v_lh.y < s_rh),
		(v_lh.z < s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreater3is(ivec3 const v_lh, int const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x > s_rh),
		(v_lh.y > s_rh),
		(v_lh.z > s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecAnd3is(ivec3 const v_lh, int const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x && s_rh),
		(v_lh.y && s_rh),
		(v_lh.z && s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNand3is(ivec3 const v_lh, int const s_rh)
{
	bvec3 const bv_out = {
		!(v_lh.x && s_rh),
		!(v_lh.y && s_rh),
		!(v_lh.z && s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecOr3is(ivec3 const v_lh, int const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x || s_rh),
		(v_lh.y || s_rh),
		(v_lh.z || s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNor3is(ivec3 const v_lh, int const s_rh)
{
	bvec3 const bv_out = {
		!(v_lh.x || s_rh),
		!(v_lh.y || s_rh),
		!(v_lh.z || s_rh),
	};
	return bv_out;
}

ijk_inl ivec3 ijkVecCopy3xi(int const x, ivec2 const v_yz)
{
	ivec3 const v_out = { x, v_yz.x, v_yz.y };
	return v_out;
}

ijk_inl ivec3 ijkVecAdd3si(int const s_lh, ivec3 const v_rh)
{
	ivec3 const v_out = {
		s_lh + v_rh.x,
		s_lh + v_rh.y,
		s_lh + v_rh.z,
	};
	return v_out;
}

ijk_inl ivec3 ijkVecSub3si(int const s_lh, ivec3 const v_rh)
{
	ivec3 const v_out = {
		s_lh - v_rh.x,
		s_lh - v_rh.y,
		s_lh - v_rh.z,
	};
	return v_out;
}

ijk_inl ivec3 ijkVecMul3si(int const s_lh, ivec3 const v_rh)
{
	ivec3 const v_out = {
		s_lh * v_rh.x,
		s_lh * v_rh.y,
		s_lh * v_rh.z,
	};
	return v_out;
}

ijk_inl ivec3 ijkVecDiv3si(int const s_lh, ivec3 const v_rh)
{
	ivec3 const v_out = {
		s_lh / v_rh.x,
		s_lh / v_rh.y,
		s_lh / v_rh.z,
	};
	return v_out;
}

ijk_inl ivec3 ijkVecDivSafe3si(int const s_lh, ivec3 const v_rh)
{
	ivec3 const v_out = {
		ijk_divide_safe_int(s_lh, v_rh.x),
		ijk_divide_safe_int(s_lh, v_rh.y),
		ijk_divide_safe_int(s_lh, v_rh.z),
	};
	return v_out;
}

ijk_inl ivec3 ijkVecMod3si(int const s_lh, ivec3 const v_rh)
{
	ivec3 const v_out = {
		s_lh % v_rh.x,
		s_lh % v_rh.y,
		s_lh % v_rh.z,
	};
	return v_out;
}

ijk_inl ivec3 ijkVecModSafe3si(int const s_lh, ivec3 const v_rh)
{
	ivec3 const v_out = {
		ijk_modulo_safe_int(s_lh, v_rh.x),
		ijk_modulo_safe_int(s_lh, v_rh.y),
		ijk_modulo_safe_int(s_lh, v_rh.z),
	};
	return v_out;
}

ijk_inl ivec3 ijkVecBitAnd3si(int const s_lh, ivec3 const v_rh)
{
	ivec3 const v_out = {
		(s_lh & v_rh.x),
		(s_lh & v_rh.y),
		(s_lh & v_rh.z),
	};
	return v_out;
}

ijk_inl ivec3 ijkVecBitNand3si(int const s_lh, ivec3 const v_rh)
{
	ivec3 const v_out = {
		~(s_lh & v_rh.x),
		~(s_lh & v_rh.y),
		~(s_lh & v_rh.z),
	};
	return v_out;
}

ijk_inl ivec3 ijkVecBitOr3si(int const s_lh, ivec3 const v_rh)
{
	ivec3 const v_out = {
		(s_lh | v_rh.x),
		(s_lh | v_rh.y),
		(s_lh | v_rh.z),
	};
	return v_out;
}

ijk_inl ivec3 ijkVecBitNor3si(int const s_lh, ivec3 const v_rh)
{
	ivec3 const v_out = {
		~(s_lh | v_rh.x),
		~(s_lh | v_rh.y),
		~(s_lh | v_rh.z),
	};
	return v_out;
}

ijk_inl ivec3 ijkVecBitXor3si(int const s_lh, ivec3 const v_rh)
{
	ivec3 const v_out = {
		(s_lh ^ v_rh.x),
		(s_lh ^ v_rh.y),
		(s_lh ^ v_rh.z),
	};
	return v_out;
}

ijk_inl ivec3 ijkVecBitXnor3si(int const s_lh, ivec3 const v_rh)
{
	ivec3 const v_out = {
		~(s_lh ^ v_rh.x),
		~(s_lh ^ v_rh.y),
		~(s_lh ^ v_rh.z),
	};
	return v_out;
}

ijk_inl ivec3 ijkVecBitShiftLeft3si(int const s_lh, ivec3 const v_rh)
{
	ivec3 const v_out = {
		(s_lh << v_rh.x),
		(s_lh << v_rh.y),
		(s_lh << v_rh.z),
	};
	return v_out;
}

ijk_inl ivec3 ijkVecBitShiftRight3si(int const s_lh, ivec3 const v_rh)
{
	ivec3 const v_out = {
		(s_lh >> v_rh.x),
		(s_lh >> v_rh.y),
		(s_lh >> v_rh.z),
	};
	return v_out;
}

ijk_inl bvec3 ijkVecEqual3si(int const s_lh, ivec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh == v_rh.x),
		(s_lh == v_rh.y),
		(s_lh == v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecInequal3si(int const s_lh, ivec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh != v_rh.x),
		(s_lh != v_rh.y),
		(s_lh != v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLessEqual3si(int const s_lh, ivec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh <= v_rh.x),
		(s_lh <= v_rh.y),
		(s_lh <= v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreaterEqual3si(int const s_lh, ivec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh >= v_rh.x),
		(s_lh >= v_rh.y),
		(s_lh >= v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLess3si(int const s_lh, ivec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh < v_rh.x),
		(s_lh < v_rh.y),
		(s_lh < v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreater3si(int const s_lh, ivec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh > v_rh.x),
		(s_lh > v_rh.y),
		(s_lh > v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecAnd3si(int const s_lh, ivec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh && v_rh.x),
		(s_lh && v_rh.y),
		(s_lh && v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNand3si(int const s_lh, ivec3 const v_rh)
{
	bvec3 const bv_out = {
		!(s_lh && v_rh.x),
		!(s_lh && v_rh.y),
		!(s_lh && v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecOr3si(int const s_lh, ivec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh || v_rh.x),
		(s_lh || v_rh.y),
		(s_lh || v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNor3si(int const s_lh, ivec3 const v_rh)
{
	bvec3 const bv_out = {
		!(s_lh || v_rh.x),
		!(s_lh || v_rh.y),
		!(s_lh || v_rh.z),
	};
	return bv_out;
}

ijk_inl int ijkVecDot3i(ivec3 const v_lh, ivec3 const v_rh)
{
	return ijkVecDot3iv(v_lh.xyz, v_rh.xyz);
}

ijk_inl ivec3 ijkVecCross3i(ivec3 const v_lh, ivec3 const v_rh)
{
	ivec3 v_out;
	ijkVecCross3iv(v_out.xyz, v_lh.xyz, v_rh.xyz);
	return v_out;
}


//-----------------------------------------------------------------------------

ijk_inl ivec4 ijkVecInit4i()
{
	ivec4 const v_out = { 0, 0, 0, 0 };
	return v_out;
}

ijk_inl ivec4 ijkVecInitElems4i(int const x, int const y, int const z, int const w)
{
	ivec4 const v_out = { x, y, z, w };
	return v_out;
}

ijk_inl ivec4 ijkVecCopy4xiw(int const x, ivec2 const v_yz, int const w)
{
	ivec4 const v_out = { x, v_yz.x, v_yz.y, w };
	return v_out;
}

ijk_inl ivec4 ijkVecCopy4i2(ivec2 const v_xy, ivec2 const v_zw)
{
	ivec4 const v_out = { v_xy.x, v_xy.y, v_zw.x, v_zw.y };
	return v_out;
}

ijk_inl ivec4 ijkVecCopy4i(ivec4 const v_in)
{
	ivec4 const v_out = { +v_in.x, +v_in.y, +v_in.z, +v_in.w };
	return v_out;
}

ijk_inl ivec4 ijkVecNegate4i(ivec4 const v_in)
{
	ivec4 const v_out = { -v_in.x, -v_in.y, -v_in.z, -v_in.w };
	return v_out;
}

ijk_inl ivec4 ijkVecBitNot4i(ivec4 const v_in)
{
	ivec4 const v_out = { ~v_in.x, ~v_in.y, ~v_in.z, ~v_in.w };
	return v_out;
}

ijk_inl bvec4 ijkVecNot4i(ivec4 const v_in)
{
	bvec4 const bv_out = { !v_in.x, !v_in.y, !v_in.z, !v_in.w };
	return bv_out;
}

ijk_inl ivec4 ijkVecAdd4i(ivec4 const v_lh, ivec4 const v_rh)
{
	ivec4 const v_out = {
		v_lh.x + v_rh.x,
		v_lh.y + v_rh.y,
		v_lh.z + v_rh.z,
		v_lh.w + v_rh.w,
	};
	return v_out;
}

ijk_inl ivec4 ijkVecSub4i(ivec4 const v_lh, ivec4 const v_rh)
{
	ivec4 const v_out = {
		v_lh.x - v_rh.x,
		v_lh.y - v_rh.y,
		v_lh.z - v_rh.z,
		v_lh.w - v_rh.w,
	};
	return v_out;
}

ijk_inl ivec4 ijkVecMul4i(ivec4 const v_lh, ivec4 const v_rh)
{
	ivec4 const v_out = {
		v_lh.x * v_rh.x,
		v_lh.y * v_rh.y,
		v_lh.z * v_rh.z,
		v_lh.w * v_rh.w,
	};
	return v_out;
}

ijk_inl ivec4 ijkVecDiv4i(ivec4 const v_lh, ivec4 const v_rh)
{
	ivec4 const v_out = {
		v_lh.x / v_rh.x,
		v_lh.y / v_rh.y,
		v_lh.z / v_rh.z,
		v_lh.w / v_rh.w,
	};
	return v_out;
}

ijk_inl ivec4 ijkVecDivSafe4i(ivec4 const v_lh, ivec4 const v_rh)
{
	ivec4 const v_out = {
		ijk_divide_safe_int(v_lh.x, v_rh.x),
		ijk_divide_safe_int(v_lh.y, v_rh.y),
		ijk_divide_safe_int(v_lh.z, v_rh.z),
		ijk_divide_safe_int(v_lh.w, v_rh.w),
	};
	return v_out;
}

ijk_inl ivec4 ijkVecMod4i(ivec4 const v_lh, ivec4 const v_rh)
{
	ivec4 const v_out = {
		v_lh.x % v_rh.x,
		v_lh.y % v_rh.y,
		v_lh.z % v_rh.z,
		v_lh.w % v_rh.w,
	};
	return v_out;
}

ijk_inl ivec4 ijkVecModSafe4i(ivec4 const v_lh, ivec4 const v_rh)
{
	ivec4 const v_out = {
		ijk_modulo_safe_int(v_lh.x, v_rh.x),
		ijk_modulo_safe_int(v_lh.y, v_rh.y),
		ijk_modulo_safe_int(v_lh.z, v_rh.z),
		ijk_modulo_safe_int(v_lh.w, v_rh.w),
	};
	return v_out;
}

ijk_inl ivec4 ijkVecBitAnd4i(ivec4 const v_lh, ivec4 const v_rh)
{
	ivec4 const v_out = {
		(v_lh.x & v_rh.x),
		(v_lh.y & v_rh.y),
		(v_lh.z & v_rh.z),
		(v_lh.w & v_rh.w),
	};
	return v_out;
}

ijk_inl ivec4 ijkVecBitNand4i(ivec4 const v_lh, ivec4 const v_rh)
{
	ivec4 const v_out = {
		~(v_lh.x & v_rh.x),
		~(v_lh.y & v_rh.y),
		~(v_lh.z & v_rh.z),
		~(v_lh.w & v_rh.w),
	};
	return v_out;
}

ijk_inl ivec4 ijkVecBitOr4i(ivec4 const v_lh, ivec4 const v_rh)
{
	ivec4 const v_out = {
		(v_lh.x | v_rh.x),
		(v_lh.y | v_rh.y),
		(v_lh.z | v_rh.z),
		(v_lh.w | v_rh.w),
	};
	return v_out;
}

ijk_inl ivec4 ijkVecBitNor4i(ivec4 const v_lh, ivec4 const v_rh)
{
	ivec4 const v_out = {
		~(v_lh.x | v_rh.x),
		~(v_lh.y | v_rh.y),
		~(v_lh.z | v_rh.z),
		~(v_lh.w | v_rh.w),
	};
	return v_out;
}

ijk_inl ivec4 ijkVecBitXor4i(ivec4 const v_lh, ivec4 const v_rh)
{
	ivec4 const v_out = {
		(v_lh.x ^ v_rh.x),
		(v_lh.y ^ v_rh.y),
		(v_lh.z ^ v_rh.z),
		(v_lh.w ^ v_rh.w),
	};
	return v_out;
}

ijk_inl ivec4 ijkVecBitXnor4i(ivec4 const v_lh, ivec4 const v_rh)
{
	ivec4 const v_out = {
		~(v_lh.x ^ v_rh.x),
		~(v_lh.y ^ v_rh.y),
		~(v_lh.z ^ v_rh.z),
		~(v_lh.w ^ v_rh.w),
	};
	return v_out;
}

ijk_inl ivec4 ijkVecBitShiftLeft4i(ivec4 const v_lh, ivec4 const v_rh)
{
	ivec4 const v_out = {
		(v_lh.x << v_rh.x),
		(v_lh.y << v_rh.y),
		(v_lh.z << v_rh.z),
		(v_lh.w << v_rh.w),
	};
	return v_out;
}

ijk_inl ivec4 ijkVecBitShiftRight4i(ivec4 const v_lh, ivec4 const v_rh)
{
	ivec4 const v_out = {
		(v_lh.x >> v_rh.x),
		(v_lh.y >> v_rh.y),
		(v_lh.z >> v_rh.z),
		(v_lh.w >> v_rh.w),
	};
	return v_out;
}

ijk_inl bvec4 ijkVecEqual4i(ivec4 const v_lh, ivec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x == v_rh.x),
		(v_lh.y == v_rh.y),
		(v_lh.z == v_rh.z),
		(v_lh.w == v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecInequal4i(ivec4 const v_lh, ivec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x != v_rh.x),
		(v_lh.y != v_rh.y),
		(v_lh.z != v_rh.z),
		(v_lh.w != v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLessEqual4i(ivec4 const v_lh, ivec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x <= v_rh.x),
		(v_lh.y <= v_rh.y),
		(v_lh.z <= v_rh.z),
		(v_lh.w <= v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreaterEqual4i(ivec4 const v_lh, ivec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x >= v_rh.x),
		(v_lh.y >= v_rh.y),
		(v_lh.z >= v_rh.z),
		(v_lh.w >= v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLess4i(ivec4 const v_lh, ivec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x < v_rh.x),
		(v_lh.y < v_rh.y),
		(v_lh.z < v_rh.z),
		(v_lh.w < v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreater4i(ivec4 const v_lh, ivec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x > v_rh.x),
		(v_lh.y > v_rh.y),
		(v_lh.z > v_rh.z),
		(v_lh.w > v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecAnd4i(ivec4 const v_lh, ivec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x && v_rh.x),
		(v_lh.y && v_rh.y),
		(v_lh.z && v_rh.z),
		(v_lh.w && v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNand4i(ivec4 const v_lh, ivec4 const v_rh)
{
	bvec4 const bv_out = {
		!(v_lh.x && v_rh.x),
		!(v_lh.y && v_rh.y),
		!(v_lh.z && v_rh.z),
		!(v_lh.w && v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecOr4i(ivec4 const v_lh, ivec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x || v_rh.x),
		(v_lh.y || v_rh.y),
		(v_lh.z || v_rh.z),
		(v_lh.w || v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNor4i(ivec4 const v_lh, ivec4 const v_rh)
{
	bvec4 const bv_out = {
		!(v_lh.x || v_rh.x),
		!(v_lh.y || v_rh.y),
		!(v_lh.z || v_rh.z),
		!(v_lh.w || v_rh.w),
	};
	return bv_out;
}

ijk_inl ivec4 ijkVecCopy4izw(ivec2 const v_xy, int const z, int const w)
{
	ivec4 const v_out = { v_xy.x, v_xy.y, z, w };
	return v_out;
}

ijk_inl ivec4 ijkVecCopy4iw(ivec3 const v_xyz, int const w)
{
	ivec4 const v_out = { v_xyz.x, v_xyz.y, v_xyz.z, w };
	return v_out;
}

ijk_inl ivec4 ijkVecCopy4is(int const s_in)
{
	ivec4 const v_out = { s_in, s_in, s_in, s_in };
	return v_out;
}

ijk_inl ivec4 ijkVecNegate4is(int const s_in)
{
	int const s = -s_in;
	ivec4 const v_out = { s, s, s, s };
	return v_out;
}

ijk_inl ivec4 ijkVecBitNot4is(int const s_in)
{
	int const s = ~s_in;
	ivec4 const v_out = { s, s, s, s };
	return v_out;
}

ijk_inl bvec4 ijkVecNot4is(int const s_in)
{
	bool const s = !s_in;
	bvec4 const bv_out = { s, s, s, s };
	return bv_out;
}

ijk_inl ivec4 ijkVecAdd4is(ivec4 const v_lh, int const s_rh)
{
	ivec4 const v_out = {
		v_lh.x + s_rh,
		v_lh.y + s_rh,
		v_lh.z + s_rh,
		v_lh.w + s_rh,
	};
	return v_out;
}

ijk_inl ivec4 ijkVecSub4is(ivec4 const v_lh, int const s_rh)
{
	ivec4 const v_out = {
		v_lh.x - s_rh,
		v_lh.y - s_rh,
		v_lh.z - s_rh,
		v_lh.w - s_rh,
	};
	return v_out;
}

ijk_inl ivec4 ijkVecMul4is(ivec4 const v_lh, int const s_rh)
{
	ivec4 const v_out = {
		v_lh.x * s_rh,
		v_lh.y * s_rh,
		v_lh.z * s_rh,
		v_lh.w * s_rh,
	};
	return v_out;
}

ijk_inl ivec4 ijkVecDiv4is(ivec4 const v_lh, int const s_rh)
{
	ivec4 const v_out = {
		v_lh.x / s_rh,
		v_lh.y / s_rh,
		v_lh.z / s_rh,
		v_lh.w / s_rh,
	};
	return v_out;
}

ijk_inl ivec4 ijkVecDivSafe4is(ivec4 const v_lh, int const s_rh)
{
	if (s_rh)
	{
		ivec4 const v_out = {
			v_lh.x / s_rh,
			v_lh.y / s_rh,
			v_lh.z / s_rh,
			v_lh.w / s_rh,
		};
		return v_out;
	}
	else
	{
		ivec4 const v_out = { 0, 0, 0, 0 };
		return v_out;
	}
}

ijk_inl ivec4 ijkVecMod4is(ivec4 const v_lh, int const s_rh)
{
	ivec4 const v_out = {
		v_lh.x % s_rh,
		v_lh.y % s_rh,
		v_lh.z % s_rh,
		v_lh.w % s_rh,
	};
	return v_out;
}

ijk_inl ivec4 ijkVecModSafe4is(ivec4 const v_lh, int const s_rh)
{
	if (s_rh)
	{
		ivec4 const v_out = {
			v_lh.x % s_rh,
			v_lh.y % s_rh,
			v_lh.z % s_rh,
			v_lh.w % s_rh,
		};
		return v_out;
	}
	else
	{
		ivec4 const v_out = { 0, 0, 0, 0 };
		return v_out;
	}
}

ijk_inl ivec4 ijkVecBitAnd4is(ivec4 const v_lh, int const s_rh)
{
	ivec4 const v_out = {
		(v_lh.x & s_rh),
		(v_lh.y & s_rh),
		(v_lh.z & s_rh),
		(v_lh.w & s_rh),
	};
	return v_out;
}

ijk_inl ivec4 ijkVecBitNand4is(ivec4 const v_lh, int const s_rh)
{
	ivec4 const v_out = {
		~(v_lh.x & s_rh),
		~(v_lh.y & s_rh),
		~(v_lh.z & s_rh),
		~(v_lh.w & s_rh),
	};
	return v_out;
}

ijk_inl ivec4 ijkVecBitOr4is(ivec4 const v_lh, int const s_rh)
{
	ivec4 const v_out = {
		(v_lh.x | s_rh),
		(v_lh.y | s_rh),
		(v_lh.z | s_rh),
		(v_lh.w | s_rh),
	};
	return v_out;
}

ijk_inl ivec4 ijkVecBitNor4is(ivec4 const v_lh, int const s_rh)
{
	ivec4 const v_out = {
		~(v_lh.x | s_rh),
		~(v_lh.y | s_rh),
		~(v_lh.z | s_rh),
		~(v_lh.w | s_rh),
	};
	return v_out;
}

ijk_inl ivec4 ijkVecBitXor4is(ivec4 const v_lh, int const s_rh)
{
	ivec4 const v_out = {
		(v_lh.x ^ s_rh),
		(v_lh.y ^ s_rh),
		(v_lh.z ^ s_rh),
		(v_lh.w ^ s_rh),
	};
	return v_out;
}

ijk_inl ivec4 ijkVecBitXnor4is(ivec4 const v_lh, int const s_rh)
{
	ivec4 const v_out = {
		~(v_lh.x ^ s_rh),
		~(v_lh.y ^ s_rh),
		~(v_lh.z ^ s_rh),
		~(v_lh.w ^ s_rh),
	};
	return v_out;
}

ijk_inl ivec4 ijkVecBitShiftLeft4is(ivec4 const v_lh, int const s_rh)
{
	ivec4 const v_out = {
		(v_lh.x << s_rh),
		(v_lh.y << s_rh),
		(v_lh.z << s_rh),
		(v_lh.w << s_rh),
	};
	return v_out;
}

ijk_inl ivec4 ijkVecBitShiftRight4is(ivec4 const v_lh, int const s_rh)
{
	ivec4 const v_out = {
		(v_lh.x >> s_rh),
		(v_lh.y >> s_rh),
		(v_lh.z >> s_rh),
		(v_lh.w >> s_rh),
	};
	return v_out;
}

ijk_inl bvec4 ijkVecEqual4is(ivec4 const v_lh, int const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x == s_rh),
		(v_lh.y == s_rh),
		(v_lh.z == s_rh),
		(v_lh.w == s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecInequal4is(ivec4 const v_lh, int const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x != s_rh),
		(v_lh.y != s_rh),
		(v_lh.z != s_rh),
		(v_lh.w != s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLessEqual4is(ivec4 const v_lh, int const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x <= s_rh),
		(v_lh.y <= s_rh),
		(v_lh.z <= s_rh),
		(v_lh.w <= s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreaterEqual4is(ivec4 const v_lh, int const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x >= s_rh),
		(v_lh.y >= s_rh),
		(v_lh.z >= s_rh),
		(v_lh.w >= s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLess4is(ivec4 const v_lh, int const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x < s_rh),
		(v_lh.y < s_rh),
		(v_lh.z < s_rh),
		(v_lh.w < s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreater4is(ivec4 const v_lh, int const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x > s_rh),
		(v_lh.y > s_rh),
		(v_lh.z > s_rh),
		(v_lh.w > s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecAnd4is(ivec4 const v_lh, int const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x && s_rh),
		(v_lh.y && s_rh),
		(v_lh.z && s_rh),
		(v_lh.w && s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNand4is(ivec4 const v_lh, int const s_rh)
{
	bvec4 const bv_out = {
		!(v_lh.x && s_rh),
		!(v_lh.y && s_rh),
		!(v_lh.z && s_rh),
		!(v_lh.w && s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecOr4is(ivec4 const v_lh, int const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x || s_rh),
		(v_lh.y || s_rh),
		(v_lh.z || s_rh),
		(v_lh.w || s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNor4is(ivec4 const v_lh, int const s_rh)
{
	bvec4 const bv_out = {
		!(v_lh.x || s_rh),
		!(v_lh.y || s_rh),
		!(v_lh.z || s_rh),
		!(v_lh.w || s_rh),
	};
	return bv_out;
}

ijk_inl ivec4 ijkVecCopy4xyi(int const x, int const y, ivec2 const v_zw)
{
	ivec4 const v_out = { x, y, v_zw.x, v_zw.y };
	return v_out;
}

ijk_inl ivec4 ijkVecCopy4xi(int const x, ivec3 const v_yzw)
{
	ivec4 const v_out = { x, v_yzw.x, v_yzw.y, v_yzw.z };
	return v_out;
}

ijk_inl ivec4 ijkVecAdd4si(int const s_lh, ivec4 const v_rh)
{
	ivec4 const v_out = {
		s_lh + v_rh.x,
		s_lh + v_rh.y,
		s_lh + v_rh.z,
		s_lh + v_rh.w,
	};
	return v_out;
}

ijk_inl ivec4 ijkVecSub4si(int const s_lh, ivec4 const v_rh)
{
	ivec4 const v_out = {
		s_lh - v_rh.x,
		s_lh - v_rh.y,
		s_lh - v_rh.z,
		s_lh - v_rh.w,
	};
	return v_out;
}

ijk_inl ivec4 ijkVecMul4si(int const s_lh, ivec4 const v_rh)
{
	ivec4 const v_out = {
		s_lh * v_rh.x,
		s_lh * v_rh.y,
		s_lh * v_rh.z,
		s_lh * v_rh.w,
	};
	return v_out;
}

ijk_inl ivec4 ijkVecDiv4si(int const s_lh, ivec4 const v_rh)
{
	ivec4 const v_out = {
		s_lh / v_rh.x,
		s_lh / v_rh.y,
		s_lh / v_rh.z,
		s_lh / v_rh.w,
	};
	return v_out;
}

ijk_inl ivec4 ijkVecDivSafe4si(int const s_lh, ivec4 const v_rh)
{
	ivec4 const v_out = {
		ijk_divide_safe_int(s_lh, v_rh.x),
		ijk_divide_safe_int(s_lh, v_rh.y),
		ijk_divide_safe_int(s_lh, v_rh.z),
		ijk_divide_safe_int(s_lh, v_rh.w),
	};
	return v_out;
}

ijk_inl ivec4 ijkVecMod4si(int const s_lh, ivec4 const v_rh)
{
	ivec4 const v_out = {
		s_lh % v_rh.x,
		s_lh % v_rh.y,
		s_lh % v_rh.z,
		s_lh % v_rh.w,
	};
	return v_out;
}

ijk_inl ivec4 ijkVecModSafe4si(int const s_lh, ivec4 const v_rh)
{
	ivec4 const v_out = {
		ijk_modulo_safe_int(s_lh, v_rh.x),
		ijk_modulo_safe_int(s_lh, v_rh.y),
		ijk_modulo_safe_int(s_lh, v_rh.z),
		ijk_modulo_safe_int(s_lh, v_rh.w),
	};
	return v_out;
}

ijk_inl ivec4 ijkVecBitAnd4si(int const s_lh, ivec4 const v_rh)
{
	ivec4 const v_out = {
		(s_lh & v_rh.x),
		(s_lh & v_rh.y),
		(s_lh & v_rh.z),
		(s_lh & v_rh.w),
	};
	return v_out;
}

ijk_inl ivec4 ijkVecBitNand4si(int const s_lh, ivec4 const v_rh)
{
	ivec4 const v_out = {
		~(s_lh & v_rh.x),
		~(s_lh & v_rh.y),
		~(s_lh & v_rh.z),
		~(s_lh & v_rh.w),
	};
	return v_out;
}

ijk_inl ivec4 ijkVecBitOr4si(int const s_lh, ivec4 const v_rh)
{
	ivec4 const v_out = {
		(s_lh | v_rh.x),
		(s_lh | v_rh.y),
		(s_lh | v_rh.z),
		(s_lh | v_rh.w),
	};
	return v_out;
}

ijk_inl ivec4 ijkVecBitNor4si(int const s_lh, ivec4 const v_rh)
{
	ivec4 const v_out = {
		~(s_lh | v_rh.x),
		~(s_lh | v_rh.y),
		~(s_lh | v_rh.z),
		~(s_lh | v_rh.w),
	};
	return v_out;
}

ijk_inl ivec4 ijkVecBitXor4si(int const s_lh, ivec4 const v_rh)
{
	ivec4 const v_out = {
		(s_lh ^ v_rh.x),
		(s_lh ^ v_rh.y),
		(s_lh ^ v_rh.z),
		(s_lh ^ v_rh.w),
	};
	return v_out;
}

ijk_inl ivec4 ijkVecBitXnor4si(int const s_lh, ivec4 const v_rh)
{
	ivec4 const v_out = {
		~(s_lh ^ v_rh.x),
		~(s_lh ^ v_rh.y),
		~(s_lh ^ v_rh.z),
		~(s_lh ^ v_rh.w),
	};
	return v_out;
}

ijk_inl ivec4 ijkVecBitShiftLeft4si(int const s_lh, ivec4 const v_rh)
{
	ivec4 const v_out = {
		(s_lh << v_rh.x),
		(s_lh << v_rh.y),
		(s_lh << v_rh.z),
		(s_lh << v_rh.w),
	};
	return v_out;
}

ijk_inl ivec4 ijkVecBitShiftRight4si(int const s_lh, ivec4 const v_rh)
{
	ivec4 const v_out = {
		(s_lh >> v_rh.x),
		(s_lh >> v_rh.y),
		(s_lh >> v_rh.z),
		(s_lh >> v_rh.w),
	};
	return v_out;
}

ijk_inl bvec4 ijkVecEqual4si(int const s_lh, ivec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh == v_rh.x),
		(s_lh == v_rh.y),
		(s_lh == v_rh.z),
		(s_lh == v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecInequal4si(int const s_lh, ivec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh != v_rh.x),
		(s_lh != v_rh.y),
		(s_lh != v_rh.z),
		(s_lh != v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLessEqual4si(int const s_lh, ivec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh <= v_rh.x),
		(s_lh <= v_rh.y),
		(s_lh <= v_rh.z),
		(s_lh <= v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreaterEqual4si(int const s_lh, ivec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh >= v_rh.x),
		(s_lh >= v_rh.y),
		(s_lh >= v_rh.z),
		(s_lh >= v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLess4si(int const s_lh, ivec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh < v_rh.x),
		(s_lh < v_rh.y),
		(s_lh < v_rh.z),
		(s_lh < v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreater4si(int const s_lh, ivec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh > v_rh.x),
		(s_lh > v_rh.y),
		(s_lh > v_rh.z),
		(s_lh > v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecAnd4si(int const s_lh, ivec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh && v_rh.x),
		(s_lh && v_rh.y),
		(s_lh && v_rh.z),
		(s_lh && v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNand4si(int const s_lh, ivec4 const v_rh)
{
	bvec4 const bv_out = {
		!(s_lh && v_rh.x),
		!(s_lh && v_rh.y),
		!(s_lh && v_rh.z),
		!(s_lh && v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecOr4si(int const s_lh, ivec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh || v_rh.x),
		(s_lh || v_rh.y),
		(s_lh || v_rh.z),
		(s_lh || v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNor4si(int const s_lh, ivec4 const v_rh)
{
	bvec4 const bv_out = {
		!(s_lh || v_rh.x),
		!(s_lh || v_rh.y),
		!(s_lh || v_rh.z),
		!(s_lh || v_rh.w),
	};
	return bv_out;
}

ijk_inl int ijkVecDot4i(ivec4 const v_lh, ivec4 const v_rh)
{
	return ijkVecDot4iv(v_lh.xyzw, v_rh.xyzw);
}

ijk_inl ivec4 ijkVecCross4i(ivec4 const v_lh, ivec4 const v_rh)
{
	ivec4 v_out;
	ijkVecCross4iv(v_out.xyzw, v_lh.xyzw, v_rh.xyzw);
	return v_out;
}


//-----------------------------------------------------------------------------


#endif	// !_IJK_VECTOR_INT_INL_
#endif	// _IJK_VECTOR_INT_H_