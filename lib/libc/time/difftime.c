/*
 *  time/difftime.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <time.h>

double difftime(time_t time1, time_t time0)
{
	return (double) (time1 - time0);
}
