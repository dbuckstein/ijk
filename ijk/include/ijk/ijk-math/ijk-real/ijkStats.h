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


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus


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


//-----------------------------------------------------------------------------

// ijkStatsGetMedianInt_flt
//	Calculate the median of a sorted integer data set. Half of the data are 
//	less and half are greater than the median.
//		param v: array of values
//		param n: number of values in set
//		return: median as float
flt ijkStatsGetMedianInt_flt(schomp const v[], size const n);

// ijkStatsGetMeanInt_flt
//	Calculate the mean (average) of an integer data set.
//		param v: array of values
//		param n: number of values in set
//		return: mean as float
flt ijkStatsGetMeanInt_flt(schomp const v[], size const n);

// ijkStatsGetVarianceInt_flt
//	Calculate the variance (squared mean deviation) of an integer data set.
//		param v: array of values
//		param n: number of values in set
//		param mean_opt: optional pointer to capture mean in calculation
//		return: variance as float
flt ijkStatsGetVarianceInt_flt(schomp const v[], size const n, flt mean_opt[1]);

// ijkStatsGetStdDevInt_flt
//	Calculate the standard deviation (from mean) of an integer data set.
//		param v: array of values
//		param n: number of values in set
//		param mean_opt: optional pointer to capture mean in calculation
//		return: standard deviation as float
flt ijkStatsGetStdDevInt_flt(schomp const v[], size const n, flt mean_opt[1]);

// ijkStatsGetMedian_flt
//	Calculate the median of a sorted data set. Half of the data are 
//	less and half are greater than the median.
//		param v: array of values
//		param n: number of values in set
//		return: median
flt ijkStatsGetMedian_flt(flt const v[], size const n);

// ijkStatsGetMean_flt
//	Calculate the mean (average) of a data set.
//		param v: array of values
//		param n: number of values in set
//		return: mean
flt ijkStatsGetMean_flt(flt const v[], size const n);

// ijkStatsGetVariance_flt
//	Calculate the variance (squared mean deviation) of a data set.
//		param v: array of values
//		param n: number of values in set
//		param mean_opt: optional pointer to capture mean in calculation
//		return: variance
flt ijkStatsGetVariance_flt(flt const v[], size const n, flt mean_opt[1]);

// ijkStatsGetStdDev_flt
//	Calculate the standard deviation (from mean) of a data set.
//		param v: array of values
//		param n: number of values in set
//		param mean_opt: optional pointer to capture mean in calculation
//		return: standard deviation
flt ijkStatsGetStdDev_flt(flt const v[], size const n, flt mean_opt[1]);


//-----------------------------------------------------------------------------

// ijkStatsGetMedianInt_dbl
//	Calculate the median of a sorted integer data set. Half of the data are 
//	less and half are greater than the median.
//		param v: array of values
//		param n: number of values in set
//		return: median as double
dbl ijkStatsGetMedianInt_dbl(schomp const v[], size const n);

// ijkStatsGetMeanInt_dbl
//	Calculate the mean (average) of an integer data set.
//		param v: array of values
//		param n: number of values in set
//		return: mean as double
dbl ijkStatsGetMeanInt_dbl(schomp const v[], size const n);

// ijkStatsGetVarianceInt_dbl
//	Calculate the variance (squared mean deviation) of an integer data set.
//		param v: array of values
//		param n: number of values in set
//		param mean_opt: optional pointer to capture mean in calculation
//		return: variance as double
dbl ijkStatsGetVarianceInt_dbl(schomp const v[], size const n, dbl mean_opt[1]);

// ijkStatsGetStdDevInt_dbl
//	Calculate the standard deviation (from mean) of an integer data set.
//		param v: array of values
//		param n: number of values in set
//		param mean_opt: optional pointer to capture mean in calculation
//		return: standard deviation as double
dbl ijkStatsGetStdDevInt_dbl(schomp const v[], size const n, dbl mean_opt[1]);

// ijkStatsGetMedian_dbl
//	Calculate the median of a sorted data set. Half of the data are 
//	less and half are greater than the median.
//		param v: array of values
//		param n: number of values in set
//		return: median
dbl ijkStatsGetMedian_dbl(dbl const v[], size const n);

