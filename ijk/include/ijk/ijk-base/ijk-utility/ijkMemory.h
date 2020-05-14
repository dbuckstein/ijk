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
//		param sz_chomps: size of block in chomps
//		return (recommended): dst
typedef	ptr(*ijkMemoryCopyCallback)(ptr dst, kptr src, size sz_chomps);


// ijkMemoryInitCallback
//	Format of callback to use when initializing or terminating.
//		param dst: pointer to destination block
//		param sz_chomps: size of block in chomps
//		return (recommended): dst
typedef ptr(*ijkMemoryInitCallback)(ptr dst, size sz_chomps);


//-----------------------------------------------------------------------------

// ijkMemorySet
//	Set/format memory block.
//		param dst: pointer to destination block
//			valid: non-null
//		param sz_bytes: size of block in bytes
//			valid: non-zero
//		param value: value used to set all bytes
//		return SUCCESS: dst
//		return FAILURE: null/zero
ptr ijkMemorySet(ptr const dst, size const sz_bytes, byte const value);

// ijkMemorySetZero
//	Set/format memory block such that all bytes are zero.
//		param dst: pointer to destination block
//			valid: non-null
//		param sz_bytes: size of block in bytes
//			valid: non-zero
//		return SUCCESS: dst
//		return FAILURE: null/zero
ptr ijkMemorySetZero(ptr const dst, size const sz_bytes);

// ijkMemoryCopy
//	Copy memory block.
//		param dst: pointer to destination block
//			valid: non-null
//		param src: pointer to source block
//			valid: non-null
//		param sz_bytes: size of block in bytes
//			valid: non-zero
//		return SUCCESS: dst
//		return FAILURE: null/zero
ptr ijkMemoryCopy(ptr const dst, kptr const src, size const sz_bytes);

// ijkMemoryCompare
//	Compare memory block.
//		param dst: pointer to destination block
//			valid: non-null
//		param src: pointer to source block
//			valid: non-null
//		param sz_bytes: size of block in bytes
//			valid: non-zero
//		return SUCCESS: number of bytes before difference
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
ptrdiff ijkMemoryCompare(kptr const dst, kptr const src, size const sz_bytes);

// ijkMemoryCopyC
//	Set/format memory block of chomps.
//		param dst: pointer to destination block
//			valid: non-null
//		param sz_chomps: size of block in chomps
//			valid: non-zero
//		param value: value used to set all chomps
//		return SUCCESS: dst
//		return FAILURE: null/zero
ptr ijkMemorySetC(ptr const dst, size const sz_chomps, chomp const value);

// ijkMemorySetZeroC
//	Set/format memory block of chomps such that all bytes are zero.
//		param dst: pointer to destination block
//			valid: non-null
//		param sz_chomps: size of block in chomps
//			valid: non-zero
//		return SUCCESS: dst
//		return FAILURE: null/zero
ptr ijkMemorySetZeroC(ptr const dst, size const sz_chomps);

// ijkMemoryCopyC
//	Copy memory block of chomps.
//		param dst: pointer to destination block
//			valid: non-null
//		param src: pointer to source block
//			valid: non-null
//		param sz_chomps: size of block in chomps
//			valid: non-zero
//		return SUCCESS: dst
//		return FAILURE: null/zero
ptr ijkMemoryCopyC(ptr const dst, kptr const src, size const sz_chomps);

// ijkMemoryCompareC
//	Compare memory block of chomps.
//		param dst: pointer to destination block
//			valid: non-null
//		param src: pointer to source block
//			valid: non-null
//		param sz_chomps: size of block in chomps
//			valid: non-zero
//		return SUCCESS: number of chomps before difference
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
ptrdiff ijkMemoryCompareC(kptr const dst, kptr const src, size const sz_chomps);


//-----------------------------------------------------------------------------

// ijkMemoryPoolCreate
//	Initialize managed pool given pre-allocated (stack or heap) block of 
//	memory. Effectively turns any memory block into a managed block.
//		param pool_base: base pointer to pre-allocated block
//			valid: non-null, uninitialized as pool
//		param baseSize: size of base block (pre-allocated) in bytes
//			valid: non-zero
//		param poolSize: size of pool (managed) in bytes
//			valid: non-zero
//		param name: name of pool
//			valid: non-zero, non-empty c-string
//		param initCallback_opt: optional initialization callback
//		return SUCCESS: ijk_success if pool initialized
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if not initialized
iret ijkMemoryPoolCreate(ptr const pool_base, size const baseSize, size const poolSize, tag const name, ijkMemoryInitCallback const initCallback_opt);

