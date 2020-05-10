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

	ijkTimer.inl
	Timer utility inline implementation.
*/

#ifdef _IJK_TIMER_H_
#ifndef _IJK_TIMER_INL_
#define _IJK_TIMER_INL_


//-----------------------------------------------------------------------------

ijk_inl iret ijkTimerPause(ijkTimer* const timer)
{
	if (timer)
	{
		timer->active = ijk_false;
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkTimerResume(ijkTimer* const timer)
{
	if (timer)
	{
		timer->active = ijk_true;
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------


#endif	// !_IJK_TIMER_INL_
#endif	// _IJK_TIMER_H_