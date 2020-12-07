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

	ijkApplication.h
	Application management interface.
*/

#ifndef _IJK_APPLICATION_H_
#define _IJK_APPLICATION_H_

#include "ijk/ijk/ijk-typedefs.h"


#ifdef __cplusplus
extern "C" {
#else	// !__cplusplus

#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijk_warn_application_exist
//	Application warning indicating that application cannot be initialized 
//	because instance already exists, or indicates that the app should 
//	terminate because instance cannot be initialized.
#define ijk_warn_application_exist	ijk_warncode(0x1)


// ijkApplicationStartSingleInstanceSwitchExisting
//	Call at the beginning of application entry to prevent multiple instances 
//	of the application from running; automatically switch to original instance.
//		param windowName: title of window created
//			valid: non-null, non-empty
//		return SUCCESS: ijk_success if application can be initialized
//		return WARNING: ijk_warn_application_exist if application cannot be 
//			initialized due to another instance existing; original instance 
//			will automatically be activated and displayed in foreground
//		return FAILURE: ijk_fail_operationfail if application not initialized 
//			and failed to switch to original instance
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkApplicationStartSingleInstanceSwitchExisting(tag const windowName);

// ijkApplicationStartSingleInstance
//	Call at the beginning of application entry to prevent multiple instances 
//	of the application from running.
//		param handle_out: pointer to mutex handle
//			valid: non-null, value pointed to is null
//		param instanceName: name of application instance
//			valid: non-null, non-empty
//		param index_out_opt: optional pointer to index of this instance; if 
//			passed, points to value of exactly zero (the only valid index)
//		return SUCCESS: ijk_success if application can be initialized
//		return WARNING: ijk_warn_application_exist if application cannot be 
//			initialized due to another instance existing
//		return FAILURE: ijk_fail_operationfail if application not initialized
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkApplicationStartSingleInstance(ptr* const handle_out, tag const instanceName, i32* const index_out_opt);

// ijkApplicationStartMultipleInstance
//	Call at the beginning of application entry to allow running multiple 
//	instances of application.
//		param handle_out: pointer to semaphore handle
//			valid: non-null, value pointed to is null
//		param instanceName: name of application instance
//			valid: non-null, non-empty
//		param limit: number of instances allowed
//			valid: non-zero
//		param index_out_opt: optional pointer to index of this instance; if 
//			passed, points to non-negative value upon success
//		return SUCCESS: ijk_success if application can be initialized
//		return WARNING: ijk_warn_application_exist if application cannot be 
//			initialized due to another instance existing
//		return FAILURE: ijk_fail_operationfail if application not initialized
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkApplicationStartMultipleInstance(ptr* const handle_out, tag const instanceName, ui32 const limit, i32* const index_out_opt);

// ijkApplicationStopSingleInstance
//	Stop single instance using mutex.
//		param handle: pointer to mutex handle
//			valid: non-null, value pointed to is non-null
//		param available_out_opt: optional pointer to number of available or  
//			remaining instances after release; if passed, points to value of 
//			exactly one (the only valid availability)
//		return SUCCESS: ijk_success if application successfully terminated
//		return FAILURE: ijk_fail_operationfail if application not terminated
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkApplicationStopSingleInstance(ptr* const handle, ui32* const available_out_opt);

// ijkApplicationStopMultipleInstance
//	Stop instance using semaphore.
//		param handle: pointer to semaphore handle
//			valid: non-null, value pointed to is non-null
//		param available_out_opt: optional pointer to number of available or  
//			remaining instances after release; if passed, points to positive 
//			value upon success
//		return SUCCESS: ijk_success if application successfully terminated
//		return FAILURE: ijk_fail_operationfail if application not terminated
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkApplicationStopMultipleInstance(ptr* const handle, ui32* const available_out_opt);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#endif	// !_IJK_APPLICATION_H_