#
#  Makrfile for JunOS utility
#  
#  This file is part of JunOS Operating System.
#  
#  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
#  Licensed under MIT, http://opensource.org/licenses/MIT. 
#

AS=nasm
CC=gcc
LD=ld -m elf_i386 -T ../script/ldscript  ../lib/crt.o

SFLAGS=-g -f elf32
CFLAGS=-g -c -x c -Wall -m32 -std=c99 -nostdinc -nostdlib -fno-builtin \
       -fno-stack-protector -I ../include
LIB=../lib/libutil.a ../lib/libc.a

OBJS=init.elf  sh.elf     ls.elf    cat.elf  sync.elf   mkdir.elf   cp.elf  \
     rm.elf    rmdir.elf  ln.elf    vi.elf   mount.elf  umount.elf  cal.elf \
     date.elf

.s.o:
	@$(AS) $(SFLAGS) -o $@  $<
.c.o:
	@$(CC) $(CFLAGS) -o $@  $<

all:$(OBJS)

install: $(OBJS)
	@ for obj in $(OBJS) ;                                    \
	do                                                        \
	    cp $$obj `echo $(PREFIX)/$$obj | cut -d '.' -f 1` ;   \
	done

clean:
	@-rm -f *.o $(OBJS)

$(OBJS):%.elf:%.o $(LIB)
	@echo CC       $@
	@$(LD) -o  $@  $<  $(LIB)
