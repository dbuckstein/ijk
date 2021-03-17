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

	ijkTimer.h
	Timer utility interface.
*/

#ifndef _IJK_TIMER_H_
#define _IJK_TIMER_H_


#include "ijk/ijk/ijk-typedefs.h"


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijkTimer
//	Timer descriptor.
//		member active: timer started/running flag
//		member tickCount: number of timer ticks
//		member totalTime: total time taken (updated on tick)
//		member tickMeasure: duration of current tick being measured (constant)
//		member tickComplete: duration of completed tick measurement (on tick)
//		member ticksPerSecond: expected number of ticks per second
//		member secondsPerTick: expected time per tick; inverse ticks per second
typedef struct ijkTimer
{
	bool active;						// running flag
	qword tickCount;					// number of ticks
	dbl totalTime;						// total time taken
	dbl tickMeasure;					// current tick measurement
	dbl tickComplete;					// completed tick measurement
	dbl ticksPerSecond;					// expected tick rate
	dbl secondsPerTick;					// expected tick time
	qword tf[1], t0[1], t1[1];			// internal measurement
} ijkTimer;


//-----------------------------------------------------------------------------

// ijkTimerReset
//	Stop and reset a timer to default settings, clear data.
//		param timer: pointer to timer descriptor
//			valid: non-null
//		return SUCCESS: ijk_success if timer reset
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkTimerReset(ijkTimer* const timer);

// ijkTimerSet
//	Reset and set timer to desired rate; also stops timing.
//		param timer: pointer to timer descriptor
//			valid: non-null
//		param ticksPerSecond: desired tick rate
//			note: if rate > 0, timer ticks based on interval
//			note: if rate <= 0, timer always ticks while running ("continuous")
//		return SUCCESS: ijk_success if timer set
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkTimerSet(ijkTimer* const timer, dbl const ticksPerSecond);

// ijkTimerStart
//	Begin counting time; reset current tick if already running.
//		param timer: pointer to timer descriptor
//			valid: non-null
//		return SUCCESS: ijk_success if timer started
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if timer not started
iret ijkTimerStart(ijkTimer* const timer);

// ijkTimerStop
//	Stop counting time; measures current tick.
//		param timer: pointer to timer descriptor
//			valid: non-null
//		return SUCCESS: ijk_success if timer stopped
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if timer not stopped
iret ijkTimerStop(ijkTimer* const timer);

// ijkTimerPause
//	Pause timer; does not measure current tick.
//		param timer: pointer to timer descriptor
//			valid: non-null
//		return SUCCESS: ijk_success if timer paused
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkTimerPause(ijkTimer* const timer);

// ijkTimerResume
//	Continue counting time; does not measure current tick.
//		param timer: pointer to timer descriptor
//			valid: non-null
//		return SUCCESS: ijk_success if timer resumed
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkTimerResume(ijkTimer* const timer);

// ijkTimerCheckTick
//	Measure current tick and accumulate time.
//		param timer: pointer to timer descriptor
//			valid: non-null
//		return SUCCESS: ijk_true if timer ticked
//		return SUCCESS: ijk_false if timer did not tick
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if timer not updated
iret ijkTimerCheckTick(ijkTimer* const timer);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#include "_inl/ijkTimer.inl"


#endif	// !_IJK_TIMER_H_