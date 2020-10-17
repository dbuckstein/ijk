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

	ijkVectorFunc.inl
	Inline definitions for vector functions, using "templates" for C.
	This file is an attempt to avoid writing 7 implementations for each vector 
		function, one per type, of which there are many.
*/

#if (_IJK_VECTORFUNC_H_ == IJK_VECTORFUNC_TYPE)
#ifndef _IJK_VECTORFUNC_INL_
#define _IJK_VECTORFUNC_INL_


//-----------------------------------------------------------------------------

// ijkVecAbs1*s
//	Absolute value of scalar: (s >= 0 ? +s : -s).
//		param s: scalar
//		return: absolute value
ijk_inl type tfuncs(ijkVecAbs1, s, type const s)
{
	return tabs(s);
}

// ijkVecSgn1*s
//	Sign of scalar: (s != 0 ? s > 0 ? +1 : -1).
//		param s: scalar
//		return: sign
ijk_inl type tfuncs(ijkVecSgn1, s, type const s)
{
	return tsgn(s);
}

// ijkVecDot1*s
//	Dot product of scalars, which is just their product.
//		param s_lh: left-hand scalar
//		param s_rh: right-hand scalar
//		return: product
ijk_inl type tfuncs(ijkVecDot1, s, type const s_lh, type const s_rh)
{
	return (s_lh * s_rh);
}

// ijkVecLengthSq1*s
//	Squared length of scalar.
//		param s: scalar
//		return: squared length
ijk_inl type tfuncs(ijkVecLengthSq1, s, type const s)
{
	return (s * s);
}

// ijkVecLength1*s
//	Length of scalar.
//		param s: scalar
//		return: length
ijk_inl type tfuncs(ijkVecLength1, s, type const s)
{
	return tabs(s);
}

// ijkVecLengthSqInv1*s
//	Inverse squared length of scalar.
//		param s: scalar
//		return: inverse squared length
ijk_inl type tfuncs(ijkVecLengthSqInv1, s, type const s)
{
	type const lengthSq = (s * s);
	return trecip(lengthSq);
}

// ijkVecLengthSqInv1*s
//	Inverse length of scalar.
//		param s: scalar
//		return: inverse length
ijk_inl type tfuncs(ijkVecLengthInv1, s, type const s)
{
	type const length = tabs(s);
	return trecip(length);
}

// ijkVecNormalize1*s
//	Calculate unit scalar in same direction as input (sign).
//		param s: scalar
//		return: unit scalar (sign)
ijk_inl type tfuncs(ijkVecNormalize1, s, type const s)
{
	return tsgn(s);
}

// ijkVecNormalizeGetLength1*s
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the length (absolute value).
//		param s: scalar
//		param length_out: pointer to length storage
//		return: unit scalar (sign)
ijk_inl type tfuncs(ijkVecNormalizeGetLength1, s, type const s, type* const length_out)
{
	type const length = *length_out = tabs(s);
	return (s / length);
}

// ijkVecNormalizeGetLengthInv1*s
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the inverse length length (absolute value).
//		param s: scalar
//		param lengthInv_out: pointer to length storage
//		return: unit scalar (sign)
ijk_inl type tfuncs(ijkVecNormalizeGetLengthInv1, s, type const s, type* const lengthInv_out)
{
	type const length = tabs(s);
	*lengthInv_out = trecip(length);
	return tsgn(s);
}


//-----------------------------------------------------------------------------

// ijkVecP*v
//	Pass-thru array-based vector function (does nothing).
//		param v_out: output vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecP, v, typev v_out)
{
	return v_out;
}


//-----------------------------------------------------------------------------

// ijkVecInit2*v
//	Initialize 2D vector to default value (zero vector).
//		param v_out: output vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecInit2, v, type2 v_out)
{

	return v_out;
}

// ijkVecInitElems2*v
//	Initialize 2D vector to specified individual elements.
//		param v_out: output vector
//		param x: first element
//		param y: second element
//		return: v_out
ijk_inl typev tfuncs(ijkVecInitElems2, v, type2 v_out, type const x, type const y)
{

	return v_out;
}

