/*
 *  driver/tty/tty.h
 *
 *  This file is part of JunOS Operating System.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#ifndef _TTY_H
#define _TTY_H

#include <sys/termios.h>

#define C(x) (x - '@')

#define MAX_COM		2	/* max rs232			*/
#define MAX_PTY		0	/* max pty, not support now. 	*/
#define MAX_TTY		(1 + 1 + MAX_COM + MAX_PTY)

#define TTY_BUF_SIZE 1024
struct tty_buf {
	char            buf[TTY_BUF_SIZE];
	unsigned short  head;
	unsigned short  tail;
	unsigned short  count;
	unsigned short  lines;
	struct task  *  wait;
};

struct tty_struct {
	struct termios  termios;
	pid_t           pgrp;
	struct tty_buf  raw;
	struct tty_buf  cook;
	struct tty_buf  out;
	int             (*write)(struct tty_struct *tty);
	unsigned long   private;
};

static inline int ISFULL(struct tty_buf *buf)
{
	return buf->count==TTY_BUF_SIZE;
}

static inline int ISEMPTY(struct tty_buf *buf)
{
	return buf->count == 0;
}

static inline int GETCH(struct tty_buf *buf)
{
	char retval;
	
	irq_lock();
	retval=buf->buf[buf->tail];
	buf->tail=(buf->tail +1)% TTY_BUF_SIZE;
	buf->count--;
	irq_unlock();

	return retval;
}

static inline void PUTCH(struct tty_buf *buf,char ch)
{
	irq_lock();
	buf->buf[buf->head]=ch;
	buf->count++;
	buf->head=(buf->head +1)% TTY_BUF_SIZE;
	irq_unlock();
}

extern struct tty_struct *tty_table[];
extern void copy_to_cook(struct tty_struct *tty);

#endif
