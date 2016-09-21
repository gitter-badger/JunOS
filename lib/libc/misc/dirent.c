/*
 *  misc/dirent.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <sys/fcntl.h>
#include <sys/stat.h>
#include <sys/unistd.h>
#include <sys/dirent.h>
#include <stdlib.h>
#include <errno.h>

DIR * opendir(char * dirname)
{
	struct stat statbuf;
	DIR *dir;
	int  fd;

	if ((fd = open(dirname, O_READ)) < 0)
		return NULL;

	if (fstat(fd, &statbuf) < 0 ||
	    !S_ISDIR(statbuf.st_mode) ||
	    !(dir =malloc(sizeof(DIR)))) {
		close(fd);
		return NULL;
	}

	dir->dd_fd = fd;

	return dir;
}

struct dirent * readdir(DIR * dir)
{
	static struct dirent _res_dirent;

	if (!dir) {
		errno = EBADF;
		return NULL;
	}

	if(read(dir->dd_fd,(char*)&_res_dirent,sizeof(struct dirent))<=0)
		return NULL;

	return &_res_dirent;
}

void rewinddir(DIR * dir)
{
	if (!dir) {
		errno = EBADF;
		return;
	}
	lseek(dir->dd_fd, 0L, SEEK_SET);
}

int closedir(DIR * dir)
{
	int fd;

	if (!dir) {
		errno = EBADF;
		return -1;
	}

	fd = dir->dd_fd;
	free(dir);

	return close(fd);
}
