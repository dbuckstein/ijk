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

	ijkConsole.c
	Console management source.
*/

#include "ijk/ijk/ijk-config.h"
#if (__ijk_cfg_platform == WINDOWS)

#include "ijk/ijk-platform/ijk-app/ijkConsole.h"
#include <stdio.h>

// 'printf' equivalent for 'stderr'
#define eprintf(format, ...)	fprintf(stderr, format, __VA_ARGS__)
#define cin(format, ...)		fscanf(stdin, format, __VA_ARGS__)
#define cout(format, ...)		printf(stdout, format, __VA_ARGS__)
#define cerr(format, ...)		eprintf(format, __VA_ARGS__)


iret ijkConsoleCreate(ijkConsole* const console_out, ibool const input, ibool const output, ibool const error)
{
	if (console_out &&
		!*console_out->handle)
	{

		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkConsoleCreateMain(ibool const input, ibool const output, ibool const error)
{
	//if (1)
	{

		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkConsoleRelease(ijkConsole* const console)
{
	if (console &&
		*console->handle)
	{

		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkConsoleReleaseMain()
{
	//if (1)
	{

		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkConsoleActivate(ijkConsole const* const console)
{
	if (console &&
		*console->handle)
	{

		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkConsoleDeactive()
{
	//if (1)
	{

		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


#endif	// WINDOWS