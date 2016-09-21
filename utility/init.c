/*
 *  init.c
 *
 *  This file is part of JunOS Core Utility.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <sys/unistd.h>
#include <sys/wait.h>
#include <sys/fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char *envp[] = { "PATH=/System/Utility", NULL };

char *ttys[] = { "/System/Devices/console",
                 "/System/Devices/com1", 
                 NULL,
};

int main(int argc, char **argv)
{
	char **p = ttys;

	while (*p) {
		if (!fork()) {
			close(0);
			close(1);
			close(2);
			setsid();
			if (open(*p, O_RDWR, 0) < 0)
				exit(0);
			dup(0);
			dup(0);
			execve("/System/Utility/sh", NULL, envp);
		}
		p++;
	}

	wait(NULL);
}
