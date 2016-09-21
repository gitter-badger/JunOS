/*
 *  time/ctime.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <time.h>

char *ctime(time_t *tp)
{
	return(asctime(localtime(tp)));
}
