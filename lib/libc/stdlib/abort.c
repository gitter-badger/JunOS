/*
 *  stdlib/abort.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <stdlib.h>
#include <sys/unistd.h>
#include <signal.h>

void abort(void)
{
	sigsend(getpid(), SIGABRT);
}
