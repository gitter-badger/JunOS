/*
 *  init/main.c
 *
 *  This file is part of JunOS Operating System.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <junos/junos.h>

extern char _edata[];
extern char _end[];

extern void arch_init(void);
extern void mm_init(void);
extern void dev_init(void);
extern void pci_init(void);
extern void ne2k_init(void);
extern void buffer_init(void);
extern void sched_init(void);
extern void softirq_init(void);
extern void timer_init(void);
extern int  sys_fork(void);
extern int  sys_execve(char *filename, char **argv, char **envp);
extern void mount_root(void);
extern void inet_init(void);
extern void vga_init(void);

static time_t kmktime(int year, int mon, int day, int hour, int min, int sec)
{
	static int month[] = {
		0, 0,
		31,
		(31 + 28),
		(31 + 28 + 31),
		(31 + 28 + 31 + 30),
		(31 + 28 + 31 + 30 + 31),
		(31 + 28 + 31 + 30 + 31 + 30),
		(31 + 28 + 31 + 30 + 31 + 30 + 31),
		(31 + 28 + 31 + 30 + 31 + 30 + 31 + 31),
		(31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30),
		(31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31),
		(31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30)
	};

	long res = 0;

	year = year % 100 + 2000;
	for (int i = 1970; i < year; i++) {
		res += 365;
		if (isleap(i))
			res++;
	}
	res += month[mon];
	if (isleap(year) && mon > 2)
		res++;
	res = res + day - 1;
	res = res * 24 + hour;
	res = res * 60 + min;
	res = res * 60 + sec;
	return res;
}

static void time_init(void)
{
	int year, month, day, hour, min, sec;

	sec=readcoms(0);
	min=readcoms(2);
	hour=readcoms(4);
	day=readcoms(7);
	month=readcoms(8);
	year=readcoms(9);
	BCD_BIN(sec);
	BCD_BIN(min);
	BCD_BIN(hour);
	BCD_BIN(day);
	BCD_BIN(month);
	BCD_BIN(year);
	start_time = kmktime(year, month, day, hour, min, sec);
}

void start(void)
{
	memset(_edata, 0, (_end - _edata));

	arch_init();
	time_init();
	mm_init();
	dev_init();
	pci_init();
	ne2k_init();
	sched_init();
	vga_init();
	
	if (sys_fork()) {
		__asm__("__hlt:hlt ; jmp __hlt");
	}

	setpriority(5);

	softirq_init();
	inet_init();
	timer_init();
	buffer_init();
	mount_root();
	
	sys_execve("/System/Utility/init", NULL, NULL);
	panic("Can't find init");
}
