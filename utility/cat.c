/*
 *  cat.c
 *
 *  This file is part of JunOS Core Utility.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <sys/unistd.h>
#include <sys/fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char buf[1024];

void do_cat(int fd)
{
	int size;
	while ((size = read(fd, buf, 1024)) > 0)
		write(STDOUT_FILENO, buf, size);
}

int main(int argc, char *argv[])
{
	int fd;
	if (argc < 2) {
		do_cat(0);
		return 0;
	}

	for (int i = 1; i < argc; i++) {
		fd = open(argv[i], O_RDWR);
		if (fd < 0) {
			fprintf(stderr, "fopen error :%s\n", argv[i]);
			continue;
		}
		do_cat(fd);
		close(fd);
	}
}
