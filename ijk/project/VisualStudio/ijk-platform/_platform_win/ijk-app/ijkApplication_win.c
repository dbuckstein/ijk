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

#include "ijk/ijk/ijk-config.h"
#if (__ijk_cfg_platform == WINDOWS)

#include "ijk/ijk-platform/ijk-app/ijkApplication.h"

#include <Windows.h>


//-----------------------------------------------------------------------------

iret ijkApplicationStartSingleInstanceSwitchExisting(tag const windowName)
{
	if (windowName && *windowName)
	{
		// find existing instance
		HWND const existing = FindWindowA(0, windowName);
		if (existing)
		{
			// set foreground window to existing
			if (SetForegroundWindow(existing))
			{
				return ijk_warn_application_exist;
			}
			return ijk_fail_operationfail;
		}
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


iret ijkApplicationStartSingleInstance(ptr* const handle_out, tag const instanceName)
{
	if (handle_out && instanceName && !*handle_out && *instanceName)
	{
		// create mutex handle
		*handle_out = CreateMutexA(0, 0, instanceName);
		if (*handle_out)
		{
			// check if instance exists
			if (*handle_out && GetLastError() == ERROR_ALREADY_EXISTS)
			{
				CloseHandle(*handle_out);
				*handle_out = 0;
				return ijk_warn_application_exist;
			}
			return ijk_success;
		}
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkApplicationStartMultipleInstance(ptr* const handle_out, tag const instanceName, ui32 const limit)
{
	if (handle_out && instanceName && !*handle_out && *instanceName && limit)
	{
		// create semaphore handle
		*handle_out = CreateSemaphoreA(0, limit, limit, instanceName);
		if (*handle_out)
		{
			// check if waited too long for new instance
			if (*handle_out && WaitForSingleObject(*handle_out, 0) == WAIT_TIMEOUT)
			{
				CloseHandle(*handle_out);
				*handle_out = 0;
				return ijk_warn_application_exist;
			}
			return ijk_success;
		}
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkApplicationStopSingleInstance(ptr* const handle)
{
	if (handle && *handle)
	{
		// release and close mutex
		if (ReleaseMutex(*handle))
		{
			CloseHandle(*handle);
			*handle = 0;
			return ijk_success;
		}
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkApplicationStopMultipleInstance(ptr* const handle)
{
	if (handle && *handle)
	{
		// release and close semaphore
		if (ReleaseSemaphore(*handle, 1, 0))
		{
			CloseHandle(*handle);
			*handle = 0;
			return ijk_success;
		}
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------


#endif	// WINDOWS