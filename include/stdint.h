/*
 *  stdint.h
 * 
 *  This file is part of JunOS C Library.
 *
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#ifndef _STDINT_H
#define _STDINT_H

typedef char			int8_t;
typedef short			int16_t;
typedef int			int32_t;
typedef long long 		int64_t;

typedef unsigned char 		uint8_t;
typedef unsigned short 		uint16_t;
typedef unsigned int		uint32_t;
typedef unsigned long long	uint64_t;

typedef long                 	intptr_t;
typedef unsigned long        	uintptr_t;

typedef long  uintmax_t;

#endif
