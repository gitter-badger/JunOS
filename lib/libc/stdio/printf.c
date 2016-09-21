/*
 *  stdio/printf.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <sys/unistd.h>

int printf(char *fmt, ...)
{
	char buf[2048];
	va_list ap;
	int i;

	i = vsnprintf(buf, 2048, fmt, va_start(ap, fmt));
	write(STDOUT_FILENO, buf, i);
	return i;
}
