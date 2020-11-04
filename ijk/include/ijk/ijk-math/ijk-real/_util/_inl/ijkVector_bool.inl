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

#ifdef _IJK_VECTOR_BOOL_H_
#ifndef _IJK_VECTOR_BOOL_INL_
#define _IJK_VECTOR_BOOL_INL_


//-----------------------------------------------------------------------------

ijk_inl boolv ijkVecInitElems2bv(bool2 v_out, bool const x, bool const y)
{
	v_out[0] = ijk_istrue(x);
	v_out[1] = ijk_istrue(y);
	return v_out;
}

ijk_inl boolv ijkVecCopy2bv(bool2 v_out, bool2 const v_in)
{
	v_out[0] = ijk_istrue(v_in[0]);
	v_out[1] = ijk_istrue(v_in[1]);
	return v_out;
}

ijk_inl boolv ijkVecNot2bv(bool2 v_out, bool2 const v_in)
{
	v_out[0] = ijk_isfalse(v_in[0]);
	v_out[1] = ijk_isfalse(v_in[1]);
	return v_out;
}

ijk_inl boolv ijkVecEqual2bv(bool2 v_out, bool2 const v_lh, bool2 const v_rh)
{
	v_out[0] = (v_lh[0] == v_rh[0]);
	v_out[1] = (v_lh[1] == v_rh[1]);
	return v_out;
}

ijk_inl boolv ijkVecInequal2bv(bool2 v_out, bool2 const v_lh, bool2 const v_rh)
{
	v_out[0] = (v_lh[0] != v_rh[0]);
	v_out[1] = (v_lh[1] != v_rh[1]);
	return v_out;
}

ijk_inl boolv ijkVecAnd2bv(bool2 v_out, bool2 const v_lh, bool2 const v_rh)
{
	v_out[0] = (v_lh[0] && v_rh[0]);
	v_out[1] = (v_lh[1] && v_rh[1]);
	return v_out;
}

ijk_inl boolv ijkVecNand2bv(bool2 v_out, bool2 const v_lh, bool2 const v_rh)
{
	v_out[0] = !(v_lh[0] && v_rh[0]);
	v_out[1] = !(v_lh[1] && v_rh[1]);
	return v_out;
}

ijk_inl boolv ijkVecOr2bv(bool2 v_out, bool2 const v_lh, bool2 const v_rh)
{
	v_out[0] = (v_lh[0] || v_rh[0]);
	v_out[1] = (v_lh[1] || v_rh[1]);
	return v_out;
}

ijk_inl boolv ijkVecNor2bv(bool2 v_out, bool2 const v_lh, bool2 const v_rh)
{
	v_out[0] = !(v_lh[0] || v_rh[0]);
	v_out[1] = !(v_lh[1] || v_rh[1]);
	return v_out;
}

ijk_inl boolv ijkVecCopy2bvs(bool2 v_out, bool const s_in)
{
	v_out[0] = v_out[1] = ijk_istrue(s_in);
	return v_out;
}

ijk_inl boolv ijkVecNot2bvs(bool2 v_out, bool const s_in)
{
	v_out[0] = v_out[1] = ijk_isfalse(s_in);
	return v_out;
}

ijk_inl boolv ijkVecEqual2bvs(bool2 v_out, bool2 const v_lh, bool const s_rh)
{
	v_out[0] = ((bool)v_lh[0] == s_rh);
	v_out[1] = ((bool)v_lh[1] == s_rh);
	return v_out;
}

ijk_inl boolv ijkVecInequal2bvs(bool2 v_out, bool2 const v_lh, bool const s_rh)
{
	v_out[0] = ((bool)v_lh[0] != s_rh);
	v_out[1] = ((bool)v_lh[1] != s_rh);
	return v_out;
}

ijk_inl boolv ijkVecAnd2bvs(bool2 v_out, bool2 const v_lh, bool const s_rh)
{
	v_out[0] = (v_lh[0] && s_rh);
	v_out[1] = (v_lh[1] && s_rh);
	return v_out;
}

ijk_inl boolv ijkVecNand2bvs(bool2 v_out, bool2 const v_lh, bool const s_rh)
{
	v_out[0] = !(v_lh[0] && s_rh);
	v_out[1] = !(v_lh[1] && s_rh);
	return v_out;
}

ijk_inl boolv ijkVecOr2bvs(bool2 v_out, bool2 const v_lh, bool const s_rh)
{
	v_out[0] = (v_lh[0] || s_rh);
	v_out[1] = (v_lh[1] || s_rh);
	return v_out;
}

ijk_inl boolv ijkVecNor2bvs(bool2 v_out, bool2 const v_lh, bool const s_rh)
{
	v_out[0] = !(v_lh[0] || s_rh);
	v_out[1] = !(v_lh[1] || s_rh);
	return v_out;
}

ijk_inl boolv ijkVecEqual2bsv(bool2 v_out, bool const s_lh, bool2 const v_rh)
{
	v_out[0] = (s_lh == (bool)v_rh[0]);
	v_out[1] = (s_lh == (bool)v_rh[1]);
	return v_out;
}

ijk_inl boolv ijkVecInequal2bsv(bool2 v_out, bool const s_lh, bool2 const v_rh)
{
	v_out[0] = (s_lh != (bool)v_rh[0]);
	v_out[1] = (s_lh != (bool)v_rh[1]);
	return v_out;
}

