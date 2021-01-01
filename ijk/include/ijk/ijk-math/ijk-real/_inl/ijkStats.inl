/*
   Copyright 2020-2021 Daniel S. Buckstein

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

	ijkStats.inl
	Inline definitions for statistics functions.
*/

#ifdef _IJK_STATS_H_
#ifndef _IJK_STATS_INL_
#define _IJK_STATS_INL_


//-----------------------------------------------------------------------------

ijk_inl size ijkStatsGetFactorial(size const n)
{
	uitr i = 1, f = i;
	while (i < n)
		f *= ++i;
	return f;
}


ijk_inl size ijkStatsGetPermutations(size const n, size const k)
{
	if (k <= n)
		return (ijkStatsGetFactorial(n) / ijkStatsGetFactorial(n - k));
	return 0;
}


ijk_inl size ijkStatsGetCombinations(size const n, size const k)
{
	if (k <= n)
		return (ijkStatsGetFactorial(n) / (ijkStatsGetFactorial(n - k) * ijkStatsGetFactorial(k)));
	return 0;
}


ijk_inl size ijkStatsPascal(size const n, size const k)
{
	if (k <= n)
	{
		size i, v = 1;
		for (i = 0; i < k; ++i)
			v = (v * (n - i)) / (i + 1);
		return v;
	}
	return 0;
}


//-----------------------------------------------------------------------------

ijk_inl flt ijkStatsGetMedianInt_flt(schomp const v[], size const n)
{
	uitr const half = n >> 1;
	if (((n + 1) >> 1) - half)
		return (flt)v[half];
	return (flt_half * (flt)(v[half] + v[half - 1]));
}


ijk_inl flt ijkStatsGetMeanInt_flt(schomp const v[], size const n)
{
	if (n > 0)
	{
		schomp sum;
		uitr i;
		for (i = 0, sum = 0; i < n; ++i)
			sum += v[i];
		return ((flt)sum / (flt)n);
	}
	return flt_zero;
}


ijk_inl flt ijkStatsGetVarianceInt_flt(schomp const v[], size const n, flt mean_opt[1])
{
	flt mean = flt_zero, var = flt_zero, dvar;
	schomp sum;
	uitr i;
	if (n > 1)
	{
		for (i = 0, sum = 0; i < n; ++i)
			sum += v[i];
		for (mean = ((flt)sum / (flt)n),
			i = 0; i < n; ++i)
		{
			dvar = (flt)v[i] - mean;
			var += dvar * dvar;
		}
		var /= (flt)(n - 1);
	}
	if (mean_opt)
		*mean_opt = mean;
	return var;
}


ijk_inl flt ijkStatsGetStdDevInt_flt(schomp const v[], size const n, flt mean_opt[1])
{
	flt const var = ijkStatsGetVarianceInt_flt(v, n, mean_opt);
	return ijkSqrt_flt(var);
}


ijk_inl flt ijkStatsGetMedian_flt(flt const v[], size const n)
{
	uitr const half = n >> 1;
	if (((n + 1) >> 1) - half)
		return v[half];
	return (flt_half * (v[half] + v[half - 1]));
}


ijk_inl flt ijkStatsGetMean_flt(flt const v[], size const n)
{
	if (n > 0)
	{
		flt sum;
		uitr i;
		for (i = 0, sum = flt_zero; i < n; ++i)
			sum += v[i];
		return (sum / (flt)n);
	}
	return flt_zero;
}


ijk_inl flt ijkStatsGetVariance_flt(flt const v[], size const n, flt mean_opt[1])
{
	flt mean = flt_zero, var = flt_zero, dvar;
	uitr i;
	if (n > 1)
	{
		for (i = 0; i < n; ++i)
			mean += v[i];
		for (mean /= (flt)n,
			i = 0; i < n; ++i)
		{
			dvar = v[i] - mean;
			var += dvar * dvar;
		}
		var /= (flt)(n - 1);
	}
	if (mean_opt)
		*mean_opt = mean;
	return var;
}


ijk_inl flt ijkStatsGetStdDev_flt(flt const v[], size const n, flt mean_opt[1])
{
	flt const var = ijkStatsGetVariance_flt(v, n, mean_opt);
	return ijkSqrt_flt(var);
}


//-----------------------------------------------------------------------------

ijk_inl dbl ijkStatsGetMedianInt_dbl(schomp const v[], size const n)
{
	uitr const half = n >> 1;
	if (((n + 1) >> 1) - half)
		return (dbl)v[half];
	return (dbl_half * (dbl)(v[half] + v[half - 1]));
}


ijk_inl dbl ijkStatsGetMeanInt_dbl(schomp const v[], size const n)
{
	if (n > 0)
	{
		schomp sum;
		uitr i;
		for (i = 0, sum = 0; i < n; ++i)
			sum += v[i];
		return ((dbl)sum / (dbl)n);
	}
	return dbl_zero;
}


ijk_inl dbl ijkStatsGetVarianceInt_dbl(schomp const v[], size const n, dbl mean_opt[1])
{
	dbl mean = flt_zero, var = flt_zero, dvar;
	schomp sum;
	uitr i;
	if (n > 1)
	{
		for (i = 0, sum = 0; i < n; ++i)
			sum += v[i];
		for (mean = ((dbl)sum / (dbl)n),
			i = 0; i < n; ++i)
		{
			dvar = (dbl)v[i] - mean;
			var += dvar * dvar;
		}
		var /= (dbl)(n - 1);
	}
	if (mean_opt)
		*mean_opt = mean;
	return var;
}


ijk_inl dbl ijkStatsGetStdDevInt_dbl(schomp const v[], size const n, dbl mean_opt[1])
{
	dbl const var = ijkStatsGetVarianceInt_dbl(v, n, mean_opt);
	return ijkSqrt_dbl(var);
}


ijk_inl dbl ijkStatsGetMedian_dbl(dbl const v[], size const n)
{
	uitr const half = n >> 1;
	if (((n + 1) >> 1) - half)
		return v[half];
	return (dbl_half * (v[half] + v[half - 1]));
}


ijk_inl dbl ijkStatsGetMean_dbl(dbl const v[], size const n)
{
	if (n > 0)
	{
		dbl sum;
		uitr i;
		for (i = 0, sum = dbl_zero; i < n; ++i)
			sum += v[i];
		return (sum / (dbl)n);
	}
	return dbl_zero;
}


ijk_inl dbl ijkStatsGetVariance_dbl(dbl const v[], size const n, dbl mean_opt[1])
{
	dbl mean = flt_zero, var = flt_zero, dvar;
	uitr i;
	if (n > 1)
	{
		for (i = 0; i < n; ++i)
			mean += v[i];
		for (mean /= (dbl)n,
			i = 0; i < n; ++i)
		{
			dvar = v[i] - mean;
			var += dvar * dvar;
		}
		var /= (dbl)(n - 1);
	}
	if (mean_opt)
		*mean_opt = mean;
	return var;
}


ijk_inl dbl ijkStatsGetStdDev_dbl(dbl const v[], size const n, dbl mean_opt[1])
{
	dbl const var = ijkStatsGetVariance_dbl(v, n, mean_opt);
	return ijkSqrt_dbl(var);
}


//-----------------------------------------------------------------------------


#endif	// !_IJK_STATS_INL_
#endif	// _IJK_STATS_H_