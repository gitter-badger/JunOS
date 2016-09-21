/*
 *  stdlib/calloc.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <stdlib.h>
#include <stddef.h>
#include <string.h>

void * calloc(size_t nelem, size_t elsize)
{
	void *tmp;
	int size = nelem * elsize;

	tmp = malloc(size);
	if (!tmp)
		return NULL;
	memset((char*) tmp, 0, size);
	return tmp;
}
