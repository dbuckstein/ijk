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

	ijkThread.c
	Thread utility implementation.
*/

#include "ijk/ijk-base/ijkThread.h"


// include platform APIs
#if (__ijk_cfg_platform == WINDOWS)
#include <Windows.h>
#else	// !WINDOWS
#include <pthread.h>
#include <signal.h>
#include <sys/types.h>
#endif	// WINDOWS


iret ijkThreadCreate(ijkThread* const thread_out, ijkThreadFunc const entryFunc, ptr const entryArg, tag const name)
{
	// validate parameters
	if (thread_out && entryFunc)
	{
		// validate parameters are not in-use
		if (*thread_out->handle == 0)
		{
			// default values
			thread_out->active = ijk_false;
			thread_out->result = ijk_failure;
			thread_out->entryFunc = entryFunc;
			thread_out->entryArg = entryArg;
			ijk_copytag(thread_out->name, name);

			// launch
#if (__ijk_cfg_platform == WINDOWS)
#else	// !WINDOWS
#endif	// WINDOWS
		}
	}
	return ijk_failure;
}


iret ijkThreadRelease(ijkThread* const thread)
{
	// validate parameter
	if (thread)
	{
		// validate parameter is a valid thread in-use
		if (*thread->handle != 0)
		{

		}
	}
	return ijk_failure;
}
