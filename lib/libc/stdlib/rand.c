/*
 *  stdlib/rand.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <stdlib.h>

static int __seed;

int rand(void)
{
	if(__seed==0)
		__seed++;
	__seed=__seed*123044543+12345;
	return __seed-1;
}

void srand(unsigned int seed)
{
	__seed=(int)seed;
}
