/*
 *  stdlib/getenv.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <stdlib.h>
#include <string.h>

char * getenv(const char * name)
{
	int len = strlen(name);
	char ** env = environ;
	char * tmp;

	while (*env) {
		tmp = *env++;
		if (strncmp(name, tmp, len))
			continue;
		if (tmp[len] == '=')
			return tmp + len + 1;
	}
	return NULL;
}
