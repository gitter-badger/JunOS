/*
 *  net/igmp.h
 *  
 *  This file is part of JunOS Operating System.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#ifndef _NET_IGMP_H
#define _NET_IGMP_H

struct igmphdr{
	unsigned char  igmp_type;
	unsigned char  igmp_unused;
	unsigned short igmp_checksum;
	unsigned long  igmp_group;
	unsigned char  igmp_data[0];
};

#endif
