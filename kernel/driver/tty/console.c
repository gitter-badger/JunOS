/*
 *  driver/tty/console.c
 *
 *  This file is part of JunOS Operating System.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <junos/junos.h>
#include "tty.h"

//static unsigned long base   = __va(0xb8000);
//static unsigned long origin = __va(0xb8000);
//static unsigned char color  = 7;
static unsigned char x;
static unsigned char y;

static struct tty_struct con_tty;

/*
static void srcup()
{
	if (y < 25)
		return;
	memcpy((char*) base, (char*) base + 160, 80 * 24 * 2);
	memset((char*) base + 80 * 24 * 2, 0, 80 * 2);
	y = 24;
}

static void write_char(char ch)
{
	char *p = (char*) ( base + (y * 80 + x) * 2);
	if (ch == '\r')
		return;
	if (ch == '\b') {
		if (x > 0) {
			x--;
		} else {
			if (y > 0) {
				x = 80 - 1;
				y--;
			}
		}

		*--p = color;
		*--p = ' ';

	} else if (ch == '\t') {
		do {
			*p++ = ' ';
			*p++ = color;
		} while (++x % 8);
	} else if (ch == '\n') {
		y++;
		x = 0;
		srcup();
	} else {
		*p++ = ch;
		*p++ = color;
		x++;
		if (x >= 80) {
			x = 0;
			y++;
			srcup();
		}
	}
}

static void set_orign(void)
{
	outb(0x3d4, 12);
	outb(0x3d5, (base - 0xc00b8000) >> 9 & 0xff);
	outb(0x3d4, 13);
	outb(0x3d5, (base - 0xc00b8000) >> 1 & 0xff);
}

static void set_cur(void)
{
	outb(0x3d4, 14);
	outb(0x3d5, ((base + (y * 80 + x) * 2 - 0xc00b8000) >> 9) & 0xff);
	outb(0x3d4, 15);
	outb(0x3d5, (base + (y * 80 + x) * 2 - 0xc00b8000) >> 1 & 0xff);
}

*/

void vga_put_char(int x, int y ,char ch ,long color , long bgcolor);
void vga_move_rang(int f_x0, int f_y0, int t_x0, int t_y0, int wide, int height);


static int top=100;
static int left=80;

static void vga_con_put_char(char ch)
{
	vga_put_char(left + x * 8, top + y * 16, ch , 0xffffff, 0x000000);
}

static void srcup()
{
	if (y < 25)
		return;

	vga_move_rang(left,top +16 , left, top, left +80*8, top + 23*16);
	int pp =x;
	y=24;
	for(;x < 80; x++)
		vga_con_put_char(' ');
	x=pp;
	
}

static void write_char(char ch)
{
	if (ch == '\r')
		return;
	if (ch == '\b') {
		if (x > 0) {
			x--;
		} else {
			if (y > 0) {
				x = 80 - 1;
				y--;
			}
		}

		vga_con_put_char(' ');

	} else if (ch == '\t') {
		do {
			vga_con_put_char(' ');
		} while (++x % 8);
	} else if (ch == '\n') {
		y++;
		x = 0;
		srcup();
	} else {
		vga_con_put_char(ch);
		x++;
		if (x >= 80) {
			x = 0;
			y++;
			srcup();
		}
	}
}

static void cls()
{
	int i = x, j = y;
	for (x = i; x < 80; x++) {
		for (y = j; y < 24; j++)
			write_char(' ');
	}
	x = i, y = j;
}

static int con_write(struct tty_struct *tty)
{
	char ch;
	int res = 0;
	int p1 = 0, p2 = 0, e_esc = 0;

	while (!ISEMPTY(&tty->out)) {
		
		ch = GETCH(&tty->out);
		res++;

		switch (e_esc) {
		case 0:
			if (ch == '\033') {
				e_esc = 1;
				continue;
			}
			write_char(ch);
			break;
		case 1:
			if (ch == '[') {
				e_esc = 2;
				p1 = 0;
				continue;
			}
			e_esc = 0;
			write_char(ch);
			break;
		case 2:
			if (isdigit(ch)) {
				p1 = p1 * 10 + ch - '0';
				continue;
			}
			if (ch == ';') {
				e_esc = 3;
				p2 = 0;
				continue;
			}
			if (ch == 'J') {
				e_esc = 0;
				cls();
				continue;
			}
			if (ch == 'E') {
				tty->termios.c_lflag &= ~ECHO;
				e_esc = 0;
				continue;
			}
			e_esc = 0;
			write_char(ch);
			break;
		case 3:
			if (isdigit(ch)) {
				p2 = p2 * 10 + ch - '0';
				continue;
			}
			if (ch == 'H') {
				x = p2 - 1, y = p1 - 1;
				e_esc = 0;
				continue;
			}
			e_esc = 0;
			write_char(ch);
			break;
		}
	}
	//set_cur();
	return res;
}

void con_init()
{
	con_tty.write = &con_write;
	con_tty.termios.c_lflag = ECHO;
	tty_table[1] = &con_tty;
}

void con_print(char *buf, int len)
{
	while (len--)
		write_char(*buf++);
	//set_cur();
}
