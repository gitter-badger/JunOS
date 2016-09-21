/*
 *  kern/timer.c
 *
 *  This file is part of JunOS Operating System.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <junos/junos.h>

static struct timer *timer_list = NULL;

void add_timer(struct timer *timer_ptr)
{
	struct timer *tmp = timer_list;

	irq_lock();
	if (!timer_list) {
		timer_list = timer_ptr;
		timer_ptr->next = NULL;
		irq_unlock();
		return;
	}

	while (tmp->next && (tmp->next->time < timer_ptr->time))
		tmp = tmp->next;
	timer_ptr->next = tmp->next;
	tmp->next = timer_ptr;
	irq_unlock();
}

void del_timer(struct timer *timer_ptr)
{
	struct timer *tmp = timer_list;

	irq_lock();
	if (timer_list == timer_ptr) {
		timer_list = timer_ptr->next;
		return;
	}
	while (tmp->next && (tmp->next != timer_ptr))
		tmp = tmp->next;
	tmp->next = tmp->next->next;
	irq_unlock();
}

static void timer_softirq_action(long unused)
{
	if (!timer_list) {
		printk("timer_list is NULL");
		return;
	}

	(timer_list->func)(timer_list->data);
	timer_list = timer_list->next;
}

void do_timer(void)
{
	if (!timer_list)
		return;
	if (click >= timer_list->time)
		softirq_raise(SOFTIRQ_TIMER, (long) 0);
}

void timer_init(void)
{
	softirq_setaction(SOFTIRQ_TIMER, &timer_softirq_action);
}
