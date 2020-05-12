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

#include "ijk/ijk-base/ijk-utility/ijkStream.h"

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>


//-----------------------------------------------------------------------------

iret ijkStreamCreateFile(ijkStream* const stream_out, kcstr const filePath, ibool const readMode)
{
	if (stream_out && filePath && *filePath)
	{
		if (!stream_out->base)
		{
			FILE* const fp = fopen(filePath, (readMode ? "rb" : "wb"));
			if (fp)
			{
				stream_out->base = (pbyte)fp;
				stream_out->head = 0;
				stream_out->length = 0;
				stream_out->isRead = readMode;
				stream_out->isFile = ijk_true;

				// opened file
				return ijk_success;
			}

			// failed
			return ijk_fail_operationfail;
		}
	}
	return ijk_fail_invalidparams;
}


iret ijkStreamCreateBuffer(ijkStream* const stream_out, size const buffSize, kcstr const readSource)
{
	if (stream_out && buffSize)
	{
		if (!stream_out->base)
		{
			// allocate
			stream_out->base = (pbyte)malloc(buffSize);
			if (stream_out->base)
			{
				stream_out->head = stream_out->base;
				stream_out->length = buffSize;
				stream_out->isFile = ijk_false;
				if (readSource)
				{
					memcpy(stream_out->base, readSource, buffSize);
					stream_out->isRead = ijk_true;
				}
				else
				{
					memset(stream_out->base, 0, buffSize);
					stream_out->isRead = ijk_false;
				}

				// success
				return ijk_success;
			}

			// failed
			return ijk_fail_operationfail;
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
			size result = 0;
			FILE* const fp = fopen(filePath, "rb");
			if (fp)
			{
				fseek(fp, 0, SEEK_END);
				result = (size)ftell(fp);
				if (result)
				{
					// allocate and read from beginning
					stream_out->base = (pbyte)malloc(result + 1);
					fread(stream_out->base, result, 1, fp);
					stream_out->base[result] = 0;
					stream_out->head = stream_out->base;
					stream_out->length = result;
					stream_out->isRead = ijk_true;
					stream_out->isFile = ijk_false;
				}

				// done
				fclose(fp);

				// if loaded contents, success
				if (result)
					return ijk_success;
			}

			// failed
			return ijk_fail_operationfail;
		}
	}
	return ijk_fail_invalidparams;
}


iret ijkStreamSaveBuffer(ijkStream const* const stream, kcstr const filePath)
{
	if (stream && filePath && *filePath)
	{
		if (stream->base && ijk_isfalse(stream->isFile))
		{
			FILE* const fp = fopen(filePath, "wb");
			if (fp)
			{
				// write data
				fwrite(stream->base, stream->length, 1, fp);

				// done
				fclose(fp);
				return ijk_success;
			}

			// failed
			return ijk_fail_operationfail;
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
			if (stream->isFile)
			{
				iret const result = fclose((FILE*)stream->base);
				if (ijk_issuccess(result))
					stream->base = 0;
				return result;
			}
			else
			{
				free(stream->base);
				stream->base = 0;
				stream->head = 0;
				return ijk_success;
			}

			// failed
			return ijk_fail_operationfail;
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
