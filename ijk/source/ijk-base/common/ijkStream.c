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

	ijkStream.c
	Stream utility implementation.
*/

#include "ijk/ijk-base/ijkStream.h"

#include <stdio.h>
#include <stdlib.h>


//-----------------------------------------------------------------------------

iret ijkStreamReadElement(ijkStream* const stream, ptr const elem, size const elemSize, size* const bytes_opt)
{
	// validate parameters
	if (stream && elem)
	{
		// validate initialized
		if (stream->stream && stream->isRead)
		{
			if (stream->isFile)
			{

			}
			else
			{

			}

			// failed
			return ijk_fail_operationfail;
		}
	}
	return ijk_fail_invalidparams;
}


iret ijkStreamWriteElement(ijkStream* const stream, kptr const elem, size const elemSize, size* const bytes_opt)
{
	if (stream && elem)
	{
		if (stream->stream && !stream->isRead)
		{
			if (stream->isFile)
			{

			}
			else
			{

			}

			// failed
			return ijk_fail_operationfail;
		}
	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------
