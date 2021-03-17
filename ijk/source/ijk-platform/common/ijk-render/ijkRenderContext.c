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

	ijkRenderContext.c
	Platform-agnostic and renderer-agnostic render context management source.
*/

#include "ijk/ijk-platform/ijk-render/ijkRenderContext.h"


//-----------------------------------------------------------------------------

iret ijkRenderContextCreate(ijkRenderContext* const renderContext_out, ijkRenderer const renderer)
{
	// declare render context initializers
	iret ijkRenderContextCreate_vk(ijkRenderContext* const renderContext_out, ijkRenderer const renderer);
	iret ijkRenderContextCreate_gl(ijkRenderContext* const renderContext_out, ijkRenderer const renderer);

	// validate
	if (renderContext_out && !renderContext_out->renderer && renderer)
	{
		iret status = ijk_fail_renderer_unsupported;

		// call correct function
		switch (renderer)
		{
		case ijkRenderer_Vulkan:
			status = ijkRenderContextCreate_vk(renderContext_out, renderer);
			break;
		case ijkRenderer_OpenGL:
			status = ijkRenderContextCreate_gl(renderContext_out, renderer);
			break;
		case ijkRenderer_Direct3D:
			break;
		case ijkRenderer_Metal:
			break;
		}

		// set
		if (ijk_issuccess(status))
		{
			renderContext_out->renderer = renderer;
		}
		return status;
	}
	return ijk_fail_invalidparams;
}


iret ijkRenderContextRelease(ijkRenderContext* const renderContext)
{
	iret ijkRenderContextRelease_vk(ijkRenderContext* const renderContext);
	iret ijkRenderContextRelease_gl(ijkRenderContext* const renderContext);

	// validate
	if (renderContext && renderContext->renderer)
	{
		iret status = ijk_fail_operationfail;

		// call correct function
		switch (renderContext->renderer)
		{
		case ijkRenderer_Vulkan:
			status = ijkRenderContextRelease_vk(renderContext);
			break;
		case ijkRenderer_OpenGL:
			status = ijkRenderContextRelease_gl(renderContext);
			break;
		case ijkRenderer_Direct3D:
			break;
		case ijkRenderer_Metal:
			break;
		}

		// reset
		if (ijk_issuccess(status))
		{
			renderContext->renderer = ijkRenderer_none;
			renderContext->rendererInfo = renderContext->rendererInfo_p = 0;
		}
		return status;
	}
	return ijk_fail_invalidparams;
}


iret ijkRenderContextActivate(ijkRenderContext const* const renderContext)
{
	if (renderContext && renderContext->renderer)
	{

		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkRenderContextDeactivate(ijkRenderContext const* const renderContext)
{
	if (renderContext && renderContext->renderer)
	{

		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkRenderContextLink(ijkRenderContext const* const renderContext0, ijkRenderContext const* const renderContext1)
{
	if (renderContext0 && renderContext1 && renderContext0->renderer && renderContext0->renderer == renderContext1->renderer)
	{

		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkRenderContextPrintInfo(ijkRenderContext const* const renderContext, str* const bufferPtr)
{
	iret ijkRenderContextPrintInfo_vk(ijkRenderContext const* const renderContext, str* const bufferPtr);
	iret ijkRenderContextPrintInfo_gl(ijkRenderContext const* const renderContext, str* const bufferPtr);

	// validate
	if (renderContext && renderContext->renderer && bufferPtr && *bufferPtr)
	{
		switch (renderContext->renderer)
		{
		case ijkRenderer_Vulkan:
			return ijkRenderContextPrintInfo_vk(renderContext, bufferPtr);
		case ijkRenderer_OpenGL:
			return ijkRenderContextPrintInfo_gl(renderContext, bufferPtr);
		case ijkRenderer_Direct3D:
			break;
		case ijkRenderer_Metal:
			break;
		}
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------
