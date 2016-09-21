/*
 *  kern/wait.c
 *
 *  This file is part of JunOS Operating System.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <junos/junos.h>

long sys_waitpid(pid_t pid, long *status, int options)
{
	long ret;
	struct task *current = CURRENT_TASK();

	while (1) {
		for (int i = 0; i < NR_TASK; i++) {
			if (!task_table[i])
				continue;
			if (task_table[i] == current)
				continue;
			if (task_table[i]->parent != current)
				continue;

			if (pid > 0) {
				if (task_table[i]->pid != pid)
					continue;
			} else if (pid == 0) {
				if (task_table[i]->grp != current->grp)
					continue;
			} else if (pid < -1) {
				if (task_table[i]->grp != -pid)
					continue;
			}

			switch (task_table[i]->state) {
			case TASK_STATE_STOP:
				if (options & WUNTRACED) {
					if (status)
						*status = 0x7f;
					return task_table[i]->pid;
				}
				break;
			case TASK_STATE_EXIT:
				ret = task_table[i]->pid;
				if (status)
					*status = task_table[i]->status;
				put_page(__pa(task_table[i]));
				task_table[i] = NULL;
				return ret;
			default:
				continue;
			}
		}

		if (options & WNOHANG)
			return -ERSCH;

		sleep_on(NULL, TASK_STATE_PAUSE);
		if (current->sigarrive & ~(1 << (SIGCHLD - 1)))
			return -EINTR;
	}
}
