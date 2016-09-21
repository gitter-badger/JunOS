/*
 *  stdio/fputs.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include "stdio_loc.h"

int fputs(const char *s, FILE *stream)
{
	char *ts = (char*) s;
	int i = 0;
	int r;

	while (*ts) {
		r = fputc(*ts++, stream);
		i++;
		if (r == EOF)
			return 0;
	}
	
	return i;
}
