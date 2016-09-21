/*
 *  string/memchr.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <string.h>

#ifdef _MEMCHR
void * memchr(const void * buf, int chr, size_t n)
{
	char *s = (char *) buf;

	while (--n && *s != chr) {
		s++;
	}

	return n ? s : NULL;
}
#endif

#ifdef _MEMRCHR
void* memrchr(const void *s, int c, size_t n)
{
	char* t = (char*) s;
	char* last = 0;

	for (int i = n; i; --i) {
		if (*t == c)
			last = t;
		++t;
	}
	return (void*) last;
}
#endif