// ijkMemoryPoolRelease
//	Terminate managed pool, leaving the contained memory unaffected.
//		param pool: base pointer to pre-allocated block
//			valid: non-null, initialized
//			note: does not format; assumes objects within have been released
//		param termCallback_opt: optional termination callback
//		return SUCCESS: ijk_success if pool terminated
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if not terminated
iret ijkMemoryPoolRelease(ptr const pool, ijkMemoryInitCallback const termCallback_opt);

// ijkMemoryPoolLoad
//	Load managed pool from an open stream.
//		param pool_base: base pointer to pre-allocated block
//			valid: non-null, initialized
//		param baseSize: size of base block in bytes
//			valid: non-zero
//		param stream: pointer to stream descriptor
//			valid: non-null, initialized, read mode enabled
//		param loadCallback_opt: optional load callback
//		return SUCCESS: ijk_success if pool loaded
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if pool not loaded
iret ijkMemoryPoolLoad(ptr const pool_base, size const baseSize, ijkStream* const stream, ijkStreamReadFunc const loadCallback_opt);

// ijkMemoryPoolSave
//	Save managed pool to an open stream.
//		param pool: base pointer to pre-allocated block
//			valid: non-null, initialized
//		param baseSize: size of base block in bytes
//			valid: non-zero
//		param stream: pointer to stream descriptor
//			valid: non-null, initialized, read mode disabled
//		param saveCallback_opt: optional load callback
//		return SUCCESS: ijk_success if pool saved
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if pool not saved
iret ijkMemoryPoolSave(kptr const pool, size const baseSize, ijkStream* const stream, ijkStreamWriteFunc const saveCallback_opt);

// ijkMemoryPoolDefragment
//	Defragment pool.
//		param pool: base pointer to pre-allocated block
//			valid: non-null, initialized
//		param copyCallback_opt: optional callback to perform copying
//			note: if null is passed, uses ijkMemoryCopyC
//		return SUCCESS: ijk_success if defragmented
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if not defragmented
iret ijkMemoryPoolDefragment(ptr const pool, ijkMemoryCopyCallback const copyCallback_opt);

// ijkMemoryPoolGetBlock
//	Find a reserved block by name within a pool.
//		param pool: base pointer to pre-allocated block
//			valid: non-null, initialized
//		param block_out: pointer to block pointer
//			valid: non-null, points to null
//			note: upon function success, points to non-null block address
//		param name: name of block to locate
//			valid: non-null, non-empty c-string
//		return SUCCESS: ijk_success if block retrieved
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if block not retrieved
iret ijkMemoryPoolGetBlock(kptr const pool, kptr* const block_out, tag const name);

// ijkMemoryPoolGetName
//	Get the name of a pool.
//		param pool: base pointer to pre-allocated block
//			valid: non-null, initialized
//		param name_out: name of pool to be retrieved
//			valid: non-null c-string
//		return SUCCESS: ijk_success if name retrieved
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if name not retrieved
iret ijkMemoryPoolGetName(kptr const pool, tag name_out);

// ijkMemoryPoolSetName
//	Set the name of a pool.
//		param pool: base pointer to pre-allocated block
//			valid: non-null, initialized
//		param name: name of pool to be set
//			valid: non-null, non-empty c-string
//		return SUCCESS: ijk_success if name set
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if name not set
iret ijkMemoryPoolSetName(ptr const pool, tag const name);

// ijkMemoryPoolGetReserved
//	Get the number of bytes reserved.
//		param pool: base pointer to pre-allocated block
//			valid: non-null, initialized
//		param size_out: pointer to reserved size
//			valid: non-null
//			note: upon function success, points to non-negative reserved size
//		return SUCCESS: ijk_success if size retrieved
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if size not retrieved
iret ijkMemoryPoolGetReserved(kptr const pool, size* const size_out);

// ijkMemoryPoolGetAvailable
//	Get the number of bytes available.
//		param pool: base pointer to pre-allocated block
//			valid: non-null, initialized
//		param size_out: pointer to available size
//			valid: non-null
//			note: upon function success, points to non-negative available size
//		return SUCCESS: ijk_success if size retrieved
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if size not retrieved
iret ijkMemoryPoolGetAvailable(kptr const pool, size* const size_out);

// ijkMemoryPoolGetFragmented
//	Get the number of bytes fragmented.
//		param pool: base pointer to pre-allocated block
//			valid: non-null, initialized
//		param size_out: pointer to fragmented size
//			valid: non-null
//			note: upon function success, points to non-negative fragmented size
//		return SUCCESS: ijk_success if size retrieved
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if size not retrieved
iret ijkMemoryPoolGetFragmented(kptr const pool, size* const size_out);

// ijkMemoryPoolGetSize
//	Get the full size of a pool in bytes.
//		param pool: base pointer to pre-allocated block
//			valid: non-null, initialized
//		param size_out: pointer to size of pool
//			valid: non-null
//			note: upon function success, points to non-negative pool size
//		return SUCCESS: ijk_success if size retrieved
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if size not retrieved
iret ijkMemoryPoolGetSize(kptr const pool, size* const size_out);


