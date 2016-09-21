#
#  Makefile for the Junos C start route.
#  
#  This file is part of JunOS Operating System.
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

../crt.o:crt.s
	@$(AS) $(SFLAGS) -o $@  $<

clean: 
	@-rm -f ../crt.o
