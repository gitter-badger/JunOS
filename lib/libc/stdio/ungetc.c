/*
 *  stdio/ungetc.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include "stdio_loc.h"

int ungetc(int c, FILE *stream)
{
	if (!stream)
		return EOF;
	if (!(stream->_flag & READING))
		return EOF;
	if (!stream->_buf)
		return EOF;
	if (stream->_ptr <= stream->_buf)
		return EOF;

	stream->_cnt++;
	*--stream->_ptr = c;

	return c;
}
