/*
 *  rmdir.c
 *
 *  This file is part of JunOS Core Utility.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <sys/unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char **argv)
{
	if (argc < 2) {
		fprintf(stderr, "Usage:rmdir dirname");
		_exit(0);
	}
	if (rmdir(argv[1]) < 0)
		fprintf(stderr, "error:mkdir");
}
