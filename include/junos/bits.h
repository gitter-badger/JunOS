/*
 *  junos/bits.h
 *
 *  This file is part of JunOS Operating System.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#ifndef _JUNOS_BITS_H
#define _JUNOS_BITS_H

static inline int find_bit(char *addr, int size)
{
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < 8; j++)
			if (!((*addr) & (1 << j)))
				return (i * 8 + j);
		addr++;
	}
	return -1;
}

static inline void set_bit(char *addr, int bit)
{
	*(addr + bit / 8) = *(addr + bit / 8) | (1 << (bit % 8));
}

static inline void clr_bit(char *addr, int bit)
{
	*(addr + bit / 8) = *(addr + bit / 8) & (~(1 << (bit % 8)));
}

static inline short bswapw(short data)
{
	short res;
	__asm__("bswap %%eax" :"=a"(res): "a"(data<<16));
	return res;
}

static inline int bswapl(int data)
{
	int res;
	__asm__("bswap %%eax" :"=a"(res): "a"(data));
	return res;
}

#endif /* _JUNOS_BITS_H */
