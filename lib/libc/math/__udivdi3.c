/*
 *  math/__udivdi3.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <stdint.h>

uint64_t __udivdi3(uint64_t a, uint64_t b)
{
	uint64_t ret = 0;

	if (b == 0)
		return (uint64_t) 0;
	while (a > b) {
		a = a - b;
		ret++;
	}
	return ret;
}
