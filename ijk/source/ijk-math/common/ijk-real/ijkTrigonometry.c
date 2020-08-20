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
	//			(1024 indices * 1 set [arcsine])
	//			+ 2 padding)
	if (subdivisionsPerDegree)
	{
		// calculate size
		size const sz = szflt * ((720 * 2 + 90 * 1) * subdivisionsPerDegree + 4) + szindex * ((1024 * 1) + 2);
		return sz;
	}
	return ijk_zero;
}


size ijkTrigSetTable_flt(flt const table[], size const tableSize_bytes, size const subdivisionsPerDegree)
{
	size const sz = ijkTrigGetTableSize_flt(subdivisionsPerDegree);
	if (table && sz && tableSize_bytes >= sz)
	{
		flt const* const table_param = table;
		index const offset_param = 0, offset_sin = offset_param + subdivisionsPerDegree * 720 + 2, offset_cos = offset_sin + subdivisionsPerDegree * 90;
		index const* const table_index = (index *)(table_param + (offset_cos + subdivisionsPerDegree * 720 + 2));
		index const offset_index_asin = 0;
		kptr const table_end = (ptr)(table_index + (offset_index_asin + 1024 + 2));
		kptr const table_end_chksum = (ptr)((pbyte)table + sz);

		// set pointers to center of respective domain/range
		ijkTrigTableParam_flt = table_param + offset_param;
		ijkTrigTableSin_flt = table_param + offset_sin;
		ijkTrigTableCos_flt = table_param + offset_cos;
		ijkTrigTableIndexAsin_flt = table_index + offset_index_asin;
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
		index* tableIndexAsin_flt = (index*)ijkTrigTableIndexAsin_flt;
		kptr const table_end = ijkTrigTableIndexAsin_flt + 1024 + 2;
		kptr const table_end_chksum = (ptr)((pbyte)table_out + sz);

		uindex const numSubdivisions = ijkTrigSubdivisionsPerDegree_flt * 720;
		uindex i, j;
		index x0;
		flt x, y, c, s;
		flt dx;

		// store parameters as well as sine/cosine values
		for (x0 = -360, dx = ijkTrigSubdivisionsPerDegreeInv_flt; x0 < +360; ++x0)
			for (i = 0; i < ijkTrigSubdivisionsPerDegree_flt; ++i)
			{
				// calculate parameter
				x = *(tableParam_flt++) = (flt)x0 + (flt)i * dx;

				// calculate most accurate trig result
				c = ijkTrigCosTaylor_deg_flt(x - flt_90);
				s = ijkTrigSinTaylor_deg_flt(x + flt_zero);
				y = *(tableSin_flt++) = (c + s) * flt_half;
			}

		// copy additional 90 degrees of data for cosine
		for (; x0 < +450; ++x0)
			for (i = 0; i < ijkTrigSubdivisionsPerDegree_flt; ++i, ++tableSin_flt)
				y = *(tableSin_flt) = *(tableSin_flt - numSubdivisions);
		
		// prepare indices for sampling inverse trig
		for (x0 = -512, dx = ijk_recip_flt((flt)512), i = ijkTrigSubdivisionsPerDegree_flt * 270, j = i + 1; x0 < +512; ++x0)
		{
			// threshold: index should not be higher than the sampling index 
			//	that would yield this number when computing sine
			x = (flt)x0 * dx;

			// increment index until sample exceeds threshold
			while ((y = *(ijkTrigTableSin_flt + j)) < x)
				i = j++;

			// assign index
			// asin starts at -90 index (which maps to -1)
			// acos uses identity: acos(x) = 90 - asin(x)
			*(tableIndexAsin_flt++) = i;
		}

		// store final values and padding values
		i = *(tableIndexAsin_flt) = (ijkTrigSubdivisionsPerDegree_flt * 450 - 1);
		x = *(tableParam_flt) = (flt_360);
		y = *(tableSin_flt) = *(tableSin_flt - numSubdivisions);
		*(++tableParam_flt) = *(++tableSin_flt) = flt_zero;
		*(++tableIndexAsin_flt) = 0;

		// done
		return sz;
	}
	return ijk_zero;
}


//-----------------------------------------------------------------------------

// ijkTrigTableParam_dbl
//	Pointer to parameter input table.
dbl const* ijkTrigTableParam_dbl;

// ijkTrigTableSin_dbl
//	Pointer to sine output table.
dbl const* ijkTrigTableSin_dbl;

// ijkTrigTableCos_dbl
//	Pointer to cosine output table.
dbl const* ijkTrigTableCos_dbl;

// ijkTrigTableIndexAsin_dbl
//	Pointer to arcsine index table.
index const* ijkTrigTableIndexAsin_dbl;

// ijkTrigSubdivisionsPerDegree_dbl
//	Number of subdivisions per degree.
size ijkTrigSubdivisionsPerDegree_dbl;

// ijkTrigSubdivisionsPerDegreeInv_dbl
//	Inverse of subdivisions per degree.
dbl ijkTrigSubdivisionsPerDegreeInv_dbl;


//-----------------------------------------------------------------------------

