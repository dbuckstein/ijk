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

	ijk-macros.h
	Common macros.
*/

#ifndef _IJK_MACROS_H_
#define _IJK_MACROS_H_


#include "ijk-config.h"


// general qualifiers
///
#define ijk_inl							static inline


// general flags and checks
///
#define ijk_true						(1)
#define ijk_false						(0)
#define ijk_success						(0)
#define ijk_failure						(-1)
#define ijk_warning						(+1)
#define ijk_failcode(x)					((x) * ijk_failure)
#define ijk_warncode(x)					((x) * ijk_warning)
#define ijk_fail_invalidparams			(ijk_failcode(1))
#define ijk_fail_operationfail			(ijk_failcode(2))
#define ijk_istrue(x)					((x) != ijk_false)
#define ijk_isfalse(x)					((x) == ijk_false)
#define ijk_issuccess(x)				((x) == ijk_success)
#define ijk_isfailure(x)				((x) <= ijk_failure)
#define ijk_iswarning(x)				((x) >= ijk_warning)
#define ijk_isnfailure(x)				((x) > ijk_failure)
#define ijk_flagch(x, f)				(((x) & (f)) != (0))
#define ijk_flagnch(x, f)				(((x) & (f)) == (0))
#define ijk_flageq(x, f)				(((x) & (f)) == (f))
#define ijk_flagneq(x, f)				(((x) & (f)) != (f))


// token stringify and concatenate
///
#define ijk_tokenstr(x)					__ijk_cfg_tokenstr(x)
#define ijk_tokencat(x, y)				__ijk_cfg_tokencat(x, y)
#define ijk_tokencat_arch(x)			ijk_tokencat(x, __ijk_cfg_archbits)


// simple mathematical operations
///
#define ijk_minimum(x, y)				((x) <= (y) ? (x) : (y))
#define ijk_maximum(x, y)				((x) >= (y) ? (x) : (y))
#define ijk_clamp(lower, upper, value)	((value) >= (lower) ? (value) <= (upper) ? (value) : (upper) : (lower))
#define ijk_sgn(x)						((x) > 0 ? +1 : (x) < 0 ? -1 : 0)
#define ijk_abs(x)						((x) >= 0 ? +(x) : -(x))


// simple logical operations
///
#define ijk_swap2(x, y, tmp)			tmp=x;x=y;y=tmp
#define ijk_swap3(x, y, z, tmp)			tmp=x;x=y;y=z;z=tmp
#define ijk_swap4(x, y, z, w, tmp)		tmp=x;x=y;y=z;z=w;w=tmp


#endif	// !_IJK_MACROS_H_