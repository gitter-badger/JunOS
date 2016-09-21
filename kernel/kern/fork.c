/*
 *  kern/fork.c
 *
 *  This file is part of JunOS Operating System.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <junos/junos.h>

long sys_fork(long unuesd)
{
	static pid_t last_pid = 0;

	struct task * task = (struct task*) __va(get_page());
	struct task * current = CURRENT_TASK();

	memcpy(task, current , PAGE_SIZE);
	
	task->state = TASK_STATE_STOP;
	task->pid = ++last_pid;
	task->parent = current;

	task->utime = 0;
	task->stime = 0;

	task->start = current_time();
	task->kesp = build_context((((long) &unuesd) & 0xfff) | (long) task);
	task->pdtr = copy_mm();

	irq_lock();
	if (current->pwd)
		current->pwd->i_count++;
	for (int i = 0; i < NR_OPEN; i++) {
		if (current->file[i]) {
			current->file[i]->f_count++;
		}
	}
	irq_unlock();

	for (int i = 0; i < NR_TASK; i++) {
		if (task_table[i])
			continue;
		task_table[i] = task;
		wake_up_proc(task);
		return task->pid;
	}
	return -1;
}
