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

	ijkRenderContext.h
	Render context management interface.
*/

#ifndef _IJK_RENDERCONTEXT_H_
#define _IJK_RENDERCONTEXT_H_

#include "ijk/ijk/ijk-typedefs.h"


#ifdef __cplusplus
extern "C" {
#else	// !__cplusplus
typedef struct ijkRenderContext	ijkRenderContext;
typedef enum ijkRenderer		ijkRenderer;
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijk_fail_renderer_unsupported
//	Renderer warning indicating that renderer type is not supported.
#define ijk_fail_renderer_unsupported	ijk_failcode(0x4)


//-----------------------------------------------------------------------------

// ijkRendererInfo
//	Renderer- and platform-agnostic alias for renderer info descriptor, 
//	implemented in source for renderer- and platform-specific requirements.
typedef ptr ijkRendererInfo;

// ijkRenderer
//	Enumeration of available renderers.
enum ijkRenderer
{
	ijkRenderer_none,		// No renderer enabled.
	ijkRenderer_OpenGL,		// OpenGL: cross-platform.
	ijkRenderer_Vulkan,		// Vulkan: cross-platform, low-overhead.
	ijkRenderer_DirectX,	// DirectX: Microsoft native.
	ijkRenderer_Metal,		// Metal: Apple native.
};

// ijkRenderContext
//	High-level rendering context descriptor.
//		member renderer: renderer type enum
//		member info: internal renderer info
struct ijkRenderContext
{
	ijkRenderer renderer;
	ijkRendererInfo info;
};


//-----------------------------------------------------------------------------

// ijkRenderContextCreate
//	Create and initialize render context of specified type.
//		param renderContext_out: pointer to render context
//			valid: non-null, uninitialized
//		param renderer: renderer type to initialize
//			valid: non-zero
//		return SUCCESS: ijk_success if renderer initialized
//		return FAILURE: ijk_fail_renderer_unsupported if renderer unsupported
//		return FAILURE: ijk_fail_operationfail if renderer not initialized
//		return FAILURE: ijk_fail_invalidparams if invalid parameters


// ijkRenderContextRelease
//	Terminate and release render context.
//		param renderContext: pointer to render context
//			valid: non-null, initialized
//		return SUCCESS: ijk_success if renderer terminated
//		return FAILURE: ijk_fail_operationfail if renderer not terminated
//		return FAILURE: ijk_fail_invalidparams if invalid parameters


// ijkRenderContextActivate
//	Activate render context.
//		param renderContext: pointer to render context
//			valid: non-null, initialized
//		return SUCCESS: ijk_success if renderer activated
//		return FAILURE: ijk_fail_operationfail if renderer not activated
//		return FAILURE: ijk_fail_invalidparams if invalid parameters


// ijkRenderContextDeactivate
//	Deactivate render context.
//		param renderContext: pointer to render context
//			valid: non-null, initialized
//		return SUCCESS: ijk_success if renderer deactivated
//		return FAILURE: ijk_fail_operationfail if renderer not deactivated
//		return FAILURE: ijk_fail_invalidparams if invalid parameters


// ijkRenderContextLink
//	Link render contexts, allowing them to share resources; must be done prior 
//	to any rendering tasks to allow either context to manage resources.
//		param renderContext0: pointer to first render context
//			valid: non-null, initialized
//		param renderContext1: pointer to second render context
//			valid: non-null, initialized
//		return SUCCESS: ijk_success if renderers linked
//		return FAILURE: ijk_fail_operationfail if renderers not linked
//		return FAILURE: ijk_fail_invalidparams if invalid parameters


// ijkRenderContextPrintInfo
//	Link render contexts, allowing them to share resources; must be done prior 
//	to any rendering tasks to allow either context to manage resources.
//		param renderContext: pointer to render context
//			valid: non-null, initialized
//		param bufferPtr: pointer to c-string to capture info
//			valid: non-null, points to valid c-string
//		return SUCCESS: ijk_success if info printed to buffer
//		return FAILURE: ijk_fail_operationfail if info not printed
//		return FAILURE: ijk_fail_invalidparams if invalid parameters


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#endif	// !_IJK_RENDERCONTEXT_H_