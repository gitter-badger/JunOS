/*
 *  string/memcpy.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <string.h>

#ifdef _MEMCPY
void * memcpy(void *dst, const void *src, size_t n)
{
	char *d = (char*) dst;
	char *s = (char*) src;

	while (n--)
		*d++ = *s++;

	return dst;
}
#endif

#ifdef _MEMCCPY
void *memccpy(void *dst, const void *src, int c, size_t count)
{
	char *a = dst;
	char *b = (char *)src;

	while (count--) {
		*a++ = *b;
		if (*b == c) {
			return (void *) a;
		}
		b++;
	}
	return 0;
}
#endif
