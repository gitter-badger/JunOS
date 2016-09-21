/*
 *  kern/signal.c
 *
 *  This file is part of JunOS Operating System.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <junos/junos.h>

void ksigsend(struct task *p, int signo)
{
	if (!p)
		return;

	p->sigarrive |= 1 << (signo - 1);
	if (p->state == TASK_STATE_PAUSE)
		wake_up_proc(p);
}

void do_signal(long unused)
{
	struct trapframe *tf = (struct trapframe *) &unused;
	struct task * current;
	sigset_t signal;

	if (!(tf->cs & 3))
		return;

	current = CURRENT_TASK();

	signal = current->sigarrive & (~current->sigmask);
	if (!signal)
		return;

	for (int signr = 0; signr < NR_SIG; signr++) {
		if (!(signal & (1 << signr)))
			continue;
		if (current->sighandle[signr] == SIG_IGN)
			continue;
		if (!current->sighandle[signr]) {
			if (signr == SIGCHLD - 1)
				continue;
			else
				do_exit(1 << signr);
		}

		unsigned long *esp = (unsigned long *) tf->esp;
		*(--esp) = tf->eax;
		*(--esp) = signr + 1;
		*(--esp) = tf->eip;
		tf->eip = (unsigned long) current->sighandle[signr];
		tf->esp = (unsigned long) esp;
		current->sigarrive &= ~(1 << signr);
		return;
	}

	current->sigarrive &= ~signal;
}

long sys_sigsend(pid_t pid, unsigned int signo)
{
	struct task **p;

	if (signo > NR_SIG)
		return -EINVAL;

	if (pid > 0) {
		for (p = task_table; p < task_table + NR_TASK; p++) {
			if (*p && (*p)->pid == pid)
				ksigsend(*p, signo);
		}
	}

	if (pid < 0) {
		pid = -pid;
		for (p = task_table; p < task_table + NR_TASK; p++) {
			if (*p && (*p)->grp == pid)
				ksigsend(*p, signo);
		}
	}
	return 0;
}

long sys_sigmask(long how, sigset_t *set, sigset_t *oset)
{
	struct task *current = CURRENT_TASK();

	if (oset)
		*oset = current->sigmask;

	if (!set)
		return -ERROR;

	switch (how) {
	case SIG_BLOCK:
		current->sigmask |= *set;
		break;
	case SIG_UNBLOCK:
		current->sigmask &= ~(*set);
		break;
	case SIG_SETMASK:
		current->sigmask = *set;
		break;
	default:
		return -EINVAL;
	}
	current->sigmask &= ~(1 << (SIGKILL - 1) | 1 << (SIGSTOP - 1));

	return 0;
}

long sys_sigact(unsigned long signo, sigact_t sigact)
{
	struct task *current;
	sigact_t oact;

	if (signo >= NR_SIG)
		return -EINVAL;

	current = CURRENT_TASK();

	oact = current->sighandle[signo - 1];
	current->sighandle[signo - 1] = sigact;

	return (long) oact;
}
