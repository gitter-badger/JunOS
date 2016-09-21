/*
 *  driver/tty/keyboard.c
 *
 *  This file is part of JunOS Operating System.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <junos/junos.h>
#include "tty.h"

#define CTRL_L	0x81
#define CTRL_R	0x82
#define SHIFT_L 0x83
#define SHIFT_R 0x84
#define ALT_L	0x85
#define ALT_R	0x86
#define CAPLK   0x87

#define F1 	0x91
#define F2	0x92
#define F3 	0x93
#define F4 	0x94
#define F5 	0x95
#define F6	0x96
#define F7 	0x97
#define F8 	0x98
#define F9 	0x99
#define F10 	0x9a
#define F11	0x9b
#define F12 	0x9c

static unsigned char key_map[0x60]={
	0,   0x1b,  '1',  '2',  '3',  '4',  '5',  '6',
	'7',  '8',  '9',  '0',  '-',  '=',  '\b', '\t',
	'q',  'w',  'e',  'r',  't',  'y',  'u',  'i',
	'o',  'p',  '[',  ']',  '\n', CTRL_L, 'a', 's',
	'd',  'f',  'g',  'h',  'j',  'k',   'l',  ';',
	'\'', '`',  SHIFT_L,'\\','z',  'x',  'c',  'v',
	'b',  'n',  'm',  ',',  '.',  '/',  SHIFT_R, '*',
	ALT_L,' ',  CAPLK, F1,   F2,   F3,   F4,   F5,
	F6,   F7,   F8,   F9,   F10,   0,    0,   '7',
	'8',  '9',  '-',  '4',  '5',  '6',   '+',  '1',
	'2',  '3',  '0',  '.',  0,   0, 0,   F11,  F12
};

static unsigned char shift_map[0x60]={
	 0,   0x1b,  '!',    '@',  '#',  '$',    '%',   '^',
	'&',  '*',  '(',     ')',  '_',  '+',    '\b',  '\t',
	'Q',  'W',  'E',     'R',  'T',  'Y',    'U',   'I',
	'O',  'P',  '{',      '}', '\n', CTRL_L, 'A',   'S',
	'D',  'F',  'G',     'H',  'J',  'K',    'L',   ':',
	'"',  '~',  SHIFT_L, '|',  'Z',  'X',    'C',   'V',
	'B',  'N',  'M',     '<',  '>',  '?',  SHIFT_R, '*',
	ALT_L,' ',  CAPLK,    F1,   F2,   F3,     F4,    F5,
	F6,   F7,    F8,      F9,   F10,   0,      0,   '7',
	'8',  '9',  '-',     '4',  '5',  '6',    '+',   '1',
	'2',  '3',  '0',     '.',   0,    0,       0,   F11, F12
};

static unsigned char ctrl_map[0x60]={
	0,      0,       0,      0,      0,      0,      0,      0,
	0,      0,       0,      0,      0,      0,      0,      0,
	C('Q'), C('W'),  C('E'), C('R'), C('T'), C('Y'), C('U'), C('I'),
	C('O'), C('P'),  0,      0,      '\r',   0,      C('A'), C('S'),
	C('D'), C('F'),  C('G'), C('H'), C('J'), C('K'), C('L'), 0,
	0,      0,       0,      C('\\'),C('Z'), C('X'), C('C'), C('V'),
	C('B'), C('N'),  C('M'), 0,      0,      C('/'), 0,      0,
};

static int shiftl;
static int shiftr;
static int ctrlr;
static int ctrll;
static int cap;

extern void dump_task();
extern void dump_mem();

static void do_kbd(struct trapframe *tf)
{
	unsigned char tmp, s;
	outb(0x20, 0x20);
	tmp = inb(0x60);
	if (tmp < 0x7f) {
		if(ctrll|ctrlr)
			s=ctrl_map[tmp];
		else if(shiftl|shiftr)
			s=shift_map[tmp];
		else
			s=key_map[tmp];
		switch (s) {
		case CTRL_L:
			ctrll = 1;
			break;
		case CTRL_R:
			ctrlr = 1;
			break;
		case SHIFT_L:
			shiftl = 1;
			break;
		case SHIFT_R:
			shiftr = 1;
			break;
		case CAPLK:
			cap = !cap;
			break;
		case F1:
		case F2:
		case F3:
		case F4:
		case F5:
		case F6:
		case F7:
		case F8:
		case F9:
			break;
		case F10:
			dump_mem();
			break;
		case F11:
			dump_task();
			break;
		default:
			if (cap) {
				if (s >= 'a' && s <= 'z')
					s = s - 32;
				else if (s >= 'A' && s <= 'Z')
					s = s + 32;
			}
			PUTCH(&(tty_table[1]->raw),s);
			copy_to_cook(tty_table[1]);
			break;
		}
	} else {
		if (tmp == 0xe0) {
			tmp = inb(0x60);
		} else {
			tmp &= 0x7f;
			tmp = key_map[tmp];
			switch (tmp) {
			case CTRL_L:
				ctrll = 0;
				break;
			case CTRL_R:
				ctrlr = 0;
				break;
			case SHIFT_L:
				shiftl = 0;
				break;
			case SHIFT_R:
				shiftr = 0;
				break;
			}
		}
	}
}

void kbd_init(void)
{
	set_trap_handle(0x21, &do_kbd);
	outb(0x21, inb(0x21) & ~2);
}
