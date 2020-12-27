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

	ijkRenderContext_win_gl.c
	OpenGL render context management source for Windows.
*/

/*
	Download latest version of GLEW (OpenGL Extension Wrangler): 
		-> http://glew.sourceforge.net/ 
	Unzip versioned folder (e.g. "glew-2.1.0") into container directory at 
	system level: "C:/GLEW" (e.g. above, full path "C:/GLEW/glew-2.1.0").
	After unzipping, run install utility: 
		-> "<ijk root>/utility/windows/dev/ijk-glewlocate.bat" 
		-> Environment variables: GLEW_PATH
	Other info about GL loaders and extension managers: 
		-> https://www.khronos.org/opengl/wiki/OpenGL_Loading_Library 
*/

#include "ijk/ijk-platform/ijk-render/ijkRenderContext.h"
#if ijk_platform_is(WINDOWS)
#include <Windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//-----------------------------------------------------------------------------

// ijkRendererInfo_win_gl
//	Renderer info for OpenGL render context on Windows.
typedef struct ijkRendererInfo_win_gl_tag
{
	ijkRenderContext const* renderContext;
	HGLRC rc;
	HWND wnd;
	HDC dc;
	i32 pf;
} ijkRendererInfo_win_gl;


#define info info_rp


//-----------------------------------------------------------------------------

iret ijkRenderContextCreateWINDOWS_gl(ijkRenderContext* const renderContext_out)
{
	if (renderContext_out->info == 0)
	{
		// allocate platform info
		size const sz = szb(ijkRendererInfo_win_gl);
		ijkRendererInfo_win_gl* info = (ijkRendererInfo_win_gl*)malloc(sz);
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