/*
 *  time/localtime.c
 *
 *  This file is part of JunOS C Library.
 *
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <time.h>

struct tm *localtime(time_t * t)
{
	*t = *t + 8 * 3600; // for 8 hour
	return gmtime(t);;
}
