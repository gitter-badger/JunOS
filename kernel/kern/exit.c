/*
 *  kern/exit.c
 *
 *  This file is part of JunOS Operating System.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <junos/junos.h>

extern int sys_close(int fd);

void do_exit(long exitcode)
{
	struct task * current = CURRENT_TASK();
	current->status = exitcode;
	free_mm();

	if (current->pwd)
		iput(current->pwd);
	for (int i = 0; i < NR_OPEN; i++)
		if (current->file[i])
			sys_close(i);

	irq_lock();
	unready(TASK_STATE_EXIT);
	ksigsend(current->parent, SIGCHLD);
	sched();
}

void sys_exit(long status)
{
	do_exit((status << 8) & 0xff00);
}
