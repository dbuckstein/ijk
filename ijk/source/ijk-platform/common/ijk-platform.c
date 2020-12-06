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

	ijk-platform.c
	Default source for platform library.
*/

#include "ijk/ijk-platform/ijk-platform.h"

#include <stdio.h>

void ijkPlatformTestConsole()
{
#if (__ijk_cfg_platform == WINDOWS)
	i16 GetAsyncKeyState(i32 key);
	i32 i = -1;

	ijkConsole console[1] = { 0 };

	// quit function with escape key
	while (!GetAsyncKeyState(27))
	{
		// press '0' to release console
		if (GetAsyncKeyState(48))
		{
			if (ijk_isnfailure(ijkConsoleReleaseMain(console)))
			{

			}
		}
		// press '1' to create console
		else if (GetAsyncKeyState(49))
		{
			if (ijk_isnfailure(ijkConsoleCreateMain(console)))
			{
				ijkConsoleRedirectMain(console, 1, 1, 1);
			}
		}
		// press '2' to test stdin
		else if (GetAsyncKeyState(50))
		{
			//fscanf(stdin, "%d", &i);
		}
		// press '3' to test stdout
		else if (GetAsyncKeyState(51))
		{
			//fprintf(stdout, "  %d %d  ", 3, i);
		}
		// press '4' to test stderr
		else if (GetAsyncKeyState(52))
		{
			//fprintf(stderr, "  %d %d  ", 4, i);
		}
	}
#endif	// WINDOWS
}