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

	ijkStats.h
	Simple statistical functions.
*/

#ifndef _IJK_STATS_H_
#define _IJK_STATS_H_


#include "ijkSqrt.h"


//-----------------------------------------------------------------------------

// ijkStatsGetFactorial
//	Calculate the factorial of a number.
//		param n: number
//		return: factorial of 'n' (n!)
size ijkStatsGetFactorial(size const n);

// ijkStatsGetPermutations
//	Calculate the permutations of (number of ways to order) k elements in a 
//	set of n items.
//		param n: set size
//		param k: number of elements to permute (order)
//		return: permutations of k elements in a set of n items (nPk)
size ijkStatsGetPermutations(size const n, size const k);

// ijkStatsGetCombinations
//	Calculate the combinations of (number of ways to choose) k elements in a 
//	set of n items.
//		param n: set size
//		param k: number of elements to combine (choose)
//		return: combinations of k elements in a set of n items (nCk)
size ijkStatsGetCombinations(size const n, size const k);


// ijkStatsGetMedian_int_flt
//	Calculate the median of a sorted integer data set. Half of the data are 
//	less and half are greater than the median.
//		param v: array of values
//		param n: number of values in set
//		return: median as float
flt ijkStatsGetMedian_int_flt(schomp const v[], size const n);

// ijkStatsGetMedian_int_dbl
//	Calculate the median of a sorted integer data set. Half of the data are 
//	less and half are greater than the median.
//		param v: array of values
//		param n: number of values in set
//		return: median as double
dbl ijkStatsGetMedian_int_dbl(schomp const v[], size const n);

// ijkStatsGetMedian_flt
//	Calculate the median of a sorted float data set. Half of the data are 
//	less and half are greater than the median.
//		param v: array of values
//		param n: number of values in set
//		return: median
flt ijkStatsGetMedian_flt(flt const v[], size const n);

// ijkStatsGetMedian_dbl
//	Calculate the median of a sorted double data set. Half of the data are 
//	less and half are greater than the median.
//		param v: array of values
//		param n: number of values in set
//		return: median
dbl ijkStatsGetMedian_dbl(dbl const v[], size const n);


// ijkStatsGetMean_int_flt
//	Calculate the mean (average) of an integer data set.
//		param v: array of values
//		param n: number of values in set
//		return: mean as float
flt ijkStatsGetMean_int_flt(schomp const v[], size const n);

// ijkStatsGetMean_int_dbl
//	Calculate the mean (average) of an integer data set.
//		param v: array of values
//		param n: number of values in set
//		return: mean as double
dbl ijkStatsGetMean_int_dbl(schomp const v[], size const n);

// ijkStatsGetMean_flt
//	Calculate the mean (average) of a float data set.
//		param v: array of values
//		param n: number of values in set
//		return: mean
flt ijkStatsGetMean_flt(flt const v[], size const n);

// ijkStatsGetMean_dbl
//	Calculate the mean (average) of a double data set.
//		param v: array of values
//		param n: number of values in set
//		return: mean
dbl ijkStatsGetMean_dbl(dbl const v[], size const n);


// ijkStatsGetVariance_int_flt
//	Calculate the variance (squared mean deviation) of an integer data set.
//		param v: array of values
//		param n: number of values in set
//		param mean_opt: optional pointer to capture mean in calculation
//		return: variance as float
flt ijkStatsGetVariance_int_flt(schomp const v[], size const n, flt mean_opt[1]);

// ijkStatsGetVariance_int_dbl
//	Calculate the variance (squared mean deviation) of an integer data set.
//		param v: array of values
//		param n: number of values in set
//		param mean_opt: optional pointer to capture mean in calculation
//		return: variance as double
dbl ijkStatsGetVariance_int_dbl(schomp const v[], size const n, dbl mean_opt[1]);

// ijkStatsGetVariance_flt
//	Calculate the variance (squared mean deviation) of a float data set.
//		param v: array of values
//		param n: number of values in set
//		param mean_opt: optional pointer to capture mean in calculation
//		return: variance
flt ijkStatsGetVariance_flt(flt const v[], size const n, flt mean_opt[1]);

// ijkStatsGetVariance_dbl
//	Calculate the variance (squared mean deviation) of a double data set.
//		param v: array of values
//		param n: number of values in set
//		param mean_opt: optional pointer to capture mean in calculation
//		return: variance
dbl ijkStatsGetVariance_dbl(dbl const v[], size const n, dbl mean_opt[1]);


// ijkStatsGetStdDev_int_flt
//	Calculate the standard deviation (from mean) of an integer data set.
//		param v: array of values
//		param n: number of values in set
//		param mean_opt: optional pointer to capture mean in calculation
//		return: standard deviation as float
flt ijkStatsGetStdDev_int_flt(schomp const v[], size const n, flt mean_opt[1]);

// ijkStatsGetStdDev_int_dbl
//	Calculate the standard deviation (from mean) of an integer data set.
//		param v: array of values
//		param n: number of values in set
//		param mean_opt: optional pointer to capture mean in calculation
//		return: standard deviation as double
dbl ijkStatsGetStdDev_int_dbl(schomp const v[], size const n, dbl mean_opt[1]);

// ijkStatsGetStdDev_flt
//	Calculate the standard deviation (from mean) of an integer data set.
//		param v: array of values
//		param n: number of values in set
//		param mean_opt: optional pointer to capture mean in calculation
//		return: standard deviation
flt ijkStatsGetStdDev_flt(flt const v[], size const n, flt mean_opt[1]);

// ijkStatsGetStdDev_dbl
//	Calculate the standard deviation (from mean) of an integer data set.
//		param v: array of values
//		param n: number of values in set
//		param mean_opt: optional pointer to capture mean in calculation
//		return: standard deviation
dbl ijkStatsGetStdDev_dbl(dbl const v[], size const n, dbl mean_opt[1]);


//-----------------------------------------------------------------------------

#define ijkStatsGetMedian_int	ijk_declrealf(ijkStatsGetMedian_int)
#define ijkStatsGetMedian		ijk_declrealf(ijkStatsGetMedian)
#define ijkStatsGetMean_int		ijk_declrealf(ijkStatsGetMean_int)
#define ijkStatsGetMean			ijk_declrealf(ijkStatsGetMean)
#define ijkStatsGetVariance_int	ijk_declrealf(ijkStatsGetVariance_int)
#define ijkStatsGetVariance		ijk_declrealf(ijkStatsGetVariance)
#define ijkStatsGetStdDev_int	ijk_declrealf(ijkStatsGetStdDev_int)
#define ijkStatsGetStdDev		ijk_declrealf(ijkStatsGetStdDev)


//-----------------------------------------------------------------------------


#include "_inl/ijkStats.inl"


#endif	// !_IJK_STATS_H_