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
typedef	  signed	char					i8, sbyte;
typedef	  signed	short					i16;
typedef	  signed	long					i32;
typedef	  signed	long long				i64;
typedef	unsigned	char					ui8, byte, ubyte;
typedef	unsigned	short					ui16, word;
typedef	unsigned	long					ui32, dword;
typedef	unsigned	long long				ui64, qword;
typedef				float					f32, flt;
typedef				double					f64, dbl;
#define				szbyte					((size)sizeof(byte))
#define				szword					((size)sizeof(word))
#define				szdword					((size)sizeof(dword))
#define				szqword					((size)sizeof(qword))
#define				szflt					((size)sizeof(flt))
#define				szdbl					((size)sizeof(dbl))


// core pointer type abbreviations
///
typedef				void					* ptr, * addr;
typedef				void const				* kptr, * kaddr;
#define				szaddr					((size)sizeof(addr))


// convenient types sized for current architecture
///
typedef				ijk_tokencat_arch( i)	flag, ptrdiff, schomp, itr, index;
typedef				ijk_tokencat_arch(ui)	size, chomp, uchomp, uitr, uindex;
#define				szchomp					((size)sizeof(chomp))


// convenient short c-string type abbreviations
///
typedef				byte					tag[szaddr * szqword], * ptag;
typedef				byte const				* kptag;
#define				sztag					((size)sizeof(tag))


// convenient short wide-character string type abbreviations
///
typedef				word					wtag[sztag], * pwtag;
typedef				word const				* kpwtag;
#define				szwtag					((size)sizeof(wtag))


#endif	// !_IJK_TYPEDEFS_H_