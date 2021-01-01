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

	ijk-platform.c
	Default source for platform library.
*/

#include "ijk/ijk-platform/ijk-platform.h"

#include <stdio.h>
#include <stdlib.h>

void ijkPlatformTestConsole()
{
	i32 i = -1;
	ijkConsole console[1] = { 0 };

	fprintf(stdout, "STDOUT INIT \n");
	fprintf(stderr, "STDERR INIT \n");

	while (i)
	{
		// create console
		if (ijk_isnfailure(ijkConsoleCreateMain(console)))
		{
			fprintf(stdout, "STDOUT CREATED \n");
			fprintf(stderr, "STDERR CREATED \n");
		}

		// release and create again
		system("pause");
		if (ijk_isnfailure(ijkConsoleReleaseMain(console)))
		{
			fprintf(stdout, "STDOUT RELEASED \n");
			fprintf(stderr, "STDERR RELEASED \n");
		}
		if (ijk_isnfailure(ijkConsoleCreateMain(console)))
		{
			fprintf(stdout, "STDOUT CREATED \n");
			fprintf(stderr, "STDERR CREATED \n");
		}

		// redirect to default and back to console
		system("pause");
		if (ijk_isnfailure(ijkConsoleRedirectMain(console, 0, 0, 0)))
		{
			fprintf(stdout, "STDOUT RESET \n");
			fprintf(stderr, "STDERR RESET \n");
		}
		if (ijk_isnfailure(ijkConsoleRedirectMain(console, 1, 1, 1)))
		{
			fprintf(stdout, "STDOUT REDIRECTED \n");
			fprintf(stderr, "STDERR REDIRECTED \n");
		}

		// redirect and back again
		system("pause");
		if (ijk_isnfailure(ijkConsoleRedirectMain(console, 0, 0, 0)))
		{
			fprintf(stdout, "STDOUT RESET \n");
			fprintf(stderr, "STDERR RESET \n");
		}
		if (ijk_isnfailure(ijkConsoleRedirectMain(console, 1, 1, 1)))
		{
			fprintf(stdout, "STDOUT REDIRECTED \n");
			fprintf(stderr, "STDERR REDIRECTED \n");
		}

		// test utilities
		system("pause");
		ijkConsoleToggleCursor(0);
		ijkConsoleDrawTestPatch();
		system("pause");
		ijkConsoleToggleCursor(1);
		ijkConsoleDrawTestPatch();

		// test input to test again
		ijkConsoleResetColor();
		fprintf(stdout, "STDOUT TEST AGAIN? -> ");
		fprintf(stderr, "STDERR TEST AGAIN? -> ");
		fscanf(stdin, "%d", &i);

		// release console
		system("pause");
		if (ijk_isnfailure(ijkConsoleReleaseMain(console)))
		{
			fprintf(stdout, "STDOUT RELEASED \n");
			fprintf(stderr, "STDERR RELEASED \n");
		}
	}

	fprintf(stdout, "STDOUT TERM \n");
	fprintf(stderr, "STDERR TERM \n");
}