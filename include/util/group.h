/*
 *  util/group.h
 * 
 *  This file is part of JunOS utitliy Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#ifndef _UTIL_GROUP_H
#define _UTIL_GROUP_H

#include <sys/types.h>

#define GRP_FILE 	"/System/Setting/group"

/* The group structure */
struct group {
	char   *gr_name;	/* Group name.	*/
	gid_t   gr_gid; 	/* Group ID.	*/
	char  **gr_mem;		/* Member list.	*/
};

extern struct group  *getgrgid(gid_t gid);
extern struct group  *getgrnam(const char *name);

#endif
