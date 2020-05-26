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

#include "ijk/ijk-base/ijk-utility/ijkThread.h"


// include platform APIs
#if (__ijk_cfg_platform == WINDOWS)
#include <Windows.h>
#else	// !WINDOWS
#include <pthread.h>
#include <signal.h>
#include <sys/types.h>
#endif	// WINDOWS


//-----------------------------------------------------------------------------

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
			//return ijk_fail_operationfail;
		}
#pragma warning(pop)
		return ijk_success;
#else	// !(defined _WINDOWS || defined _WIN32)
		// do rename
		return ijk_success;
#endif	// (defined _WINDOWS || defined _WIN32)
	}
	return ijk_fail_invalidparams;
}


// internal thread launcher
#if (__ijk_cfg_platform == WINDOWS)
iret __stdcall ijkThreadInternalEntryFunc(ijkThread* const thread)
{
#else	// !WINDOWS
ptr ijkThreadInternalEntryFunc(ijkThread* const thread)
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


//-----------------------------------------------------------------------------

iret ijkThreadCreate(ijkThread* const thread_out, ijkThreadEntryFunc const entryFunc, ptr const entryArg, tag const name)
{
	// validate parameters
	if (thread_out && entryFunc &&
		!*thread_out->handle)
	{
		// default values
		thread_out->active = ijk_false;
		thread_out->result = ijk_failure;
		thread_out->entryFunc = entryFunc;
		thread_out->entryArg = entryArg;
		ijk_copytag(thread_out->name, name);

		// launch
#if (__ijk_cfg_platform == WINDOWS)
		* thread_out->handle = CreateThread(0, 0, ijkThreadInternalEntryFunc, thread_out, 0, &thread_out->sysID);
#else	// !WINDOWS
		thread_out->sysID = 1;
		pthread_create((pthread_t*)thread_out->handle, 0, ijkThreadInternalEntryFunc, thread_out);
#endif	// WINDOWS

		// success
		if (*thread_out->handle)
			return ijk_success;

		// failure
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkThreadRelease(ijkThread* const thread)
{
	if (thread &&
		*thread->handle)
	{
		ibool result;
#if (__ijk_cfg_platform == WINDOWS)
		result = (WaitForSingleObject(*thread->handle, INFINITE) == WAIT_OBJECT_0);
#else	// !WINDOWS
		result = ijk_issuccess(pthread_join(*(pthread_t*)thread->handle, 0));
#endif	// WINDOWS

		// success
		if (result)
		{
			thread->sysID = 0;
			*thread->handle = 0;
			return ijk_success;
		}

		// failure
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkThreadReleaseUnsafe(ijkThread* const thread)
{
	// validate parameter
	if (thread &&
		*thread->handle)
	{
		ibool result;
#if (__ijk_cfg_platform == WINDOWS)
		// unsafe because TerminateThread does not allow thread to clean up
		// https://docs.microsoft.com/en-us/cpp/code-quality/c6258?view=vs-2019
		result = ijk_istrue(TerminateThread(*thread->handle, ijk_failure))
			&& ijk_istrue(CloseHandle(*thread->handle));
#else	// !WINDOWS
		result = ijk_issuccess(pthread_kill(*(pthread_t*)thread->handle, SIGKILL));
#endif	// WINDOWS

		// success
		if (result)
		{
			thread->sysID = 0;
			*thread->handle = 0;
			return ijk_success;
		}

		// failure
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkThreadCheckActive(ijkThread const* const thread)
{
	if (thread &&
		*thread->handle)
	{
#if (__ijk_cfg_platform == WINDOWS)
		dword result;
		GetExitCodeThread(*thread->handle, &result);
		if (result == STILL_ACTIVE)
			return ijk_true;
#else	// !WINDOWS
		// check if "not complete" flag is set non-complete
#endif	// WINDOWS

			// inactive
		return ijk_false;
	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------

dword ijkThreadInternalGetSysID()
{
#if (__ijk_cfg_platform == WINDOWS)
	return GetCurrentThreadId();
#else	// !WINDOWS
	return gettid();
#endif	// WINDOWS
}


//-----------------------------------------------------------------------------
