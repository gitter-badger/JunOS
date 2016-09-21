/*
 *  string/strcoll.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <string.h>

int strcoll(const char *s1, const char *s2)
{
	return strcmp(s1, s2);
}
