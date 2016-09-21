/*
 *  junos/sched.h    -- kernel shecd define and function.
 *
 *  This file is part of JunOS Operating System.
 *
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#ifndef _JUNOS_SCHED_H
#define _JUNOS_SCHED_H

struct tss_struct {
	unsigned int  link;
	unsigned int  esp0;
	unsigned int  ss0;
	unsigned int  esp1;
	unsigned int  ss1;
	unsigned int  esp2;
	unsigned int  ss2;
	unsigned int  cr3;
	unsigned int  eip;
	unsigned int  eflags;
	unsigned int  eax;
	unsigned int  ecx;
	unsigned int  edx;
	unsigned int  ebx;
	unsigned int  esp;
	unsigned int  ebp;
	unsigned int  esi;
	unsigned int  edi;
	unsigned int  es;
	unsigned int  cs;
	unsigned int  ss;
	unsigned int  ds;
	unsigned int  fs;
	unsigned int  gs;
	unsigned int  ldt;
	unsigned short trap;
	unsigned short iobase;
};

struct task {
	long          kesp; 		/* kernel stack_end. 	*/
	pid_t         pid; 		/* process id.  	*/
	pid_t         grp; 		/* process group id. 	*/
	pid_t         sid; 		/* session id.  	*/
	uid_t         uid; 		/* user id. 		*/
	gid_t         gid; 		/* user group id. 	*/
	clock_t       start;		/* start time. 		*/
	clock_t       stime; 		/* system time. 	*/
	clock_t       utime; 		/* user   time. 	*/
	clock_t       alarm; 		/* alarm. 		*/
	long          state; 		/* process state. 	*/
	long          count; 		/* have not used time. 	*/
	long          priority; 	/* process priority.	*/
	long          pdtr; 		/* cr3 			*/
	long          sbrk; 		/* heap end. 		*/
	long          stack; 		/* stack end. 		*/
	long 	      status; 		/* exit status. 	*/
	sigset_t      sigarrive;	/* sig arrived map 	*/
	sigset_t      sigmask;		/* sig mask    map	*/
	sigact_t      sighandle[NR_SIG];/* sig handle table	*/
	unsigned int  tty; 		/* control tty. 	*/
	struct inode *pwd; 		/* current dir inode. 	*/
	struct file  *file[NR_OPEN]; 	/* file open point. 	*/
	struct task  *parent;		/* point to father task */
	struct task  *next;		/* point to list next   */
};

/* Values of task->state */
enum {
	TASK_STATE_UNUSE, 	/* unused or creating.	*/
	TASK_STATE_READY, 	/* ready  or running.	*/
	TASK_STATE_BLOCK, 	/* wait some resource.	*/
	TASK_STATE_PAUSE, 	/* wait singal.		*/
	TASK_STATE_STOP, 	/* stop by singal etc.	*/
	TASK_STATE_EXIT, 	/* task exit.		*/
};

#define CURRENT_TASK() 			\
    (struct task*)({ 			\
	unsigned long __res; 		\
	__asm__ __volatile__(		\
            "movl %%esp,%%eax;"		\
            "andl $0xfffff000,%%eax"	\
            :"=a"(__res)); 		\
	__res; 				\
    })

#define __switch_to(p)			\
    ({	tss.esp0 = (long)p + 4096;	\
        __asm__ volatile (		\
        "movl %%eax,%%cr3;"		\
	"pushl $__ret_switch;"		\
	"pushf;"			\
	"pushl %%eax;"			\
	"pushl %%ebx;"			\
	"pushl %%ecx;"			\
	"pushl %%edx;"			\
	"pushl %%edi;"			\
	"pushl %%esi;"			\
	"pushl %%ebp;"			\
	"subl  $108,%%esp;"		\
	"fnsave (%%esp);"		\
	"movl  %%esp,%%eax;"		\
	"andl  $0xfffff000,%%eax;"	\
	"movl  %%esp,(%%eax);"		\
	"movl  %%ecx,%%esp;"		\
	"frstor (%%esp);"		\
	"addl  $108,%%esp;"		\
	"popl  %%ebp;"			\
	"popl  %%esi;"			\
	"popl  %%edi;"			\
	"popl  %%edx;"			\
	"popl  %%ecx;"			\
	"popl  %%ebx;"			\
	"popl  %%eax;"			\
	"popf;"				\
	"ret;"				\
	"__ret_switch:  ;"		\
	::"a"(p->pdtr),			\
	  "c"(p->kesp));		\
    })

static inline long build_context(long stack)
{
	long *p = (long *) stack;

	--p;			// ret
	*(--p) = 0x13200;	// popf
	*(--p) = 0;		// eax
	*(--p) = 0;		// ebx
	*(--p) = 0;		// ecx
	*(--p) = 0;		// edx
	*(--p) = 0;		// edi
	*(--p) = 0;		// esi
	*(--p) = 0;		// ebp

	p -= 27;
	__asm__ ("fnsave (%%eax)" ::"a"(p));

	return (long) p;
}

#define NR_PRIO		8

extern struct tss_struct tss;
extern struct task * task_table[];
extern struct task * priority[];

extern void sleep_on(struct task **wait, int state);
extern void wake_up_proc(struct task *p);
extern void wake_up(struct task **wait);
extern void setpriority(int pr);
extern void sched(void);
extern void unready(int state);

#endif /* _JUNOS_SCHED_H */
