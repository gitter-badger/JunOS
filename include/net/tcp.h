/*
 *  net/tcp.h
 *  
 *  This file is part of JunOS Operating System.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#ifndef _NET_TCP_H
#define _NET_TCP_H

struct tcphdr{
	unsigned short tcp_src;
	unsigned short tcp_dst;
	unsigned int   tcp_seq;
	unsigned int   tcp_ackseq;
	unsigned short tcp_flags;
	unsigned short tcp_window;
	unsigned short tcp_check;
	unsigned short tcp_urgptr;
	unsigned char  tcp_data[0];
};

#endif
