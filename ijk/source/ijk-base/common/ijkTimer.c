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

	ijkTimer.c
	Timer utility implementation.
*/

#include "ijk/ijk-base/ijkTimer.h"


#if (__ijk_cfg_platform == WINDOWS)
#include <Windows.h>
#ifdef MIDL_PASS
#define Q			qs
#else	// !MIDL_PASS
#define Q			qu
#endif	// MIDL_PASS
#else	// !WINDOWS
#include <time.h>
#define Q			qs
#define BILLION		1000000000
#endif	// WINDOWS


//-----------------------------------------------------------------------------

iret ijkTimerReset(ijkTimer* const timer)
{
	if (timer)
	{

	}
	return ijk_fail_invalidparams;
}


iret ijkTimerSet(ijkTimer* const timer, dbl const ticksPerSecond)
{
	if (timer)
	{

	}
	return ijk_fail_invalidparams;
}


iret ijkTimerStart(ijkTimer* const timer)
{
	if (timer)
	{

	}
	return ijk_fail_invalidparams;
}


iret ijkTimerStop(ijkTimer* const timer)
{
	if (timer)
	{

	}
	return ijk_fail_invalidparams;
}


iret ijkTimerCheckTick(ijkTimer* const timer)
{
	if (timer)
	{

	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------
