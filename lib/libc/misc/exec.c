/*
 *  misc/exec.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <sys/unistd.h>

#if defined(_EXECL)
int execl(const char *path, const char *arg0, ...)
{
	return execve(path, (char **) &arg0, environ);
}

#elif defined(_EXECLE)
int execle(const char *path, const char * arg0, ...)
{
	char ** env = (char **) &arg0;

	while (!*env)
		env++;

	return execve(path, (char **) &arg0, env);
}

#elif defined(_EXECLP)
int execlp(const char * file, const char * arg0, ...)
{
	return execvp(file, (char **) &arg0);
}

#elif defined(_EXECV)
int execv(const char *path, char **argv)
{
	return execve(path, argv, environ);
}

#elif defined(_EXECVP)
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

int execvp(const char *file, char **argv)
{
	char *path, *tmp, tmp_path[PATH_MAX];
	struct stat st;
	int len;

	if (*file == '/' || !(path = getenv("PATH")))
		return execve(file, argv, environ);

	while (*path) {
		tmp = tmp_path;
		len = 0;
		while (len < PATH_MAX && *path && *path != ':') {
			*(tmp++) = *(path++);
			len++;
		}
		if (*path == ':')
			path++;
		if (!len || tmp[-1] != '/') {
			*(tmp++) = '/';
			len++;
		}
		if (len >= PATH_MAX)
			continue;
		strncpy(tmp, file, PATH_MAX - len);

		if (stat(tmp_path, &st))
			continue;
		else if (!(st.st_mode & S_IFREG))
			continue;
		return execve(tmp_path, argv, environ);
	}
	errno = ENOENT;
	return -1;
}

#endif
