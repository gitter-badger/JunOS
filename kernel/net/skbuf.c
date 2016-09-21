/*
 *  net/skbuf.c
 *
 *  This file is part of JunOS Operating System.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <junos/junos.h>

static struct skbuf *skb_free_list;

void free_skbuf(struct skbuf *skb)
{
	if (!skb)
		return;

	irq_lock();
	skb->next = skb_free_list;
	skb_free_list = skb;
	irq_unlock();
}

struct skbuf *alloc_skbuf(void)
{
	unsigned long tmp;
	struct skbuf *skb;

	irq_lock();
	if (skb_free_list) {
		skb = skb_free_list;
		skb_free_list = skb_free_list->next;
		irq_unlock();
		return skb;
	}
	irq_unlock();

	tmp = __va(get_page());

	free_skbuf((struct skbuf *) (tmp + 2048));

	return (struct skbuf*) tmp;
}
