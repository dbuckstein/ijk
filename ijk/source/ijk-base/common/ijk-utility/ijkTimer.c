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

	ijkTimer.c
	Timer utility implementation.
*/

#include "ijk/ijk-base/ijk-utility/ijkTimer.h"


#if (__ijk_cfg_platform == WINDOWS)
#include <Windows.h>
#else	// !WINDOWS
#include <time.h>
#define BILLION				1000000000
typedef struct timespec		timespec;
#endif	// WINDOWS


//-----------------------------------------------------------------------------

iret ijkTimerReset(ijkTimer* const timer)
{
	if (timer)
	{
		// set all to zero
		timer->active = ijk_false;
		timer->tickCount = 0;
		timer->totalTime = 0.0;
		timer->tickMeasure = 0.0;
		timer->tickComplete = 0.0;
		*timer->tf = *timer->t0 = *timer->t1 = 0;

		// success
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


iret ijkTimerSet(ijkTimer* const timer, dbl const ticksPerSecond)
{
	if (timer)
	{
		// set all to zero
		timer->active = ijk_false;
		timer->tickCount = 0;
		timer->totalTime = 0.0;
		timer->tickMeasure = 0.0;
		timer->tickComplete = 0.0;
		*timer->tf = *timer->t0 = *timer->t1 = 0;

		// set rate
		if (ticksPerSecond > 0.0)
		{
			timer->ticksPerSecond = ticksPerSecond;
			timer->secondsPerTick = 1.0 / ticksPerSecond;
		}
		else
		{
			timer->ticksPerSecond = 0.0;
			timer->secondsPerTick = 0.0;
		}

		// success
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


iret ijkTimerStart(ijkTimer* const timer)
{
	if (timer)
	{
		// take measurement
		ibool result;
#if (__ijk_cfg_platform == WINDOWS)
		result = QueryPerformanceFrequency((PLARGE_INTEGER)timer->tf)
			&& QueryPerformanceCounter((PLARGE_INTEGER)timer->t0);
#else	// !WINDOWS
		result = ijk_issuccess(clock_gettime(CLOCK_REALTIME, (timespec*)timer->t0));
		if (result)
		{
			// convert to seconds
			// measurement in nanoseconds
			*timer->t0 = BILLION * ((dword*)timer->t0)[0] + ((dword*)timer->t0)[1];
			*timer->tf = BILLION;
		}
#endif	// WINDOWS

		// check result
		if (result)
		{
			// raise flag
			timer->active = ijk_true;

			// success
			return ijk_success;
		}

		// failure
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkTimerStop(ijkTimer* const timer)
{
	if (timer)
	{
		// take measurement
		ibool result;
#if (__ijk_cfg_platform == WINDOWS)
		result = QueryPerformanceFrequency((PLARGE_INTEGER)timer->tf)
			&& QueryPerformanceCounter((PLARGE_INTEGER)timer->t1);
#else	// !WINDOWS
		result = ijk_issuccess(clock_gettime(CLOCK_REALTIME, (timespec*)timer->t1));
		if (result)
			*timer->t1 = BILLION * ((dword*)timer->t1)[0] + ((dword*)timer->t1)[1];
#endif	// WINDOWS

		// check result
		if (result)
		{
			// measure tick
			timer->tickMeasure = (dbl)(*timer->t1 - *timer->t0) / (dbl)(*timer->tf);

			// lower flag
			timer->active = ijk_false;

			// success
			return ijk_success;
		}

		// failure
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkTimerCheckTick(ijkTimer* const timer)
{
	if (timer)
	{
		// take measurement
		ibool result;
#if (__ijk_cfg_platform == WINDOWS)
		result = QueryPerformanceFrequency((PLARGE_INTEGER)timer->tf)
			&& QueryPerformanceCounter((PLARGE_INTEGER)timer->t1);
#else	// !WINDOWS
		result = ijk_issuccess(clock_gettime(CLOCK_REALTIME, (timespec*)timer->t1));
		if (result)
			*timer->t1 = BILLION * ((dword*)timer->t1)[0] + ((dword*)timer->t1)[1];
#endif	// WINDOWS

		// check result
		if (result)
		{
			// measure tick
			timer->tickMeasure = (dbl)(*timer->t1 - *timer->t0) / (dbl)(*timer->tf);

			// if not continuously updating
			if (timer->secondsPerTick > 0.0)
			{
				// reset flag
				result = ijk_false;

				// if the current measure exceeds the rate
				while (timer->tickMeasure >= timer->secondsPerTick)
				{
					// update tick: transfer expected delta from tick to total
					//	until the measured tick does not exceed rate
					timer->totalTime += timer->secondsPerTick;
					timer->tickComplete = timer->tickMeasure;
					timer->tickMeasure -= timer->secondsPerTick;

					// increment count
					++(timer->tickCount);

					// raise flag
					result = ijk_true;
				}
			}

			// always update if "continuous"
			else
			{
				// same as above
				timer->totalTime += timer->tickMeasure;
				timer->tickComplete = timer->tickMeasure;
				timer->tickMeasure = 0.0;
				++(timer->tickCount);
			}

			// copy current time measurement to previous
			if (result)
				*timer->t0 = *timer->t1;

			// done
			return result;
		}

		// failure
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------
