COMMENT @
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

	ijkSqrt_a.asm
	Assembly definitions for fast square root in all possible configurations.
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



;//////////////////////////////////////////////////////////////////////////////



;//////////////////////////////////////////////////////////////////////////////


; required at end (no newline)
END