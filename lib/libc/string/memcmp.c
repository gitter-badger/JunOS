/*
 *  string/memcmp.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <string.h>

int memcmp(const void *buf1, const void *buf2, size_t n)
{
	char *s1 = (char *) buf1;
	char *s2 = (char *) buf2;

	while (n-- && *s1 == *s2) {
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}