// ijkVecCopy2*v
//	Copy 2D vector from first elements of another vector.
//		param v_out: output vector to hold copy
//		param v_in: input vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecCopy2, v, type2 v_out, type2 const v_in)
{

	return v_out;
}

// ijkVecNegate2*v
//	Negate 2D vector.
//		param v_out: output vector to hold negated
//		param v_in: input vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecNegate2, v, type2 v_out, type2 const v_in)
{

	return v_out;
}

// ijkVecBitNot2*v
//	Calculate component-wise bitwise 'not' of 2D vector.
//		param v_out: output vector to hold component-wise bitwise 'not'
//		param v_in: input vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecBitNot2, v, type2 v_out, type2 const v_in)
{

	return v_out;
}

// ijkVecNot2*v
//	Calculate component-wise logical 'not' of 2D vector.
//		param bv_out: boolean vector to hold component-wise logical 'not'
//		param v_in: input vector
//		return: bv_out
ijk_inl boolv tfuncs(ijkVecNot2, v, bool2 bv_out, type2 const v_in)
{

	return bv_out;
}

// ijkVecAdd2*v
//	Calculate sum of 2D vectors.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecAdd2, v, type2 v_out, type2 const v_lh, type2 const v_rh)
{

	return v_out;
}

// ijkVecSub2*v
//	Calculate difference of 2D vectors.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecSub2, v, type2 v_out, type2 const v_lh, type2 const v_rh)
{

	return v_out;
}

// ijkVecMul2*v
//	Calculate component-wise product of 2D vectors.
//		param v_out: output vector to hold component-wise product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecMul2, v, type2 v_out, type2 const v_lh, type2 const v_rh)
{

	return v_out;
}

// ijkVecDiv2*v
//	Calculate component-wise quotient of 2D vectors.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecDiv2, v, type2 v_out, type2 const v_lh, type2 const v_rh)
{

	return v_out;
}

// ijkVecDivSafe2*v
//	Calculate component-wise quotient of 2D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecDivSafe2, v, type2 v_out, type2 const v_lh, type2 const v_rh)
{

	return v_out;
}

// ijkVecMod2*v
//	Calculate component-wise modulo of 2D vectors.
//		param v_out: output vector to hold component-wise modulo
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecMod2, v, type2 v_out, type2 const v_lh, type2 const v_rh)
{

	return v_out;
}

// ijkVecModSafe2*v
//	Calculate component-wise modulo of 2D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise modulo
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecModSafe2, v, type2 v_out, type2 const v_lh, type2 const v_rh)
{

	return v_out;
}

// ijkVecBitAnd2*v
//	Calculate component-wise bitwise 'and' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'and'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecBitAnd2, v, type2 v_out, type2 const v_lh, type2 const v_rh)
{

	return v_out;
}

// ijkVecBitNand2*v
//	Calculate component-wise bitwise 'not and' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nand'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecBitNand2, v, type2 v_out, type2 const v_lh, type2 const v_rh)
{

	return v_out;
}

// ijkVecBitOr2*v
//	Calculate component-wise bitwise 'or' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'or'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecBitOr2, v, type2 v_out, type2 const v_lh, type2 const v_rh)
{

	return v_out;
}

// ijkVecBitNor2*v
//	Calculate component-wise bitwise 'not or' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecBitNor2, v, type2 v_out, type2 const v_lh, type2 const v_rh)
{

	return v_out;
}

// ijkVecBitXor2*v
//	Calculate component-wise bitwise 'exclusive or' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'xor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecBitXor2, v, type2 v_out, type2 const v_lh, type2 const v_rh)
{

	return v_out;
}

// ijkVecBitNxor2*v
//	Calculate component-wise bitwise 'not exclusive or' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nxor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecBitNxor2, v, type2 v_out, type2 const v_lh, type2 const v_rh)
{

	return v_out;
}

// ijkVecBitShiftLeft2*v
//	Calculate component-wise bit shift left of 2D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecBitShiftLeft2, v, type2 v_out, type2 const v_lh, type2 const v_rh)
{

	return v_out;
}

