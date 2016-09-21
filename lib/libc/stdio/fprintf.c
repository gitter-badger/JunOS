/*
 *  stdio/fprintf.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <sys/unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int fprintf(FILE *stream, const char *fmt, ...)
{
	va_list ap;
	int i;
	char buf[512];

	fflush(stream);

	i=vsnprintf(buf,512,fmt,va_start(ap,fmt));
	write(fileno(stream),buf,i);

	return i;
}