ijk_inl boolv ijkVecAnd2bsv(bool2 v_out, bool const s_lh, bool2 const v_rh)
{
	v_out[0] = (s_lh && (bool)v_rh[0]);
	v_out[1] = (s_lh && (bool)v_rh[1]);
	return v_out;
}

ijk_inl boolv ijkVecNand2bsv(bool2 v_out, bool const s_lh, bool2 const v_rh)
{
	v_out[0] = !(s_lh && (bool)v_rh[0]);
	v_out[1] = !(s_lh && (bool)v_rh[1]);
	return v_out;
}

ijk_inl boolv ijkVecOr2bsv(bool2 v_out, bool const s_lh, bool2 const v_rh)
{
	v_out[0] = (s_lh || (bool)v_rh[0]);
	v_out[1] = (s_lh || (bool)v_rh[1]);
	return v_out;
}

ijk_inl boolv ijkVecNor2bsv(bool2 v_out, bool const s_lh, bool2 const v_rh)
{
	v_out[0] = !(s_lh || (bool)v_rh[0]);
	v_out[1] = !(s_lh || (bool)v_rh[1]);
	return v_out;
}


//-----------------------------------------------------------------------------

ijk_inl boolv ijkVecInitElems3bv(bool3 v_out, bool const x, bool const y, bool const z)
{
	v_out[0] = ijk_istrue(x);
	v_out[1] = ijk_istrue(y);
	v_out[2] = ijk_istrue(z);
	return v_out;
}

ijk_inl boolv ijkVecCopy3bv(bool3 v_out, bool3 const v_in)
{
	v_out[0] = ijk_istrue(v_in[0]);
	v_out[1] = ijk_istrue(v_in[1]);
	v_out[2] = ijk_istrue(v_in[2]);
	return v_out;
}

ijk_inl boolv ijkVecNot3bv(bool3 v_out, bool3 const v_in)
{
	v_out[0] = ijk_isfalse(v_in[0]);
	v_out[1] = ijk_isfalse(v_in[1]);
	v_out[2] = ijk_isfalse(v_in[2]);
	return v_out;
}

ijk_inl boolv ijkVecEqual3bv(bool3 v_out, bool3 const v_lh, bool3 const v_rh)
{
	v_out[0] = (v_lh[0] == v_rh[0]);
	v_out[1] = (v_lh[1] == v_rh[1]);
	v_out[2] = (v_lh[2] == v_rh[2]);
	return v_out;
}

ijk_inl boolv ijkVecInequal3bv(bool3 v_out, bool3 const v_lh, bool3 const v_rh)
{
	v_out[0] = (v_lh[0] != v_rh[0]);
	v_out[1] = (v_lh[1] != v_rh[1]);
	v_out[2] = (v_lh[2] != v_rh[2]);
	return v_out;
}

ijk_inl boolv ijkVecAnd3bv(bool3 v_out, bool3 const v_lh, bool3 const v_rh)
{
	v_out[0] = (v_lh[0] && v_rh[0]);
	v_out[1] = (v_lh[1] && v_rh[1]);
	v_out[2] = (v_lh[2] && v_rh[2]);
	return v_out;
}

ijk_inl boolv ijkVecNand3bv(bool3 v_out, bool3 const v_lh, bool3 const v_rh)
{
	v_out[0] = !(v_lh[0] && v_rh[0]);
	v_out[1] = !(v_lh[1] && v_rh[1]);
	v_out[2] = !(v_lh[2] && v_rh[2]);
	return v_out;
}

ijk_inl boolv ijkVecOr3bv(bool3 v_out, bool3 const v_lh, bool3 const v_rh)
{
	v_out[0] = (v_lh[0] || v_rh[0]);
	v_out[1] = (v_lh[1] || v_rh[1]);
	v_out[2] = (v_lh[2] || v_rh[2]);
	return v_out;
}

ijk_inl boolv ijkVecNor3bv(bool3 v_out, bool3 const v_lh, bool3 const v_rh)
{
	v_out[0] = !(v_lh[0] || v_rh[0]);
	v_out[1] = !(v_lh[1] || v_rh[1]);
	v_out[2] = !(v_lh[2] || v_rh[2]);
	return v_out;
}

ijk_inl boolv ijkVecCopy3bvs(bool3 v_out, bool const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = ijk_istrue(s_in);
	return v_out;
}

ijk_inl boolv ijkVecNot3bvs(bool3 v_out, bool const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = ijk_isfalse(s_in);
	return v_out;
}

ijk_inl boolv ijkVecEqual3bvs(bool3 v_out, bool3 const v_lh, bool const s_rh)
{
	v_out[0] = ((bool)v_lh[0] == s_rh);
	v_out[1] = ((bool)v_lh[1] == s_rh);
	v_out[2] = ((bool)v_lh[2] == s_rh);
	return v_out;
}

ijk_inl boolv ijkVecInequal3bvs(bool3 v_out, bool3 const v_lh, bool const s_rh)
{
	v_out[0] = ((bool)v_lh[0] != s_rh);
	v_out[1] = ((bool)v_lh[1] != s_rh);
	v_out[2] = ((bool)v_lh[2] != s_rh);
	return v_out;
}

