/*
 *  string/strlen.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <string.h>

#ifdef _STRLEN
size_t strlen(const char *s)
{
	char *p = (char*) s;
	while (*p)
		p++;
	return (size_t) (p - s);
}
#endif

#ifdef _STRNLEN
size_t strnlen(const char *s, size_t n)
{
	char *t = (char *)s;

	while (n-- && *t)
		t++;
	return (t - s);
}
#endif
