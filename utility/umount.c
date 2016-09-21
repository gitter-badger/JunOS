/*
 *  umount.c
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
	if (argc != 2) {
		fprintf(stderr, "Usage: umount special ");
		_exit(0);
	}
	if (umount(argv[1]) < 0) {
		fprintf(stderr, "%d:%s", errno, strerror(errno));
	}
	return 0;
}
