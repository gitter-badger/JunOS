/*
 *  net/ip.h
 *  
 *  This file is part of JunOS Operating System.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#ifndef _NET_IP_H
#define _NET_IP_H

struct iphdr{
	unsigned char  ip_hl_and_ver;
	unsigned char  ip_tos;
	unsigned short ip_len;
	unsigned short ip_id;
	unsigned short ip_fragoff;
	unsigned char  ip_ttl;
	unsigned char  ip_protocol;
	unsigned char  ip_checksum;
	unsigned int   ip_srcaddr;
	unsigned int   ip_dstaddr;
	unsigned char  ip_data[0];
};

#endif
