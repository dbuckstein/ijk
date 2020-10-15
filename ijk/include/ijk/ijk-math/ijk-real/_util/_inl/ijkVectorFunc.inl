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

#if (_IJK_VECTORFUNC_H_ == ijk_tokencat(IJK_VECTORFUNC_PREFIX, IJK_VECTORFUNC_H))
#ifndef _IJK_VECTORFUNC_INL_
#define _IJK_VECTORFUNC_INL_ ijk_tokencat(IJK_VECTORFUNC_PREFIX, IJK_VECTORFUNC_INL)


//-----------------------------------------------------------------------------

// abs1*s
//	Absolute value of scalar: (s >= 0 ? +s : -s).
//		param s: scalar
//		return: absolute value
ijk_inl type tfuncs(abs1, s, type const s)
{
	return tabs(s);
}

// sgn1*s
//	Sign of scalar: (s != 0 ? s > 0 ? +1 : -1).
//		param s: scalar
//		return: sign
ijk_inl type tfuncs(sgn1, s, type const s)
{
	return tsgn(s);
}

// dot1*s
//	Dot product of scalars, which is just their product.
//		param s_lh: left-hand scalar
//		param s_rh: right-hand scalar
//		return: product
ijk_inl type tfuncs(dot1, s, type const s_lh, type const s_rh)
{
	return (s_lh * s_rh);
}

// lengthSq1*s
//	Squared length of scalar.
//		param s: scalar
//		return: squared length
ijk_inl type tfuncs(lengthSq1, s, type const s)
{
	return (s * s);
}

// length1*s
//	Length of scalar.
//		param s: scalar
//		return: length
ijk_inl type tfuncs(length1, s, type const s)
{
	return tabs(s);
}

// lengthSqInv1*s
//	Inverse squared length of scalar.
//		param s: scalar
//		return: inverse squared length
ijk_inl type tfuncs(lengthSqInv1, s, type const s)
{
	type const lengthSq = (s * s);
	return trecip(lengthSq);
}

// lengthSqInv1*s
//	Inverse length of scalar.
//		param s: scalar
//		return: inverse length
ijk_inl type tfuncs(lengthInv1, s, type const s)
{
	type const length = tabs(s);
	return trecip(length);
}

// normalize1*s
//	Calculate unit scalar in same direction as input (sign).
//		param s: scalar
//		return: unit scalar (sign)
ijk_inl type tfuncs(normalize1, s, type const s)
{
	return tsgn(s);
}

// normalizeGetLength1*s
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the length (absolute value).
//		param s: scalar
//		param length_out: pointer to length storage
//		return: unit scalar (sign)
ijk_inl type tfuncs(normalizeGetLength1, s, type const s, type* const length_out)
{
	type const length = *length_out = tabs(s);
	return (s * trecip(length));
}

// normalizeGetLengthInv1*s
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the inverse length length (absolute value).
//		param s: scalar
//		param lengthInv_out: pointer to length storage
//		return: unit scalar (sign)
ijk_inl type tfuncs(normalizeGetLengthInv1, s, type const s, type* const lengthInv_out)
{
	type const length = tabs(s);
	return (s * (*lengthInv_out = trecip(length)));
}


//-----------------------------------------------------------------------------

// dot2*v
//	Dot product of 2D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
ijk_inl type tfuncs(dot2, v, type2 const v_lh, type2 const v_rh)
{
	return (v_lh[0] * v_rh[0] + v_lh[1] * v_rh[1]);
}

// cross2*v
//	Cross product scalar of 2D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar quantity of imaginary perpendicular axis
ijk_inl type tfuncs(cross2, v, type2 const v_lh, type2 const v_rh)
{
	return (v_lh[0] * v_rh[1] - v_lh[1] * v_rh[0]);
}


//-----------------------------------------------------------------------------

// dot3*v
//	Dot product of 3D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
ijk_inl type tfuncs(dot3, v, type3 const v_lh, type3 const v_rh)
{
	return (v_lh[0] * v_rh[0] + v_lh[1] * v_rh[1] + v_lh[2] * v_rh[2]);
}

// cross3*v
//	Cross product of 3D array-based vectors.
//		param v_out: output vector to hold cross product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
ijk_inl typev tfuncs(cross3, v, type3 v_out, type3 const v_lh, type3 const v_rh)
{
	v_out[0] = (v_lh[1] * v_rh[2] - v_lh[2] * v_rh[1]);
	v_out[1] = (v_lh[2] * v_rh[0] - v_lh[0] * v_rh[2]);
	v_out[2] = (v_lh[0] * v_rh[1] - v_lh[1] * v_rh[0]);
	return v_out;
}


//-----------------------------------------------------------------------------

// dot4*v
//	Dot product of 4D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
ijk_inl type tfuncs(dot4, v, type4 const v_lh, type4 const v_rh)
{
	return (v_lh[0] * v_rh[0] + v_lh[1] * v_rh[1] + v_lh[2] * v_rh[2] + v_lh[3] * v_rh[3]);
}

