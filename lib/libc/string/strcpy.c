/*
 *  string/strcpy.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <string.h>

#ifdef _STRCPY
char *strcpy(char *dst, const char *src)
{
	char *tmp = dst;
	char *t =(char *)src;
	while (*t)
		*tmp++ = *t++;
	*tmp = 0;
	return dst;
}
#endif

#ifdef _STRNCPY
char *strncpy(char *dst, const char *src, size_t n)
{
	char *t = dst;
	char *t2=(char *)src;

	while (n-- && *t2)
		*t++ = *t2++;
	if(n)
		*t=0;
	return dst;
}
#endif
