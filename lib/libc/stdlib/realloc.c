/*
 *  stdlib/realloc.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <stdlib.h>
#include <string.h>

void * realloc(void *ptr, size_t size)
{
	void *tmp;

	tmp = malloc(size);

	if (!tmp)
		return NULL;

	if (ptr) {
		memcpy((char*) tmp, (char*) ptr, size);
		free(ptr);
	}
	return tmp;
}
