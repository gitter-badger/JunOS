/*
 *  string/strchr.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <string.h>

#ifdef _STRCHR
char * strchr(const char * str, int ch)
{
	char *s = (char *) str;

	while (*s && *s!= ch)
		s++;

	return  *s ? s : NULL;
}
#endif

#ifdef _STRRCHR
char * strrchr(const char *str, int ch)
{
	char *s = (char *) str;
	while (*s)
		s++;

	while (s-- != str && *s != (char) ch)
		;

	return s <= str ? NULL : s;
}
#endif
