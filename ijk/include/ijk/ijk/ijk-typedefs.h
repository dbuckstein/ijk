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

	ijk-typedefs.h
	Common shorthand type definitions.
*/

#ifndef _IJK_TYPEDEFS_H_
#define _IJK_TYPEDEFS_H_


#include "ijk-macros.h"


// core integer and floating point type abbreviations
///
typedef	  signed	char					i8, sbyte, asciicode;
typedef	  signed	short					i16;
typedef	  signed	long					i32, iret, ibool, istate;
typedef	  signed	long long				i64, intl;
typedef	unsigned	char					ui8, byte, ubyte, keycode;
typedef	unsigned	short					ui16, word;
typedef	unsigned	long					ui32, dword, uint;
typedef	unsigned	long long				ui64, qword, uintl;
typedef				float					f32, flt, single;
typedef				double					f64, dbl;


// convenient types sized for current architecture
///
typedef				ijk_tokencat_arch( i)	ptrdiff, schomp, itr, index, flag;
typedef				ijk_tokencat_arch(ui)	chomp, uchomp, uitr, uindex, size;


// core pointer type abbreviations
///
typedef				void					* ptr, * addr;
typedef				void const				* kptr, * kaddr;
typedef				byte					* pbyte, * cstr;
typedef				byte const				* kpbyte, * kcstr;
typedef				chomp					* pchomp, * cbuff;
typedef				chomp const				* kpchomp, * kcbuff;


// convenient size abbreviations for byte and chomp
///
#define				szb(x)					(size)sizeof(x)
#define				szbyte					szb(byte)
#define				szchomp					szb(chomp)
#define				szindex					szb(index)
#define				ijk_b2c(b)				(((b)+szchomp-1)/szchomp)
#define				ijk_c2b(c)				((c)*szchomp)
#define				szc(x)					ijk_b2c(szb(x))


// convenient size abbreviations for other types
///
#define				szword					szb(word)
#define				szdword					szb(dword)
#define				szqword					szb(qword)
#define				szflt					szb(flt)
#define				szdbl					szb(dbl)
#define				szaddr					szb(addr)


// convenient short c-string type abbreviations
///
typedef				byte					tag[szdword * szqword], * ptag;
typedef				byte const				* kptag;
#define				sztag					szb(tag)


// convenient short wide-character string type abbreviations
///
typedef				word					wtag[sztag], * pwtag, * wcstr;
typedef				word const				* kpwtag, * kwcstr;
#define				szwtag					szb(wtag)


// convenient short dynamic (architecture-dependent) c-string abbreviations
///
typedef				byte					dtag[szchomp * szqword];
#define				szdtag					szb(dtag)
typedef				word					dwtag[szdtag];
#define				szdwtag					szb(dwtag)


// simple copy operations
///
#define ijk_copyb(dst, src, offset)			(*((byte*)(dst) + (offset)) = *((byte const *)(src) + (offset)))
#define ijk_copyw(dst, src, offset)			(*((word*)(dst) + (offset)) = *((word const *)(src) + (offset)))
#define ijk_copydw(dst, src, offset)		(*((dword*)(dst) + (offset)) = *((dword const*)(src) + (offset)))
#define ijk_copyqw(dst, src, offset)		(*((qword*)(dst) + (offset)) = *((qword const*)(src) + (offset)))
#define ijk_copyc(dst, src, offset)			(*((chomp*)(dst) + (offset)) = *((chomp const*)(src) + (offset)))
#define ijk_copytag(dst, src)				ijk_copyqw(dst,src,0);ijk_copyqw(dst,src,1);ijk_copyqw(dst,src,2);ijk_copyqw(dst,src,3)
#define ijk_copywtag(dst, src)				ijk_copytag((ptag)(dst),(kptag)(src));ijk_copytag((ptag)(dst)+sztag,(kptag)(src)+sztag)


#ifndef __cplusplus
// missing C type for boolean
///
typedef byte bool;
#endif	// !__cplusplus


#endif	// !_IJK_TYPEDEFS_H_