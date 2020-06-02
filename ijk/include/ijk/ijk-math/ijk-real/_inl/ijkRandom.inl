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

	ijkRandom.inl
	Inline definitions for random number generation.
*/

#ifdef _IJK_RANDOM_H_
#ifndef _IJK_RANDOM_INL_
#define _IJK_RANDOM_INL_


//-----------------------------------------------------------------------------

ijk_inl i32 ijkRandomGetMax()
{
	ijk_ext i32 const ijk_random_max;
	return ijk_random_max;
}


ijk_inl i32 ijkRandomGetSeed()
{
	ijk_ext i32 ijk_random_seed;
	return ijk_random_seed;
}


ijk_inl i32 ijkRandomSetSeed(i32 const seed)
{
	ijk_ext i32 ijk_random_seed;
	i32 const ret = ijk_random_seed;
	ijk_random_seed = seed;
	return ret;
}


ijk_inl i32 ijkRandomNum_int()
{
	// quick n' dirty random number generator that has been around for decades
	// set the seed every time for true randomness
	ijk_ext i32 const ijk_random_max;
	ijk_ext i32 ijk_random_seed;
	i32 const rp_a = 8121, rp_c = 28411;
	ijk_random_seed = (ijk_random_seed * rp_a + rp_c) % ijk_random_max;
	return ijk_random_seed;
}


ijk_inl i32 ijkRandomNumMax_int(i32 const usermax)
{
	return (ijkRandomNum_int() % usermax);
}


ijk_inl i32 ijkRandomNumRange_int(i32 const usermin, i32 const usermax)
{
	return (ijkRandomNum_int() % (usermax - usermin) + usermin);
}


//-----------------------------------------------------------------------------

ijk_inl flt ijkRandomNum_flt()
{
	return (flt)ijkRandomNum_int();
}


ijk_inl flt ijkRandomNumUnitNrm_flt()
{
	ijk_ext flt const ijk_random_max_inv_flt;
	return (ijkRandomNum_flt() * ijk_random_max_inv_flt);
}


ijk_inl flt ijkRandomNumUnitSym_flt()
{
	return ijk_nrm2sym_flt(ijkRandomNumUnitNrm_flt());
}


ijk_inl flt ijkRandomNumMax_flt(flt const usermax)
{
	return (ijkRandomNumUnitNrm_flt() * usermax);
}


ijk_inl flt ijkRandomNumRange_flt(flt const usermin, flt const usermax)
{
	return ijk_lerp(usermin, usermax, ijkRandomNumUnitNrm_flt());
}


//-----------------------------------------------------------------------------

ijk_inl dbl ijkRandomNum_dbl()
{
	return (dbl)ijkRandomNum_int();
}


ijk_inl dbl ijkRandomNumUnitNrm_dbl()
{
	ijk_ext dbl const ijk_random_max_inv_dbl;
	return (ijkRandomNum_dbl() * ijk_random_max_inv_dbl);
}


ijk_inl dbl ijkRandomNumUnitSym_dbl()
{
	return ijk_nrm2sym_dbl(ijkRandomNumUnitNrm_dbl());
}


ijk_inl dbl ijkRandomNumMax_dbl(dbl const usermax)
{
	return (ijkRandomNumUnitNrm_dbl() * usermax);
}


ijk_inl dbl ijkRandomNumRange_dbl(dbl const usermin, dbl const usermax)
{
	return ijk_lerp(usermin, usermax, ijkRandomNumUnitNrm_dbl());
}


//-----------------------------------------------------------------------------


#endif	// !_IJK_RANDOM_INL_
#endif	// _IJK_RANDOM_H_