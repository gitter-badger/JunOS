/*
 *  driver/dev.c
 *
 *  This file is part of JunOS Operating System.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <junos/junos.h>

extern void tty_init(void);
extern void mem_init(void);
extern void rd_init(void);
extern void hd_init(void);

struct char_device  *char_table[DEV_CHAR_MAX + 1];
struct block_device *blk_table[DEV_BLK_MAX + 1];

void dev_init(void)
{
	/* init char dev */
	tty_init();
	mem_init();

	/* init block dev */
	rd_init();
	hd_init();
}
