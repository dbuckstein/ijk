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

	ijkVector_uuint.inl
	Inline definitions for unsigned 32-bit uinteger vector functions.
*/

#ifdef _IJK_VECTOR_UINT_H_
#ifndef _IJK_VECTOR_UINT_INL_
#define _IJK_VECTOR_UINT_INL_


//-----------------------------------------------------------------------------

ijk_inl ui32 ijkVecAbs1us(ui32 const s)
{
	return ijk_abs_int(s);
}

ijk_inl ui32 ijkVecSgn1us(ui32 const s)
{
	return ijk_sgn_int(s);
}

ijk_inl ui32 ijkVecDot1us(ui32 const s_lh, ui32 const s_rh)
{
	return (s_lh * s_rh);
}

ijk_inl ui32 ijkVecLengthSq1us(ui32 const s)
{
	return (s * s);
}

ijk_inl ui32 ijkVecLength1us(ui32 const s)
{
	return ijk_abs_int(s);
}

ijk_inl ui32 ijkVecLengthSqInv1us(ui32 const s)
{
	ui32 const lengthSq = (s * s);
	//return trecip(lengthSq);
	return 0;
}

ijk_inl ui32 ijkVecLengthInv1us(ui32 const s)
{
	ui32 const length = ijk_abs_int(s);
	//return trecip(length);
	return 0;
}

ijk_inl ui32 ijkVecNormalize1us(ui32 const s)
{
	return ijk_sgn_int(s);
}

ijk_inl ui32 ijkVecNormalizeGetLength1us(ui32 const s, ui32* const length_out)
{
	ui32 const length = *length_out = ijk_abs_int(s);
	return (s / length);
}

ijk_inl ui32 ijkVecNormalizeGetLengthInv1us(ui32 const s, ui32* const lengthInv_out)
{
	ui32 const length = ijk_abs_int(s);
	//*lengthInv_out = trecip(length);
	return ijk_sgn_int(s);
}


//-----------------------------------------------------------------------------

ijk_inl uintv ijkVecPuv(uintv v_out)
{
	return v_out;
}


//-----------------------------------------------------------------------------

ijk_inl uintv ijkVecInit2uv(uint2 v_out)
{
	v_out[0] = v_out[1] = 0;
	return v_out;
}

ijk_inl uintv ijkVecInitElems2uv(uint2 v_out, ui32 const x, ui32 const y)
{
	v_out[0] = x;
	v_out[1] = y;
	return v_out;
}

ijk_inl uintv ijkVecCopy2uv(uint2 v_out, uint2 const v_in)
{
	v_out[0] = +v_in[0];
	v_out[1] = +v_in[1];
	return v_out;
}

#if TSIGNED
ijk_inl uintv ijkVecNegate2uv(uint2 v_out, uint2 const v_in)
{
	v_out[0] = -v_in[0];
	v_out[1] = -v_in[1];
	return v_out;
}
#endif	// TSIGNED

#if TINTEGER
ijk_inl uintv ijkVecBitNot2uv(uint2 v_out, uint2 const v_in)
{
	v_out[0] = ~v_in[0];
	v_out[1] = ~v_in[1];
	return v_out;
}
#endif	// TINTEGER

ijk_inl boolv ijkVecNot2uv(bool2 bv_out, uint2 const v_in)
{
	bv_out[0] = !v_in[0];
	bv_out[1] = !v_in[1];
	return bv_out;
}

ijk_inl uintv ijkVecAdd2uv(uint2 v_out, uint2 const v_lh, uint2 const v_rh)
{
	v_out[0] = v_lh[0] + v_rh[0];
	v_out[1] = v_lh[1] + v_rh[1];
	return v_out;
}

ijk_inl uintv ijkVecSub2uv(uint2 v_out, uint2 const v_lh, uint2 const v_rh)
{
	v_out[0] = v_lh[0] - v_rh[0];
	v_out[1] = v_lh[1] - v_rh[1];
	return v_out;
}

ijk_inl uintv ijkVecMul2uv(uint2 v_out, uint2 const v_lh, uint2 const v_rh)
{
	v_out[0] = v_lh[0] * v_rh[0];
	v_out[1] = v_lh[1] * v_rh[1];
	return v_out;
}

ijk_inl uintv ijkVecDiv2uv(uint2 v_out, uint2 const v_lh, uint2 const v_rh)
{
	v_out[0] = v_lh[0] / v_rh[0];
	v_out[1] = v_lh[1] / v_rh[1];
	return v_out;
}

ijk_inl uintv ijkVecDivSafe2uv(uint2 v_out, uint2 const v_lh, uint2 const v_rh)
{
	v_out[0] = ijk_divide_safe_int(v_lh[0], v_rh[0]);
	v_out[1] = ijk_divide_safe_int(v_lh[1], v_rh[1]);
	return v_out;
}

ijk_inl uintv ijkVecMod2uv(uint2 v_out, uint2 const v_lh, uint2 const v_rh)
{
	v_out[0] = v_lh[0] % v_rh[0];
	v_out[1] = v_lh[1] % v_rh[1];
	return v_out;
}

ijk_inl uintv ijkVecModSafe2uv(uint2 v_out, uint2 const v_lh, uint2 const v_rh)
{
	v_out[0] = ijk_modulo_safe_int(v_lh[0], v_rh[0]);
	v_out[1] = ijk_modulo_safe_int(v_lh[1], v_rh[1]);
	return v_out;
}

#if TINTEGER
ijk_inl uintv ijkVecBitAnd2uv(uint2 v_out, uint2 const v_lh, uint2 const v_rh)
{
	v_out[0] = (v_lh[0] & v_rh[0]);
	v_out[1] = (v_lh[1] & v_rh[1]);
	return v_out;
}

ijk_inl uintv ijkVecBitNand2uv(uint2 v_out, uint2 const v_lh, uint2 const v_rh)
{
	v_out[0] = ~(v_lh[0] & v_rh[0]);
	v_out[1] = ~(v_lh[1] & v_rh[1]);
	return v_out;
}

ijk_inl uintv ijkVecBitOr2uv(uint2 v_out, uint2 const v_lh, uint2 const v_rh)
{
	v_out[0] = (v_lh[0] | v_rh[0]);
	v_out[1] = (v_lh[1] | v_rh[1]);
	return v_out;
}

ijk_inl uintv ijkVecBitNor2uv(uint2 v_out, uint2 const v_lh, uint2 const v_rh)
{
	v_out[0] = ~(v_lh[0] | v_rh[0]);
	v_out[1] = ~(v_lh[1] | v_rh[1]);
	return v_out;
}

ijk_inl uintv ijkVecBitXor2uv(uint2 v_out, uint2 const v_lh, uint2 const v_rh)
{
	v_out[0] = (v_lh[0] ^ v_rh[0]);
	v_out[1] = (v_lh[1] ^ v_rh[1]);
	return v_out;
}

ijk_inl uintv ijkVecBitXnor2uv(uint2 v_out, uint2 const v_lh, uint2 const v_rh)
{
	v_out[0] = ~(v_lh[0] ^ v_rh[0]);
	v_out[1] = ~(v_lh[1] ^ v_rh[1]);
	return v_out;
}

ijk_inl uintv ijkVecBitShiftLeft2uv(uint2 v_out, uint2 const v_lh, uint2 const v_rh)
{
	v_out[0] = (v_lh[0] << v_rh[0]);
	v_out[1] = (v_lh[1] << v_rh[1]);
	return v_out;
}

ijk_inl uintv ijkVecBitShiftRight2uv(uint2 v_out, uint2 const v_lh, uint2 const v_rh)
{
	v_out[0] = (v_lh[0] >> v_rh[0]);
	v_out[1] = (v_lh[1] >> v_rh[1]);
	return v_out;
}
#endif	// TINTEGER

