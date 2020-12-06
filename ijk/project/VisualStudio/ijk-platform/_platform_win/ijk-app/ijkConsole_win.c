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
#include <Windows.h>

// 'printf' equivalent for 'stderr'
#define eprintf(format, ...)	fprintf(stderr, format, __VA_ARGS__)
#define cin(format, ...)		fscanf(stdin, format, __VA_ARGS__)
#define cout(format, ...)		printf(stdout, format, __VA_ARGS__)
#define cerr(format, ...)		eprintf(format, __VA_ARGS__)


//-----------------------------------------------------------------------------

iret ijkConsoleCreateMain(ijkConsole* const console)
{
	if (console)
	{
		// if console not already open
		if (!GetConsoleWindow())
		{
			// allocate and show console
			if (AllocConsole())
			{
				// disable closing console manually because doing this kills 
				//	the whole application; could also start a new process, 
				//	but then there's also that to manage
				DeleteMenu(GetSystemMenu(GetConsoleWindow(), FALSE), SC_CLOSE, MF_BYCOMMAND);

				// set up stdin
				if (GetStdHandle(STD_INPUT_HANDLE) != INVALID_HANDLE_VALUE)
					if (freopen("CONIN$", "r", stdin) == 0)
						setvbuf(stdin, NULL, _IONBF, 0);

				// set up stdout
				if (GetStdHandle(STD_OUTPUT_HANDLE) != INVALID_HANDLE_VALUE)
					if (freopen("CONOUT$", "w", stdout) == 0)
						setvbuf(stdout, NULL, _IONBF, 0);

				// set up stderr
				if (GetStdHandle(STD_ERROR_HANDLE) != INVALID_HANDLE_VALUE)
					if (freopen("CONOUT$", "w", stderr) == 0)
						setvbuf(stderr, NULL, _IONBF, 0);

				// done
				return ijk_success;
			}
			return ijk_fail_operationfail;
		}
		return ijk_warn_console_exist;
	}
	return ijk_fail_invalidparams;
}


iret ijkConsoleReleaseMain(ijkConsole* const console)
{
	if (console)
	{
		// if console exists
		if (GetConsoleWindow())
		{
			// delete console instance
			// console will hide when all standard handles are closed
			if (FreeConsole())
			{
				// redirect stdin
				if (GetStdHandle(STD_INPUT_HANDLE) != INVALID_HANDLE_VALUE)
					if (freopen("NUL:", "r", stdin) == 0)
						setvbuf(stdin, NULL, _IONBF, 0);

				// redirect stdout
				if (GetStdHandle(STD_OUTPUT_HANDLE) != INVALID_HANDLE_VALUE)
					if (freopen("NUL:", "w", stdout) == 0)
						setvbuf(stdout, NULL, _IONBF, 0);

				// redirect stderr
				if (GetStdHandle(STD_ERROR_HANDLE) != INVALID_HANDLE_VALUE)
					if (freopen("NUL:", "w", stderr) == 0)
						setvbuf(stderr, NULL, _IONBF, 0);

				// done
				return ijk_success;
			}
			return ijk_fail_operationfail;
		}
		return ijk_warn_console_exist;
	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------


#endif	// WINDOWS