/*
 *  stdlib/abs.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <stdlib.h>

#if defined(_ABS)
int abs(int i)
{
	return i >= 0 ? i : -i;
}

#elif defined(_LABS)
long labs(long i)
{
	return i >= 0 ? i : -i;
}

#elif defined(_LLABS)
long long llabs(long long i)
{
	return i >= 0 ? i : -i;
}
#endif
