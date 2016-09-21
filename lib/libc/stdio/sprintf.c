/*
 *  stdio/sprintf.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int sprintf(char * buf, const char *fmt,...)
{
	va_list ap;
	int i;

	i=vsprintf(buf, fmt, va_start(ap,fmt));

	return i;
}