// ijkVecBitShiftRight2*v
//	Calculate component-wise bit shift right of 2D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecBitShiftRight2, v, type2 v_out, type2 const v_lh, type2 const v_rh)
{

	return v_out;
}

// ijkVecEqual2*v
//	Equality comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
ijk_inl boolv tfuncs(ijkVecEqual2, v, bool2 bv_out, type2 const v_lh, type2 const v_rh)
{

	return bv_out;
}

// ijkVecInequal2*v
//	Inequality comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
ijk_inl boolv tfuncs(ijkVecInequal2, v, bool2 bv_out, type2 const v_lh, type2 const v_rh)
{

	return bv_out;
}

// ijkVecLessEqual2*v
//	Less-than or equal comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
ijk_inl boolv tfuncs(ijkVecLessEqual2, v, bool2 bv_out, type2 const v_lh, type2 const v_rh)
{

	return bv_out;
}

// ijkVecGreaterEqual2*v
//	Greater-than or equal comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
ijk_inl boolv tfuncs(ijkVecGreaterEqual2, v, bool2 bv_out, type2 const v_lh, type2 const v_rh)
{

	return bv_out;
}

// ijkVecLess2*v
//	Less-than comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
ijk_inl boolv tfuncs(ijkVecLess2, v, bool2 bv_out, type2 const v_lh, type2 const v_rh)
{

	return bv_out;
}

// ijkVecGreater2*v
//	Greater-than comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
ijk_inl boolv tfuncs(ijkVecGreater2, v, bool2 bv_out, type2 const v_lh, type2 const v_rh)
{

	return bv_out;
}

// ijkVecCopy2*vs
//	Copy 2D vector from scalar.
//		param v_out: output vector to hold copy
//		param s_in: input scalar
//		return: v_out
ijk_inl typev tfuncs(ijkVecCopy2, vs, type2 v_out, type const s_in)
{

	return v_out;
}

// ijkVecNegate2*vs
//	Negate scalar to 2D vector.
//		param v_out: output vector to hold negated
//		param s_in: input scalar
//		return: v_out
ijk_inl typev tfuncs(ijkVecNegate2, vs, type2 v_out, type const s_in)
{

	return v_out;
}

// ijkVecBitNot2*vs
//	Calculate bitwise 'not' of 2D vector.
//		param v_out: output vector to hold bitwise 'not'
//		param s_in: input scalar
//		return: v_out
ijk_inl typev tfuncs(ijkVecBitNot2, vs, type2 v_out, type const s_in)
{

	return v_out;
}

// ijkVecNot2*vs
//	Calculate logical 'not' of scalar.
//		param bv_out: boolean vector to hold logical 'not'
//		param s_in: input scalar
//		return: bv_out
ijk_inl boolv tfuncs(ijkVecNot2, vs, bool2 bv_out, type const s_in)
{

	return bv_out;
}

// ijkVecAdd2*vs
//	Calculate sum of 2D vector components and scalar.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
ijk_inl typev tfuncs(ijkVecAdd2, vs, type2 v_out, type2 const v_lh, type const s_rh)
{

	return v_out;
}

// ijkVecSub2*vs
//	Calculate difference of 2D vector components and scalar.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
ijk_inl typev tfuncs(ijkVecSub2, vs, type2 v_out, type2 const v_lh, type const s_rh)
{

	return v_out;
}

// ijkVecMul2*vs
//	Calculate product of 2D vector components by scalar.
//		param v_out: output vector to hold product
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
ijk_inl typev tfuncs(ijkVecMul2, vs, type2 v_out, type2 const v_lh, type const s_rh)
{

	return v_out;
}

// ijkVecDiv2*vs
//	Calculate quotient of 2D vector components by scalar.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
ijk_inl typev tfuncs(ijkVecDiv2, vs, type2 v_out, type2 const v_lh, type const s_rh)
{

	return v_out;
}

// ijkVecDivSafe2*vs
//	Calculate quotient of 2D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
ijk_inl typev tfuncs(ijkVecDivSafe2, vs, type2 v_out, type2 const v_lh, type const s_rh)
{

	return v_out;
}

