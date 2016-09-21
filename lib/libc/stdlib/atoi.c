/*
 *  stdlib/atoi.c
 *
 *  This file is part of JunOS C Library.
 *
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <stdlib.h>
#include <ctype.h>

int atoi(const char *s)
{
	int r = 0;
	while (isspace(*s))
		s++;
	while (isdigit(*s)) {
		r = r * 10 + *s - '0';
		s++;
	}
	return r;
	//return (int) strtol(s, (char**) NULL, 10);
}

long atol(const char *s)
{
	//return (long) strtol(s, (char**) NULL, 10);
}
