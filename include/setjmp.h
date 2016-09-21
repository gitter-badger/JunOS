/*
 *  setjmp.h
 * 
 *  This file is part of JunOS C Library.
 *
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#ifndef _SETJMP_H
#define _SETJMP_H

typedef long jmp_buf[6];

extern int  setjmp(jmp_buf buf);
extern void longjmp(jmp_buf buf, int val);

#endif
