/*
 *  net/inet.c
 *
 *  This file is part of JunOS Operating System.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <junos/junos.h>

void inet_softirq_action(long data)
{
	struct skbuf *skb=(struct skbuf *)data;

	if(!skb)
		return;

	free_skbuf(skb);
}

void inet_init(void)
{
	printk("init inet\n");
	
	softirq_setaction(SOFTIRQ_INET, &inet_softirq_action);
}