ijk_inl boolv ijkVecAnd3bvs(bool3 v_out, bool3 const v_lh, bool const s_rh)
{
	v_out[0] = (v_lh[0] && s_rh);
	v_out[1] = (v_lh[1] && s_rh);
	v_out[2] = (v_lh[2] && s_rh);
	return v_out;
}

ijk_inl boolv ijkVecNand3bvs(bool3 v_out, bool3 const v_lh, bool const s_rh)
{
	v_out[0] = !(v_lh[0] && s_rh);
	v_out[1] = !(v_lh[1] && s_rh);
	v_out[2] = !(v_lh[2] && s_rh);
	return v_out;
}

ijk_inl boolv ijkVecOr3bvs(bool3 v_out, bool3 const v_lh, bool const s_rh)
{
	v_out[0] = (v_lh[0] || s_rh);
	v_out[1] = (v_lh[1] || s_rh);
	v_out[2] = (v_lh[2] || s_rh);
	return v_out;
}

ijk_inl boolv ijkVecNor3bvs(bool3 v_out, bool3 const v_lh, bool const s_rh)
{
	v_out[0] = !(v_lh[0] || s_rh);
	v_out[1] = !(v_lh[1] || s_rh);
	v_out[2] = !(v_lh[2] || s_rh);
	return v_out;
}

ijk_inl boolv ijkVecEqual3bsv(bool3 v_out, bool const s_lh, bool3 const v_rh)
{
	v_out[0] = (s_lh == (bool)v_rh[0]);
	v_out[1] = (s_lh == (bool)v_rh[1]);
	v_out[2] = (s_lh == (bool)v_rh[2]);
	return v_out;
}

ijk_inl boolv ijkVecInequal3bsv(bool3 v_out, bool const s_lh, bool3 const v_rh)
{
	v_out[0] = (s_lh != (bool)v_rh[0]);
	v_out[1] = (s_lh != (bool)v_rh[1]);
	v_out[2] = (s_lh != (bool)v_rh[2]);
	return v_out;
}

ijk_inl boolv ijkVecAnd3bsv(bool3 v_out, bool const s_lh, bool3 const v_rh)
{
	v_out[0] = (s_lh && (bool)v_rh[0]);
	v_out[1] = (s_lh && (bool)v_rh[1]);
	v_out[2] = (s_lh && (bool)v_rh[2]);
	return v_out;
}

ijk_inl boolv ijkVecNand3bsv(bool3 v_out, bool const s_lh, bool3 const v_rh)
{
	v_out[0] = !(s_lh && (bool)v_rh[0]);
	v_out[1] = !(s_lh && (bool)v_rh[1]);
	v_out[2] = !(s_lh && (bool)v_rh[2]);
	return v_out;
}

ijk_inl boolv ijkVecOr3bsv(bool3 v_out, bool const s_lh, bool3 const v_rh)
{
	v_out[0] = (s_lh || (bool)v_rh[0]);
	v_out[1] = (s_lh || (bool)v_rh[1]);
	v_out[2] = (s_lh || (bool)v_rh[2]);
	return v_out;
}

ijk_inl boolv ijkVecNor3bsv(bool3 v_out, bool const s_lh, bool3 const v_rh)
{
	v_out[0] = !(s_lh || (bool)v_rh[0]);
	v_out[1] = !(s_lh || (bool)v_rh[1]);
	v_out[2] = !(s_lh || (bool)v_rh[2]);
	return v_out;
}


//-----------------------------------------------------------------------------

ijk_inl boolv ijkVecInitElems4bv(bool4 v_out, bool const x, bool const y, bool const z, bool const w)
{
	v_out[0] = ijk_istrue(x);
	v_out[1] = ijk_istrue(y);
	v_out[2] = ijk_istrue(z);
	v_out[3] = ijk_istrue(w);
	return v_out;
}

ijk_inl boolv ijkVecCopy4bv(bool4 v_out, bool4 const v_in)
{
	v_out[0] = ijk_istrue(v_in[0]);
	v_out[1] = ijk_istrue(v_in[1]);
	v_out[2] = ijk_istrue(v_in[2]);
	v_out[3] = ijk_istrue(v_in[3]);
	return v_out;
}

ijk_inl boolv ijkVecNot4bv(bool4 v_out, bool4 const v_in)
{
	v_out[0] = ijk_isfalse(v_in[0]);
	v_out[1] = ijk_isfalse(v_in[1]);
	v_out[2] = ijk_isfalse(v_in[2]);
	v_out[3] = ijk_isfalse(v_in[3]);
	return v_out;
}

ijk_inl boolv ijkVecEqual4bv(bool4 v_out, bool4 const v_lh, bool4 const v_rh)
{
	v_out[0] = (v_lh[0] == v_rh[0]);
	v_out[1] = (v_lh[1] == v_rh[1]);
	v_out[2] = (v_lh[2] == v_rh[2]);
	v_out[3] = (v_lh[3] == v_rh[3]);
	return v_out;
}

ijk_inl boolv ijkVecInequal4bv(bool4 v_out, bool4 const v_lh, bool4 const v_rh)
{
	v_out[0] = (v_lh[0] != v_rh[0]);
	v_out[1] = (v_lh[1] != v_rh[1]);
	v_out[2] = (v_lh[2] != v_rh[2]);
	v_out[3] = (v_lh[3] != v_rh[3]);
	return v_out;
}

