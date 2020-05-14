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

	ijkMemory.c
	Memory utility implementation.
*/

#include "ijk/ijk-base/ijk-utility/ijkMemory.h"


//-----------------------------------------------------------------------------

#ifndef __cplusplus
typedef struct ijkMemoryPool	ijkMemoryPool;
typedef struct ijkMemoryBlock	ijkMemoryBlock;
#endif	// !__cplusplus


// ijkMemoryPool
//	Managed memory pool descriptor.
//		member name: name of pool used for identification
//		member chompsReserved: number of chomps (units) occupied
//		member chompsAvailable: number of chomps free/open/available
//		member chompsFragmented: number of chomps lost to fragmentation
//		member chompSize: total size of pool in chomps
//		member chompOffsetPrev: offset to previous reservation block descriptor
//		member chompOffsetNext: offset to next reservation block descriptor
//		member chompOffsetLastRelease: offset to last-released block descriptor
//		member reserveCount: number of reservations
struct ijkMemoryPool
{
	dtag name;							// identifier
	size chompsReserved;				// space occupied
	size chompsAvailable;				// space available
	size chompsFragmented;				// space fragmented
	size chompSize;						// total space
	size chompOffsetPrev;				// offset to previous reservation
	size chompOffsetNext;				// offset to next reservation
	size chompOffsetLastRelease;		// offset to last release
	size reserveCount;					// number of reservations
};

// szmempool
//	Convenient macro for size of pool.
#define szmempool						szb(ijkMemoryPool)

// szcmempool
//	Size of pool in chomps.
#define szcmempool						szc(ijkMemoryPool)


// ijkMemoryBlock
//	Managed memory reservation descriptor.
//		member name: name of block used for identification
//		member type: user-defined data type identifier of block
//		member chompSize: size of block in chomps
//		member chompOffsetPrev: offset from previous block
//		member chompOffsetNext: offset towards next block
//		member chompOffsetHead: offset from pool head
//		member chompOffsetTail: offset towards pool tail
//		member chompOpenHead: open/available chomps from pool head
//		member chompOpenTail: open/available chomps towards pool tail
struct ijkMemoryBlock
{
	dtag name;							// identifier
	flag type;							// user-defined type
	size chompSize;						// size of block
	size chompOffsetPrev;				// offset from previous block
	size chompOffsetNext;				// offset towards next block
	size chompOffsetHead;				// offset from pool head
	size chompOffsetTail;				// offset towards pool tail
	size chompOpenHead;					// available from head
	size chompOpenTail;					// available towards tail
};

// szmemblock
//	Convenient macro for size of reservation block.
#define szmemblock						szb(ijkMemoryBlock)

// szcmemblock
//	Size of reservation block in chomps.
#define szcmempool						szc(ijkMemoryPool)


//-----------------------------------------------------------------------------

iret ijkMemoryPoolCreate(ptr const pool_base, size const baseSize, size const poolSize, tag const name, ijkMemoryInitCallback const initCallback_opt)
{
	if (pool_base && baseSize && poolSize && name && *name)
	{

	}
	return ijk_fail_invalidparams;
}


iret ijkMemoryPoolRelease(ptr const pool, ijkMemoryInitCallback const termCallback_opt)
{
	if (pool)
	{

	}
	return ijk_fail_invalidparams;
}


iret ijkMemoryPoolLoad(ptr const pool_base, size const baseSize, ijkStream* const stream, ijkMemoryInitCallback const loadCallback_opt)
{
	if (pool_base && baseSize && stream &&
		stream->base && stream->isRead)
	{

	}
	return ijk_fail_invalidparams;
}


iret ijkMemoryPoolSave(kptr const pool, size const baseSize, ijkStream* const stream, ijkMemoryInitCallback const saveCallback_opt)
{
	if (pool && baseSize && stream &&
		stream->base && !stream->isRead)
	{

	}
	return ijk_fail_invalidparams;
}


iret ijkMemoryPoolDefragment(ptr const pool, ijkMemoryCopyCallback const copyCallback_opt)
{
	if (pool)
	{

	}
	return ijk_fail_invalidparams;
}


iret ijkMemoryPoolGetBlock(ptr const pool, ptr* const block_out)
{
	if (pool && block_out && !*block_out)
	{

	}
	return ijk_fail_invalidparams;
}


iret ijkMemoryPoolGetName(ptr const pool, tag name_out)
{
	if (pool && name_out)
	{

	}
	return ijk_fail_invalidparams;
}


iret ijkMemoryPoolSetName(ptr const pool, tag const name)
{
	if (pool && name && *name)
	{

	}
	return ijk_fail_invalidparams;
}


iret ijkMemoryPoolGetReserved(ptr const pool, size* const size_out)
{
	if (pool && size_out)
	{

	}
	return ijk_fail_invalidparams;
}


iret ijkMemoryPoolGetAvailable(ptr const pool, size* const size_out)
{
	if (pool && size_out)
	{

	}
	return ijk_fail_invalidparams;
}


iret ijkMemoryPoolGetFragmented(ptr const pool, size* const size_out)
{
	if (pool && size_out)
	{

	}
	return ijk_fail_invalidparams;
}


iret ijkMemoryPoolGetSize(ptr const pool, size* const size_out)
{
	if (pool && size_out)
	{

	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
