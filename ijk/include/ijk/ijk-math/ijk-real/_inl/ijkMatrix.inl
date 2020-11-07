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

	ijkMatrix.inl
	Inline definitions for matrix types.
*/

#ifdef _IJK_MATRIX_H_
#ifndef _IJK_MATRIX_INL_
#define _IJK_MATRIX_INL_


//-----------------------------------------------------------------------------

ijk_inl float2m ijkMatTest2fv(float2x2 m_out, float2x2 const m_in)
{
	ijkVecCopy2fv(m_out[0], m_in[0]);
	ijkVecCopy2fv(m_out[1], m_in[1]);
	return m_out;
}

ijk_inl float2m ijkMatTest2fvs(float2x2 m_out, float2x2 const m_lh, f32 const s_rh)
{
	return ijkMatTest2fv(ijkMatTest2fv(m_out, m_lh), m_lh);
}


//-----------------------------------------------------------------------------


#endif	// !_IJK_MATRIX_INL_
#endif	// _IJK_MATRIX_H_