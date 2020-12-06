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

#include <io.h>
#include <stdio.h>
#include <Windows.h>

// 'printf' equivalent for 'stderr'
#define eprintf(format, ...)	fprintf(stderr, format, __VA_ARGS__)
#define cin(format, ...)		fscanf(stdin, format, __VA_ARGS__)
#define cout(format, ...)		printf(stdout, format, __VA_ARGS__)
#define cerr(format, ...)		eprintf(format, __VA_ARGS__)


//-----------------------------------------------------------------------------

// redirect with settings
ijk_inl void ijkConsoleInternalRedirectToggle(ijkConsole* const console, ibool const redirectInput, ibool const redirectOutput, ibool const redirectError)
{
	FILE* str = 0;
	i32 i = -1, j = -1;

	// redirect input
	i = 0;
	if (redirectInput && !console->handle[i])
	{
		if (GetStdHandle(STD_INPUT_HANDLE) != INVALID_HANDLE_VALUE)
		{
			// flush buffer, duplicate handle and reopen stream to console
			//j = fprintf(stdin, "\n STDIN =/= DEFAULT \n");
			j = fflush(stdin);
			j = _dup(i);
			str = freopen("CONIN$", "r+", stdin);
			if (str)
			{
				// store values and configure
				console->handle[i] = str;
				console->io[i] = j;
				j = setvbuf(stdin, NULL, _IONBF, 0);
				//j = fprintf(stdin, "\n STDIN == CONSOLE \n");
			}
		}
	}
	else if (console->handle[i])
	{
		if (GetStdHandle(STD_INPUT_HANDLE) != INVALID_HANDLE_VALUE)
		{
			// flush and reopen
			//j = fprintf(stdin, "\n STDIN =/= CONSOLE \n");
			j = fflush(stdin);
			str = freopen("NUL:", "r+", stdin);
			if (str)
			{
				// duplicate handle and reconfigure stream, reset variables
				j = _dup2(console->io[i], i);
				j = setvbuf(stdin, NULL, _IONBF, 0);
				//j = fprintf(stdin, "\n STDIN == DEFAULT \n");
				console->handle[i] = 0;
				console->io[i] = -1;
			}
		}
	}

	// redirect output
	i = 1;
	if (redirectOutput && !console->handle[i])
	{
		if (GetStdHandle(STD_OUTPUT_HANDLE) != INVALID_HANDLE_VALUE)
		{
			// flush buffer, duplicate handle and reopen stream to console
			//j = fprintf(stdout, "\n STDOUT =/= DEFAULT \n");
			j = fflush(stdout);
			j = _dup(i);
			str = freopen("CONOUT$", "a+", stdout);
			if (str)
			{
				// store values and configure
				console->handle[i] = str;
				console->io[i] = j;
				j = setvbuf(stdout, NULL, _IONBF, 0);
				//j = fprintf(stdout, "\n STDOUT == CONSOLE \n");
			}
		}
	}
	else if (console->handle[i])
	{
		if (GetStdHandle(STD_OUTPUT_HANDLE) != INVALID_HANDLE_VALUE)
		{
			// flush and reopen
			//j = fprintf(stdout, "\n STDOUT =/= CONSOLE \n");
			j = fflush(stdout);
			str = freopen("NUL:", "a+", stdout);
			if (str)
			{
				// duplicate handle and reconfigure stream, reset variables
				j = _dup2(console->io[i], i);
				j = setvbuf(stdout, NULL, _IONBF, 0);
				//j = fprintf(stdout, "\n STDOUT == DEFAULT \n");
				console->handle[i] = 0;
				console->io[i] = -1;
			}
		}
	}

	// redirect error
	i = 2;
	if (redirectError && !console->handle[i])
	{
		if (GetStdHandle(STD_ERROR_HANDLE) != INVALID_HANDLE_VALUE)
		{
			// flush buffer, duplicate handle and reopen stream to console
			//j = fprintf(stderr, "\n STDERR =/= DEFAULT \n");
			j = fflush(stderr);
			j = _dup(i);
			str = freopen("CONOUT$", "a+", stderr);
			if (str)
			{
				// store values and configure
				console->handle[i] = str;
				console->io[i] = j;
				j = setvbuf(stderr, NULL, _IONBF, 0);
				//j = fprintf(stderr, "\n STDERR == CONSOLE \n");
			}
		}
	}
	else if (console->handle[i])
	{
		if (GetStdHandle(STD_ERROR_HANDLE) != INVALID_HANDLE_VALUE)
		{
			// flush and reopen
			//j = fprintf(stderr, "\n STDERR =/= CONSOLE \n");
			j = fflush(stderr);
			str = freopen("NUL:", "a+", stderr);
			if (str)
			{
				// duplicate handle and reconfigure stream, reset variables
				j = _dup2(console->io[i], i);
				j = setvbuf(stderr, NULL, _IONBF, 0);
				//j = fprintf(stderr, "\n STDERR == DEFAULT \n");
				console->handle[i] = 0;
				console->io[i] = -1;
			}
		}
	}
}


//-----------------------------------------------------------------------------

iret ijkConsoleCreateMain(ijkConsole* const console)
{
	if (console)
	{
		// if console not already open
		ptr handle = GetConsoleWindow();
		if (!handle && !console->handle[3])
		{
			// allocate and show console
			if (AllocConsole())
			{
				// reset flags
				console->handle[0] = console->handle[1] = console->handle[2] = 0;
				console->io[0] = console->io[1] = console->io[2] = -1;

				// init flag
				console->handle[3] = handle = GetConsoleWindow();

				// disable closing console manually because doing this kills 
				//	the whole application; could also start a new process, 
				//	but then there's also that to manage
				DeleteMenu(GetSystemMenu(handle, FALSE), SC_CLOSE, MF_BYCOMMAND);

				// redirect to new console
				ijkConsoleInternalRedirectToggle(console, 1, 1, 1);

				// done
				return ijk_success;
			}
			return ijk_fail_operationfail;
		}
		return ijk_warn_console_exist;
	}
	return ijk_fail_invalidparams;
}


iret ijkConsoleRedirectMain(ijkConsole* const console, ibool const redirectInput, ibool const redirectOutput, ibool const redirectError)
{
	if (console)
	{
		// if console exists
		kptr const handle = GetConsoleWindow();
		if ((console->handle[3] == handle) && handle)
		{
			// redirect toggle
			ijkConsoleInternalRedirectToggle(console, redirectInput, redirectOutput, redirectError);

			// done
			return ijk_success;
		}
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkConsoleReleaseMain(ijkConsole* const console)
{
	if (console)
	{
		// if console exists
		kptr const handle = GetConsoleWindow();
		if ((console->handle[3] == handle) && handle)
		{
			// reset to original standard i/o
			ijkConsoleInternalRedirectToggle(console, 0, 0, 0);

			// delete console instance
			// console will hide when all standard handles are closed
			if (FreeConsole())
			{
				// reset
				console->handle[3] = 0;

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