ijk_inl boolv ijkVecAnd4bv(bool4 v_out, bool4 const v_lh, bool4 const v_rh)
{
	v_out[0] = (v_lh[0] && v_rh[0]);
	v_out[1] = (v_lh[1] && v_rh[1]);
	v_out[2] = (v_lh[2] && v_rh[2]);
	v_out[3] = (v_lh[3] && v_rh[3]);
	return v_out;
}

ijk_inl boolv ijkVecNand4bv(bool4 v_out, bool4 const v_lh, bool4 const v_rh)
{
	v_out[0] = !(v_lh[0] && v_rh[0]);
	v_out[1] = !(v_lh[1] && v_rh[1]);
	v_out[2] = !(v_lh[2] && v_rh[2]);
	v_out[3] = !(v_lh[3] && v_rh[3]);
	return v_out;
}

ijk_inl boolv ijkVecOr4bv(bool4 v_out, bool4 const v_lh, bool4 const v_rh)
{
	v_out[0] = (v_lh[0] || v_rh[0]);
	v_out[1] = (v_lh[1] || v_rh[1]);
	v_out[2] = (v_lh[2] || v_rh[2]);
	v_out[3] = (v_lh[3] || v_rh[3]);
	return v_out;
}

ijk_inl boolv ijkVecNor4bv(bool4 v_out, bool4 const v_lh, bool4 const v_rh)
{
	v_out[0] = !(v_lh[0] || v_rh[0]);
	v_out[1] = !(v_lh[1] || v_rh[1]);
	v_out[2] = !(v_lh[2] || v_rh[2]);
	v_out[3] = !(v_lh[3] || v_rh[3]);
	return v_out;
}

ijk_inl boolv ijkVecCopy4bvs(bool4 v_out, bool const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = v_out[3] = ijk_istrue(s_in);
	return v_out;
}

ijk_inl boolv ijkVecNot4bvs(bool4 v_out, bool const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = v_out[3] = ijk_isfalse(s_in);
	return v_out;
}

ijk_inl boolv ijkVecEqual4bvs(bool4 v_out, bool4 const v_lh, bool const s_rh)
{
	v_out[0] = ((bool)v_lh[0] == s_rh);
	v_out[1] = ((bool)v_lh[1] == s_rh);
	v_out[2] = ((bool)v_lh[2] == s_rh);
	v_out[3] = ((bool)v_lh[3] == s_rh);
	return v_out;
}

ijk_inl boolv ijkVecInequal4bvs(bool4 v_out, bool4 const v_lh, bool const s_rh)
{
	v_out[0] = ((bool)v_lh[0] != s_rh);
	v_out[1] = ((bool)v_lh[1] != s_rh);
	v_out[2] = ((bool)v_lh[2] != s_rh);
	v_out[3] = ((bool)v_lh[3] != s_rh);
	return v_out;
}

ijk_inl boolv ijkVecAnd4bvs(bool4 v_out, bool4 const v_lh, bool const s_rh)
{
	v_out[0] = (v_lh[0] && s_rh);
	v_out[1] = (v_lh[1] && s_rh);
	v_out[2] = (v_lh[2] && s_rh);
	v_out[3] = (v_lh[3] && s_rh);
	return v_out;
}

ijk_inl boolv ijkVecNand4bvs(bool4 v_out, bool4 const v_lh, bool const s_rh)
{
	v_out[0] = !(v_lh[0] && s_rh);
	v_out[1] = !(v_lh[1] && s_rh);
	v_out[2] = !(v_lh[2] && s_rh);
	v_out[3] = !(v_lh[3] && s_rh);
	return v_out;
}

ijk_inl boolv ijkVecOr4bvs(bool4 v_out, bool4 const v_lh, bool const s_rh)
{
	v_out[0] = (v_lh[0] || s_rh);
	v_out[1] = (v_lh[1] || s_rh);
	v_out[2] = (v_lh[2] || s_rh);
	v_out[3] = (v_lh[3] || s_rh);
	return v_out;
}

ijk_inl boolv ijkVecNor4bvs(bool4 v_out, bool4 const v_lh, bool const s_rh)
{
	v_out[0] = !(v_lh[0] || s_rh);
	v_out[1] = !(v_lh[1] || s_rh);
	v_out[2] = !(v_lh[2] || s_rh);
	v_out[3] = !(v_lh[3] || s_rh);
	return v_out;
}

ijk_inl boolv ijkVecEqual4bsv(bool4 v_out, bool const s_lh, bool4 const v_rh)
{
	v_out[0] = (s_lh == (bool)v_rh[0]);
	v_out[1] = (s_lh == (bool)v_rh[1]);
	v_out[2] = (s_lh == (bool)v_rh[2]);
	v_out[3] = (s_lh == (bool)v_rh[3]);
	return v_out;
}

ijk_inl boolv ijkVecInequal4bsv(bool4 v_out, bool const s_lh, bool4 const v_rh)
{
	v_out[0] = (s_lh != (bool)v_rh[0]);
	v_out[1] = (s_lh != (bool)v_rh[1]);
	v_out[2] = (s_lh != (bool)v_rh[2]);
	v_out[3] = (s_lh != (bool)v_rh[3]);
	return v_out;
}

