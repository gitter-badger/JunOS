/*
 *  kern/softirq.c
 *
 *  This file is part of JunOS Operating System.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <junos/junos.h>

#define NR_SOFTIRQ	16

struct softirq_action {
	void (*action)(long data);
	long data;
};

static long softirq_map;
static struct task *softirq_wait;
static struct softirq_action softirq_actions[NR_SOFTIRQ];

void softirq_raise(int index, long data)
{
	if (index >= NR_SOFTIRQ)
		return;
	irq_lock();
	softirq_map |= 1 << index;
	softirq_actions[index].data=data;
	irq_unlock();
	wake_up(&softirq_wait);
}

int softirq_setaction(int index, void (*action)(long data))
{
	if (index > NR_SOFTIRQ)
		panic("set_sofirq_action index too big %d", index);

	if (softirq_actions[index].action != NULL)
		panic("set_softirq_action action has exsit %d", index);

	softirq_actions[index].action = action;

	return 0;
}

extern long sys_fork(void);

void do_softirq(void)
{
	setpriority(1);

	while (1) {
		while (!softirq_map)
			sleep_on(&softirq_wait, TASK_STATE_BLOCK);

		for (int i = 0; i < NR_SOFTIRQ; i++) {
			if (!(softirq_map & (1 << i)))
				continue;
			irq_lock();
			softirq_map &= ~(1 << i);
			irq_unlock();
			(softirq_actions[i].action)(softirq_actions[i].data);
		}
	}
}

void softirq_init(void)
{
	printk("init softirq\n");

	if (!sys_fork())
		do_softirq();
}
