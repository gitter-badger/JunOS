/*
 *  time/time.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <sys/types.h>
#include <sys/syscall.h>
#include <time.h>
#include <errno.h>

time_t time(time_t *tloc)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);

	if (tloc) {
		*tloc = tv.tv_sec;
	}
	return tv.tv_sec;
}
