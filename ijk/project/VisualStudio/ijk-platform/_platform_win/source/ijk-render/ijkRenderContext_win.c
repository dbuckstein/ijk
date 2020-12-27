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

	ijkRenderContext_win.c
	Renderer-agnostic render context management source for Windows.
*/

#include "ijk/ijk-platform/ijk-render/ijkRenderContext.h"
#if ijk_platform_is(WINDOWS)
#include <Windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//-----------------------------------------------------------------------------

// ijkRendererInfo_win
//	Renderer info for render context on Windows platform.
typedef struct ijkRendererInfo_win_tag
{
	ijkRenderContext const* renderContext;
} ijkRendererInfo_win;


#define info info_p


//-----------------------------------------------------------------------------

iret ijkRenderContextCreateWINDOWS(ijkRenderContext* const renderContext_out)
{
	if (renderContext_out->info == 0)
	{
		// allocate platform info
		size const sz = szb(ijkRendererInfo_win);
		ijkRendererInfo_win* info = (ijkRendererInfo_win*)malloc(sz);
		if (info)
		{
			// reset
			memset(info, 0, sz);
			renderContext_out->info = info;
			info->renderContext = renderContext_out;

			// ****TO-DO: 
			//	-> set platform-specific renderer info


			// done
			return ijk_success;
		}
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------


#endif	// WINDOWS