ijk_inl boolv ijkVecAnd4bsv(bool4 v_out, bool const s_lh, bool4 const v_rh)
{
	v_out[0] = (s_lh && (bool)v_rh[0]);
	v_out[1] = (s_lh && (bool)v_rh[1]);
	v_out[2] = (s_lh && (bool)v_rh[2]);
	v_out[3] = (s_lh && (bool)v_rh[3]);
	return v_out;
}

ijk_inl boolv ijkVecNand4bsv(bool4 v_out, bool const s_lh, bool4 const v_rh)
{
	v_out[0] = !(s_lh && (bool)v_rh[0]);
	v_out[1] = !(s_lh && (bool)v_rh[1]);
	v_out[2] = !(s_lh && (bool)v_rh[2]);
	v_out[3] = !(s_lh && (bool)v_rh[3]);
	return v_out;
}

ijk_inl boolv ijkVecOr4bsv(bool4 v_out, bool const s_lh, bool4 const v_rh)
{
	v_out[0] = (s_lh || (bool)v_rh[0]);
	v_out[1] = (s_lh || (bool)v_rh[1]);
	v_out[2] = (s_lh || (bool)v_rh[2]);
	v_out[3] = (s_lh || (bool)v_rh[3]);
	return v_out;
}

ijk_inl boolv ijkVecNor4bsv(bool4 v_out, bool const s_lh, bool4 const v_rh)
{
	v_out[0] = !(s_lh || (bool)v_rh[0]);
	v_out[1] = !(s_lh || (bool)v_rh[1]);
	v_out[2] = !(s_lh || (bool)v_rh[2]);
	v_out[3] = !(s_lh || (bool)v_rh[3]);
	return v_out;
}


//-----------------------------------------------------------------------------

ijk_inl bvec2 ijkVecInitElems2b(bool const x, bool const y)
{
	bvec2 const v_out = { ijk_istrue(x), ijk_istrue(y) };
	return v_out;
}

ijk_inl bvec2 ijkVecCopy2b(bvec2 const v_in)
{
	bvec2 const v_out = { ijk_istrue(v_in.x), ijk_istrue(v_in.y) };
	return v_out;
}

ijk_inl bvec2 ijkVecNot2b(bvec2 const v_in)
{
	bvec2 const v_out = { ijk_isfalse(v_in.x), ijk_isfalse(v_in.y) };
	return v_out;
}

ijk_inl bvec2 ijkVecEqual2b(bvec2 const v_lh, bvec2 const v_rh)
{
	bvec2 const v_out = {
		(v_lh.x == v_rh.x),
		(v_lh.y == v_rh.y),
	};
	return v_out;
}

ijk_inl bvec2 ijkVecInequal2b(bvec2 const v_lh, bvec2 const v_rh)
{
	bvec2 const v_out = {
		(v_lh.x != v_rh.x),
		(v_lh.y != v_rh.y),
	};
	return v_out;
}

ijk_inl bvec2 ijkVecAnd2b(bvec2 const v_lh, bvec2 const v_rh)
{
	bvec2 const v_out = {
		(v_lh.x && v_rh.x),
		(v_lh.y && v_rh.y),
	};
	return v_out;
}

ijk_inl bvec2 ijkVecNand2b(bvec2 const v_lh, bvec2 const v_rh)
{
	bvec2 const v_out = {
		!(v_lh.x && v_rh.x),
		!(v_lh.y && v_rh.y),
	};
	return v_out;
}

ijk_inl bvec2 ijkVecOr2b(bvec2 const v_lh, bvec2 const v_rh)
{
	bvec2 const v_out = {
		(v_lh.x || v_rh.x),
		(v_lh.y || v_rh.y),
	};
	return v_out;
}

ijk_inl bvec2 ijkVecNor2b(bvec2 const v_lh, bvec2 const v_rh)
{
	bvec2 const v_out = {
		!(v_lh.x || v_rh.x),
		!(v_lh.y || v_rh.y),
	};
	return v_out;
}

ijk_inl bvec2 ijkVecCopy2bs(bool const s_in)
{
	bool const s = ijk_istrue(s_in);
	bvec2 const v_out = { s, s };
	return v_out;
}

ijk_inl bvec2 ijkVecNot2bs(bool const s_in)
{
	bool const s = ijk_isfalse(s_in);
	bvec2 const v_out = { s, s };
	return v_out;
}

ijk_inl bvec2 ijkVecEqual2bs(bvec2 const v_lh, bool const s_rh)
{
	bvec2 const v_out = {
		(v_lh.x == s_rh),
		(v_lh.y == s_rh),
	};
	return v_out;
}

ijk_inl bvec2 ijkVecInequal2bs(bvec2 const v_lh, bool const s_rh)
{
	bvec2 const v_out = {
		(v_lh.x != s_rh),
		(v_lh.y != s_rh),
	};
	return v_out;
}

ijk_inl bvec2 ijkVecAnd2bs(bvec2 const v_lh, bool const s_rh)
{
	bvec2 const v_out = {
		(v_lh.x && s_rh),
		(v_lh.y && s_rh),
	};
	return v_out;
}

ijk_inl bvec2 ijkVecNand2bs(bvec2 const v_lh, bool const s_rh)
{
	bvec2 const v_out = {
		!(v_lh.x && s_rh),
		!(v_lh.y && s_rh),
	};
	return v_out;
}

