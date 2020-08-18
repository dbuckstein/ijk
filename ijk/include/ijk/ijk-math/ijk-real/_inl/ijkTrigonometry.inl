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

	ijkTrigonometry.inl
	Inline definitions for fast trigonometry.
*/

#ifdef _IJK_TRIGONOMETRY_H_
#ifndef _IJK_TRIGONOMETRY_INL_
#define _IJK_TRIGONOMETRY_INL_


//-----------------------------------------------------------------------------

ijk_inl flt ijkTrigValidateDegree_flt(flt x)
{
	return x;
}


ijk_inl flt ijkTrigValidateRadian_flt(flt x)
{
	return x;
}


ijk_inl flt ijkTrigValidateInverse_flt(flt x)
{
	return x;
}


ijk_inl flt ijkTrigValidateInverseRecip_flt(flt x)
{
	return x;
}


ijk_inl flt ijkTrigSind_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigCosd_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigTand_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigCscd_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigSecd_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigCotd_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigAsind_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigAcosd_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigAtand_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigAcscd_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigAsecd_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigAcotd_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigAtan2d_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigSindTaylor_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigCosdTaylor_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigTandTaylor_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigCscdTaylor_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigSecdTaylor_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigCotdTaylor_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigSindCosdTaylor_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigSinr_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigCosr_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigTanr_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigCscr_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigSecr_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigCotr_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigAsinr_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigAcosr_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigAtanr_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigAcscr_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigAsecr_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigAcotr_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigAtan2r_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigSinrTaylor_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigCosrTaylor_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigTanrTaylor_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigCscrTaylor_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigSecrTaylor_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigCotrTaylor_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigSinrCosrTaylor_flt(flt const x)
{
	return x;
}


ijk_inl flt ijkTrigPointToEdgeRatio_flt(flt const azimuth, size const numSlices)
{
	return ijkTrigCosd_flt(flt_half * azimuth / (flt)numSlices);
}


ijk_inl flt ijkTrigEdgeToPointRatio_flt(flt const azimuth, size const numSlices)
{
	return ijk_recip_flt(ijkTrigPointToEdgeRatio_flt(azimuth, numSlices));
}


ijk_inl flt ijkTrigPointToFaceRatio_flt(flt const azimuth, flt const elevation, size const numSlices, size const numStacks)
{
	return (ijkTrigPointToEdgeRatio_flt(azimuth, numSlices) * ijkTrigPointToEdgeRatio_flt(elevation, numStacks));
}


ijk_inl flt ijkTrigFaceToPointRatio_flt(flt const azimuth, flt const elevation, size const numSlices, size const numStacks)
{
	return ijk_recip_flt(ijkTrigPointToFaceRatio_flt(azimuth, elevation, numSlices, numStacks));
}


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------


#endif	// !_IJK_TRIGONOMETRY_INL_
#endif	// _IJK_TRIGONOMETRY_H_