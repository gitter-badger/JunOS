/*
 *  junos/kernel.h    -- kernel misc interface.
 *
 *  This file is part of JunOS Operating System.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#ifndef _JUNOS_KERNEL_H
#define _JUNOS_KERNEL_H

#define max(a,b)	((a)>=(b) ? (a) : (b))
#define min(a,b)	((a)<=(b) ? (a) : (b))

#define BCD_BIN(c)	(c=c/16*10+c%16)

extern void printk(char * fmt, ...);
extern void panic(char * fmt, ...);

extern time_t start_time;
extern clock_t click;

#define current_time()	(start_time + click / HZ)

extern void do_exit(long status);

extern void ksigsend(struct task *p, int signo);

static inline int isdigit(int c)
{
	return (c >= '0' && c <= '9'); 
}

/* softirq */
enum {
	SOFTIRQ_TIMER,
	SOFTIRQ_INET
};

extern void softirq_raise(int index, long data);
extern int  softirq_setaction(int index, void (*action)(long data));

/* timer */
struct timer{
	clock_t       time;
	void          (*func)(long arg);
	long          data;
	struct timer *next;
};

extern void add_timer(struct timer *timer_ptr);
extern void del_timer(struct timer *timer_ptr);

struct partition {
	unsigned char boot_ind;
	unsigned char head;
	unsigned char sector;
	unsigned char cyl;
	unsigned char sys_ind;
	unsigned char end_head;
	unsigned char end_sector;
	unsigned char end_cyl;
	unsigned int  start_sect;
	unsigned int  nr_sects;
};

#endif /* _JUNOS_KERNEL_H */
