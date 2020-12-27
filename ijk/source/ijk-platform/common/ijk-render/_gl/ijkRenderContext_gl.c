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

	ijkRenderContext_gl.c
	Platform-agnostic OpenGL render context management source.
*/

#include "ijk/ijk-platform/ijk-render/ijkRenderContext.h"

#include <stdio.h>


//-----------------------------------------------------------------------------

iret ijkRenderContextPrintInfo_gl(ijkRenderContext const* const renderContext, cstr* const bufferPtr)
{
	*bufferPtr += sprintf(*bufferPtr, "OpenGL \n");
	/*
	kptag* const versionStr = glGetString(GL_VERSION);
	kptag* const shadingStr = glGetString(GL_SHADING_LANGUAGE_VERSION);
	kptag* const rendererStr = glGetString(GL_RENDERER);
	kptag* const vendorStr = glGetString(GL_VENDOR);
	*/
	return ijk_success;
}


//-----------------------------------------------------------------------------
