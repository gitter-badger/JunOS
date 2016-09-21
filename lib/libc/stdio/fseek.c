/*
 *  stdio/fseek.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include "stdio_loc.h"

int fseek(FILE *stream, off_t offset, int where)
{
	if(!stream)
		return EOF;

	fflush(stream);

	return lseek(stream->_fd, offset, where);
}
