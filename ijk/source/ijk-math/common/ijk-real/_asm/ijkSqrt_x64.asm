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

	ijkSqrt_a.asm
	Assembly definitions for fast square root in 64-bit (x64).
*/
@

;//////////////////////////////////////////////////////////////////////////////
; 64-bit defined if rax register exists
IFDEF RAX


.data
one				EQU			1.0			; effectively the same as define
fs1				dd			one			; constant single (float) set to 1
fd1				dq			one			; constant double set to 1


.code

; sqrt (float)
; simple sqrt call
ijkSqrt_flt PROC
	sqrtss		xmm0,		xmm0		; do scalar single sqrt on xmm0 (already contains arg from function setup)
	ret									; exit function
ijkSqrt_flt ENDP


; sqrt inverse (float)
; rsqrtss is handy (one line) but does not give correct result
; nor does rcpss with reciprocal of square root; better with recip first
; need to do reciprocal of square root manually
ijkSqrtInv_flt PROC
	movss		xmm1,		[fs1]		; copy constant to register xmm1
	divss		xmm1,		xmm0		; do reciprocal of xmm0, store in xmm1
	sqrtss		xmm0,		xmm1		; do scalar single sqrt on xmm1 -> xmm0
	ret									; exit
ijkSqrtInv_flt ENDP


; cbrt (float)
; use power/logarithm to compute
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
; simple sqrt call
ijkSqrt_dbl PROC
	sqrtsd		xmm0,		xmm0		; do scalar double sqrt on xmm0
	ret									; exit function
ijkSqrt_dbl ENDP


; sqrt inverse (double)
ijkSqrtInv_dbl PROC
	movsd		xmm1,		[fd1]		; copy constant to register xmm1
	divsd		xmm1,		xmm0		; do reciprocal of xmm0, store in xmm1
	sqrtsd		xmm0,		xmm1		; do scalar double sqrt on xmm1 -> xmm0
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
; 32-bit if no rax register
ELSE	; !RAX


;//////////////////////////////////////////////////////////////////////////////
; done
ENDIF


; required at end (no newline)
END