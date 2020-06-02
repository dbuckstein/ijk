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

	ijkReal.c
	Source definitions for real number.
*/

#include "ijk/ijk-math/ijk-real/ijkReal.h"


//-----------------------------------------------------------------------------

#define __real_zero					0.0
#define __real_1000th				0.001
#define __real_100th				0.01
#define __real_10th					0.1
#define __real_9th					0.11111111111111111111111111111111
#define __real_8th					0.125
#define __real_7th					0.14285714285714285714285714285714
#define __real_6th					0.16666666666666666666666666666667
#define __real_5th					0.2
#define __real_quarter				0.25
#define __real_third				0.33333333333333333333333333333333
#define __real_half					0.5
#define __real_2thirds				0.66666666666666666666666666666667
#define __real_3quarters			0.75
#define __real_one					1.0
#define __real_4third				1.3333333333333333333333333333333
#define __real_3half				1.5
#define __real_two					2.0
#define __real_three				3.0
#define __real_four					4.0
#define __real_five					5.0
#define __real_six					6.0
#define __real_seven				7.0
#define __real_eight				8.0
#define __real_nine					9.0
#define __real_ten					10.0
#define __real_hundred				100.0
#define __real_thousand				1000.0
#define __real_sqrtthird			0.57735026918962576450914878050196
#define __real_sqrthalf				0.70710678118654752440084436210485
#define __real_sqrt2				1.4142135623730950488016887242097
#define __real_sqrt3				1.7320508075688772935274463415059
#define __real_2pi					6.283185307179586476925286766559
#define __real_pi					3.1415926535897932384626433832795
#define __real_halfpi				1.5707963267948966192313216916398
#define __real_thirdpi				1.0471975511965977461542144610932
#define __real_quarterpi			0.78539816339744830961566084581988
#define __real_360					360.0
#define __real_180					180.0
#define __real_90					90.0
#define __real_60					60.0
#define __real_45					45.0
#define __real_deg2rad				0.01745329251994329576923690768489
#define __real_rad2deg				57.295779513082320876798154814105


//-----------------------------------------------------------------------------

flt const flt_zero = (flt)__real_zero;
flt const flt_eps = 1.19e-07f;
flt const flt_halfeps = 5.96e-08f;
flt const flt_1000th = (flt)__real_1000th;
flt const flt_100th = (flt)__real_100th;
flt const flt_10th = (flt)__real_10th;
flt const flt_9th = (flt)__real_9th;
flt const flt_8th = (flt)__real_8th;
flt const flt_7th = (flt)__real_7th;
flt const flt_6th = (flt)__real_6th;
flt const flt_5th = (flt)__real_5th;
flt const flt_quarter = (flt)__real_quarter;
flt const flt_third = (flt)__real_third;
flt const flt_half = (flt)__real_half;
flt const flt_2thirds = (flt)__real_2thirds;
flt const flt_3quarters = (flt)__real_3quarters;
flt const flt_one = (flt)__real_one;
flt const flt_4third = (flt)__real_4third;
flt const flt_3half = (flt)__real_3half;
flt const flt_two = (flt)__real_two;
flt const flt_three = (flt)__real_three;
flt const flt_four = (flt)__real_four;
flt const flt_five = (flt)__real_five;
flt const flt_six = (flt)__real_six;
flt const flt_seven = (flt)__real_seven;
flt const flt_eight = (flt)__real_eight;
flt const flt_nine = (flt)__real_nine;
flt const flt_ten = (flt)__real_ten;
flt const flt_hundred = (flt)__real_hundred;
flt const flt_thousand = (flt)__real_thousand;
flt const flt_sqrtthird = (flt)__real_sqrtthird;
flt const flt_sqrthalf = (flt)__real_sqrthalf;
flt const flt_sqrt2 = (flt)__real_sqrt2;
flt const flt_sqrt3 = (flt)__real_sqrt3;
flt const flt_2pi = (flt)__real_2pi;
flt const flt_pi = (flt)__real_pi;
flt const flt_halfpi = (flt)__real_halfpi;
flt const flt_thirdpi = (flt)__real_thirdpi;
flt const flt_quarterpi = (flt)__real_quarterpi;
flt const flt_360 = (flt)__real_360;
flt const flt_180 = (flt)__real_180;
flt const flt_90 = (flt)__real_90;
flt const flt_60 = (flt)__real_60;
flt const flt_45 = (flt)__real_45;
flt const flt_deg2rad = (flt)__real_deg2rad;
flt const flt_rad2deg = (flt)__real_rad2deg;


//-----------------------------------------------------------------------------

dbl const dbl_zero = (dbl)__real_zero;
dbl const dbl_eps = 2.22e-16;
dbl const dbl_halfeps = 1.11e-16;
dbl const dbl_1000th = (dbl)__real_1000th;
dbl const dbl_100th = (dbl)__real_100th;
dbl const dbl_10th = (dbl)__real_10th;
dbl const dbl_9th = (dbl)__real_9th;
dbl const dbl_8th = (dbl)__real_8th;
dbl const dbl_7th = (dbl)__real_7th;
dbl const dbl_6th = (dbl)__real_6th;
dbl const dbl_5th = (dbl)__real_5th;
dbl const dbl_quarter = (dbl)__real_quarter;
dbl const dbl_third = (dbl)__real_third;
dbl const dbl_half = (dbl)__real_half;
dbl const dbl_2thirds = (dbl)__real_2thirds;
dbl const dbl_3quarters = (dbl)__real_3quarters;
dbl const dbl_one = (dbl)__real_one;
dbl const dbl_4third = (dbl)__real_4third;
dbl const dbl_3half = (dbl)__real_3half;
dbl const dbl_two = (dbl)__real_two;
dbl const dbl_three = (dbl)__real_three;
dbl const dbl_four = (dbl)__real_four;
dbl const dbl_five = (dbl)__real_five;
dbl const dbl_six = (dbl)__real_six;
dbl const dbl_seven = (dbl)__real_seven;
dbl const dbl_eight = (dbl)__real_eight;
dbl const dbl_nine = (dbl)__real_nine;
dbl const dbl_ten = (dbl)__real_ten;
dbl const dbl_hundred = (dbl)__real_hundred;
dbl const dbl_thousand = (dbl)__real_thousand;
dbl const dbl_sqrtthird = (dbl)__real_sqrtthird;
dbl const dbl_sqrthalf = (dbl)__real_sqrthalf;
dbl const dbl_sqrt2 = (dbl)__real_sqrt2;
dbl const dbl_sqrt3 = (dbl)__real_sqrt3;
dbl const dbl_2pi = (dbl)__real_2pi;
dbl const dbl_pi = (dbl)__real_pi;
dbl const dbl_halfpi = (dbl)__real_halfpi;
dbl const dbl_thirdpi = (dbl)__real_thirdpi;
dbl const dbl_quarterpi = (dbl)__real_quarterpi;
dbl const dbl_360 = (dbl)__real_360;
dbl const dbl_180 = (dbl)__real_180;
dbl const dbl_90 = (dbl)__real_90;
dbl const dbl_60 = (dbl)__real_60;
dbl const dbl_45 = (dbl)__real_45;
dbl const dbl_deg2rad = (dbl)__real_deg2rad;
dbl const dbl_rad2deg = (dbl)__real_rad2deg;


//-----------------------------------------------------------------------------
