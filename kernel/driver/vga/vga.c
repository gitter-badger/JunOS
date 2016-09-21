/*
 *  driver/vga/vga.c
 *
 *  This file is part of JunOS Operating System.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <junos/junos.h>

static long vga_addr;
static long vga_width;
static long vga_height;
static long vga_depth;

#define badxy(x,y)	\
    ((x) < 0 || (y) <0 || (x) > vga_width || (y) > vga_height)

void vga_set_pixel(int x, int y, long value)
{
	if (badxy(x, y))
		return;
	long *p = (long *)vga_addr + y * vga_width + x ;
	*p = value;
}

long vga_get_pixel(int x, int y)
{
	if (badxy(x, y))
		return 0 ;
	long *p = (long *)vga_addr + y * vga_width + x ;
	return *p;
}

void vga_set_rang(int x1, int y1, int x2, int y2, long value)
{
	if (x1 < 0)
		x1 = 0;
	if (y1 < 0)
		y1 = 0;
	if (x2 > vga_width)
		x2 = vga_width;
	if (y2 > vga_height)
		y2 = vga_height;
	for (int i = x1; i < x2; i++)
		for (int j = y1; j < y2 ; j++ ) {
			long *p = (long *)vga_addr + j * vga_width + i ;
			*p = value;
		}
}

#include "font8x16.c"

void vga_put_char(int x, int y , char ch , long color , long bgcolor)
{
	int v, v1;

	for (int i = 0 ; i < 16 ; i++) {
		v = font8x16[ch * 16 + i];
		v1 = 0x80;
		for (int j = 0 ; j < 8 ; j++)
			if (v & (v1 >> j))
				vga_set_pixel(x + j, y + i, color);
			else
				vga_set_pixel(x + j, y + i, bgcolor);
	}
}

void vga_put_string(int x, int y , char *str , long color , long bgcolor)
{
	while (*str) {
		vga_put_char(x, y, *str, color, bgcolor);
		str++;
		x += 8;
	}
}

void vga_move_rang(int f_x0, int f_y0, int t_x0, int t_y0, int wide, int height)
{
	if (t_x0 <= f_x0 && t_y0 <= f_y0) {
		for ( int j = 0; j < height; j++) {
			char *p1 = (char *)(vga_addr + (f_x0 + (f_y0 + j) * vga_width) * vga_depth);
			char *p2 = (char *)(vga_addr + (t_x0 + (t_y0 + j) * vga_width) * vga_depth);
			memcpy(p2 , p1, wide * vga_depth);
		}
	}
}

void vga_init(void)
{
	long *p;
	int addr = __va(0x1000 + 8);
	struct multiboot_tag_framebuffer *fb = NULL;
	struct multiboot_tag *tag;

	do {
		tag = (struct multiboot_tag *) addr;
		if (tag->type == MULTIBOOT_TAG_TYPE_FRAMEBUFFER) {
			fb = (struct multiboot_tag_framebuffer *) tag;
			break;
		}
		addr = (addr + tag->size + 7) & ~7;
	} while (tag->type != MULTIBOOT_HEADER_TAG_END);

	if (!fb)
		panic("Not find framebuffer by GRUB\n");


	vga_addr = (unsigned long)fb->common.framebuffer_addr;
	vga_width = fb->common.framebuffer_width;
	vga_height = fb->common.framebuffer_height;
	vga_depth = 4 ;

	for ( int i = 0; i <= (vga_width * vga_height * vga_depth / 4096 ); i++)
	{
		map_page(vga_addr + i * 4096, vga_addr + i * 4096 ,
		         (CURRENT_TASK() )->pdtr);
	}

	p = (long *)vga_addr;
	for ( int i = 0; i < vga_width * vga_height; i ++)
		*p++ = 0x6495ED;
}
