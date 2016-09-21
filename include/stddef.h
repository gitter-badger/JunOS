/*
 *  stddef.h
 * 
 *  This file is part of JunOS C Library.
 *
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#ifndef _STDDEF_H
#define _STDDEF_H

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

#ifndef  __WCHAR_T
 #define __WCHAR_T
 typedef signed short   wchar_t;
#endif

#ifndef  __PTRDIFF_T
 #define __PTRDIFF_T
 typedef signed   long  ptrdiff_t;
#endif

#define offestof(type,member) ((size_t)&((type*)0->member))

#endif