// ijkVecMod2*vs
//	Calculate modulo of 2D vector components by scalar.
//		param v_out: output vector to hold modulo
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
ijk_inl typev tfuncs(ijkVecMod2, vs, type2 v_out, type2 const v_lh, type const s_rh)
{

	return v_out;
}

// ijkVecModSafe2*vs
//	Calculate modulo of 2D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold modulo
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
ijk_inl typev tfuncs(ijkVecModSafe2, vs, type2 v_out, type2 const v_lh, type const s_rh)
{

	return v_out;
}

// ijkVecBitAnd2*vs
//	Calculate bitwise 'and' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'and'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
ijk_inl typev tfuncs(ijkVecBitAnd2, vs, type2 v_out, type2 const v_lh, type const s_rh)
{

	return v_out;
}

// ijkVecBitNand2*vs
//	Calculate bitwise 'not and' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nand'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
ijk_inl typev tfuncs(ijkVecBitNand2, vs, type2 v_out, type2 const v_lh, type const s_rh)
{

	return v_out;
}

// ijkVecBitOr2*vs
//	Calculate bitwise 'or' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'or'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
ijk_inl typev tfuncs(ijkVecBitOr2, vs, type2 v_out, type2 const v_lh, type const s_rh)
{

	return v_out;
}

// ijkVecBitNor2*vs
//	Calculate bitwise 'not or' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
ijk_inl typev tfuncs(ijkVecBitNor2, vs, type2 v_out, type2 const v_lh, type const s_rh)
{

	return v_out;
}

// ijkVecBitXor2*vs
//	Calculate bitwise 'exclusive or' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'xor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
ijk_inl typev tfuncs(ijkVecBitXor2, vs, type2 v_out, type2 const v_lh, type const s_rh)
{

	return v_out;
}

// ijkVecBitNxor2*vs
//	Calculate bitwise 'not exclusive or' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nxor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
ijk_inl typev tfuncs(ijkVecBitNxor2, vs, type2 v_out, type2 const v_lh, type const s_rh)
{

	return v_out;
}

// ijkVecBitShiftLeft2*vs
//	Calculate bit shift left of 2D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
ijk_inl typev tfuncs(ijkVecBitShiftLeft2, vs, type2 v_out, type2 const v_lh, type const s_rh)
{

	return v_out;
}

// ijkVecBitShiftRight2*vs
//	Calculate bit shift right of 2D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
ijk_inl typev tfuncs(ijkVecBitShiftRight2, vs, type2 v_out, type2 const v_lh, type const s_rh)
{

	return v_out;
}

// ijkVecEqual2*vs
//	Equality comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
ijk_inl boolv tfuncs(ijkVecEqual2, vs, bool2 bv_out, type2 const v_lh, type const s_rh)
{

	return bv_out;
}

// ijkVecInequal2*vs
//	Inequality comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
ijk_inl boolv tfuncs(ijkVecInequal2, vs, bool2 bv_out, type2 const v_lh, type const s_rh)
{

	return bv_out;
}

// ijkVecLessEqual2*vs
//	Less-than or equal comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
ijk_inl boolv tfuncs(ijkVecLessEqual2, vs, bool2 bv_out, type2 const v_lh, type const s_rh)
{

	return bv_out;
}

// ijkVecGreaterEqual2*vs
//	Greater-than or equal comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
ijk_inl boolv tfuncs(ijkVecGreaterEqual2, vs, bool2 bv_out, type2 const v_lh, type const s_rh)
{

	return bv_out;
}

// ijkVecLess2*vs
//	Less-than comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
ijk_inl boolv tfuncs(ijkVecLess2, vs, bool2 bv_out, type2 const v_lh, type const s_rh)
{

	return bv_out;
}

// ijkVecGreater2*vs
//	Greater-than comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
ijk_inl boolv tfuncs(ijkVecGreater2, vs, bool2 bv_out, type2 const v_lh, type const s_rh)
{

	return bv_out;
}

// ijkVecAdd2*sv
//	Calculate sum of scalar and 2D vector components.
//		param v_out: output vector to hold sum
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecAdd2, sv, type2 v_out, type const s_lh, type2 const v_rh)
{

	return v_out;
}

