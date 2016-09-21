/*
 *  stdio/snprintf.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int snprintf(char * buf, size_t size, const char *fmt, ...)
{
	va_list ap;

	return  vsnprintf(buf, size, fmt, va_start(ap, fmt));
}
