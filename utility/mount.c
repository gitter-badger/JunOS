/*
 *  mount.c
 *
 *  This file is part of JunOS Core Utility.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <sys/unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv)
{
	if (argc != 4) {
		fprintf(stderr, "Usage:mount special target type");
		_exit(0);
	}
	if (mount(argv[1], argv[2], argv[3], 0) < 0) {
		fprintf(stderr, "%d:%s", errno, strerror(errno));
		_exit(0);
	}
	return 0;
}