// ijkStatsGetMean_dbl
//	Calculate the mean (average) of a data set.
//		param v: array of values
//		param n: number of values in set
//		return: mean
dbl ijkStatsGetMean_dbl(dbl const v[], size const n);

// ijkStatsGetVariance_dbl
//	Calculate the variance (squared mean deviation) of a data set.
//		param v: array of values
//		param n: number of values in set
//		param mean_opt: optional pointer to capture mean in calculation
//		return: variance
dbl ijkStatsGetVariance_dbl(dbl const v[], size const n, dbl mean_opt[1]);

// ijkStatsGetStdDev_dbl
//	Calculate the standard deviation (from mean) of a data set.
//		param v: array of values
//		param n: number of values in set
//		param mean_opt: optional pointer to capture mean in calculation
//		return: standard deviation
dbl ijkStatsGetStdDev_dbl(dbl const v[], size const n, dbl mean_opt[1]);


//-----------------------------------------------------------------------------

// ijkStatsGetMedianInt
//	Calculate the median of a sorted integer data set. Half of the data are 
//	less and half are greater than the median.
//		param v: array of values
//		param n: number of values in set
//		return: median as double
// real ijkStatsGetMedianInt(schomp const v[], size const n);
#define ijkStatsGetMedianInt	ijk_declrealf(ijkStatsGetMedianInt)

// ijkStatsGetMeanInt
//	Calculate the mean (average) of an integer data set.
//		param v: array of values
//		param n: number of values in set
//		return: mean as double
// real ijkStatsGetMeanInt(schomp const v[], size const n);
#define ijkStatsGetMeanInt		ijk_declrealf(ijkStatsGetMeanInt)

// ijkStatsGetVarianceInt
//	Calculate the variance (squared mean deviation) of an integer data set.
//		param v: array of values
//		param n: number of values in set
//		param mean_opt: optional pointer to capture mean in calculation
//		return: variance as double
// real ijkStatsGetVarianceInt(schomp const v[], size const n, real mean_opt[1]);
#define ijkStatsGetVarianceInt	ijk_declrealf(ijkStatsGetVarianceInt)

// ijkStatsGetStdDevInt
//	Calculate the standard deviation (from mean) of an integer data set.
//		param v: array of values
//		param n: number of values in set
//		param mean_opt: optional pointer to capture mean in calculation
//		return: standard deviation as double
// real ijkStatsGetStdDevInt(schomp const v[], size const n, real mean_opt[1]);
#define ijkStatsGetStdDevInt	ijk_declrealf(ijkStatsGetStdDevInt)

// ijkStatsGetMedian
//	Calculate the median of a sorted data set. Half of the data are 
//	less and half are greater than the median.
//		param v: array of values
//		param n: number of values in set
//		return: median
// real ijkStatsGetMedian(real const v[], size const n);
#define ijkStatsGetMedian		ijk_declrealf(ijkStatsGetMedian)

// ijkStatsGetMean
//	Calculate the mean (average) of a data set.
//		param v: array of values
//		param n: number of values in set
//		return: mean
// real ijkStatsGetMean(real const v[], size const n);
#define ijkStatsGetMean			ijk_declrealf(ijkStatsGetMean)

// ijkStatsGetVariance
//	Calculate the variance (squared mean deviation) of a data set.
//		param v: array of values
//		param n: number of values in set
//		param mean_opt: optional pointer to capture mean in calculation
//		return: variance
// real ijkStatsGetVariance(real const v[], size const n, real mean_opt[1]);
#define ijkStatsGetVariance		ijk_declrealf(ijkStatsGetVariance)

// ijkStatsGetStdDev
//	Calculate the standard deviation (from mean) of a data set.
//		param v: array of values
//		param n: number of values in set
//		param mean_opt: optional pointer to capture mean in calculation
//		return: standard deviation
// real ijkStatsGetStdDev(real const v[], size const n, real mean_opt[1]);
#define ijkStatsGetStdDev		ijk_declrealf(ijkStatsGetStdDev)


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#include "_inl/ijkStats.inl"


#endif	// !_IJK_STATS_H_