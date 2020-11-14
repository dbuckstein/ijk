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

	ijkMatrix_float.inl
	Inline definitions for float matrix types.
*/

#ifdef _IJK_MATRIX_FLOAT_H_
#ifndef _IJK_MATRIX_FLOAT_INL_
#define _IJK_MATRIX_FLOAT_INL_


//-----------------------------------------------------------------------------

ijk_inl float2m ijkMatInit2fm(float2x2 m_out)
{
	m_out[0][0] = m_out[1][1] = flt_one;
	m_out[0][1] = m_out[1][0] = flt_zero;
	return m_out;
}


//-----------------------------------------------------------------------------

// 3D array-based


//-----------------------------------------------------------------------------

// 4D array-based


//-----------------------------------------------------------------------------

// 2D struct-based


//-----------------------------------------------------------------------------

// 3D struct-based


//-----------------------------------------------------------------------------

// 4D struct-based


//-----------------------------------------------------------------------------

// 2D array-based special


//-----------------------------------------------------------------------------

// 3D array-based special


//-----------------------------------------------------------------------------

// 4D array-based special


//-----------------------------------------------------------------------------

// 2D struct-based special


//-----------------------------------------------------------------------------

// 3D struct-based special


//-----------------------------------------------------------------------------

// 4D struct-based special


//-----------------------------------------------------------------------------


#endif	// !_IJK_MATRIX_FLOAT_INL_
#endif	// _IJK_MATRIX_FLOAT_H_