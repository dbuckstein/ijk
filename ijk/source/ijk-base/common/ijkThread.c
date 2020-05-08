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


// internal name set function
// from "How to: Set a Thread Name in Native Code"
// msdn.microsoft.com
iret ijkThreadInternalSetName(dword id, kptag name)
{
	// name must exist and id must be -1 or positive
	if (name && id)
	{
#if (defined _WINDOWS || defined _WIN32)
		// name change structure: 
		// declare a data structure that can be used internally
#pragma pack(push, 8)	// 8-bit alignment
		typedef struct tagTHREADNAME_INFO
		{
			dword type;		// must be 0x1000 (reserved)
			kptag name;		// name string
			dword threadID;	// thread ID (-1 for calling thread)
			dword flags;	// must be zero (reserved)
		} THREADNAME_INFO;
		THREADNAME_INFO info = { 0x1000, name, id, 0 };
#pragma pack(pop)
#pragma warning(push)
#pragma warning(disable: 6320 6322)	// suppress warnings
		__try
		{
			__try
			{
				// attempt name change
				RaiseException(0x406D1388, 0,
					sizeof(info) / sizeof(DWORD), (ULONG_PTR*)(&info));
			}
			__finally
			{
				// end exception
			}
		}
		__except (EXCEPTION_EXECUTE_HANDLER)
		{
			// unhandled exception
		}
#pragma warning(pop)
		return 1;
#else	// !(defined _WINDOWS || defined _WIN32)
		// do rename
		return 0;
#endif	// (defined _WINDOWS || defined _WIN32)
	}
	return -1;
}


// internal thread launcher
#if (__ijk_cfg_platform == WINDOWS)
iret __stdcall ijkThreadInternalEntryFunc(ijkThread* const thread)
{
#else	// !WINDOWS
ptr ijkThreadFuncEntry(ijkThread* const thread)
{
	// push "not complete" flag
	// set "not complete" parameter to not-complete
#endif	// WINDOWS

	// change name of thread before execution so we can identify it
	if (*thread->name)
		ijkThreadInternalSetName(-1, thread->name);

	// call thread entry function, raising active flag before and lower after
	thread->active = ijk_true;
	thread->result = thread->entryFunc(thread->entryArg);
	thread->active = ijk_false;

	// reset handle and ID
	thread->sysID = 0;
	*thread->handle = 0;

#if (__ijk_cfg_platform == WINDOWS)
	return thread->result;
}
#else	// !WINDOWS
	// pop "non complete" flag
	return thread;
}
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
			*thread_out->handle = CreateThread(0, 0, ijkThreadInternalEntryFunc, thread_out, 0, &thread_out->sysID);
#else	// !WINDOWS
			thread_out->sysID = 1;
			pthread_create((pthread_t*)thread_out->handle, 0, ijkThreadInternalEntryFunc, thread_out);
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
