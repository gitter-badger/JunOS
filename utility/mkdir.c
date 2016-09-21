/*
 *  mkdir.c
 *
 *  This file is part of JunOS Core Utility.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <sys/unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc < 2) {
		fprintf(stderr, "Usage:mkdir name ...");
		_exit(0);
	}
	return mkdir(argv[1], 0777);
}