ijk_inl bvec2 ijkVecOr2bs(bvec2 const v_lh, bool const s_rh)
{
	bvec2 const v_out = {
		(v_lh.x || s_rh),
		(v_lh.y || s_rh),
	};
	return v_out;
}

ijk_inl bvec2 ijkVecNor2bs(bvec2 const v_lh, bool const s_rh)
{
	bvec2 const v_out = {
		!(v_lh.x || s_rh),
		!(v_lh.y || s_rh),
	};
	return v_out;
}

ijk_inl bvec2 ijkVecEqual2sb(bool const s_lh, bvec2 const v_rh)
{
	bvec2 const v_out = {
		(s_lh == v_rh.x),
		(s_lh == v_rh.y),
	};
	return v_out;
}

ijk_inl bvec2 ijkVecInequal2sb(bool const s_lh, bvec2 const v_rh)
{
	bvec2 const v_out = {
		(s_lh != v_rh.x),
		(s_lh != v_rh.y),
	};
	return v_out;
}

ijk_inl bvec2 ijkVecAnd2sb(bool const s_lh, bvec2 const v_rh)
{
	bvec2 const v_out = {
		(s_lh && v_rh.x),
		(s_lh && v_rh.y),
	};
	return v_out;
}

ijk_inl bvec2 ijkVecNand2sb(bool const s_lh, bvec2 const v_rh)
{
	bvec2 const v_out = {
		!(s_lh && v_rh.x),
		!(s_lh && v_rh.y),
	};
	return v_out;
}

ijk_inl bvec2 ijkVecOr2sb(bool const s_lh, bvec2 const v_rh)
{
	bvec2 const v_out = {
		(s_lh || v_rh.x),
		(s_lh || v_rh.y),
	};
	return v_out;
}

ijk_inl bvec2 ijkVecNor2sb(bool const s_lh, bvec2 const v_rh)
{
	bvec2 const v_out = {
		!(s_lh || v_rh.x),
		!(s_lh || v_rh.y),
	};
	return v_out;
}


//-----------------------------------------------------------------------------

ijk_inl bvec3 ijkVecInitElems3b(bool const x, bool const y, bool const z)
{
	bvec3 const v_out = { ijk_istrue(x), ijk_istrue(y), ijk_istrue(z) };
	return v_out;
}

ijk_inl bvec3 ijkVecCopy3b(bvec3 const v_in)
{
	bvec3 const v_out = { ijk_istrue(v_in.x), ijk_istrue(v_in.y), ijk_istrue(v_in.z) };
	return v_out;
}

ijk_inl bvec3 ijkVecNot3b(bvec3 const v_in)
{
	bvec3 const v_out = { ijk_isfalse(v_in.x), ijk_isfalse(v_in.y), ijk_isfalse(v_in.z) };
	return v_out;
}

ijk_inl bvec3 ijkVecEqual3b(bvec3 const v_lh, bvec3 const v_rh)
{
	bvec3 const v_out = {
		(v_lh.x == v_rh.x),
		(v_lh.y == v_rh.y),
		(v_lh.z == v_rh.z),
	};
	return v_out;
}

ijk_inl bvec3 ijkVecInequal3b(bvec3 const v_lh, bvec3 const v_rh)
{
	bvec3 const v_out = {
		(v_lh.x != v_rh.x),
		(v_lh.y != v_rh.y),
		(v_lh.z != v_rh.z),
	};
	return v_out;
}

ijk_inl bvec3 ijkVecAnd3b(bvec3 const v_lh, bvec3 const v_rh)
{
	bvec3 const v_out = {
		(v_lh.x && v_rh.x),
		(v_lh.y && v_rh.y),
		(v_lh.z && v_rh.z),
	};
	return v_out;
}

ijk_inl bvec3 ijkVecNand3b(bvec3 const v_lh, bvec3 const v_rh)
{
	bvec3 const v_out = {
		!(v_lh.x && v_rh.x),
		!(v_lh.y && v_rh.y),
		!(v_lh.z && v_rh.z),
	};
	return v_out;
}

ijk_inl bvec3 ijkVecOr3b(bvec3 const v_lh, bvec3 const v_rh)
{
	bvec3 const v_out = {
		(v_lh.x || v_rh.x),
		(v_lh.y || v_rh.y),
		(v_lh.z || v_rh.z),
	};
	return v_out;
}

ijk_inl bvec3 ijkVecNor3b(bvec3 const v_lh, bvec3 const v_rh)
{
	bvec3 const v_out = {
		!(v_lh.x || v_rh.x),
		!(v_lh.y || v_rh.y),
		!(v_lh.z || v_rh.z),
	};
	return v_out;
}

ijk_inl bvec3 ijkVecCopy3bs(bool const s_in)
{
	bool const s = ijk_istrue(s_in);
	bvec3 const v_out = { s, s, s };
	return v_out;
}

ijk_inl bvec3 ijkVecNot3bs(bool const s_in)
{
	bool const s = ijk_isfalse(s_in);
	bvec3 const v_out = { s, s, s };
	return v_out;
}

ijk_inl bvec3 ijkVecEqual3bs(bvec3 const v_lh, bool const s_rh)
{
	bvec3 const v_out = {
		(v_lh.x == s_rh),
		(v_lh.y == s_rh),
		(v_lh.z == s_rh),
	};
	return v_out;
}

