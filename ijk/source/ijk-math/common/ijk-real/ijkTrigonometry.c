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
	//	SZ	= szflt * (
	//			(720 degrees * 2 sets [params, sine]
	//			+ 90 degrees * 1 set [cosine])
	//			* (samples per degree) + 4 padding)
	//		+ szindex * (
	//			(1024 indices * 1 set [arcsine])
	//			+ 2 padding)
	if (subdivisionsPerDegree)
	{
		// calculate size
		size const sz = szflt * (/*(720 * 2 + 90 * 1)*/ 1530 * subdivisionsPerDegree + 4) + szindex * (/*(1024 * 1) + 2*/ 1026);
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
		size const numSubdivisions180 = ijkTrigSubdivisionsPerDegree_flt * 180, numSubdivisions360 = numSubdivisions180 * 2, numSubdivisions720 = numSubdivisions360 * 2;
		uindex i, j;
		index x0;
		dbl c, s;
		flt x, y, dx;

		// store parameters as well as sine/cosine values
		for (dx = ijkTrigSubdivisionsPerDegreeInv_flt,
			x0 = 0; x0 < +180; ++x0)
			for (i = 0; i < ijkTrigSubdivisionsPerDegree_flt; ++i, ++tableParam_flt, ++tableSin_flt)
			{
				// calculate parameter
				x = *(tableParam_flt) = *(tableParam_flt + numSubdivisions360) = (flt)x0 + (flt)i * dx;

				// calculate most accurate trig result
				c = ijkTrigCosTaylor_deg_dbl(x - dbl_90);
				s = ijkTrigSinTaylor_deg_dbl(x + dbl_zero);
				y = *(tableSin_flt) = *(tableSin_flt + numSubdivisions360) = (flt)((c + s) * dbl_half);

				// calculate parameter and value offset by 180 using identity
				x = *(tableParam_flt + numSubdivisions180) = (x + flt_180);
				y = *(tableSin_flt + numSubdivisions180) = (-y);
			}

		// correct rational values
		tableParam_flt = (flt*)ijkTrigTableParam_flt;
		tableSin_flt = (flt*)ijkTrigTableSin_flt;
		y = *(tableSin_flt) = *(tableSin_flt + numSubdivisions180) = flt_zero;
		//y = *(tableSin_flt + ijkTrigSubdivisionsPerDegree_flt * 90) = +flt_one;
		//y = *(tableSin_flt + ijkTrigSubdivisionsPerDegree_flt * 30) = *(tableSin_flt + ijkTrigSubdivisionsPerDegree_flt * 150) = +flt_half;
		//y = *(tableSin_flt + ijkTrigSubdivisionsPerDegree_flt * 210) = *(tableSin_flt + ijkTrigSubdivisionsPerDegree_flt * 330) = -flt_half;
		//y = *(tableSin_flt + ijkTrigSubdivisionsPerDegree_flt * 270) = -flt_one;

		// copy additional 90 degrees of data for cosine
		for (tableParam_flt += numSubdivisions720, tableSin_flt += numSubdivisions720,
			x0 = +360; x0 < +450; ++x0)
			for (i = 0; i < ijkTrigSubdivisionsPerDegree_flt; ++i, ++tableSin_flt)
				y = *(tableSin_flt) = *(tableSin_flt - numSubdivisions720);

		// store final and padding values
		x = *(tableParam_flt) = (flt_360);
		y = *(tableSin_flt) = *(tableSin_flt - numSubdivisions720);
		*(++tableParam_flt) = *(++tableSin_flt) = flt_zero;

		// prepare indices for sampling inverse trig
		for (dx = ijk_recip_flt((flt)512), i = ijkTrigSubdivisionsPerDegree_flt * 270, j = i + 1,
			x0 = -512; x0 <= +512; ++x0)
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

		// store final and padding values
		//i = *(tableIndexAsin_flt++) = (ijkTrigSubdivisionsPerDegree_flt * 450 - 1);
		*(tableIndexAsin_flt) = 0;

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
	//	SZ	= szdbl * (
	//			(720 degrees * 2 sets [params, sine]
	//			+ 90 degrees * 1 set [cosine])
	//			* (samples per degree) + 4 padding)
	//		+ szindex * (
	//			(2048 indices * 1 set [arcsine])
	//			+ 4 padding)
	if (subdivisionsPerDegree)
	{
		// calculate size
		size const sz = szdbl * (/*(720 * 2 + 90 * 1)*/ 1530 * subdivisionsPerDegree + 4) + szindex * (/*(2048 * 1) + 4*/ 2052);
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
		kptr const table_end = (ptr)(table_index + (offset_index_asin + 2048 + 4));
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
		kptr const table_end = ijkTrigTableIndexAsin_dbl + 2048 + 4;
		kptr const table_end_chksum = (ptr)((pbyte)table_out + sz);
		size const numSubdivisions180 = ijkTrigSubdivisionsPerDegree_dbl * 180, numSubdivisions360 = numSubdivisions180 * 2, numSubdivisions720 = numSubdivisions360 * 2;
		uindex i, j;
		index x0;
		dbl c, s;
		dbl x, y, dx;

		// store parameters as well as sine/cosine values
		for (dx = ijkTrigSubdivisionsPerDegreeInv_dbl,
			x0 = 0; x0 < +180; ++x0)
			for (i = 0; i < ijkTrigSubdivisionsPerDegree_dbl; ++i, ++tableParam_dbl, ++tableSin_dbl)
			{
				// calculate parameter
				x = *(tableParam_dbl) = *(tableParam_dbl + numSubdivisions360) = (dbl)x0 + (dbl)i * dx;

				// calculate most accurate trig result
				c = ijkTrigCosTaylor_deg_dbl(x - dbl_90);
				s = ijkTrigSinTaylor_deg_dbl(x + dbl_zero);
				y = *(tableSin_dbl) = *(tableSin_dbl + numSubdivisions360) = ((c + s) * dbl_half);

				// calculate parameter and value offset by 180 using identity
				x = *(tableParam_dbl + numSubdivisions180) = (x + dbl_180);
				y = *(tableSin_dbl + numSubdivisions180) = (-y);
			}

		// correct rational values
		tableParam_dbl = (dbl*)ijkTrigTableParam_dbl;
		tableSin_dbl = (dbl*)ijkTrigTableSin_dbl;
		y = *(tableSin_dbl) = *(tableSin_dbl + numSubdivisions180) = dbl_zero;
		//y = *(tableSin_dbl + ijkTrigSubdivisionsPerDegree_dbl * 90) = +dbl_one;
		//y = *(tableSin_dbl + ijkTrigSubdivisionsPerDegree_dbl * 30) = *(tableSin_dbl + ijkTrigSubdivisionsPerDegree_dbl * 150) = +dbl_half;
		//y = *(tableSin_dbl + ijkTrigSubdivisionsPerDegree_dbl * 210) = *(tableSin_dbl + ijkTrigSubdivisionsPerDegree_dbl * 330) = -dbl_half;
		//y = *(tableSin_dbl + ijkTrigSubdivisionsPerDegree_dbl * 270) = -dbl_one;

		// copy additional 90 degrees of data for cosine
		for (tableParam_dbl += numSubdivisions720, tableSin_dbl += numSubdivisions720,
			x0 = +360; x0 < +450; ++x0)
			for (i = 0; i < ijkTrigSubdivisionsPerDegree_dbl; ++i, ++tableSin_dbl)
				y = *(tableSin_dbl) = *(tableSin_dbl - numSubdivisions720);

		// store final and padding values
		x = *(tableParam_dbl) = (dbl_360);
		y = *(tableSin_dbl) = *(tableSin_dbl - numSubdivisions720);
		*(++tableParam_dbl) = *(++tableSin_dbl) = dbl_zero;

		// prepare indices for sampling inverse trig
		for (dx = ijk_recip_dbl((dbl)1024), i = ijkTrigSubdivisionsPerDegree_dbl * 270, j = i + 1,
			x0 = -1024; x0 <= +1024; ++x0)
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

		// store final and padding values
		//i = *(tableIndexAsin_dbl++) = (ijkTrigSubdivisionsPerDegree_dbl * 450 - 1);
		*(tableIndexAsin_dbl++) = 0;
		*(tableIndexAsin_dbl++) = 0;
		*(tableIndexAsin_dbl) = 0;

		// done
		return sz;
	}
	return ijk_zero;
}


//-----------------------------------------------------------------------------
