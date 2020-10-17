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