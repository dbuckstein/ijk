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


//-----------------------------------------------------------------------------

iret ijkApplicationStartSingleInstanceSwitchExisting(tag const windowClassName, tag const windowName)
{
	if (windowClassName && windowName && *windowClassName && *windowName)
	{

		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkApplicationStartSingleInstance(ptr* const handle_out, tag const instanceName)
{
	if (handle_out && instanceName && !*handle_out && *instanceName)
	{

		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkApplicationStartMultipleInstance(ptr* const handle_out, tag const instanceName, ui32 const limit)
{
	if (handle_out && instanceName && !*handle_out && *instanceName && limit)
	{

		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkApplicationStopSingleInstance(ptr* const handle)
{
	if (handle && *handle)
	{

		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkApplicationStopMultipleInstance(ptr* const handle)
{
	if (handle && *handle)
	{

		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------


#endif	// WINDOWS