/*
 *  util/passwd.h
 * 
 *  This file is part of JunOS utitliy Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#ifndef _UTIL_PASSWD_H
#define _UTIL_PASSWD_H

#include <sys/types.h>

#define PW_FILE		"/System/Setting/passwd"

struct passwd {
	char *pw_name; 		/* Username.  		*/
	char *pw_passwd; 	/* Password.  		*/
	uid_t pw_uid; 		/* User ID.  		*/
	gid_t pw_gid; 		/* Group ID.  		*/
	char *pw_gecos; 	/* Real name.  		*/
	char *pw_dir; 		/* Home directory.  	*/
};

extern struct passwd *getpwnam(const char *name);
extern struct passwd *getpwuid(uid_t uid);

#endif
