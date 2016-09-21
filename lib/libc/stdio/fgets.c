/*
 *  stdio/fgets.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include "stdio_loc.h"

char * fgets(char * buf, size_t n, FILE *stream)
{
	int c;
	char *p = buf;

	while (n-- && (c = fgetc(stream)) != EOF ) {
		*p++ = c;
		if (c == '\n')
			break;
	}

	if (feof(stream))
		return NULL;

	if(n)
		*p=0;
	return (p == buf) ? NULL : buf;
}