// ijkVecSub2*sv
//	Calculate difference of scalar and 2D vector components.
//		param v_out: output vector to hold difference
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecSub2, sv, type2 v_out, type const s_lh, type2 const v_rh)
{

	return v_out;
}

// ijkVecMul2*sv
//	Calculate product of scalar by 2D vector components.
//		param v_out: output vector to hold product
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecMul2, sv, type2 v_out, type const s_lh, type2 const v_rh)
{

	return v_out;
}

// ijkVecDiv2*sv
//	Calculate quotient of scalar by 2D vector components.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecDiv2, sv, type2 v_out, type const s_lh, type2 const v_rh)
{

	return v_out;
}

// ijkVecDivSafe2*sv
//	Calculate quotient of scalar by 2D vector components, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecDivSafe2, sv, type2 v_out, type const s_lh, type2 const v_rh)
{

	return v_out;
}

// ijkVecMod2*sv
//	Calculate modulo of scalar by 2D vector components.
//		param v_out: output vector to hold modulo
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecMod2, sv, type2 v_out, type const s_lh, type2 const v_rh)
{

	return v_out;
}

// ijkVecModSafe2*sv
//	Calculate modulo of scalar by 2D vector components, division-by-zero safe.
//		param v_out: output vector to hold modulo
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecModSafe2, sv, type2 v_out, type const s_lh, type2 const v_rh)
{

	return v_out;
}

// ijkVecBitAnd2*sv
//	Calculate bitwise 'and' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'and'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecBitAnd2, sv, type2 v_out, type const s_lh, type2 const v_rh)
{

	return v_out;
}

// ijkVecBitNand2*sv
//	Calculate bitwise 'not and' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'nand'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecBitNand2, sv, type2 v_out, type const s_lh, type2 const v_rh)
{

	return v_out;
}

// ijkVecBitOr2*sv
//	Calculate bitwise 'or' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'or'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecBitOr2, sv, type2 v_out, type const s_lh, type2 const v_rh)
{

	return v_out;
}

// ijkVecBitNor2*sv
//	Calculate bitwise 'not or' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'nor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecBitNor2, sv, type2 v_out, type const s_lh, type2 const v_rh)
{

	return v_out;
}

// ijkVecBitXor2*sv
//	Calculate bitwise 'exclusive or' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'xor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecBitXor2, sv, type2 v_out, type const s_lh, type2 const v_rh)
{

	return v_out;
}

// ijkVecBitNxor2*sv
//	Calculate bitwise 'not exclusive or' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'nxor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecBitNxor2, sv, type2 v_out, type const s_lh, type2 const v_rh)
{

	return v_out;
}

// ijkVecBitShiftLeft2*sv
//	Calculate bit shift left of scalar by 2D vector components.
//		param v_out: output vector to hold bit shift
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecBitShiftLeft2, sv, type2 v_out, type const s_lh, type2 const v_rh)
{

	return v_out;
}

// ijkVecBitShiftRight2*sv
//	Calculate bit shift right of scalar by 2D vector components.
//		param v_out: output vector to hold bit shift
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecBitShiftRight2, sv, type2 v_out, type const s_lh, type2 const v_rh)
{

	return v_out;
}

// ijkVecEqual2*sv
//	Equality comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
ijk_inl boolv tfuncs(ijkVecEqual2, sv, bool2 bv_out, type const s_lh, type2 const v_rh)
{

	return bv_out;
}

// ijkVecInequal2*sv
//	Inequality comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
ijk_inl boolv tfuncs(ijkVecInequal2, sv, bool2 bv_out, type const s_lh, type2 const v_rh)
{

	return bv_out;
}

// ijkVecLessEqual2*sv
//	Less-than or equal comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
ijk_inl boolv tfuncs(ijkVecLessEqual2, sv, bool2 bv_out, type const s_lh, type2 const v_rh)
{

	return bv_out;
}

// ijkVecGreaterEqual2*sv
//	Greater-than or equal comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
ijk_inl boolv tfuncs(ijkVecGreaterEqual2, sv, bool2 bv_out, type const s_lh, type2 const v_rh)
{

	return bv_out;
}

