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

	ijkTrigonometry.h
	Core fast trigonometry functions and utilities.
*/

#ifndef _IJK_TRIGONOMETRY_H_
#define _IJK_TRIGONOMETRY_H_


#include "ijkReal.h"


//-----------------------------------------------------------------------------

// ijkTrigGetTableSize_flt
//	Get the minimum required fast trigonometry table size in bytes. This will 
//	be different based on the sample type (float or double) and architecture 
//	(32-bit or 64-bit integer for index).
//		param subdivisionsPerDegree: number of samples per degree
//			valid: non-zero
//			note: each degree will be subsampled this number of times
//		return SUCCESS: ijk_success if set data
//		return FAILURE: ijk_fail_invalidparams if invalid parameters


// ijkTrigSetTable_flt
//	Set data tables for fast trigonometry.
//		param table: pointer to pre-allocated table
//			valid: non-null
//		param tableSize_bytes: size of provided table in bytes
//			valid: at least the minimum required size
//			note: minimum required size (in bytes) is: 
//				SZ	= SZ_sample * (
//						(720 degrees * 5 sets [params, sine, cosine, cosecant, secant]
//						+ 90 degrees * 2 sets [cosine, secant])
//						* (samples per degree) + 4 padding)
//					+ SZ_index * (
//						(720 * 2 sets[arcsine, arccosine])
//						+ 4 padding)
//		param subdivisionsPerDegree: number of samples per degree
//			valid: non-zero
//			note: each degree will be subsampled this number of times
//		return SUCCESS: ijk_success if set data
//		return FAILURE: ijk_fail_invalidparams if invalid parameters


// ijkTrigInit_flt
//	Initialize and set data tables for fast trigonometry.
//		param table_out: pointer to pre-allocated table to store data
//			valid: non-null
//		param tableSize_bytes: size of provided table in bytes
//			valid: at least the minimum required size
//			note: minimum required size (in bytes) is: 
//				SZ	= SZ_sample * (
//						(720 degrees * 5 sets [params, sine, cosine, cosecant, secant]
//						+ 90 degrees * 2 sets [cosine, secant])
//						* (samples per degree) + 4 padding)
//					+ SZ_index * (
//						(720 * 2 sets[arcsine, arccosine])
//						+ 4 padding)
//		param subdivisionsPerDegree: number of samples per degree
//			valid: non-zero
//			note: each degree will be subsampled this number of times
//		return SUCCESS: ijk_success if initialized data
//		return FAILURE: ijk_fail_invalidparams if invalid parameters


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------


#include "_inl/ijkTrigonometry.inl"


#endif	// !_IJK_TRIGONOMETRY_H_