ijk_inl boolv ijkVecEqual2uv(bool2 bv_out, uint2 const v_lh, uint2 const v_rh)
{
	bv_out[0] = (v_lh[0] == v_rh[0]);
	bv_out[1] = (v_lh[1] == v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal2uv(bool2 bv_out, uint2 const v_lh, uint2 const v_rh)
{
	bv_out[0] = (v_lh[0] != v_rh[0]);
	bv_out[1] = (v_lh[1] != v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual2uv(bool2 bv_out, uint2 const v_lh, uint2 const v_rh)
{
	bv_out[0] = (v_lh[0] <= v_rh[0]);
	bv_out[1] = (v_lh[1] <= v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual2uv(bool2 bv_out, uint2 const v_lh, uint2 const v_rh)
{
	bv_out[0] = (v_lh[0] >= v_rh[0]);
	bv_out[1] = (v_lh[1] >= v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecLess2uv(bool2 bv_out, uint2 const v_lh, uint2 const v_rh)
{
	bv_out[0] = (v_lh[0] < v_rh[0]);
	bv_out[1] = (v_lh[1] < v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater2uv(bool2 bv_out, uint2 const v_lh, uint2 const v_rh)
{
	bv_out[0] = (v_lh[0] > v_rh[0]);
	bv_out[1] = (v_lh[1] > v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd2uv(bool2 bv_out, uint2 const v_lh, uint2 const v_rh)
{
	bv_out[0] = (v_lh[0] && v_rh[0]);
	bv_out[1] = (v_lh[1] && v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecNand2uv(bool2 bv_out, uint2 const v_lh, uint2 const v_rh)
{
	bv_out[0] = !(v_lh[0] && v_rh[0]);
	bv_out[1] = !(v_lh[1] && v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecOr2uv(bool2 bv_out, uint2 const v_lh, uint2 const v_rh)
{
	bv_out[0] = (v_lh[0] || v_rh[0]);
	bv_out[1] = (v_lh[1] || v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecNor2uv(bool2 bv_out, uint2 const v_lh, uint2 const v_rh)
{
	bv_out[0] = !(v_lh[0] || v_rh[0]);
	bv_out[1] = !(v_lh[1] || v_rh[1]);
	return bv_out;
}

ijk_inl uintv ijkVecCopy2uvs(uint2 v_out, ui32 const s_in)
{
	v_out[0] = v_out[1] = +s_in;
	return v_out;
}

#if TSIGNED
ijk_inl uintv ijkVecNegate2uvs(uint2 v_out, ui32 const s_in)
{
	v_out[0] = v_out[1] = -s_in;
	return v_out;
}
#endif	// TSIGNED

#if TINTEGER
ijk_inl uintv ijkVecBitNot2uvs(uint2 v_out, ui32 const s_in)
{
	v_out[0] = v_out[1] = ~s_in;
	return v_out;
}
#endif	// TINTEGER

ijk_inl boolv ijkVecNot2uvs(bool2 bv_out, ui32 const s_in)
{
	bv_out[0] = bv_out[1] = !s_in;
	return bv_out;
}

ijk_inl uintv ijkVecAdd2uvs(uint2 v_out, uint2 const v_lh, ui32 const s_rh)
{
	v_out[0] = v_lh[0] + s_rh;
	v_out[1] = v_lh[1] + s_rh;
	return v_out;
}

ijk_inl uintv ijkVecSub2uvs(uint2 v_out, uint2 const v_lh, ui32 const s_rh)
{
	v_out[0] = v_lh[0] - s_rh;
	v_out[1] = v_lh[1] - s_rh;
	return v_out;
}

ijk_inl uintv ijkVecMul2uvs(uint2 v_out, uint2 const v_lh, ui32 const s_rh)
{
	v_out[0] = v_lh[0] * s_rh;
	v_out[1] = v_lh[1] * s_rh;
	return v_out;
}

ijk_inl uintv ijkVecDiv2uvs(uint2 v_out, uint2 const v_lh, ui32 const s_rh)
{
	v_out[0] = v_lh[0] / s_rh;
	v_out[1] = v_lh[1] / s_rh;
	return v_out;
}

ijk_inl uintv ijkVecDivSafe2uvs(uint2 v_out, uint2 const v_lh, ui32 const s_rh)
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

ijk_inl uintv ijkVecMod2uvs(uint2 v_out, uint2 const v_lh, ui32 const s_rh)
{
	v_out[0] = v_lh[0] % s_rh;
	v_out[1] = v_lh[1] % s_rh;
	return v_out;
}

ijk_inl uintv ijkVecModSafe2uvs(uint2 v_out, uint2 const v_lh, ui32 const s_rh)
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

#if TINTEGER
ijk_inl uintv ijkVecBitAnd2uvs(uint2 v_out, uint2 const v_lh, ui32 const s_rh)
{
	v_out[0] = (v_lh[0] & s_rh);
	v_out[1] = (v_lh[1] & s_rh);
	return v_out;
}

ijk_inl uintv ijkVecBitNand2uvs(uint2 v_out, uint2 const v_lh, ui32 const s_rh)
{
	v_out[0] = ~(v_lh[0] & s_rh);
	v_out[1] = ~(v_lh[1] & s_rh);
	return v_out;
}

ijk_inl uintv ijkVecBitOr2uvs(uint2 v_out, uint2 const v_lh, ui32 const s_rh)
{
	v_out[0] = (v_lh[0] | s_rh);
	v_out[1] = (v_lh[1] | s_rh);
	return v_out;
}

ijk_inl uintv ijkVecBitNor2uvs(uint2 v_out, uint2 const v_lh, ui32 const s_rh)
{
	v_out[0] = ~(v_lh[0] | s_rh);
	v_out[1] = ~(v_lh[1] | s_rh);
	return v_out;
}

ijk_inl uintv ijkVecBitXor2uvs(uint2 v_out, uint2 const v_lh, ui32 const s_rh)
{
	v_out[0] = (v_lh[0] ^ s_rh);
	v_out[1] = (v_lh[1] ^ s_rh);
	return v_out;
}

ijk_inl uintv ijkVecBitXnor2uvs(uint2 v_out, uint2 const v_lh, ui32 const s_rh)
{
	v_out[0] = ~(v_lh[0] ^ s_rh);
	v_out[1] = ~(v_lh[1] ^ s_rh);
	return v_out;
}

ijk_inl uintv ijkVecBitShiftLeft2uvs(uint2 v_out, uint2 const v_lh, ui32 const s_rh)
{
	v_out[0] = (v_lh[0] << s_rh);
	v_out[1] = (v_lh[1] << s_rh);
	return v_out;
}

ijk_inl uintv ijkVecBitShiftRight2uvs(uint2 v_out, uint2 const v_lh, ui32 const s_rh)
{
	v_out[0] = (v_lh[0] >> s_rh);
	v_out[1] = (v_lh[1] >> s_rh);
	return v_out;
}
#endif	// TINTEGER

ijk_inl boolv ijkVecEqual2uvs(bool2 bv_out, uint2 const v_lh, ui32 const s_rh)
{
	bv_out[0] = (v_lh[0] == s_rh);
	bv_out[1] = (v_lh[1] == s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecInequal2uvs(bool2 bv_out, uint2 const v_lh, ui32 const s_rh)
{
	bv_out[0] = (v_lh[0] != s_rh);
	bv_out[1] = (v_lh[1] != s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual2uvs(bool2 bv_out, uint2 const v_lh, ui32 const s_rh)
{
	bv_out[0] = (v_lh[0] <= s_rh);
	bv_out[1] = (v_lh[1] <= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual2uvs(bool2 bv_out, uint2 const v_lh, ui32 const s_rh)
{
	bv_out[0] = (v_lh[0] >= s_rh);
	bv_out[1] = (v_lh[1] >= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLess2uvs(bool2 bv_out, uint2 const v_lh, ui32 const s_rh)
{
	bv_out[0] = (v_lh[0] < s_rh);
	bv_out[1] = (v_lh[1] < s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreater2uvs(bool2 bv_out, uint2 const v_lh, ui32 const s_rh)
{
	bv_out[0] = (v_lh[0] > s_rh);
	bv_out[1] = (v_lh[1] > s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecAnd2uvs(bool2 bv_out, uint2 const v_lh, ui32 const s_rh)
{
	bv_out[0] = (v_lh[0] && s_rh);
	bv_out[1] = (v_lh[1] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNand2uvs(bool2 bv_out, uint2 const v_lh, ui32 const s_rh)
{
	bv_out[0] = !(v_lh[0] && s_rh);
	bv_out[1] = !(v_lh[1] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecOr2uvs(bool2 bv_out, uint2 const v_lh, ui32 const s_rh)
{
	bv_out[0] = (v_lh[0] || s_rh);
	bv_out[1] = (v_lh[1] || s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNor2uvs(bool2 bv_out, uint2 const v_lh, ui32 const s_rh)
{
	bv_out[0] = !(v_lh[0] || s_rh);
	bv_out[1] = !(v_lh[1] || s_rh);
	return bv_out;
}

ijk_inl uintv ijkVecAdd2usv(uint2 v_out, ui32 const s_lh, uint2 const v_rh)
{
	v_out[0] = s_lh + v_rh[0];
	v_out[1] = s_lh + v_rh[1];
	return v_out;
}

ijk_inl uintv ijkVecSub2usv(uint2 v_out, ui32 const s_lh, uint2 const v_rh)
{
	v_out[0] = s_lh - v_rh[0];
	v_out[1] = s_lh - v_rh[1];
	return v_out;
}

ijk_inl uintv ijkVecMul2usv(uint2 v_out, ui32 const s_lh, uint2 const v_rh)
{
	v_out[0] = s_lh * v_rh[0];
	v_out[1] = s_lh * v_rh[1];
	return v_out;
}

ijk_inl uintv ijkVecDiv2usv(uint2 v_out, ui32 const s_lh, uint2 const v_rh)
{
	v_out[0] = s_lh / v_rh[0];
	v_out[1] = s_lh / v_rh[1];
	return v_out;
}

ijk_inl uintv ijkVecDivSafe2usv(uint2 v_out, ui32 const s_lh, uint2 const v_rh)
{
	v_out[0] = ijk_divide_safe_int(s_lh, v_rh[0]);
	v_out[1] = ijk_divide_safe_int(s_lh, v_rh[1]);
	return v_out;
}

ijk_inl uintv ijkVecMod2usv(uint2 v_out, ui32 const s_lh, uint2 const v_rh)
{
	v_out[0] = s_lh % v_rh[0];
	v_out[1] = s_lh % v_rh[1];
	return v_out;
}

ijk_inl uintv ijkVecModSafe2usv(uint2 v_out, ui32 const s_lh, uint2 const v_rh)
{
	v_out[0] = ijk_modulo_safe_int(s_lh, v_rh[0]);
	v_out[1] = ijk_modulo_safe_int(s_lh, v_rh[1]);
	return v_out;
}

#if TINTEGER
ijk_inl uintv ijkVecBitAnd2usv(uint2 v_out, ui32 const s_lh, uint2 const v_rh)
{
	v_out[0] = (s_lh & v_rh[0]);
	v_out[1] = (s_lh & v_rh[1]);
	return v_out;
}

ijk_inl uintv ijkVecBitNand2usv(uint2 v_out, ui32 const s_lh, uint2 const v_rh)
{
	v_out[0] = ~(s_lh & v_rh[0]);
	v_out[1] = ~(s_lh & v_rh[1]);
	return v_out;
}

ijk_inl uintv ijkVecBitOr2usv(uint2 v_out, ui32 const s_lh, uint2 const v_rh)
{
	v_out[0] = (s_lh | v_rh[0]);
	v_out[1] = (s_lh | v_rh[1]);
	return v_out;
}

ijk_inl uintv ijkVecBitNor2usv(uint2 v_out, ui32 const s_lh, uint2 const v_rh)
{
	v_out[0] = ~(s_lh | v_rh[0]);
	v_out[1] = ~(s_lh | v_rh[1]);
	return v_out;
}

ijk_inl uintv ijkVecBitXor2usv(uint2 v_out, ui32 const s_lh, uint2 const v_rh)
{
	v_out[0] = (s_lh ^ v_rh[0]);
	v_out[1] = (s_lh ^ v_rh[1]);
	return v_out;
}

ijk_inl uintv ijkVecBitXnor2usv(uint2 v_out, ui32 const s_lh, uint2 const v_rh)
{
	v_out[0] = ~(s_lh ^ v_rh[0]);
	v_out[1] = ~(s_lh ^ v_rh[1]);
	return v_out;
}

ijk_inl uintv ijkVecBitShiftLeft2usv(uint2 v_out, ui32 const s_lh, uint2 const v_rh)
{
	v_out[0] = (s_lh << v_rh[0]);
	v_out[1] = (s_lh << v_rh[1]);
	return v_out;
}

ijk_inl uintv ijkVecBitShiftRight2usv(uint2 v_out, ui32 const s_lh, uint2 const v_rh)
{
	v_out[0] = (s_lh >> v_rh[0]);
	v_out[1] = (s_lh >> v_rh[1]);
	return v_out;
}
#endif	// TINTEGER

ijk_inl boolv ijkVecEqual2usv(bool2 bv_out, ui32 const s_lh, uint2 const v_rh)
{
	bv_out[0] = (s_lh == v_rh[0]);
	bv_out[1] = (s_lh == v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal2usv(bool2 bv_out, ui32 const s_lh, uint2 const v_rh)
{
	bv_out[0] = (s_lh != v_rh[0]);
	bv_out[1] = (s_lh != v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual2usv(bool2 bv_out, ui32 const s_lh, uint2 const v_rh)
{
	bv_out[0] = (s_lh <= v_rh[0]);
	bv_out[1] = (s_lh <= v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual2usv(bool2 bv_out, ui32 const s_lh, uint2 const v_rh)
{
	bv_out[0] = (s_lh >= v_rh[0]);
	bv_out[1] = (s_lh >= v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecLess2usv(bool2 bv_out, ui32 const s_lh, uint2 const v_rh)
{
	bv_out[0] = (s_lh < v_rh[0]);
	bv_out[1] = (s_lh < v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater2usv(bool2 bv_out, ui32 const s_lh, uint2 const v_rh)
{
	bv_out[0] = (s_lh > v_rh[0]);
	bv_out[1] = (s_lh > v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd2usv(bool2 bv_out, ui32 const s_lh, uint2 const v_rh)
{
	bv_out[0] = (s_lh && v_rh[0]);
	bv_out[1] = (s_lh && v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecNand2usv(bool2 bv_out, ui32 const s_lh, uint2 const v_rh)
{
	bv_out[0] = !(s_lh && v_rh[0]);
	bv_out[1] = !(s_lh && v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecOr2usv(bool2 bv_out, ui32 const s_lh, uint2 const v_rh)
{
	bv_out[0] = (s_lh || v_rh[0]);
	bv_out[1] = (s_lh || v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecNor2usv(bool2 bv_out, ui32 const s_lh, uint2 const v_rh)
{
	bv_out[0] = !(s_lh || v_rh[0]);
	bv_out[1] = !(s_lh || v_rh[1]);
	return bv_out;
}

ijk_inl ui32 ijkVecDot2uv(uint2 const v_lh, uint2 const v_rh)
{
	return (v_lh[0] * v_rh[0] + v_lh[1] * v_rh[1]);
}

ijk_inl ui32 ijkVecCross2uv(uint2 const v_lh, uint2 const v_rh)
{
	return (v_lh[0] * v_rh[1] - v_lh[1] * v_rh[0]);
}


//-----------------------------------------------------------------------------

ijk_inl uintv ijkVecInit3uv(uint3 v_out)
{
	v_out[0] = v_out[1] = v_out[2] = 0;
	return v_out;
}

ijk_inl uintv ijkVecInitElems3uv(uint3 v_out, ui32 const x, ui32 const y, ui32 const z)
{
	v_out[0] = x;
	v_out[1] = y;
	v_out[2] = z;
	return v_out;
}

ijk_inl uintv ijkVecCopy3uv(uint3 v_out, uint3 const v_in)
{
	v_out[0] = +v_in[0];
	v_out[1] = +v_in[1];
	v_out[2] = +v_in[2];
	return v_out;
}

#if TSIGNED
ijk_inl uintv ijkVecNegate3uv(uint3 v_out, uint3 const v_in)
{
	v_out[0] = -v_in[0];
	v_out[1] = -v_in[1];
	v_out[2] = -v_in[2];
	return v_out;
}
#endif	// TSIGNED

#if TINTEGER
ijk_inl uintv ijkVecBitNot3uv(uint3 v_out, uint3 const v_in)
{
	v_out[0] = ~v_in[0];
	v_out[1] = ~v_in[1];
	v_out[2] = ~v_in[2];
	return v_out;
}
#endif	// TINTEGER

ijk_inl boolv ijkVecNot3uv(bool3 bv_out, uint3 const v_in)
{
	bv_out[0] = !v_in[0];
	bv_out[1] = !v_in[1];
	bv_out[2] = !v_in[2];
	return bv_out;
}

ijk_inl uintv ijkVecAdd3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh)
{
	v_out[0] = v_lh[0] + v_rh[0];
	v_out[1] = v_lh[1] + v_rh[1];
	v_out[2] = v_lh[2] + v_rh[2];
	return v_out;
}

ijk_inl uintv ijkVecSub3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh)
{
	v_out[0] = v_lh[0] - v_rh[0];
	v_out[1] = v_lh[1] - v_rh[1];
	v_out[2] = v_lh[2] - v_rh[2];
	return v_out;
}

ijk_inl uintv ijkVecMul3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh)
{
	v_out[0] = v_lh[0] * v_rh[0];
	v_out[1] = v_lh[1] * v_rh[1];
	v_out[2] = v_lh[2] * v_rh[2];
	return v_out;
}

ijk_inl uintv ijkVecDiv3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh)
{
	v_out[0] = v_lh[0] / v_rh[0];
	v_out[1] = v_lh[1] / v_rh[1];
	v_out[2] = v_lh[2] / v_rh[2];
	return v_out;
}

ijk_inl uintv ijkVecDivSafe3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh)
{
	v_out[0] = ijk_divide_safe_int(v_lh[0], v_rh[0]);
	v_out[1] = ijk_divide_safe_int(v_lh[1], v_rh[1]);
	v_out[2] = ijk_divide_safe_int(v_lh[2], v_rh[2]);
	return v_out;
}

ijk_inl uintv ijkVecMod3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh)
{
	v_out[0] = v_lh[0] % v_rh[0];
	v_out[1] = v_lh[1] % v_rh[1];
	v_out[2] = v_lh[2] % v_rh[2];
	return v_out;
}

ijk_inl uintv ijkVecModSafe3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh)
{
	v_out[0] = ijk_modulo_safe_int(v_lh[0], v_rh[0]);
	v_out[1] = ijk_modulo_safe_int(v_lh[1], v_rh[1]);
	v_out[2] = ijk_modulo_safe_int(v_lh[2], v_rh[2]);
	return v_out;
}

#if TINTEGER
ijk_inl uintv ijkVecBitAnd3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh)
{
	v_out[0] = (v_lh[0] & v_rh[0]);
	v_out[1] = (v_lh[1] & v_rh[1]);
	v_out[2] = (v_lh[2] & v_rh[2]);
	return v_out;
}

ijk_inl uintv ijkVecBitNand3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh)
{
	v_out[0] = ~(v_lh[0] & v_rh[0]);
	v_out[1] = ~(v_lh[1] & v_rh[1]);
	v_out[2] = ~(v_lh[2] & v_rh[2]);
	return v_out;
}

ijk_inl uintv ijkVecBitOr3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh)
{
	v_out[0] = (v_lh[0] | v_rh[0]);
	v_out[1] = (v_lh[1] | v_rh[1]);
	v_out[2] = (v_lh[2] | v_rh[2]);
	return v_out;
}

ijk_inl uintv ijkVecBitNor3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh)
{
	v_out[0] = ~(v_lh[0] | v_rh[0]);
	v_out[1] = ~(v_lh[1] | v_rh[1]);
	v_out[2] = ~(v_lh[2] | v_rh[2]);
	return v_out;
}

ijk_inl uintv ijkVecBitXor3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh)
{
	v_out[0] = (v_lh[0] ^ v_rh[0]);
	v_out[1] = (v_lh[1] ^ v_rh[1]);
	v_out[2] = (v_lh[2] ^ v_rh[2]);
	return v_out;
}

ijk_inl uintv ijkVecBitXnor3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh)
{
	v_out[0] = ~(v_lh[0] ^ v_rh[0]);
	v_out[1] = ~(v_lh[1] ^ v_rh[1]);
	v_out[2] = ~(v_lh[2] ^ v_rh[2]);
	return v_out;
}

ijk_inl uintv ijkVecBitShiftLeft3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh)
{
	v_out[0] = (v_lh[0] << v_rh[0]);
	v_out[1] = (v_lh[1] << v_rh[1]);
	v_out[2] = (v_lh[2] << v_rh[2]);
	return v_out;
}

ijk_inl uintv ijkVecBitShiftRight3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh)
{
	v_out[0] = (v_lh[0] >> v_rh[0]);
	v_out[1] = (v_lh[1] >> v_rh[1]);
	v_out[2] = (v_lh[2] >> v_rh[2]);
	return v_out;
}
#endif	// TINTEGER

ijk_inl boolv ijkVecEqual3uv(bool3 bv_out, uint3 const v_lh, uint3 const v_rh)
{
	bv_out[0] = (v_lh[0] == v_rh[0]);
	bv_out[1] = (v_lh[1] == v_rh[1]);
	bv_out[2] = (v_lh[2] == v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal3uv(bool3 bv_out, uint3 const v_lh, uint3 const v_rh)
{
	bv_out[0] = (v_lh[0] != v_rh[0]);
	bv_out[1] = (v_lh[1] != v_rh[1]);
	bv_out[2] = (v_lh[2] != v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual3uv(bool3 bv_out, uint3 const v_lh, uint3 const v_rh)
{
	bv_out[0] = (v_lh[0] <= v_rh[0]);
	bv_out[1] = (v_lh[1] <= v_rh[1]);
	bv_out[2] = (v_lh[2] <= v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual3uv(bool3 bv_out, uint3 const v_lh, uint3 const v_rh)
{
	bv_out[0] = (v_lh[0] >= v_rh[0]);
	bv_out[1] = (v_lh[1] >= v_rh[1]);
	bv_out[2] = (v_lh[2] >= v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecLess3uv(bool3 bv_out, uint3 const v_lh, uint3 const v_rh)
{
	bv_out[0] = (v_lh[0] < v_rh[0]);
	bv_out[1] = (v_lh[1] < v_rh[1]);
	bv_out[2] = (v_lh[2] < v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater3uv(bool3 bv_out, uint3 const v_lh, uint3 const v_rh)
{
	bv_out[0] = (v_lh[0] > v_rh[0]);
	bv_out[1] = (v_lh[1] > v_rh[1]);
	bv_out[2] = (v_lh[2] > v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd3uv(bool3 bv_out, uint3 const v_lh, uint3 const v_rh)
{
	bv_out[0] = (v_lh[0] && v_rh[0]);
	bv_out[1] = (v_lh[1] && v_rh[1]);
	bv_out[2] = (v_lh[2] && v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecNand3uv(bool3 bv_out, uint3 const v_lh, uint3 const v_rh)
{
	bv_out[0] = !(v_lh[0] && v_rh[0]);
	bv_out[1] = !(v_lh[1] && v_rh[1]);
	bv_out[2] = !(v_lh[2] && v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecOr3uv(bool3 bv_out, uint3 const v_lh, uint3 const v_rh)
{
	bv_out[0] = (v_lh[0] || v_rh[0]);
	bv_out[1] = (v_lh[1] || v_rh[1]);
	bv_out[2] = (v_lh[2] || v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecNor3uv(bool3 bv_out, uint3 const v_lh, uint3 const v_rh)
{
	bv_out[0] = !(v_lh[0] || v_rh[0]);
	bv_out[1] = !(v_lh[1] || v_rh[1]);
	bv_out[2] = !(v_lh[2] || v_rh[2]);
	return bv_out;
}

ijk_inl uintv ijkVecCopy3uvz(uint3 v_out, uint2 const v_xy, ui32 const z)
{
	v_out[0] = v_xy[0];
	v_out[1] = v_xy[1];
	v_out[2] = z;
	return v_out;
}

ijk_inl uintv ijkVecCopy3uvs(uint3 v_out, ui32 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = +s_in;
	return v_out;
}

#if TSIGNED
ijk_inl uintv ijkVecNegate3uvs(uint3 v_out, ui32 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = -s_in;
	return v_out;
}
#endif	// TSIGNED

#if TINTEGER
ijk_inl uintv ijkVecBitNot3uvs(uint3 v_out, ui32 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = ~s_in;
	return v_out;
}
#endif	// TINTEGER

ijk_inl boolv ijkVecNot3uvs(bool3 bv_out, ui32 const s_in)
{
	bv_out[0] = bv_out[1] = bv_out[2] = !s_in;
	return bv_out;
}

ijk_inl uintv ijkVecAdd3uvs(uint3 v_out, uint3 const v_lh, ui32 const s_rh)
{
	v_out[0] = v_lh[0] + s_rh;
	v_out[1] = v_lh[1] + s_rh;
	v_out[2] = v_lh[2] + s_rh;
	return v_out;
}

ijk_inl uintv ijkVecSub3uvs(uint3 v_out, uint3 const v_lh, ui32 const s_rh)
{
	v_out[0] = v_lh[0] - s_rh;
	v_out[1] = v_lh[1] - s_rh;
	v_out[2] = v_lh[2] - s_rh;
	return v_out;
}

ijk_inl uintv ijkVecMul3uvs(uint3 v_out, uint3 const v_lh, ui32 const s_rh)
{
	v_out[0] = v_lh[0] * s_rh;
	v_out[1] = v_lh[1] * s_rh;
	v_out[2] = v_lh[2] * s_rh;
	return v_out;
}

ijk_inl uintv ijkVecDiv3uvs(uint3 v_out, uint3 const v_lh, ui32 const s_rh)
{
	v_out[0] = v_lh[0] / s_rh;
	v_out[1] = v_lh[1] / s_rh;
	v_out[2] = v_lh[2] / s_rh;
	return v_out;
}

ijk_inl uintv ijkVecDivSafe3uvs(uint3 v_out, uint3 const v_lh, ui32 const s_rh)
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

ijk_inl uintv ijkVecMod3uvs(uint3 v_out, uint3 const v_lh, ui32 const s_rh)
{
	v_out[0] = v_lh[0] % s_rh;
	v_out[1] = v_lh[1] % s_rh;
	v_out[2] = v_lh[2] % s_rh;
	return v_out;
}

ijk_inl uintv ijkVecModSafe3uvs(uint3 v_out, uint3 const v_lh, ui32 const s_rh)
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

#if TINTEGER
ijk_inl uintv ijkVecBitAnd3uvs(uint3 v_out, uint3 const v_lh, ui32 const s_rh)
{
	v_out[0] = (v_lh[0] & s_rh);
	v_out[1] = (v_lh[1] & s_rh);
	v_out[2] = (v_lh[2] & s_rh);
	return v_out;
}

ijk_inl uintv ijkVecBitNand3uvs(uint3 v_out, uint3 const v_lh, ui32 const s_rh)
{
	v_out[0] = ~(v_lh[0] & s_rh);
	v_out[1] = ~(v_lh[1] & s_rh);
	v_out[2] = ~(v_lh[2] & s_rh);
	return v_out;
}

ijk_inl uintv ijkVecBitOr3uvs(uint3 v_out, uint3 const v_lh, ui32 const s_rh)
{
	v_out[0] = (v_lh[0] | s_rh);
	v_out[1] = (v_lh[1] | s_rh);
	v_out[2] = (v_lh[2] | s_rh);
	return v_out;
}

ijk_inl uintv ijkVecBitNor3uvs(uint3 v_out, uint3 const v_lh, ui32 const s_rh)
{
	v_out[0] = ~(v_lh[0] | s_rh);
	v_out[1] = ~(v_lh[1] | s_rh);
	v_out[2] = ~(v_lh[2] | s_rh);
	return v_out;
}

ijk_inl uintv ijkVecBitXor3uvs(uint3 v_out, uint3 const v_lh, ui32 const s_rh)
{
	v_out[0] = (v_lh[0] ^ s_rh);
	v_out[1] = (v_lh[1] ^ s_rh);
	v_out[2] = (v_lh[2] ^ s_rh);
	return v_out;
}

ijk_inl uintv ijkVecBitXnor3uvs(uint3 v_out, uint3 const v_lh, ui32 const s_rh)
{
	v_out[0] = ~(v_lh[0] ^ s_rh);
	v_out[1] = ~(v_lh[1] ^ s_rh);
	v_out[2] = ~(v_lh[2] ^ s_rh);
	return v_out;
}

ijk_inl uintv ijkVecBitShiftLeft3uvs(uint3 v_out, uint3 const v_lh, ui32 const s_rh)
{
	v_out[0] = (v_lh[0] << s_rh);
	v_out[1] = (v_lh[1] << s_rh);
	v_out[2] = (v_lh[2] << s_rh);
	return v_out;
}

ijk_inl uintv ijkVecBitShiftRight3uvs(uint3 v_out, uint3 const v_lh, ui32 const s_rh)
{
	v_out[0] = (v_lh[0] >> s_rh);
	v_out[1] = (v_lh[1] >> s_rh);
	v_out[2] = (v_lh[2] >> s_rh);
	return v_out;
}
#endif	// TINTEGER

ijk_inl boolv ijkVecEqual3uvs(bool3 bv_out, uint3 const v_lh, ui32 const s_rh)
{
	bv_out[0] = (v_lh[0] == s_rh);
	bv_out[1] = (v_lh[1] == s_rh);
	bv_out[2] = (v_lh[2] == s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecInequal3uvs(bool3 bv_out, uint3 const v_lh, ui32 const s_rh)
{
	bv_out[0] = (v_lh[0] != s_rh);
	bv_out[1] = (v_lh[1] != s_rh);
	bv_out[2] = (v_lh[2] != s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual3uvs(bool3 bv_out, uint3 const v_lh, ui32 const s_rh)
{
	bv_out[0] = (v_lh[0] <= s_rh);
	bv_out[1] = (v_lh[1] <= s_rh);
	bv_out[2] = (v_lh[2] <= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual3uvs(bool3 bv_out, uint3 const v_lh, ui32 const s_rh)
{
	bv_out[0] = (v_lh[0] >= s_rh);
	bv_out[1] = (v_lh[1] >= s_rh);
	bv_out[2] = (v_lh[2] >= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLess3uvs(bool3 bv_out, uint3 const v_lh, ui32 const s_rh)
{
	bv_out[0] = (v_lh[0] < s_rh);
	bv_out[1] = (v_lh[1] < s_rh);
	bv_out[2] = (v_lh[2] < s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreater3uvs(bool3 bv_out, uint3 const v_lh, ui32 const s_rh)
{
	bv_out[0] = (v_lh[0] > s_rh);
	bv_out[1] = (v_lh[1] > s_rh);
	bv_out[2] = (v_lh[2] > s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecAnd3uvs(bool3 bv_out, uint3 const v_lh, ui32 const s_rh)
{
	bv_out[0] = (v_lh[0] && s_rh);
	bv_out[1] = (v_lh[1] && s_rh);
	bv_out[2] = (v_lh[2] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNand3uvs(bool3 bv_out, uint3 const v_lh, ui32 const s_rh)
{
	bv_out[0] = !(v_lh[0] && s_rh);
	bv_out[1] = !(v_lh[1] && s_rh);
	bv_out[2] = !(v_lh[2] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecOr3uvs(bool3 bv_out, uint3 const v_lh, ui32 const s_rh)
{
	bv_out[0] = (v_lh[0] || s_rh);
	bv_out[1] = (v_lh[1] || s_rh);
	bv_out[2] = (v_lh[2] || s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNor3uvs(bool3 bv_out, uint3 const v_lh, ui32 const s_rh)
{
	bv_out[0] = !(v_lh[0] || s_rh);
	bv_out[1] = !(v_lh[1] || s_rh);
	bv_out[2] = !(v_lh[2] || s_rh);
	return bv_out;
}

ijk_inl uintv ijkVecCopy3uxv(uint3 v_out, ui32 const x, uint2 const v_yz)
{
	v_out[0] = x;
	v_out[1] = v_yz[0];
	v_out[2] = v_yz[1];
	return v_out;
}

ijk_inl uintv ijkVecAdd3usv(uint3 v_out, ui32 const s_lh, uint3 const v_rh)
{
	v_out[0] = s_lh + v_rh[0];
	v_out[1] = s_lh + v_rh[1];
	v_out[2] = s_lh + v_rh[2];
	return v_out;
}

ijk_inl uintv ijkVecSub3usv(uint3 v_out, ui32 const s_lh, uint3 const v_rh)
{
	v_out[0] = s_lh - v_rh[0];
	v_out[1] = s_lh - v_rh[1];
	v_out[2] = s_lh - v_rh[2];
	return v_out;
}

ijk_inl uintv ijkVecMul3usv(uint3 v_out, ui32 const s_lh, uint3 const v_rh)
{
	v_out[0] = s_lh * v_rh[0];
	v_out[1] = s_lh * v_rh[1];
	v_out[2] = s_lh * v_rh[2];
	return v_out;
}

ijk_inl uintv ijkVecDiv3usv(uint3 v_out, ui32 const s_lh, uint3 const v_rh)
{
	v_out[0] = s_lh / v_rh[0];
	v_out[1] = s_lh / v_rh[1];
	v_out[2] = s_lh / v_rh[2];
	return v_out;
}

ijk_inl uintv ijkVecDivSafe3usv(uint3 v_out, ui32 const s_lh, uint3 const v_rh)
{
	v_out[0] = ijk_divide_safe_int(s_lh, v_rh[0]);
	v_out[1] = ijk_divide_safe_int(s_lh, v_rh[1]);
	v_out[2] = ijk_divide_safe_int(s_lh, v_rh[2]);
	return v_out;
}

ijk_inl uintv ijkVecMod3usv(uint3 v_out, ui32 const s_lh, uint3 const v_rh)
{
	v_out[0] = s_lh % v_rh[0];
	v_out[1] = s_lh % v_rh[1];
	v_out[2] = s_lh % v_rh[2];
	return v_out;
}

ijk_inl uintv ijkVecModSafe3usv(uint3 v_out, ui32 const s_lh, uint3 const v_rh)
{
	v_out[0] = ijk_modulo_safe_int(s_lh, v_rh[0]);
	v_out[1] = ijk_modulo_safe_int(s_lh, v_rh[1]);
	v_out[2] = ijk_modulo_safe_int(s_lh, v_rh[2]);
	return v_out;
}

#if TINTEGER
ijk_inl uintv ijkVecBitAnd3usv(uint3 v_out, ui32 const s_lh, uint3 const v_rh)
{
	v_out[0] = (s_lh & v_rh[0]);
	v_out[1] = (s_lh & v_rh[1]);
	v_out[2] = (s_lh & v_rh[2]);
	return v_out;
}

ijk_inl uintv ijkVecBitNand3usv(uint3 v_out, ui32 const s_lh, uint3 const v_rh)
{
	v_out[0] = ~(s_lh & v_rh[0]);
	v_out[1] = ~(s_lh & v_rh[1]);
	v_out[2] = ~(s_lh & v_rh[2]);
	return v_out;
}

ijk_inl uintv ijkVecBitOr3usv(uint3 v_out, ui32 const s_lh, uint3 const v_rh)
{
	v_out[0] = (s_lh | v_rh[0]);
	v_out[1] = (s_lh | v_rh[1]);
	v_out[2] = (s_lh | v_rh[2]);
	return v_out;
}

ijk_inl uintv ijkVecBitNor3usv(uint3 v_out, ui32 const s_lh, uint3 const v_rh)
{
	v_out[0] = ~(s_lh | v_rh[0]);
	v_out[1] = ~(s_lh | v_rh[1]);
	v_out[2] = ~(s_lh | v_rh[2]);
	return v_out;
}

ijk_inl uintv ijkVecBitXor3usv(uint3 v_out, ui32 const s_lh, uint3 const v_rh)
{
	v_out[0] = (s_lh ^ v_rh[0]);
	v_out[1] = (s_lh ^ v_rh[1]);
	v_out[2] = (s_lh ^ v_rh[2]);
	return v_out;
}

ijk_inl uintv ijkVecBitXnor3usv(uint3 v_out, ui32 const s_lh, uint3 const v_rh)
{
	v_out[0] = ~(s_lh ^ v_rh[0]);
	v_out[1] = ~(s_lh ^ v_rh[1]);
	v_out[2] = ~(s_lh ^ v_rh[2]);
	return v_out;
}

ijk_inl uintv ijkVecBitShiftLeft3usv(uint3 v_out, ui32 const s_lh, uint3 const v_rh)
{
	v_out[0] = (s_lh << v_rh[0]);
	v_out[1] = (s_lh << v_rh[1]);
	v_out[2] = (s_lh << v_rh[2]);
	return v_out;
}

ijk_inl uintv ijkVecBitShiftRight3usv(uint3 v_out, ui32 const s_lh, uint3 const v_rh)
{
	v_out[0] = (s_lh >> v_rh[0]);
	v_out[1] = (s_lh >> v_rh[1]);
	v_out[2] = (s_lh >> v_rh[2]);
	return v_out;
}
#endif	// TINTEGER

ijk_inl boolv ijkVecEqual3usv(bool3 bv_out, ui32 const s_lh, uint3 const v_rh)
{
	bv_out[0] = (s_lh == v_rh[0]);
	bv_out[1] = (s_lh == v_rh[1]);
	bv_out[2] = (s_lh == v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal3usv(bool3 bv_out, ui32 const s_lh, uint3 const v_rh)
{
	bv_out[0] = (s_lh != v_rh[0]);
	bv_out[1] = (s_lh != v_rh[1]);
	bv_out[2] = (s_lh != v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual3usv(bool3 bv_out, ui32 const s_lh, uint3 const v_rh)
{
	bv_out[0] = (s_lh <= v_rh[0]);
	bv_out[1] = (s_lh <= v_rh[1]);
	bv_out[2] = (s_lh <= v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual3usv(bool3 bv_out, ui32 const s_lh, uint3 const v_rh)
{
	bv_out[0] = (s_lh >= v_rh[0]);
	bv_out[1] = (s_lh >= v_rh[1]);
	bv_out[2] = (s_lh >= v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecLess3usv(bool3 bv_out, ui32 const s_lh, uint3 const v_rh)
{
	bv_out[0] = (s_lh < v_rh[0]);
	bv_out[1] = (s_lh < v_rh[1]);
	bv_out[2] = (s_lh < v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater3usv(bool3 bv_out, ui32 const s_lh, uint3 const v_rh)
{
	bv_out[0] = (s_lh > v_rh[0]);
	bv_out[1] = (s_lh > v_rh[1]);
	bv_out[2] = (s_lh > v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd3usv(bool3 bv_out, ui32 const s_lh, uint3 const v_rh)
{
	bv_out[0] = (s_lh && v_rh[0]);
	bv_out[1] = (s_lh && v_rh[1]);
	bv_out[2] = (s_lh && v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecNand3usv(bool3 bv_out, ui32 const s_lh, uint3 const v_rh)
{
	bv_out[0] = !(s_lh && v_rh[0]);
	bv_out[1] = !(s_lh && v_rh[1]);
	bv_out[2] = !(s_lh && v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecOr3usv(bool3 bv_out, ui32 const s_lh, uint3 const v_rh)
{
	bv_out[0] = (s_lh || v_rh[0]);
	bv_out[1] = (s_lh || v_rh[1]);
	bv_out[2] = (s_lh || v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecNor3usv(bool3 bv_out, ui32 const s_lh, uint3 const v_rh)
{
	bv_out[0] = !(s_lh || v_rh[0]);
	bv_out[1] = !(s_lh || v_rh[1]);
	bv_out[2] = !(s_lh || v_rh[2]);
	return bv_out;
}

ijk_inl ui32 ijkVecDot3uv(uint3 const v_lh, uint3 const v_rh)
{
	return (v_lh[0] * v_rh[0] + v_lh[1] * v_rh[1] + v_lh[2] * v_rh[2]);
}

ijk_inl uintv ijkVecCross3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh)
{
	v_out[0] = (v_lh[1] * v_rh[2] - v_lh[2] * v_rh[1]);
	v_out[1] = (v_lh[2] * v_rh[0] - v_lh[0] * v_rh[2]);
	v_out[2] = (v_lh[0] * v_rh[1] - v_lh[1] * v_rh[0]);
	return v_out;
}


//-----------------------------------------------------------------------------

ijk_inl uintv ijkVecInit4uv(uint4 v_out)
{
	v_out[0] = v_out[1] = v_out[2] = v_out[3] = 0;
	return v_out;
}

ijk_inl uintv ijkVecInitElems4uv(uint4 v_out, ui32 const x, ui32 const y, ui32 const z, ui32 const w)
{
	v_out[0] = x;
	v_out[1] = y;
	v_out[2] = z;
	v_out[3] = w;
	return v_out;
}

ijk_inl uintv ijkVecCopy4uxvw(uint4 v_out, ui32 const x, uint2 const v_yz, ui32 const w)
{
	v_out[0] = x;
	v_out[1] = v_yz[0];
	v_out[2] = v_yz[1];
	v_out[3] = w;
	return v_out;
}

ijk_inl uintv ijkVecCopy4uv2(uint4 v_out, uint2 const v_xy, uint2 const v_zw)
{
	v_out[0] = v_xy[0];
	v_out[1] = v_xy[1];
	v_out[2] = v_zw[0];
	v_out[3] = v_zw[1];
	return v_out;
}

ijk_inl uintv ijkVecCopy4uv(uint4 v_out, uint4 const v_in)
{
	v_out[0] = +v_in[0];
	v_out[1] = +v_in[1];
	v_out[2] = +v_in[2];
	v_out[3] = +v_in[3];
	return v_out;
}

#if TSIGNED
ijk_inl uintv ijkVecNegate4uv(uint4 v_out, uint4 const v_in)
{
	v_out[0] = -v_in[0];
	v_out[1] = -v_in[1];
	v_out[2] = -v_in[2];
	v_out[3] = -v_in[3];
	return v_out;
}
#endif	// TSIGNED

#if TINTEGER
ijk_inl uintv ijkVecBitNot4uv(uint4 v_out, uint4 const v_in)
{
	v_out[0] = ~v_in[0];
	v_out[1] = ~v_in[1];
	v_out[2] = ~v_in[2];
	v_out[3] = ~v_in[3];
	return v_out;
}
#endif	// TINTEGER

ijk_inl boolv ijkVecNot4uv(bool4 bv_out, uint4 const v_in)
{
	bv_out[0] = !v_in[0];
	bv_out[1] = !v_in[1];
	bv_out[2] = !v_in[2];
	bv_out[3] = !v_in[3];
	return bv_out;
}

ijk_inl uintv ijkVecAdd4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh)
{
	v_out[0] = v_lh[0] + v_rh[0];
	v_out[1] = v_lh[1] + v_rh[1];
	v_out[2] = v_lh[2] + v_rh[2];
	v_out[3] = v_lh[3] + v_rh[3];
	return v_out;
}

ijk_inl uintv ijkVecSub4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh)
{
	v_out[0] = v_lh[0] - v_rh[0];
	v_out[1] = v_lh[1] - v_rh[1];
	v_out[2] = v_lh[2] - v_rh[2];
	v_out[3] = v_lh[3] - v_rh[3];
	return v_out;
}

ijk_inl uintv ijkVecMul4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh)
{
	v_out[0] = v_lh[0] * v_rh[0];
	v_out[1] = v_lh[1] * v_rh[1];
	v_out[2] = v_lh[2] * v_rh[2];
	v_out[3] = v_lh[3] * v_rh[3];
	return v_out;
}

ijk_inl uintv ijkVecDiv4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh)
{
	v_out[0] = v_lh[0] / v_rh[0];
	v_out[1] = v_lh[1] / v_rh[1];
	v_out[2] = v_lh[2] / v_rh[2];
	v_out[3] = v_lh[3] / v_rh[3];
	return v_out;
}

ijk_inl uintv ijkVecDivSafe4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh)
{
	v_out[0] = ijk_divide_safe_int(v_lh[0], v_rh[0]);
	v_out[1] = ijk_divide_safe_int(v_lh[1], v_rh[1]);
	v_out[2] = ijk_divide_safe_int(v_lh[2], v_rh[2]);
	v_out[3] = ijk_divide_safe_int(v_lh[3], v_rh[3]);
	return v_out;
}

ijk_inl uintv ijkVecMod4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh)
{
	v_out[0] = v_lh[0] % v_rh[0];
	v_out[1] = v_lh[1] % v_rh[1];
	v_out[2] = v_lh[2] % v_rh[2];
	v_out[3] = v_lh[3] % v_rh[3];
	return v_out;
}

ijk_inl uintv ijkVecModSafe4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh)
{
	v_out[0] = ijk_modulo_safe_int(v_lh[0], v_rh[0]);
	v_out[1] = ijk_modulo_safe_int(v_lh[1], v_rh[1]);
	v_out[2] = ijk_modulo_safe_int(v_lh[2], v_rh[2]);
	v_out[3] = ijk_modulo_safe_int(v_lh[3], v_rh[3]);
	return v_out;
}

#if TINTEGER
ijk_inl uintv ijkVecBitAnd4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh)
{
	v_out[0] = (v_lh[0] & v_rh[0]);
	v_out[1] = (v_lh[1] & v_rh[1]);
	v_out[2] = (v_lh[2] & v_rh[2]);
	v_out[3] = (v_lh[3] & v_rh[3]);
	return v_out;
}

ijk_inl uintv ijkVecBitNand4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh)
{
	v_out[0] = ~(v_lh[0] & v_rh[0]);
	v_out[1] = ~(v_lh[1] & v_rh[1]);
	v_out[2] = ~(v_lh[2] & v_rh[2]);
	v_out[3] = ~(v_lh[3] & v_rh[3]);
	return v_out;
}

ijk_inl uintv ijkVecBitOr4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh)
{
	v_out[0] = (v_lh[0] | v_rh[0]);
	v_out[1] = (v_lh[1] | v_rh[1]);
	v_out[2] = (v_lh[2] | v_rh[2]);
	v_out[3] = (v_lh[3] | v_rh[3]);
	return v_out;
}

ijk_inl uintv ijkVecBitNor4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh)
{
	v_out[0] = ~(v_lh[0] | v_rh[0]);
	v_out[1] = ~(v_lh[1] | v_rh[1]);
	v_out[2] = ~(v_lh[2] | v_rh[2]);
	v_out[3] = ~(v_lh[3] | v_rh[3]);
	return v_out;
}

ijk_inl uintv ijkVecBitXor4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh)
{
	v_out[0] = (v_lh[0] ^ v_rh[0]);
	v_out[1] = (v_lh[1] ^ v_rh[1]);
	v_out[2] = (v_lh[2] ^ v_rh[2]);
	v_out[3] = (v_lh[3] ^ v_rh[3]);
	return v_out;
}

ijk_inl uintv ijkVecBitXnor4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh)
{
	v_out[0] = ~(v_lh[0] ^ v_rh[0]);
	v_out[1] = ~(v_lh[1] ^ v_rh[1]);
	v_out[2] = ~(v_lh[2] ^ v_rh[2]);
	v_out[3] = ~(v_lh[3] ^ v_rh[3]);
	return v_out;
}

ijk_inl uintv ijkVecBitShiftLeft4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh)
{
	v_out[0] = (v_lh[0] << v_rh[0]);
	v_out[1] = (v_lh[1] << v_rh[1]);
	v_out[2] = (v_lh[2] << v_rh[2]);
	v_out[3] = (v_lh[3] << v_rh[3]);
	return v_out;
}

ijk_inl uintv ijkVecBitShiftRight4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh)
{
	v_out[0] = (v_lh[0] >> v_rh[0]);
	v_out[1] = (v_lh[1] >> v_rh[1]);
	v_out[2] = (v_lh[2] >> v_rh[2]);
	v_out[3] = (v_lh[3] >> v_rh[3]);
	return v_out;
}
#endif	// TINTEGER

ijk_inl boolv ijkVecEqual4uv(bool4 bv_out, uint4 const v_lh, uint4 const v_rh)
{
	bv_out[0] = (v_lh[0] == v_rh[0]);
	bv_out[1] = (v_lh[1] == v_rh[1]);
	bv_out[2] = (v_lh[2] == v_rh[2]);
	bv_out[3] = (v_lh[3] == v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal4uv(bool4 bv_out, uint4 const v_lh, uint4 const v_rh)
{
	bv_out[0] = (v_lh[0] != v_rh[0]);
	bv_out[1] = (v_lh[1] != v_rh[1]);
	bv_out[2] = (v_lh[2] != v_rh[2]);
	bv_out[3] = (v_lh[3] != v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual4uv(bool4 bv_out, uint4 const v_lh, uint4 const v_rh)
{
	bv_out[0] = (v_lh[0] <= v_rh[0]);
	bv_out[1] = (v_lh[1] <= v_rh[1]);
	bv_out[2] = (v_lh[2] <= v_rh[2]);
	bv_out[3] = (v_lh[3] <= v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual4uv(bool4 bv_out, uint4 const v_lh, uint4 const v_rh)
{
	bv_out[0] = (v_lh[0] >= v_rh[0]);
	bv_out[1] = (v_lh[1] >= v_rh[1]);
	bv_out[2] = (v_lh[2] >= v_rh[2]);
	bv_out[3] = (v_lh[3] >= v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecLess4uv(bool4 bv_out, uint4 const v_lh, uint4 const v_rh)
{
	bv_out[0] = (v_lh[0] < v_rh[0]);
	bv_out[1] = (v_lh[1] < v_rh[1]);
	bv_out[2] = (v_lh[2] < v_rh[2]);
	bv_out[3] = (v_lh[3] < v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater4uv(bool4 bv_out, uint4 const v_lh, uint4 const v_rh)
{
	bv_out[0] = (v_lh[0] > v_rh[0]);
	bv_out[1] = (v_lh[1] > v_rh[1]);
	bv_out[2] = (v_lh[2] > v_rh[2]);
	bv_out[3] = (v_lh[3] > v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd4uv(bool4 bv_out, uint4 const v_lh, uint4 const v_rh)
{
	bv_out[0] = (v_lh[0] && v_rh[0]);
	bv_out[1] = (v_lh[1] && v_rh[1]);
	bv_out[2] = (v_lh[2] && v_rh[2]);
	bv_out[3] = (v_lh[3] && v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecNand4uv(bool4 bv_out, uint4 const v_lh, uint4 const v_rh)
{
	bv_out[0] = !(v_lh[0] && v_rh[0]);
	bv_out[1] = !(v_lh[1] && v_rh[1]);
	bv_out[2] = !(v_lh[2] && v_rh[2]);
	bv_out[3] = !(v_lh[3] && v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecOr4uv(bool4 bv_out, uint4 const v_lh, uint4 const v_rh)
{
	bv_out[0] = (v_lh[0] || v_rh[0]);
	bv_out[1] = (v_lh[1] || v_rh[1]);
	bv_out[2] = (v_lh[2] || v_rh[2]);
	bv_out[3] = (v_lh[3] || v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecNor4uv(bool4 bv_out, uint4 const v_lh, uint4 const v_rh)
{
	bv_out[0] = !(v_lh[0] || v_rh[0]);
	bv_out[1] = !(v_lh[1] || v_rh[1]);
	bv_out[2] = !(v_lh[2] || v_rh[2]);
	bv_out[3] = !(v_lh[3] || v_rh[3]);
	return bv_out;
}

ijk_inl uintv ijkVecCopy4uvzw(uint4 v_out, uint2 const v_xy, ui32 const z, ui32 const w)
{
	v_out[0] = v_xy[0];
	v_out[1] = v_xy[1];
	v_out[2] = z;
	v_out[3] = w;
	return v_out;
}

ijk_inl uintv ijkVecCopy4uvw(uint4 v_out, uint3 const v_xyz, ui32 const w)
{
	v_out[0] = v_xyz[0];
	v_out[1] = v_xyz[1];
	v_out[2] = v_xyz[2];
	v_out[3] = w;
	return v_out;
}

ijk_inl uintv ijkVecCopy4uvs(uint4 v_out, ui32 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = v_out[3] = +s_in;
	return v_out;
}

#if TSIGNED
ijk_inl uintv ijkVecNegate4uvs(uint4 v_out, ui32 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = v_out[3] = -s_in;
	return v_out;
}
#endif	// TSIGNED

#if TINTEGER
ijk_inl uintv ijkVecBitNot4uvs(uint4 v_out, ui32 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = v_out[3] = ~s_in;
	return v_out;
}
#endif	// TINTEGER

ijk_inl boolv ijkVecNot4uvs(bool4 bv_out, ui32 const s_in)
{
	bv_out[0] = bv_out[1] = bv_out[2] = bv_out[3] = !s_in;
	return bv_out;
}

ijk_inl uintv ijkVecAdd4uvs(uint4 v_out, uint4 const v_lh, ui32 const s_rh)
{
	v_out[0] = v_lh[0] + s_rh;
	v_out[1] = v_lh[1] + s_rh;
	v_out[2] = v_lh[2] + s_rh;
	v_out[3] = v_lh[3] + s_rh;
	return v_out;
}

ijk_inl uintv ijkVecSub4uvs(uint4 v_out, uint4 const v_lh, ui32 const s_rh)
{
	v_out[0] = v_lh[0] - s_rh;
	v_out[1] = v_lh[1] - s_rh;
	v_out[2] = v_lh[2] - s_rh;
	v_out[3] = v_lh[3] - s_rh;
	return v_out;
}

ijk_inl uintv ijkVecMul4uvs(uint4 v_out, uint4 const v_lh, ui32 const s_rh)
{
	v_out[0] = v_lh[0] * s_rh;
	v_out[1] = v_lh[1] * s_rh;
	v_out[2] = v_lh[2] * s_rh;
	v_out[3] = v_lh[3] * s_rh;
	return v_out;
}

ijk_inl uintv ijkVecDiv4uvs(uint4 v_out, uint4 const v_lh, ui32 const s_rh)
{
	v_out[0] = v_lh[0] / s_rh;
	v_out[1] = v_lh[1] / s_rh;
	v_out[2] = v_lh[2] / s_rh;
	v_out[3] = v_lh[3] / s_rh;
	return v_out;
}

ijk_inl uintv ijkVecDivSafe4uvs(uint4 v_out, uint4 const v_lh, ui32 const s_rh)
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

ijk_inl uintv ijkVecMod4uvs(uint4 v_out, uint4 const v_lh, ui32 const s_rh)
{
	v_out[0] = v_lh[0] % s_rh;
	v_out[1] = v_lh[1] % s_rh;
	v_out[2] = v_lh[2] % s_rh;
	v_out[3] = v_lh[3] % s_rh;
	return v_out;
}

ijk_inl uintv ijkVecModSafe4uvs(uint4 v_out, uint4 const v_lh, ui32 const s_rh)
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

#if TINTEGER
ijk_inl uintv ijkVecBitAnd4uvs(uint4 v_out, uint4 const v_lh, ui32 const s_rh)
{
	v_out[0] = (v_lh[0] & s_rh);
	v_out[1] = (v_lh[1] & s_rh);
	v_out[2] = (v_lh[2] & s_rh);
	v_out[3] = (v_lh[3] & s_rh);
	return v_out;
}

ijk_inl uintv ijkVecBitNand4uvs(uint4 v_out, uint4 const v_lh, ui32 const s_rh)
{
	v_out[0] = ~(v_lh[0] & s_rh);
	v_out[1] = ~(v_lh[1] & s_rh);
	v_out[2] = ~(v_lh[2] & s_rh);
	v_out[3] = ~(v_lh[3] & s_rh);
	return v_out;
}

ijk_inl uintv ijkVecBitOr4uvs(uint4 v_out, uint4 const v_lh, ui32 const s_rh)
{
	v_out[0] = (v_lh[0] | s_rh);
	v_out[1] = (v_lh[1] | s_rh);
	v_out[2] = (v_lh[2] | s_rh);
	v_out[3] = (v_lh[3] | s_rh);
	return v_out;
}

ijk_inl uintv ijkVecBitNor4uvs(uint4 v_out, uint4 const v_lh, ui32 const s_rh)
{
	v_out[0] = ~(v_lh[0] | s_rh);
	v_out[1] = ~(v_lh[1] | s_rh);
	v_out[2] = ~(v_lh[2] | s_rh);
	v_out[3] = ~(v_lh[3] | s_rh);
	return v_out;
}

ijk_inl uintv ijkVecBitXor4uvs(uint4 v_out, uint4 const v_lh, ui32 const s_rh)
{
	v_out[0] = (v_lh[0] ^ s_rh);
	v_out[1] = (v_lh[1] ^ s_rh);
	v_out[2] = (v_lh[2] ^ s_rh);
	v_out[3] = (v_lh[3] ^ s_rh);
	return v_out;
}

ijk_inl uintv ijkVecBitXnor4uvs(uint4 v_out, uint4 const v_lh, ui32 const s_rh)
{
	v_out[0] = ~(v_lh[0] ^ s_rh);
	v_out[1] = ~(v_lh[1] ^ s_rh);
	v_out[2] = ~(v_lh[2] ^ s_rh);
	v_out[3] = ~(v_lh[3] ^ s_rh);
	return v_out;
}

ijk_inl uintv ijkVecBitShiftLeft4uvs(uint4 v_out, uint4 const v_lh, ui32 const s_rh)
{
	v_out[0] = (v_lh[0] << s_rh);
	v_out[1] = (v_lh[1] << s_rh);
	v_out[2] = (v_lh[2] << s_rh);
	v_out[3] = (v_lh[3] << s_rh);
	return v_out;
}

ijk_inl uintv ijkVecBitShiftRight4uvs(uint4 v_out, uint4 const v_lh, ui32 const s_rh)
{
	v_out[0] = (v_lh[0] >> s_rh);
	v_out[1] = (v_lh[1] >> s_rh);
	v_out[2] = (v_lh[2] >> s_rh);
	v_out[3] = (v_lh[3] >> s_rh);
	return v_out;
}
#endif	// TINTEGER

ijk_inl boolv ijkVecEqual4uvs(bool4 bv_out, uint4 const v_lh, ui32 const s_rh)
{
	bv_out[0] = (v_lh[0] == s_rh);
	bv_out[1] = (v_lh[1] == s_rh);
	bv_out[2] = (v_lh[2] == s_rh);
	bv_out[3] = (v_lh[3] == s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecInequal4uvs(bool4 bv_out, uint4 const v_lh, ui32 const s_rh)
{
	bv_out[0] = (v_lh[0] != s_rh);
	bv_out[1] = (v_lh[1] != s_rh);
	bv_out[2] = (v_lh[2] != s_rh);
	bv_out[3] = (v_lh[3] != s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual4uvs(bool4 bv_out, uint4 const v_lh, ui32 const s_rh)
{
	bv_out[0] = (v_lh[0] <= s_rh);
	bv_out[1] = (v_lh[1] <= s_rh);
	bv_out[2] = (v_lh[2] <= s_rh);
	bv_out[3] = (v_lh[3] <= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual4uvs(bool4 bv_out, uint4 const v_lh, ui32 const s_rh)
{
	bv_out[0] = (v_lh[0] >= s_rh);
	bv_out[1] = (v_lh[1] >= s_rh);
	bv_out[2] = (v_lh[2] >= s_rh);
	bv_out[3] = (v_lh[3] >= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLess4uvs(bool4 bv_out, uint4 const v_lh, ui32 const s_rh)
{
	bv_out[0] = (v_lh[0] < s_rh);
	bv_out[1] = (v_lh[1] < s_rh);
	bv_out[2] = (v_lh[2] < s_rh);
	bv_out[3] = (v_lh[3] < s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreater4uvs(bool4 bv_out, uint4 const v_lh, ui32 const s_rh)
{
	bv_out[0] = (v_lh[0] > s_rh);
	bv_out[1] = (v_lh[1] > s_rh);
	bv_out[2] = (v_lh[2] > s_rh);
	bv_out[3] = (v_lh[3] > s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecAnd4uvs(bool4 bv_out, uint4 const v_lh, ui32 const s_rh)
{
	bv_out[0] = (v_lh[0] && s_rh);
	bv_out[1] = (v_lh[1] && s_rh);
	bv_out[2] = (v_lh[2] && s_rh);
	bv_out[3] = (v_lh[3] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNand4uvs(bool4 bv_out, uint4 const v_lh, ui32 const s_rh)
{
	bv_out[0] = !(v_lh[0] && s_rh);
	bv_out[1] = !(v_lh[1] && s_rh);
	bv_out[2] = !(v_lh[2] && s_rh);
	bv_out[3] = !(v_lh[3] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecOr4uvs(bool4 bv_out, uint4 const v_lh, ui32 const s_rh)
{
	bv_out[0] = (v_lh[0] || s_rh);
	bv_out[1] = (v_lh[1] || s_rh);
	bv_out[2] = (v_lh[2] || s_rh);
	bv_out[3] = (v_lh[3] || s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNor4uvs(bool4 bv_out, uint4 const v_lh, ui32 const s_rh)
{
	bv_out[0] = !(v_lh[0] || s_rh);
	bv_out[1] = !(v_lh[1] || s_rh);
	bv_out[2] = !(v_lh[2] || s_rh);
	bv_out[3] = !(v_lh[3] || s_rh);
	return bv_out;
}

ijk_inl uintv ijkVecCopy4uxyv(uint4 v_out, ui32 const x, ui32 const y, uint2 const v_zw)
{
	v_out[0] = x;
	v_out[1] = y;
	v_out[2] = v_zw[0];
	v_out[3] = v_zw[1];
	return v_out;
}

ijk_inl uintv ijkVecCopy4uxv(uint4 v_out, ui32 const x, uint3 const v_yzw)
{
	v_out[0] = x;
	v_out[1] = v_yzw[0];
	v_out[2] = v_yzw[1];
	v_out[3] = v_yzw[2];
	return v_out;
}

ijk_inl uintv ijkVecAdd4usv(uint4 v_out, ui32 const s_lh, uint4 const v_rh)
{
	v_out[0] = s_lh + v_rh[0];
	v_out[1] = s_lh + v_rh[1];
	v_out[2] = s_lh + v_rh[2];
	v_out[3] = s_lh + v_rh[3];
	return v_out;
}

ijk_inl uintv ijkVecSub4usv(uint4 v_out, ui32 const s_lh, uint4 const v_rh)
{
	v_out[0] = s_lh - v_rh[0];
	v_out[1] = s_lh - v_rh[1];
	v_out[2] = s_lh - v_rh[2];
	v_out[3] = s_lh - v_rh[3];
	return v_out;
}

ijk_inl uintv ijkVecMul4usv(uint4 v_out, ui32 const s_lh, uint4 const v_rh)
{
	v_out[0] = s_lh * v_rh[0];
	v_out[1] = s_lh * v_rh[1];
	v_out[2] = s_lh * v_rh[2];
	v_out[3] = s_lh * v_rh[3];
	return v_out;
}

ijk_inl uintv ijkVecDiv4usv(uint4 v_out, ui32 const s_lh, uint4 const v_rh)
{
	v_out[0] = s_lh / v_rh[0];
	v_out[1] = s_lh / v_rh[1];
	v_out[2] = s_lh / v_rh[2];
	v_out[3] = s_lh / v_rh[3];
	return v_out;
}

ijk_inl uintv ijkVecDivSafe4usv(uint4 v_out, ui32 const s_lh, uint4 const v_rh)
{
	v_out[0] = ijk_divide_safe_int(s_lh, v_rh[0]);
	v_out[1] = ijk_divide_safe_int(s_lh, v_rh[1]);
	v_out[2] = ijk_divide_safe_int(s_lh, v_rh[2]);
	v_out[3] = ijk_divide_safe_int(s_lh, v_rh[3]);
	return v_out;
}

ijk_inl uintv ijkVecMod4usv(uint4 v_out, ui32 const s_lh, uint4 const v_rh)
{
	v_out[0] = s_lh % v_rh[0];
	v_out[1] = s_lh % v_rh[1];
	v_out[2] = s_lh % v_rh[2];
	v_out[3] = s_lh % v_rh[3];
	return v_out;
}

ijk_inl uintv ijkVecModSafe4usv(uint4 v_out, ui32 const s_lh, uint4 const v_rh)
{
	v_out[0] = ijk_modulo_safe_int(s_lh, v_rh[0]);
	v_out[1] = ijk_modulo_safe_int(s_lh, v_rh[1]);
	v_out[2] = ijk_modulo_safe_int(s_lh, v_rh[2]);
	v_out[3] = ijk_modulo_safe_int(s_lh, v_rh[3]);
	return v_out;
}

#if TINTEGER
ijk_inl uintv ijkVecBitAnd4usv(uint4 v_out, ui32 const s_lh, uint4 const v_rh)
{
	v_out[0] = (s_lh & v_rh[0]);
	v_out[1] = (s_lh & v_rh[1]);
	v_out[2] = (s_lh & v_rh[2]);
	v_out[3] = (s_lh & v_rh[3]);
	return v_out;
}

ijk_inl uintv ijkVecBitNand4usv(uint4 v_out, ui32 const s_lh, uint4 const v_rh)
{
	v_out[0] = ~(s_lh & v_rh[0]);
	v_out[1] = ~(s_lh & v_rh[1]);
	v_out[2] = ~(s_lh & v_rh[2]);
	v_out[3] = ~(s_lh & v_rh[3]);
	return v_out;
}

ijk_inl uintv ijkVecBitOr4usv(uint4 v_out, ui32 const s_lh, uint4 const v_rh)
{
	v_out[0] = (s_lh | v_rh[0]);
	v_out[1] = (s_lh | v_rh[1]);
	v_out[2] = (s_lh | v_rh[2]);
	v_out[3] = (s_lh | v_rh[3]);
	return v_out;
}

ijk_inl uintv ijkVecBitNor4usv(uint4 v_out, ui32 const s_lh, uint4 const v_rh)
{
	v_out[0] = ~(s_lh | v_rh[0]);
	v_out[1] = ~(s_lh | v_rh[1]);
	v_out[2] = ~(s_lh | v_rh[2]);
	v_out[3] = ~(s_lh | v_rh[3]);
	return v_out;
}

ijk_inl uintv ijkVecBitXor4usv(uint4 v_out, ui32 const s_lh, uint4 const v_rh)
{
	v_out[0] = (s_lh ^ v_rh[0]);
	v_out[1] = (s_lh ^ v_rh[1]);
	v_out[2] = (s_lh ^ v_rh[2]);
	v_out[3] = (s_lh ^ v_rh[3]);
	return v_out;
}

ijk_inl uintv ijkVecBitXnor4usv(uint4 v_out, ui32 const s_lh, uint4 const v_rh)
{
	v_out[0] = ~(s_lh ^ v_rh[0]);
	v_out[1] = ~(s_lh ^ v_rh[1]);
	v_out[2] = ~(s_lh ^ v_rh[2]);
	v_out[3] = ~(s_lh ^ v_rh[3]);
	return v_out;
}

ijk_inl uintv ijkVecBitShiftLeft4usv(uint4 v_out, ui32 const s_lh, uint4 const v_rh)
{
	v_out[0] = (s_lh << v_rh[0]);
	v_out[1] = (s_lh << v_rh[1]);
	v_out[2] = (s_lh << v_rh[2]);
	v_out[3] = (s_lh << v_rh[3]);
	return v_out;
}

ijk_inl uintv ijkVecBitShiftRight4usv(uint4 v_out, ui32 const s_lh, uint4 const v_rh)
{
	v_out[0] = (s_lh >> v_rh[0]);
	v_out[1] = (s_lh >> v_rh[1]);
	v_out[2] = (s_lh >> v_rh[2]);
	v_out[3] = (s_lh >> v_rh[3]);
	return v_out;
}
#endif	// TINTEGER

ijk_inl boolv ijkVecEqual4usv(bool4 bv_out, ui32 const s_lh, uint4 const v_rh)
{
	bv_out[0] = (s_lh == v_rh[0]);
	bv_out[1] = (s_lh == v_rh[1]);
	bv_out[2] = (s_lh == v_rh[2]);
	bv_out[3] = (s_lh == v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal4usv(bool4 bv_out, ui32 const s_lh, uint4 const v_rh)
{
	bv_out[0] = (s_lh != v_rh[0]);
	bv_out[1] = (s_lh != v_rh[1]);
	bv_out[2] = (s_lh != v_rh[2]);
	bv_out[3] = (s_lh != v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual4usv(bool4 bv_out, ui32 const s_lh, uint4 const v_rh)
{
	bv_out[0] = (s_lh <= v_rh[0]);
	bv_out[1] = (s_lh <= v_rh[1]);
	bv_out[2] = (s_lh <= v_rh[2]);
	bv_out[3] = (s_lh <= v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual4usv(bool4 bv_out, ui32 const s_lh, uint4 const v_rh)
{
	bv_out[0] = (s_lh >= v_rh[0]);
	bv_out[1] = (s_lh >= v_rh[1]);
	bv_out[2] = (s_lh >= v_rh[2]);
	bv_out[3] = (s_lh >= v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecLess4usv(bool4 bv_out, ui32 const s_lh, uint4 const v_rh)
{
	bv_out[0] = (s_lh < v_rh[0]);
	bv_out[1] = (s_lh < v_rh[1]);
	bv_out[2] = (s_lh < v_rh[2]);
	bv_out[3] = (s_lh < v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater4usv(bool4 bv_out, ui32 const s_lh, uint4 const v_rh)
{
	bv_out[0] = (s_lh > v_rh[0]);
	bv_out[1] = (s_lh > v_rh[1]);
	bv_out[2] = (s_lh > v_rh[2]);
	bv_out[3] = (s_lh > v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd4usv(bool4 bv_out, ui32 const s_lh, uint4 const v_rh)
{
	bv_out[0] = (s_lh && v_rh[0]);
	bv_out[1] = (s_lh && v_rh[1]);
	bv_out[2] = (s_lh && v_rh[2]);
	bv_out[3] = (s_lh && v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecNand4usv(bool4 bv_out, ui32 const s_lh, uint4 const v_rh)
{
	bv_out[0] = !(s_lh && v_rh[0]);
	bv_out[1] = !(s_lh && v_rh[1]);
	bv_out[2] = !(s_lh && v_rh[2]);
	bv_out[3] = !(s_lh && v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecOr4usv(bool4 bv_out, ui32 const s_lh, uint4 const v_rh)
{
	bv_out[0] = (s_lh || v_rh[0]);
	bv_out[1] = (s_lh || v_rh[1]);
	bv_out[2] = (s_lh || v_rh[2]);
	bv_out[3] = (s_lh || v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecNor4usv(bool4 bv_out, ui32 const s_lh, uint4 const v_rh)
{
	bv_out[0] = !(s_lh || v_rh[0]);
	bv_out[1] = !(s_lh || v_rh[1]);
	bv_out[2] = !(s_lh || v_rh[2]);
	bv_out[3] = !(s_lh || v_rh[3]);
	return bv_out;
}

ijk_inl ui32 ijkVecDot4uv(uint4 const v_lh, uint4 const v_rh)
{
	return (v_lh[0] * v_rh[0] + v_lh[1] * v_rh[1] + v_lh[2] * v_rh[2] + v_lh[3] * v_rh[3]);
}

ijk_inl uintv ijkVecCross4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh)
{
	v_out[3] = 0;
	return ijkVecCross3uv(v_out, v_lh, v_rh);
}


//-----------------------------------------------------------------------------

ijk_inl uint ijkVecAbs1u(uint const s)
{
	return ijkVecAbs1us(s);
}

ijk_inl uint ijkVecSgn1u(uint const s)
{
	return ijkVecSgn1us(s);
}

ijk_inl uint ijkVecDot1u(uint const s_lh, uint const s_rh)
{
	return ijkVecDot1us(s_lh, s_rh);
}

ijk_inl uint ijkVecLengthSq1u(uint const s)
{
	return ijkVecLengthSq1us(s);
}

ijk_inl uint ijkVecLength1u(uint const s)
{
	return ijkVecLength1us(s);
}

ijk_inl uint ijkVecLengthSqInv1u(uint const s)
{
	return ijkVecLengthSqInv1us(s);
}

ijk_inl uint ijkVecLengthInv1u(uint const s)
{
	return ijkVecLengthInv1us(s);
}

ijk_inl uint ijkVecNormalize1u(uint const s)
{
	return ijkVecNormalize1us(s);
}

ijk_inl uint ijkVecNormalizeGetLength1u(uint const s, uint* const length_out)
{
	return ijkVecNormalizeGetLength1us(s, (ui32*)length_out);
}

ijk_inl uint ijkVecNormalizeGetLengthInv1u(uint const s, uint* const lengthInv_out)
{
	return ijkVecNormalizeGetLength1us(s, (ui32*)lengthInv_out);
}


//-----------------------------------------------------------------------------

ijk_inl uvec2 ijkVecInit2u()
{
	uvec2 const v_out = { 0, 0 };
	return v_out;
}

ijk_inl uvec2 ijkVecInitElems2u(uint const x, uint const y)
{
	uvec2 const v_out = { x, y };
	return v_out;
}

ijk_inl uvec2 ijkVecCopy2u(uvec2 const v_in)
{
	uvec2 const v_out = { +v_in.x, +v_in.y };
	return v_out;
}

#if TSIGNED
ijk_inl uvec2 ijkVecNegate2u(uvec2 const v_in)
{
	uvec2 const v_out = { -v_in.x, -v_in.y };
	return v_out;
}
#endif	// TSIGNED

#if TINTEGER
ijk_inl uvec2 ijkVecBitNot2u(uvec2 const v_in)
{
	uvec2 const v_out = { ~v_in.x, ~v_in.y };
	return v_out;
}
#endif	// TINTEGER

ijk_inl bvec2 ijkVecNot2u(uvec2 const v_in)
{
	bvec2 const bv_out = { !v_in.x, !v_in.y };
	return bv_out;
}

ijk_inl uvec2 ijkVecAdd2u(uvec2 const v_lh, uvec2 const v_rh)
{
	uvec2 const v_out = {
		v_lh.x + v_rh.x,
		v_lh.y + v_rh.y,
	};
	return v_out;
}

ijk_inl uvec2 ijkVecSub2u(uvec2 const v_lh, uvec2 const v_rh)
{
	uvec2 const v_out = {
		v_lh.x - v_rh.x,
		v_lh.y - v_rh.y,
	};
	return v_out;
}

ijk_inl uvec2 ijkVecMul2u(uvec2 const v_lh, uvec2 const v_rh)
{
	uvec2 const v_out = {
		v_lh.x * v_rh.x,
		v_lh.y * v_rh.y,
	};
	return v_out;
}

ijk_inl uvec2 ijkVecDiv2u(uvec2 const v_lh, uvec2 const v_rh)
{
	uvec2 const v_out = {
		v_lh.x / v_rh.x,
		v_lh.y / v_rh.y,
	};
	return v_out;
}

ijk_inl uvec2 ijkVecDivSafe2u(uvec2 const v_lh, uvec2 const v_rh)
{
	uvec2 const v_out = {
		ijk_divide_safe_int(v_lh.x, v_rh.x),
		ijk_divide_safe_int(v_lh.y, v_rh.y),
	};
	return v_out;
}

ijk_inl uvec2 ijkVecMod2u(uvec2 const v_lh, uvec2 const v_rh)
{
	uvec2 const v_out = {
		v_lh.x % v_rh.x,
		v_lh.y % v_rh.y,
	};
	return v_out;
}

ijk_inl uvec2 ijkVecModSafe2u(uvec2 const v_lh, uvec2 const v_rh)
{
	uvec2 const v_out = {
		ijk_modulo_safe_int(v_lh.x, v_rh.x),
		ijk_modulo_safe_int(v_lh.y, v_rh.y),
	};
	return v_out;
}

#if TINTEGER
ijk_inl uvec2 ijkVecBitAnd2u(uvec2 const v_lh, uvec2 const v_rh)
{
	uvec2 const v_out = {
		(v_lh.x & v_rh.x),
		(v_lh.y & v_rh.y),
	};
	return v_out;
}

ijk_inl uvec2 ijkVecBitNand2u(uvec2 const v_lh, uvec2 const v_rh)
{
	uvec2 const v_out = {
		~(v_lh.x & v_rh.x),
		~(v_lh.y & v_rh.y),
	};
	return v_out;
}

ijk_inl uvec2 ijkVecBitOr2u(uvec2 const v_lh, uvec2 const v_rh)
{
	uvec2 const v_out = {
		(v_lh.x | v_rh.x),
		(v_lh.y | v_rh.y),
	};
	return v_out;
}

ijk_inl uvec2 ijkVecBitNor2u(uvec2 const v_lh, uvec2 const v_rh)
{
	uvec2 const v_out = {
		~(v_lh.x | v_rh.x),
		~(v_lh.y | v_rh.y),
	};
	return v_out;
}

ijk_inl uvec2 ijkVecBitXor2u(uvec2 const v_lh, uvec2 const v_rh)
{
	uvec2 const v_out = {
		(v_lh.x ^ v_rh.x),
		(v_lh.y ^ v_rh.y),
	};
	return v_out;
}

ijk_inl uvec2 ijkVecBitXnor2u(uvec2 const v_lh, uvec2 const v_rh)
{
	uvec2 const v_out = {
		~(v_lh.x ^ v_rh.x),
		~(v_lh.y ^ v_rh.y),
	};
	return v_out;
}

ijk_inl uvec2 ijkVecBitShiftLeft2u(uvec2 const v_lh, uvec2 const v_rh)
{
	uvec2 const v_out = {
		(v_lh.x << v_rh.x),
		(v_lh.y << v_rh.y),
	};
	return v_out;
}

ijk_inl uvec2 ijkVecBitShiftRight2u(uvec2 const v_lh, uvec2 const v_rh)
{
	uvec2 const v_out = {
		(v_lh.x >> v_rh.x),
		(v_lh.y >> v_rh.y),
	};
	return v_out;
}
#endif	// TINTEGER

ijk_inl bvec2 ijkVecEqual2u(uvec2 const v_lh, uvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x == v_rh.x),
		(v_lh.y == v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecInequal2u(uvec2 const v_lh, uvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x != v_rh.x),
		(v_lh.y != v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLessEqual2u(uvec2 const v_lh, uvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x <= v_rh.x),
		(v_lh.y <= v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreaterEqual2u(uvec2 const v_lh, uvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x >= v_rh.x),
		(v_lh.y >= v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLess2u(uvec2 const v_lh, uvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x < v_rh.x),
		(v_lh.y < v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreater2u(uvec2 const v_lh, uvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x > v_rh.x),
		(v_lh.y > v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecAnd2u(uvec2 const v_lh, uvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x && v_rh.x),
		(v_lh.y && v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNand2u(uvec2 const v_lh, uvec2 const v_rh)
{
	bvec2 const bv_out = {
		!(v_lh.x && v_rh.x),
		!(v_lh.y && v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecOr2u(uvec2 const v_lh, uvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x || v_rh.x),
		(v_lh.y || v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNor2u(uvec2 const v_lh, uvec2 const v_rh)
{
	bvec2 const bv_out = {
		!(v_lh.x || v_rh.x),
		!(v_lh.y || v_rh.y),
	};
	return bv_out;
}

ijk_inl uvec2 ijkVecCopy2us(uint const s_in)
{
	uvec2 const v_out = { s_in, s_in };
	return v_out;
}

#if TSIGNED
ijk_inl uvec2 ijkVecNegate2us(uint const s_in)
{
	uint const s = -s_in;
	uvec2 const v_out = { s, s };
	return v_out;
}
#endif	// TSIGNED

#if TINTEGER
ijk_inl uvec2 ijkVecBitNot2us(uint const s_in)
{
	uint const s = ~s_in;
	uvec2 const v_out = { s, s };
	return v_out;
}
#endif	// TINTEGER

ijk_inl bvec2 ijkVecNot2us(uint const s_in)
{
	bool const s = !s_in;
	bvec2 const bv_out = { s, s };
	return bv_out;
}

ijk_inl uvec2 ijkVecAdd2us(uvec2 const v_lh, uint const s_rh)
{
	uvec2 const v_out = {
		v_lh.x + s_rh,
		v_lh.y + s_rh,
	};
	return v_out;
}

ijk_inl uvec2 ijkVecSub2us(uvec2 const v_lh, uint const s_rh)
{
	uvec2 const v_out = {
		v_lh.x - s_rh,
		v_lh.y - s_rh,
	};
	return v_out;
}

ijk_inl uvec2 ijkVecMul2us(uvec2 const v_lh, uint const s_rh)
{
	uvec2 const v_out = {
		v_lh.x * s_rh,
		v_lh.y * s_rh,
	};
	return v_out;
}

ijk_inl uvec2 ijkVecDiv2us(uvec2 const v_lh, uint const s_rh)
{
	uvec2 const v_out = {
		v_lh.x / s_rh,
		v_lh.y / s_rh,
	};
	return v_out;
}

ijk_inl uvec2 ijkVecDivSafe2us(uvec2 const v_lh, uint const s_rh)
{
	if (s_rh)
	{
		uvec2 const v_out = {
			v_lh.x / s_rh,
			v_lh.y / s_rh,
		};
		return v_out;
	}
	else
	{
		uvec2 const v_out = { 0, 0 };
		return v_out;
	}
}

ijk_inl uvec2 ijkVecMod2us(uvec2 const v_lh, uint const s_rh)
{
	uvec2 const v_out = {
		v_lh.x % s_rh,
		v_lh.y % s_rh,
	};
	return v_out;
}

ijk_inl uvec2 ijkVecModSafe2us(uvec2 const v_lh, uint const s_rh)
{
	if (s_rh)
	{
		uvec2 const v_out = {
			v_lh.x % s_rh,
			v_lh.y % s_rh,
		};
		return v_out;
	}
	else
	{
		uvec2 const v_out = { 0, 0 };
		return v_out;
	}
}

#if TINTEGER
ijk_inl uvec2 ijkVecBitAnd2us(uvec2 const v_lh, uint const s_rh)
{
	uvec2 const v_out = {
		(v_lh.x & s_rh),
		(v_lh.y & s_rh),
	};
	return v_out;
}

ijk_inl uvec2 ijkVecBitNand2us(uvec2 const v_lh, uint const s_rh)
{
	uvec2 const v_out = {
		~(v_lh.x & s_rh),
		~(v_lh.y & s_rh),
	};
	return v_out;
}

ijk_inl uvec2 ijkVecBitOr2us(uvec2 const v_lh, uint const s_rh)
{
	uvec2 const v_out = {
		(v_lh.x | s_rh),
		(v_lh.y | s_rh),
	};
	return v_out;
}

ijk_inl uvec2 ijkVecBitNor2us(uvec2 const v_lh, uint const s_rh)
{
	uvec2 const v_out = {
		~(v_lh.x | s_rh),
		~(v_lh.y | s_rh),
	};
	return v_out;
}

ijk_inl uvec2 ijkVecBitXor2us(uvec2 const v_lh, uint const s_rh)
{
	uvec2 const v_out = {
		(v_lh.x ^ s_rh),
		(v_lh.y ^ s_rh),
	};
	return v_out;
}

ijk_inl uvec2 ijkVecBitXnor2us(uvec2 const v_lh, uint const s_rh)
{
	uvec2 const v_out = {
		~(v_lh.x ^ s_rh),
		~(v_lh.y ^ s_rh),
	};
	return v_out;
}

ijk_inl uvec2 ijkVecBitShiftLeft2us(uvec2 const v_lh, uint const s_rh)
{
	uvec2 const v_out = {
		(v_lh.x << s_rh),
		(v_lh.y << s_rh),
	};
	return v_out;
}

ijk_inl uvec2 ijkVecBitShiftRight2us(uvec2 const v_lh, uint const s_rh)
{
	uvec2 const v_out = {
		(v_lh.x >> s_rh),
		(v_lh.y >> s_rh),
	};
	return v_out;
}
#endif	// TINTEGER

ijk_inl bvec2 ijkVecEqual2us(uvec2 const v_lh, uint const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x == s_rh),
		(v_lh.y == s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecInequal2us(uvec2 const v_lh, uint const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x != s_rh),
		(v_lh.y != s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLessEqual2us(uvec2 const v_lh, uint const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x <= s_rh),
		(v_lh.y <= s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreaterEqual2us(uvec2 const v_lh, uint const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x >= s_rh),
		(v_lh.y >= s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLess2us(uvec2 const v_lh, uint const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x < s_rh),
		(v_lh.y < s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreater2us(uvec2 const v_lh, uint const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x > s_rh),
		(v_lh.y > s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecAnd2us(uvec2 const v_lh, uint const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x && s_rh),
		(v_lh.y && s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNand2us(uvec2 const v_lh, uint const s_rh)
{
	bvec2 const bv_out = {
		!(v_lh.x && s_rh),
		!(v_lh.y && s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecOr2us(uvec2 const v_lh, uint const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x || s_rh),
		(v_lh.y || s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNor2us(uvec2 const v_lh, uint const s_rh)
{
	bvec2 const bv_out = {
		!(v_lh.x || s_rh),
		!(v_lh.y || s_rh),
	};
	return bv_out;
}

ijk_inl uvec2 ijkVecAdd2su(uint const s_lh, uvec2 const v_rh)
{
	uvec2 const v_out = {
		s_lh + v_rh.x,
		s_lh + v_rh.y,
	};
	return v_out;
}

ijk_inl uvec2 ijkVecSub2su(uint const s_lh, uvec2 const v_rh)
{
	uvec2 const v_out = {
		s_lh - v_rh.x,
		s_lh - v_rh.y,
	};
	return v_out;
}

ijk_inl uvec2 ijkVecMul2su(uint const s_lh, uvec2 const v_rh)
{
	uvec2 const v_out = {
		s_lh * v_rh.x,
		s_lh * v_rh.y,
	};
	return v_out;
}

ijk_inl uvec2 ijkVecDiv2su(uint const s_lh, uvec2 const v_rh)
{
	uvec2 const v_out = {
		s_lh / v_rh.x,
		s_lh / v_rh.y,
	};
	return v_out;
}

ijk_inl uvec2 ijkVecDivSafe2su(uint const s_lh, uvec2 const v_rh)
{
	uvec2 const v_out = {
		ijk_divide_safe_int(s_lh, v_rh.x),
		ijk_divide_safe_int(s_lh, v_rh.y),
	};
	return v_out;
}

ijk_inl uvec2 ijkVecMod2su(uint const s_lh, uvec2 const v_rh)
{
	uvec2 const v_out = {
		s_lh % v_rh.x,
		s_lh % v_rh.y,
	};
	return v_out;
}

ijk_inl uvec2 ijkVecModSafe2su(uint const s_lh, uvec2 const v_rh)
{
	uvec2 const v_out = {
		ijk_modulo_safe_int(s_lh, v_rh.x),
		ijk_modulo_safe_int(s_lh, v_rh.y),
	};
	return v_out;
}

#if TINTEGER
ijk_inl uvec2 ijkVecBitAnd2su(uint const s_lh, uvec2 const v_rh)
{
	uvec2 const v_out = {
		(s_lh & v_rh.x),
		(s_lh & v_rh.y),
	};
	return v_out;
}

ijk_inl uvec2 ijkVecBitNand2su(uint const s_lh, uvec2 const v_rh)
{
	uvec2 const v_out = {
		~(s_lh & v_rh.x),
		~(s_lh & v_rh.y),
	};
	return v_out;
}

ijk_inl uvec2 ijkVecBitOr2su(uint const s_lh, uvec2 const v_rh)
{
	uvec2 const v_out = {
		(s_lh | v_rh.x),
		(s_lh | v_rh.y),
	};
	return v_out;
}

ijk_inl uvec2 ijkVecBitNor2su(uint const s_lh, uvec2 const v_rh)
{
	uvec2 const v_out = {
		~(s_lh | v_rh.x),
		~(s_lh | v_rh.y),
	};
	return v_out;
}

ijk_inl uvec2 ijkVecBitXor2su(uint const s_lh, uvec2 const v_rh)
{
	uvec2 const v_out = {
		(s_lh ^ v_rh.x),
		(s_lh ^ v_rh.y),
	};
	return v_out;
}

ijk_inl uvec2 ijkVecBitXnor2su(uint const s_lh, uvec2 const v_rh)
{
	uvec2 const v_out = {
		~(s_lh ^ v_rh.x),
		~(s_lh ^ v_rh.y),
	};
	return v_out;
}

ijk_inl uvec2 ijkVecBitShiftLeft2su(uint const s_lh, uvec2 const v_rh)
{
	uvec2 const v_out = {
		(s_lh << v_rh.x),
		(s_lh << v_rh.y),
	};
	return v_out;
}

ijk_inl uvec2 ijkVecBitShiftRight2su(uint const s_lh, uvec2 const v_rh)
{
	uvec2 const v_out = {
		(s_lh >> v_rh.x),
		(s_lh >> v_rh.y),
	};
	return v_out;
}
#endif	// TINTEGER

ijk_inl bvec2 ijkVecEqual2su(uint const s_lh, uvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh == v_rh.x),
		(s_lh == v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecInequal2su(uint const s_lh, uvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh != v_rh.x),
		(s_lh != v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLessEqual2su(uint const s_lh, uvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh <= v_rh.x),
		(s_lh <= v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreaterEqual2su(uint const s_lh, uvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh >= v_rh.x),
		(s_lh >= v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLess2su(uint const s_lh, uvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh < v_rh.x),
		(s_lh < v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreater2su(uint const s_lh, uvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh > v_rh.x),
		(s_lh > v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecAnd2su(uint const s_lh, uvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh && v_rh.x),
		(s_lh && v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNand2su(uint const s_lh, uvec2 const v_rh)
{
	bvec2 const bv_out = {
		!(s_lh && v_rh.x),
		!(s_lh && v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecOr2su(uint const s_lh, uvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh || v_rh.x),
		(s_lh || v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNor2su(uint const s_lh, uvec2 const v_rh)
{
	bvec2 const bv_out = {
		!(s_lh || v_rh.x),
		!(s_lh || v_rh.y),
	};
	return bv_out;
}

ijk_inl uint ijkVecDot2u(uvec2 const v_lh, uvec2 const v_rh)
{
	return ijkVecDot2uv(v_lh.xy, v_rh.xy);
}

ijk_inl uint ijkVecCross2u(uvec2 const v_lh, uvec2 const v_rh)
{
	return ijkVecCross2uv(v_lh.xy, v_rh.xy);
}


//-----------------------------------------------------------------------------

ijk_inl uvec3 ijkVecInit3u()
{
	uvec3 const v_out = { 0, 0, 0 };
	return v_out;
}

ijk_inl uvec3 ijkVecInitElems3u(uint const x, uint const y, uint const z)
{
	uvec3 const v_out = { x, y, z };
	return v_out;
}

ijk_inl uvec3 ijkVecCopy3u(uvec3 const v_in)
{
	uvec3 const v_out = { +v_in.x, +v_in.y, +v_in.z };
	return v_out;
}

#if TSIGNED
ijk_inl uvec3 ijkVecNegate3u(uvec3 const v_in)
{
	uvec3 const v_out = { -v_in.x, -v_in.y, -v_in.z };
	return v_out;
}
#endif	// TSIGNED

#if TINTEGER
ijk_inl uvec3 ijkVecBitNot3u(uvec3 const v_in)
{
	uvec3 const v_out = { ~v_in.x, ~v_in.y, ~v_in.z };
	return v_out;
}
#endif	// TINTEGER

ijk_inl bvec3 ijkVecNot3u(uvec3 const v_in)
{
	bvec3 const bv_out = { !v_in.x, !v_in.y, !v_in.z };
	return bv_out;
}

ijk_inl uvec3 ijkVecAdd3u(uvec3 const v_lh, uvec3 const v_rh)
{
	uvec3 const v_out = {
		v_lh.x + v_rh.x,
		v_lh.y + v_rh.y,
		v_lh.z + v_rh.z,
	};
	return v_out;
}

ijk_inl uvec3 ijkVecSub3u(uvec3 const v_lh, uvec3 const v_rh)
{
	uvec3 const v_out = {
		v_lh.x - v_rh.x,
		v_lh.y - v_rh.y,
		v_lh.z - v_rh.z,
	};
	return v_out;
}

ijk_inl uvec3 ijkVecMul3u(uvec3 const v_lh, uvec3 const v_rh)
{
	uvec3 const v_out = {
		v_lh.x * v_rh.x,
		v_lh.y * v_rh.y,
		v_lh.z * v_rh.z,
	};
	return v_out;
}

ijk_inl uvec3 ijkVecDiv3u(uvec3 const v_lh, uvec3 const v_rh)
{
	uvec3 const v_out = {
		v_lh.x / v_rh.x,
		v_lh.y / v_rh.y,
		v_lh.z / v_rh.z,
	};
	return v_out;
}

ijk_inl uvec3 ijkVecDivSafe3u(uvec3 const v_lh, uvec3 const v_rh)
{
	uvec3 const v_out = {
		ijk_divide_safe_int(v_lh.x, v_rh.x),
		ijk_divide_safe_int(v_lh.y, v_rh.y),
		ijk_divide_safe_int(v_lh.z, v_rh.z),
	};
	return v_out;
}

ijk_inl uvec3 ijkVecMod3u(uvec3 const v_lh, uvec3 const v_rh)
{
	uvec3 const v_out = {
		v_lh.x % v_rh.x,
		v_lh.y % v_rh.y,
		v_lh.z % v_rh.z,
	};
	return v_out;
}

ijk_inl uvec3 ijkVecModSafe3u(uvec3 const v_lh, uvec3 const v_rh)
{
	uvec3 const v_out = {
		ijk_modulo_safe_int(v_lh.x, v_rh.x),
		ijk_modulo_safe_int(v_lh.y, v_rh.y),
		ijk_modulo_safe_int(v_lh.z, v_rh.z),
	};
	return v_out;
}

#if TINTEGER
ijk_inl uvec3 ijkVecBitAnd3u(uvec3 const v_lh, uvec3 const v_rh)
{
	uvec3 const v_out = {
		(v_lh.x & v_rh.x),
		(v_lh.y & v_rh.y),
		(v_lh.z & v_rh.z),
	};
	return v_out;
}

ijk_inl uvec3 ijkVecBitNand3u(uvec3 const v_lh, uvec3 const v_rh)
{
	uvec3 const v_out = {
		~(v_lh.x & v_rh.x),
		~(v_lh.y & v_rh.y),
		~(v_lh.z & v_rh.z),
	};
	return v_out;
}

ijk_inl uvec3 ijkVecBitOr3u(uvec3 const v_lh, uvec3 const v_rh)
{
	uvec3 const v_out = {
		(v_lh.x | v_rh.x),
		(v_lh.y | v_rh.y),
		(v_lh.z | v_rh.z),
	};
	return v_out;
}

ijk_inl uvec3 ijkVecBitNor3u(uvec3 const v_lh, uvec3 const v_rh)
{
	uvec3 const v_out = {
		~(v_lh.x | v_rh.x),
		~(v_lh.y | v_rh.y),
		~(v_lh.z | v_rh.z),
	};
	return v_out;
}

ijk_inl uvec3 ijkVecBitXor3u(uvec3 const v_lh, uvec3 const v_rh)
{
	uvec3 const v_out = {
		(v_lh.x ^ v_rh.x),
		(v_lh.y ^ v_rh.y),
		(v_lh.z ^ v_rh.z),
	};
	return v_out;
}

ijk_inl uvec3 ijkVecBitXnor3u(uvec3 const v_lh, uvec3 const v_rh)
{
	uvec3 const v_out = {
		~(v_lh.x ^ v_rh.x),
		~(v_lh.y ^ v_rh.y),
		~(v_lh.z ^ v_rh.z),
	};
	return v_out;
}

ijk_inl uvec3 ijkVecBitShiftLeft3u(uvec3 const v_lh, uvec3 const v_rh)
{
	uvec3 const v_out = {
		(v_lh.x << v_rh.x),
		(v_lh.y << v_rh.y),
		(v_lh.z << v_rh.z),
	};
	return v_out;
}

ijk_inl uvec3 ijkVecBitShiftRight3u(uvec3 const v_lh, uvec3 const v_rh)
{
	uvec3 const v_out = {
		(v_lh.x >> v_rh.x),
		(v_lh.y >> v_rh.y),
		(v_lh.z >> v_rh.z),
	};
	return v_out;
}
#endif	// TINTEGER

ijk_inl bvec3 ijkVecEqual3u(uvec3 const v_lh, uvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x == v_rh.x),
		(v_lh.y == v_rh.y),
		(v_lh.z == v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecInequal3u(uvec3 const v_lh, uvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x != v_rh.x),
		(v_lh.y != v_rh.y),
		(v_lh.z != v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLessEqual3u(uvec3 const v_lh, uvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x <= v_rh.x),
		(v_lh.y <= v_rh.y),
		(v_lh.z <= v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreaterEqual3u(uvec3 const v_lh, uvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x >= v_rh.x),
		(v_lh.y >= v_rh.y),
		(v_lh.z >= v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLess3u(uvec3 const v_lh, uvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x < v_rh.x),
		(v_lh.y < v_rh.y),
		(v_lh.z < v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreater3u(uvec3 const v_lh, uvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x > v_rh.x),
		(v_lh.y > v_rh.y),
		(v_lh.z > v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecAnd3u(uvec3 const v_lh, uvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x && v_rh.x),
		(v_lh.y && v_rh.y),
		(v_lh.z && v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNand3u(uvec3 const v_lh, uvec3 const v_rh)
{
	bvec3 const bv_out = {
		!(v_lh.x && v_rh.x),
		!(v_lh.y && v_rh.y),
		!(v_lh.z && v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecOr3u(uvec3 const v_lh, uvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x || v_rh.x),
		(v_lh.y || v_rh.y),
		(v_lh.z || v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNor3u(uvec3 const v_lh, uvec3 const v_rh)
{
	bvec3 const bv_out = {
		!(v_lh.x || v_rh.x),
		!(v_lh.y || v_rh.y),
		!(v_lh.z || v_rh.z),
	};
	return bv_out;
}

ijk_inl uvec3 ijkVecCopy3uz(uvec2 const v_xy, uint const z)
{
	uvec3 const v_out = { v_xy.x, v_xy.y, z };
	return v_out;
}

ijk_inl uvec3 ijkVecCopy3us(uint const s_in)
{
	uvec3 const v_out = { s_in, s_in, s_in };
	return v_out;
}

#if TSIGNED
ijk_inl uvec3 ijkVecNegate3us(uint const s_in)
{
	uint const s = -s_in;
	uvec3 const v_out = { s, s, s };
	return v_out;
}
#endif	// TSIGNED

#if TINTEGER
ijk_inl uvec3 ijkVecBitNot3us(uint const s_in)
{
	uint const s = ~s_in;
	uvec3 const v_out = { s, s, s };
	return v_out;
}
#endif	// TINTEGER

ijk_inl bvec3 ijkVecNot3us(uint const s_in)
{
	bool const s = !s_in;
	bvec3 const bv_out = { s, s, s };
	return bv_out;
}

ijk_inl uvec3 ijkVecAdd3us(uvec3 const v_lh, uint const s_rh)
{
	uvec3 const v_out = {
		v_lh.x + s_rh,
		v_lh.y + s_rh,
		v_lh.z + s_rh,
	};
	return v_out;
}

ijk_inl uvec3 ijkVecSub3us(uvec3 const v_lh, uint const s_rh)
{
	uvec3 const v_out = {
		v_lh.x - s_rh,
		v_lh.y - s_rh,
		v_lh.z - s_rh,
	};
	return v_out;
}

ijk_inl uvec3 ijkVecMul3us(uvec3 const v_lh, uint const s_rh)
{
	uvec3 const v_out = {
		v_lh.x * s_rh,
		v_lh.y * s_rh,
		v_lh.z * s_rh,
	};
	return v_out;
}

ijk_inl uvec3 ijkVecDiv3us(uvec3 const v_lh, uint const s_rh)
{
	uvec3 const v_out = {
		v_lh.x / s_rh,
		v_lh.y / s_rh,
		v_lh.z / s_rh,
	};
	return v_out;
}

ijk_inl uvec3 ijkVecDivSafe3us(uvec3 const v_lh, uint const s_rh)
{
	if (s_rh)
	{
		uvec3 const v_out = {
			v_lh.x / s_rh,
			v_lh.y / s_rh,
			v_lh.z / s_rh,
		};
		return v_out;
	}
	else
	{
		uvec3 const v_out = { 0, 0, 0 };
		return v_out;
	}
}

ijk_inl uvec3 ijkVecMod3us(uvec3 const v_lh, uint const s_rh)
{
	uvec3 const v_out = {
		v_lh.x % s_rh,
		v_lh.y % s_rh,
		v_lh.z % s_rh,
	};
	return v_out;
}

ijk_inl uvec3 ijkVecModSafe3us(uvec3 const v_lh, uint const s_rh)
{
	if (s_rh)
	{
		uvec3 const v_out = {
			v_lh.x % s_rh,
			v_lh.y % s_rh,
			v_lh.z % s_rh,
		};
		return v_out;
	}
	else
	{
		uvec3 const v_out = { 0, 0, 0 };
		return v_out;
	}
}

#if TINTEGER
ijk_inl uvec3 ijkVecBitAnd3us(uvec3 const v_lh, uint const s_rh)
{
	uvec3 const v_out = {
		(v_lh.x & s_rh),
		(v_lh.y & s_rh),
		(v_lh.z & s_rh),
	};
	return v_out;
}

ijk_inl uvec3 ijkVecBitNand3us(uvec3 const v_lh, uint const s_rh)
{
	uvec3 const v_out = {
		~(v_lh.x & s_rh),
		~(v_lh.y & s_rh),
		~(v_lh.z & s_rh),
	};
	return v_out;
}

ijk_inl uvec3 ijkVecBitOr3us(uvec3 const v_lh, uint const s_rh)
{
	uvec3 const v_out = {
		(v_lh.x | s_rh),
		(v_lh.y | s_rh),
		(v_lh.z | s_rh),
	};
	return v_out;
}

ijk_inl uvec3 ijkVecBitNor3us(uvec3 const v_lh, uint const s_rh)
{
	uvec3 const v_out = {
		~(v_lh.x | s_rh),
		~(v_lh.y | s_rh),
		~(v_lh.z | s_rh),
	};
	return v_out;
}

ijk_inl uvec3 ijkVecBitXor3us(uvec3 const v_lh, uint const s_rh)
{
	uvec3 const v_out = {
		(v_lh.x ^ s_rh),
		(v_lh.y ^ s_rh),
		(v_lh.z ^ s_rh),
	};
	return v_out;
}

ijk_inl uvec3 ijkVecBitXnor3us(uvec3 const v_lh, uint const s_rh)
{
	uvec3 const v_out = {
		~(v_lh.x ^ s_rh),
		~(v_lh.y ^ s_rh),
		~(v_lh.z ^ s_rh),
	};
	return v_out;
}

ijk_inl uvec3 ijkVecBitShiftLeft3us(uvec3 const v_lh, uint const s_rh)
{
	uvec3 const v_out = {
		(v_lh.x << s_rh),
		(v_lh.y << s_rh),
		(v_lh.z << s_rh),
	};
	return v_out;
}

ijk_inl uvec3 ijkVecBitShiftRight3us(uvec3 const v_lh, uint const s_rh)
{
	uvec3 const v_out = {
		(v_lh.x >> s_rh),
		(v_lh.y >> s_rh),
		(v_lh.z >> s_rh),
	};
	return v_out;
}
#endif	// TINTEGER

ijk_inl bvec3 ijkVecEqual3us(uvec3 const v_lh, uint const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x == s_rh),
		(v_lh.y == s_rh),
		(v_lh.z == s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecInequal3us(uvec3 const v_lh, uint const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x != s_rh),
		(v_lh.y != s_rh),
		(v_lh.z != s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLessEqual3us(uvec3 const v_lh, uint const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x <= s_rh),
		(v_lh.y <= s_rh),
		(v_lh.z <= s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreaterEqual3us(uvec3 const v_lh, uint const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x >= s_rh),
		(v_lh.y >= s_rh),
		(v_lh.z >= s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLess3us(uvec3 const v_lh, uint const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x < s_rh),
		(v_lh.y < s_rh),
		(v_lh.z < s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreater3us(uvec3 const v_lh, uint const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x > s_rh),
		(v_lh.y > s_rh),
		(v_lh.z > s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecAnd3us(uvec3 const v_lh, uint const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x && s_rh),
		(v_lh.y && s_rh),
		(v_lh.z && s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNand3us(uvec3 const v_lh, uint const s_rh)
{
	bvec3 const bv_out = {
		!(v_lh.x && s_rh),
		!(v_lh.y && s_rh),
		!(v_lh.z && s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecOr3us(uvec3 const v_lh, uint const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x || s_rh),
		(v_lh.y || s_rh),
		(v_lh.z || s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNor3us(uvec3 const v_lh, uint const s_rh)
{
	bvec3 const bv_out = {
		!(v_lh.x || s_rh),
		!(v_lh.y || s_rh),
		!(v_lh.z || s_rh),
	};
	return bv_out;
}

ijk_inl uvec3 ijkVecCopy3xu(uint const x, uvec2 const v_yz)
{
	uvec3 const v_out = { x, v_yz.x, v_yz.y };
	return v_out;
}

ijk_inl uvec3 ijkVecAdd3su(uint const s_lh, uvec3 const v_rh)
{
	uvec3 const v_out = {
		s_lh + v_rh.x,
		s_lh + v_rh.y,
		s_lh + v_rh.z,
	};
	return v_out;
}

ijk_inl uvec3 ijkVecSub3su(uint const s_lh, uvec3 const v_rh)
{
	uvec3 const v_out = {
		s_lh - v_rh.x,
		s_lh - v_rh.y,
		s_lh - v_rh.z,
	};
	return v_out;
}

ijk_inl uvec3 ijkVecMul3su(uint const s_lh, uvec3 const v_rh)
{
	uvec3 const v_out = {
		s_lh * v_rh.x,
		s_lh * v_rh.y,
		s_lh * v_rh.z,
	};
	return v_out;
}

ijk_inl uvec3 ijkVecDiv3su(uint const s_lh, uvec3 const v_rh)
{
	uvec3 const v_out = {
		s_lh / v_rh.x,
		s_lh / v_rh.y,
		s_lh / v_rh.z,
	};
	return v_out;
}

ijk_inl uvec3 ijkVecDivSafe3su(uint const s_lh, uvec3 const v_rh)
{
	uvec3 const v_out = {
		ijk_divide_safe_int(s_lh, v_rh.x),
		ijk_divide_safe_int(s_lh, v_rh.y),
		ijk_divide_safe_int(s_lh, v_rh.z),
	};
	return v_out;
}

ijk_inl uvec3 ijkVecMod3su(uint const s_lh, uvec3 const v_rh)
{
	uvec3 const v_out = {
		s_lh % v_rh.x,
		s_lh % v_rh.y,
		s_lh % v_rh.z,
	};
	return v_out;
}

ijk_inl uvec3 ijkVecModSafe3su(uint const s_lh, uvec3 const v_rh)
{
	uvec3 const v_out = {
		ijk_modulo_safe_int(s_lh, v_rh.x),
		ijk_modulo_safe_int(s_lh, v_rh.y),
		ijk_modulo_safe_int(s_lh, v_rh.z),
	};
	return v_out;
}

#if TINTEGER
ijk_inl uvec3 ijkVecBitAnd3su(uint const s_lh, uvec3 const v_rh)
{
	uvec3 const v_out = {
		(s_lh & v_rh.x),
		(s_lh & v_rh.y),
		(s_lh & v_rh.z),
	};
	return v_out;
}

ijk_inl uvec3 ijkVecBitNand3su(uint const s_lh, uvec3 const v_rh)
{
	uvec3 const v_out = {
		~(s_lh & v_rh.x),
		~(s_lh & v_rh.y),
		~(s_lh & v_rh.z),
	};
	return v_out;
}

ijk_inl uvec3 ijkVecBitOr3su(uint const s_lh, uvec3 const v_rh)
{
	uvec3 const v_out = {
		(s_lh | v_rh.x),
		(s_lh | v_rh.y),
		(s_lh | v_rh.z),
	};
	return v_out;
}

ijk_inl uvec3 ijkVecBitNor3su(uint const s_lh, uvec3 const v_rh)
{
	uvec3 const v_out = {
		~(s_lh | v_rh.x),
		~(s_lh | v_rh.y),
		~(s_lh | v_rh.z),
	};
	return v_out;
}

ijk_inl uvec3 ijkVecBitXor3su(uint const s_lh, uvec3 const v_rh)
{
	uvec3 const v_out = {
		(s_lh ^ v_rh.x),
		(s_lh ^ v_rh.y),
		(s_lh ^ v_rh.z),
	};
	return v_out;
}

ijk_inl uvec3 ijkVecBitXnor3su(uint const s_lh, uvec3 const v_rh)
{
	uvec3 const v_out = {
		~(s_lh ^ v_rh.x),
		~(s_lh ^ v_rh.y),
		~(s_lh ^ v_rh.z),
	};
	return v_out;
}

ijk_inl uvec3 ijkVecBitShiftLeft3su(uint const s_lh, uvec3 const v_rh)
{
	uvec3 const v_out = {
		(s_lh << v_rh.x),
		(s_lh << v_rh.y),
		(s_lh << v_rh.z),
	};
	return v_out;
}

ijk_inl uvec3 ijkVecBitShiftRight3su(uint const s_lh, uvec3 const v_rh)
{
	uvec3 const v_out = {
		(s_lh >> v_rh.x),
		(s_lh >> v_rh.y),
		(s_lh >> v_rh.z),
	};
	return v_out;
}
#endif	// TINTEGER

ijk_inl bvec3 ijkVecEqual3su(uint const s_lh, uvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh == v_rh.x),
		(s_lh == v_rh.y),
		(s_lh == v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecInequal3su(uint const s_lh, uvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh != v_rh.x),
		(s_lh != v_rh.y),
		(s_lh != v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLessEqual3su(uint const s_lh, uvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh <= v_rh.x),
		(s_lh <= v_rh.y),
		(s_lh <= v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreaterEqual3su(uint const s_lh, uvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh >= v_rh.x),
		(s_lh >= v_rh.y),
		(s_lh >= v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLess3su(uint const s_lh, uvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh < v_rh.x),
		(s_lh < v_rh.y),
		(s_lh < v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreater3su(uint const s_lh, uvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh > v_rh.x),
		(s_lh > v_rh.y),
		(s_lh > v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecAnd3su(uint const s_lh, uvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh && v_rh.x),
		(s_lh && v_rh.y),
		(s_lh && v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNand3su(uint const s_lh, uvec3 const v_rh)
{
	bvec3 const bv_out = {
		!(s_lh && v_rh.x),
		!(s_lh && v_rh.y),
		!(s_lh && v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecOr3su(uint const s_lh, uvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh || v_rh.x),
		(s_lh || v_rh.y),
		(s_lh || v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNor3su(uint const s_lh, uvec3 const v_rh)
{
	bvec3 const bv_out = {
		!(s_lh || v_rh.x),
		!(s_lh || v_rh.y),
		!(s_lh || v_rh.z),
	};
	return bv_out;
}

ijk_inl uint ijkVecDot3u(uvec3 const v_lh, uvec3 const v_rh)
{
	return ijkVecDot3uv(v_lh.xyz, v_rh.xyz);
}

ijk_inl uvec3 ijkVecCross3u(uvec3 const v_lh, uvec3 const v_rh)
{
	uvec3 v_out;
	ijkVecCross3uv(v_out.xyz, v_lh.xyz, v_rh.xyz);
	return v_out;
}


//-----------------------------------------------------------------------------

ijk_inl uvec4 ijkVecInit4u()
{
	uvec4 const v_out = { 0, 0, 0, 0 };
	return v_out;
}

ijk_inl uvec4 ijkVecInitElems4u(uint const x, uint const y, uint const z, uint const w)
{
	uvec4 const v_out = { x, y, z, w };
	return v_out;
}

ijk_inl uvec4 ijkVecCopy4xuw(uint const x, uvec2 const v_yz, uint const w)
{
	uvec4 const v_out = { x, v_yz.x, v_yz.y, w };
	return v_out;
}

ijk_inl uvec4 ijkVecCopy4u2(uvec2 const v_xy, uvec2 const v_zw)
{
	uvec4 const v_out = { v_xy.x, v_xy.y, v_zw.x, v_zw.y };
	return v_out;
}

ijk_inl uvec4 ijkVecCopy4u(uvec4 const v_in)
{
	uvec4 const v_out = { +v_in.x, +v_in.y, +v_in.z, +v_in.w };
	return v_out;
}

#if TSIGNED
ijk_inl uvec4 ijkVecNegate4u(uvec4 const v_in)
{
	uvec4 const v_out = { -v_in.x, -v_in.y, -v_in.z, -v_in.w };
	return v_out;
}
#endif	// TSIGNED

#if TINTEGER
ijk_inl uvec4 ijkVecBitNot4u(uvec4 const v_in)
{
	uvec4 const v_out = { ~v_in.x, ~v_in.y, ~v_in.z, ~v_in.w };
	return v_out;
}
#endif	// TINTEGER

ijk_inl bvec4 ijkVecNot4u(uvec4 const v_in)
{
	bvec4 const bv_out = { !v_in.x, !v_in.y, !v_in.z, !v_in.w };
	return bv_out;
}

ijk_inl uvec4 ijkVecAdd4u(uvec4 const v_lh, uvec4 const v_rh)
{
	uvec4 const v_out = {
		v_lh.x + v_rh.x,
		v_lh.y + v_rh.y,
		v_lh.z + v_rh.z,
		v_lh.w + v_rh.w,
	};
	return v_out;
}

ijk_inl uvec4 ijkVecSub4u(uvec4 const v_lh, uvec4 const v_rh)
{
	uvec4 const v_out = {
		v_lh.x - v_rh.x,
		v_lh.y - v_rh.y,
		v_lh.z - v_rh.z,
		v_lh.w - v_rh.w,
	};
	return v_out;
}

ijk_inl uvec4 ijkVecMul4u(uvec4 const v_lh, uvec4 const v_rh)
{
	uvec4 const v_out = {
		v_lh.x * v_rh.x,
		v_lh.y * v_rh.y,
		v_lh.z * v_rh.z,
		v_lh.w * v_rh.w,
	};
	return v_out;
}

ijk_inl uvec4 ijkVecDiv4u(uvec4 const v_lh, uvec4 const v_rh)
{
	uvec4 const v_out = {
		v_lh.x / v_rh.x,
		v_lh.y / v_rh.y,
		v_lh.z / v_rh.z,
		v_lh.w / v_rh.w,
	};
	return v_out;
}

ijk_inl uvec4 ijkVecDivSafe4u(uvec4 const v_lh, uvec4 const v_rh)
{
	uvec4 const v_out = {
		ijk_divide_safe_int(v_lh.x, v_rh.x),
		ijk_divide_safe_int(v_lh.y, v_rh.y),
		ijk_divide_safe_int(v_lh.z, v_rh.z),
		ijk_divide_safe_int(v_lh.w, v_rh.w),
	};
	return v_out;
}

ijk_inl uvec4 ijkVecMod4u(uvec4 const v_lh, uvec4 const v_rh)
{
	uvec4 const v_out = {
		v_lh.x % v_rh.x,
		v_lh.y % v_rh.y,
		v_lh.z % v_rh.z,
		v_lh.w % v_rh.w,
	};
	return v_out;
}

ijk_inl uvec4 ijkVecModSafe4u(uvec4 const v_lh, uvec4 const v_rh)
{
	uvec4 const v_out = {
		ijk_modulo_safe_int(v_lh.x, v_rh.x),
		ijk_modulo_safe_int(v_lh.y, v_rh.y),
		ijk_modulo_safe_int(v_lh.z, v_rh.z),
		ijk_modulo_safe_int(v_lh.w, v_rh.w),
	};
	return v_out;
}

#if TINTEGER
ijk_inl uvec4 ijkVecBitAnd4u(uvec4 const v_lh, uvec4 const v_rh)
{
	uvec4 const v_out = {
		(v_lh.x & v_rh.x),
		(v_lh.y & v_rh.y),
		(v_lh.z & v_rh.z),
		(v_lh.w & v_rh.w),
	};
	return v_out;
}

ijk_inl uvec4 ijkVecBitNand4u(uvec4 const v_lh, uvec4 const v_rh)
{
	uvec4 const v_out = {
		~(v_lh.x & v_rh.x),
		~(v_lh.y & v_rh.y),
		~(v_lh.z & v_rh.z),
		~(v_lh.w & v_rh.w),
	};
	return v_out;
}

ijk_inl uvec4 ijkVecBitOr4u(uvec4 const v_lh, uvec4 const v_rh)
{
	uvec4 const v_out = {
		(v_lh.x | v_rh.x),
		(v_lh.y | v_rh.y),
		(v_lh.z | v_rh.z),
		(v_lh.w | v_rh.w),
	};
	return v_out;
}

ijk_inl uvec4 ijkVecBitNor4u(uvec4 const v_lh, uvec4 const v_rh)
{
	uvec4 const v_out = {
		~(v_lh.x | v_rh.x),
		~(v_lh.y | v_rh.y),
		~(v_lh.z | v_rh.z),
		~(v_lh.w | v_rh.w),
	};
	return v_out;
}

ijk_inl uvec4 ijkVecBitXor4u(uvec4 const v_lh, uvec4 const v_rh)
{
	uvec4 const v_out = {
		(v_lh.x ^ v_rh.x),
		(v_lh.y ^ v_rh.y),
		(v_lh.z ^ v_rh.z),
		(v_lh.w ^ v_rh.w),
	};
	return v_out;
}

ijk_inl uvec4 ijkVecBitXnor4u(uvec4 const v_lh, uvec4 const v_rh)
{
	uvec4 const v_out = {
		~(v_lh.x ^ v_rh.x),
		~(v_lh.y ^ v_rh.y),
		~(v_lh.z ^ v_rh.z),
		~(v_lh.w ^ v_rh.w),
	};
	return v_out;
}

ijk_inl uvec4 ijkVecBitShiftLeft4u(uvec4 const v_lh, uvec4 const v_rh)
{
	uvec4 const v_out = {
		(v_lh.x << v_rh.x),
		(v_lh.y << v_rh.y),
		(v_lh.z << v_rh.z),
		(v_lh.w << v_rh.w),
	};
	return v_out;
}

ijk_inl uvec4 ijkVecBitShiftRight4u(uvec4 const v_lh, uvec4 const v_rh)
{
	uvec4 const v_out = {
		(v_lh.x >> v_rh.x),
		(v_lh.y >> v_rh.y),
		(v_lh.z >> v_rh.z),
		(v_lh.w >> v_rh.w),
	};
	return v_out;
}
#endif	// TINTEGER

ijk_inl bvec4 ijkVecEqual4u(uvec4 const v_lh, uvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x == v_rh.x),
		(v_lh.y == v_rh.y),
		(v_lh.z == v_rh.z),
		(v_lh.w == v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecInequal4u(uvec4 const v_lh, uvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x != v_rh.x),
		(v_lh.y != v_rh.y),
		(v_lh.z != v_rh.z),
		(v_lh.w != v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLessEqual4u(uvec4 const v_lh, uvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x <= v_rh.x),
		(v_lh.y <= v_rh.y),
		(v_lh.z <= v_rh.z),
		(v_lh.w <= v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreaterEqual4u(uvec4 const v_lh, uvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x >= v_rh.x),
		(v_lh.y >= v_rh.y),
		(v_lh.z >= v_rh.z),
		(v_lh.w >= v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLess4u(uvec4 const v_lh, uvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x < v_rh.x),
		(v_lh.y < v_rh.y),
		(v_lh.z < v_rh.z),
		(v_lh.w < v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreater4u(uvec4 const v_lh, uvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x > v_rh.x),
		(v_lh.y > v_rh.y),
		(v_lh.z > v_rh.z),
		(v_lh.w > v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecAnd4u(uvec4 const v_lh, uvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x && v_rh.x),
		(v_lh.y && v_rh.y),
		(v_lh.z && v_rh.z),
		(v_lh.w && v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNand4u(uvec4 const v_lh, uvec4 const v_rh)
{
	bvec4 const bv_out = {
		!(v_lh.x && v_rh.x),
		!(v_lh.y && v_rh.y),
		!(v_lh.z && v_rh.z),
		!(v_lh.w && v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecOr4u(uvec4 const v_lh, uvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x || v_rh.x),
		(v_lh.y || v_rh.y),
		(v_lh.z || v_rh.z),
		(v_lh.w || v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNor4u(uvec4 const v_lh, uvec4 const v_rh)
{
	bvec4 const bv_out = {
		!(v_lh.x || v_rh.x),
		!(v_lh.y || v_rh.y),
		!(v_lh.z || v_rh.z),
		!(v_lh.w || v_rh.w),
	};
	return bv_out;
}

ijk_inl uvec4 ijkVecCopy4uzw(uvec2 const v_xy, uint const z, uint const w)
{
	uvec4 const v_out = { v_xy.x, v_xy.y, z, w };
	return v_out;
}

ijk_inl uvec4 ijkVecCopy4uw(uvec3 const v_xyz, uint const w)
{
	uvec4 const v_out = { v_xyz.x, v_xyz.y, v_xyz.z, w };
	return v_out;
}

ijk_inl uvec4 ijkVecCopy4us(uint const s_in)
{
	uvec4 const v_out = { s_in, s_in, s_in, s_in };
	return v_out;
}

#if TSIGNED
ijk_inl uvec4 ijkVecNegate4us(uint const s_in)
{
	uint const s = -s_in;
	uvec4 const v_out = { s, s, s, s };
	return v_out;
}
#endif	// TSIGNED

#if TINTEGER
ijk_inl uvec4 ijkVecBitNot4us(uint const s_in)
{
	uint const s = ~s_in;
	uvec4 const v_out = { s, s, s, s };
	return v_out;
}
#endif	// TINTEGER

ijk_inl bvec4 ijkVecNot4us(uint const s_in)
{
	bool const s = !s_in;
	bvec4 const bv_out = { s, s, s, s };
	return bv_out;
}

ijk_inl uvec4 ijkVecAdd4us(uvec4 const v_lh, uint const s_rh)
{
	uvec4 const v_out = {
		v_lh.x + s_rh,
		v_lh.y + s_rh,
		v_lh.z + s_rh,
		v_lh.w + s_rh,
	};
	return v_out;
}

ijk_inl uvec4 ijkVecSub4us(uvec4 const v_lh, uint const s_rh)
{
	uvec4 const v_out = {
		v_lh.x - s_rh,
		v_lh.y - s_rh,
		v_lh.z - s_rh,
		v_lh.w - s_rh,
	};
	return v_out;
}

ijk_inl uvec4 ijkVecMul4us(uvec4 const v_lh, uint const s_rh)
{
	uvec4 const v_out = {
		v_lh.x * s_rh,
		v_lh.y * s_rh,
		v_lh.z * s_rh,
		v_lh.w * s_rh,
	};
	return v_out;
}

ijk_inl uvec4 ijkVecDiv4us(uvec4 const v_lh, uint const s_rh)
{
	uvec4 const v_out = {
		v_lh.x / s_rh,
		v_lh.y / s_rh,
		v_lh.z / s_rh,
		v_lh.w / s_rh,
	};
	return v_out;
}

ijk_inl uvec4 ijkVecDivSafe4us(uvec4 const v_lh, uint const s_rh)
{
	if (s_rh)
	{
		uvec4 const v_out = {
			v_lh.x / s_rh,
			v_lh.y / s_rh,
			v_lh.z / s_rh,
			v_lh.w / s_rh,
		};
		return v_out;
	}
	else
	{
		uvec4 const v_out = { 0, 0, 0, 0 };
		return v_out;
	}
}

ijk_inl uvec4 ijkVecMod4us(uvec4 const v_lh, uint const s_rh)
{
	uvec4 const v_out = {
		v_lh.x % s_rh,
		v_lh.y % s_rh,
		v_lh.z % s_rh,
		v_lh.w % s_rh,
	};
	return v_out;
}

ijk_inl uvec4 ijkVecModSafe4us(uvec4 const v_lh, uint const s_rh)
{
	if (s_rh)
	{
		uvec4 const v_out = {
			v_lh.x % s_rh,
			v_lh.y % s_rh,
			v_lh.z % s_rh,
			v_lh.w % s_rh,
		};
		return v_out;
	}
	else
	{
		uvec4 const v_out = { 0, 0, 0, 0 };
		return v_out;
	}
}

#if TINTEGER
ijk_inl uvec4 ijkVecBitAnd4us(uvec4 const v_lh, uint const s_rh)
{
	uvec4 const v_out = {
		(v_lh.x & s_rh),
		(v_lh.y & s_rh),
		(v_lh.z & s_rh),
		(v_lh.w & s_rh),
	};
	return v_out;
}

ijk_inl uvec4 ijkVecBitNand4us(uvec4 const v_lh, uint const s_rh)
{
	uvec4 const v_out = {
		~(v_lh.x & s_rh),
		~(v_lh.y & s_rh),
		~(v_lh.z & s_rh),
		~(v_lh.w & s_rh),
	};
	return v_out;
}

ijk_inl uvec4 ijkVecBitOr4us(uvec4 const v_lh, uint const s_rh)
{
	uvec4 const v_out = {
		(v_lh.x | s_rh),
		(v_lh.y | s_rh),
		(v_lh.z | s_rh),
		(v_lh.w | s_rh),
	};
	return v_out;
}

ijk_inl uvec4 ijkVecBitNor4us(uvec4 const v_lh, uint const s_rh)
{
	uvec4 const v_out = {
		~(v_lh.x | s_rh),
		~(v_lh.y | s_rh),
		~(v_lh.z | s_rh),
		~(v_lh.w | s_rh),
	};
	return v_out;
}

ijk_inl uvec4 ijkVecBitXor4us(uvec4 const v_lh, uint const s_rh)
{
	uvec4 const v_out = {
		(v_lh.x ^ s_rh),
		(v_lh.y ^ s_rh),
		(v_lh.z ^ s_rh),
		(v_lh.w ^ s_rh),
	};
	return v_out;
}

ijk_inl uvec4 ijkVecBitXnor4us(uvec4 const v_lh, uint const s_rh)
{
	uvec4 const v_out = {
		~(v_lh.x ^ s_rh),
		~(v_lh.y ^ s_rh),
		~(v_lh.z ^ s_rh),
		~(v_lh.w ^ s_rh),
	};
	return v_out;
}

ijk_inl uvec4 ijkVecBitShiftLeft4us(uvec4 const v_lh, uint const s_rh)
{
	uvec4 const v_out = {
		(v_lh.x << s_rh),
		(v_lh.y << s_rh),
		(v_lh.z << s_rh),
		(v_lh.w << s_rh),
	};
	return v_out;
}

ijk_inl uvec4 ijkVecBitShiftRight4us(uvec4 const v_lh, uint const s_rh)
{
	uvec4 const v_out = {
		(v_lh.x >> s_rh),
		(v_lh.y >> s_rh),
		(v_lh.z >> s_rh),
		(v_lh.w >> s_rh),
	};
	return v_out;
}
#endif	// TINTEGER

ijk_inl bvec4 ijkVecEqual4us(uvec4 const v_lh, uint const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x == s_rh),
		(v_lh.y == s_rh),
		(v_lh.z == s_rh),
		(v_lh.w == s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecInequal4us(uvec4 const v_lh, uint const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x != s_rh),
		(v_lh.y != s_rh),
		(v_lh.z != s_rh),
		(v_lh.w != s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLessEqual4us(uvec4 const v_lh, uint const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x <= s_rh),
		(v_lh.y <= s_rh),
		(v_lh.z <= s_rh),
		(v_lh.w <= s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreaterEqual4us(uvec4 const v_lh, uint const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x >= s_rh),
		(v_lh.y >= s_rh),
		(v_lh.z >= s_rh),
		(v_lh.w >= s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLess4us(uvec4 const v_lh, uint const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x < s_rh),
		(v_lh.y < s_rh),
		(v_lh.z < s_rh),
		(v_lh.w < s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreater4us(uvec4 const v_lh, uint const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x > s_rh),
		(v_lh.y > s_rh),
		(v_lh.z > s_rh),
		(v_lh.w > s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecAnd4us(uvec4 const v_lh, uint const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x && s_rh),
		(v_lh.y && s_rh),
		(v_lh.z && s_rh),
		(v_lh.w && s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNand4us(uvec4 const v_lh, uint const s_rh)
{
	bvec4 const bv_out = {
		!(v_lh.x && s_rh),
		!(v_lh.y && s_rh),
		!(v_lh.z && s_rh),
		!(v_lh.w && s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecOr4us(uvec4 const v_lh, uint const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x || s_rh),
		(v_lh.y || s_rh),
		(v_lh.z || s_rh),
		(v_lh.w || s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNor4us(uvec4 const v_lh, uint const s_rh)
{
	bvec4 const bv_out = {
		!(v_lh.x || s_rh),
		!(v_lh.y || s_rh),
		!(v_lh.z || s_rh),
		!(v_lh.w || s_rh),
	};
	return bv_out;
}

ijk_inl uvec4 ijkVecCopy4xyu(uint const x, uint const y, uvec2 const v_zw)
{
	uvec4 const v_out = { x, y, v_zw.x, v_zw.y };
	return v_out;
}

ijk_inl uvec4 ijkVecCopy4xu(uint const x, uvec3 const v_yzw)
{
	uvec4 const v_out = { x, v_yzw.x, v_yzw.y, v_yzw.z };
	return v_out;
}

ijk_inl uvec4 ijkVecAdd4su(uint const s_lh, uvec4 const v_rh)
{
	uvec4 const v_out = {
		s_lh + v_rh.x,
		s_lh + v_rh.y,
		s_lh + v_rh.z,
		s_lh + v_rh.w,
	};
	return v_out;
}

ijk_inl uvec4 ijkVecSub4su(uint const s_lh, uvec4 const v_rh)
{
	uvec4 const v_out = {
		s_lh - v_rh.x,
		s_lh - v_rh.y,
		s_lh - v_rh.z,
		s_lh - v_rh.w,
	};
	return v_out;
}

ijk_inl uvec4 ijkVecMul4su(uint const s_lh, uvec4 const v_rh)
{
	uvec4 const v_out = {
		s_lh * v_rh.x,
		s_lh * v_rh.y,
		s_lh * v_rh.z,
		s_lh * v_rh.w,
	};
	return v_out;
}

ijk_inl uvec4 ijkVecDiv4su(uint const s_lh, uvec4 const v_rh)
{
	uvec4 const v_out = {
		s_lh / v_rh.x,
		s_lh / v_rh.y,
		s_lh / v_rh.z,
		s_lh / v_rh.w,
	};
	return v_out;
}

ijk_inl uvec4 ijkVecDivSafe4su(uint const s_lh, uvec4 const v_rh)
{
	uvec4 const v_out = {
		ijk_divide_safe_int(s_lh, v_rh.x),
		ijk_divide_safe_int(s_lh, v_rh.y),
		ijk_divide_safe_int(s_lh, v_rh.z),
		ijk_divide_safe_int(s_lh, v_rh.w),
	};
	return v_out;
}

ijk_inl uvec4 ijkVecMod4su(uint const s_lh, uvec4 const v_rh)
{
	uvec4 const v_out = {
		s_lh % v_rh.x,
		s_lh % v_rh.y,
		s_lh % v_rh.z,
		s_lh % v_rh.w,
	};
	return v_out;
}

ijk_inl uvec4 ijkVecModSafe4su(uint const s_lh, uvec4 const v_rh)
{
	uvec4 const v_out = {
		ijk_modulo_safe_int(s_lh, v_rh.x),
		ijk_modulo_safe_int(s_lh, v_rh.y),
		ijk_modulo_safe_int(s_lh, v_rh.z),
		ijk_modulo_safe_int(s_lh, v_rh.w),
	};
	return v_out;
}

#if TINTEGER
ijk_inl uvec4 ijkVecBitAnd4su(uint const s_lh, uvec4 const v_rh)
{
	uvec4 const v_out = {
		(s_lh & v_rh.x),
		(s_lh & v_rh.y),
		(s_lh & v_rh.z),
		(s_lh & v_rh.w),
	};
	return v_out;
}

ijk_inl uvec4 ijkVecBitNand4su(uint const s_lh, uvec4 const v_rh)
{
	uvec4 const v_out = {
		~(s_lh & v_rh.x),
		~(s_lh & v_rh.y),
		~(s_lh & v_rh.z),
		~(s_lh & v_rh.w),
	};
	return v_out;
}

ijk_inl uvec4 ijkVecBitOr4su(uint const s_lh, uvec4 const v_rh)
{
	uvec4 const v_out = {
		(s_lh | v_rh.x),
		(s_lh | v_rh.y),
		(s_lh | v_rh.z),
		(s_lh | v_rh.w),
	};
	return v_out;
}

ijk_inl uvec4 ijkVecBitNor4su(uint const s_lh, uvec4 const v_rh)
{
	uvec4 const v_out = {
		~(s_lh | v_rh.x),
		~(s_lh | v_rh.y),
		~(s_lh | v_rh.z),
		~(s_lh | v_rh.w),
	};
	return v_out;
}

ijk_inl uvec4 ijkVecBitXor4su(uint const s_lh, uvec4 const v_rh)
{
	uvec4 const v_out = {
		(s_lh ^ v_rh.x),
		(s_lh ^ v_rh.y),
		(s_lh ^ v_rh.z),
		(s_lh ^ v_rh.w),
	};
	return v_out;
}

ijk_inl uvec4 ijkVecBitXnor4su(uint const s_lh, uvec4 const v_rh)
{
	uvec4 const v_out = {
		~(s_lh ^ v_rh.x),
		~(s_lh ^ v_rh.y),
		~(s_lh ^ v_rh.z),
		~(s_lh ^ v_rh.w),
	};
	return v_out;
}

ijk_inl uvec4 ijkVecBitShiftLeft4su(uint const s_lh, uvec4 const v_rh)
{
	uvec4 const v_out = {
		(s_lh << v_rh.x),
		(s_lh << v_rh.y),
		(s_lh << v_rh.z),
		(s_lh << v_rh.w),
	};
	return v_out;
}

ijk_inl uvec4 ijkVecBitShiftRight4su(uint const s_lh, uvec4 const v_rh)
{
	uvec4 const v_out = {
		(s_lh >> v_rh.x),
		(s_lh >> v_rh.y),
		(s_lh >> v_rh.z),
		(s_lh >> v_rh.w),
	};
	return v_out;
}
#endif	// TINTEGER

ijk_inl bvec4 ijkVecEqual4su(uint const s_lh, uvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh == v_rh.x),
		(s_lh == v_rh.y),
		(s_lh == v_rh.z),
		(s_lh == v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecInequal4su(uint const s_lh, uvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh != v_rh.x),
		(s_lh != v_rh.y),
		(s_lh != v_rh.z),
		(s_lh != v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLessEqual4su(uint const s_lh, uvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh <= v_rh.x),
		(s_lh <= v_rh.y),
		(s_lh <= v_rh.z),
		(s_lh <= v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreaterEqual4su(uint const s_lh, uvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh >= v_rh.x),
		(s_lh >= v_rh.y),
		(s_lh >= v_rh.z),
		(s_lh >= v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLess4su(uint const s_lh, uvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh < v_rh.x),
		(s_lh < v_rh.y),
		(s_lh < v_rh.z),
		(s_lh < v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreater4su(uint const s_lh, uvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh > v_rh.x),
		(s_lh > v_rh.y),
		(s_lh > v_rh.z),
		(s_lh > v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecAnd4su(uint const s_lh, uvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh && v_rh.x),
		(s_lh && v_rh.y),
		(s_lh && v_rh.z),
		(s_lh && v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNand4su(uint const s_lh, uvec4 const v_rh)
{
	bvec4 const bv_out = {
		!(s_lh && v_rh.x),
		!(s_lh && v_rh.y),
		!(s_lh && v_rh.z),
		!(s_lh && v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecOr4su(uint const s_lh, uvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh || v_rh.x),
		(s_lh || v_rh.y),
		(s_lh || v_rh.z),
		(s_lh || v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNor4su(uint const s_lh, uvec4 const v_rh)
{
	bvec4 const bv_out = {
		!(s_lh || v_rh.x),
		!(s_lh || v_rh.y),
		!(s_lh || v_rh.z),
		!(s_lh || v_rh.w),
	};
	return bv_out;
}

ijk_inl uint ijkVecDot4u(uvec4 const v_lh, uvec4 const v_rh)
{
	return ijkVecDot4uv(v_lh.xyzw, v_rh.xyzw);
}

ijk_inl uvec4 ijkVecCross4u(uvec4 const v_lh, uvec4 const v_rh)
{
	uvec4 v_out;
	ijkVecCross4uv(v_out.xyzw, v_lh.xyzw, v_rh.xyzw);
	return v_out;
}


//-----------------------------------------------------------------------------


#endif	// !_IJK_VECTOR_UINT_INL_
#endif	// _IJK_VECTOR_UINT_H_