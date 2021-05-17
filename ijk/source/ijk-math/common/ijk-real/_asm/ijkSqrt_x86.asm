COMMENT @
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

	ijkSqrt_x86.asm
	Assembly definitions for fast square root in 32-bit (x86).
*/

/*
	Help: 
	https://stackoverflow.com/questions/4548763/compiling-assembly-in-visual-studio
	http://lallouslab.net/2016/01/11/introduction-to-writing-x64-assembly-in-visual-studio/
	http://rayseyfarth.com/asm/pdf/ch11-floating-point.pdf

	Info: 
	<op>ss	scalar single: one float in the register (quarter of xmm [e.g. xmm0])
	<op>ps	packed single: four floats in the register (all of xmm)
	<op>sd	scalar double: one double in the register (half of xmm)
	<op>pd	packed double: two doubles in the register (all of xmm)
	
	THIS CODE IS ASSEMBLED USING THE ASSEMBLER...
		WINDOWS: masm
		LINUX: nasm, clang, as (new); (could use gas)
		MAC: clang; gcc is deprecated

	Summary: 
		-add ASM file to project
		-right click project > build dependencies > build customizations
		-enable MASM
		-right click ASM file > properties > item type > microsoft macro assembler
*/
@

;//////////////////////////////////////////////////////////////////////////////
; 64-bit defined if rax register exists
IFDEF RAX


;//////////////////////////////////////////////////////////////////////////////
; 32-bit if no rax register
ELSE	; !RAX


.model flat, c
.code


; sqrt (float)
ijkSqrt_flt PROC
	fld			dword ptr	[esp+4]		; load input to float stack (st0) as float (i32 size); arg is 4 bytes past return address (which is ptr size)
	fsqrt								; do sqrt on top of float stack (st0)
	ret									; exit function
ijkSqrt_flt ENDP


; sqrt inverse (float)
ijkSqrtInv_flt PROC
	fld1								; load 1 to float stack (st0)
	fld			dword ptr	[esp+4]		; load input to float stack (st0); pushes previously-loaded value (st0 = 1 -> st1 = 1)
	fdivp								; divide st1 by st0, store in st1 and pop
	fsqrt								; do sqrt on top of stack
	ret									; exit
ijkSqrtInv_flt ENDP


; cbrt (float)
ijkCbrt_flt PROC
										; TO-DO
	ret									; exit
ijkCbrt_flt ENDP


; cbrt inverse (float)
ijkCbrtInv_flt PROC
										; TO-DO
	ret									; exit
ijkCbrtInv_flt ENDP


; sqrt (double)
ijkSqrt_dbl PROC
	fld			qword ptr	[esp+4]		; load input to float stack (st0) as double (i64 size); arg is still 4 bytes past return address (4-byte ptr)
	fsqrt								; do sqrt on top of float stack (st0)
	ret									; exit
ijkSqrt_dbl ENDP


; sqrt inverse (double)
ijkSqrtInv_dbl PROC
	fld1								; load 1 to float stack (st0)
	fld			qword ptr	[esp+4]		; load input to float stack (st0); pushes previously-loaded value (st0 = 1 -> st1 = 1)
	fdivp								; divide st1 by st0, store in st1 and pop
	fsqrt								; do sqrt on top of stack
	ret									; exit
ijkSqrtInv_dbl ENDP


; cbrt (double)
ijkCbrt_dbl PROC
										; TO-DO
	ret									; exit
ijkCbrt_dbl ENDP


; cbrt inverse (double)
ijkCbrtInv_dbl PROC
										; TO-DO
	ret									; exit
ijkCbrtInv_dbl ENDP


;//////////////////////////////////////////////////////////////////////////////
; done
ENDIF


; required at end (no newline)
END