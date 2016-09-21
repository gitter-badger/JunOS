/*
 *  stdio/fflush.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include "stdio_loc.h"

int fflush(FILE *stream)
{

	if (!stream){
		for (int i = 0; i < MAX_OPEN; i++)
			if (__iotab[i]._flag)
				fflush(&__iotab[i]);
	}

	if (stream->_flag & WRITING) {
		int size = stream->_ptr - stream->_buf;
		if (size && (write(stream->_fd, stream->_buf, size) != size)) {
			stream->_flag |= _IOERR;
		}
	}

	stream->_cnt = 0;
	stream->_ptr = stream->_buf;
	stream->_flag &= ~(READING | WRITING);

	return 0;
}
