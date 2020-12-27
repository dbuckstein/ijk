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

	ijkRenderContext.c
	Platform-agnostic and renderer-agnostic render context management source.
*/

#include "ijk/ijk-platform/ijk-render/ijkRenderContext.h"


//-----------------------------------------------------------------------------

iret ijkRenderContextCreate(ijkRenderContext* const renderContext_out, ijkRenderer const renderer)
{

	return ijk_fail_invalidparams;
}


iret ijkRenderContextRelease(ijkRenderContext* const renderContext)
{

	return ijk_fail_invalidparams;
}


iret ijkRenderContextActivate(ijkRenderContext const* const renderContext)
{

	return ijk_fail_invalidparams;
}


iret ijkRenderContextDeactivate(ijkRenderContext const* const renderContext)
{

	return ijk_fail_invalidparams;
}


iret ijkRenderContextLink(ijkRenderContext const* const renderContext0, ijkRenderContext const* const renderContext1)
{

	return ijk_fail_invalidparams;
}


iret ijkRenderContextPrintInfo(ijkRenderContext const* const renderContext, cstr* const bufferPtr)
{

	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------