size ijkTrigGetTableSize_dbl(size const subdivisionsPerDegree)
{
	//	SZ	= SZ_sample * (
	//			(720 degrees * 2 sets [params, sine]
	//			+ 90 degrees * 1 set [cosine])
	//			* (samples per degree) + 4 padding)
	//		+ SZ_index * (
	//			(1024 indices * 1 set [arcsine])
	//			+ 2 padding)
	if (subdivisionsPerDegree)
	{
		// calculate size
		size const sz = szdbl * ((720 * 2 + 90 * 1) * subdivisionsPerDegree + 4) + szindex * ((1024 * 1) + 2);
		return sz;
	}
	return ijk_zero;
}


size ijkTrigSetTable_dbl(dbl const table[], size const tableSize_bytes, size const subdivisionsPerDegree)
{
	size const sz = ijkTrigGetTableSize_dbl(subdivisionsPerDegree);
	if (table && sz && tableSize_bytes >= sz)
	{
		dbl const* const table_param = table;
		index const offset_param = 0, offset_sin = offset_param + subdivisionsPerDegree * 720 + 2, offset_cos = offset_sin + subdivisionsPerDegree * 90;
		index const* const table_index = (index*)(table_param + (offset_cos + subdivisionsPerDegree * 720 + 2));
		index const offset_index_asin = 0;
		kptr const table_end = (ptr)(table_index + (offset_index_asin + 1024 + 2));
		kptr const table_end_chksum = (ptr)((pbyte)table + sz);

		// set pointers to center of respective domain/range
		ijkTrigTableParam_dbl = table_param + offset_param;
		ijkTrigTableSin_dbl = table_param + offset_sin;
		ijkTrigTableCos_dbl = table_param + offset_cos;
		ijkTrigTableIndexAsin_dbl = table_index + offset_index_asin;
		ijkTrigSubdivisionsPerDegree_dbl = subdivisionsPerDegree;
		ijkTrigSubdivisionsPerDegreeInv_dbl = ijk_recip_dbl((dbl)subdivisionsPerDegree);

		// done
		return sz;
	}
	return ijk_zero;
}


size ijkTrigInit_dbl(dbl table_out[], size const tableSize_bytes, size const subdivisionsPerDegree)
{
	size const sz = ijkTrigSetTable_dbl(table_out, tableSize_bytes, subdivisionsPerDegree);
	if (sz)
	{
		dbl* tableParam_dbl = (dbl*)ijkTrigTableParam_dbl;
		dbl* tableSin_dbl = (dbl*)ijkTrigTableSin_dbl;
		index* tableIndexAsin_dbl = (index*)ijkTrigTableIndexAsin_dbl;
		kptr const table_end = ijkTrigTableIndexAsin_dbl + 1024 + 2;
		kptr const table_end_chksum = (ptr)((pbyte)table_out + sz);

		uindex const numSubdivisions = ijkTrigSubdivisionsPerDegree_dbl * 720;
		uindex i, j;
		index x0;
		dbl x, y, c, s;
		dbl dx;

		// store parameters as well as sine/cosine values
		for (x0 = -360, dx = ijkTrigSubdivisionsPerDegreeInv_dbl; x0 < +360; ++x0)
			for (i = 0; i < ijkTrigSubdivisionsPerDegree_dbl; ++i)
			{
				// calculate parameter
				x = *(tableParam_dbl++) = (dbl)x0 + (dbl)i * dx;

				// calculate most accurate trig result
				c = ijkTrigCosTaylor_deg_dbl(x - dbl_90);
				s = ijkTrigSinTaylor_deg_dbl(x + dbl_zero);
				y = *(tableSin_dbl++) = (c + s) * dbl_half;
			}

		// copy additional 90 degrees of data for cosine
		for (; x0 < +450; ++x0)
			for (i = 0; i < ijkTrigSubdivisionsPerDegree_dbl; ++i, ++tableSin_dbl)
				y = *(tableSin_dbl) = *(tableSin_dbl - numSubdivisions);

		// prepare indices for sampling inverse trig
		for (x0 = -512, dx = ijk_recip_dbl((dbl)512), i = ijkTrigSubdivisionsPerDegree_dbl * 270, j = i + 1; x0 < +512; ++x0)
		{
			// threshold: index should not be higher than the sampling index 
			//	that would yield this number when computing sine
			x = (dbl)x0 * dx;

			// increment index until sample exceeds threshold
			while ((y = *(ijkTrigTableSin_dbl + j)) < x)
				i = j++;

			// assign index
			// asin starts at -90 index (which maps to -1)
			// acos uses identity: acos(x) = 90 - asin(x)
			*(tableIndexAsin_dbl++) = i;
		}

		// store final values and padding values
		i = *(tableIndexAsin_dbl) = (ijkTrigSubdivisionsPerDegree_dbl * 450 - 1);
		x = *(tableParam_dbl) = (dbl_360);
		y = *(tableSin_dbl) = *(tableSin_dbl - numSubdivisions);
		*(++tableParam_dbl) = *(++tableSin_dbl) = dbl_zero;
		*(++tableIndexAsin_dbl) = 0;

		// done
		return sz;
	}
	return ijk_zero;
}


//-----------------------------------------------------------------------------
