/*
 *  stdio/stdio_loc.h
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#ifndef _STDIO_LOC_H
#define _STDIO_LOC_H

#include <sys/fcntl.h>
#include <sys/unistd.h>
#include <stdio.h>
#include <stdlib.h>

extern FILE __iotab[];

#define READING		0x0100
#define WRITING		0x0200

#endif