// ijkVecLess2*sv
//	Less-than comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
ijk_inl boolv tfuncs(ijkVecLess2, sv, bool2 bv_out, type const s_lh, type2 const v_rh)
{

	return bv_out;
}

// ijkVecGreater2*sv
//	Greater-than comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
ijk_inl boolv tfuncs(ijkVecGreater2, sv, bool2 bv_out, type const s_lh, type2 const v_rh)
{

	return bv_out;
}

// ijkVecDot2*v
//	Dot product of 2D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
ijk_inl type tfuncs(ijkVecDot2, v, type2 const v_lh, type2 const v_rh)
{
	return (v_lh[0] * v_rh[0] + v_lh[1] * v_rh[1]);
}

// ijkVecCross2*v
//	Cross product scalar of 2D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar quantity of imaginary perpendicular axis
ijk_inl type tfuncs(ijkVecCross2, v, type2 const v_lh, type2 const v_rh)
{
	return (v_lh[0] * v_rh[1] - v_lh[1] * v_rh[0]);
}


//-----------------------------------------------------------------------------

// ijkVecDot3*v
//	Dot product of 3D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
ijk_inl type tfuncs(ijkVecDot3, v, type3 const v_lh, type3 const v_rh)
{
	return (v_lh[0] * v_rh[0] + v_lh[1] * v_rh[1] + v_lh[2] * v_rh[2]);
}

// ijkVecCross3*v
//	Cross product of 3D array-based vectors.
//		param v_out: output vector to hold cross product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(ijkVecCross3, v, type3 v_out, type3 const v_lh, type3 const v_rh)
{
	v_out[0] = (v_lh[1] * v_rh[2] - v_lh[2] * v_rh[1]);
	v_out[1] = (v_lh[2] * v_rh[0] - v_lh[0] * v_rh[2]);
	v_out[2] = (v_lh[0] * v_rh[1] - v_lh[1] * v_rh[0]);
	return v_out;
}


//-----------------------------------------------------------------------------

// ijkVecDot4*v
//	Dot product of 4D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
ijk_inl type tfuncs(ijkVecDot4, v, type4 const v_lh, type4 const v_rh)
{
	return (v_lh[0] * v_rh[0] + v_lh[1] * v_rh[1] + v_lh[2] * v_rh[2] + v_lh[3] * v_rh[3]);
}

// ijkVecCross4*v
//	Cross product of 4D array-based vectors.
//		param v_out: output vector to hold cross product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out (fourth element is zero)
ijk_inl typev tfuncs(ijkVecCross4, v, type4 v_out, type4 const v_lh, type4 const v_rh)
{
	v_out[3] = (type)0;
	return tfuncs(ijkVecCross3, v, v_out, v_lh, v_rh);
}


//-----------------------------------------------------------------------------

// ijkVecAbs1*
//	Absolute value of scalar: (s >= 0 ? +s : -s).
//		param s: scalar
//		return: absolute value
ijk_inl type tfunc(ijkVecAbs1, type const s)
{
	return tfuncs(ijkVecAbs1, s, s);
}

// ijkVecSgn1*
//	Sign of scalar: (s != 0 ? s > 0 ? +1 : -1).
//		param s: scalar
//		return: sign
ijk_inl type tfunc(ijkVecSgn1, type const s)
{
	return tfuncs(ijkVecSgn1, s, s);
}

// ijkVecDot1*
//	Dot product of scalars, which is just their product.
//		param s_lh: left-hand scalar
//		param s_rh: right-hand scalar
//		return: product
ijk_inl tvec tfunc(ijkVecDot1, tvec const s_lh, tvec const s_rh)
{
	return tfuncs(ijkVecDot1, s, s_lh, s_rh);
}

// ijkVecLengthSq1*
//	Squared length of scalar.
//		param s: scalar
//		return: squared length
ijk_inl tvec tfunc(ijkVecLengthSq1, tvec const s)
{
	return tfuncs(ijkVecLengthSq1, s, s);
}

