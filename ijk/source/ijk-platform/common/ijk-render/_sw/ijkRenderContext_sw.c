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

	ijkRenderContext_sw.c
	Platform-agnostic software renderer.
*/

#include "ijk/ijk-platform/ijk-render/ijkRenderContext.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//-----------------------------------------------------------------------------

// ijkRendererInfo_sw
//	Renderer info for software renderer.
typedef struct ijkRendererInfo_sw
{
	ijkRenderContext const* renderContext;
} ijkRendererInfo_sw;


#define _rc _sw
#define ijkRenderContextCreateRP	ijk_rc_rp(ijkRenderContextCreate)


//-----------------------------------------------------------------------------

iret ijkRenderContextCreate_sw(ijkRenderContext* const renderContext_out, ijkRenderer const renderer)
{
	iret ijkRenderContextCreateRP(ijkRenderContext* const renderContext_out);

	// validate
	if (renderContext_out && renderer == ijkRenderer_software && !renderContext_out->rendererInfo)
	{
		// allocate renderer info
		size const sz = sizeof(ijkRendererInfo_sw);
		ijkRendererInfo_sw* rendererInfo = (ijkRendererInfo_sw*)malloc(sz);
		if (rendererInfo)
		{
			// initialize platform info
			memset(rendererInfo, 0, sz);
			if (ijk_issuccess(ijkRenderContextCreateRP(renderContext_out)))
			{
				// reset
				renderContext_out->rendererInfo = rendererInfo;
				rendererInfo->renderContext = renderContext_out;

				// ****TO-DO: 
				//	-> set platform-agnostic renderer info


				// done
				return ijk_success;
			}
			free(rendererInfo);
		}
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}

iret ijkRenderContextRelease_sw(ijkRenderContext* const renderContext)
{
	if (renderContext && renderContext->renderer == ijkRenderer_software && renderContext->rendererInfo)
	{
		// ****TO-DO: 
		//	-> renderer-specific cleanup


		free(renderContext->rendererInfo_p);
		free(renderContext->rendererInfo);
		renderContext->rendererInfo = renderContext->rendererInfo_p = 0;
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}

iret ijkRenderContextPrintInfo_sw(ijkRenderContext const* const renderContext, str* const bufferPtr)
{
	if (renderContext && renderContext->renderer == ijkRenderer_software && renderContext->rendererInfo)
	{
		*bufferPtr += sprintf(*bufferPtr, "Software \n");

		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------
