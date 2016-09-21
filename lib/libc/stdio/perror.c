/*
 *  stdio/perror.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <stdio.h>
#include <string.h>
#include <errno.h>

void perror(const char *s)
{
	fprintf(stderr, "%s:%s", s, strerror(errno));
	fflush(stderr);
}
