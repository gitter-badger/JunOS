/*
 *  driver/tty/tty.c
 *
 *  This file is part of JunOS Operating System.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <junos/junos.h>
#include "tty.h"

extern void con_init(void);
extern void kbd_init(void);
extern void com_init(void);

struct tty_struct *tty_table[MAX_TTY];

void copy_to_cook(struct tty_struct *tty)
{
	char ch;

	while (!ISEMPTY(&(tty->raw))) {

		ch = GETCH(&(tty->raw));

		PUTCH(&(tty->cook), ch);

		if (tty->termios.c_lflag & ECHO) {
	
			if ( ch == '\n') {

				PUTCH(&(tty->out), ch);
				tty->write(tty);
				wake_up(&(tty->cook.wait));
				continue;

			}
			
			PUTCH(&tty->out, ch);
			tty->write(tty);
		}
		wake_up(&tty->cook.wait);
	}
}

static int tty_read(dev_t dev, char * buf, off_t off, size_t size)
{
	struct tty_struct *tty;
	long left = size;
	int ch;

	if (MINOR(dev) == 0) {
		printk("read from tty0");
		return -1;
	}

	tty = tty_table[MINOR(dev)];

	//irq_lock();
	while (left) {
		if (!ISEMPTY(&tty->cook)) {
			ch = GETCH(&(tty->cook));
			*buf++ = ch;
			if (ch == '\n') {
				//irq_unlock();
				return size - left + 1;
			}
			if (ch == C('D')) {
				//irq_unlock();
				return size - left;
			}
			left--;
			continue;
		}
		sleep_on(&(tty->cook.wait), TASK_STATE_BLOCK);
	}
	//irq_unlock();
	return size - left;

}

static int tty_write(dev_t dev, char * buf, off_t off, size_t size)
{
	struct tty_struct *tty;
	long left = size;
	char ch;

	if (MINOR(dev) == 0)
		return -1;

	tty = tty_table[MINOR(dev)];

	while (left) {
		if (!ISFULL(&(tty->out))) {
			ch = *buf++;
			if (ch == '\n' && (tty->termios.c_oflag & ONLCR))
				PUTCH(&(tty->out), '\r');
			PUTCH(&(tty->out), ch);
			left--;
			continue;
		}
		tty->write(tty);
	}
	tty->write(tty);
	return size - left;
}

static int tty_ioctl(dev_t dev, int cmd, long arg)
{
	struct tty_struct *tty;

	if (MINOR(dev) == 0)
		return -1;

	tty = tty_table[MINOR(dev)];

	switch (cmd) {
	case TCGETS:
		memcpy((char*) arg, (char*) &tty->termios,
				sizeof(struct termios));
		return 0;
	case TCSETS:
		memcpy((char*) &tty->termios, (char*) arg,
				sizeof(struct termios));
		return 0;
	default:
		return -1;
	}
}

static struct char_device tty =
	{ "TTY", NULL, NULL, tty_read, tty_write, tty_ioctl };

void tty_init(void)
{
	con_init();
	kbd_init();
	com_init();
	char_table[DEV_CHAR_TTY] = &tty;
}
