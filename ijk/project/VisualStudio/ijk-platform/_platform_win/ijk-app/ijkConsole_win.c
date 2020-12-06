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

// redirect standard handles to console
ijk_inl void ijkConsoleInternalRedirect()
{
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
}

// hard reset of standard handles
ijk_inl void ijkConsoleInternalReset()
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
	i32 i = -1;
	if (console)
	{
		// if console exists
		kptr const handle = GetConsoleWindow();
		if ((console->handle[3] == handle) && handle)
		{
			// flush and clear all stream buffers
			_flushall();

			// redirect input
			i = 0;
			if (redirectInput && !console->handle[0])
			{

			}
			else if (console->handle[0])
			{

			}

			// redirect output
			i = 1;
			if (redirectOutput && !console->handle[i])
			{
				if (GetStdHandle(STD_OUTPUT_HANDLE) != INVALID_HANDLE_VALUE)
				{
					// copy handle to stdout
					console->io[i] = _dup(i);
					console->handle[i] = fopen("CONOUT$", "w");
					if (console->handle[i])
					{
						// enable streaming
						setvbuf(console->handle[i], NULL, _IONBF, 0);

						// route stdout to console
						fprintf(stdout, "\n STDOUT =/= DEFAULT \n");
						fflush(stdout);
						if (_dup2(_fileno(console->handle[i]), i) >= 0)
						{
							fprintf(stdout, "\n STDOUT == CONSOLE \n");
						}
					}
				}
			}
			else if (console->handle[i])
			{
				// finish stdout buffer and close file
				fprintf(stdout, "\n STDOUT =/= CONSOLE \n");
				fflush(stdout);
				fclose(console->handle[i]);
				console->handle[i] = 0;

				// reassign stdout to original
				if (_dup2(console->io[i], i) >= 0)
				{
					console->io[i] = -1;
					fprintf(stdout, "\n STDOUT == DEFAULT \n");
				}
			}

			// redirect error
			i = 2;
			if (redirectError && !console->handle[i])
			{

			}
			else if (console->handle[i])
			{

			}

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
			ijkConsoleRedirectMain(console, 0, 0, 0);

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