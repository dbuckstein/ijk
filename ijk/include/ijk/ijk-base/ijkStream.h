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
//		param stream: pointer to stream interface
//		param streamArg: pointer representing data to be input
//		return: any integer (e.g. number of bytes read)
typedef iret(*ijkStreamReadFunc)(ijkStream* const stream, ptr streamArg);


// ijkStreamWriteFunc
//	Write function type for stream interface. Any function returning integer 
//	and taking a stream pointer and one constant pointer parameter (any type)
//	qualifies.
//		param stream: pointer to stream interface
//		param streamArg: pointer representing constant data to be output
//		return: any integer (e.g. number of bytes written)
typedef iret(*ijkStreamWriteFunc)(ijkStream* const stream, kptr streamArg);


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#include "_inl/ijkStream.inl"


#endif	// !_IJK_STREAM_H_