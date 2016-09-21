/*
 *  net/udp.h
 *  
 *  This file is part of JunOS Operating System.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#ifndef _NET_UDP_H
#define _NET_UDP_H

struct udphdr{
	unsigned short udp_src;
	unsigned short udp_dst;
	unsigned short udp_len;
	unsigned short udp_check;
	unsigned char  udp_data[0];
};

#endif