// cross4*v
//	Cross product of 4D array-based vectors.
//		param v_out: output vector to hold cross product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out (fourth element is zero)
ijk_inl typev tfuncs(cross4, v, type4 v_out, type4 const v_lh, type4 const v_rh)
{
	v_out[3] = (type)0;
	return tfuncs(cross3, v, v_out, v_lh, v_rh);
}


//-----------------------------------------------------------------------------

// abs1*
//	Absolute value of scalar: (s >= 0 ? +s : -s).
//		param s: scalar
//		return: absolute value
ijk_inl type tfunc(abs1, type const s)
{
	return tfuncs(abs1, s, s);
}

// sgn1*
//	Sign of scalar: (s != 0 ? s > 0 ? +1 : -1).
//		param s: scalar
//		return: sign
ijk_inl type tfunc(sgn1, type const s)
{
	return tfuncs(sgn1, s, s);
}

// dot1*
//	Dot product of scalars, which is just their product.
//		param s_lh: left-hand scalar
//		param s_rh: right-hand scalar
//		return: product
ijk_inl tvec tfunc(dot1, tvec const s_lh, tvec const s_rh)
{
	return tfuncs(dot1, s, s_lh, s_rh);
}

// lengthSq1*
//	Squared length of scalar.
//		param s: scalar
//		return: squared length
ijk_inl tvec tfunc(lengthSq1, tvec const s)
{
	return tfuncs(lengthSq1, s, s);
}

// length1*
//	Length of scalar.
//		param s: scalar
//		return: length
ijk_inl tvec tfunc(length1, tvec const s)
{
	return tfuncs(length1, s, s);
}

// lengthSqInv1*
//	Inverse squared length of scalar.
//		param s: scalar
//		return: inverse squared length
ijk_inl tvec tfunc(lengthSqInv1, tvec const s)
{
	return tfuncs(lengthSqInv1, s, s);
}

// lengthSqInv1*
//	Inverse length of scalar.
//		param s: scalar
//		return: inverse length
ijk_inl tvec tfunc(lengthInv1, tvec const s)
{
	return tfuncs(lengthInv1, s, s);
}

// normalize1*
//	Calculate unit scalar in same direction as input (sign).
//		param s: scalar
//		return: unit scalar (sign)
ijk_inl tvec tfunc(normalize1, tvec const s)
{
	return tfuncs(normalize1, s, s);
}

// normalizeGetLength1*
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the length (absolute value).
//		param s: scalar
//		param length_out: pointer to length storage
//		return: unit scalar (sign)
ijk_inl tvec tfunc(normalizeGetLength1, tvec const s, tvec* const length_out)
{
	return tfuncs(normalizeGetLength1, s, s, (type*)length_out);
}

// normalizeGetLengthInv1*
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the inverse length length (absolute value).
//		param s: scalar
//		param lengthInv_out: pointer to length storage
//		return: unit scalar (sign)
ijk_inl tvec tfunc(normalizeGetLengthInv1, tvec const s, tvec* const lengthInv_out)
{
	return tfuncs(normalizeGetLength1, s, s, (type*)lengthInv_out);
}


//-----------------------------------------------------------------------------

// dot2*
//	Dot product of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
ijk_inl tvec tfunc(dot2, tvec2 const v_lh, tvec2 const v_rh)
{
	return tfuncs(dot2, v, v_lh.xy, v_rh.xy);
}

// cross2*
//	Cross product scalar of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar quantity of imaginary perpendicular axis
ijk_inl tvec tfunc(cross2, tvec2 const v_lh, tvec2 const v_rh)
{
	return tfuncs(cross2, v, v_lh.xy, v_rh.xy);
}


//-----------------------------------------------------------------------------

// dot3*
//	Dot product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
ijk_inl tvec tfunc(dot3, tvec3 const v_lh, tvec3 const v_rh)
{
	return tfuncs(dot3, v, v_lh.xyz, v_rh.xyz);
}

// cross3*
//	Cross product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: cross product
ijk_inl tvec3 tfunc(cross3, tvec3 const v_lh, tvec3 const v_rh)
{
	tvec3 v_out;
	tfuncs(cross3, v, v_out.xyz, v_lh.xyz, v_rh.xyz);
	return v_out;
}


//-----------------------------------------------------------------------------

// dot4*
//	Dot product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
ijk_inl tvec tfunc(dot4, tvec4 const v_lh, tvec4 const v_rh)
{
	return tfuncs(dot4, v, v_lh.xyzw, v_rh.xyzw);
}

// cross4*
//	Cross product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: cross product (fourth component is zero)
ijk_inl tvec4 tfunc(cross4, tvec4 const v_lh, tvec4 const v_rh)
{
	tvec4 v_out;
	tfuncs(cross4, v, v_out.xyzw, v_lh.xyzw, v_rh.xyzw);
	return v_out;
}


//-----------------------------------------------------------------------------


#undef _IJK_VECTORFUNC_INL_
#endif	// !_IJK_VECTORFUNC_INL_
#endif	// (_IJK_VECTORFUNC_H_ == ijk_tokencat(IJK_VECTORFUNC_PREFIX, IJK_VECTORFUNC_H))