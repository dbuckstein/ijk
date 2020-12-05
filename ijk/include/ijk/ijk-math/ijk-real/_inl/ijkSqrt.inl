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

	ijkSqrt.inl
	Inline definitions for square root.
*/

#ifdef _IJK_SQRT_H_
#ifndef _IJK_SQRT_INL_
#define _IJK_SQRT_INL_


//-----------------------------------------------------------------------------

ijk_inl flt ijkSqrtInv0x_flt(flt const x)
{
	union {
		f32 f;
		i32 i;
	} u = { x };

	// input is converted to an integer, shifted one bit, wizardry occurs, 
	//	then it is converted back to decimal as a guess for Newton's method
	u.i = 0x5f3759df - (u.i >> 1);

	// run Newton's method to converge on solution
	// multiple iterations takes longer, but converges more
	// 1x optimizes speed while 3x is better for precision
	u.f *= (flt_3half - flt_half * x * u.f * u.f);

	// done
	return u.f;
}


ijk_inl flt ijkSqrt0x_flt(flt const x)
{
	return (x * ijkSqrtInv0x_flt(x));
}


//-----------------------------------------------------------------------------

ijk_inl dbl ijkSqrtInv0x_dbl(dbl const x)
{
	return (dbl)ijkSqrtInv0x_flt((flt)x);
}


ijk_inl dbl ijkSqrt0x_dbl(dbl const x)
{
	return (x * ijkSqrtInv0x_dbl(x));
}


//-----------------------------------------------------------------------------


#endif	// !_IJK_SQRT_INL_
#endif	// _IJK_SQRT_H_