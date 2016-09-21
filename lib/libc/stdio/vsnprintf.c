/*
 *  stdio/vsnprintf.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int vsnprintf(char * buf, size_t size, const char *fmt, va_list ap)
{
	char tmp_buf[2048];
	int i;

	i = vsprintf(tmp_buf, fmt, ap);

	if (i > size)
		i = size;
	memcpy(buf, tmp_buf, i);
	return i;
}
