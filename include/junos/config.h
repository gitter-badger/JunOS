/*
 *  junos/config.h    -- kernel config.
 *
 *  This file is part of JunOS Operating System.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#ifndef _JUNOS_CONFIG_H
#define _JUNOS_CONFIG_H

/* clock interrupt one seconds */
#define HZ		100

/* Max file open one task */
#define NR_OPEN		32

/* Max task exsit */
#define NR_TASK		16

/* Max inode cache in memory */
#define NR_INODE	32

/* Max supper block in system */
#define NR_SUPER	4

/* Mac buffer cache in system */
#define NR_BUFFER	64

/* buffer cache size */
#define BUF_SIZE	1024

#endif /* _JUNOS_CONFIG_H */
