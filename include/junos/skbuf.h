/*
 *  junos/skbuf.h    -- kernel socket buffer interface.
 *
 *  This file is part of JunOS Operating System.
 *
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#ifndef _JUNOS_SKBUF_H
#define _JUNOS_SKBUF_H

struct skbuf{
	struct skbuf  *next;
	struct ethhdr *eh;
	union{
		struct iphdr *ip;
		struct arphdr *arp;
	};
	union{
		struct icmphdr *icmp;
		struct igmphdr *igmp;
		struct udphdr  *udp;
		struct tcphdr  *tcp;
	};
	unsigned char data[0];
};

extern void free_skbuf(struct skbuf *skb);
extern struct skbuf *alloc_skbuf(void);

#endif /* _JUNOS_SKBUF_H */
