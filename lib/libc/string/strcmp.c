/*
 *  string/strcmp.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <string.h>
#include <ctype.h>

#ifdef _STRCMP
int strcmp(const char *s1, const char *s2)
{
	char *t_s1 = (char*) s1;
	char *t_s2 = (char *) s2;
	while (*t_s1 && *t_s2 && *t_s1 == *t_s2) {
		t_s1++;
		t_s2++;
	}

	return (int) (*t_s1 - *t_s2);
}
#endif

#ifdef _STRICMP
int stricmp(const char *s1, const char *s2)
{
	char *ts1=(char *)s1;
	char *ts2=(char *)s2;

	while (*ts1 && *ts2 && toupper(*ts1)==toupper(*ts2)){
		ts1++;
		ts2++;
	}

	return (int)(*ts1-*ts2);
}
#endif

#ifdef _STRNCMP
int strncmp(const char *s1, const char *s2, size_t n)
{
	char *ts1=(char *)s1;
	char *ts2=(char *)s2;

	while (n--) {
		if (*ts1 && (*ts1 == *ts2)) {
			ts1++;
			ts2++;
		} else {
			return (*ts1 - *ts2);
		}
	}
	return 0;
}
#endif

#ifdef _STRNICMP
int strnicmp(const char *s1, const char *s2, size_t n)
{
	char *ts1=(char *)s1;
	char *ts2=(char *)s2;

	while (n--) {
		if (*ts1 && (toupper(*ts1) == toupper(*ts2))) {
			ts1++;
			ts2++;
		} else {
			return (*ts1 - *ts2);
		}
	}
	return 0;
}
#endif
