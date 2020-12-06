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
#include <stdlib.h>

void ijkPlatformTestConsole()
{
#if (__ijk_cfg_platform == WINDOWS)
	i32 i = -1;
	ijkConsole console[1] = { 0 };

	fprintf(stdout, "\n STDOUT INIT \n");
	fprintf(stderr, "\n STDERR INIT \n");

	if (ijk_isnfailure(ijkConsoleCreateMain(console)))
	{
		fprintf(stdout, "\n STDOUT CREATED \n");
		fprintf(stderr, "\n STDERR CREATED \n");
	}

	system("pause");
	if (ijk_isnfailure(ijkConsoleReleaseMain(console)))
	{
		fprintf(stdout, "\n STDOUT RELEASED \n");
		fprintf(stderr, "\n STDERR RELEASED \n");
	}
	if (ijk_isnfailure(ijkConsoleCreateMain(console)))
	{
		fprintf(stdout, "\n STDOUT CREATED \n");
		fprintf(stderr, "\n STDERR CREATED \n");
	}

	system("pause");
	if (ijk_isnfailure(ijkConsoleRedirectMain(console, 0, 0, 0)))
	{
		fprintf(stdout, "\n STDOUT RESET \n");
		fprintf(stderr, "\n STDERR RESET \n");
	}
	if (ijk_isnfailure(ijkConsoleRedirectMain(console, 1, 1, 1)))
	{
		fprintf(stdout, "\n STDOUT REDIRECTED \n");
		fprintf(stderr, "\n STDERR REDIRECTED \n");
	}

	system("pause");
	if (ijk_isnfailure(ijkConsoleRedirectMain(console, 0, 0, 0)))
	{
		fprintf(stdout, "\n STDOUT RESET \n");
		fprintf(stderr, "\n STDERR RESET \n");
	}
	if (ijk_isnfailure(ijkConsoleRedirectMain(console, 1, 1, 1)))
	{
		fprintf(stdout, "\n STDOUT REDIRECTED \n");
		fprintf(stderr, "\n STDERR REDIRECTED \n");
	}

	system("pause");
	if (ijk_isnfailure(ijkConsoleReleaseMain(console)))
	{
		fprintf(stdout, "\n STDOUT RELEASED \n");
		fprintf(stderr, "\n STDERR RELEASED \n");
	}

	fprintf(stdout, "\n STDOUT TERM \n");
	fprintf(stderr, "\n STDERR TERM \n");
#endif	// WINDOWS
}