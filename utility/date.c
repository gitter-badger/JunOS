/*
 *  date.c
 *
 *  This file is part of JunOS Core Utility.
 *
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <stdio.h>
#include <time.h>

int main(int argc, char **argv)
{
	time_t now = time(NULL);

	printf("%s\n", ctime(&now));
}