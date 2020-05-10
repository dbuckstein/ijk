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

	ijkTimer.h
	Timer utility interface.
*/

#ifndef _IJK_TIMER_H_
#define _IJK_TIMER_H_


#include "ijk/ijk/ijk-typedefs.h"


#ifdef __cplusplus
extern "C" {
#else	// !__cplusplus
typedef struct		ijkTimer			ijkTimer;
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
struct ijkTimer
{
	ibool active;						// running flag
	qword tickCount;					// number of ticks
	dbl totalTime;						// total time taken
	dbl tickMeasure;					// current tick measurement
	dbl tickComplete;					// completed tick measurement
	dbl ticksPerSecond;					// expected tick rate
	dbl secondsPerTick;					// expected tick time
	union {								// internal measurement
		struct {
			i32 q[2];
			i64 qs;
		};
		ui64 qu;
	} tf[1], t0[1], t1[1];
};


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#include "_inl/ijkTimer.inl"


#endif	// !_IJK_TIMER_H_