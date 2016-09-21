/*
 *  sys/types.h
 * 
 *  This file is part of JunOS C Library.
 *
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H

#ifndef  NULL
 #define NULL 		((void*)0)
#endif

#ifndef  __SIZE_T
 #define __SIZE_T
 typedef unsigned long 	size_t;
#endif

#ifndef  __SSIZE_T
 #define __SSIZE_T
 typedef signed   long 	ssize_t;
#endif

#ifndef  __OFF_T
 #define __OFF_T
 typedef unsigned long 	off_t;
#endif

typedef unsigned long 	time_t;
typedef unsigned long 	clock_t;

typedef signed int 	uid_t;
typedef signed int 	gid_t;
typedef signed int 	pid_t;

typedef unsigned int 	dev_t;
typedef unsigned int 	ino_t;
typedef unsigned int 	mode_t;
typedef unsigned int 	nlink_t;

#endif