// ijkVecLength1*
//	Length of scalar.
//		param s: scalar
//		return: length
ijk_inl tvec tfunc(ijkVecLength1, tvec const s)
{
	return tfuncs(ijkVecLength1, s, s);
}

// ijkVecLengthSqInv1*
//	Inverse squared length of scalar.
//		param s: scalar
//		return: inverse squared length
ijk_inl tvec tfunc(ijkVecLengthSqInv1, tvec const s)
{
	return tfuncs(ijkVecLengthSqInv1, s, s);
}

// ijkVecLengthSqInv1*
//	Inverse length of scalar.
//		param s: scalar
//		return: inverse length
ijk_inl tvec tfunc(ijkVecLengthInv1, tvec const s)
{
	return tfuncs(ijkVecLengthInv1, s, s);
}

// ijkVecNormalize1*
//	Calculate unit scalar in same direction as input (sign).
//		param s: scalar
//		return: unit scalar (sign)
ijk_inl tvec tfunc(ijkVecNormalize1, tvec const s)
{
	return tfuncs(ijkVecNormalize1, s, s);
}

// ijkVecNormalizeGetLength1*
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the length (absolute value).
//		param s: scalar
//		param length_out: pointer to length storage
//		return: unit scalar (sign)
ijk_inl tvec tfunc(ijkVecNormalizeGetLength1, tvec const s, tvec* const length_out)
{
	return tfuncs(ijkVecNormalizeGetLength1, s, s, (type*)length_out);
}

// ijkVecNormalizeGetLengthInv1*
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the inverse length length (absolute value).
//		param s: scalar
//		param lengthInv_out: pointer to length storage
//		return: unit scalar (sign)
ijk_inl tvec tfunc(ijkVecNormalizeGetLengthInv1, tvec const s, tvec* const lengthInv_out)
{
	return tfuncs(ijkVecNormalizeGetLength1, s, s, (type*)lengthInv_out);
}


//-----------------------------------------------------------------------------

// ijkVecDot2*
//	Dot product of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
ijk_inl tvec tfunc(ijkVecDot2, tvec2 const v_lh, tvec2 const v_rh)
{
	return tfuncs(ijkVecDot2, v, v_lh.xy, v_rh.xy);
}

// ijkVecCross2*
//	Cross product scalar of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar quantity of imaginary perpendicular axis
ijk_inl tvec tfunc(ijkVecCross2, tvec2 const v_lh, tvec2 const v_rh)
{
	return tfuncs(ijkVecCross2, v, v_lh.xy, v_rh.xy);
}


//-----------------------------------------------------------------------------

// ijkVecDot3*
//	Dot product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
ijk_inl tvec tfunc(ijkVecDot3, tvec3 const v_lh, tvec3 const v_rh)
{
	return tfuncs(ijkVecDot3, v, v_lh.xyz, v_rh.xyz);
}

// ijkVecCross3*
//	Cross product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: cross product
ijk_inl tvec3 tfunc(ijkVecCross3, tvec3 const v_lh, tvec3 const v_rh)
{
	tvec3 v_out;
	tfuncs(ijkVecCross3, v, v_out.xyz, v_lh.xyz, v_rh.xyz);
	return v_out;
}


//-----------------------------------------------------------------------------

// ijkVecDot4*
//	Dot product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
ijk_inl tvec tfunc(ijkVecDot4, tvec4 const v_lh, tvec4 const v_rh)
{
	return tfuncs(ijkVecDot4, v, v_lh.xyzw, v_rh.xyzw);
}

// ijkVecCross4*
//	Cross product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: cross product (fourth component is zero)
ijk_inl tvec4 tfunc(ijkVecCross4, tvec4 const v_lh, tvec4 const v_rh)
{
	tvec4 v_out;
	tfuncs(ijkVecCross4, v, v_out.xyzw, v_lh.xyzw, v_rh.xyzw);
	return v_out;
}


//-----------------------------------------------------------------------------


#undef _IJK_VECTORFUNC_INL_
#endif	// !_IJK_VECTORFUNC_INL_
#endif	// (_IJK_VECTORFUNC_H_ == IJK_VECTORFUNC_TYPE)