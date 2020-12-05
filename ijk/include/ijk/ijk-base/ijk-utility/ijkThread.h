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
typedef struct		ijkMutex			ijkMutex;
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijk_warn_mutex_current
//	Mutex warning indicating that calling thread already holds mutex lock.
#define ijk_warn_mutex_current	ijk_warncode(0x1)


// ijkThreadEntryFunc
//	Entry function type for thread interface. Any function returning integer 
//	and taking one pointer parameter (any type) qualifies.
//		param entryArg: pointer representing data to be passed to the function
//		return: any integer
typedef iret(*ijkThreadEntryFunc)(ptr entryArg);


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
	ijkThreadEntryFunc entryFunc;	// entry function
	ptr entryArg;					// entry argument
	tag name;						// name of thread
	dword sysID;					// system ID of thread
	ibool active;					// whether thread is still executing
	iret result;					// return value from entry function
};


// ijkMutex
//	Simple mutex (mutual exclusion) descriptor.
//		member sysID: system ID number of thread holding mutex
struct ijkMutex
{
	dword sysID;					// system ID of holding thread
};


//-----------------------------------------------------------------------------

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
iret ijkThreadCreate(ijkThread* const thread_out, ijkThreadEntryFunc const entryFunc, ptr const entryArg, tag const name);

// ijkThreadRelease
//	Wait indefinitely for a thread to safely finish.
//		param thread: pointer to thread descriptor
//			valid: non-null, initialized
//		return SUCCESS: ijk_success if thread terminated
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if failed to wait
iret ijkThreadRelease(ijkThread* const thread);

// ijkThreadReleaseUnsafe
//	Terminate a thread.
//		param thread: pointer to thread descriptor
//			valid: non-null, initialized
//		return SUCCESS: ijk_success if thread terminated
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if thread not terminated
iret ijkThreadReleaseUnsafe(ijkThread* const thread);

// ijkThreadCheckActive
//	Check internally whether thread is still active
//		param thread: pointer to thread descriptor
//			valid: non-null, initialized
//		return SUCCESS: ijk_true if thread is still active
//		return SUCCESS: ijk_false if thread is not active
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkThreadCheckActive(ijkThread const* const thread);


//-----------------------------------------------------------------------------

// ijkMutexLock
//	Single attempt to lock (gain control of) mutex handle.
//		param mutex: pointer to mutex descriptor
//			valid: non-null
//		return SUCCESS: ijk_success if mutex successfully locked
//		return WARNING: ijk_warn_mutex_current if caller already locked mutex
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if mutex not locked
iret ijkMutexLock(ijkMutex* const mutex);

// ijkMutexLockWait
//	Perpetual attempt to lock mutex handle.
//		param mutex: pointer to mutex descriptor
//			valid: non-null
//		return SUCCESS: ijk_success if mutex successfully locked
//		return WARNING: ijk_warn_mutex_current if caller already locked mutex
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if mutex not locked
iret ijkMutexLockWait(ijkMutex* const mutex);

// ijkMutexUnlock
//	Unlock (release control of) mutex handle if calling thread holds it.
//		param mutex: pointer to mutex descriptor
//			valid: non-null
//		return SUCCESS: ijk_success if mutex successfully unlocked
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if caller cannot unlock mutex
iret ijkMutexUnlock(ijkMutex* const mutex);

// ijkMutexIsLocked
//	Check if mutex is locked.
//		param mutex: pointer to mutex descriptor
//			valid: non-null
//		return SUCCESS: ijk_true if mutex is locked
//		return SUCCESS: ijk_false if mutex is unlocked
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkMutexIsLocked(ijkMutex const* const mutex);

// ijkMutexIsLockedByCaller
//	Check if mutex is locked by calling thread.
//		param mutex: pointer to mutex descriptor
//			valid: non-null
//		return SUCCESS: ijk_true if mutex is locked by caller
//		return SUCCESS: ijk_false if mutex is unlocked
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkMutexIsLockedByCaller(ijkMutex const* const mutex);

// ijkMutexIsUnlocked
//	Check if mutex is unlocked.
//		param mutex: pointer to mutex descriptor
//			valid: non-null
//		return SUCCESS: ijk_true if mutex is unlocked
//		return SUCCESS: ijk_false if mutex is locked
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkMutexIsUnlocked(ijkMutex const* const mutex);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#include "_inl/ijkThread.inl"


#endif	// !_IJK_THREAD_H_