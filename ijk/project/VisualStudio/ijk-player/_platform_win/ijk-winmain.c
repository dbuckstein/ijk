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

	ijk-winmain.c
	Windows application entry point.
*/

#include "ijk/ijk-platform/ijk-platform.h"

#if (__ijk_cfg_platform == WINDOWS)

//#include <stdio.h>
//#include <stdlib.h>


//-----------------------------------------------------------------------------
// application entry point

iret __stdcall wWinMain(
	kptr const		hInstance,
	kptr const		hPrevInstance,
	kwcstr const	lpCmdLine,
	i32 const		nCmdShow)
{
	ktag appName = "ijk Player Application";
	iret status = -1;
	ptr handle[1] = { 0 };

	//ijkConsole console[1] = { 0 };

	// initialize application instance
	status = ijkApplicationStartSingleInstanceSwitchExisting(appName);
	//i32 i = -1;
	//ui32 const c = 1;
	//status = ijkApplicationStartSingleInstance(handle, appName, &i);
	//ui32 const c = 3;
	//status = ijkApplicationStartMultipleInstance(handle, appName, c, &i);
	if (ijk_issuccess(status))
	{
		// initialize
		//ijkConsoleCreateMain(console);
		//printf("APP INST INDEX: %d / %d \n", i, c);
		//system("pause");

		// terminate application instance
		//status = ijkApplicationStopSingleInstance(handle, &i);
		//status = ijkApplicationStopMultipleInstance(handle, &i);
		if (ijk_issuccess(status))
		{
			// terminate
			//printf("APP INST REMAIN: %d / %d \n", i, c);
			//system("pause");
			//ijkConsoleReleaseMain(console);

			// done
			status = ijk_success;
		}
	}

	// the end
	return status;
}


//-----------------------------------------------------------------------------


#endif  // WINDOWS