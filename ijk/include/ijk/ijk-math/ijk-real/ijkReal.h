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

	ijkReal.h
	Real number types.
*/

#ifndef _IJK_REAL_H_
#define _IJK_REAL_H_


#include "ijk/ijk/ijk-typedefs.h"


// definitions of reusable pointer-based vector types
///
typedef int			int2[2], int3[3], int4[4], * pint2, * pint3, * pint4;
typedef int const	* kpint2, * kpint3, * kpint4;
typedef flt			flt2[2], flt3[3], flt4[4], * pflt2, * pflt3, * pflt4;
typedef flt const	* kpflt2, * kpflt3, * kpflt4;
typedef dbl			dbl2[2], dbl3[3], dbl4[4], * pdbl2, * pdbl3, * pdbl4;
typedef dbl const	* kpdbl2, * kpdbl3, * kpdbl4;


// IJK_REAL_DBL
//	User-defined macro to select double as base real number type. If not 
//	defined, the base real number type defaults to float.	
#ifdef IJK_REAL_DBL
typedef dbl real;
#else	// !IJK_REAL_DBL
typedef flt real;
#endif	// IJK_REAL_DBL

// definitions of reusable pointer-based real number types
///
typedef real		real2[2], real3[3], real4[4], * preal2, * preal3, * preal4;
typedef real const	* kreal2, * kreal3, * kreal4;


// ijk_lerp
//	Linear interpolation.
//		param v0: lower bound at t=0
//		param v1: upper bound at t=1
//		param t: interpolation parameter; t=[0,1] for interpolation,
//			t=(-inf,0)U(1,+inf) for extrapolation
//		return: interpolated value 'v'; v=[v0,v1] for interpolation,
//			v=(-inf,v0)U(v1,+inf) for extrapolation
#define ijk_lerp(v0,v1,t)			((v0) + ((v1) - (v0)) * (t))

// ijk_unlerp
//	Linear interpolation inverse.
//		param v0: lower bound at t=0
//		param v1: upper bound at t=1
//		param v: interpolated value; v=[v0,v1] for interpolation,
//			v=(-inf,v0)U(v1,+inf) for extrapolation
//		return: interpolation parameter 't'; t=[0,1] for interpolation,
//			t=(-inf,0)U(1,+inf) for extrapolation
#define ijk_unlerp(v0,v1,v)			(((v) - (v0)) / ((v1) - (v0)))

// ijk_unlerp_safe
//	Linear interpolation with division-by-zero safety.
#define ijk_unlerp_safe(v0,v1,v)	((v0) != (v1) ? ijk_unlerp(v0,v1,v) : ((v1) - (v0)))

// ijk_remap
//	Re-map or re-interpolate value from one range into another.
//		param v0_new: lower bound of new/output range
//		param v1_new: upper bound of new/output range
//		param v0_orig: lower bound of original/input range
//		param v1_orig: upper bound of original/input range
//		return: re-interpolated value 'v_new' in new/output range
#define ijk_remap(v0_new,v1_new,v0_orig,v1_orig,v_orig)			((v0_new) + (((v1_new) - (v0_new)) * ((v_orig) - (v0_orig))) / ((v1_orig) - (v0_orig)))

// ijk_remap_safe
//	Re-map/re-interpolate with division-by-zero safety.
#define ijk_remap_safe(v0_new,v1_new,v0_orig,v1_orig,v_orig)	((v0_orig) != (v1_orig) ? ijk_remap(v0_new,v1_new,v0_orig,v1_orig,v_orig) : (v0_new))


#define ijk_sgn_i(x)		((x) > 0	? +1	: (x) < 0		? -1	: 0)
#define ijk_sgn_f(x)		((x) > 0.0f	? +1.0f	: (x) < 0.0f	? -1.0f	: 0.0f)
#define ijk_sgn_d(x)		((x) > 0.0	? +1.0	: (x) < 0.0		? -1.0	: 0.0)

#define ijk_abs_i(x)		((x) >= 0		? +(x) : -(x))
#define ijk_abs_f(x)		((x) >= 0.0f	? +(x) : -(x))
#define ijk_abs_d(x)		((x) >= 0.0		? +(x) : -(x))

#define ijk_unit2symm_i(v)	(((v) << 1) - 1)
#define ijk_unit2symm_f(v)	((v) * 2.0f - 1.0f)
#define ijk_unit2symm_d(v)	((v) * 2.0 - 1.0)

#define ijk_symm2unit_i(v)	(((v) + 1) >> 1)
#define ijk_symm2unit_f(v)	((v) * 0.5f + 0.5f)
#define ijk_symm2unit_d(v)	((v) * 0.5 + 0.5)


#endif	// !_IJK_REAL_H_