//-----------------------------------------------------------------------------

// ijkMemoryBlockCreate
//	Reserve a block within a pool.
//		param block_out: pointer to block pointer
//			valid: non-null, points to null
//		param blockSize: size of block in bytes
//			valid: non-zero
//		param pool: base pointer to managed pool
//			valid: non-null, initialized
//		param name: name of pool
//			valid: non-zero, non-empty c-string
//		param type: user-defined data type of block
//			valid: non-negative
//		param initCallback_opt: optional initialization callback
//		return SUCCESS: ijk_success if block reserved
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if not reserved
iret ijkMemoryBlockCreate(ptr* const block_out, size const blockSize, ptr const pool, tag const name, flag const type, ijkMemoryInitCallback const initCallback_opt);

// ijkMemoryBlockRelease
//	Release a block back into a pool.
//		param block: pointer to block
//			valid: non-null, initialized
//			note: does not format
//		param pool: base pointer to managed pool
//			valid: non-null, initialized
//		param termCallback_opt: optional termination callback
//		return SUCCESS: ijk_success if block released
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if not released
iret ijkMemoryBlockRelease(ptr const block, ptr const pool, ijkMemoryInitCallback const termCallback_opt);

// ijkMemoryBlockLoad
//	Load a block from an open stream.
//		param block: pointer to block
//			valid: non-null, initialized
//		param stream: pointer to stream descriptor
//			valid: non-null, initialized, read mode enabled
//		param loadCallback_opt: optional load callback
//		return SUCCESS: ijk_success if block loaded
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if block not loaded
iret ijkMemoryBlockLoad(ptr const block, ijkStream* const stream, ijkStreamReadFunc const loadCallback_opt);

// ijkMemoryBlockSave
//	Save a block to an open stream.
//		param block: pointer to block
//			valid: non-null, initialized
//		param stream: pointer to stream descriptor
//			valid: non-null, initialized, read mode disabled
//		param saveCallback_opt: optional load callback
//		return SUCCESS: ijk_success if block saved
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if block not saved
iret ijkMemoryBlockSave(kptr const block, ijkStream* const stream, ijkStreamWriteFunc const saveCallback_opt);

// ijkMemoryBlockIsInPool
//	Check if reserved block is contained within a pool.
//		param block: pointer to block
//			valid: non-null, initialized
//		param pool: pointer to pool
//			valid: non-null, initialized
//		param status_out: pointer to status
//			valid: non-null
//			note: upon function success, points to boolean status
//		return SUCCESS: ijk_success if status retrieved
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if status not retrieved
iret ijkMemoryBlockIsInPool(kptr const block, kptr const pool, ibool* const status_out);

// ijkMemoryBlockGetName
//	Get the name of a reserved block.
//		param block: pointer to block
//			valid: non-null, initialized
//		param name_out: name of block to be retrieved
//			valid: non-null c-string
//		return SUCCESS: ijk_success if name retrieved
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if name not retrieved
iret ijkMemoryBlockGetName(kptr const block, tag name_out);

// ijkMemoryBlockSetName
//	Set the name of a reserved block.
//		param block: pointer to block
//			valid: non-null, initialized
//		param name: name of block to be set
//			valid: non-null, non-empty c-string
//		return SUCCESS: ijk_success if name set
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if name not set
iret ijkMemoryBlockSetName(ptr const block, tag const name);

// ijkMemoryBlockGetType
//	Get the user-defined data type of a reserved block.
//		param block: pointer to block
//			valid: non-null, initialized
//		param type_out: pointer to user-defined data type of block
//			valid: non-null
//			note: upon function success, points to non-negative type identifier
//		return SUCCESS: ijk_success if type retrieved
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if type not retrieved
iret ijkMemoryBlockGetType(kptr const block, flag* const type_out);

// ijkMemoryBlockSetType
//	Set the user-defined data type of a reserved block.
//		param block: pointer to block
//			valid: non-null, initialized
//		param type: user-defined data type of block
//			valid: non-negative
//		return SUCCESS: ijk_success if type set
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if type not set
iret ijkMemoryBlockSetType(ptr const block, flag const type);

// ijkMemoryBlockGetSize
//	Get the size of a reserved block.
//		param block: pointer to block
//			valid: non-null, initialized
//		param size_out: pointer to size of block
//			valid: non-null
//			note: upon function success, points to non-negative block size
//		return SUCCESS: ijk_success if size retrieved
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if size not retrieved
iret ijkMemoryBlockGetSize(kptr const block, size* const size_out);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#include "_inl/ijkMemory.inl"


#endif	// !_IJK_MEMORY_H_