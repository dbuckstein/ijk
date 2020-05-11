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

	ijkStream.h
	Stream utility interface.
*/

#ifndef _IJK_STREAM_H_
#define _IJK_STREAM_H_


#include "ijk/ijk/ijk-typedefs.h"


#ifdef __cplusplus
extern "C" {
#else	// !__cplusplus
typedef struct ijkStream				ijkStream;
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijk_warn_stream_incomplete
//	Stream warning indicating that read/write operation did not fully complete.
#define ijk_warn_stream_incomplete	(ijk_warncode(1))


// ijkStream
//	Stream descriptor.
//		member stream: pointer to stream contents
//		member length: length of contents
//		member offset: offset of stream head
//		member isRead: flag whether interface is used for reading
//		member isFile: flag whether interface is used for file streaming
struct ijkStream
{
	kptr stream;						// stream contents
	size length;						// length of contents
	uitr offset;						// offset of head
	ibool isRead;						// read flag
	ibool isFile;						// file flag
};


// ijkStreamReadFunc
//	Read function type for stream interface. Any function returning integer 
//	and taking a stream pointer and one pointer parameter (any type) qualifies.
//	Allows for custom object streaming.
//		param stream: pointer to stream interface
//		param streamArg: pointer representing data to be input
//		return: any integer (e.g. number of bytes read)
typedef iret(*ijkStreamReadFunc)(ijkStream* const stream, ptr streamArg);


// ijkStreamWriteFunc
//	Write function type for stream interface. Any function returning integer 
//	and taking a stream pointer and one constant pointer parameter (any type)
//	qualifies. Allows for custom object streaming.
//		param stream: pointer to stream interface
//		param streamArg: pointer representing constant data to be output
//		return: any integer (e.g. number of bytes written)
typedef iret(*ijkStreamWriteFunc)(ijkStream* const stream, kptr streamArg);


//-----------------------------------------------------------------------------

// ijkStreamReadElement
//	Read single element from stream.
//		param stream: pointer to stream descriptor.
//			valid: non-null, initialized, read flag enabled
//			note: reads from file if file flag is raised
//		param elem: pointer to element to read
//			valid: non-null
//		param elemSize: size of element
//			valid: non-zero
//		param bytes_opt: optional pointer to value holding number of bytes 
//			read; used for caller validation
//		return SUCCESS: ijk_success if read expected number of bytes
//		return WARNING: ijk_warn_stream_incomplete if did not read all bytes
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if read failed
iret ijkStreamReadElement(ijkStream* const stream, ptr const elem, size const elemSize, size* const bytes_opt);

// ijkStreamWriteElement
//	Write single element to stream.
//		param stream: pointer to stream descriptor.
//			valid: non-null, initialized, read flag disabled
//			note: writes to file if file flag is raised
//		param elem: pointer to constant element to write
//			valid: non-null
//		param elemSize: size of element
//			valid: non-zero
//		param bytes_opt: optional pointer to value holding number of bytes 
//			written; used for caller validation
//		return SUCCESS: ijk_success if wrote expected number of bytes
//		return WARNING: ijk_warn_stream_incomplete if did not write all bytes
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if write failed
iret ijkStreamWriteElement(ijkStream* const stream, kptr const elem, size const elemSize, size* const bytes_opt);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#include "_inl/ijkStream.inl"


#endif	// !_IJK_STREAM_H_