ijk_inl bvec3 ijkVecInequal3bs(bvec3 const v_lh, bool const s_rh)
{
	bvec3 const v_out = {
		(v_lh.x != s_rh),
		(v_lh.y != s_rh),
		(v_lh.z != s_rh),
	};
	return v_out;
}

ijk_inl bvec3 ijkVecAnd3bs(bvec3 const v_lh, bool const s_rh)
{
	bvec3 const v_out = {
		(v_lh.x && s_rh),
		(v_lh.y && s_rh),
		(v_lh.z && s_rh),
	};
	return v_out;
}

ijk_inl bvec3 ijkVecNand3bs(bvec3 const v_lh, bool const s_rh)
{
	bvec3 const v_out = {
		!(v_lh.x && s_rh),
		!(v_lh.y && s_rh),
		!(v_lh.z && s_rh),
	};
	return v_out;
}

ijk_inl bvec3 ijkVecOr3bs(bvec3 const v_lh, bool const s_rh)
{
	bvec3 const v_out = {
		(v_lh.x || s_rh),
		(v_lh.y || s_rh),
		(v_lh.z || s_rh),
	};
	return v_out;
}

ijk_inl bvec3 ijkVecNor3bs(bvec3 const v_lh, bool const s_rh)
{
	bvec3 const v_out = {
		!(v_lh.x || s_rh),
		!(v_lh.y || s_rh),
		!(v_lh.z || s_rh),
	};
	return v_out;
}

ijk_inl bvec3 ijkVecEqual3sb(bool const s_lh, bvec3 const v_rh)
{
	bvec3 const v_out = {
		(s_lh == v_rh.x),
		(s_lh == v_rh.y),
		(s_lh == v_rh.z),
	};
	return v_out;
}

ijk_inl bvec3 ijkVecInequal3sb(bool const s_lh, bvec3 const v_rh)
{
	bvec3 const v_out = {
		(s_lh != v_rh.x),
		(s_lh != v_rh.y),
		(s_lh != v_rh.z),
	};
	return v_out;
}

ijk_inl bvec3 ijkVecAnd3sb(bool const s_lh, bvec3 const v_rh)
{
	bvec3 const v_out = {
		(s_lh && v_rh.x),
		(s_lh && v_rh.y),
		(s_lh && v_rh.z),
	};
	return v_out;
}

ijk_inl bvec3 ijkVecNand3sb(bool const s_lh, bvec3 const v_rh)
{
	bvec3 const v_out = {
		!(s_lh && v_rh.x),
		!(s_lh && v_rh.y),
		!(s_lh && v_rh.z),
	};
	return v_out;
}

ijk_inl bvec3 ijkVecOr3sb(bool const s_lh, bvec3 const v_rh)
{
	bvec3 const v_out = {
		(s_lh || v_rh.x),
		(s_lh || v_rh.y),
		(s_lh || v_rh.z),
	};
	return v_out;
}

ijk_inl bvec3 ijkVecNor3sb(bool const s_lh, bvec3 const v_rh)
{
	bvec3 const v_out = {
		!(s_lh || v_rh.x),
		!(s_lh || v_rh.y),
		!(s_lh || v_rh.z),
	};
	return v_out;
}


//-----------------------------------------------------------------------------

ijk_inl bvec4 ijkVecInitElems4b(bool const x, bool const y, bool const z, bool const w)
{
	bvec4 const v_out = { ijk_istrue(x), ijk_istrue(y), ijk_istrue(z), ijk_istrue(w) };
	return v_out;
}

ijk_inl bvec4 ijkVecCopy4b(bvec4 const v_in)
{
	bvec4 const v_out = { ijk_istrue(v_in.x), ijk_istrue(v_in.y), ijk_istrue(v_in.z), ijk_istrue(v_in.w) };
	return v_out;
}

ijk_inl bvec4 ijkVecNot4b(bvec4 const v_in)
{
	bvec4 const v_out = { ijk_isfalse(v_in.x), ijk_isfalse(v_in.y), ijk_isfalse(v_in.z), ijk_isfalse(v_in.w) };
	return v_out;
}

ijk_inl bvec4 ijkVecEqual4b(bvec4 const v_lh, bvec4 const v_rh)
{
	bvec4 const v_out = {
		(v_lh.x == v_rh.x),
		(v_lh.y == v_rh.y),
		(v_lh.z == v_rh.z),
		(v_lh.w == v_rh.w),
	};
	return v_out;
}

ijk_inl bvec4 ijkVecInequal4b(bvec4 const v_lh, bvec4 const v_rh)
{
	bvec4 const v_out = {
		(v_lh.x != v_rh.x),
		(v_lh.y != v_rh.y),
		(v_lh.z != v_rh.z),
		(v_lh.w != v_rh.w),
	};
	return v_out;
}

ijk_inl bvec4 ijkVecAnd4b(bvec4 const v_lh, bvec4 const v_rh)
{
	bvec4 const v_out = {
		(v_lh.x && v_rh.x),
		(v_lh.y && v_rh.y),
		(v_lh.z && v_rh.z),
		(v_lh.w && v_rh.w),
	};
	return v_out;
}

ijk_inl bvec4 ijkVecNand4b(bvec4 const v_lh, bvec4 const v_rh)
{
	bvec4 const v_out = {
		!(v_lh.x && v_rh.x),
		!(v_lh.y && v_rh.y),
		!(v_lh.z && v_rh.z),
		!(v_lh.w && v_rh.w),
	};
	return v_out;
}

