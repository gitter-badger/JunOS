/*
 *  stdarg.h
 * 
 *  This file is part of JunOS C Library.
 *
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#ifndef _STDARG_H
#define _STDARG_H

typedef char * va_list;

#define va_start(ap,fmt)   ap=(va_list)&fmt+sizeof(int)
#define va_arg(ap,type)	  (ap+=sizeof(int),*((type*)(ap-sizeof(int))))
#define va_copy(d,s)	  (d)=(s)
#define va_end(ap)

#endif
