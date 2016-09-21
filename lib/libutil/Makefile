#
#  Makefile for the Junos utility Library.
#  
#  This file is part of JunOS utility Library.
#  
#  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
#  Licensed under MIT, http://opensource.org/licenses/MIT. 
#

AS=nasm
CC=gcc

SFLAGS=-f elf32
CFLAGS=-c -x c -Wall -m32 -std=c99 -nostdinc -nostdlib -fno-builtin \
       -fno-stack-protector -I ../../include

.s.o:
	@echo         AS	$<
	@$(AS) $(SFLAGS) -o $@  $<
.c.o:
	@echo         CC	$<
	@$(CC) $(CFLAGS) -o $@  $<

OBJS  =basename.o 	\
       dirname.o  	\
       group.o      	\
       passwd.o      

../libutil.a: $(OBJS)
	@echo         AR       libc
	@ar rcs ../libutil.a   $(OBJS) 

clean: 
	@-rm -f ../libutil.a $(LIBC_OBJ)
