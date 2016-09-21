/*
 *  stdio/iotab.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include "stdio_loc.h"

FILE __iotab[MAX_OPEN] = {
	{ 0, _IOLBF, 0, 0, 0, 0 },
	{ 1, _IOLBF, 0, 0, 0, 0 },
	{ 2, _IONBF, 0, 0, 0, 0 },
};

FILE *stdin=  &__iotab[0];
FILE *stdout= &__iotab[1];
FILE *stderr= &__iotab[2];
