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

// dot1*s
//	Dot product of scalars, which is just their product.
//		param s_lh: left-hand scalar
//		param s_rh: right-hand scalar
//		return: product
ijk_inl type tfuncs(dot1, s, type const s_lh, type const s_rh)
{
	return (s_lh * s_rh);
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

// dot1*
//	Dot product of scalars, which is just their product.
//		param s_lh: left-hand scalar
//		param s_rh: right-hand scalar
//		return: product
ijk_inl tvec tfunc(dot1, tvec const s_lh, tvec const s_rh)
{
	return tfuncs(dot1, s, s_lh, s_rh);
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