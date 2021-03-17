/*
   Copyright 2020-2021 Daniel S. Buckstein

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

	ijkMemory.inl
	Memory utility inline implementation.
*/

#ifdef _IJK_MEMORY_H_
#ifndef _IJK_MEMORY_INL_
#define _IJK_MEMORY_INL_


//-----------------------------------------------------------------------------

// helper macros for basic operations
///
#define ijk_memory_set(dst, end, value)		while (dst < end) (*(dst++) = value)
#define ijk_memory_copy(dst, src, end)		while (dst < end) (*(dst++) = *(src++))
#define ijk_memory_compare(dst, src, end)	while (dst < end) if (*(dst) == *(src++)) (++dst); else break


//-----------------------------------------------------------------------------

ijk_inl ptr ijkMemorySet(ptr const dst, size const sz_bytes, byte const value)
{
	if (dst && sz_bytes)
	{
		byte const value2chomp[szqword] = { value, value, value, value, value, value, value, value };
		chomp const value_chomp = *((pchomp)value2chomp);
		pchomp dst_chomp = (pchomp)dst;
		pbyte dst_byte = (pbyte)dst;
		kpchomp const end_chomp = dst_chomp + sz_bytes / szchomp;
		kpbyte const end_byte = dst_byte + sz_bytes;

		// set integers until the last integer can fit
		ijk_memory_set(dst_chomp, end_chomp, value_chomp);

		// set the remaining bytes
		dst_byte = (pbyte)dst_chomp;
		ijk_memory_set(dst_byte, end_byte, value);

		// done
		return dst;
	}
	return 0;
}


ijk_inl ptr ijkMemorySetZero(ptr const dst, size const sz_bytes)
{
	return ijkMemorySet(dst, sz_bytes, 0);
}


ijk_inl ptr ijkMemoryCopy(ptr const dst, kptr const src, size const sz_bytes)
{
	if (dst && src && sz_bytes)
	{
		pchomp dst_chomp = (pchomp)dst;
		kpchomp src_chomp = (pchomp)src;
		pbyte dst_byte = (pbyte)dst;
		kpbyte src_byte = (pbyte)src;
		kpchomp const end_chomp = dst_chomp + sz_bytes / szchomp;
		kpbyte const end_byte = dst_byte + sz_bytes;

		// copy integers until the last integer can fit
		ijk_memory_copy(dst_chomp, src_chomp, end_chomp);

		// copy the remaining bytes
		dst_byte = (pbyte)dst_chomp;
		src_byte = (pbyte)src_chomp;
		ijk_memory_copy(dst_byte, src_byte, end_byte);

		// done
		return dst;
	}
	return 0;
}


ijk_inl pdiff ijkMemoryCompare(kptr const dst, kptr const src, size const sz_bytes)
{
	if (dst && src && sz_bytes)
	{
		kpchomp dst_chomp = (pchomp)dst;
		kpchomp src_chomp = (pchomp)src;
		kpbyte dst_byte = (pbyte)dst, base = dst_byte;
		kpbyte src_byte = (pbyte)src;
		kpchomp const end_chomp = dst_chomp + sz_bytes / szchomp;
		kpbyte const end_byte = dst_byte + sz_bytes;

		// compare integers until the last integer can be compared
		ijk_memory_compare(dst_chomp, src_chomp, end_chomp);

		// compare the remaining bytes
		dst_byte = (pbyte)dst_chomp;
		src_byte = (pbyte)src_chomp;
		ijk_memory_compare(dst_byte, src_byte, end_byte);

		// done
		return (dst_byte - base);
	}
	return ijk_fail_invalidparams;
}


ijk_inl ptr ijkMemorySetC(ptr const dst, size const sz_chomps, chomp const value)
{
	if (dst && sz_chomps)
	{
		pchomp dst_chomp = (pchomp)dst;
		kpchomp const end_chomp = dst_chomp + sz_chomps;
		ijk_memory_set(dst_chomp, end_chomp, value);

		// done
		return dst;
	}
	return 0;
}


ijk_inl ptr ijkMemorySetZeroC(ptr const dst, size const sz_chomps)
{
	return ijkMemorySetC(dst, sz_chomps, 0);
}


ijk_inl ptr ijkMemoryCopyC(ptr const dst, kptr const src, size const sz_chomps)
{
	if (dst && src && sz_chomps)
	{
		pchomp dst_chomp = (pchomp)dst;
		kpchomp src_chomp = (pchomp)src;
		kpchomp const end_chomp = dst_chomp + sz_chomps;
		ijk_memory_copy(dst_chomp, src_chomp, end_chomp);

		// done
		return dst;
	}
	return 0;
}


ijk_inl pdiff ijkMemoryCompareC(kptr const dst, kptr const src, size const sz_chomps)
{
	if (dst && src && sz_chomps)
	{
		kpchomp dst_chomp = (pchomp)dst, base = dst_chomp;
		kpchomp src_chomp = (pchomp)src;
		kpchomp const end_chomp = dst_chomp + sz_chomps;
		ijk_memory_compare(dst_chomp, src_chomp, end_chomp);

		// done
		return (dst_chomp - base);
	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------


#endif	// !_IJK_MEMORY_INL_
#endif	// _IJK_MEMORY_H_