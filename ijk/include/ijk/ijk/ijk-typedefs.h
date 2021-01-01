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

	ijk-typedefs.h
	Common shorthand type definitions.
*/

#ifndef _IJK_TYPEDEFS_H_
#define _IJK_TYPEDEFS_H_


#include "ijk-macros.h"


// Core integer and floating point type abbreviations and aliases.
///
typedef	  signed	char					i8, sbyte, asciicode;		// Alias for signed single byte.
typedef	  signed	short					i16;						// Alias for signed short integer/word (two bytes).
typedef	  signed	long					i32, iret, ibool, istate;	// Alias for signed long integer/double-word (four bytes).
typedef	  signed	long long				i64, intl;					// Alias for signed long-long integer/quad-word (eight bytes).
typedef	unsigned	char					ui8, byte, ubyte, keycode;	// Alias for unsigned single byte.
typedef	unsigned	short					ui16, word;					// Alias for unsigned short integer/word (two bytes).
typedef	unsigned	long					ui32, dword, uint;			// Alias for unsigned long integer/double-word (four bytes).
typedef	unsigned	long long				ui64, qword, uintl;			// Alias for unsigned long-long integer/quad-word (eight bytes).
typedef				float					f32, flt, single;			// Alias for signed single-precision floating point number (four bytes).
typedef				double					f64, dbl;					// Alias for signed double-precision floating point number (eight bytes).


// Convenient types sized for current architecture.
///
typedef				ijk_tokencat_arch( i)	ptrdiff, schomp, itr, index, flag;	// Aliases based on signed integer that has same size as pointer.
typedef				ijk_tokencat_arch(ui)	chomp, uchomp, uitr, uindex, size;	// Aliases based on unsigned integer that has same size as pointer.


// Core pointer type abbreviations and aliases.
///
typedef				void					* ptr, * addr;			// Alias for generic pointer.
typedef				void const				* kptr, * kaddr;		// Alias for generic pointer to constant.
typedef				byte					* pbyte, * cstr;		// Alias for pointer to byte, or a c-string.
typedef				byte const				* kpbyte, * kcstr;		// Alias for pointer to constant byte, or a constant c-string.
typedef				chomp					* pchomp, * cbuff;		// Alias for pointer to integer that has same size as pointer.
typedef				chomp const				* kpchomp, * kcbuff;	// Alias for pointer to constant integer that has same size as pointer.


// Convenient size abbreviations for byte and chomp (integer that has same size as pointer).
///
#define				szb(x)					(size)sizeof(x)				// Get size in bytes.
#define				szbyte					szb(byte)					// Get size of byte (1).
#define				szchomp					szb(chomp)					// Get size of chomp (4 in 32-bit, 8 in 64-bit).
#define				szindex					szb(index)					// Get size of index (4 in 32-bit, 8 in 64-bit).
#define				ijk_b2c(b)				(((b)+szchomp-1)/szchomp)	// Convert size in bytes to size in chomps (4:1 or 8:1).
#define				ijk_c2b(c)				((c)*szchomp)				// Convert size in chomps to size in bytes (1:4 or 1:8).
#define				szc(x)					ijk_b2c(szb(x))				// Get size in chomps (integer that has same size as pointer).


// Convenient size abbreviations for other types.
///
#define				szword					szb(word)					// Get size of short/word in bytes (2).
#define				szdword					szb(dword)					// Get size of long/double-word in bytes (4).
#define				szqword					szb(qword)					// Get size of long-long/quad-word in bytes (8).
#define				szflt					szb(flt)					// Get size of single-precision float in bytes (4).
#define				szdbl					szb(dbl)					// Get size of double-precision float in bytes (8).
#define				szaddr					szb(addr)					// Get size of pointer in bytes (4 in 32-bit, 8 in 64-bit).


// Convenient short c-string and wide character string type abbreviations and aliases.
///
typedef				byte					tag[szdword * szqword], * ptag;		// Alias for tag or short name made of bytes.
typedef				byte const				ktag[szdword * szqword], * kptag;	// Alias for constant tag or short name made of bytes.
#define				sztag					szb(tag)							// Get size of tag in bytes (32).
typedef				word					wtag[sztag], * pwtag, * wcstr;		// Alias for wide tag or short name made of short integers.
typedef				word const				kwtag[sztag], * kpwtag, * kwcstr;	// Alias for constant wide tag or short name made of short integers.
#define				szwtag					szb(wtag)							// Get size of wide tag in bytes (64).


// Convenient short dynamic (architecture-dependent) c-string abbreviations and aliases.
///
typedef				byte					dtag[szchomp * szqword], * pdtag, * dcstr;		// Alias for dynamic tag whose size is dependent on architecture.
typedef				byte const				kdtag[szchomp * szqword], * kpdtag, * kdcstr;	// Alias for constant dynamic tag whose size is dependent on architecture.
#define				szdtag					szb(dtag)										// Get size of dynamic tag (same as architecture bits).
typedef				word					dwtag[szdtag], * pdwtag, * dwcstr;				// Alias for wide dynamic tag whose size is dependent on architecture.
typedef				word const				kdwtag[szdtag], * kpdwtag, * kdwcstr;			// Alias for constant wide dynamic tag whose size is dependent on architecture.
#define				szdwtag					szb(dwtag)										// Get size of wide dynamic tag (double architecture bits).


// Simple copy operations.
///
#define ijk_copyb(dst, src, offset)			(*((byte*)(dst) + (offset)) = *((byte const *)(src) + (offset)))	// Copy single byte from src to dst at offset.
#define ijk_copyw(dst, src, offset)			(*((word*)(dst) + (offset)) = *((word const *)(src) + (offset)))	// Copy word from src to dst at offset.
#define ijk_copydw(dst, src, offset)		(*((dword*)(dst) + (offset)) = *((dword const*)(src) + (offset)))	// Copy double-word from src to dst at offset.
#define ijk_copyqw(dst, src, offset)		(*((qword*)(dst) + (offset)) = *((qword const*)(src) + (offset)))	// Copy quad-word from src to dst at offset.
#define ijk_copyc(dst, src, offset)			(*((chomp*)(dst) + (offset)) = *((chomp const*)(src) + (offset)))	// Copy single chomp from src to dst at offset.
#define ijk_copytag(dst, src)				ijk_copyqw(dst,src,0);ijk_copyqw(dst,src,1);ijk_copyqw(dst,src,2);ijk_copyqw(dst,src,3)		// Copy tag from src to dst.
#define ijk_copywtag(dst, src)				ijk_copytag((ptag)(dst),(kptag)(src));ijk_copytag((ptag)(dst)+sztag,(kptag)(src)+sztag)		// Copy wide tag frm src to dst.
#define ijk_copydtag(dst, src)				ijk_copyc(dst,src,0);ijk_copyc(dst,src,1);ijk_copyc(dst,src,2);ijk_copyc(dst,src,3);ijk_copyc(dst,src,4);ijk_copyc(dst,src,5);ijk_copyc(dst,src,6);ijk_copyc(dst,src,7)	// Copy dynamic tag from src to dst.
#define ijk_copydwtag(dst, src)				ijk_copydtag((ptag)(dst),(kptag)(src));ijk_copydtag((ptag)(dst)+szdtag,(kptag)(src)+szdtag)	// Copy wide dynamic tag frm src to dst.


#ifndef __cplusplus
// C-specific aliases.
///
typedef byte	bool;		// Boolean type for C.
#define true	ijk_true	// Boolean true for C.
#define false	ijk_false	// Boolean false for C.
#endif	// !__cplusplus


#endif	// !_IJK_TYPEDEFS_H_