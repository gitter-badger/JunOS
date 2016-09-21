/*
 *  ln.c
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
	if (argc < 3) {
		fprintf(stderr, "Usage:link name newname");
		_exit(0);
	}
	return link(argv[1], argv[2]);
}
