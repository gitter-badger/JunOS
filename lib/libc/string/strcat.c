/*
 *  string/strcat.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <string.h>

#ifdef _STRCAT
char * strcat(char *s1, const char *s2)
{
	char *tmp = s1;
	char *tmp2 = (char*) s2;
	while (*tmp)
		tmp++;
	while (*tmp2)
		*tmp++ = *tmp2++;
	return s1;
}
#endif

#ifdef _STRNCAT
char * strncat(char *s1, const char *s2 ,size_t n)
{
	char *tmp = s1;
	char *ts2=(char *)s2;

	while (*tmp)
		tmp++;

	while (n-- && *ts2)
		*tmp++ = *ts2++;

	return s1;
}
#endif
