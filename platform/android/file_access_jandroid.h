/*************************************************************************/
/*  file_access_jandroid.h                                               */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                    http://www.godotengine.org                         */
/*************************************************************************/
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/
#ifndef FILE_ACCESS_JANDROID_H
#define FILE_ACCESS_JANDROID_H

#ifndef ANDROID_NATIVE_ACTIVITY

#include "java_glue.h"
#include "os/file_access.h"
class FileAccessJAndroid : public FileAccess {

	static jobject io;
	static jclass cls;

	static jmethodID _file_open;
	static jmethodID _file_get_size;
	static jmethodID _file_seek;
	static jmethodID _file_tell;
	static jmethodID _file_eof;
	static jmethodID _file_read;
	static jmethodID _file_close;

	int id;
	static FileAccess* create_jandroid();


public:

	virtual Error _open(const String& p_path, int p_mode_flags); ///< open a file
	virtual void close(); ///< close a file
	virtual bool is_open() const; ///< true when file is open

	virtual void seek(size_t p_position); ///< seek to a given position
	virtual void seek_end(int64_t p_position=0); ///< seek from the end of file
	virtual size_t get_pos() const; ///< get position in the file
	virtual size_t get_len() const; ///< get size of the file

	virtual bool eof_reached() const; ///< reading passed EOF

	virtual uint8_t get_8() const; ///< get a byte
	virtual int get_buffer(uint8_t *p_dst, int p_length) const;

	virtual Error get_error() const; ///< get last error

	virtual void store_8(uint8_t p_dest); ///< store a byte

	virtual bool file_exists(const String& p_path); ///< return true if a file exists



	static void setup( jobject io);

	virtual uint64_t _get_modified_time(const String& p_file) { return 0; }

	FileAccessJAndroid();
	~FileAccessJAndroid();
};

#endif

#endif // FILE_ACCESS_JANDROID_H
