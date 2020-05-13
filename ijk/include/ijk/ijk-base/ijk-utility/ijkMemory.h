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

	ijkMemory.h
	Memory utility interface.
*/

#ifndef _IJK_MEMORY_H_
#define _IJK_MEMORY_H_


#include "ijk/ijk/ijk-typedefs.h"

#include "ijkStream.h"


#ifdef __cplusplus
extern "C" {
#else	// !__cplusplus

#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijkMemoryCopyCallback
//	Format of callback to use when copying; allows for user-managed copies.
//		param dst: pointer to destination block
//		param src: pointer to source block
//		param sz_bytes: size of block in bytes
//		return (recommended): dst
typedef	ptr(*ijkMemoryCopyCallback)(ptr dst, kptr src, size sz_bytes);


// ijkMemoryInitCallback
//	Format of callback to use when initializing or terminating.
//		param dst: pointer to destination block
//		param sz_bytes: size of block in bytes
//		return (recommended): dst
typedef ptr(*ijkMemoryInitCallback)(ptr dst, size sz_bytes);


//-----------------------------------------------------------------------------

// ijkMemorySet
//	Set/format memory block.
//		param dst: pointer to destination block
//		param sz_bytes: size of block in bytes
//		param value: value used to set all bytes
//		return SUCCESS: dst
//		return FAILURE: null/zero

// ijkMemorySetZero
//	Set/format memory block such that all bytes are zero.
//		param dst: pointer to destination block
//		param sz_bytes: size of block in bytes
//		return SUCCESS: dst
//		return FAILURE: null/zero

// ijkMemoryCopy
//	Copy memory block.
//		param dst: pointer to destination block
//		param src: pointer to source block
//		param sz_bytes: size of block in bytes
//		return SUCCESS: dst
//		return FAILURE: null/zero

// ijkMemoryCompare
//	Compare memory block.
//		param dst: pointer to destination block
//		param src: pointer to source block
//		return SUCCESS: number of bytes before difference
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkMemoryCopyC
//	Set/format memory block of chomps.
//		param dst: pointer to destination block
//		param sz_chomps: size of block in chomps
//		param value: value used to set all chomps
//		return SUCCESS: dst
//		return FAILURE: null/zero

// ijkMemorySetZeroC
//	Set/format memory block of chomps such that all bytes are zero.
//		param dst: pointer to destination block
//		param sz_chomps: size of block in chomps
//		return SUCCESS: dst
//		return FAILURE: null/zero

// ijkMemoryCopyC
//	Copy memory block of chomps.
//		param dst: pointer to destination block
//		param src: pointer to source block
//		param sz_bytes: size of block in bytes
//		return SUCCESS: dst
//		return FAILURE: null/zero

// ijkMemoryCompareC
//	Compare memory block of chomps.
//		param dst: pointer to destination block
//		param src: pointer to source block
//		return SUCCESS: number of chomps before difference
//		return FAILURE: ijk_fail_invalidparams if invalid parameters


//-----------------------------------------------------------------------------

// ijkMemoryPoolCreate
//	Initialize managed pool given pre-allocated (stack or heap) block of 
//	memory. Effectively turns any memory block into a managed block.
//		param base: base pointer to pre-allocated block
//			valid: non-null
//		param baseSize: size of base block in bytes
//			valid: non-zero
//		param poolSize: size of pool in bytes
//			valid: non-zero
//		param name: name of pool
//			valid: non-zero, non-empty c-string
//		param initCallback_opt: optional initialization callback
//		return SUCCESS: ijk_success if pool initialized
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if not initialized

// ijkMemoryPoolRelease
//	Terminate managed pool, leaving the contained memory unaffected.
//		param base: base pointer to pre-allocated block
//			valid: non-null
//			note: assumes all objects within have been released
//		param termCallback_opt: optional termination callback
//		return SUCCESS: ijk_success if pool terminated
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if not terminated

// ijkMemoryPoolLoad
//	Load managed pool from an open stream.
//		param base: base pointer to pre-allocated block
//			valid: non-null
//		param stream: pointer to stream descriptor
//			valid: non-null, initialized, read mode enabled
//		param baseSize: size of base block in bytes
//			valid: non-zero
//		param loadCallback_opt: optional load callback
//		return SUCCESS: ijk_success if pool loaded
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if pool not loaded

// ijkMemoryPoolSave
//	Save managed pool to an open stream.
//		param base: base pointer to pre-allocated block
//			valid: non-null
//		param stream: pointer to stream descriptor
//			valid: non-null, initialized, read mode disabled
//		param baseSize: size of base block in bytes
//			valid: non-zero
//		param saveCallback_opt: optional load callback
//		return SUCCESS: ijk_success if pool saved
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if pool not saved

// ijkMemoryPoolGetName
//	Get the name of a pool.

// ijkMemoryPoolSetName
//	Set the name of a pool.

// ijkMemoryPoolGetReserved
//	Get the number of bytes reserved.

// ijkMemoryPoolGetAvailable
//	Get the number of bytes available.

// ijkMemoryPoolGetFragmented
//	Get the number of bytes fragmented.

// ijkMemoryPoolGetSize
//	Get the full size of a pool in bytes.

// ijkMemoryPoolGetBlock
//	Find a reserved block by name within a pool.

// ijkMemoryPoolDefragment
//	Defragment pool.


//-----------------------------------------------------------------------------

// ijkMemoryBlockReserve
//	Reserve a block within a pool.

// ijkMemoryBlockRelease
//	Release a block back into a pool.

// ijkMemoryBlockLoad
//	Load a block from an open stream.

// ijkMemoryBlockSave
//	Save a block to an open stream.

// ijkMemoryBlockGetName
//	Get the name of a reserved block.

// ijkMemoryBlockSetName
//	Set the name of a reserved block.

// ijkMemoryBlockGetType
//	Get the user-defined data type of a reserved block.

// ijkMemoryBlockSetType
//	Set the user-defined data type of a reserved block.

// ijkMemoryBlockGetSize
//	Get the size of a reserved block.

// ijkMemoryBlockIsInPool
//	Check if reserved block is ontained within a pool.


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#include "_inl/ijkMemory.inl"


#endif	// !_IJK_MEMORY_H_