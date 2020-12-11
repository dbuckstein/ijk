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

	ijkWindowUnlockPDB_win.c
	Internal utility to force PDB to unlock; it requires some sort of "hand 
	slap" to get rid of it when using the hot-build-and-load feature.
*/

/*
	Recycled from Daniel Buckstein's framework animal3D.
	Contributions from Summer Softleigh, Alex West and Avery Dibble.

	PDB error: https://stackoverflow.com/questions/28016220/how-do-you-generate-new-pdb-files-every-build-in-visual-studio-2013
	PDB release: https://blog.molecular-matters.com/2017/05/09/deleting-pdb-files-locked-by-visual-studio/
	PDB release example by Summer Softleigh (@xKamuna): https://pastebin.com/Jtwi5Dvz
	PDB release fixes by Alex West & Avery Dibble

	Summer's references:
	Info on 'File' string https://forum.sysinternals.com/enumerating-file-handles-question_topic23264.html
	Raymon Chen: https://blogs.msdn.microsoft.com/oldnewthing/20120217-00/?p=8283/
	blez https://blez.wordpress.com/2012/09/17/enumerating-opened-handles-from-a-process/
	wj32 https://forum.sysinternals.com/howto-enumerate-handles_topic18892.html
*/

#include "ijk/ijk/ijk-typedefs.h"
#if ijk_platform_is(WINDOWS)

#include <Windows.h>


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------


#endif	// WINDOWS