ijk_inl bvec4 ijkVecOr4b(bvec4 const v_lh, bvec4 const v_rh)
{
	bvec4 const v_out = {
		(v_lh.x || v_rh.x),
		(v_lh.y || v_rh.y),
		(v_lh.z || v_rh.z),
		(v_lh.w || v_rh.w),
	};
	return v_out;
}

ijk_inl bvec4 ijkVecNor4b(bvec4 const v_lh, bvec4 const v_rh)
{
	bvec4 const v_out = {
		!(v_lh.x || v_rh.x),
		!(v_lh.y || v_rh.y),
		!(v_lh.z || v_rh.z),
		!(v_lh.w || v_rh.w),
	};
	return v_out;
}

ijk_inl bvec4 ijkVecCopy4bs(bool const s_in)
{
	bool const s = ijk_istrue(s_in);
	bvec4 const v_out = { s, s, s, s };
	return v_out;
}

ijk_inl bvec4 ijkVecNot4bs(bool const s_in)
{
	bool const s = ijk_isfalse(s_in);
	bvec4 const v_out = { s, s, s, s };
	return v_out;
}

ijk_inl bvec4 ijkVecEqual4bs(bvec4 const v_lh, bool const s_rh)
{
	bvec4 const v_out = {
		(v_lh.x == s_rh),
		(v_lh.y == s_rh),
		(v_lh.z == s_rh),
		(v_lh.w == s_rh),
	};
	return v_out;
}

ijk_inl bvec4 ijkVecInequal4bs(bvec4 const v_lh, bool const s_rh)
{
	bvec4 const v_out = {
		(v_lh.x != s_rh),
		(v_lh.y != s_rh),
		(v_lh.z != s_rh),
		(v_lh.w != s_rh),
	};
	return v_out;
}

ijk_inl bvec4 ijkVecAnd4bs(bvec4 const v_lh, bool const s_rh)
{
	bvec4 const v_out = {
		(v_lh.x && s_rh),
		(v_lh.y && s_rh),
		(v_lh.z && s_rh),
		(v_lh.w && s_rh),
	};
	return v_out;
}

ijk_inl bvec4 ijkVecNand4bs(bvec4 const v_lh, bool const s_rh)
{
	bvec4 const v_out = {
		!(v_lh.x && s_rh),
		!(v_lh.y && s_rh),
		!(v_lh.z && s_rh),
		!(v_lh.w && s_rh),
	};
	return v_out;
}

ijk_inl bvec4 ijkVecOr4bs(bvec4 const v_lh, bool const s_rh)
{
	bvec4 const v_out = {
		(v_lh.x || s_rh),
		(v_lh.y || s_rh),
		(v_lh.z || s_rh),
		(v_lh.w || s_rh),
	};
	return v_out;
}

ijk_inl bvec4 ijkVecNor4bs(bvec4 const v_lh, bool const s_rh)
{
	bvec4 const v_out = {
		!(v_lh.x || s_rh),
		!(v_lh.y || s_rh),
		!(v_lh.z || s_rh),
		!(v_lh.w || s_rh),
	};
	return v_out;
}

ijk_inl bvec4 ijkVecEqual4sb(bool const s_lh, bvec4 const v_rh)
{
	bvec4 const v_out = {
		(s_lh == v_rh.x),
		(s_lh == v_rh.y),
		(s_lh == v_rh.z),
		(s_lh == v_rh.w),
	};
	return v_out;
}

ijk_inl bvec4 ijkVecInequal4sb(bool const s_lh, bvec4 const v_rh)
{
	bvec4 const v_out = {
		(s_lh != v_rh.x),
		(s_lh != v_rh.y),
		(s_lh != v_rh.z),
		(s_lh != v_rh.w),
	};
	return v_out;
}

ijk_inl bvec4 ijkVecAnd4sb(bool const s_lh, bvec4 const v_rh)
{
	bvec4 const v_out = {
		(s_lh && v_rh.x),
		(s_lh && v_rh.y),
		(s_lh && v_rh.z),
		(s_lh && v_rh.w),
	};
	return v_out;
}

ijk_inl bvec4 ijkVecNand4sb(bool const s_lh, bvec4 const v_rh)
{
	bvec4 const v_out = {
		!(s_lh && v_rh.x),
		!(s_lh && v_rh.y),
		!(s_lh && v_rh.z),
		!(s_lh && v_rh.w),
	};
	return v_out;
}

ijk_inl bvec4 ijkVecOr4sb(bool const s_lh, bvec4 const v_rh)
{
	bvec4 const v_out = {
		(s_lh || v_rh.x),
		(s_lh || v_rh.y),
		(s_lh || v_rh.z),
		(s_lh || v_rh.w),
	};
	return v_out;
}

ijk_inl bvec4 ijkVecNor4sb(bool const s_lh, bvec4 const v_rh)
{
	bvec4 const v_out = {
		!(s_lh || v_rh.x),
		!(s_lh || v_rh.y),
		!(s_lh || v_rh.z),
		!(s_lh || v_rh.w),
	};
	return v_out;
}


//-----------------------------------------------------------------------------


#endif	// !_IJK_VECTOR_BOOL_INL_
#endif	// _IJK_VECTOR_BOOL_H_