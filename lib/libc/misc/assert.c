/*
 *  misc/assert.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <stdio.h>
#include <stdlib.h>

void __assert(char *str)
{
	fputs(str, stderr);
	fputs(" -- assertion faild\n", stderr);
	//abort();
	exit(0);
}
