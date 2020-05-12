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
#include <memory.h>


//-----------------------------------------------------------------------------

iret ijkStreamCreateFile(ijkStream* const stream_out, kcstr const filePath)
{
	if (stream_out && filePath && *filePath)
	{
		if (!stream_out->base)
		{

		}
	}
	return ijk_fail_invalidparams;
}


iret ijkStreamCreateBuffer(ijkStream* const stream_out, size const buffSize)
{
	if (stream_out && buffSize)
	{
		if (!stream_out->base)
		{

		}
	}
	return ijk_fail_invalidparams;
}


iret ijkStreamLoadBuffer(ijkStream* const stream_out, kcstr const filePath)
{
	if (stream_out && filePath && *filePath)
	{
		if (!stream_out->base)
		{

		}
	}
	return ijk_fail_invalidparams;
}


iret ijkStreamSaveBuffer(ijkStream const* const stream, kcstr const filePath)
{
	if (stream && filePath && *filePath)
	{
		if (stream->base)
		{

		}
	}
	return ijk_fail_invalidparams;
}


iret ijkStreamRelease(ijkStream* const stream)
{
	if (stream)
	{
		if (stream->base)
		{

		}
	}
	return ijk_fail_invalidparams;
}


iret ijkStreamReset(ijkStream* const stream)
{
	if (stream)
	{
		if (stream->base)
		{

		}
	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------

iret ijkStreamReadElement(ijkStream* const stream, ptr const elem, size const elemSize, size const elemCount, size* const bytes_opt)
{
	// validate parameters
	if (stream && elem && elemSize && elemCount)
	{
		// validate initialized
		if (stream->base && stream->isRead)
		{
			size result = 0;
			size const expected = elemSize * elemCount;
			if (stream->isFile)
			{
				result = fread(elem, elemSize, elemCount, (FILE*)stream->base);
				stream->length += result;
				if (bytes_opt)
					*bytes_opt = result;
			}
			else
			{
				size const offset = stream->head - stream->base;
				size const capacity = stream->length - offset;
				result = ijk_minimum(expected, capacity);
				memcpy(elem, stream->head, result);
				stream->head += result;
				if (bytes_opt)
					*bytes_opt = result;
			}

			// success
			if (result)
				return (result == expected ? ijk_success : ijk_warn_stream_incomplete);

			// failed
			return ijk_fail_operationfail;
		}
	}
	return ijk_fail_invalidparams;
}


iret ijkStreamWriteElement(ijkStream* const stream, kptr const elem, size const elemSize, size const elemCount, size* const bytes_opt)
{
	if (stream && elem && elemSize && elemCount)
	{
		if (stream->base && !stream->isRead)
		{
			size result = 0;
			size const expected = elemSize * elemCount;
			if (stream->isFile)
			{
				result = fwrite(elem, elemSize, elemCount, (FILE*)stream->base);
				stream->length += result;
				if (bytes_opt)
					*bytes_opt = result;
			}
			else
			{
				size const offset = stream->head - stream->base;
				size const capacity = stream->length - offset;
				result = ijk_minimum(expected, capacity);
				memcpy(stream->head, elem, result);
				stream->head += result;
				if (bytes_opt)
					*bytes_opt = result;
			}

			// success
			if (result)
				return (result == expected ? ijk_success : ijk_warn_stream_incomplete);

			// failed
			return ijk_fail_operationfail;
		}
	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------

#if (__ijk_cfg_platform == WINDOWS)
#include <direct.h>
#else	// !WINDOWS
#include <sys/stat.h>
#endif	// WINDOWS


iret ijkStreamMakeDirectory(kcstr const directory)
{
	if (directory && *directory)
	{
		iret const result =
#if (__ijk_cfg_platform == WINDOWS)
			_mkdir(directory);
#else	// !WINDOWS
			mkdir(directory, 0700);
#endif	// WINDOWS
		return (result * 2);
	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------
