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

	ijkRenderContext_win_vk.c
	Vulkan render context management source for Windows.
*/

/*
	Download and install Vulkan SDK for current platform: 
		-> https://vulkan.lunarg.com/sdk/home#windows 
		-> Environment variables: VK_SDK_PATH & VULKAN_SDK
*/

#include "ijk/ijk-platform/ijk-render/ijkRenderContext.h"
#if ijk_platform_is(WINDOWS)
#include <Windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VK_USE_PLATFORM_WIN32_KHR
#include "vulkan/vulkan.h"


//-----------------------------------------------------------------------------

// ijkRendererInfo_win_vk
//	Renderer info for Vulkan render context on Windows.
typedef struct ijkRendererInfo_win_vk_tag
{
	ijkRenderContext const* renderContext;
} ijkRendererInfo_win_vk;


//-----------------------------------------------------------------------------

iret ijkRenderContextCreateWINDOWS_vk(ijkRenderContext* const renderContext_out)
{
	//iret ijkRenderContextCreateP(ijkRenderContext* const renderContext_out);

	// validate
	if (renderContext_out && !renderContext_out->rendererInfo_p)
	{
		// allocate platform info
		size const sz = sizeof(ijkRendererInfo_win_vk);
		ijkRendererInfo_win_vk* rendererInfo_p = (ijkRendererInfo_win_vk*)malloc(sz);
		if (rendererInfo_p)
		{
			// initialize platform renderer-agnostic info
			memset(rendererInfo_p, 0, sz);
			//if (ijk_issuccess(ijkRenderContextCreateP(renderContext_out)))
			{
				// reset
				renderContext_out->rendererInfo_p = rendererInfo_p;
				rendererInfo_p->renderContext = renderContext_out;

				// ****TO-DO: 
				//	-> set platform-specific renderer info


				// done
				return ijk_success;
			}
			free(rendererInfo_p);
		}
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------


#endif	// WINDOWS