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

ijk_inl pdiff ijkMemoryGetStringLength(kstr s)
{
	if (s)
	{
		// iterate through characters until nul-terminator
		kstr const first = s;
		while (*s)
			++s;
		return (s - first);
	}
	return ijk_fail_invalidparams;
}

ijk_inl pdiff ijkMemoryCompareStrings(kstr s0, kstr s1)
{
	if (s0 && s1)
	{
		// iterate through characters until either mismatch or nul-terminator
		kstr const first0 = s0, first1 = s1;
		while (*(s0++) == *s1)
			if (!*(s1++))
				return 0;
		return (s0 - first0);
	}
	return ijk_fail_invalidparams;
}

ijk_inl pdiff ijkMemoryGetPointerArrayElems(kptr const* arr)
{
	if (arr)
	{
		// iterate until null pointer
		kptr const* const first = arr;
		while (*arr)
			++arr;
		return (arr - first);
	}
	return ijk_fail_invalidparams;
}

ijk_inl pdiff ijkMemoryGetPointerArrayElemsMax(kptr const* arr, pdiff const len)
{
	if (arr && len > 0)
	{
		// iterate until limit exceeded or null pointer
		kptr const* const first = arr, *const end = arr + len;
		while ((arr < end) && *arr)
			++arr;
		return (arr - first);
	}
	return ijk_fail_invalidparams;
}

ijk_inl pdiff ijkMemoryGetStringIndex(kstr const key, kstr const* arr)
{
	if (arr)
	{
		// iterate until matching string found or null pointer
		kstr const* const first = arr;
		while (*arr)
		{
			if (!ijkMemoryCompareStrings(*arr, key))
				return (arr - first);
			++arr;
		}
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}

ijk_inl pdiff ijkMemoryGetStringIndexMax(kstr const key, kstr const* arr, pdiff const len)
{
	if (arr && len > 0)
	{
		// iterate until matching string, null pointer or limit reached
		kstr const* const first = arr, *const end = arr + len;
		while ((arr < end) && *arr)
		{
			if (!ijkMemoryCompareStrings(*arr, key))
				return (arr - first);
			++arr;
		}
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}

ijk_inl pdiff ijkMemoryStoreString(kstr const key, kstr* const arr_dst, pdiff* const len_dst_inout, kstr const* arr_src, pdiff const len_src)
{
	pdiff n = ijkMemoryGetStringIndexMax(key, arr_dst, *len_dst_inout);
	if (n < ijk_fail_invalidparams)
	{
		// search for string in source list, add to target list if found
		if ((n = ijkMemoryGetStringIndexMax(key, arr_src, len_src)) >= 0)
			arr_dst[(*len_dst_inout)++] = arr_src[n];
	}
	return n;
}

ijk_inl pdiff ijkMemoryStoreStringList(kstr* const arr_dst, pdiff* const len_dst_inout, kstr const* arr_src, pdiff const len_src)
{
	if (arr_src && len_src > 0)
	{
		kstr const* const first = arr_src, * const end = arr_src + len_src;
		while (arr_src < end)
		{
			// search for each string in target list, add if not found
			if (ijkMemoryGetStringIndexMax(*arr_src, arr_dst, *len_dst_inout) < ijk_fail_invalidparams)
				arr_dst[(*len_dst_inout)++] = *arr_src;
			++arr_src;
		}
		return *len_dst_inout;
	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------


#endif	// !_IJK_MEMORY_INL_
#endif	// _IJK_MEMORY_H_