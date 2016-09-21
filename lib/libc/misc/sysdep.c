/*
 *  misc/sysdep.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <sys/types.h>
#include <sys/syscall.h>
#include <sys/unistd.h>
#include <errno.h>

#if defined(_FORK)
__syscall0(pid_t, fork);

#elif defined(_EXECVE)
__syscall3(int, execve, const char*, path, char **, argv, char **, envp) ;

#elif defined(_SBRK)
__syscall1(int, sbrk, int, inc);

#elif defined(_WAITPID)
__syscall3(pid_t, waitpid, pid_t, pid, int*, status, int, options);

#elif defined(_WAIT)
#include <sys/wait.h>
pid_t wait(int *status)
{
	return waitpid(-1, status, 0);
}

#elif defined(__EXIT)
void _exit(int status)
{
	__asm__("int $0x30" : :"a"(__NR_exit),"b"(status));
}

#elif defined(_TRACE)
__syscall0(int, trace);

#elif defined(_ALARM)
__syscall1(int, alarm, int, seconds);

#elif defined(_GETPID)
__syscall0(pid_t, getpid);

#elif defined(_SETGRP)
__syscall0(pid_t, setgrp);

#elif defined(_SETSID)
__syscall0(pid_t, setsid);

#elif defined(_GETUID)
__syscall0(uid_t, getuid);

#elif defined(_SETUID)
__syscall1(uid_t, setuid, uid_t, uid);

#elif defined(_GETGID)
__syscall0(gid_t, getgid);

#elif defined(_SETGID)
__syscall1(gid_t, setgid, gid_t, gid);

#elif defined(_ACCESS)
__syscall2(int, access, const char *, path, int, mode);

#elif defined(_OPEN)
__syscall3(int, open, const char*, filename, int, flag, mode_t, mode);

#elif defined(_READ)
__syscall3(ssize_t, read, int, fd, void*, buf, size_t, size);

#elif defined(_WRITE)
__syscall3(ssize_t, write, int, fd, void*, buf, size_t, size);

#elif defined(_CLOSE)
__syscall1(int, close, int, fd);

#elif defined(_LSEEK)
__syscall3(int, lseek, int, fd, long, off, int, where);

#elif defined(_FCNTL)
__syscall3(int, fcntl, int, fd, int, cmd, long ,arg);

#elif defined(_DUP)
#include <sys/fcntl.h>
int dup(int fd)
{
	return fcntl(fd,F_DUPFD,0);
}

#elif defined(_DUP2)
#include <sys/fcntl.h>
int dup2(int fd, int fd2)
{
	return fcntl(fd, F_DUPFD, fd2);
}

#elif defined(_IOCTL)
__syscall3(int, ioctl, int, fd, int, cmd, long, arg);

#elif defined(_PIPE)
__syscall1(int, pipe, int *, fd);

#elif defined(_MKNOD)
__syscall3(int, mknod, char *, filename, mode_t, mode, dev_t, dev);

#elif defined(_MKDIR)
__syscall2(int, mkdir, char *, name, mode_t, mode);

#elif defined(_LINK)
__syscall2(int, link, const char *, name, const char *, newname);

#elif defined(_RENAME)
__syscall2(int, rename, const char *, name, const char *, newname);

#elif defined(_UNLINK)
__syscall1(int, unlink, const char *, filename);

#elif defined(_RMDIR)
__syscall1(int, rmdir, char *, filename);

#elif defined(_CHDIR)
__syscall1(int, chdir, char *, filename);

#elif defined(_MOUNT)
__syscall4(int, mount, char *, special, char *, target, char *, type, int,
		rw_flag);

#elif defined(_UMOUNT)
__syscall1(int, umount, char *, special);

#elif defined(_STAT)
#include <sys/stat.h>
__syscall2(int, stat, char *, filename, struct stat *, statbuf);

#elif defined(_FSTAT)
#include <sys/stat.h>
__syscall2(int, fstat, int, fd, struct stat *, statbuf);

#elif defined(_CHMOD)
__syscall2(int, chmod, const char *, filename, mode_t, mode);

#elif defined(_CHOWN)
__syscall3(int, chown, const char *, filename, uid_t, uid, gid_t, gid);

#elif defined(_UTIME)
__syscall2(int, utime, const char *, filename, struct utimebuf *, utbuf);

#elif defined(_SYNC)
__syscall0(int, sync);

#elif defined(_GETTIMEOFDAY)
#include <time.h>
__syscall2(int, gettimeofday, struct timeval*, tv, struct timezone *, tz);

#elif defined(_SETTIMEOFDAY)
#include <time.h>
__syscall2(int, settimeofday, struct timeval*, tv, struct timezone *, tz);

#elif defined(_SIGSEND)
__syscall2(int, sigsend, pid_t, pid, int, signo);


#elif defined(_SIGMASK)
#include <signal.h>
__syscall3(int, sigmask, int, how, sigset_t *, set, sigset_t *, oset);

#elif defined(_SIGACT)
#include <signal.h>
__syscall2(sigact_t, sigact, int, signo, sigact_t, action);

#elif defined(_PAUSE)
__syscall0(int, pause);

#elif defined(_FCHDIR)
__syscall1(int, fchdir, int, fd);

#endif
