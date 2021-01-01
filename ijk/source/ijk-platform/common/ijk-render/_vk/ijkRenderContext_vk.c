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

	ijkRenderContext_vk.c
	Platform-agnostic Vulkan render context management source.
*/

#include "ijk/ijk-platform/ijk-render/ijkRenderContext.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vulkan/vulkan.h"


//-----------------------------------------------------------------------------

// ijkRendererInfo_vk
//	Renderer info for Vulkan render context.
typedef struct ijkRendererInfo_vk_tag
{
	ijkRenderContext const* renderContext;
} ijkRendererInfo_vk;


#define _rc _vk
#define ijkRenderContextCreateRP	ijk_rc_rp(ijkRenderContextCreate)
#define info info_r
#define type ijkRenderer_Vulkan


//-----------------------------------------------------------------------------

iret ijkRenderContextCreate_vk(ijkRenderContext* const renderContext_out, ijkRenderer const renderer)
{
	iret ijkRenderContextCreateRP(ijkRenderContext* const renderContext_out);

	// validate
	if (renderContext_out && renderer == type && !renderContext_out->info)
	{
		// allocate renderer info
		size const sz = szb(ijkRendererInfo_vk);
		ijkRendererInfo_vk* info = (ijkRendererInfo_vk*)malloc(sz);
		if (info)
		{
			// initialize platform info
			memset(info, 0, sz);
			if (ijk_issuccess(ijkRenderContextCreateRP(renderContext_out)))
			{
				// reset
				renderContext_out->info = info;
				info->renderContext = renderContext_out;

				// ****TO-DO: 
				//	-> set platform-agnostic renderer info


				// done
				return ijk_success;
			}
			free(info);
		}
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}

iret ijkRenderContextRelease_vk(ijkRenderContext* const renderContext)
{
	if (renderContext && renderContext->renderer == type && renderContext->info)
	{
		free(renderContext->info_p);
		free(renderContext->info_rp);
		free(renderContext->info_r);
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}

iret ijkRenderContextPrintInfo_vk(ijkRenderContext const* const renderContext, cstr* const bufferPtr)
{
	if (renderContext && renderContext->renderer == type && renderContext->info)
	{
		*bufferPtr += sprintf(*bufferPtr, "Vulkan \n");

		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------
