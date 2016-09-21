#
#  Makefile for the Junos C Library.
#  
#  This file is part of Junos C Library.
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

default:../libc.a

include string/sub.mk
include stdio/sub.mk
include stdlib/sub.mk
include time/sub.mk
include math/sub.mk
include misc/sub.mk

../libc.a: $(LIBC_OBJ)
	@echo         AR       libc
	@ar rcs   ../libc.a    $(LIBC_OBJ) 

clean: 
	@-rm -f ../libc.a $(LIBC_OBJ)
