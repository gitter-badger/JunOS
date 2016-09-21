#
#  Makefile of tcc-0.9.26 for Junos.
#
#  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
#  Licensed under MIT, http://opensource.org/licenses/MIT.
#

AS=nasm
CC=gcc
LD=ld -m elf_i386 -T ../script/ldscript  ../lib/crt.o

SFLAGS=-O2 -f elf32
CFLAGS=-O2 -c -x c  -m32 -std=c99 -nostdinc -nostdlib -fno-builtin \
       -fno-stack-protector -I ../include 
LIB=../lib/libutil.a ../lib/libc.a  

.s.o:
	@echo         AS	$<
	@$(AS) $(SFLAGS) -o $@  $<
.c.o:
	@echo         CC	$<
	@$(CC) $(CFLAGS) -o $@  $<

DOWN_DIR= ../tmp/down
S=$(DOWN_DIR)/tcc-0.9.26

OBJS=$(S)/tcc.o      $(S)/libtcc.o   $(S)/tccpp.o    $(S)/tccgen.o   \
     $(S)/tccelf.o   $(S)/tccasm.o   $(S)/i386-gen.o $(S)/i386-asm.o


CFLAGS+=-DTCC_TARGET_I386 -DCONFIG_TCC_STATIC -UTCC_IS_NATIVE -I . -I $(S)

tcc.elf: $(S)  $(OBJS) comp.o $(LIB)
	@$(LD) -o $@ $(OBJS) comp.o $(LIB)

install: 
	cp tcc.elf    $(PREFIX)/tcc 

clean:
	@rm -f tcc.elf comp.o $(OBJS) 

$(S):
	cd $(DOWN_DIR) &&                                                   \
	wget http://ftp.twaren.net/Unix/NonGNU/tinycc/tcc-0.9.26.tar.bz2 && \
	tar -jxf tcc-0.9.26.tar.bz2
