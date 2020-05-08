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

	ijkThread.h
	Thread utility interface.
*/

#ifndef _IJK_THREAD_H_
#define _IJK_THREAD_H_


#include "ijk/ijk/ijk-typedefs.h"


#ifdef __cplusplus
extern "C" {
#else	// !__cplusplus
typedef struct		ijkThread			ijkThread;
#endif	// __cplusplus


// ijkThreadFunc
//	Entry function type for thread interface. Any function returning integer 
//	and taking one pointer parameter (any type) qualifies.
//		param: any pointer representing the data to be passed to the function
//		return: any integer
typedef iret(*ijkThreadFunc)(ptr);


// ijkThread
//	Thread descriptor.
//		member handle: internal thread handle(s), not platform-specific
//		member entryFunc: function to call for entry point
//		member entryArg: argument pointer to pass to entry function
//		member name: name of thread to appear in debugging interface
//		member sysID: system ID number of thread, identifier for handle
//		member active: boolean flag describing whether thread is running
//		member result: integer return value from entry function
struct ijkThread
{
	ptr handle[2];					// internal handles
	ijkThreadFunc entryFunc;		// entry function
	ptr entryArg;					// entry argument
	tag name;						// name of thread
	dword sysID;					// system ID of thread
	ibool active;					// whether thread is still executing
	iret result;					// return value from entry function
};


// ijkThreadCreate
//	Create and launch a thread.
//		param thread_out: pointer to thread descriptor
//			valid: non-null, uninitialized
//		param entryFunc: function to call when thread initializes
//			valid: non-null
//		param entryArg: argument to pass to entryFunc when it is called
//			note: pass null/zero if no argument to pass to entryFunc
//		param name: short name of thread
//			note: pass empty string "" to use default name
//		return SUCCESS: ijk_success if thread created
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if thread not created
iret ijkThreadCreate(ijkThread* const thread_out, ijkThreadFunc const entryFunc, ptr const entryArg, tag const name);

// ijkThreadReleaseUnsafe
//	Terminate a thread.
//		param thread: pointer to thread descriptor
//			valid: non-null, initialized
//		return SUCCESS: ijk_success if thread terminated
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if thread not terminated
iret ijkThreadReleaseUnsafe(ijkThread* const thread);

// ijkThreadReleaseSafe
//	Wait indefinitely for a thread to finish.
//		param thread: pointer to thread descriptor
//			valid: non-null, initialized
//		return SUCCESS: ijk_success if thread terminated
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if failed to wait
iret ijkThreadReleaseSafe(ijkThread* const thread);

// ijkThreadCheckActive
//	Check internally whether thread is still active
//		param thread: pointer to thread descriptor
//			valid: non-null, initialized
//		return SUCCESS: ijk_true if thread is still active
//		return SUCCESS: ijk_false if thread is not active
//		return FAILURE: ijk_fail_invalidparams if invalid params
iret ijkThreadCheckActive(ijkThread const* const thread);


#ifdef __cplusplus
}
#endif	// __cplusplus


#include "_inl/ijkThread.inl"


#endif	// !_IJK_THREAD_H_