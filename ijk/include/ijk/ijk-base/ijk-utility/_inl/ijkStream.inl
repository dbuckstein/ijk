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

	ijkStream.inl
	Stream utility inline implementation.
*/

#ifdef _IJK_STREAM_H_
#ifndef _IJK_STREAM_INL_
#define _IJK_STREAM_INL_


//-----------------------------------------------------------------------------

ijk_inl iret ijkStreamGetOffset(ijkStream const* const stream, size* const offset_out)
{
	if (stream && offset_out &&
		stream->base)
	{
		*offset_out = (stream->isFile ? stream->length : (stream->head - stream->base));
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkStreamBufferReset(ijkStream* const stream, ibool const readMode)
{
	if (stream &&
		stream->base && ijk_isfalse(stream->isFile))
	{
		stream->head = stream->base;
		stream->isRead = readMode;
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkStreamRead(ijkStream* const stream, ijkStreamReadFunc const streamFunc, ptr streamArg, size* const bytes_opt)
{
	if (stream && streamFunc && streamArg &&
		stream->base)
	{
		size const result = streamFunc(stream, streamArg);
		if (bytes_opt)
			*bytes_opt = result;
		return (result ? ijk_success : ijk_fail_operationfail);
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkStreamWrite(ijkStream* const stream, ijkStreamWriteFunc const streamFunc, kptr streamArg, size* const bytes_opt)
{
	if (stream && streamFunc && streamArg &&
		stream->base)
	{
		size const result = streamFunc(stream, streamArg);
		if (bytes_opt)
			*bytes_opt = result;
		return (result ? ijk_success : ijk_fail_operationfail);
	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------


#endif	// !_IJK_STREAM_INL_
#endif	// _IJK_STREAM_H_