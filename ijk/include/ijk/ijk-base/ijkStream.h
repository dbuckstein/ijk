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
#define ijk_warn_stream_incomplete	ijk_warncode(1)


// ijkStream
//	Stream descriptor.
//		member base: pointer to base of stream contents
//		member head: pointer to current content head
//		member length: length of contents
//		member isRead: flag whether interface is used for reading
//		member isFile: flag whether interface is used for file streaming
struct ijkStream
{
	pbyte base;							// stream contents
	pbyte head;							// content head
	size length;						// length of contents
	ibool isRead;						// read flag
	ibool isFile;						// file flag
};


// ijkStreamReadFunc
//	Read function type for stream interface. Any function returning integer 
//	and taking a stream pointer and one pointer parameter (any type) qualifies.
//	Allows for custom object streaming.
//		param stream: pointer to stream interface
//		param streamArg: pointer representing data to be input
//		return: number of bytes read
typedef iret(*ijkStreamReadFunc)(ijkStream* const stream, ptr streamArg);


// ijkStreamWriteFunc
//	Write function type for stream interface. Any function returning integer 
//	and taking a stream pointer and one constant pointer parameter (any type)
//	qualifies. Allows for custom object streaming.
//		param stream: pointer to stream interface
//		param streamArg: pointer representing constant data to be output
//		return: number of bytes written
typedef iret(*ijkStreamWriteFunc)(ijkStream* const stream, kptr streamArg);


//-----------------------------------------------------------------------------

// ijkStreamCreateFile
//	Open file for read/write.
//		param stream_out: pointer to stream descriptor
//			valid: non-null, uninitialized
//		param filePath: relative or absolute path to file to open
//			valid: non-null, non-empty c-string
//		param readMode: open file for reading if true, otherwise for writing
//		return SUCCESS: ijk_success if file opened
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if file not opened
iret ijkStreamCreateFile(ijkStream* const stream_out, kcstr const filePath, ibool const readMode);

// ijkStreamCreateBuffer
//	Allocate empty string for writing.
//		param stream_out: pointer to stream descriptor
//			valid: non-null, uninitialized
//		param buffSize: size of buffer in bytes
//			valid: non-zero
//		param readSource: source data to copy from for reading
//			note: non-null for reading, null for writing
//		return SUCCESS: ijk_success if buffer allocated
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if buffer not allocated
iret ijkStreamCreateBuffer(ijkStream* const stream_out, size const buffSize, kcstr const readSource);

// ijkStreamLoadBuffer
//	Allocate buffer from file for reading.
//		param stream_out: pointer to stream descriptor
//			valid: non-null, uninitialized
//		param filePath: relative or absolute path to file to load
//			valid: non-null, non-empty c-string
//		return SUCCESS: ijk_success if file loaded
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if file not loaded
iret ijkStreamLoadBuffer(ijkStream* const stream_out, kcstr const filePath);

// ijkStreamSaveBuffer
//	Store buffer in file.
//	Allocate buffer from file for reading.
//		param stream: pointer to constant stream descriptor
//			valid: non-null, initialized, file mode disabled
//		param filePath: relative or absolute path to file to save
//			valid: non-null, non-empty c-string
//		return SUCCESS: ijk_success if file saved
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if file not saved
iret ijkStreamSaveBuffer(ijkStream const* const stream, kcstr const filePath);

// ijkStreamGetOffset
//	Get number of bytes streamed.
//		param stream: pointer to constant stream descriptor
//			valid: non-null, initialized
//		param offset_out: pointer to value representing offset
//			valid: non-null
//		return SUCCESS: ijk_success if retrieved number of bytes streamed
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if did not get value
iret ijkStreamGetOffset(ijkStream const* const stream, size* const offset_out);

// ijkStreamBufferReset
//	Reset buffer head.
//		param stream: pointer to stream descriptor
//			valid: non-null, initialized, file mode disabled
//		param readMode: reset in read mode if true, otherwise write
//		return SUCCESS: ijk_success if stream reset
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkStreamBufferReset(ijkStream* const stream, ibool const readMode);

// ijkStreamRelease
//	Close file or release string contents.
//		param stream: pointer to stream descriptor
//			valid: non-null, initialized
//		return SUCCESS: ijk_success if stream released
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if stream not released
iret ijkStreamRelease(ijkStream* const stream);

// ijkStreamRead
//	Read from stream using callback.
//		param stream: pointer to stream descriptor
//			valid: non-null, initialized
//		param streamFunc: pointer to read callback
//			valid: non-null
//		param streamArg: pointer to data to stream
//			valid: non-null
//		param bytes_opt: optional pointer to value holding number of bytes 
//			read; used for caller validation
//		return SUCCESS: ijk_success if read succeeded
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if read failed
iret ijkStreamRead(ijkStream* const stream, ijkStreamReadFunc const streamFunc, ptr streamArg, size* const bytes_opt);

// ijkStreamWrite
//	Write to stream using callback.
//		param stream: pointer to stream descriptor
//			valid: non-null, initialized
//		param streamFunc: pointer to write callback
//			valid: non-null
//		param streamArg: pointer to constant data to stream
//			valid: non-null
//		param bytes_opt: optional pointer to value holding number of bytes 
//			written; used for caller validation
//		return SUCCESS: ijk_success if write succeeded
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if write failed
iret ijkStreamWrite(ijkStream* const stream, ijkStreamWriteFunc const streamFunc, kptr streamArg, size* const bytes_opt);


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
//		param elemCount: number of elements to read
//			valid: non-zero
//		param bytes_opt: optional pointer to value holding number of bytes 
//			read; used for caller validation
//		return SUCCESS: ijk_success if read expected number of bytes
//		return WARNING: ijk_warn_stream_incomplete if did not read all bytes
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if read failed
iret ijkStreamReadElement(ijkStream* const stream, ptr const elem, size const elemSize, size const elemCount, size* const bytes_opt);

// ijkStreamWriteElement
//	Write single element to stream.
//		param stream: pointer to stream descriptor.
//			valid: non-null, initialized, read flag disabled
//			note: writes to file if file flag is raised
//		param elem: pointer to constant element to write
//			valid: non-null
//		param elemSize: size of element
//			valid: non-zero
//		param elemCount: number of elements to write
//			valid: non-zero
//		param bytes_opt: optional pointer to value holding number of bytes 
//			written; used for caller validation
//		return SUCCESS: ijk_success if wrote expected number of bytes
//		return WARNING: ijk_warn_stream_incomplete if did not write all bytes
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if write failed
iret ijkStreamWriteElement(ijkStream* const stream, kptr const elem, size const elemSize, size const elemCount, size* const bytes_opt);


//-----------------------------------------------------------------------------

// ijkStreamMakeDirectory
//	Make a directory.
//		param directory: relative or absolute path of directory to create
//			valid: non-null, non-empty c-string
//		return SUCCESS: ijk_success if directory created
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if directory creation failed
iret ijkStreamMakeDirectory(kcstr const directory);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#include "_inl/ijkStream.inl"


#endif	// !_IJK_STREAM_H_