/*
 *  stdio/fread.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include "stdio_loc.h"

size_t fread(void * ptr, size_t size, size_t nobj, FILE *stream)
{
	int tmp_len, done, c;
	char *buf = (char*) ptr;

	tmp_len = size * nobj;
	if (!tmp_len)
		return 0;

	while (tmp_len--) {
		c = fgetc(stream);
		if (c == EOF)
			break;
		*buf++ = c;
		done++;
	}

	return done / size;
}
