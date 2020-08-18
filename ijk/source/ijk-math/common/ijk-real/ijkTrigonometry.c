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

	ijkTrigonometry.c
	Source definitions for fast trigonometry.
*/

#include "ijk/ijk-math/ijk-real/ijkTrigonometry.h"


//-----------------------------------------------------------------------------

size ijkTrigGetTableSize_flt(size const subdivisionsPerDegree)
{
	//	SZ	= SZ_sample * (
	//			(720 degrees * 3 sets [params, sine, cosine]
	//			+ 90 degrees * 1 set [cosine])
	//			* (samples per degree) + 4 padding)
	//		+ SZ_index * (
	//			(720 indices * 2 sets[arcsine, arccosine])
	//			+ 4 padding)
	if (subdivisionsPerDegree)
	{
		size const sz = szflt * ((720 * 3 + 90 * 1) * subdivisionsPerDegree + 4) + szindex * ((720 * 2) + 4);
		return sz;
	}
	return ijk_zero;
}


size ijkTrigSetTable_flt(flt const table[], size const tableSize_bytes, size const subdivisionsPerDegree)
{
	size const sz = ijkTrigGetTableSize_flt(subdivisionsPerDegree);
	if (sz && tableSize_bytes > sz)
	{

		return sz;
	}
	return ijk_zero;
}


size ijkTrigInit_flt(flt table[], size const tableSize_bytes, size const subdivisionsPerDegree)
{
	size const sz = ijkTrigSetTable_flt(table, tableSize_bytes, subdivisionsPerDegree);
	if (sz)
	{

	}
	return sz;
}


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
