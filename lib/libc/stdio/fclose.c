/*
 *  stdio/fclose.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include "stdio_loc.h"

int fclose(FILE *stream)
{
	if (!stream)
		return EOF;

	fflush(stream);

	if (stream->_buf){
		free(stream->_buf);
		stream->_buf=NULL;
	}

	stream->_flag=0;
	return close(stream->_fd);
}
