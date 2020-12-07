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

	ijkApplication.c
	Application management source.
*/

#include "ijk/ijk-platform/ijk-app/ijkApplication.h"
#if (ijk_platform_is(WINDOWS))

#include <Windows.h>


//-----------------------------------------------------------------------------

iret ijkApplicationStartSingleInstance(ptr* const handle_out, tag const instanceName, i32* const index_out_opt)
{
	if (index_out_opt)
		*index_out_opt = -1;
	if (handle_out && instanceName && !*handle_out && *instanceName)
	{
		// create mutex handle
		ptr const handle = CreateMutexA(0, TRUE, instanceName);
		if (handle)
		{
			// check if instance exists
			dword status = GetLastError();
			if (status == ERROR_ALREADY_EXISTS)
			{
				// current index is limit (1)
				if (index_out_opt)
					*index_out_opt = 1;

				// attempt close handle
				status = CloseHandle(handle);
				return ijk_warn_application_exist;
			}

			// set index
			if (index_out_opt)
				*index_out_opt = 0;

			// done
			*handle_out = handle;
			return ijk_success;
		}
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkApplicationStartSingleInstanceSwitch(ptr* const handle_out, tag const instanceName, i32* const index_out_opt)
{
	iret status = ijkApplicationStartSingleInstance(handle_out, instanceName, index_out_opt);
	if (status == ijk_warn_application_exist)
	{
		HWND const existing = FindWindowA(0, instanceName);
		if (SetForegroundWindow(existing))
		{
			// switched to existing window
			// nothing more to do
		}
		else
		{
			// cannot switch to existing window
			// append warning
			status |= ijk_warn_application_no_window;
		}
	}
	return status;
}


iret ijkApplicationStartMultipleInstance(ptr* const handle_out, tag const instanceName, ui32 const limit, i32* const index_out_opt)
{
	if (index_out_opt)
		*index_out_opt = -1;
	if (handle_out && instanceName && !*handle_out && *instanceName && limit)
	{
		// create semaphore handle, max count (signaled)
		ptr const handle = CreateSemaphoreA(0, limit, limit, instanceName);
		if (handle)
		{
			dword status = GetLastError();
			
			// get signal state, decrements count
			dword signal = WaitForSingleObject(handle, 0);

			// semaphore has positive count (signaled)
			if (signal == WAIT_OBJECT_0)
			{
				if (index_out_opt)
				{
					// to get current count, force semaphor change then undo
					signal = WaitForSingleObject(handle, 0);
					if (signal == WAIT_OBJECT_0)
					{
						// there are more instances available, revert and capture count
						// index will be two less than what we want relative to limit 
						//	because we have done two 'wait' operations
						status = ReleaseSemaphore(handle, 1, index_out_opt);
						*index_out_opt = limit - (*index_out_opt + 2);
					}
					else if (signal == WAIT_TIMEOUT)
					{
						// this is the last available instance
						// index is one less than count
						*index_out_opt = limit - 1;
					}
				}

				// done
				*handle_out = handle;
				return ijk_success;
			}
			// check if waited too long for new instance
			// this happens if count is zero (non-signaled) and timeout occurs
			else if (signal == WAIT_TIMEOUT)
			{
				// current index is limit because a new instance should not start
				if (index_out_opt)
					*index_out_opt = limit;

				//status == ERROR_ALREADY_EXISTS
				// attempt close handle
				status = CloseHandle(handle);
				return ijk_warn_application_exist;
			}

			// error
			status = CloseHandle(handle);
			return ijk_fail_operationfail;
		}
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkApplicationStopSingleInstance(ptr* const handle, ui32* const available_out_opt)
{
	if (available_out_opt)
		*available_out_opt = 0;
	if (handle && *handle)
	{
		// release and close mutex
		if (ReleaseMutex(*handle) && CloseHandle(*handle))
		{
			// update count
			if (available_out_opt)
				++(*available_out_opt);

			// done
			*handle = 0;
			return ijk_success;
		}
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkApplicationStopMultipleInstance(ptr* const handle, ui32* const available_out_opt)
{
	if (available_out_opt)
		*available_out_opt = 0;
	if (handle && *handle)
	{
		// release and close semaphore, increasing count by 1 (signaled)
		if (ReleaseSemaphore(*handle, 1, available_out_opt) && CloseHandle(*handle))
		{
			// update count
			if (available_out_opt)
				++(*available_out_opt);

			// done
			*handle = 0;
			return ijk_success;
		}
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------


#endif	// WINDOWS