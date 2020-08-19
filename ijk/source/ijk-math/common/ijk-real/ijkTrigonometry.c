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

// ijkTrigTableParam_flt
//	Pointer to parameter input table.
flt const* ijkTrigTableParam_flt;

// ijkTrigTableSin_flt
//	Pointer to sine output table.
flt const* ijkTrigTableSin_flt;

// ijkTrigTableCos_flt
//	Pointer to cosine output table.
flt const* ijkTrigTableCos_flt;

// ijkTrigTableIndexAsin_flt
//	Pointer to arcsine index table.
index const* ijkTrigTableIndexAsin_flt;

// ijkTrigTableIndexAcos_flt
//	Pointer to arccosine index table.
index const* ijkTrigTableIndexAcos_flt;

// ijkTrigSubdivisionsPerDegree_flt
//	Number of subdivisions per degree.
size ijkTrigSubdivisionsPerDegree_flt;

// ijkTrigSubdivisionsPerDegreeInv_flt
//	Inverse of subdivisions per degree.
flt ijkTrigSubdivisionsPerDegreeInv_flt;


//-----------------------------------------------------------------------------

size ijkTrigGetTableSize_flt(size const subdivisionsPerDegree)
{
	//	SZ	= SZ_sample * (
	//			(720 degrees * 2 sets [params, sine]
	//			+ 90 degrees * 1 set [cosine])
	//			* (samples per degree) + 4 padding)
	//		+ SZ_index * (
	//			(720 indices * 2 sets[arcsine, arccosine])
	//			+ 4 padding)
	if (subdivisionsPerDegree)
	{
		// calculate size
		size const sz = szflt * ((720 * 2 + 90 * 1) * subdivisionsPerDegree + 4) + szindex * ((720 * 2) + 4);
		return sz;
	}
	return ijk_zero;
}


size ijkTrigSetTable_flt(flt const table[], size const tableSize_bytes, size const subdivisionsPerDegree)
{
	size const sz = ijkTrigGetTableSize_flt(subdivisionsPerDegree);
	if (table && sz && tableSize_bytes > sz)
	{
		flt const* const table_param = table;
		index const offset_param = 0, offset_sin = offset_param + subdivisionsPerDegree * 720 + 2, offset_cos = offset_sin + subdivisionsPerDegree * 90;
		index const* const table_index = (index *)(table_param + (offset_cos + subdivisionsPerDegree * 720 + 2));
		index const offset_index_asin = 0, offset_index_acos = offset_index_asin + 720 + 2;
		kptr const table_end = (ptr)(table_index + (offset_index_acos + 720 + 2));
		kptr const table_end_chksum = (ptr)((pbyte)table + sz);

		// set pointers to center of respective domain/range
		ijkTrigTableParam_flt = table_param + offset_param;
		ijkTrigTableSin_flt = table_param + offset_sin;
		ijkTrigTableCos_flt = table_param + offset_cos;
		ijkTrigTableIndexAsin_flt = table_index + offset_index_asin;
		ijkTrigTableIndexAcos_flt = table_index + offset_index_acos;
		ijkTrigSubdivisionsPerDegree_flt = subdivisionsPerDegree;
		ijkTrigSubdivisionsPerDegreeInv_flt = ijk_recip_flt((flt)subdivisionsPerDegree);

		// done
		return sz;
	}
	return ijk_zero;
}


size ijkTrigInit_flt(flt table_out[], size const tableSize_bytes, size const subdivisionsPerDegree)
{
	size const sz = ijkTrigSetTable_flt(table_out, tableSize_bytes, subdivisionsPerDegree);
	if (sz)
	{
		flt* tableParam_flt = (flt*)ijkTrigTableParam_flt;
		flt* tableSin_flt = (flt*)ijkTrigTableSin_flt;
		flt* tableCos_flt = (flt*)ijkTrigTableCos_flt;
		index* tableIndexAsin_flt = (index*)ijkTrigTableIndexAsin_flt;
		index* tableIndexAcos_flt = (index*)ijkTrigTableIndexAcos_flt;
		kptr const tableEnd = ijkTrigTableIndexAcos_flt + 720 + 2;

		uindex const numSubdivisions = subdivisionsPerDegree * 360, cosOffset = subdivisionsPerDegree * 90;
		uindex i, j;
		index x0;
		flt x;
		flt dx;

		// store parameters as well as sine/cosine values
		for (x0 = -360, dx = ijk_recip_flt(subdivisionsPerDegree); x0 < +360; ++x0)
			for (i = 0; i < subdivisionsPerDegree; ++i)
			{
				x = *(tableParam_flt++) = (flt)x0 + (flt)i * dx;
				*(tableSin_flt++) = ijkTrigSinTaylor_deg_flt(x);
			}

		// copy additional 90 degrees of data for cosine
		// sine and cosine table pointers should now be equal
		for (; x0 < +450; ++x0)
			for (i = 0; i < subdivisionsPerDegree; ++i, ++tableSin_flt)
				*(tableSin_flt) = *(tableSin_flt - numSubdivisions);
		
		// store padding values
		*(tableParam_flt) = flt_360;
		*(tableSin_flt) = *(tableSin_flt - numSubdivisions);
		*(++tableParam_flt) = *(++tableSin_flt) = flt_zero;

		// prepare indices for sampling inverse trig
		for (x0 = -360, dx = ijk_recip_flt(flt_360), i = subdivisionsPerDegree * 270, j = i + 1; x0 <= +360; ++x0)
		{
			// threshold: index should not be higher than the sampling index 
			//	that would yield this number when computing sine
			x = x0 * dx;

			// increment index until sample exceeds threshold
			while (*(tableSin_flt + j) < x)
				i = j++;

			// assign index
			// sin starts at -90 index (which maps to -1)
			// cos starts at -180 index (which maps to -1)
			*(tableIndexAsin_flt++) = i;
			*(tableIndexAcos_flt++) = i - cosOffset;
		}

		// store padding values
		*(tableIndexAsin_flt++) = 0;
		*(tableIndexAcos_flt++) = 0;

		// done
		return sz;
	}
	return ijk_zero;
}


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
