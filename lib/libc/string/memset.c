/*
 *  string/memset.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <string.h>

void *memset(void *s, int c, size_t n)
{
	char *t = (char*) s;

	while (n--)
		*t++ = c;
	return s;
}
