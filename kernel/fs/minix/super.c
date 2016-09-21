/*
 *  fs/minix/super.c
 *
 *  This file is part of JunOS Operating System.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include "minix.h"

int minix1_read_super(struct super *super)
{
	struct minix1_super *m1_super;
	struct buffer *buf;
	struct minix_s_ext *s_ext = (struct minix_s_ext*) super->s_ext;

	buf = bread(super->s_dev, 1);
	m1_super = (struct minix1_super *) (buf->b_data);
	if (m1_super->s_magic != 0x138f) {
		printk("Not minix file system %x", super->s_dev);
		brelse(buf);
		return -1;
	}

	s_ext->s_ninodes = m1_super->s_ninodes;
	s_ext->s_nzones = m1_super->s_nzones;
	s_ext->s_imap_blocks = m1_super->s_imap_blocks;
	s_ext->s_zmap_blocks = m1_super->s_zmap_blocks;
	s_ext->s_firstdatazone = m1_super->s_firstdatazone;
	s_ext->s_log_zone_size = m1_super->s_log_zone_size;
	s_ext->s_max_size = m1_super->s_max_size;
	s_ext->s_magic = m1_super->s_magic;

	brelse(buf);
	return 0;
}

int minix1_write_super(struct super *super)
{
	return 0;
}

struct fs_operation minix_fs_operation={
	minix1_read_super,
	minix1_write_super,
	minix1_read_inode,
	minix1_write_inode,
	minix1_lookup,
	minix1_mknod,
	minix1_mkdir,
	minix1_link,
	minix1_unlink,
	minix1_rmdir,
	minix1_rename,
	minix1_file_read,
	minix1_file_readdir,
	minix1_file_write
};
