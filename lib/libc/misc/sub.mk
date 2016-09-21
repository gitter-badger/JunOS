LIBC_OBJ+=misc/assert.o 	\
          misc/locale.o 	\
          misc/dirent.o
# ctpye
LIBC_OBJ+=misc/__ctype.o 	\
          misc/isalnum.o 	\
	  misc/isalpha.o 	\
	  misc/iscntrl.o 	\
          misc/isdigit.o 	\
	  misc/islower.o 	\
	  misc/isprint.o 	\
	  misc/ispunct.o 	\
          misc/isupper.o 	\
	  misc/isxdigit.o 	\
	  misc/isspace.o  	\
	  misc/isgraph.o 	\
          misc/tolower.o 	\
	  misc/toupper.o

misc/__ctype.o:misc/ctype.c
	@$(CC) $(CFLAGS) -D__CTYPE -o $@  $<

misc/isupper.o:misc/ctype.c
	@$(CC) $(CFLAGS) -D_ISUPPER -o $@  $<

misc/islower.o:misc/ctype.c
	@$(CC) $(CFLAGS) -D_ISLOWER -o $@  $<

misc/isdigit.o:misc/ctype.c
	@$(CC) $(CFLAGS) -D_ISDIGIT -o $@  $<

misc/iscntrl.o:misc/ctype.c
	@$(CC) $(CFLAGS) -D_ISCNTRL -o $@  $<

misc/isspace.o:misc/ctype.c
	@$(CC) $(CFLAGS) -D_ISSPACE -o $@  $<

misc/ispunct.o:misc/ctype.c
	@$(CC) $(CFLAGS) -D_ISPUNCT -o $@  $<

misc/isxdigit.o:misc/ctype.c
	@$(CC) $(CFLAGS) -D_ISXDIGIT -o $@  $<

misc/isalpha.o:misc/ctype.c
	@$(CC) $(CFLAGS) -D_ISALPHA -o $@  $<

misc/isalnum.o:misc/ctype.c
	@$(CC) $(CFLAGS) -D_ISALNUM -o $@  $<

misc/isgraph.o:misc/ctype.c
	@$(CC) $(CFLAGS) -D_ISGRAPH -o $@  $<

misc/isprint.o:misc/ctype.c
	@$(CC) $(CFLAGS) -D_ISPRINT -o $@  $<

misc/toupper.o:misc/ctype.c
	@$(CC) $(CFLAGS) -D_TOUPPER -o $@  $<

misc/tolower.o:misc/ctype.c
	@$(CC) $(CFLAGS) -D_TOLOWER -o $@  $<

# unistd
LIBC_OBJ+=misc/getuid.o 	\
          misc/setuid.o 	\
	  misc/setsid.o 	\
	  misc/mknod.o 		\
	  misc/open.o 		\
	  misc/read.o 		\
	  misc/stat.o 		\
	  misc/link.o 		\
	  misc/execl.o 		\
	  misc/execv.o 		\
	  misc/execle.o 	\
          misc/execve.o 	\
          misc/execvp.o 	\
          misc/execlp.o 	\
	  misc/_exit.o 		\
	  misc/sbrk.o 		\
          misc/fork.o 		\
	  misc/getpid.o  	\
	  misc/chdir.o 		\
	  misc/close.o 		\
	  misc/sync.o 		\
	  misc/mkdir.o 		\
	  misc/write.o 		\
	  misc/fstat.o 		\
	  misc/dup.o  		\
	  misc/dup2.o 		\
	  misc/fcntl.o 		\
	  misc/lseek.o 		\
	  misc/wait.o 		\
	  misc/waitpid.o 	\
	  misc/pipe.o 		\
	  misc/execl.o 		\
	  misc/rmdir.o 		\
	  misc/unlink.o 	\
	  misc/mount.o  	\
	  misc/umount.o 	\
	  misc/sigsend.o 	\
	  misc/sigmask.o 	\
	  misc/sigact.o  	\
	  misc/pause.o   	\
	  misc/gettimeofday.o 	\
	  misc/settimeofday.o 	\
	  misc/fchdir.o       	\
	  misc/getcwd.o  	\
	  misc/ioctl.o  	\
	  misc/chmod.o  	\
	  misc/access.o

misc/fork.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_FORK -o $@  $<
misc/execve.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_EXECVE -o $@  $<
misc/sbrk.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_SBRK -o $@  $<
misc/waitpid.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_WAITPID -o $@  $<
misc/wait.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_WAIT -o $@  $<	  
misc/_exit.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D__EXIT -o $@  $<
misc/trace.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_TRACE -o $@  $<
misc/alarm.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_ALARM -o $@  $<
misc/getpid.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_GETPID -o $@  $<
misc/setgrp.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_SETGRP -o $@  $<
misc/setsid.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_SETSID -o $@  $<
misc/getuid.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_GETUID -o $@  $<
misc/setuid.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_SETUID -o $@  $<
misc/access.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_ACCESS -o $@  $<
misc/open.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_OPEN -o $@  $<
misc/read.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_READ -o $@  $<
misc/write.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_WRITE -o $@  $<
misc/close.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_CLOSE -o $@  $<
misc/lseek.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_LSEEK -o $@  $<
misc/fcntl.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_FCNTL -o $@  $<
misc/dup.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_DUP -o $@  $<
misc/dup2.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_DUP2 -o $@  $<
misc/ioctl.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_IOCTL -o $@  $<
misc/pipe.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_PIPE -o $@  $<
misc/mknod.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_MKNOD -o $@  $<
misc/mkdir.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_MKDIR -o $@  $<
misc/link.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_LINK -o $@  $<
misc/tan.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_RENAME -o $@  $<
misc/unlink.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_UNLINK -o $@  $<
misc/rmdir.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_RMDIR -o $@  $<
misc/chdir.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_CHDIR -o $@  $<
misc/mount.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_MOUNT -o $@  $<
misc/umount.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_UMOUNT -o $@  $<
misc/stat.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_STAT -o $@  $<
misc/fstat.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_FSTAT -o $@  $<
misc/chmod.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_CHMOD -o $@  $<
misc/chown.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_CHOWN -o $@  $<
misc/utime.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_UTIME -o $@  $<
misc/sync.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_SYNC -o $@  $<
misc/gettimeofday.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_GETTIMEOFDAY -o $@  $<
misc/settimeofday.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_SETTIMEOFDAY -o $@  $<
misc/sigsend.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_SIGSEND -o $@  $<
misc/sigmask.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_SIGNASK -o $@  $<
misc/sigact.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_SIGACT -o $@  $<
misc/pause.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_PAUSE -o $@  $<
misc/fchdir.o:misc/sysdep.c
	@$(CC) $(CFLAGS) -D_FCHDIR -o $@  $<
misc/execl.o:misc/exec.c
	@$(CC) $(CFLAGS) -D_EXECL -o $@  $<
misc/execle.o:misc/exec.c
	@$(CC) $(CFLAGS) -D_EXECLE -o $@  $<
misc/execlp.o:misc/exec.c
	@$(CC) $(CFLAGS) -D_EXECLP -o $@  $<
misc/execv.o:misc/exec.c
	@$(CC) $(CFLAGS) -D_EXECV -o $@  $<
misc/execvp.o:misc/exec.c
	@$(CC) $(CFLAGS) -D_EXECVP -o $@  $<
