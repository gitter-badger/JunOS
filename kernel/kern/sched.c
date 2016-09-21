/*
 *  kern/sched.c
 *
 *  This file is part of JunOS Operating System.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <junos/junos.h>

time_t start_time;
clock_t click;

struct task * task_table[NR_TASK];
struct task * priority[NR_PRIO];

#define LATCH		(1193180/HZ)

static void do_clock(struct trapframe *tf)
{
	extern void do_timer(void);
	struct task *current = CURRENT_TASK();

	outb(0x20, 0x20);
	click++;

	if (tf->cs & 3) {
		current->utime++;
	} else
		current->stime++;

	do_timer();

	if (--current->count < 0)
		sched();
}

void sched_init(void)
{
	struct task *current = CURRENT_TASK();

	memset(current, 0, sizeof(struct task));
	current->count = 20;
	current->state = TASK_STATE_READY;
	task_table[0] = current;
	current->priority = NR_PRIO - 1;
	current->parent = current;
	current->next = NULL;
	priority[NR_PRIO - 1] = current;

	/* setup clock */
	outb(0x43, 0x36);
	outb(0x40, LATCH && 0xff);
	outb(0x40, LATCH >> 8);
	set_trap_handle(0x20, &do_clock);
	outb(0x21, inb(0x21) & ~1);
}

void dump_task()
{
	struct task *p;
	irq_lock();
	printk("dump task:\n");
	printk(" index  pid    ppid    grp    sid   state    count priority\n");

	for (int i = 0; i < NR_TASK; i++) {
		if (!task_table[i])
			continue;
		p = task_table[i];
		printk("%5d %5d %5d %5d  %5d  %5d %5d %5d  %5d\n", i, p->pid,
				p->parent->pid, p->grp, p->sid, p->state,
				p->count, p->priority);
	}
	printk("dump priortiy\n");
	printk("priority  list \n");
	for (int i = 0; i < NR_PRIO; i++) {
		if (!priority[i])
			continue;
		printk("%5d ", i);
		p = priority[i];
		while (p) {
			printk("%#x ", p);
			p = p->next;
		}
	}
	irq_unlock();
}

void sched(void)
{
	struct task *p, *q, *current;

	for (int i = 0; i < NR_PRIO; i++) {
		if (!priority[i])
			continue;
		irq_lock();
		p = priority[i];
		if (p->count <= 0) {
			p->count = 25;
			if (p->next) {
				priority[i] = p->next;
				q = p->next;
				while (q->next)
					q = q->next;
				q->next = p;
				p->next = NULL;
			}
		}
		irq_unlock();

		current = CURRENT_TASK();
		if (priority[i] != current)
			__switch_to(priority[i]);
		return;
	}
	panic("Don't have ready process");
}

void sleep_on(struct task **wait, int state)
{
	struct task *p;
	struct task *current = CURRENT_TASK();

	current->state = state;

	p = priority[current->priority];
	irq_lock();
	if (p == current)
		priority[current->priority] = current->next;
	else {
		while (p->next && p->next != current)
			p = p->next;
		p->next = p->next->next;
	}

	if (wait) {
		current->next = *wait;
		*wait = current;
	} else
		current->next = NULL;
	irq_unlock();
	sched();
}

void unready(int state)
{
	struct task *p;
	struct task *current = CURRENT_TASK();

	current->state = state;

	p = priority[current->priority];
	irq_lock();
	if (p == current)
		priority[current->priority] = current->next;
	else {
		while (p->next && p->next != current)
			p = p->next;
		p->next = p->next->next;
	}

	irq_unlock();
}

static void __wake_up_proc(struct task *p)
{
	if (p->state == TASK_STATE_READY)
		return;
	p->state = TASK_STATE_READY;
	p->next = priority[p->priority];
	priority[p->priority] = p;
}

void wake_up_proc(struct task *p)
{
	irq_lock();
	__wake_up_proc(p);
	irq_unlock();
	sched();
}

void wake_up(struct task **wait)
{
	struct task *tmp;

	if (!wait)
		return;
	irq_lock();
	while (*wait) {
		tmp = *wait;
		*wait = tmp->next;
		__wake_up_proc(tmp);
	}
	irq_unlock();
	sched();
}

void setpriority(int pr)
{
	struct task *current;
	struct task *p;

	if (pr >= NR_PRIO) {
		printk("priority too big :%d", pr);
		return;
	}

	current = CURRENT_TASK();

	/* remove from old list */
	p = priority[current->priority];
	if (p == current)
		priority[current->priority] = current->next;
	else {
		while (p->next && p->next != current)
			p = p->next;
		if (p->next)
			p->next = p->next->next;
	}

	/* add to new list */
	current->priority = pr;
	current->next = priority[current->priority];
	priority[current->priority] = current;
}

long sys_getpid(void)
{
	return (CURRENT_TASK() )->pid;
}

long sys_setgrp(void)
{
	struct task *current = CURRENT_TASK();
	return current->grp = current->pid;
}

long sys_setsid(void)
{
	struct task *task = CURRENT_TASK();

	if ((task->sid == task->pid) || (task->uid != 0))
		return -EPERM;
	task->tty = -1;
	return task->sid = task->grp = task->pid;
}

long sys_getuid(void)
{
	return (CURRENT_TASK() )->uid;
}

long sys_setuid(uid_t uid)
{
	if ((CURRENT_TASK() )->uid != 0)
		return -EPERM;
	return (CURRENT_TASK() )->uid = uid;
}

long sys_getgid(void)
{
	return (CURRENT_TASK() )->gid;
}

long sys_setgid(gid_t gid)
{
	if ((CURRENT_TASK() )->uid != 0)
		return -EPERM;
	return (CURRENT_TASK() )->gid = gid;
}

/*
 * Note: Align to 16 Bytes
 */
long sys_sbrk(unsigned long inc)
{
	unsigned int res;
	unsigned long addr;
	struct task *current;

	current = CURRENT_TASK();
	res = current->sbrk;
	inc = (inc + 0xf) & 0xfffffff0;
	current->sbrk += inc;

	addr = (res + 0xfff) & 0xfffff000;
	for (; addr <= current->sbrk; addr += 4096) {
		map_page(addr, get_page(), current->pdtr);
	}
	return res;
}

long sys_alarm(unsigned long seconds)
{
	long old;
	struct task *current;

	current = CURRENT_TASK();
	old = current->alarm;

	current->alarm = seconds ? (click + seconds * HZ) : 0;
	if (old)
		return (old - click) / HZ;
	return 0;
}

long sys_pause(void)
{
	sleep_on(NULL, TASK_STATE_PAUSE);
	return -EINTR;
}

long sys_gettimeofday(struct timeval *tv, struct timezone *tz)
{
	if (tv) {
		tv->tv_sec = current_time();
		tv->tv_usec = 0;
	}
	return 0;
}

long sys_settimeofday(struct timeval *tv, struct timezone *tz)
{
	if ((CURRENT_TASK() )->uid != 0)
		return -EPERM;

	if(tv){
		start_time = tv->tv_sec - click / HZ;
	}

	return 0;
}
