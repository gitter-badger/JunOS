/*
 *  net/icmp.h
 *  
 *  This file is part of JunOS Operating System.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#ifndef _NET_ICMP_H
#define _NET_ICMP_H

struct icmphdr{
	unsigned char  icmp_type;
	unsigned char  icmp_unused;
	unsigned short icmp_checksum;
	unsigned char  icmp_data[0];
};

#endif
