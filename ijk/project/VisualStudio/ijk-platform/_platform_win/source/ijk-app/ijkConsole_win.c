/*
   Copyright 2020-2021 Daniel S. Buckstein

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

	ijkConsole_win.c
	Console management source for Windows.
*/

#include "ijk/ijk-platform/ijk-app/ijkConsole.h"
#if ijk_platform_is(WINDOWS)

#include <io.h>
#include <stdio.h>
#include <Windows.h>


//-----------------------------------------------------------------------------

// redirect with settings
ijk_inl void ijkConsoleInternalRedirectToggle(ijkConsole* const console, bool const redirectInput, bool const redirectOutput, bool const redirectError)
{
	FILE* str = 0;
	i32 i = -1, j = -1;

	// redirect input
	i = 0;
	if (redirectInput)
	{
		if (GetStdHandle(STD_INPUT_HANDLE) != INVALID_HANDLE_VALUE && !console->handle[i])
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
	else
	{
		if (GetStdHandle(STD_INPUT_HANDLE) != INVALID_HANDLE_VALUE && console->handle[i])
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
	if (redirectOutput)
	{
		if (GetStdHandle(STD_OUTPUT_HANDLE) != INVALID_HANDLE_VALUE && !console->handle[i])
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
	else
	{
		if (GetStdHandle(STD_OUTPUT_HANDLE) != INVALID_HANDLE_VALUE && console->handle[i])
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
	if (redirectError)
	{
		if (GetStdHandle(STD_ERROR_HANDLE) != INVALID_HANDLE_VALUE && !console->handle[i])
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
	else
	{
		if (GetStdHandle(STD_ERROR_HANDLE) != INVALID_HANDLE_VALUE && console->handle[i])
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

				// redirect to new console (in/out, not err)
				ijkConsoleInternalRedirectToggle(console, 1, 1, 0);

				// done
				return ijk_success;
			}
			return ijk_fail_operationfail;
		}
		return ijk_warn_console_exist;
	}
	return ijk_fail_invalidparams;
}


iret ijkConsoleRedirectMain(ijkConsole* const console, bool const redirectInput, bool const redirectOutput, bool const redirectError)
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

iret ijkConsoleGetCursor(i16* const x_out, i16* const y_out)
{
	if (x_out && y_out)
	{
		CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo[1];
		HANDLE const stdHandle = GetStdHandle(STD_OUTPUT_HANDLE), console = GetConsoleWindow();
		if (stdHandle && console &&
			GetConsoleScreenBufferInfo(stdHandle, screenBufferInfo))
		{
			*x_out = screenBufferInfo->dwCursorPosition.X;
			*y_out = screenBufferInfo->dwCursorPosition.Y;
			return ijk_success;
		}
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkConsoleSetCursor(i16 const x, i16 const y)
{
	COORD const pos = { x, y };
	HANDLE const stdHandle = GetStdHandle(STD_OUTPUT_HANDLE), console = GetConsoleWindow();
	if (stdHandle && console &&
		SetConsoleCursorPosition(stdHandle, pos))
	{
		return ijk_success;
	}
	return ijk_fail_operationfail;
}


iret ijkConsoleToggleCursor(bool const visible)
{
	CONSOLE_CURSOR_INFO cursorInfo[1];
	HANDLE const stdHandle = GetStdHandle(STD_OUTPUT_HANDLE), console = GetConsoleWindow();
	if (stdHandle && console &&
		GetConsoleCursorInfo(stdHandle, cursorInfo))
	{
		cursorInfo->bVisible = visible;
		if (SetConsoleCursorInfo(stdHandle, cursorInfo))
		{
			return ijk_success;
		}
	}
	return ijk_fail_operationfail;
}


iret ijkConsoleGetColor(ijkConsoleColor* const fg_out, ijkConsoleColor* const bg_out)
{
	if (fg_out && bg_out)
	{
		CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo[1];
		HANDLE const stdHandle = GetStdHandle(STD_OUTPUT_HANDLE), console = GetConsoleWindow();
		if (stdHandle && console &&
			GetConsoleScreenBufferInfo(stdHandle, screenBufferInfo))
		{
			*fg_out = (ijkConsoleColor)(screenBufferInfo->wAttributes & 0xf);
			*bg_out = (ijkConsoleColor)(screenBufferInfo->wAttributes >> 4 & 0xf);
			return ijk_success;
		}
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkConsoleSetColor(ijkConsoleColor const fg, ijkConsoleColor const bg)
{
	HANDLE const stdHandle = GetStdHandle(STD_OUTPUT_HANDLE), console = GetConsoleWindow();
	if (stdHandle && console &&
		SetConsoleTextAttribute(stdHandle, (i16)(fg | bg << 4)))
	{
		return ijk_success;
	}
	return ijk_fail_operationfail;
}


iret ijkConsoleResetColor()
{
	return ijkConsoleSetColor(ijkConsoleColor_white, ijkConsoleColor_black);
}


iret ijkConsoleGetCursorColor(i16* const x_out, i16* const y_out, ijkConsoleColor* const fg_out, ijkConsoleColor* const bg_out)
{
	if (x_out && y_out && fg_out && bg_out)
	{
		CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo[1];
		HANDLE const stdHandle = GetStdHandle(STD_OUTPUT_HANDLE), console = GetConsoleWindow();
		if (stdHandle && console &&
			GetConsoleScreenBufferInfo(stdHandle, screenBufferInfo))
		{
			*x_out = screenBufferInfo->dwCursorPosition.X;
			*y_out = screenBufferInfo->dwCursorPosition.Y;
			*fg_out = (ijkConsoleColor)(screenBufferInfo->wAttributes & 0xf);
			*bg_out = (ijkConsoleColor)(screenBufferInfo->wAttributes >> 4 & 0xf);
			return ijk_success;
		}
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkConsoleSetCursorColor(i16 const x, i16 const y, ijkConsoleColor const fg, ijkConsoleColor const bg)
{
	COORD const pos = { x, y };
	HANDLE const stdHandle = GetStdHandle(STD_OUTPUT_HANDLE), console = GetConsoleWindow();
	if (stdHandle && console &&
		SetConsoleCursorPosition(stdHandle, pos) &&
		SetConsoleTextAttribute(stdHandle, (i16)(fg | bg << 4)))
	{
		return ijk_success;
	}
	return ijk_fail_operationfail;
}


iret ijkConsoleDrawTestPatch()
{
	HANDLE const stdHandle = GetStdHandle(STD_OUTPUT_HANDLE), console = GetConsoleWindow();
	if (stdHandle && console)
	{
		// test all colors and shifts
		i16 x, y;
		ijkConsoleColor fg, bg;
		for (y = 0; y < 16; ++y)
		{
			for (x = 0; x < 16; ++x)
			{
				fg = (ijkConsoleColor)y;
				bg = (ijkConsoleColor)x;
				ijkConsoleSetColor(fg, bg);
				ijkConsoleSetCursor(x * 2, y);
				printf("%x", (i32)x);
				ijkConsoleSetCursorColor(x * 2 + 1, y, fg, bg);
				printf("%x", (i32)y);
			}
		}
		ijkConsoleGetCursor(&x, &y);
		ijkConsoleGetColor(&fg, &bg);
		ijkConsoleGetCursorColor(&x, &y, &fg, &bg);
		ijkConsoleResetColor();
		printf("[]=(%d, %d) \n", (i32)x, (i32)y);

		// done
		return ijk_success;
	}
	return ijk_fail_operationfail;
}


iret ijkConsoleClear()
{
	// help to avoid using system("cls"): https://docs.microsoft.com/en-us/windows/console/clearing-the-screen 
	HANDLE const stdHandle = GetStdHandle(STD_OUTPUT_HANDLE), console = GetConsoleWindow();
	if (stdHandle && console)
	{
		// simple clear
		//system("cls");

		CONSOLE_SCREEN_BUFFER_INFO buffer[1];
		if (GetConsoleScreenBufferInfo(stdHandle, buffer))
		{
			COORD const coord = { 0, 0 };
			dword const sz = (buffer->dwSize.X * buffer->dwSize.Y);
			dword write[1] = { 0 };
			if (FillConsoleOutputCharacterA(stdHandle, ' ', sz, coord, write) &&
				GetConsoleScreenBufferInfo(stdHandle, buffer) &&
				FillConsoleOutputAttribute(stdHandle, buffer->wAttributes, sz, coord, write) &&
				SetConsoleCursorPosition(stdHandle, coord))
			{
				// done
				return ijk_success;
			}
		}
	}
	return ijk_fail_operationfail;
}


//-----------------------------------------------------------------------------

iret ijkConsolePrintDebug(kstr const format, ...)
{
	if (format)
	{
		byte str[256] = { 0 };
		va_list args = 0;
		iret result = 0;

		// fill buffer with formatted arguments
		va_start(args, format);
		result = _vsnprintf(str, sizeof(str), format, args);
		va_end(args);

		// internal print
		OutputDebugStringA(str);

		// return length
		return result;
	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------


#endif	// WINDOWS